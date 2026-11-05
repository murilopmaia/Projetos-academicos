import { useNavigate } from "react-router-dom";
import "../Styles/ErrorPage.css";

function ErrorPage() {
  const navigate = useNavigate();
  return (
    <div className="error-page">
      <div className="error-container">
        <h1 className="error-title">404</h1>
        <p className="error-message">Oops! A página que você está procurando não existe.</p>
        <button className="error-button" onClick={() => navigate("/")}>
          Voltar para a Página Inicial
        </button>
      </div>
    </div>
  );
}

export default ErrorPage;
