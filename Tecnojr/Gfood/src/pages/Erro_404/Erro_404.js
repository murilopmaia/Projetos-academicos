import { Link } from "react-router-dom";
//css
import "./Erro_404.css";
//Imagem
import Sad_img from "../../assets/Icon_sad.png";
function Erro_404() {
  return (
    <div className="Corpo_erro_404">
      <img className="Imagem_sad" src={Sad_img} alt="Sad" />
      <div className="Descri_erro">
        <h1>404</h1>
        <h2>Oops...</h2>
        <h2>Page Not Found</h2>
        <p>
          It's looking like you may have taken a wrong turn. Don't worry...it
          happens to the most of us
        </p>
      </div>
      <Link to="/gfood">
        <img
          width="30%"
          src="https://cdn-icons-png.flaticon.com/512/25/25694.png"
          alt="Home"
        />
      </Link>
    </div>
  );
}

export default Erro_404;
