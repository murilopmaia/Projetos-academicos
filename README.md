# Projetos acadêmicos 

Uma seleção dos projetos desenvolvidos ao longo dos meus quatro anos de graduação em Ciência da Computação na UESC, de parte do mestrado e da minha atuação na TecnoJr. O conjunto reflete uma formação ampla: dos fundamentos de computação e métodos numéricos a análise de dados, inteligência artificial, computação paralela e desenvolvimento web, com facilidade para aprender e me adaptar a novas linguagens e ferramentas.

## Estrutura

| Pasta | Conteúdo |
|---|---|
| [`mestrado/`](mestrado) | Computação científica: métodos numéricos e fundamentos matemáticos |
| [`Tecnojr/`](Tecnojr) | Projetos da empresa júnior (processo seletivo de trainee e diretoria de marketing) |
| [`graduacao/`](graduacao) | Projetos e atividades das disciplinas da graduação |

## Tecnologias e conhecimentos

### Linguagens
| Linguagem | Onde aparece |
|---|---|
| **Python** | métodos numéricos, IA, análise de dados, redes (sockets), MPI |
| **C** | LP1/LP2, estruturas de dados, software básico, computação gráfica, compiladores, MPI/OpenMP/CUDA |
| **C++** | MPI (sistemas distribuídos) |
| **CUDA C** | multiplicação de matrizes em GPU |
| **Java** | RMI / jogos distribuídos (sistemas distribuídos) |
| **C#** | API REST com .NET e Entity Framework (desenvolvimento web) |
| **JavaScript** | React, Node/Express, front-end puro |
| **HTML / CSS** | Wiki_Lol, Gfood, web |
| **SQL** | modelagem e consultas (BD1 e BD2) |
| **Flex / Bison** | analisador léxico e sintático (compiladores) |

### Ciência de dados e computação científica
- **Análise e limpeza de dados:** `pandas`, `numpy`, `matplotlib`, `seaborn`, análise exploratória em Jupyter
- **Cálculo numérico:** sistemas lineares (eliminação de Gauss, LU, Jacobi, Gauss-Seidel, inversão), zeros de funções (bissecção, posição falsa, Newton, secante, ponto fixo), interpolação (Lagrange, Newton, splines), mínimos quadrados, regressão, derivação e integração numérica (trapézio, Simpson, Gauss, Richardson), EDOs (Euler, Heun, Runge-Kutta, shooting, diferenças finitas)
- **Modelagem de EDPs:** equação do calor e da corda (2D/3D), séries de Fourier e de Taylor, com `scipy` e `sympy`
- **Inteligência artificial clássica:** busca em largura e profundidade, busca de custo uniforme, A\*, IDA\*, busca bidirecional, hill climbing, otimização por busca local e satisfação de restrições (Sudoku)
- **Computação de alto desempenho:** multiplicação de matrizes sequencial por blocos, paralela (OpenMP), distribuída (MPI) e em GPU (CUDA), com medições de tempo por tamanho de matriz

### Engenharia de software e web
- **Front-end:** React, React Router, HTML/CSS/JS, consumo de API REST (`fetch`)
- **Back-end:** Node.js, Express, Sequelize, SQLite, .NET (C#), JWT, bcrypt
- **Bancos de dados:** modelagem relacional, SQL, MySQL e SQLite
- **Práticas:** Git e GitHub, versionamento em equipe, testes (Jest e Testing Library), deploy no GitHub Pages

### Fundamentos de computação
Estruturas de dados (listas encadeadas, recursividade, ordenação), algoritmos de busca e complexidade, compiladores, redes (sockets TCP), sistemas distribuídos, computação gráfica (OpenGL, chroma key, manipulação de imagens PNM), ponto flutuante (IEEE 754).

## Mestrado

| Projeto | O que é |
|---|---|
| [`metodos-numericos/`](mestrado/metodos-numericos) | Listas e notebooks da disciplina: interpolação polinomial, splines, mínimos quadrados, zeros de funções, integrais e sistemas lineares, com módulos Python reutilizáveis |
| [`fundamentos-matematicos-mc/`](mestrado/fundamentos-matematicos-mc) | Simulações de EDPs: calor 2D/3D, corda vibrante 2D/3D, séries de Fourier e de Taylor |

## TecnoJr

| Projeto | Contexto |
|---|---|
| [`Wiki_Lol/`](Tecnojr/Wiki_Lol) | **Projeto do processo seletivo de trainee.** Foi feito para entrar na empresa júnior. É um site em HTML, CSS e JavaScript sobre campeões e skins de League of Legends, que consome a API de dados do jogo |
| [`Gfood/`](Tecnojr/Gfood) | **Feito para continuar na empresa júnior**, na minha entrada na diretoria de marketing. Aplicação web em React com login, cadastro e rotas |

## Graduação — destaques

| Disciplina | Destaque |
|---|---|
| [`analise-numerica/`](graduacao/analise-numerica) | Três relatórios com implementação própria em Python dos métodos numéricos, incluindo sistemas lineares, zeros, interpolação, MMQ, derivação, integração e EDOs. Há entradas e saídas versionadas e scripts de gráficos para comparar os métodos |
| [`inteligencia-artificial/`](graduacao/inteligencia-artificial) | Algoritmos de busca (informada, não informada e bidirecional), busca local (hill climbing sobre um polinômio interpolador de Lagrange), CSP com Sudoku e agente robô-aspirador |
| [`organizacao-recuperacao-informacao/`](graduacao/organizacao-recuperacao-informacao) | Análise exploratória com `pandas` de uma base pública de alunos com deficiência (gráficos por campus, ano e tipo) e experimento comparando o tempo de busca linear e binária |
| [`tecnicas-avancadas-computacao-1/`](graduacao/tecnicas-avancadas-computacao-1) | Pré-processamento de um dataset de saúde (CSV) com `pandas`: seleção de colunas e exportação do conjunto tratado |
| [`processamento-paralelo/`](graduacao/processamento-paralelo) | Multiplicação de matrizes em 6 versões (sequencial por blocos, OpenMP, MPI e três variantes CUDA), com resultados para N = 512 a 4096 |
| [`banco-de-dados-1/`](graduacao/banco-de-dados-1) e [`banco-de-dados-2/`](graduacao/banco-de-dados-2) | Modelagem relacional e SQL: criação de tabelas com chaves e restrições e consultas (BD2), além de uma aplicação com Node/Express, EJS e MySQL/SQLite com CRUD de clientes, reservas e combos (BD1) |
| [`estruturas-de-dados/`](graduacao/estruturas-de-dados) | Manipulação de arquivos CSV em C (base de videogames) |

As demais disciplinas ([`desenvolvimento_web`](graduacao/desenvolvimento_web), [`engenharia-de-software`](graduacao/engenharia-de-software), [`compiladores`](graduacao/compiladores), [`redes-1`](graduacao/redes-1), [`computacao-grafica`](graduacao/computacao-grafica) e as de linguagem de programação) estão aqui como registro e não têm destaque.
