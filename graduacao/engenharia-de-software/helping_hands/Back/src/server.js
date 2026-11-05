const express = require('express');
const cors = require('cors');
const morgan = require('morgan');
const routes = require('./routes');
const errorHandler = require('./middlewares/errorHandler');
const { sequelize, testConnection } = require('./database');

const app = express();
const PORT = process.env.PORT || 3000;

// Middlewares
app.use(cors());
app.use(express.json());
app.use(morgan('dev'));

// Routes
app.use('/api', routes);

// Error handling middleware
app.use(errorHandler);

// 404 handler
app.use((req, res) => {
  res.status(404).json({
    status: 'error',
    message: 'Route not found'
  });
});

// Initialize database and start server
async function startServer() {
  try {
    // Test database connection
    await testConnection();
    
    // Sync database models (in production, use migrations instead)
    await sequelize.sync();
    
    // Start the server
    app.listen(PORT, () => {
      console.log(`Server running on port ${PORT}`);
    });
  } catch (error) {
    console.error('Failed to start server:', error);
    process.exit(1);
  }
}

startServer();