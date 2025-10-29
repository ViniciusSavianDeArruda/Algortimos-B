# 📚 Algoritmos e Programação B

Este repositório contém estudos e exercícios práticos da disciplina **Algoritmos e Programação B** do curso de Sistemas de Informação, focando em conceitos avançados de programação estruturada em linguagem C.

## 🎯 Objetivos da Disciplina

- Dominar estruturas de dados heterogêneas (structs, unions, enums)
- Implementar e utilizar funções personalizadas e recursivas
- Compreender e manipular ponteiros e alocação dinâmica de memória
- Trabalhar com manipulação de arquivos
- Desenvolver soluções modulares e organizadas
- Aplicar boas práticas de programação e gerenciamento de memória

## 📖 Conteúdo Estudado

### 1. Estruturas de Dados Heterogêneas

#### 🏗️ Structs (Estruturas)
- Definição e declaração de estruturas
- Estruturas aninhadas (struct dentro de struct)
- Arrays de estruturas
- Aplicações práticas: cadastro de pessoas, produtos, alunos

```c
struct pessoa {
    char nome[40];
    struct endereco e;
};
```

#### 🔄 Unions (Uniões)
- Compartilhamento de memória entre diferentes tipos
- Economia de espaço de armazenamento
- Conversão entre graus e radianos

#### 📋 Enums (Enumerações)
- Definição de constantes nomeadas
- Melhoria na legibilidade do código
- Representação de estados e categorias

#### 🏷️ Typedef
- Criação de aliases para tipos de dados
- Simplificação de declarações complexas
- Melhoria na manutenibilidade do código

### 2. Modularização e Funções

#### 🔧 Conceitos Fundamentais
- Declaração e definição de funções
- Parâmetros e valores de retorno (com/sem retorno, com/sem parâmetros)
- Passagem por valor vs passagem por referência
- Escopo de variáveis (locais vs globais)
- Protótipos de funções
- Modularização de código

#### 💼 Aplicações Práticas
- Cálculos de INSS e IRPF
- Conversão de moedas
- Validação de dados
- Processamento de arrays e matrizes

### 3. Recursividade

#### 🔄 Conceitos de Recursão
- Caso base e caso recursivo
- Chamadas recursivas e pilha de execução
- Problemas clássicos: fatorial, Fibonacci, potenciação
- Recursão vs iteração

#### 📊 Aplicações
- Soma de elementos de arrays
- Inversão de strings
- Busca e ordenação recursiva

### 4. Ponteiros

#### 📍 Fundamentos
- Conceito de endereço de memória
- Operadores `&` (endereço) e `*` (desreferência)
- Declaração e inicialização de ponteiros
- Aritmética de ponteiros
- Ponteiros nulos e boas práticas

#### 🔗 Ponteiros Avançados
- Ponteiros e arrays
- Ponteiros e strings
- Ponteiros para ponteiros
- Ponteiros para estruturas (`->`)

### 5. Ponteiros e Funções

#### 🔀 Manipulação Avançada
- Passagem de parâmetros por referência
- Funções que modificam múltiplos valores
- Funções que retornam ponteiros
- Arrays de ponteiros
- Funções com strings e vetores

### 6. Alocação Dinâmica de Memória

#### 💾 Gerenciamento de Memória
- Diferença entre stack e heap
- Funções `malloc()`, `calloc()`, `realloc()`, `free()`
- Vetores e strings dinâmicas
- Matrizes dinâmicas (unidimensional e bidimensional)

#### ⚠️ Boas Práticas
- Verificação de alocação bem-sucedida
- Prevenção de memory leaks
- Evitar dangling pointers e double free
- Liberação adequada de memória

### 7. Manipulação de Arquivos

#### 📁 Operações Básicas
- Abertura e fechamento de arquivos (`fopen`, `fclose`)
- Leitura de dados (`fscanf`, `fgets`)
- Escrita de dados (`fprintf`, `fputs`)
- Tratamento de erros

#### 💾 Persistência de Dados
- Armazenamento permanente de informações
- Leitura de dados previamente salvos
- Integração com estruturas de dados

## 🗂️ Estrutura do Projeto

