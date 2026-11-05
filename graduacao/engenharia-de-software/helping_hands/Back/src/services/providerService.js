const { Provider, Availability, TimeSlot, Booking } = require('../database/models');
console.log('Provider model:', Provider);
const { Op } = require('sequelize');

/**
 * Get all providers, optionally filtered by service type
 */
exports.getAllProviders = async (serviceType) => {
  try {
    let whereCondition = {};
    if (serviceType) {
      whereCondition.role = { [Op.like]: `%${serviceType}%` };
    }
    
    return await Provider.findAll({
      where: whereCondition,
      include: [{
        model: Availability,
        include: [{
          model: TimeSlot
        }]
      }]
    });
  } catch (error) {
    console.error('Error getting providers:', error);
    throw new Error('Failed to get providers');
  }
};

/**
 * Get a provider by ID
 */
exports.getProviderById = async (id) => {
  try {
    return await Provider.findByPk(id, {
      include: [{
        model: Availability,
        include: [{
          model: TimeSlot
        }]
      }]
    });
  } catch (error) {
    console.error('Error getting provider by ID:', error);
    throw new Error('Failed to get provider');
  }
};

/**
 * Get a provider's availability for a specific date
 */
exports.getProviderAvailability = async (id, date) => {
  try {
    const provider = await this.getProviderById(id);
    if (!provider) return null;
    
    // Format date to YYYY-MM-DD if provided
    const formattedDate = date ? new Date(date).toISOString().split('T')[0] : new Date().toISOString().split('T')[0];
    
    // Get the day of week (0-6, where 0 is Sunday)
    const dayOfWeek = new Date(formattedDate).getDay();
    
    // Find the schedule for that day
    const dayAvailability = await Availability.findOne({
      where: {
        providerId: id,
        dayOfWeek: dayOfWeek
      },
      include: [{
        model: TimeSlot
      }]
    });
    
    if (!dayAvailability) {
      return { date: formattedDate, available: false, timeSlots: [] };
    }
    
    // Get existing bookings for this date
    const existingBookings = await Booking.findAll({
      where: {
        providerId: id,
        date: formattedDate,
        status: 'confirmed'
      }
    });
    
    // Mark booked slots as unavailable
    const timeSlots = dayAvailability.TimeSlots.map(slot => {
      const isBooked = existingBookings.some(booking => booking.time === slot.time);
      return {
        time: slot.time,
        available: slot.available && !isBooked
      };
    });
    
    return {
      date: formattedDate,
      available: dayAvailability.available,
      timeSlots: timeSlots
    };
  } catch (error) {
    console.error('Error getting availability:', error);
    throw new Error('Failed to get availability');
  }
};

/**
 * Check if a specific time slot is available for a provider
 */
exports.checkAvailability = async (providerId, date, time, excludeBookingId = null) => {
  try {
    const provider = await this.getProviderById(providerId);
    if (!provider) return false;
    
    // Format date to get day of week
    const dayOfWeek = new Date(date).getDay();
    
    // Find the schedule for that day
    const dayAvailability = await Availability.findOne({
      where: {
        providerId,
        dayOfWeek
      },
      include: [{
        model: TimeSlot,
        where: {
          time,
          available: true
        }
      }]
    });
    
    // Check if the day is available and the time slot exists
    if (!dayAvailability || !dayAvailability.available || dayAvailability.TimeSlots.length === 0) {
      return false;
    }
    
    // Check existing bookings to ensure the time slot is not already booked
    const whereCondition = {
      providerId,
      date,
      time,
      status: 'confirmed'
    };
    
    if (excludeBookingId) {
      whereCondition.id = { [Op.ne]: excludeBookingId };
    }
    
    const existingBooking = await Booking.findOne({
      where: whereCondition
    });
    
    return !existingBooking;
  } catch (error) {
    console.error('Error checking availability:', error);
    throw new Error('Failed to check availability');
  }
};