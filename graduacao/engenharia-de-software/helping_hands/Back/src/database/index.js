const { Sequelize } = require('sequelize');
const path = require('path');

// Definir o caminho para o arquivo do banco de dados
const dbPath = path.resolve(__dirname, '..', '..', 'database.sqlite');

// Criar a conexão com o SQLite
const sequelize = new Sequelize({
  dialect: 'sqlite',
  storage: dbPath,
  logging: false 
});

// Função para testar a conexão
const testConnection = async () => {
  try {
    await sequelize.authenticate();
    console.log('Conexão com o banco de dados estabelecida com sucesso.');
  } catch (error) {
    console.error('Não foi possível conectar ao banco de dados:', error);
  }
};

module.exports = {
  sequelize,
  testConnection
};