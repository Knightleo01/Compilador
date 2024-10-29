# Compilador
Fase 2 Implementar um interpretador

Implementação de um Interpretador para Comandos DBASE em Linguagem C 

1. Introdução 

  

A linguagem DBASE foi amplamente utilizada para acesso e manipulação de dados em bases de dados no formato DBASE, caracterizando-se por uma estrutura simples de comandos para interagir com tabelas. Este projeto visa implementar um interpretador em C para comandos básicos da linguagem DBASE, como USE, LIST, APPEND, REPLACE e DELETE. 

  

2. Estrutura do Código 

  

A implementação do interpretador utiliza estruturas de dados básicas em C e manipulação de strings para processar os comandos. Cada comando é identificado e tratado por funções específicas.  
 
 2.2 Explicação do Código 

 -Estrutura de Dados: Foi criada uma estrutura chamada Registro para armazenar os dados de cada registro na tabela. Essa estrutura contém um identificador (`id`), um campo de nome (nome) e um campo ativo, que indica se o registro está ativo ou deletado. 

- Funções para Comandos: 

  - comando USE: Simula a abertura de uma tabela. 

  - comando LIST: Exibe todos os registros ativos. 

  - comando APPEND: Adiciona um novo registro. 

  - comando REPLACE: Atualiza o nome de um registro específico. 

  - comando DELETE: Marca um registro como excluído. 

- Interpretação e Execução: A função interpretarComando analisa o comando de entrada e chama a função correspondente. 


3. Exemplos de Uso 

 Aqui estão alguns exemplos de comandos que podem ser usados para testar o interpretador: 

1. USE: Abre uma tabela. 

2. APPEND John: Adiciona um registro com o nome "John". 

3. LIST: Exibe todos os registros. 

4. REPLACE 1 Mary: Atualiza o nome do registro com ID 1 para "Mary". 

5. DELETE 1: Marca o registro com ID 1 como excluído.


4. Referências 

Compiladores Princípios, Técnicas E Ferramentas: Free Download, Borrow, and Streaming : Internet Archive. Disponível em: <https://archive.org/details/compiladores-principios-tecnicas-e-ferramentas>. Acesso em: 27 out. 2024. 

The C programming language. Free Download, Borrow, and Streaming: Internet Archive. Disponível em: <https://archive.org/details/programmingdbase0000rube>. Acesso em: 27 out. 2024. 

Advanced guide to DBASE IV programming. Free Download, Borrow, and Streaming: Internet Archive. Disponível em: <https://archive.org/details/advanceddbaseiv0000robe>. Acesso em: 27 out. 2024. 

 
