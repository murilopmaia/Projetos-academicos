import {useState} from 'react'
//css
import "./Vitrine.css"

function Vitrine({Apresente}){ //Apresente é o objeto da lista Alimentos a ser apresentado
    const direita = "\u2192"
    const esquerda ="\u2190"
    const [Ind,setInd] = useState(0);
    

    function handleEsquerda(){
        if(Ind-1 === -1){
            setInd(Apresente.length-1);
        }
        else{
            setInd((prevInd)=>prevInd-1);
        }
    }

    function handleDireita(){
        if(Ind+1 === Apresente.length){
            setInd(0);
        }
        else{
            setInd((prevInd)=>prevInd+1);
        }
    }
    
    return(
       
            <div className='Comida'>
                <div className='Cor_de_fundo'></div>
                <img src={Apresente[Ind].imagem} alt={Apresente[Ind].Nome}/>
                <div className='Descri'>
                    <h4>{Apresente[Ind].Nome}</h4>
                    <p>{Apresente[Ind].Descri}</p>
                    <div className='Price'>
                    <p className='Red'>$:</p>
                    <p>{Apresente[Ind].Preço}</p>
                    </div>
                    
                </div>
                <div className='Botoes'>
                    <button onClick={handleDireita} className='es'>{direita}</button>
                    <button onClick={handleEsquerda} className='di'>{esquerda}</button>
                </div>
            </div>
       
    )
}

export default Vitrine;