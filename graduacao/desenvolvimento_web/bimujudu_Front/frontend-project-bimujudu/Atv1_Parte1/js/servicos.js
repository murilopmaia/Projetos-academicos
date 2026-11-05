let itemIdCounter = 4;

function editarItem(id) {
    const card = document.querySelector(`.card[data-id='${id}']`);
    const title = prompt("Edite o título do Serviço:", card.querySelector("h3").innerText);
    const description = prompt("Edite a descrição do Serviço:", card.querySelector("p").innerText);
    if (title) card.querySelector("h3").innerText = title;
    if (description) card.querySelector("p").innerText = description;
}

function excluirItem(id) {
    const card = document.querySelector(`.card[data-id='${id}']`);
    if (confirm(`Tem certeza que deseja excluir o Serviço ${id}?`)) {
        card.remove();
    }
}

function visualizarItem(id) {
    const card = document.querySelector(`.card[data-id='${id}']`);
    alert(`Detalhes do Serviço:\n\nTítulo: ${card.querySelector("h3").innerText}\nDescrição: ${card.querySelector("p").innerText}`);
}

function adicionarItem() {
    const title = prompt("Digite o título do novo Serviço:");
    const description = prompt("Digite a descrição do novo Serviço:");
    if (title && description) {
        const container = document.getElementById("card-container");
        const newCard = document.createElement("div");
        newCard.classList.add("card");
        newCard.setAttribute("data-id", itemIdCounter);
        newCard.innerHTML = `
            <h3>${title}</h3>
            <p>${description}</p>
            <div class="actions">
                <button onclick="editarItem(${itemIdCounter})">Editar</button>
                <button onclick="excluirItem(${itemIdCounter})">Excluir</button>
                <button onclick="visualizarItem(${itemIdCounter})">Detalhes</button>
            </div>
        `;
        container.appendChild(newCard);
        itemIdCounter++;
    } else {
        alert("Título e descrição são obrigatórios para adicionar um novo Serviço.");
    }
}