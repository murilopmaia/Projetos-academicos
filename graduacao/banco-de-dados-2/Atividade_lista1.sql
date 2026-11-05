-- Questão 1
create table PAI_pais(
	pai_cd_pais int identity,
	pai_nm_pais varchar(50) not null,
	pai_dc_nacionalidade varchar(18) not null,
	primary key(pai_cd_pais)
)

create table ATO_ator(
	ato_cd_codigo int identity,
	ato_nm_ator varchar(50) not null,
	ato_sx_ator char(1) default 'M',
	ato_dt_nascimento smalldatetime not null,
	ato_rg_ator int unique not null,
	ato_dt_pais_nacionalidade int not null,

	primary key(ato_cd_codigo),
	foreign key(ato_dt_pais_nacionalidade) references PAI_pais(pai_cd_pais) on update cascade on delete no action,
	check (ato_sx_ator in ('F', 'M'))
)

create table TIP_tipo(
	tip_cd_tipo int identity,
	tip_dc_tipo varchar(50) not null,
	primary key(tip_cd_tipo)
)
create table GEN_genero(
	gen_cd_genero int identity,
	gen_dc_genero varchar(50) not null,
	primary key(gen_cd_genero)
)

create table FIL_filme(
	fil_cd_filme int identity,
	fil_tl_original varchar(85) not null,
	fil_tl_portugues varchar(85),
	fil_cd_genero int not null,
	fil_cd_duracao varchar(20) not null,
	fil_dc_importancia varchar(99),
	fil_dc_impropriedade varchar(20) not null,
	fil_cd_pais_origem int not null,
	fil_cd_diretor int not null,

	primary key(fil_cd_filme),
	foreign key(fil_cd_genero) references GEN_genero(gen_cd_genero) on update cascade on delete no action,
	foreign key(fil_cd_pais_origem) references PAI_pais(pai_cd_pais) on update no action on delete no action, --Perguntas do on cascade, no lugar de no action em update
	foreign key(fil_cd_diretor) references ATO_ator(ato_cd_codigo) on update cascade on delete no action -- Perguntar de como no action no delete funciona
)

create table EST_estado(
	est_cd_estado int identity,
	est_nm_estado varchar(50) not null,
	est_cd_pais int not null,

	primary key(est_cd_estado),
	foreign key(est_cd_pais) references PAI_pais on update cascade on delete no action
)

create table CID_cidade(
	cid_cd_cidade int identity,
	cid_nm_cidade varchar(50) not null,
	cid_cd_estado int not null

	primary key(cid_cd_cidade),
	foreign key(cid_cd_estado) references EST_estado on update cascade on delete no action
)

create table CIN_cinema(
	cin_cd_cinema int identity,
	cin_nm_fantasia varchar(50) not null,
	cin_dc_logradouro varchar(30) not null,
	cin_dc_complemento varchar(20),
	cin_nu_numero int,
	cin_dc_bairro varchar(20) not null,
	cin_cd_cidade int not null,
	cin_cp_lotacao int,

	primary key(cin_cd_cinema),
	foreign key(cin_cd_cidade) references CID_cidade on update cascade on delete no action
)

create table FCI_filme_cinema(
	fci_cd_filme int,
	fci_cd_cinema int,
	fci_dt_inicio smalldatetime not null,
	fci_dt_fim  smalldatetime not null,
)

-- Questão 2
drop table FCI_filme_cinema

-- Questão 3
alter table FIL_filme add fil_cd_tipo int
alter table FIL_filme add constraint fk_fill_cd_tipo foreign key(fil_cd_tipo) references TIP_tipo on update cascade on delete no action

-- Questão 4
alter table FIL_filme ALTER COLUMN fil_tl_original varchar(100)

-- Questão 5
alter table FIL_filme drop column fil_dc_impropriedade

-- Questão 6
create table FCI_filme_cinema(
	fci_cd_filme int not null,
	fci_cd_cinema int not null,
	fci_dt_inicio smalldatetime not null,
	fci_dt_fim  smalldatetime not null,
)

-- Questão 7
alter table FCI_filme_cinema add constraint  pk_fci primary key(fci_cd_filme, fci_cd_cinema )

