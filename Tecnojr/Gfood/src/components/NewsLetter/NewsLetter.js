import { useState } from "react";

//css
import "./NewsLetter.css";

//Imagem
import Hamb_letter_img from "../../assets/Hamb_Letter.png";

function NewsLetter() {
  const [Escrita, setEscrita] = useState("");//valor do input
  const [Confirma, setConfirma] = useState("Type your email.....");//valor do placeholder

  function HandleSubmit(e) {
    e.preventDefault();
    if (Escrita !== "") {
      setConfirma("Enviado!");
      setEscrita("");
    }
  }
  return (
    <div className="Corpo_NewsLetter">
      <div className="Fundo_NewsLetter"></div>
      <img width="40%" src={Hamb_letter_img} alt="Hambuguer" />
      <div className="Infos_letter">
        <h3>Subcribe To Our Newsletter</h3>
        <p>
          Lorem ipsum dolor sit amet, consectetur adipidrscing elit. Purus
          mauris sem sed urna venenatis vivamus. Egestas in velit nulla viverra
          turpis id ac. Amet faucibus tempus.
        </p>

        <form onSubmit={HandleSubmit}>
          <label>
            <input
              className="input_text"
              disabled={Confirma === "Enviado!" ? "1" : ""}
              minLength={10}
              maxLength={30}
              type="email"
              placeholder={Confirma}
              onChange={(e) => setEscrita(e.target.value)}
              value={Escrita}
            />
            <input className="input_submit" type="Submit" value="SUBCRIBE" />
          </label>
        </form>
      </div>
    </div>
  );
}

export default NewsLetter;
