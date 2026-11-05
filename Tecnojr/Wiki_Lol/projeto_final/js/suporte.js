const parametro_busca = new URLSearchParams(window.location.search);
const nome_champ = tocapitalcase(parametro_busca.get("champ")); // usa a função criada la embaixo
if(!nome_champ){
  alert("Campeão não encontrado")
}
console.log(nome_champ)
const icone = document.querySelector("#icone");
const titulo_nome = document.querySelector("#titulo_nome");
const sub_nome = document.querySelector("#sub_nome");
const historia_texto = document.querySelector("#historia_texto");
const habilidade_Q_disc = document.querySelector("#habilidade_Q_disc");
const habilidade_Q_icone = document.querySelector("#habilidade_Q_icone");
const mana_Q = document.querySelector("#mana_Q");
const cooldown_Q = document.querySelector("#cooldown_Q");
const habilidade_W_icone = document.querySelector("#habilidade_W_icone");
const habilidade_W_disc = document.querySelector("#habilidade_W_disc");
const mana_W = document.querySelector("#mana_W");
const cooldown_W = document.querySelector("#cooldown_W");
const habilidade_E_icone = document.querySelector("#habilidade_E_icone");
const habilidade_E_disc = document.querySelector("#habilidade_E_disc");
const mana_E = document.querySelector("#mana_E");
const cooldown_E = document.querySelector("#cooldown_E");
const habilidade_R_icone = document.querySelector("#habilidade_R_icone");
const habilidade_R_disc = document.querySelector("#habilidade_R_disc");
const mana_R = document.querySelector("#mana_R");
const cooldown_R = document.querySelector("#cooldown_R");
const passiva_icone = document.querySelector("#passiva_icone");
const passiva_disc = document.querySelector("#passiva_disc");
const nome_passiva = document.querySelector("#nome_passiva");
const nome_Q = document.querySelector("#nome_Q");
const nome_W = document.querySelector("#nome_W");
const nome_E = document.querySelector("#nome_E");
const nome_R = document.querySelector("#nome_R");
const classe = document.querySelector("#classe");
const vida = document.querySelector("#vida");
const vda_nivel = document.querySelector("#vida_nivel");
const regen_vida = document.querySelector("#regen_vida");
const regen_vida_nivel = document.querySelector("#regen_vida_nivel");
const mana = document.querySelector("#mana");
const mana_nivel = document.querySelector("#mana_nivel");
const regen_mana = document.querySelector("#regen_mana");
const regen_mana_nivel = document.querySelector("#regen_mana_nivel");
const velocidade_movimento = document.querySelector("#velocidade_movimento");
const alcance = document.querySelector("#alcance");
const dano_atk = document.querySelector("#dano_atk");
const dano_atk_nivel = document.querySelector("#dano_atk_nivel");
const velocidade_atk = document.querySelector("#velocidade_atk");
const velocidade_atk_nivel = document.querySelector("#velocidade_atk_nivel");
const armadura = document.querySelector("#armadura");
const armadura_nivel = document.querySelector("#armadura_nivel");
const res_magica = document.querySelector("#res_magica");
const res_magica_nivel = document.querySelector("#res_magica_nivel");
const lista_dicas_aliados = document.querySelector("#lista_dicas_aliados");
const lista_dicas_inimigos = document.querySelector("#lista_dicas_inimigo");
const dicas_aliados_tudo = document.querySelector("#dicas_aliados_tudo");
const dicas_inimigos_tudo = document.querySelector("#dicas_inimigos_tudo");
const nick = localStorage.getItem("nick");
const nick_antigo = document.querySelector("#nick h3");





nick_antigo.innerText = nick;

