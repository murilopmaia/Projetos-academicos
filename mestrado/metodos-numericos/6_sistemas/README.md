# Control de Verçoes

* Sempre que vc vai a fazel algum cambio o troca nos arquivos, tem que fazer `git pull` para que não tenha conflictos.

## Sobre os commits

Sempre que faza un commit tem que usar diante do mensagem as siguintes dicas

* `add:` quando vc cria um novo arquivo o agrega um novo metodo
* `feat:` Cuando vc melhora alguma coisa, na estrucutra de arquivos o testes, o alguma coisa ja feita
* `fix:` Arruma um erro
* `del:` Tira alguma coisa
* `doc:` Implementa uma explicaçao de algums dos metodos feitos.

## Não Incluir

Arquivos temporales o que sejan propios do Sistema Operativo seu. Por exemplo.
.venv, venvs, *.pdf, conversas de ChatGpt. Todo isso tem que ser adicionado no arquivo `.gitignore`

## Gerenciamento do ambiente com UV

Este projeto utiliza o **uv** para gerenciar o ambiente virtual e as dependências Python. O `uv` é uma ferramenta rápida e moderna que substitui o uso combinado de `venv` e `pip`.

### Instalação do UV

Caso ainda não tenha o `uv` instalado, execute:

```bash
# Linux / macOS
curl -LsSf https://astral.sh/uv/install.sh | sh

# Windows (PowerShell)
powershell -ExecutionPolicy ByPass -c "irm https://astral.sh/uv/install.ps1 | iex"
```

Ou instale utilizando o `pip`:

```bash
pip install uv
```

### Criando o ambiente virtual

Na raiz do projeto, execute:

```bash
uv venv
```

Isso criará um ambiente virtual na pasta `.venv`.

### Ativando o ambiente

**Linux / macOS**

```bash
source .venv/bin/activate
```

**Windows (PowerShell)**

```powershell
.venv\Scripts\Activate.ps1
```

### Instalando as dependências

Se o projeto utiliza um arquivo `pyproject.toml`, basta executar:

```bash
uv sync
```


### Adicionando novas dependências

Para adicionar uma biblioteca ao projeto:

```bash
uv add nome_da_biblioteca
```

Exemplo:

```bash
uv add numpy
```


### Atualizando as dependências

```bash
uv sync
```

Este comando instala e sincroniza todas as dependências definidas no projeto, garantindo que o ambiente esteja consistente com o arquivo `pyproject.toml` e o `uv.lock`.