const { DataTypes } = require('sequelize');
const { sequelize } = require('../index');

const Availability = sequelize.define('Availability', {
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
    type: DataTypes.DATE,
  },
  available: {
    type: DataTypes.BOOLEAN,
    defaultValue: true
  }
});

module.exports = Availability;