fetch(
  `https://ddragon.leagueoflegends.com/cdn/12.13.1/data/pt_BR/champion/${nome_champ}.json`
)
  .then((res) => res.json())
  .then((conteudo) => {
    let nome = Object.values(conteudo.data)[0]; //vai naquele objeto e pega o primeiro valor dele

    titulo_nome.innerHTML = nome.name;

    console.log(nome)
    nome_passiva.innerHTML = "Passiva - " + nome.passive.name;
    nome_Q.innerHTML = "Q - " + nome.spells[0].name;
    nome_W.innerHTML = "W - " + nome.spells[1].name;
    nome_E.innerHTML = "E - " + nome.spells[2].name;
    nome_R.innerHTML = "R - " + nome.spells[3].name;

    if (nome.tags[1]) {
      classe.innerHTML = nome.tags[0] + " / " + nome.tags[1];
    } else {
      classe.innerHTML = nome.tags[0];
    }

    let i, x;
    for (i = 0; ; i++) {
      if (nome.allytips[i]) {
        let item = document.createElement("li");
        item.innerHTML = nome.allytips[i];
        lista_dicas_aliados.appendChild(item);
        continue;
      } else {
        break;
      }
    }
    
    if (i == 0) {
      dicas_aliados_tudo.classList.remove("dicas_aliados_tudo");
      dicas_aliados_tudo.classList.add("sumir");
    }

    for (x = 0; ; x++) {
      if (nome.enemytips[x]) {
        let item = document.createElement("li");
        item.innerHTML = nome.enemytips[x];
        lista_dicas_inimigos.appendChild(item);
        continue;
      } else {
        break;
      }
    }

    if (x == 0) {
      dicas_inimigos_tudo.classList.remove("dicas_inimigos_tudo");
      dicas_inimigos_tudo.classList.add("sumir");
    }

    vida.innerHTML = nome.stats.hp;
    vda_nivel.innerHTML = nome.stats.hpperlevel;
    regen_vida.innerHTML = nome.stats.hpregen;
    regen_vida_nivel.innerHTML = nome.stats.hpregenperlevel;
    mana.innerHTML = nome.stats.mp;
    mana_nivel.innerHTML = nome.stats.mpperlevel;
    regen_mana.innerHTML = nome.stats.mpregen;
    regen_mana_nivel.innerHTML = nome.stats.mpregenperlevel;
    velocidade_movimento.innerHTML = nome.stats.movespeed;
    alcance.innerHTML = nome.stats.attackrange;
    dano_atk.innerHTML = nome.stats.attackdamage;
    dano_atk_nivel.innerHTML = nome.stats.attackdamageperlevel;
    velocidade_atk.innerHTML = nome.stats.attackspeed;
    velocidade_atk_nivel.innerHTML = nome.stats.attackspeedperlevel;
    armadura.innerHTML = nome.stats.armor;
    armadura_nivel.innerHTML = nome.stats.armorperlevel;
    res_magica.innerHTML = nome.stats.spellblock;
    res_magica_nivel.innerHTML = nome.stats.spellblockperlevel;

    mana_Q.innerHTML = nome.spells[0].costBurn;
    mana_W.innerHTML = nome.spells[1].costBurn;
    if (nome_champ == "Yuumi") {
      mana_E.innerHTML = "40/45/50/55/60 (+ 12% Mana_Max)";
    } else {
      mana_E.innerHTML = nome.spells[2].costBurn;
    }
    
    mana_R.innerHTML = nome.spells[3].costBurn;
    
    if(nome_champ == "Zyra"){
      cooldown_W.innerHTML = "18 / 16 / 14 / 12 / 10"
    } else{
      cooldown_W.innerHTML = nome.spells[1].cooldownBurn;
    }
    

    if (nome_champ == "Rakan") {
      cooldown_E.innerHTML = nome.spells[2].effectBurn[4];
      cooldown_Q.innerHTML = nome.spells[0].effectBurn[5];
    } else {
      cooldown_E.innerHTML = nome.spells[2].cooldownBurn;
      cooldown_Q.innerHTML = nome.spells[0].cooldownBurn;
    }

    if(nome_champ == "TahmKench"){
      cooldown_R.innerHTML = "120/100/80"
    }else{
      cooldown_R.innerHTML = nome.spells[3].cooldownBurn;
    }
    
    sub_nome.innerHTML = nome.title;
    historia_texto.innerHTML = nome.lore;
    habilidade_Q_disc.innerHTML = nome.spells[0].description;
    habilidade_W_disc.innerHTML = nome.spells[1].description;
    habilidade_E_disc.innerHTML = nome.spells[2].description;
    habilidade_R_disc.innerHTML = nome.spells[3].description;
    passiva_disc.innerHTML = nome.passive.description;
    habilidade_R_icone.src = `http://ddragon.leagueoflegends.com/cdn/12.13.1/img/spell/${nome.spells[3].image.full}`;
    habilidade_W_icone.src = `http://ddragon.leagueoflegends.com/cdn/12.13.1/img/spell/${nome.spells[1].image.full}`;
    habilidade_E_icone.src = `http://ddragon.leagueoflegends.com/cdn/12.13.1/img/spell/${nome.spells[2].image.full}`;
    habilidade_Q_icone.src = `http://ddragon.leagueoflegends.com/cdn/12.13.1/img/spell/${nome.spells[0].image.full}`;
    icone.src = `http://ddragon.leagueoflegends.com/cdn/12.13.1/img/champion/${nome.image.full}`;
    passiva_icone.src = `http://ddragon.leagueoflegends.com/cdn/12.13.1/img/passive/${nome.passive.image.full}`;
  });

function tocapitalcase(texto) {
  if(texto){
  return texto.charAt(0).toUpperCase() + texto.slice(1); //criando uma função , precisa do return pra poder usar a função depois
  }
}

