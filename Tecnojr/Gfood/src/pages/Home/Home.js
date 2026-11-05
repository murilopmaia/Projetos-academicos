import { useRef, useState } from "react";

//Components
import Topo from "../../components/Topo/Topo";
import Infos from "../../components/Infos/Infos";
import Menu from "../../components/Menu/Menu";
import Services from "../../components/Services/Services";
import How_to_work from "../../components/How_to_work/How_to_work";
import Clientes from "../../components/Clients/Clients";
import NewsLetter from "../../components/NewsLetter/NewsLetter";
import ComFooter from "../../components/ComFooter/ComFooter";
import NavBar from "../../components/NavBar/NavBar";

//CSS
import "./Home.css";

function Home() {
  const ScrollHome = useRef(null);
  const ScrollMenu = useRef(null);
  const ScrollService = useRef(null); //Para mover o scroll usando ref
  const [Qtd, setQtd] = useState(0); //Quantidade de itens no carrinho

  function Qtd_itens() {
    setQtd((prevQtd) => prevQtd + 1);
  }

  function Handle_ScrollHome() {
    ScrollHome.current?.scrollIntoView({ behavior: "smooth" });
  }

  function Handle_ScrollMenu() {
    ScrollMenu.current?.scrollIntoView({ behavior: "smooth" });
  }

  function Handle_ScrollService() {
    ScrollService.current?.scrollIntoView({ behavior: "smooth" });
  }

  return (
    <div className="Corpo_home">
      <div ref={ScrollHome}></div>
      <div className="Max">
        <NavBar
          Handle_ScrollHome={Handle_ScrollHome}
          Handle_ScrollMenu={Handle_ScrollMenu}
          Handle_ScrollService={Handle_ScrollService}
          Qtd={Qtd}
          Qtd_itens={Qtd_itens}
        />
        <Topo />
        <Infos />
        <Menu ref={ScrollMenu} Qtd_itens={Qtd_itens} />
        <Services ref={ScrollService} />
        <How_to_work />
        <Clientes />
        <NewsLetter />
      </div>

      <ComFooter />
    </div>
  );
}

export default Home;
