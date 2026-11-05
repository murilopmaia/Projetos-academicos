const providerService = require('../services/providerService');

exports.getAllProviders = async (req, res, next) => {
  try {
    const { serviceType } = req.query;
    const providers = await providerService.getAllProviders(serviceType);
    
    res.status(200).json({
      status: 'success',
      results: providers.length,
      data: {
        providers
      }
    });
  } catch (error) {
    next(error);
  }
};

exports.getProviderById = async (req, res, next) => {
  try {
    const { id } = req.params;
    const provider = await providerService.getProviderById(id);
    
    if (!provider) {
      return res.status(404).json({
        status: 'error',
        message: 'Provider not found'
      });
    }
    
    res.status(200).json({
      status: 'success',
      data: {
        provider
      }
    });
  } catch (error) {
    next(error);
  }
};

exports.getProviderAvailability = async (req, res, next) => {
  try {
    const { id } = req.params;
    const { date } = req.query;
    
    const provider = await providerService.getProviderById(id);
    
    if (!provider) {
      return res.status(404).json({
        status: 'error',
        message: 'Provider not found'
      });
    }
    
    const availability = await providerService.getProviderAvailability(id, date);
    
    res.status(200).json({
      status: 'success',
      data: {
        availability
      }
    });
  } catch (error) {
    next(error);
  }
};