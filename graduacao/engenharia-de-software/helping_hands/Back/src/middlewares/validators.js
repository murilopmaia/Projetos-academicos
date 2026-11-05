const Joi = require('joi');

/**
 * Validate booking request
 */
exports.validateBookingRequest = (req, res, next) => {
  const schema = Joi.object({
    providerId: Joi.string().required().messages({
      'string.empty': 'Provider ID is required',
      'any.required': 'Provider ID is required'
    }),
    date: Joi.date().iso().required().messages({
      'date.base': 'Date must be a valid date',
      'date.format': 'Date must be in ISO format (YYYY-MM-DD)',
      'any.required': 'Date is required'
    }),
    time: Joi.string().pattern(/^([0-1]?[0-9]|2[0-3]):([0-5][0-9])$/).required().messages({
      'string.pattern.base': 'Time must be in format HH:MM',
      'any.required': 'Time is required'
    }),
    clientDetails: Joi.object({
      name: Joi.string().required().messages({
        'string.empty': 'Client name is required',
        'any.required': 'Client name is required'
      }),
      phone: Joi.string().required().messages({
        'string.empty': 'Client phone is required',
        'any.required': 'Client phone is required'
      }),
      email: Joi.string().email().required().messages({
        'string.email': 'Email must be valid',
        'string.empty': 'Email is required',
        'any.required': 'Email is required'
      }),
      address: Joi.string().required().messages({
        'string.empty': 'Address is required',
        'any.required': 'Address is required'
      }),
      notes: Joi.string().allow('', null)
    }).required().messages({
      'any.required': 'Client details are required'
    })
  });

  const { error } = schema.validate(req.body, { abortEarly: false });
  
  if (error) {
    const errorMessage = error.details.map(detail => detail.message).join(', ');
    return res.status(400).json({
      status: 'error',
      message: 'Validation error',
      details: errorMessage
    });
  }
  
  next();
};