-- Questão 8
alter table FCI_filme_cinema add constraint fk_fci_cd_filme foreign key(fci_cd_filme) references FIL_filme on update cascade on delete no action

-- Questão 9
alter table FCI_filme_cinema add constraint fk_fci_cd_cinema foreign key(fci_cd_cinema) references CIN_cinema on update no action on delete no action 

-- Qestão 10

-- Povoando PAI_pais
insert into PAI_pais (pai_nm_pais, pai_dc_nacionalidade)
values 
('Brasil', 'Brasileira'),
('Estados Unidos', 'Americana'),
('França', 'Francesa'),
('Japão', 'Japonesa'),
('Alemanha', 'Alemã');

-- Povoando ATO_ator
SELECT @@LANGUAGE; -- Verificar a linguagem, muda o formato da data
insert into ATO_ator (ato_nm_ator, ato_sx_ator, ato_dt_nascimento, ato_rg_ator, ato_dt_pais_nacionalidade)
values
('Pedro Alves', 'M', '20-02-1985', 12345, 1),
('Laura Martins', 'F', '15-07-1990', 23456, 1),
('John Smith', 'M', '30-11-1980', 34567, 2),
('Yuki Tanaka', 'F', '18-05-1975', 45678, 4),
('Hans Muller', 'M', '01-01-1965', 56789, 5);

-- Povoando TIP_tipo
insert into TIP_tipo (tip_dc_tipo)
values
('Ação'),
('Comédia'),
('Drama'),
('Ficção Científica'),
('Terror');

-- Povoando GEN_genero
insert into GEN_genero (gen_dc_genero)
values
('Aventura'),
('Comédia'),
('Romance'),
('Terror'),
('Ficção Científica');

-- Povoando FIL_filme
insert into FIL_filme (fil_tl_original, fil_tl_portugues, fil_cd_genero, fil_cd_duracao, fil_dc_importancia, fil_cd_pais_origem, fil_cd_diretor)
values
('End Game', 'Guerra infinita', 1, '200', 'Alto', 2, 18),
('Inception', 'A Origem', 5, '148', 'Alto', 2, 18),
('Cidade de Deus', NULL, 1, '130', 'Alto', 1, 19),
('Parasite', 'Parasita', 3, '132', 'Média', 4, 20),
('Titanic', NULL, 2, '195', 'Alto', 2, 22),
('O Auto da Compadecida', NULL, 2, '104', 'Alta', 1, 24);


-- Povoando EST_estado
insert into EST_estado (est_nm_estado, est_cd_pais)
values
('São Paulo', 1),
('Califórnia', 2),
('Île-de-France', 3),
('Tóquio', 4),
('Baviera', 5);

-- Povoando CID_cidade
insert into CID_cidade (cid_nm_cidade, cid_cd_estado)
values
('São Paulo', 1),
('Los Angeles', 2),
('Paris', 3),
('Tóquio', 4),
('Munique', 5);

-- Povoando CIN_cinema
insert into CIN_cinema (cin_nm_fantasia, cin_dc_logradouro, cin_dc_complemento, cin_nu_numero, cin_dc_bairro, cin_cd_cidade, cin_cp_lotacao)
values
('Cine São Paulo', 'Rua Augusta', NULL, 123, 'Centro', 1, 200),
('Cineplex LA', 'Sunset Boulevard', 'Sala 5', 456, 'Hollywood', 2, 300),
('Le Grand Rex', 'Boulevard Poissonnière', 'Piso 2', 789, '9º Arrondissement', 3, 250),
('Cine Tokyo', 'Shibuya Crossing', NULL, 101, 'Shibuya', 4, 400),
('Cine München', 'Marienplatz', NULL, 202, 'Altstadt', 5, 150);

-- Questão 11
insert into ATO_ator (ato_nm_ator, ato_sx_ator, ato_dt_nascimento, ato_rg_ator, ato_dt_pais_nacionalidade)
values
('Carlos Silva', 'M', '12-08-1992', 67890, 1),
('Hiroshi Nakamura', 'M', '10-04-1987', 78901, 4),
('Maria Souza', 'F', '22-03-1995', 89012, 1),
('Anna Fischer', 'F', '18-06-1988', 90123, 5),
('Emily Johnson', 'F', '07-09-1991', 12367, 2);