```
📦 Algoritmos-B/
├── 📄 README.md                                      # Documentação do projeto
├── 📄 ResumoConteudo.md                              # Guia completo de estudos
├── 📄 Exercicios.c                                   # Lista de exercícios diversos
│
├── 📁 Aulas-algortimosB/                             # Aulas práticas
│   ├── 📄 aula-02-08.c                               # Structs básicas
│   ├── 📄 Aula-12-08.c                               # Structs aninhadas
│   ├── 📄 Aula-19-08.c                               # Arrays de structs
│   ├── 📄 aula-16-09.c                               # Funções
│   ├── 📄 aula-23-09.c                               # Recursividade
│   ├── 📄 Aula dia 30-09-25.c                        # Ponteiros
│   ├── 📄 aula 07-10-25.c                            # Alocação dinâmica
│   └── 📄 ExerciciosAula.C                           # Exercícios práticos
│
├── 📁 Lista2-Funcoes/                                # Lista de exercícios sobre funções
│   ├── 📄 exe1.c - exe7.c                            # Exercícios de 1 a 7
│
├── 📁 Lista6- Ponteiros e funções/                   # Lista de exercícios sobre ponteiros
│   ├── 📄 ex1.c - ex12.c                             # Exercícios de 1 a 12
│
├── 📁 ListaLB2-Structs/                              # Lista de exercícios sobre structs
│   ├── 📄 exe1.c, exe2.c                             # Exercícios com estruturas
│
├── 📁 ListaLB3-Funcoes/                              # Lista avançada de funções
│   └── 📄 exe1.c                                     # Exercício avançado
│
└── 📁 Produtos de Aprendizagem/                      # Projetos integradores
    └── 📄 Produto de Aprendizagem Algortimos B.c     # Projeto final
```

## 🚀 Principais Projetos Desenvolvidos

### 1. Sistema de Controle de Papelaria
- **Tecnologias**: Structs, Arrays, Funções
- **Funcionalidades**:
  - Cadastro de produtos
  - Cálculo automático de preço de venda
  - Consultas por código
  - Relatórios de estoque
  - Identificação de produtos mais/menos caros

### 2. Sistema de Gestão de Turmas Acadêmicas
- **Tecnologias**: Structs aninhadas, Arrays
- **Funcionalidades**:
  - Cadastro de turmas e alunos
  - Controle de frequência
  - Cálculo de percentuais de presença
  - Relatórios estatísticos

### 3. Calculadora de Impostos
- **Tecnologias**: Funções, Estruturas condicionais
- **Funcionalidades**:
  - Cálculo de INSS por faixas salariais
  - Cálculo de IRPF progressivo
  - Conversão de salário para dólar
  - Interface interativa

## 🛠️ Tecnologias e Ferramentas

- **Linguagem**: C
- **Compilador**: GCC
- **Conceitos**: 
  - Programação estruturada
  - Modularização
  - Manipulação de memória
  - Entrada/Saída de dados
  - Persistência em arquivos

## 📈 Habilidades Desenvolvidas

- ✅ Criação de tipos de dados personalizados (structs, unions, enums)
- ✅ Implementação de funções modulares e recursivas
- ✅ Manipulação de ponteiros e referências de memória
- ✅ Gerenciamento de memória dinâmica (malloc, free)
- ✅ Manipulação eficiente de arquivos
- ✅ Validação e tratamento de dados
- ✅ Desenvolvimento de interfaces de usuário em console
- ✅ Aplicação de boas práticas de programação
- ✅ Resolução de problemas complexos e algorítmicos
- ✅ Debugging e otimização de código

## 🎓 Aplicações Práticas

Os conhecimentos adquiridos são aplicáveis em:

- **Sistemas de Gestão**: Controle de estoque, cadastros
- **Aplicações Financeiras**: Cálculos de impostos, conversões
- **Sistemas Acadêmicos**: Controle de notas e frequência
- **Processamento de Dados**: Análise e relatórios
- **Desenvolvimento de Software**: Base para linguagens mais avançadas

## 📝 Próximos Passos

- [ ] Implementar estruturas de dados dinâmicas (listas encadeadas)
- [ ] Estudar algoritmos de busca e ordenação
- [ ] Desenvolver projetos mais complexos com múltiplos módulos
- [ ] Aplicar conceitos de estruturas de dados avançadas (pilhas, filas, árvores)
- [ ] Integrar conhecimentos em projetos práticos reais

## 📚 Recursos Complementares

- [Documentação Oficial C](https://en.cppreference.com/)
- [Tutorial C - GeeksforGeeks](https://www.geeksforgeeks.org/c-programming-language/)
- [Visualizador de Código C](https://pythontutor.com/c.html)
- **ResumoConteudo.md** - Guia detalhado com exemplos práticos de todos os tópicos

## 🤝 Como Utilizar Este Repositório

1. **Iniciantes**: Comece pelo `ResumoConteudo.md` para entender a teoria
2. **Prática**: Analise os códigos em `Aulas-algortimosB/` para ver exemplos
3. **Exercícios**: Resolva as listas organizadas por tópico
4. **Projetos**: Estude os projetos em `Produtos de Aprendizagem/`

---

> **Disciplina**: Algoritmos e Programação B
> **Curso**: Sistemas de Informação
> **Período**: 2025
> **Foco**: Estruturas de Dados, Funções, Recursividade, Ponteiros e Alocação Dinâmica em C

*Este repositório documenta o aprendizado em programação estruturada avançada e serve como referência completa dos conhecimentos adquiridos na disciplina.*