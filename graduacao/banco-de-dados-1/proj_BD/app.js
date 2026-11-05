const express = require("express");
const app = express();
const mySql = require("./db.js");
app.use(express.urlencoded({ extended: false }));
app.set("engine ejs", "ejs");
app.use(express.static("public"));

app.get("/", function (req, res) {
  let sql = `SELECT * FROM Cliente, Reserva `;
  const orderby = req.query.orderby;
  const leftJoin = req.query.leftJoin;
  if (leftJoin) {
    sql +=
      " left join Combo on Cod_Combo = Cod_ComboFK left join Gato on Cod_Gato = Cod_GatoFK where CPF_Cliente = CPF_ClienteFK";
  } else {
    sql +=
      ", Gato, Combo WHERE Cod_Gato=Cod_GatoFK AND CPF_Cliente=CPF_ClienteFK AND Cod_Combo = Cod_ComboFK";
  }

  if (orderby) {
    sql += ` ORDER BY ${orderby} `;
  }

  mySql.query(sql, [], function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("index.ejs", { dados: rows });
  });
});

app.get("/Gatos", function (req, res) {
  const orderby = req.query.orderby;
  const groupby = req.query.groupBy;
  const having = req.query.having;
  const rollup = req.query.rollup;
  let aplicar = false;
  let sql;
  if (groupby) {
    aplicar = true;
    sql =
      "select raca, count(*) as quantidade, min(idade_Gato) as idade_minima, max(idade_Gato) as idade_maxima from gato group by raca";

    if (rollup) {
      sql += ` WITH ROLLUP `;
    }
    if (having) {
      sql += ` HAVING ${having} `;
    }
  } else {
    sql = "SELECT * FROM Gato ";
  }
  if (orderby) {
    sql += ` ORDER BY ${orderby} `;
  }

  mySql.query(sql, [], function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("Gatos.ejs", { dados: rows, aplicar: aplicar });
  });
});

app.get("/Clientes", function (req, res) {
  let sql = "SELECT * FROM Cliente";
  const orderby = req.query.orderby;
  if (orderby) {
    sql += ` ORDER BY ${orderby} `;
  }
  mySql.query(sql, [], function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("Cliente.ejs", { dados: rows });
  });
});

app.get("/Reservas", function (req, res) {
  let sql = "SELECT * FROM Reserva";
  const orderby = req.query.orderby;
  if (orderby) {
    sql += ` order by ${orderby}`;
  }

  mySql.query(sql, [], function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("Reservas.ejs", { dados: rows });
  });
});

app.get("/Combos", function (req, res) {
  const orderby = req.query.orderby;
  const groupby = req.query.groupBy;
  const having = req.query.having;
  const rollup = req.query.rollup;
  let aplicar = false;
  let sql;
  if (groupby) {
    aplicar = true;
    sql =
      "select Disponibilidade, count(*) as quantidade, min(valor) as valor_minimo, max(valor) as valor_maximo from Combo group by Disponibilidade";

    if (rollup) {
      sql += ` WITH ROLLUP `;
    }
    if (having) {
      sql += ` HAVING ${having} `;
    }
  } else {
    sql = "SELECT * FROM Combo ";
  }
  if (orderby) {
    sql += ` ORDER BY ${orderby} `;
  }

  mySql.query(sql, [], function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("Combo.ejs", { dados: rows, aplicar: aplicar });
  });
});

// inserir reserva

app.get("/inserirR", function (req, res) {
  const sql1 =
    "SELECT CPF_Cliente, Nome_Cliente from Cliente order by Nome_Cliente";
  const sql2 = "SeLECT Cod_Combo from Combo order by Cod_Combo";
  const sql3 = "SELECT Cod_Gato, Nome_Gato from Gato order by Nome_Gato";
  mySql.query(sql1, [], function (err, rows1) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    mySql.query(sql2, [], function (err, rows2) {
      if (err) {
        return console.error("Erro no retorno da SELECT...");
      }

      mySql.query(sql3, [], function (err, rows3) {
        if (err) {
          return console.error("Erro no retorno da SELECT...");
        }

        res.render("inserirR.ejs", {
          dados1: rows1,
          dados2: rows2,
          dados3: rows3,
        });
      });
    });
  });
});