-- Questão 12
update PAI_pais
set pai_nm_pais = 'Japão', pai_dc_nacionalidade = 'Japonês'
where pai_cd_pais = 1


-- Questão 13
DELETE from ATO_ator
where ato_cd_codigo  in
(select ato_cd_codigo from ATO_ator where ato_sx_ator = 'M')

-- Questão 14
select pai_cd_pais as codigo, pai_nm_pais as nome_país
from PAI_pais
where pai_cd_pais = 1

-- Questão 15
select ato_nm_ator as nome, ato_sx_ator as sexo, ato_dt_nascimento as data_nascimento
from ATO_ator
where ato_sx_ator = 'F'

-- Questão 16
select fil_tl_original as titulo
from FIL_filme
where fil_tl_portugues is null

---------------------- Lista 2 ---------------------------------

-- Questão 1
create table ATO_ator_novo (
	ato_cd_codigo int identity,
	ato_nm_ator varchar(50) not null,
	ato_sx_ator char(1) default 'M',
	ato_dt_nascimento smalldatetime not null,
	ato_rg_ator int unique not null,
	ato_dt_pais_nacionalidade int not null,

	primary key(ato_cd_codigo),
	foreign key(ato_dt_pais_nacionalidade) references PAI_pais(pai_cd_pais) on update cascade on delete no action,
	check (ato_sx_ator in ('F', 'M'))
)

insert into ATO_ator_novo (ato_nm_ator, ato_sx_ator, ato_dt_nascimento, ato_rg_ator, ato_dt_pais_nacionalidade)
select ato_nm_ator, ato_sx_ator, ato_dt_nascimento, ato_rg_ator, ato_dt_pais_nacionalidade
from ATO_ator
where ato_sx_ator = 'M'

-- Questão 2
insert into ATO_ator_novo (ato_nm_ator, ato_sx_ator, ato_dt_nascimento, ato_rg_ator, ato_dt_pais_nacionalidade) values 
('Maria Silva', 'F', '15/05/1985', 123456789, 1),
('Ana Souza', 'F', '23/11/1990', 987654321, 2),
('Fernanda Costa', 'F', '10/03/1982', 456789123, 3),
('Patrícia Lima', 'F', '08/07/1987', 789123456, 1),
('Carla Santos', 'F', '22/09/1995', 321654987, 2);

-- Questão 3
delete from ATO_ator
where ato_nm_ator in 
(select ato_nm_ator from ATO_ator_novo)

-- Questão 4
-- Where
select ato_nm_ator as nome, pai_dc_nacionalidade as nome_nacionalidade
from ATO_ator, PAI_pais
where ato_dt_pais_nacionalidade = pai_cd_pais
order by nome asc

-- Inner join
select ato_nm_ator as nome, pai_dc_nacionalidade as nome_nacionalidade
from ATO_ator inner join PAI_pais
on ato_dt_pais_nacionalidade = pai_cd_pais
order by nome asc

-- Questão 5
select distinct ato_dt_pais_nacionalidade
from ATO_ator

-- Questão 6
select distinct ato_dt_pais_nacionalidade as CODIGO, pai_dc_nacionalidade  as NACIONALIDADE 
from ATO_ator inner join PAI_pais
on ato_dt_pais_nacionalidade = pai_cd_pais
order by NACIONALIDADE asc

-- Questão 7
select AVG(cin_cp_lotacao) as media
from CIN_cinema
where cin_cd_cidade = 1

-- Questão 8
select sum(cin_cp_lotacao) as total
from CIN_cinema
where cin_cd_cidade = 1

-- Questão 9
select cin_nm_fantasia as nome
from CIN_cinema
where  cin_cp_lotacao = (select max(cin_cp_lotacao) from CIN_cinema where cin_cd_cidade = 1)

-- Questão 10
select count(*) as quantidade_cinema
from cin_cinema
where cin_cd_cidade = 1

-- Questão 11
select cin_nm_fantasia as nome
from CIN_cinema
where  cin_cp_lotacao = (select min(cin_cp_lotacao) from CIN_cinema where cin_cd_cidade = 1)

