//css
import "./Produto.css";
//Imagem
import Estrela_img from "../../assets/Estrela.png";

function Produto({ Qtd_itens, Estrelas, Nome, Imagem, Preço }) {
  return (
    <div className="Corpo_produto">
      <div className="Imagem_produto">
        <img src={Imagem} alt={Nome} />
      </div>

      <div className="Corpo_baixo">
        <div className="Alinhar_produto_direita">
          <h4>{Nome}</h4>
          <button onClick={Qtd_itens}>Add To Cart</button>
        </div>
        <div className="Alinhar_produto_esquerda">
          <div className="Estrela">
            <img src={Estrela_img} alt="Estrela" />
            <p>{Estrelas}</p>
          </div>
          <p>${Preço}</p>
        </div>
      </div>
    </div>
  );
}

export default Produto;
