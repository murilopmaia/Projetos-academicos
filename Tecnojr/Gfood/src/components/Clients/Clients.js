import { ClientesData } from "../../data/ClientesData";
import { useState } from "react";

//css
import "./Clients.css";
//Imagem
import Hamburguer_img from "../../assets/Hamburguer.png";

function Clientes() {
  const [Ind, setInd] = useState(0);
  const direita = "\u2192"; //codigo de uma seta em ascii
  const esquerda = "\u2190";

  function handleEsquerda() {
    //Diminui o indice da lista
    if (Ind - 1 === -1) {
      setInd(ClientesData.length - 1);
    } else {
      setInd((prevInd) => prevInd - 1);
    }
  }

  function handleDireita() {
    //Aumenta o indice da lista
    if (Ind + 1 === ClientesData.length) {
      setInd(0);
    } else {
      setInd((prevInd) => prevInd + 1);
    }
  }

  return (
    <div className="Clientes_tudo">
      <div className="Cliente_titulo">
        <p>Testimonials</p>
        <h3>Our Happy Client Says</h3>
      </div>

      <div className="Clientes_Corpo">
        <div className="Cliente_descri">
          <div className="Fundo_cliente_branco"></div>

          <button onClick={handleEsquerda}>{esquerda}</button>

          <div className="Cliente_corpo_info">
            <div className="Cliente_perfil">
              <div className="Imagem_foto">
                <img
                  width="100%"
                  src={ClientesData[Ind].Foto}
                  alt={ClientesData[Ind].Nome}
                />
              </div>

              <div className="Cliente_Nome">
                <h5>{ClientesData[Ind].Nome}</h5>
                <p>{ClientesData[Ind].Descri}</p>
              </div>
            </div>

            <p className="Texto_coment">{ClientesData[Ind].Comentario}</p>
          </div>

          <button onClick={handleDireita}>{direita}</button>
        </div>

        <img
          className="Imagem_hamb"
          width="40%"
          src={Hamburguer_img}
          alt="Hambuguer"
        />
      </div>
    </div>
  );
}

export default Clientes;
