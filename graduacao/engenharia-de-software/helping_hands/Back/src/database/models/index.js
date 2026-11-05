const Provider = require('./Provider');
const Availability = require('./Availability');
const TimeSlot = require('./TimeSlot');
const Booking = require('./Booking');

// Definir relacionamentos
Provider.hasMany(Availability, { foreignKey: 'providerId', onDelete: 'CASCADE' });
Availability.belongsTo(Provider, { foreignKey: 'providerId' });

Availability.hasMany(TimeSlot, { foreignKey: 'availabilityId', onDelete: 'CASCADE' });
TimeSlot.belongsTo(Availability, { foreignKey: 'availabilityId' });

Provider.hasMany(Booking, { foreignKey: 'providerId' });
Booking.belongsTo(Provider, { foreignKey: 'providerId' });

module.exports = {
  Provider,
  Availability,
  TimeSlot,
  Booking
};