app.post("/inserirR", function (req, res) {
  const sql1 = `INSERT INTO Reserva
    (CPF_ClienteFK, Cod_GatoFK, Cod_ComboFK, horario_inicio, 
    horario_fim,
    Status_Pagamento,
    Numero_Mesa) 
    values (?, ?, ?, ?, ?, ?, ?)`;
  req.body.Cod_Gato = req.body.Cod_Gato === "NULL" ? null : req.body.Cod_Gato;
  req.body.Cod_Combo = req.body.Cod_Combo == "NULL" ? null : req.body.Cod_Combo;

  const dadosMestre = [
    req.body.CPF_Cliente,
    req.body.Cod_Gato,
    req.body.Cod_Combo,
    req.body.horario_inicio,
    req.body.horario_fim,
    req.body.Status_Pagamento,
    req.body.Numero_Mesa,
  ];
  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      console.log("Erro no Insert....");
    }
    res.redirect("/");
  });
});

//inserir gato

app.get("/inserirG", function (req, res) {
  res.render("inserirG.ejs");
});

app.post("/inserirG", function (req, res) {
  const sql1 = `INSERT INTO Gato
    (Cod_Gato, 
    Nome_Gato, 
    raca, 
    idade_Gato) 
    values (?, ?, ?, ?)`;

  const dadosMestre = [
    req.body.Cod_Gato,
    req.body.Nome_Gato,
    req.body.raca,
    req.body.idade_Gato,
  ];
  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      console.log("Erro no Insert....");
    }
    res.redirect("/Gatos");
  });
});

//inserir cliente


app.get("/inserirCl", function (req, res) {
  res.render("inserirCl.ejs");
});

app.post("/inserirCl", function (req, res) {
  const sql1 = `INSERT INTO Cliente
    (CPF_Cliente, 
    Nome_Cliente, 
    idade_Cliente, 
    telefone_Cliente) 
    values (?, ?, ?, ?)`;

  const dadosMestre = [
    req.body.CPF_Cliente,
    req.body.Nome_Cliente,
    req.body.idade_Cliente,
    req.body.telefone_Cliente,
  ];
  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      console.log("Erro no Insert....");
    }
    res.redirect("/Clientes");
  });
});

//inserir combo

app.get("/inserirCo", function (req, res) {
  res.render("inserirCo.ejs");
});

app.post("/inserirCo", function (req, res) {
  const sql1 = `INSERT INTO Combo
    (Cod_Combo, 
    Bebida, 
    Comida, 
    Disponibilidade,
    Valor) 
    values (?, ?, ?, ?, ?)`;

  const dadosMestre = [
    req.body.Cod_Combo,
    req.body.Bebida,
    req.body.Comida,
    req.body.Disponibilidade,
    req.body.Valor,
  ];
  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      console.log("Erro no Insert....");
    }
    res.redirect("/Combos");
  });
});

//editar

app.get("/editarR/:Cod_Reserva", function (req, res) {
  const Cod_Reserva = req.params.Cod_Reserva;

  const sql = `select * from Cliente, Reserva left join Combo on (Cod_ComboFK = Cod_Combo) left join gato on (Cod_Gato = Cod_GatoFK)
  where (Cod_Reserva = ?) and (CPF_Cliente = CPF_ClienteFK)`;
  const sql4 =
    "SELECT CPF_Cliente, Nome_Cliente from Cliente where (CPF_Cliente <> ?) order by Nome_Cliente";
  let sql2;
  let sql3;

  mySql.query(sql, Cod_Reserva, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...1");
    }
    const CPF_Cliente = rows[0].CPF_ClienteFK;
    const Cod_Combo = rows[0].Cod_ComboFK;
    if (Cod_Combo) {
      sql2 =
        "SeLECT Cod_Combo from Combo where (Cod_Combo <> ?) order by Cod_Combo";
    } else {
      sql2 = "SELECT Cod_Combo from Combo order by Cod_Combo";
    }
    const Cod_Gato = rows[0].Cod_GatoFK;
    if (Cod_Gato) {
      sql3 =
        "SeLECT Cod_Gato, Nome_Gato from Gato where (Cod_Gato <> ?) order by Cod_Gato";
    } else {
      sql3 = "SeLECT Cod_Gato, Nome_Gato from Gato order by Cod_Gato";
    }

    mySql.query(sql2, Cod_Combo, function (err, rows2) {
      if (err) {
        return console.error("Erro no retorno da SELECT...2");
      }

      mySql.query(sql3, Cod_Gato, function (err, rows3) {
        if (err) {
          return console.error("Erro no retorno da SELECT...3");
        }

        mySql.query(sql4, CPF_Cliente, function (err, rows11) {
          if (err) {
            return console.error("Erro no retorno da SELECT...4");
          }

          res.render("editarR.ejs", {
            dados: rows,
            dados1: rows11,
            dados2: rows2,
            dados3: rows3,
          });
        });
      });
    });
  });
});

