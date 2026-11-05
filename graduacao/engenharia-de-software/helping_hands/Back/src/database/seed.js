const { sequelize } = require("./index");
const { Provider, Availability, TimeSlot, Booking } = require("./models");
const { providers, bookings } = require("./models/mockData");
const bcryptjs = require("bcryptjs");

async function seedDatabase() {
  try {
    // Sincronizar o banco de dados (cria as tabelas)
    await sequelize.sync({ force: true });
    console.log("Banco de dados sincronizado");

    // Inserir os fornecedores (providers)
    for (const providerData of providers) {
      const hashedPassword = await bcryptjs.hash('senha123', 10); // Hash da senha padrão

      const provider = await Provider.create({
        id: providerData.id,
        name: providerData.name,
        email: `${providerData.name
          .toLowerCase()
          .replace(/\s/g, ".")}@example.com`, // Email baseado no nome
        password: hashedPassword,
        role: providerData.role,
        focus: providerData.focus,
        stars: providerData.stars,
        imageUrl: providerData.imageUrl,
      });

      // Inserir disponibilidades e horários
      for (const availabilityData of providerData.availability) {
        const availability = await Availability.create({
          providerId: provider.id,
          date: availabilityData.date,
          available: availabilityData.available,
        });

        if (
          availabilityData.timeSlots &&
          availabilityData.timeSlots.length > 0
        ) {
          for (const timeSlotData of availabilityData.timeSlots) {
            await TimeSlot.create({
              availabilityId: availability.id,
              time: timeSlotData.time,
              available: timeSlotData.available,
            });
          }
        }
      }
    }

    // Inserir as reservas (bookings)
    for (const bookingData of bookings) {
      await Booking.create({
        id: bookingData.id,
        providerId: bookingData.providerId,
        date: bookingData.date,
        time: bookingData.time,
        clientName: bookingData.clientDetails.name,
        clientPhone: bookingData.clientDetails.phone,
        clientEmail: bookingData.clientDetails.email,
        clientAddress: bookingData.clientDetails.address,
        notes: bookingData.clientDetails.notes,
        status: bookingData.status,
      });
    }

    console.log("Dados inseridos com sucesso");
  } catch (error) {
    console.error("Erro ao popular o banco de dados:", error);
  }
}

// Executar a função de seed
seedDatabase();
