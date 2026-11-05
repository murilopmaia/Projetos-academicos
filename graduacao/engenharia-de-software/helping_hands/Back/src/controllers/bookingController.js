const bookingService = require('../services/bookingService');
const providerService = require('../services/providerService');

exports.getAllBookings = async (req, res, next) => {
  try {
    const { providerId, clientId } = req.query;
    const bookings = await bookingService.getAllBookings(providerId, clientId);
    
    res.status(200).json({
      status: 'success',
      results: bookings.length,
      data: {
        bookings
      }
    });
  } catch (error) {
    next(error);
  }
};

exports.getBookingById = async (req, res, next) => {
  try {
    const { id } = req.params;
    const booking = await bookingService.getBookingById(id);
    
    if (!booking) {
      return res.status(404).json({
        status: 'error',
        message: 'Booking not found'
      });
    }
    
    res.status(200).json({
      status: 'success',
      data: {
        booking
      }
    });
  } catch (error) {
    next(error);
  }
};

exports.createBooking = async (req, res, next) => {
  try {
    const { providerId, date, time, clientDetails } = req.body;
    
    // Check if provider exists
    const provider = await providerService.getProviderById(providerId);
    if (!provider) {
      return res.status(404).json({
        status: 'error',
        message: 'Provider not found'
      });
    }
    
    // Check if the time slot is available
    const isAvailable = providerService.checkAvailability(providerId, date, time);
    if (!isAvailable) {
      return res.status(400).json({
        status: 'error',
        message: 'The selected time slot is not available'
      });
    }
    
    // Create booking
    const newBooking = bookingService.createBooking({
      providerId,
      date,
      time,
      clientDetails
    });
    
    res.status(201).json({
      status: 'success',
      data: {
        booking: newBooking
      }
    });
  } catch (error) {
    next(error);
  }
};

exports.updateBooking = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { date, time, clientDetails } = req.body;
    
    // Check if booking exists
    const existingBooking = await bookingService.getBookingById(id);
    if (!existingBooking) {
      return res.status(404).json({
        status: 'error',
        message: 'Booking not found'
      });
    }
    
    // If date or time has changed, check availability
    if ((date && date !== existingBooking.date) || (time && time !== existingBooking.time)) {
      const isAvailable = providerService.checkAvailability(
        existingBooking.providerId,
        date || existingBooking.date,
        time || existingBooking.time,
        id // Exclude current booking from availability check
      );
      
      if (!isAvailable) {
        return res.status(400).json({
          status: 'error',
          message: 'The selected time slot is not available'
        });
      }
    }
    
    // Update booking
    const updatedBooking = bookingService.updateBooking(id, {
      date,
      time,
      clientDetails
    });
    
    res.status(200).json({
      status: 'success',
      data: {
        booking: updatedBooking
      }
    });
  } catch (error) {
    next(error);
  }
};

exports.cancelBooking = async (req, res, next) => {
  try {
    const { id } = req.params;
    
    // Check if booking exists
    const existingBooking = await bookingService.getBookingById(id);
    if (!existingBooking) {
      return res.status(404).json({
        status: 'error',
        message: 'Booking not found'
      });
    }
    
    // Cancel booking
    await bookingService.cancelBooking(id);

    res.status(200).json({
      status: 'success',
      message: 'Booking cancelled successfully'
    });
  } catch (error) {
    next(error);
  }
};