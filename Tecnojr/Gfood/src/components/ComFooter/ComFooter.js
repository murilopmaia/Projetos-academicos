import { Link } from "react-router-dom";
import { useState } from "react";

//css
import "./ComFooter.css";
//Imagem
import Logo_img from "../../assets/Logo.png";
import Facebook_img from "../../assets/Facebook.png";
import Twitter_img from "../../assets/Twitter.png";
import Linkind_img from "../../assets/Linkind.png";
import Instagram_img from "../../assets/Instagram.png";

function ComFooter() {
  const [Escrita, setEscrita] = useState(""); //Value do input
  const [Confirma, setConfirma] = useState("Enter your email....."); //Placeholder do input, também usado para desabilitar o input

  function HandleSubmit(e) {
    //Altera o Placeholder, desabilitando o input
    e.preventDefault();
    if (Escrita != "") {
      setConfirma("Enviado!");
      setEscrita("");
    }
  }

  return (
    <div className="Corpo_footer">
      <footer>
        <div className="div_logo">
          <img width="50%" src={Logo_img} alt="Logo" />
          <p>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Commodo
            libero viverra dapibus odio sit malesuada in quis. Arcu tristique
            elementum viverra integer id.
          </p>
          <div className="Redes_soc">
            <img width="12%" src={Facebook_img} alt="Facebook" />
            <img width="12%" src={Twitter_img} alt="Twitter" />
            <img width="12%" src={Linkind_img} alt="Linkind" />
            <img width="12%" src={Instagram_img} alt="Instagram" />
          </div>
        </div>

        <div className="Corpo_div">
          <h4>Opening Restaurant</h4>
          <div className="Text_footer">
            <p>Sat-Wet: 09:00am-10:00PM</p>
            <p>Thursdayt: 09:00am-11:00PM</p>
            <p>Friday: 09:00am-8:00PM</p>
          </div>
        </div>

        <div className="Corpo_div">
          <h4>User Link</h4>
          <div className="Text_footer">
            <Link to="/About">
              <p>About us</p>
            </Link>
            <Link to="/Contact">
              <p>Contact Us</p>
            </Link>
            <Link to="/Order">
              <p>Order Delivery</p>
            </Link>
            <Link to="/Payment">
              <p>Payment & Tex</p>
            </Link>
            <Link to="/Terms">
              <p>Terms of Services</p>
            </Link>
          </div>
        </div>

        <div className="Corpo_div">
          <h4>Contact Us</h4>
          <div className="Footer_contato">
            <div className="Text_footer">
              <p>1234 Country Club Ave</p>
              <p>NC 123456, London, UK</p>
              <p>+0123 456 7891</p>
            </div>

            <form onSubmit={HandleSubmit}>
              <label>
                <input
                  className="in_text"
                  disabled={Confirma === "Enviado!" ? "1" : ""}
                  minLength={10}
                  maxLength={30}
                  type="email"
                  placeholder={Confirma}
                  onChange={(e) => setEscrita(e.target.value)}
                  value={Escrita}
                />
                <input className="in_submit" type="Submit" value=">" />
              </label>
            </form>
          </div>
        </div>
      </footer>
    </div>
  );
}

export default ComFooter;
