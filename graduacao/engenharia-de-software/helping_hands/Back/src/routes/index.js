const express = require('express');
const providerRoutes = require('./providerRoutes');
const bookingRoutes = require('./bookingRoutes');

const router = express.Router();

router.use('/providers', providerRoutes);
router.use('/bookings', bookingRoutes);

// Health check route
router.get('/health', (req, res) => {
  res.status(200).json({
    status: 'success',
    message: 'API is running'
  });
});

module.exports = router;