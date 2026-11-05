const express = require('express');
const providerController = require('../controllers/providerController');

const router = express.Router();

// Get all providers with optional filtering
router.get('/', providerController.getAllProviders);

// Get provider by ID
router.get('/:id', providerController.getProviderById);

// Get provider availability
router.get('/:id/availability', providerController.getProviderAvailability);

module.exports = router;