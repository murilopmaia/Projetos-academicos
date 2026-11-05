import FormData from "../Components/FormData";
import { useNavigate } from "react-router-dom";
import Footer from "../Components/Footer";
import Header from "../Components/Header";
import "../Styles/RouteData.css"

function RouteData() {
  const navigate = useNavigate();
  return (
    <div className="wrapper">
      <Header />
      <div className="content">
        <FormData />
        <button onClick={() => navigate("/")} className="button_cancelar">
          Cancelar
        </button>
      </div>
      
      <Footer />
    </div>
  );
}

export default RouteData;