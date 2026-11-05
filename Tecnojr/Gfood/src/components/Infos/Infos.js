//css
import "./Infos.css";

//Imagem
import horario_img from "../../assets/horario.png";
import Local_img from "../../assets/Local.png";
import telefone_img from "../../assets/telefone.png";

function Infos() {
  return (
    <div className="Informa">
      <div className="Instru">
        <div>
          <img src={horario_img} alt="horas" />
        </div>

        <h5>Today 10:00am - 10:00pm</h5>
        <p>Working Time</p>
      </div>
      <div className="Linha"></div>
      <div className="Instru">
        <div>
          <img src={Local_img} alt="local" />
        </div>

        <h5>Washington, D.C., DC,USA</h5>
        <p>Our Location</p>
      </div>
      <div className="Linha"></div>
      <div className="Instru">
        <div>
          <img src={telefone_img} alt="Contato" />
        </div>

        <h5>+0123 456 7891</h5>
        <p>Phone Number</p>
      </div>
    </div>
  );
}
export default Infos;
