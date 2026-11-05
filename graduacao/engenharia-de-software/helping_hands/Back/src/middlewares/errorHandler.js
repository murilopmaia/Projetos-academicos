/**
 * Global error handling middleware
 */
module.exports = (err, req, res, next) => {
  console.error('Error:', err);
  
  // Default error status and message
  const status = err.statusCode || 500;
  const message = err.message || 'Something went wrong';
  
  res.status(status).json({
    status: 'error',
    message: message,
    ...(process.env.NODE_ENV === 'development' && { stack: err.stack })
  });
};