app.post("/editarR/:Cod_Reserva", function (req, res) {
  let Cod_Reserva = req.params.Cod_Reserva;
  const sql1 = `Update Reserva set
        CPF_ClienteFK = ?, Cod_GatoFK = ?, Cod_ComboFK = ?, horario_inicio = ?, horario_fim = ?,
        Status_Pagamento = ?, Numero_Mesa = ? 
        where (Cod_Reserva = ?)`;
  req.body.Cod_Gato = req.body.Cod_Gato === "NULL" ? null : req.body.Cod_Gato;
  req.body.Cod_Combo = req.body.Cod_Combo == "NULL" ? null : req.body.Cod_Combo;
  const dadosMestre = [
    req.body.CPF_Cliente,
    req.body.Cod_Gato,
    req.body.Cod_Combo,
    req.body.horario_inicio,
    req.body.horario_fim,
    req.body.Status_Pagamento,
    req.body.Numero_Mesa,
    Cod_Reserva,
  ];

  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      return console.error("Erro no retorno da Update...");
    }
    res.redirect("/");
  });
});

//editar gato

app.get("/editarG/:Cod_Gato", function (req, res) {
  const Cod_Gato = req.params.Cod_Gato;
  const sql = `select * from Gato where cod_Gato = ?`;
  mySql.query(sql, Cod_Gato, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...1");
    }
    res.render("editarG.ejs", {
      dados: rows,
    });
  });
});

app.post("/editarG/:Cod_Gato", function (req, res) {
  let Cod_Gato = req.params.Cod_Gato;
  const sql1 = `Update Gato set
        Nome_Gato = ?, raca = ?, idade_Gato = ?
        where (Cod_Gato = ?)`;
        
  const dadosMestre = [
    req.body.Nome_Gato,
    req.body.raca,
    req.body.idade_Gato,
    Cod_Gato,
  ];

  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      return console.error("Erro no retorno da Update...");
    }
    res.redirect("/Gatos");
  });
});

//editar cliente

app.get("/editarCl/:CPF_Cliente", function (req, res) {
  const CPF_Cliente = req.params.CPF_Cliente;
  const sql = `select * from Cliente where CPF_Cliente = ?`;
  mySql.query(sql, CPF_Cliente, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...1");
    }
    res.render("editarCl.ejs", {
      dados: rows,
    });
  });
});

app.post("/editarCl/:CPF_Cliente", function (req, res) {
  let CPF_Cliente = req.params.CPF_Cliente;
  const sql1 = `Update Cliente set
        Nome_Cliente = ?, idade_Cliente = ?, telefone_Cliente = ?
        where (CPF_Cliente = ?)`;
        
  const dadosMestre = [
    req.body.Nome_Cliente,
    req.body.idade_Cliente,
    req.body.telefone_Cliente,
    CPF_Cliente,
  ];

  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      return console.error("Erro no retorno da Update...");
    }
    res.redirect("/Clientes");
  });
});

//editar combo

