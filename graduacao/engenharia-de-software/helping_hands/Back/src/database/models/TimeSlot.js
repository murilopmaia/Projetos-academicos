const { DataTypes } = require('sequelize');
const { sequelize } = require('../index');

const TimeSlot = sequelize.define('TimeSlot', {
  id: {
    type: DataTypes.UUID,
    defaultValue: DataTypes.UUIDV4,
    primaryKey: true
  },
  availabilityId: {
    type: DataTypes.UUID,
    allowNull: false
  },
  time: {
    type: DataTypes.STRING,
    allowNull: false
  },
  available: {
    type: DataTypes.BOOLEAN,
    defaultValue: true
  }
});

module.exports = TimeSlot;