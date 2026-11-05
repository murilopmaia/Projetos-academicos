//css
import "./How_to_work.css";

//Imagem
import Tela_not_img from "../../assets/Tela_not.png";
import Food_img from "../../assets/Food.png";
import Sacolas_img from "../../assets/Sacolas.png";

function How_to_work() {
  return (
    <div className="How_corpo">
      <div className="How_titulo">
        <p>How to work</p>
        <h3>Food Us An Important Part Of A Balanced Diet</h3>
      </div>

      <div className="How_infos">
        <div className="How_esquerdo">
          <img src={Tela_not_img} alt="Tela" />

          <div className="Nome_bolinha_esquerdo">
            <h4>CHOOSE</h4>
            <div className="Bolinha">
              <p></p>
            </div>
          </div>
          <p>
            Do you want to lose weight, exercise, adhere to a therapeutic diet?
            Our dietitian will help you with choosing the right program!
          </p>
        </div>

        <div className="How_meio">
          <div className="Nome_bolinha_meio">
            <div className="Bolinha"></div>
            <h4>PREPARE FOOD</h4>
            <div className="Bolinha"></div>
          </div>
          <p>
            Do you want to lose weight, exercise, adhere to a therapeutic diet?
            Our dietitian will help you with choosing the right program!
          </p>
          <img src={Food_img} alt="Food" />
        </div>

        <div className="How_direito">
          <img src={Sacolas_img} alt="Sacolas" />
          <div className="Nome_bolinha_direito">
            <div className="Bolinha"></div>
            <h4>DELIVER</h4>
          </div>

          <p>
            Do you want to lose weight, exercise, adhere to a therapeutic diet?
            Our dietitian will help you with choosing the right program!
          </p>
        </div>
      </div>
    </div>
  );
}

export default How_to_work;
