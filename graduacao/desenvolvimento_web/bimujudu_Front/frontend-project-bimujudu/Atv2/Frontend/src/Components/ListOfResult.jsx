import React, { useState, useEffect } from "react";
import { Link } from "react-router-dom";
import "../Styles/ListOfResult.css";

function ListOfResult() {
  // Guarda e atualiza as informações recebidas do backend.
  const [result, setResult] = useState([]);

  // Faz a solicitação das informações no backend quando a página é carrgada.
  useEffect(() => {
    fetch("http://localhost:3000")
      .then((res) => res.json())
      .then((data) => {
        setResult(data);
        console.log(data);
      })
      .catch((err) => {
        console.error(err);
      });
  }, []);

  // Detecta em qual cartão de informação estamos clicando, obém o MotoristaID e o envia para o backend, que será responsável por excluir os dados do bd.

  const handleDelete = (e) => {
    console.log(e.target.name);
    
    if (confirm("Tem certeza que deseja excluir estas informações?")) {
      console.log("Informação excluída");
      fetch("http://localhost:3000", {
        method: "DELETE",
        body: JSON.stringify({
          ["MotoristaID"]: e.target.name,
        }),
        headers: { "Content-Type": "application/json" },
      });
      // Atualiza a página para atualizar os dados do bd.
      window.location.reload();
    } else {
      console.log("Pedido de exclusão cancelado.");
    }
  };

  const formatDateTime = (dateTime) => {
    if (!dateTime) return "Data inválida";
  
    const date = new Date(dateTime); // Converte para objeto Date
    if (isNaN(date)) return "Data inválida";
  
    return date.toLocaleString("pt-BR", {
      day: "2-digit",
      month: "2-digit",
      year: "numeric",
      hour: "2-digit",
      minute: "2-digit",
    });
  };

  return (
    <div className="results">
      <h1 className="title_results">Resultados</h1>
      <section className="section_all_results">
        {result.map((item, index) => (
          <section key={index} className="section_individual_result">
            <article>
              <p className="m_results"><strong>Nome motorista:</strong> {item.MotoristaName}</p>
              <p className="m_results"><strong>Saída:</strong> {item.LocalSaida}</p>
              <p className="m_results"><strong>Destino:</strong> {item.LocalDestino}</p>
              <p className="m_results"><strong>Quantidade de Vagas:</strong> {item.QuantidadeVagas}</p>
              <p className="m_results"><strong>Estrelas:</strong> {item.Estrelas}</p>
              <p className="m_results"><strong>Valor:</strong> {item.Valor}</p>
              <p className="m_results"><strong>Hora e dia de Saída:</strong> {formatDateTime(item.HoraDiaSaida)}</p>
            </article>
            <div className="div_buttons_results">
              <Link to={`/modify/${item.MotoristaID}`}>
                <button className="modify_results">Modificar</button>
              </Link>
              <button
                name={item.MotoristaID}
                onClick={handleDelete}
                className="delete_results"
              >
                Excluir
              </button>
            </div>
          </section>
        ))}
      </section>
    </div>
  );
}

export default ListOfResult;