app.get("/editarCo/:Cod_Combo", function (req, res) {
  const Cod_Combo = req.params.Cod_Combo;
  const sql = `select * from Combo where Cod_Combo = ?`;
  mySql.query(sql, Cod_Combo, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...1");
    }
    res.render("editarCo.ejs", {
      dados: rows,
    });
  });
});

app.post("/editarCo/:Cod_Combo", function (req, res) {
  let Cod_Combo = req.params.Cod_Combo;
  const sql1 = `Update Combo set
        Bebida = ?, Comida = ?, Disponibilidade = ?, Valor = ?
        where (Cod_Combo = ?)`;
        
  const dadosMestre = [
    req.body.Bebida,
    req.body.Comida,
    req.body.Disponibilidade,
    req.body.Valor,
    Cod_Combo,
  ];

  mySql.query(sql1, dadosMestre, function (err) {
    if (err) {
      return console.error("Erro no retorno da Update...");
    }
    res.redirect("/Combos");
  });
});

// remover

app.get("/deletarR/:Cod_Reserva", function (req, res) {
  const Cod_Reserva = req.params.Cod_Reserva;
  const sql = `select * from Cliente, Reserva left join Combo on (Cod_ComboFK = Cod_Combo) left join gato on (Cod_Gato = Cod_GatoFK)
  where (Cod_Reserva = ?) and (CPF_Cliente = CPF_ClienteFK)`;

  mySql.query(sql, Cod_Reserva, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("deletarR.ejs", {
      dados: rows,
    });
  });
});

app.post("/deletarR/:Cod_Reserva", function (req, res) {
  const Cod_Reserva = req.params.Cod_Reserva;
  const sql = "delete from Reserva where (Cod_Reserva = ?)";
  mySql.query(sql, Cod_Reserva, function (err) {
    if (err) {
      return console.error(err.message);
    }
    res.redirect("/");
  });
});

// remover gato

app.get("/deletarG/:Cod_Gato", function (req, res) {
  const Cod_Gato = req.params.Cod_Gato;
  const sql = `select * from Gato where cod_Gato = ?`;

  mySql.query(sql, Cod_Gato, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("deletarG.ejs", {
      dados: rows,
    });
  });
});

app.post("/deletarG/:Cod_Gato", function (req, res) {
  const Cod_Gato = req.params.Cod_Gato;
  const sql = "delete from Gato where (Cod_Gato = ?)";
  mySql.query(sql, Cod_Gato, function (err) {
    if (err) {
      return console.error(err.message);
    }
    res.redirect("/Gatos");
  });
});

//deletar cliente

app.get("/deletarCl/:CPF_Cliente", function (req, res) {
  const CPF_Cliente = req.params.CPF_Cliente;
  const sql = `select * from Cliente where CPF_Cliente = ?`;

  mySql.query(sql, CPF_Cliente, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("deletarCl.ejs", {
      dados: rows,
    });
  });
});

app.post("/deletarCl/:CPF_Cliente", function (req, res) {
  const CPF_Cliente = req.params.CPF_Cliente;
  const sql = "delete from Cliente where (CPF_Cliente = ?)";
  mySql.query(sql, CPF_Cliente, function (err) {
    if (err) {
      return console.error(err.message);
    }
    res.redirect("/Clientes");
  });
});

//deletar combo

app.get("/deletarCo/:Cod_Combo", function (req, res) {
  const Cod_Combo = req.params.Cod_Combo;
  const sql = `select * from Combo where Cod_Combo = ?`;

  mySql.query(sql, Cod_Combo, function (err, rows) {
    if (err) {
      return console.error("Erro no retorno da SELECT...");
    }

    res.render("deletarCo.ejs", {
      dados: rows,
    });
  });
});

app.post("/deletarCo/:Cod_Combo", function (req, res) {
  const Cod_Combo = req.params.Cod_Combo;
  const sql = "delete from Combo where (Cod_Combo = ?)";
  mySql.query(sql, Cod_Combo, function (err) {
    if (err) {
      return console.error(err.message);
    }
    res.redirect("/Combos");
  });
});

app.listen(3000, () => {
  console.log("SERVIDOR ATIVO, ACESSE http://localhost:3000");
});
