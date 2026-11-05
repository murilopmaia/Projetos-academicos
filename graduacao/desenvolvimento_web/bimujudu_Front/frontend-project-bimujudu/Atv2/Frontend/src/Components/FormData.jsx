import React, { useState, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import "../Styles/FormData.css";

function FormData() {
  const [result, setResult] = useState([]);
  const [dataToInsert, setDataToInsert] = useState({
    MotoristaName: "",
    LocalSaida: "",
    LocalDestino: "",
    QuantidadeVagas: "",
    Estrelas: "",
    Valor: "",
    HoraDiaSaida: "",
  });

  const [redirected, setRedirected] = useState(false);
  const [errors, setErrors] = useState({});
  const navigate = useNavigate();

  useEffect(() => {
    fetch("http://localhost:3000")
      .then((res) => res.json())
      .then((data) => {
        setResult(data);
        const foundItem = data.find(
          (item) => window.location.pathname === `/modify/${item.MotoristaID}`
        );
        if (foundItem) {
          setDataToInsert((prevState) => ({
            ...prevState,
            ...foundItem,
          }));
        } else if (!redirected) {
          setRedirected(true);
          navigate("/");
        }
      })
      .catch((err) => console.error(err));
  }, []);

  // Validação dos dados do formulário
  const validateForm = () => {
    const newErrors = {};

    // Verifica se os campos estão preenchidos
    if (!dataToInsert.MotoristaName.trim()) newErrors.MotoristaName = "Nome é obrigatório";
    if (!dataToInsert.LocalSaida.trim()) newErrors.LocalSaida = "Local de saída é obrigatório";
    if (!dataToInsert.LocalDestino.trim()) newErrors.LocalDestino = "Local de destino é obrigatório";
    if (!dataToInsert.QuantidadeVagas) newErrors.QuantidadeVagas = "Quantidade de vagas é obrigatória";
    if (!dataToInsert.Estrelas) newErrors.Estrelas = "A avaliação é obrigatória"
    if (!dataToInsert.Valor) newErrors.Valor = "Valor é obrigatório";
    if (!dataToInsert.HoraDiaSaida) newErrors.HoraDiaSaida = "Data e hora são obrigatórias";

    // Validação para valores numéricos
    if (dataToInsert.QuantidadeVagas <= 0) newErrors.QuantidadeVagas = "Quantidade de vagas deve ser maior que zero";
    if (dataToInsert.Valor <= 0) newErrors.Valor = "Valor deve ser maior que zero";

    // Validação para estrelas
    if (dataToInsert.Estrelas < 0 || dataToInsert.Estrelas > 5)
      newErrors.Estrelas = "Estrelas deve ser um valor entre 0 e 5";

    // Validação para data futura
    const now = new Date();
    const selectedDate = new Date(dataToInsert.HoraDiaSaida);
    if (selectedDate <= now) newErrors.HoraDiaSaida = "A data deve ser futura";

    setErrors(newErrors);

    return Object.keys(newErrors).length === 0; // Retorna true se não houver erros
  };

  // Envio do formulário
  const handleSubmit = (e) => {
    e.preventDefault();
  
    if (!validateForm()) return; // Validação antes do envio
  
    const foundItem = result.find(
      (item) => window.location.pathname === `/modify/${item.MotoristaID}`
    );
  
    const method = foundItem ? "PUT" : "POST";
  
    fetch("http://localhost:3000", {
      method,
      body: JSON.stringify(dataToInsert),
      headers: { "Content-Type": "application/json" },
    })
      .then(() => {
        // Redireciona para a página inicial após a atualização
        navigate("/");
        // Recarrega a página para garantir que os dados sejam atualizados
        window.location.reload();
      })
      .catch((err) => console.error(err));
  };

  // Atualiza os dados do estado conforme o usuário digita
  const handleChange = (e) => {
    setDataToInsert({
      ...dataToInsert,
      [e.target.name]: e.target.value,
    });
  };

  return (
    <div className="form_div">
      <form onSubmit={handleSubmit} className="form">
        <input
          className="form_input"
          type="text"
          value={dataToInsert.MotoristaName}
          name="MotoristaName"
          onChange={handleChange}
          placeholder="Nome do(a) motorista"
        />
        {errors.MotoristaName && <p className="error">{errors.MotoristaName}</p>}

        <input
          className="form_input"
          type="text"
          value={dataToInsert.LocalSaida}
          name="LocalSaida"
          onChange={handleChange}
          placeholder="Local de Saida"
        />
        {errors.LocalSaida && <p className="error">{errors.LocalSaida}</p>}

        <input
          className="form_input"
          type="text"
          value={dataToInsert.LocalDestino}
          name="LocalDestino"
          onChange={handleChange}
          placeholder="Destino"
        />
        {errors.LocalDestino && <p className="error">{errors.LocalDestino}</p>}

        <input
          className="form_input"
          type="number"
          value={dataToInsert.QuantidadeVagas}
          name="QuantidadeVagas"
          onChange={handleChange}
          placeholder="Quantidade de vagas"
        />
        {errors.QuantidadeVagas && <p className="error">{errors.QuantidadeVagas}</p>}

        <input
          className="form_input"
          type="number"
          value={dataToInsert.Estrelas}
          name="Estrelas"
          onChange={handleChange}
          placeholder="Estrelas (avaliação)"
        />
        {errors.Estrelas && <p className="error">{errors.Estrelas}</p>}

        <input
          className="form_input"
          type="number"
          value={dataToInsert.Valor}
          name="Valor"
          onChange={handleChange}
          placeholder="Valor da carona"
        />
        {errors.Valor && <p className="error">{errors.Valor}</p>}

        <input
          className="form_input"
          type="datetime-local"
          value={dataToInsert.HoraDiaSaida}
          name="HoraDiaSaida"
          onChange={handleChange}
        />
        {errors.HoraDiaSaida && <p className="error">{errors.HoraDiaSaida}</p>}

        <button type="submit" className="form_button">
          Save
        </button>
      </form>
    </div>
  );
}

export default FormData;
