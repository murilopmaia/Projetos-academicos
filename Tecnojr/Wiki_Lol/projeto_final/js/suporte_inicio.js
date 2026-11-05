const escreva = document.querySelector("#escreva");
const botao = document.querySelector("#botao");
const form = document.querySelector("#escolha");
const nick = localStorage.getItem("nick")
const nick_antigo = document.querySelector("#nick h3")
const corpo = document.querySelector("#corpo")



nick_antigo.innerText = nick  

const champ_permitidos = [
  "Alistar",
  "Amumu",
  "Ashe",
  "Bard",
  "Blitzcrank",
  "Brand",
  "Braum",
  "Galio",
  "Janna",
  "Karma",
  "Leona",
  "Lulu",
  "Lux",
  "Maokai",
  "Morgana",
  "Nami",
  "Nautilus",
  "Pyke",
  "Rakan",
  "Rell",
  "Renata",
  "Senna",
  "Seraphine",
  "Shaco",
  "Sona",
  "Soraka",
  "Swain",
  "TahmKench",
  "Taric",
  "Thresh",
  "Velkoz",
  "Xerath",
  "Yuumi",
  "Zilean",
  "Zyra",
];



botao.addEventListener("click", ler);
form.addEventListener("submit", ler);



function ler(event) {
  event.preventDefault();
  if(escreva.value.toLowerCase() == "bardo"){
    escreva.value = "bard"
  }
  let nome_real = champ_permitidos.find(nome => nome.toLowerCase().includes(  escreva.value.toLowerCase()))
  if(nome_real){ //TOLOWERCASE() faz ser tudo minusculo

       window.location.href = `suporte.html?champ=${nome_real.toLowerCase()}`
   }
   else{
       alert("Campeão não encontrado")
       escreva.value = ""
       
   }
   
}



champ_permitidos.forEach(nome => {
    let nome_corrigido = nome
    if(nome == "TahmKench"  ){
        nome_corrigido = "Tahm_Kench"
    }else
    if(nome == "Renata"){
        nome_corrigido = "Renata_Glasc"
    }else
    if(nome == "Velkoz"){
        nome_corrigido = "Vel'Koz"
    }else
    if(nome == "Bard"){
        nome_corrigido = "Bardo"
    }

    //o + para ir add
    corpo.innerHTML += `<a href="./suporte.html?champ=${nome}"> 
    <div id="${nome}" class="champ">
        <img src="http://ddragon.leagueoflegends.com/cdn/12.13.1/img/champion/${nome}.png" alt="${nome}" height="90px">
        <p class="nome">${nome_corrigido}</p>
    </div>
    </a>`
    
})



