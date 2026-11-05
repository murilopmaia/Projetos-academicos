const { DataTypes } = require('sequelize');
const { sequelize } = require('../index');

const Booking = sequelize.define('Booking', {
  id: {
    type: DataTypes.UUID,
    defaultValue: DataTypes.UUIDV4,
    primaryKey: true
  },
  providerId: {
    type: DataTypes.UUID,
    allowNull: false
  },
  date: {
    type: DataTypes.DATEONLY,
    allowNull: false
  },
  time: {
    type: DataTypes.STRING,
    allowNull: false
  },
  clientName: {
    type: DataTypes.STRING,
    allowNull: false
  },
  clientPhone: {
    type: DataTypes.STRING,
    allowNull: false
  },
  clientEmail: {
    type: DataTypes.STRING,
    allowNull: false
  },
  clientAddress: {
    type: DataTypes.STRING,
    allowNull: false
  },
  notes: {
    type: DataTypes.TEXT,
    allowNull: true
  },
  status: {
    type: DataTypes.ENUM('confirmed', 'cancelled'),
    defaultValue: 'confirmed'
  }
});

module.exports = Booking;