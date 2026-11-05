import { Link, useNavigate } from "react-router-dom";
//css
import "./Topo.css";
//Components
import Vitrine from "../Vitrine/Vitrine";
//Lista de Alimentos
import { ListaAlimentos } from "../../data/ListaAlimentos";

function Topo() {
  const Navigate = useNavigate();
  return (
    <div className="Corpo_topo">
      <div className="Esquerdo">
        <div className="Bike_delivery">
          <h5>Bike Delivery</h5>
          <div className="Bike">
            <img
              width="40px"
              src="https://static.vecteezy.com/system/resources/previews/014/064/648/original/motorbike-for-food-delivery-service-online-ordering-concept-png.png"
              alt="Bike"
            />
          </div>
        </div>

        <div className="Textos">
          <div className="Texto_central">
            <h1>The Fastest</h1>
            <h1>Delivery</h1>
            <div className="Texto_linha">
              <h1>IN</h1>
              <h1 className="Texto_cor">Your City</h1>
            </div>
          </div>

          <div className="Mini_texto">
            <p>
              Lorem ipsum dolor sit amet, consectetur adipiscing elit. Commodo,
              sed proin amet a vestibulum enim volutpat lacus. Volutpat arcu sit
              sed tortor etiam volutpat ipsum.{" "}
            </p>
          </div>
        </div>

        <div className="Botoes">
          <Link to="/Login" className="Bot_esquerdo">
            Order Now
          </Link>

          <div className="Alinhar">
            <button
              onClick={() => {
                Navigate("/Order");
              }}
              className="Bot_direito"
            >
              <img
                width="40px"
                src="https://iconsplace.com/wp-content/uploads/_icons/ffa500/256/png/play-icon-11-256.png"
                alt="icon"
              />
            </button>
            <h4>Order Process</h4>
          </div>
        </div>
      </div>

      <div className="Direito">
        <div className="fundo_cinza"></div>
        <div className="Cima">
          <Vitrine Apresente={ListaAlimentos.Vitrine1} />
          <Vitrine Apresente={ListaAlimentos.Vitrine2} />
        </div>
        <div className="Baixo">
          <Vitrine Apresente={ListaAlimentos.Vitrine3} />
          <Vitrine Apresente={ListaAlimentos.Vitrine4} />
        </div>
      </div>
    </div>
  );
}

export default Topo;
