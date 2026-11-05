const { Booking, Provider } = require('../database/models');
const { Op } = require('sequelize');
const providerService = require('./providerService');

/**
 * Get all bookings, optionally filtered by provider or client
 */
exports.getAllBookings = async (providerId, clientId) => {
  try {
    let whereCondition = {};
    
    if (providerId) {
      whereCondition.providerId = providerId;
    }
    
    if (clientId) {
      whereCondition.clientEmail = clientId;
    }
    
    return await Booking.findAll({
      where: whereCondition,
      include: [{
        model: Provider,
        attributes: ['id', 'name', 'role']
      }]
    });
  } catch (error) {
    console.error('Error getting bookings:', error);
    throw new Error('Failed to get bookings');
  }
};

/**
 * Get a booking by ID
 */
exports.getBookingById = async (id) => {
  try {
    return await Booking.findByPk(id, {
      include: [{
        model: Provider,
        attributes: ['id', 'name', 'role']
      }]
    });
  } catch (error) {
    console.error('Error getting booking by ID:', error);
    throw new Error('Failed to get booking');
  }
};

/**
 * Create a new booking
 */
exports.createBooking = async (bookingData) => {
  try {
    const newBooking = await Booking.create({
      providerId: bookingData.providerId,
      date: bookingData.date,
      time: bookingData.time,
      clientName: bookingData.clientDetails.name,
      clientPhone: bookingData.clientDetails.phone,
      clientEmail: bookingData.clientDetails.email,
      clientAddress: bookingData.clientDetails.address,
      notes: bookingData.clientDetails.notes,
      status: 'confirmed'
    });
    
    return await this.getBookingById(newBooking.id);
  } catch (error) {
    console.error('Error creating booking:', error);
    throw new Error('Failed to create booking');
  }
};

/**
 * Update an existing booking
 */
exports.updateBooking = async (id, updateData) => {
  try {
    const booking = await this.getBookingById(id);
    if (!booking) return null;
    
    const updateFields = {
      ...(updateData.date && { date: updateData.date }),
      ...(updateData.time && { time: updateData.time }),
      ...(updateData.clientDetails?.name && { clientName: updateData.clientDetails.name }),
      ...(updateData.clientDetails?.phone && { clientPhone: updateData.clientDetails.phone }),
      ...(updateData.clientDetails?.email && { clientEmail: updateData.clientDetails.email }),
      ...(updateData.clientDetails?.address && { clientAddress: updateData.clientDetails.address }),
      ...(updateData.clientDetails?.notes && { notes: updateData.clientDetails.notes }),
    };
    
    await Booking.update(updateFields, {
      where: { id }
    });
    
    return await this.getBookingById(id);
  } catch (error) {
    console.error('Error updating booking:', error);
    throw new Error('Failed to update booking');
  }
};

/**
 * Cancel a booking
 */
exports.cancelBooking = async (id) => {
  try {
    const booking = await this.getBookingById(id);
    if (!booking) return false;
    
    await Booking.update({
      status: 'cancelled'
    }, {
      where: { id }
    });
    
    return true;
  } catch (error) {
    console.error('Error cancelling booking:', error);
    throw new Error('Failed to cancel booking');
  }
};