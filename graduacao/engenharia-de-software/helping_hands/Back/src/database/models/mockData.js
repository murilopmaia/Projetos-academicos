const { v4: uuidv4 } = require('uuid');

// IDs constantes para facilitar as relações
const PROVIDER_IDS = {
  massage: uuidv4(),
  physio: uuidv4(),
  nutrition: uuidv4(),
  therapy: uuidv4(),
  yoga: uuidv4()
};

// Função auxiliar para criar datas
function createDate(year, month, day) {
  return new Date(year, month - 1, day).toISOString().split('T')[0]; // formato YYYY-MM-DD
}

// Dados mockados de provedores de serviço 
const providers = [
  {
    id: PROVIDER_IDS.massage,
    name: 'Ana Silva',
    role: 'Massagista',
    focus: 'Especialista em diversas técnicas de massagem relaxante e terapêutica. Meu objetivo é aliviar tensões musculares, melhorar a circulação e promover o bem-estar integral através de um atendimento cuidadoso e personalizado.', 
    stars: 4.8,
    imageUrl: 'https://randomuser.me/api/portraits/women/44.jpg',
    availability: [
      //
      { date: createDate(2025, 6, 9), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:30', available: true }, { time: '14:00', available: true }, { time: '15:30', available: true }, { time: '17:00', available: true } ] },
      { date: createDate(2025, 6, 10), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:30', available: true }, { time: '14:00', available: true }, { time: '15:30', available: true }, { time: '17:00', available: true } ] },
      { date: createDate(2025, 6, 11), available: true, timeSlots: [ { time: '14:00', available: true }, { time: '15:30', available: true }, { time: '17:00', available: true } ] },
      { date: createDate(2025, 6, 12), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:30', available: true }, { time: '14:00', available: true }, { time: '15:30', available: true }, { time: '17:00', available: true } ] },
      { date: createDate(2025, 6, 13), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:30', available: true }, { time: '14:00', available: true } ] },
      { date: createDate(2025, 6, 14), available: true, timeSlots: [ { time: '10:00', available: true }, { time: '11:30', available: true } ] },
      { date: createDate(2025, 6, 15), available: false, timeSlots: [] }
    ]
  },
  {
    id: PROVIDER_IDS.physio,
    name: 'Carlos Mendes',
    role: 'Fisioterapeuta',
    focus: 'Fisioterapeuta dedicado à reabilitação musculoesquelética e fisioterapia esportiva. Trabalho com planos de tratamento individualizados para recuperação de lesões, alívio da dor e otimização da performance física e qualidade de vida.', 
    stars: 4.9,
    imageUrl: 'https://randomuser.me/api/portraits/men/32.jpg',
    availability: [
      //
      { date: createDate(2025, 6, 9), available: true, timeSlots: [ { time: '08:00', available: true }, { time: '09:00', available: true }, { time: '10:00', available: true }, { time: '14:00', available: true }, { time: '15:00', available: true }, { time: '16:00', available: true } ] },
      { date: createDate(2025, 6, 10), available: true, timeSlots: [ { time: '08:00', available: true }, { time: '09:00', available: true }, { time: '10:00', available: true }, { time: '14:00', available: true }, { time: '15:00', available: true }, { time: '16:00', available: true } ] },
      { date: createDate(2025, 6, 11), available: true, timeSlots: [ { time: '08:00', available: true }, { time: '09:00', available: true }, { time: '10:00', available: true } ] },
      { date: createDate(2025, 6, 12), available: false, timeSlots: [] },
      { date: createDate(2025, 6, 13), available: true, timeSlots: [ { time: '14:00', available: true }, { time: '15:00', available: true }, { time: '16:00', available: true }, { time: '17:00', available: true } ] },
      { date: createDate(2025, 6, 14), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:00', available: true }, { time: '11:00', available: true } ] },
      { date: createDate(2025, 6, 15), available: false, timeSlots: [] }
    ]
  },
  {
    id: PROVIDER_IDS.nutrition,
    name: 'Mariana Costa',
    role: 'Nutricionista',
    focus: 'Nutricionista com foco em nutrição funcional e emagrecimento saudável e sustentável. Elaboro planos alimentares personalizados, considerando suas metas, rotina e preferências, para uma melhor relação com a comida.', // <--- EXPANDIDO
    stars: 4.7,
    imageUrl: 'https://randomuser.me/api/portraits/women/68.jpg',
    availability: [
      // 
      { date: createDate(2025, 6, 9), available: true, timeSlots: [ { time: '08:30', available: true }, { time: '09:30', available: true }, { time: '10:30', available: true }, { time: '14:30', available: true }, { time: '15:30', available: true } ] },
      { date: createDate(2025, 6, 10), available: false, timeSlots: [] },
      { date: createDate(2025, 6, 11), available: true, timeSlots: [ { time: '08:30', available: true }, { time: '09:30', available: true }, { time: '10:30', available: true }, { time: '14:30', available: true }, { time: '15:30', available: true } ] },
      { date: createDate(2025, 6, 12), available: true, timeSlots: [ { time: '13:30', available: true }, { time: '14:30', available: true }, { time: '15:30', available: true }, { time: '16:30', available: true } ] },
      { date: createDate(2025, 6, 13), available: true, timeSlots: [ { time: '08:30', available: true }, { time: '09:30', available: true }, { time: '10:30', available: true } ] },
      { date: createDate(2025, 6, 14), available: false, timeSlots: [] },
      { date: createDate(2025, 6, 15), available: false, timeSlots: [] }
    ]
  },
  {
    id: PROVIDER_IDS.therapy,
    name: 'Ricardo Almeida',
    role: 'Psicólogo',
    focus: 'Psicólogo com abordagem em Terapia Cognitivo-Comportamental (TCC). Ofereço suporte para o desenvolvimento de habilidades de enfrentamento, autoconhecimento e superação de desafios emocionais e comportamentais.', // <--- EXPANDIDO
    stars: 4.9,
    imageUrl: 'https://randomuser.me/api/portraits/men/55.jpg',
    availability: [
      // 
      { date: createDate(2025, 6, 9), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:00', available: true }, { time: '11:00', available: true }, { time: '14:00', available: true }, { time: '15:00', available: true }, { time: '16:00', available: true } ] },
      { date: createDate(2025, 6, 10), available: true, timeSlots: [ { time: '14:00', available: true }, { time: '15:00', available: true }, { time: '16:00', available: true }, { time: '17:00', available: true }, { time: '18:00', available: true } ] },
      { date: createDate(2025, 6, 11), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:00', available: true }, { time: '11:00', available: true } ] },
      { date: createDate(2025, 6, 12), available: true, timeSlots: [ { time: '14:00', available: true }, { time: '15:00', available: true }, { time: '16:00', available: true }, { time: '17:00', available: true } ] },
      { date: createDate(2025, 6, 13), available: false, timeSlots: [] },
      { date: createDate(2025, 6, 14), available: false, timeSlots: [] },
      { date: createDate(2025, 6, 15), available: false, timeSlots: [] }
    ]
  },
  {
    id: PROVIDER_IDS.yoga,
    name: 'Juliana Mendonça',
    role: 'Instrutora de Yoga',
    focus: 'Instrutora de Hatha Yoga e Meditação, apaixonada por guiar práticas que conectam corpo, mente e respiração. Aulas para todos os níveis, com foco em autoconhecimento, flexibilidade, força e paz interior.', // <--- EXPANDIDO
    stars: 4.6,
    imageUrl: 'https://randomuser.me/api/portraits/women/33.jpg',
    availability: [
      //
      { date: createDate(2025, 6, 9), available: true, timeSlots: [ { time: '07:00', available: true }, { time: '08:00', available: true }, { time: '18:00', available: true }, { time: '19:00', available: true } ] },
      { date: createDate(2025, 6, 10), available: false, timeSlots: [] },
      { date: createDate(2025, 6, 11), available: true, timeSlots: [ { time: '07:00', available: true }, { time: '08:00', available: true }, { time: '18:00', available: true }, { time: '19:00', available: true } ] },
      { date: createDate(2025, 6, 12), available: false, timeSlots: [] },
      { date: createDate(2025, 6, 13), available: true, timeSlots: [ { time: '07:00', available: true }, { time: '08:00', available: true }, { time: '18:00', available: true }, { time: '19:00', available: true } ] },
      { date: createDate(2025, 6, 14), available: true, timeSlots: [ { time: '09:00', available: true }, { time: '10:00', available: true } ] },
      { date: createDate(2025, 6, 15), available: false, timeSlots: [] }
    ]
  }
];

// Dados mockados de agendamentos 
const bookings = [
  
  { id: uuidv4(), providerId: PROVIDER_IDS.massage, date: '2025-06-10', time: '10:30', clientDetails: { name: 'João Silva', phone: '(11) 98765-4321', email: 'joao.silva@email.com', address: 'Rua das Flores, 123 - São Paulo, SP', notes: 'Primeira sessão de massagem' }, status: 'confirmed' },
  { id: uuidv4(), providerId: PROVIDER_IDS.physio, date: '2025-06-11', time: '14:00', clientDetails: { name: 'Amanda Oliveira', phone: '(11) 97654-3210', email: 'amanda.oliveira@email.com', address: 'Av. Paulista, 1000 - São Paulo, SP', notes: 'Continuar tratamento de ombro' }, status: 'confirmed' },
  { id: uuidv4(), providerId: PROVIDER_IDS.nutrition, date: '2025-06-12', time: '09:30', clientDetails: { name: 'Pedro Santos', phone: '(11) 96543-2109', email: 'pedro.santos@email.com', address: 'Rua Augusta, 500 - São Paulo, SP', notes: 'Consulta de acompanhamento mensal' }, status: 'confirmed' },
  { id: uuidv4(), providerId: PROVIDER_IDS.therapy, date: '2025-06-09', time: '15:00', clientDetails: { name: 'Marcia Lima', phone: '(11) 95432-1098', email: 'marcia.lima@email.com', address: 'Rua Oscar Freire, 200 - São Paulo, SP', notes: '' }, status: 'confirmed' },
  { id: uuidv4(), providerId: PROVIDER_IDS.yoga, date: '2025-06-10', time: '07:00', clientDetails: { name: 'Roberto Martins', phone: '(11) 94321-0987', email: 'roberto.martins@email.com', address: 'Rua Consolação, 800 - São Paulo, SP', notes: 'Iniciante em yoga' }, status: 'confirmed' },
  { id: uuidv4(), providerId: PROVIDER_IDS.massage, date: '2025-06-05', time: '14:00', clientDetails: { name: 'Carolina Dias', phone: '(11) 93210-9876', email: 'carolina.dias@email.com', address: 'Alameda Santos, 400 - São Paulo, SP', notes: 'Preferência por massagem com pressão moderada' }, status: 'cancelled' },
  { id: uuidv4(), providerId: PROVIDER_IDS.physio, date: '2025-06-15', time: '10:00', clientDetails: { name: 'Fernando Costa', phone: '(11) 91098-7654', email: 'fernando.costa@email.com', address: 'Rua Bela Cintra, 300 - São Paulo, SP', notes: 'Recuperação de lesão no joelho' }, status: 'confirmed' }
];

module.exports = {
  providers,
  bookings
};