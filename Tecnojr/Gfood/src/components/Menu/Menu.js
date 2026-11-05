import { useRef, forwardRef, useState } from "react";

//Components
import Produto from "../Produto/Produto";

//css
import "./Menu.css";

//Lista de Alimentos
import { ListaAlimentos } from "../../data/ListaAlimentos";

//Imagem
import Seta_pequena_img from "../../assets/Seta_pequena.png";

function Menu({ Qtd_itens }, ScrollMenu) {
  const [Nome_menu, setNome_menu] = useState("Most Popular Items");//Titulo do Menu
  const [Nome_Bot, setNome_bot] = useState("See More Product");//Nome do botão
  const [Bot_click, setBot_click] = useState(true);//Serve Para Alterar o estado do botão

  function handleProdutos() {//Função para alterar o valor e o nome do botão e do Titulo do Menu
    if (Bot_click === true) {
      setBot_click(false);
    } else {
      setBot_click(true);
    }

    if (Bot_click === true) {
      setNome_bot("See Less Product");
      setNome_menu("Menu");
    } else {
      setNome_bot("See More Product");
      setNome_menu("Most Popular Items");
    }
  }

  return (
    <div className="Menu_corpo">
      <div className="Menu_titulo">
        <p ref={ScrollMenu}>Product</p>
        <h3>{Nome_menu}</h3>
      </div>
      <div className="Produtos_corpo">
        {/*Mostra os Produtos Populares, caso o botão seja apertado mostra o resto dos Produtos */}
        {ListaAlimentos.Populares.map((item) => {
          return (
            <Produto
              Qtd_itens={Qtd_itens}
              Estrelas={item.Estrelas}
              Nome={item.Nome}
              Imagem={item.imagem}
              Preço={item.Preço}
            />
          );
        })}

        {Bot_click === false
          ? ListaAlimentos.Vitrine1.map((item) => {
              return (
                <Produto
                  Qtd_itens={Qtd_itens}
                  Estrelas={item.Estrelas}
                  Nome={item.Nome}
                  Imagem={item.imagem}
                  Preço={item.Preço}
                />
              );
            })
          : null}

        {Bot_click === false
          ? ListaAlimentos.Vitrine2.map((item) => {
              return (
                <Produto
                  Qtd_itens={Qtd_itens}
                  Estrelas={item.Estrelas}
                  Nome={item.Nome}
                  Imagem={item.imagem}
                  Preço={item.Preço}

      
                />
              );
            })
          : null}

        {Bot_click === false
          ? ListaAlimentos.Vitrine3.map((item) => {
              return (
                <Produto
                  Qtd_itens={Qtd_itens}
                  Estrelas={item.Estrelas}
                  Nome={item.Nome}
                  Imagem={item.imagem}
                  Preço={item.Preço}
                />
              );
            })
          : null}

        {Bot_click === false
          ? ListaAlimentos.Vitrine4.map((item) => {
              return (
                <Produto
                  Qtd_itens={Qtd_itens}
                  Estrelas={item.Estrelas}
                  Nome={item.Nome}
                  Imagem={item.imagem}
                  Preço={item.Preço}
                />
              );
            })
          : null}

        {Bot_click === false
          ? ListaAlimentos.Outros.map((item) => {
              return (
                <Produto
                  Qtd_itens={Qtd_itens}
                  Estrelas={item.Estrelas}
                  Nome={item.Nome}
                  Imagem={item.imagem}
                  Preço={item.Preço}
                />
              );
            })
          : null}
      </div>
      <div onClick={handleProdutos} className="Botao_more">
        <p>{Nome_Bot}</p>
        <img src={Seta_pequena_img} alt="Seta" />
      </div>
    </div>
  );
}

export default forwardRef(Menu);