-- Questão 12
select cin_nm_fantasia as nome_fantasia, (cin_dc_logradouro+', '+COALESCE(cin_dc_complemento+', ', '')+cast(cin_nu_numero as varchar(5))+', '+cin_dc_bairro) as endereco, cid_nm_cidade as nome_cidade
from CIN_cinema , CID_cidade 
where cin_cp_lotacao > 200 and cid_cd_cidade = cin_cd_cidade

-- Questão 13
select cin_nm_fantasia as nome, cin_cp_lotacao as lotacao
from cin_cinema
where (cin_cp_lotacao between 200 and 400)

-- Questão 14
select cin_nm_fantasia as nome, cin_cp_lotacao as lotacao, cin_cp_lotacao*2 as lotacao_drobrada
from CIN_cinema
where cin_cd_cidade = 1

-- Questão 15
select fil_cd_filme as codigo, fil_tl_original as titulo_original, fil_tl_portugues as titulo_portugues, fil_cd_duracao as duracao, gen_dc_genero as genero
from FIL_filme inner join GEN_genero
on fil_cd_genero = gen_cd_genero and  fil_cd_genero = 1 and fil_tl_portugues is not null and fil_tl_original like 'a%'
order by fil_tl_original desc

--	Questão 16
select fil_tl_portugues as titulo_portugues
from FIL_filme
where fil_tl_portugues like '[C-H]%'

-- Questão 17
select fil_tl_portugues as titulo_portugues
from FIL_filme
where fil_tl_portugues like '[^C-H]%'

-- Questão 18
select fil_tl_portugues as titulo_portugues
from FIL_filme
where fil_tl_portugues like '__R%'

-- Questão 19
select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator atr, PAI_pais pat where pat.pai_cd_pais = atr.ato_dt_pais_nacionalidade
	union
	(select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator_novo an, PAI_pais pan where pan.pai_cd_pais = an.ato_dt_pais_nacionalidade)

select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator atr, PAI_pais pat where pat.pai_cd_pais = atr.ato_dt_pais_nacionalidade
	union all
	(select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator_novo an, PAI_pais pan where pan.pai_cd_pais = an.ato_dt_pais_nacionalidade)

-- Questão 20
select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator atr, PAI_pais pat where pat.pai_cd_pais = atr.ato_dt_pais_nacionalidade
	except
	(select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator_novo an, PAI_pais pan where pan.pai_cd_pais = an.ato_dt_pais_nacionalidade)

-- Questão 21
select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator atr, PAI_pais pat where pat.pai_cd_pais = atr.ato_dt_pais_nacionalidade
	intersect
	(select pai_dc_nacionalidade as nome, pai_cd_pais codigo from ATO_ator_novo an, PAI_pais pan where pan.pai_cd_pais = an.ato_dt_pais_nacionalidade)

-- Questão 22
select Count(*) as total_atores, pai_dc_nacionalidade as nacionalidade, ato_sx_ator as sexo
from ATO_ator, PAI_pais
where pai_cd_pais = ato_dt_pais_nacionalidade
group by pai_dc_nacionalidade, ato_sx_ator
order by pai_dc_nacionalidade asc

-- Questão 23
select ato_nm_ator as nome, ato_sx_ator as sexo from ATO_ator 
	where ato_cd_codigo in
		(select ato_cd_codigo from ATO_ator_novo )

select ato_nm_ator as nome, ato_sx_ator as sexo from ATO_ator ato
	where exists 
		(select * from ATO_ator_novo aton where ato.ato_cd_codigo = aton.ato_cd_codigo)

-- Questão 24
select ato_nm_ator as nome, ato_sx_ator as sexo from ATO_ator 
	where ato_cd_codigo not in
		(select ato_cd_codigo from ATO_ator_novo )

select ato_nm_ator as nome, ato_sx_ator as sexo from ATO_ator ato
	where not exists 
		(select * from ATO_ator_novo aton where ato.ato_cd_codigo = aton.ato_cd_codigo)

--	Questão 25
select cin_nm_fantasia as nome_fantasia, cin_cp_lotacao as lotacao
from CIN_cinema
where cin_cp_lotacao < (select AVG(cin_cp_lotacao) from CIN_cinema)