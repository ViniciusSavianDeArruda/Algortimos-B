# 📚 Algoritmos e Programação B

Este repositório contém meus estudos e exercícios práticos da disciplina **Algoritmos e Programação B**, focando em conceitos avançados de programação em linguagem C.

## 🎯 Objetivos da Disciplina

- Dominar estruturas de dados heterogêneas (structs, unions, enums)
- Implementar e utilizar funções personalizadas
- Trabalhar com manipulação de arquivos
- Desenvolver soluções modulares e organizadas
- Aplicar boas práticas de programação

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

### 2. Funções em C

#### 🔧 Conceitos Fundamentais
- Declaração e definição de funções
- Parâmetros e valores de retorno
- Escopo de variáveis (locais vs globais)
- Modularização de código

#### 💼 Aplicações Práticas
- Cálculos de INSS e IRPF
- Conversão de moedas
- Validação de dados
- Processamento de arrays

### 3. Manipulação de Arquivos

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
├── 📄 Aula.algoritmos B.c          # Conceitos teóricos e exemplos
├── 📁 AulaAlgoritmo-B- Funcoes e Arquivos/
│   ├── 📄 Aula.c                   # Funções e manipulação de arquivos
│   └── 📄 ExerciciosAula.C         # Exercícios práticos da aula
├── 📄 Exercicios.c                 # Lista de exercícios diversos
├── 📄 ExerciciosAula.C             # Exercícios com funções
└── 📁 ListaLB2/
    └── 📄 ExercicioLista.c         # Exercícios avançados com structs
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

- ✅ Criação de tipos de dados personalizados
- ✅ Implementação de funções modulares
- ✅ Manipulação eficiente de arquivos
- ✅ Validação e tratamento de dados
- ✅ Desenvolvimento de interfaces de usuário em console
- ✅ Aplicação de boas práticas de programação
- ✅ Resolução de problemas complexos

## 🎓 Aplicações Práticas

Os conhecimentos adquiridos são aplicáveis em:

- **Sistemas de Gestão**: Controle de estoque, cadastros
- **Aplicações Financeiras**: Cálculos de impostos, conversões
- **Sistemas Acadêmicos**: Controle de notas e frequência
- **Processamento de Dados**: Análise e relatórios
- **Desenvolvimento de Software**: Base para linguagens mais avançadas

## 📝 Próximos Passos

- [ ] Implementar estruturas de dados dinâmicas
- [ ] Estudar ponteiros avançados
- [ ] Desenvolver projetos mais complexos
- [ ] Integrar com bases de dados
- [ ] Aplicar conceitos em projetos reais

---

> **Disciplina**: Algoritmos e Programação B  
> **Período**: 2025  
> **Foco**: Estruturas de dados, Funções e Arquivos em C

*Este repositório documenta minha jornada de aprendizado em programação estruturada e serve como portfólio dos conhecimentos adquiridos.*