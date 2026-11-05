var mysql = require('mysql');

var conexao = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password:'Senha',
    database: 'CatCoffe',
    multipleStatements: true
});

conexao.connect();

module.exports = conexao;

