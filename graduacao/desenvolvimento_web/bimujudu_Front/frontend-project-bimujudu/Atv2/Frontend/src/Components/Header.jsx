import "../Styles/Header.css"; // Importando o CSS do cabeçalho
import logo from '../assets/logo.png';
import { Link } from "react-router-dom";

function Header() {
  return (
    <div className="header_nav">
      <header>
        <img src={logo} alt="Logo" width="150" height="auto" />
      </header>

      <nav>
        <ul>
          <li><Link className="atual" to={"#"}>Início</Link></li>
          <li><Link  to={"./sobre.html"}>Sobre</Link></li>
          <li><Link  to={"./servicos.html"}>Serviços</Link></li>
          <li><Link  to={"./contato.html"}>Contato</Link></li>
          <li><Link  to={"./registrar.html"}>Registrar</Link></li>
        </ul>
      </nav>
    </div>
  );
}

export default Header;
