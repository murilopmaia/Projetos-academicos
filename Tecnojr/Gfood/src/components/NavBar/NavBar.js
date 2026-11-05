import { Link } from "react-router-dom";
import { ListaAlimentos } from "../../data/ListaAlimentos";
import { useState } from "react";

//Component
import Pesquisa_item from "../Pesquisa_item/Pesquisa_item";
//css
import "./NavBar.css";
//Imagem
import Logo_img from "../../assets/Logo.png";
import Carrinho_img from "../../assets/Carrinho.png";

function NavBar({
  Handle_ScrollHome,
  Handle_ScrollMenu,
  Handle_ScrollService,
  Qtd,
  Qtd_itens,
}) {
  // esta recebendo funções para mover o scroll e a quantidade de itens no carrinho, junto com sua função de add no carrinho
  const [Escrita, setEscrita] = useState(""); //Valor do input
  const [Foco, setFoco] = useState(0); //Verifica se o foco esta no input

  return (
    <header className="Corpo_navbar">
      <img className="Logo" width="60px" src={Logo_img} alt="Logo" />
      <div className="Centro_navbar">
        <div className="NavBar_links">
          <button onClick={Handle_ScrollHome}>Home</button>
          <button onClick={Handle_ScrollMenu}>Menu</button>
          <button onClick={Handle_ScrollService}>Service</button>
          <Link to="/Shope">Shope</Link>
        </div>
        <div className="Corpo_div_search">
          <div className="Div_search">
            <div className="Corpo_search">
              <input
                type="text"
                placeholder="Search"
                value={Escrita}
                onChange={(e) => setEscrita(e.target.value)}
                onFocus={() => setFoco(1)}
                onBlur={() =>
                  setTimeout(() => {
                    setFoco(0);
                  }, 300)
                }
              />
            </div>

            <div className="Linha_cinza"></div>
            <div className="Carrinho">
              <div className="Quantidade_carrinho">
                <p>{Qtd}</p>
              </div>
              <img src={Carrinho_img} alt="Carrinho" />
            </div>
          </div>
          <div className="Pesquisa">
            {ListaAlimentos.Populares.map((item) => {
              if (
                item.Nome.toLowerCase().includes(Escrita.toLowerCase()) &&
                Escrita !== "" &&
                Foco === 1
              ) {
                return <Pesquisa_item Mostre={item} Qtd_itens={Qtd_itens} />;
              }
            })}

            {ListaAlimentos.Vitrine1.map((item) => {
              if (
                item.Nome.toLowerCase().includes(Escrita.toLowerCase()) &&
                Escrita !== "" &&
                Foco === 1
              ) {
                return <Pesquisa_item Mostre={item} Qtd_itens={Qtd_itens} />;
              }
            })}

            {ListaAlimentos.Vitrine2.map((item) => {
              if (
                item.Nome.toLowerCase().includes(Escrita.toLowerCase()) &&
                Escrita !== "" &&
                Foco === 1
              ) {
                return <Pesquisa_item Mostre={item} Qtd_itens={Qtd_itens} />;
              }
            })}

            {ListaAlimentos.Vitrine3.map((item) => {
              if (
                item.Nome.toLowerCase().includes(Escrita.toLowerCase()) &&
                Escrita !== "" &&
                Foco === 1
              ) {
                return <Pesquisa_item Mostre={item} Qtd_itens={Qtd_itens} />;
              }
            })}

            {ListaAlimentos.Vitrine4.map((item) => {
              if (
                item.Nome.toLowerCase().includes(Escrita.toLowerCase()) &&
                Escrita !== "" &&
                Foco === 1
              ) {
                return <Pesquisa_item Mostre={item} Qtd_itens={Qtd_itens} />;
              }
            })}

            {ListaAlimentos.Outros.map((item) => {
              if (
                item.Nome.toLowerCase().includes(Escrita.toLowerCase()) &&
                Escrita !== "" &&
                Foco === 1
              ) {
                return <Pesquisa_item Mostre={item} Qtd_itens={Qtd_itens} />;
              }
            })}
          </div>
        </div>
      </div>
    </header>
  );
}

export default NavBar;
