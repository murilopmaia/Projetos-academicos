const express = require('express');
const bookingController = require('../controllers/bookingController');
const { validateBookingRequest } = require('../middlewares/validators');

const router = express.Router();

// Get all bookings
router.get('/', bookingController.getAllBookings);

// Get booking by ID
router.get('/:id', bookingController.getBookingById);

// Create a new booking
router.post('/', validateBookingRequest, bookingController.createBooking);

// Update a booking
router.put('/:id', validateBookingRequest, bookingController.updateBooking);

// Cancel a booking
router.delete('/:id', bookingController.cancelBooking);

module.exports = router;