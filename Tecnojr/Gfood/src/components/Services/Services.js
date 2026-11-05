import { useRef, forwardRef } from "react";

//css
import "./Services.css";

//Imagem
import Garfo_faca_img from "../../assets/Garfo_faca.png";
import Colher_Garfo_img from "../../assets/Colher_Garfo.png";
import Transporte_img from "../../assets/Transporte.png";

function Services({}, ScrollService) { //ScrollService é para focar nesse componenete(ref)
  return (
    <div className="Services_corpo">
      <div className="Services_titulo">
        <p ref={ScrollService}>Services</p>
        <h3>Why Choose Our Favorite Food</h3>
      </div>

      <div className="Services_services">
        <div className="Services_extremidade">
          <img src={Garfo_faca_img} alt="Qualidade" />
          <h4>Qualityfull Food</h4>
          <p>
            But I must explain to you how all this mistaken idea of denouncing
            pleasur and prasising pain was bron.
          </p>
        </div>

        <div className="Services_meio">
          <img src={Colher_Garfo_img} alt="Saude" />
          <h4>Healthy Food</h4>
          <p>
            But I must explain to you how all this mistaken idea of denouncing
            pleasur and prasising pain was bron.
          </p>
        </div>

        <div className="Services_extremidade">
          <img src={Transporte_img} alt="Transporte" />
          <h4>Healthy Food</h4>
          <p>
            But I must explain to you how all this mistaken idea of denouncing
            pleasur and prasising pain was bron.
          </p>
        </div>
      </div>
    </div>
  );
}

export default forwardRef(Services);
