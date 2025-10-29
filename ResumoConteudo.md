# 🧠 Algoritmos e Programação B

> Guia completo de estudos na faculdade de Sistemas de informacoes sobre estruturas de dados, ponteiros, recursividade e programação modular em C

## 📑 Índice

- [Introdução](#-introdução)
- [1. Conjuntos Heterogêneos](#1-conjuntos-heterogêneos)
  - [1.1 Estruturas (struct)](#11-estruturas-struct)
  - [1.2 Uniões (union)](#12-uniões-union)
  - [1.3 Enumerações (enum)](#13-enumerações-enum)
  - [1.4 Typedef](#14-typedef)
- [2. Modularização e Funções](#2-modularização-e-funções)
- [3. Recursividade](#3-recursividade)
- [4. Ponteiros](#4-ponteiros)
- [5. Ponteiros e Funções](#5-ponteiros-e-funções)
- [6. Alocação Dinâmica de Memória](#6-alocação-dinâmica-de-memória)
- [Resumo Geral](#-resumo-geral)

---

## 📘 Introdução

A disciplina **Algoritmos e Programação B** visa desenvolver o raciocínio lógico e a capacidade de resolver problemas computacionais complexos utilizando a linguagem C. Este guia completo cobre desde estruturas de dados heterogêneas até gerenciamento avançado de memória.

### 🎯 Principais Objetivos

- **Estruturação de Dados**: Criar e manipular tipos de dados personalizados (structs, unions, enums)
- **Modularização**: Desenvolver programas organizados em funções reutilizáveis
- **Pensamento Recursivo**: Resolver problemas divisíveis em subproblemas menores
- **Gerenciamento de Memória**: Dominar ponteiros e alocação dinâmica
- **Boas Práticas**: Escrever código limpo, eficiente e livre de erros de memória

### 📖 Como Usar Este Guia

- Cada seção contém **teoria detalhada** seguida de **exemplos práticos**
- Os exemplos de código são **comentados** para facilitar o entendimento
- **Dicas e avisos** destacam pontos importantes e erros comuns
- Use o **índice** para navegação rápida entre tópicos

---

## 1. Conjuntos Heterogêneos

Conjuntos heterogêneos permitem agrupar dados de diferentes tipos em uma única estrutura lógica, facilitando a organização e manipulação de informações relacionadas.

**Por que usar?**
- Representar entidades do mundo real (pessoa, produto, aluno)
- Organizar dados relacionados de forma coesa
- Facilitar a passagem de múltiplos dados para funções
- Criar estruturas de dados complexas e hierárquicas

### 1.1 Estruturas (struct)

Uma **estrutura** é uma coleção de variáveis (campos) de tipos diferentes agrupadas sob um mesmo nome. É fundamental para representar entidades do mundo real com múltiplos atributos.

#### Sintaxe Básica

```c
struct Aluno {
    char nome[50];
    int matricula;
    int anoIngresso;
    float nota;
};
```

#### Declaração e Inicialização

```c
// Forma 1: Declaração e inicialização separadas
struct Aluno a1;
strcpy(a1.nome, "Vinicius");
a1.matricula = 12345;
a1.anoIngresso = 2023;
a1.nota = 8.5;

// Forma 2: Inicialização direta
struct Aluno a2 = {"Maria", 54321, 2023, 9.0};
```

#### Acessando Campos

```c
printf("Nome: %s\n", a1.nome);
printf("Matrícula: %d\n", a1.matricula);
printf("Ano de Ingresso: %d\n", a1.anoIngresso);
printf("Nota: %.2f\n", a1.nota);
```

#### Vetor de Estruturas

Permite armazenar múltiplos registros do mesmo tipo:

```c
struct Aluno turma[100];

// Preenchendo dados
for (int i = 0; i < 100; i++) {
    printf("Digite o nome do aluno %d: ", i+1);
    fgets(turma[i].nome, 50, stdin);
    printf("Digite a matrícula: ");
    scanf("%d", &turma[i].matricula);
}
```

#### Estruturas Aninhadas

Uma estrutura pode conter outra estrutura como campo:

```c
struct Endereco {
    char rua[50];
    int numero;
    char bairro[30];
    char cidade[30];
    char estado[3];
    char cep[10];
};

struct Pessoa {
    char nome[50];
    int idade;
    struct Endereco endereco;
};

// Uso
struct Pessoa p;
strcpy(p.nome, "João");
p.idade = 25;
strcpy(p.endereco.rua, "Av. Paulista");
p.endereco.numero = 1000;
```

#### Ponteiros para Estruturas

```c
struct Aluno *ptr;
struct Aluno a = {"Carlos", 98765, 2022, 7.8};
ptr = &a;

// Acessando através do ponteiro
printf("%s\n", (*ptr).nome);  // Forma 1
printf("%d\n", ptr->matricula); // Forma 2 (preferida)
```

### 1.2 Uniões (union)

Uma **união** compartilha o mesmo espaço de memória entre seus membros. Apenas um campo pode ser usado por vez.

**Diferença entre struct e union:**
- **struct**: Cada campo tem seu próprio espaço de memória
- **union**: Todos os campos compartilham o mesmo espaço de memória

**Quando usar unions?**
- Economizar memória quando apenas um campo será usado por vez
- Interpretar os mesmos bytes de formas diferentes
- Criar variáveis que podem armazenar diferentes tipos (mas não simultaneamente)

#### Sintaxe e Uso

```c
union Dado {
    int i;
    float f;
    char c;
};

union Dado x;
x.i = 10;
printf("Inteiro: %d\n", x.i);

x.f = 3.14;
printf("Float: %.2f\n", x.f);
// Atenção: x.i agora contém lixo de memória!
```

#### Tamanho da União

O tamanho de uma união é igual ao tamanho do seu maior membro:

```c
printf("Tamanho da union: %ld bytes\n", sizeof(union Dado));
// Será o tamanho do maior tipo (geralmente float = 4 bytes)
```

#### Caso de Uso Prático

```c
struct Item {
    int tipo; // 0=inteiro, 1=float, 2=char
    union {
        int i;
        float f;
        char c;
    } valor;
};

struct Item item1;
item1.tipo = 1;
item1.valor.f = 3.14;

if (item1.tipo == 1) {
    printf("Valor float: %.2f\n", item1.valor.f);
}
```

### 1.3 Enumerações (enum)

**Enumerações** criam um conjunto de constantes inteiras nomeadas, tornando o código mais legível e menos propenso a erros.

**Por que usar enum?**
- Substituir "números mágicos" por nomes significativos
- Representar conjuntos finitos de valores (dias da semana, status, cores)
- Melhorar a legibilidade e manutenção do código
- Prevenir valores inválidos

**Como funciona:**
- Por padrão, a primeira constante recebe valor 0
- As seguintes recebem valores incrementais (1, 2, 3...)
- Você pode atribuir valores personalizados

#### Sintaxe Básica

```c
enum Semana {DOM, SEG, TER, QUA, QUI, SEX, SAB};
enum Semana hoje = QUA;

printf("Hoje é dia %d da semana\n", hoje); // Imprime 3
```

#### Valores Customizados

```c
enum Mes {
    JAN = 1, FEV, MAR, ABR, MAI, JUN,
    JUL, AGO, SET, OUT, NOV, DEZ
};

enum Mes mesAtual = MAR;
printf("Mês: %d\n", mesAtual); // Imprime 3
```

#### Uso Prático com Switch

```c
enum Status {ATIVO, INATIVO, PENDENTE, BLOQUEADO};

enum Status statusUsuario = ATIVO;

switch(statusUsuario) {
    case ATIVO:
        printf("Usuário ativo\n");
        break;
    case INATIVO:
        printf("Usuário inativo\n");
        break;
    case PENDENTE:
        printf("Cadastro pendente\n");
        break;
    case BLOQUEADO:
        printf("Usuário bloqueado\n");
        break;
}
```

### 1.4 Typedef

O **typedef** cria sinônimos (apelidos) para tipos existentes, simplificando declarações e melhorando a legibilidade do código.

**Vantagens do typedef:**
- Simplifica declarações de tipos complexos
- Torna o código mais legível e profissional
- Facilita mudanças futuras no tipo de dados
- Permite criar nomes mais descritivos

**Uso comum:**
- Criar aliases para structs (evitar escrever "struct" toda vez)
- Simplificar declarações de ponteiros
- Criar nomes mais significativos para tipos primitivos

#### Com Estruturas

```c
// Sem typedef
struct Aluno a1;

// Com typedef
typedef struct Aluno {
    char nome[50];
    int matricula;
    int anoIngresso;
} Aluno;

Aluno a1; // Mais simples e legível
```

#### Com Tipos Primitivos

```c
typedef unsigned long int ulint;
typedef char* string;

ulint grande = 1000000;
string nome = "João";
```

#### Com Ponteiros

```c
typedef int* intPtr;

intPtr p1, p2; // Ambos são ponteiros para int
```

#### Com Enumerações

```c
typedef enum {
    SEGUNDA = 1,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA
} DiaSemana;

DiaSemana hoje = QUARTA;
```

---

## 2. Modularização e Funções

**Modularização** é o processo de dividir um programa em partes menores e independentes (funções), tornando o código mais organizado, legível, reutilizável e fácil de manter.

### Conceito de Função

Uma função é um bloco de código que executa uma tarefa específica e pode ser chamado múltiplas vezes.

**Por que usar funções?**
- **Reutilização**: Escrever uma vez, usar várias vezes
- **Organização**: Dividir problemas complexos em partes menores
- **Manutenção**: Facilita correções e melhorias
- **Legibilidade**: Código mais claro e compreensível
- **Teste**: Testar partes isoladas do programa

**Princípio da Responsabilidade Única:**
Cada função deve fazer uma coisa e fazê-la bem. Se uma função faz muitas coisas, considere dividi-la em funções menores.

### Estrutura de uma Função

```c
tipo_retorno nome_funcao(tipo_param1 param1, tipo_param2 param2) {
    // corpo da função
    return valor; // opcional, depende do tipo de retorno
}
```

### Tipos de Funções

#### 1. Com Retorno e Com Parâmetros

```c
int soma(int a, int b) {
    return a + b;
}

int resultado = soma(5, 3); // resultado = 8
```

#### 2. Com Retorno e Sem Parâmetros

```c
float pi() {
    return 3.14159;
}

float valorPi = pi();
```

#### 3. Sem Retorno e Com Parâmetros

```c
void imprime(int x) {
    printf("Valor: %d\n", x);
}

imprime(42);
```

#### 4. Sem Retorno e Sem Parâmetros

```c
void menu() {
    printf("=== MENU PRINCIPAL ===\n");
    printf("1. Cadastrar\n");
    printf("2. Listar\n");
    printf("3. Sair\n");
}

menu();
```

### Passagem de Parâmetros

#### Por Valor

Uma cópia do valor é passada. O valor original não é alterado:

```c
void incrementa(int x) {
    x++;
    printf("Dentro da função: %d\n", x); // 11
}

int main() {
    int num = 10;
    incrementa(num);
    printf("Fora da função: %d\n", num); // 10 (não mudou)
    return 0;
}
```

#### Por Referência

O endereço da variável é passado. O valor original pode ser alterado:

```c
void incrementa(int *x) {
    (*x)++;
}

int main() {
    int num = 10;
    incrementa(&num);
    printf("Valor: %d\n", num); // 11 (mudou!)
    return 0;
}
```

### Variáveis

#### Variáveis Locais

Declaradas dentro da função, existem apenas durante sua execução:

```c
void funcao() {
    int x = 10; // variável local
    printf("%d\n", x);
} // x deixa de existir aqui
```

#### Variáveis Globais

Declaradas fora de todas as funções, acessíveis por todo o programa:

```c
int contador = 0; // variável global

void incrementaContador() {
    contador++;
}

int main() {
    incrementaContador();
    printf("%d\n", contador); // 1
    return 0;
}
```

**⚠️ Atenção:** Evite o uso excessivo de variáveis globais. Prefira passar parâmetros para funções.

### Protótipo de Função

Permite declarar a função antes da `main()`, definindo-a depois:

```c
// Protótipo
int soma(int, int);
void imprime(int);

int main() {
    int r = soma(3, 2);
    imprime(r);
    return 0;
}

// Implementação
int soma(int a, int b) {
    return a + b;
}

void imprime(int x) {
    printf("Resultado: %d\n", x);
}
```

### Funções com Arrays

```c
float media(float notas[], int tamanho) {
    float soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += notas[i];
    }
    return soma / tamanho;
}

int main() {
    float notas[] = {7.5, 8.0, 9.5, 6.0};
    float m = media(notas, 4);
    printf("Média: %.2f\n", m);
    return 0;
}
```

---

## 3. Recursividade

**Recursividade** ocorre quando uma função chama a si mesma. É uma técnica poderosa para resolver problemas que podem ser divididos em subproblemas menores e similares.

**Como funciona:**
1. A função resolve uma parte pequena do problema
2. Chama a si mesma com um problema menor
3. Continua até atingir um caso trivial (caso base)
4. Os resultados são combinados para formar a solução final

**Vantagens da Recursão:**
- Código mais limpo e elegante para problemas naturalmente recursivos
- Traduz diretamente definições matemáticas recursivas
- Ideal para estruturas de dados recursivas (árvores, listas)

**Desvantagens:**
- Pode ser menos eficiente que iteração (loops)
- Consome mais memória (pilha de chamadas)
- Risco de stack overflow se não houver caso base adequado

### Estrutura de uma Função Recursiva

Toda função recursiva **DEVE TER**:

1. **Caso base (condição de parada)**: Condição que para a recursão
2. **Caso recursivo**: Chamada da função com um problema reduzido
3. **Progresso em direção ao caso base**: Cada chamada deve aproximar do fim

### Exemplo 1: Fatorial

```c
int fatorial(int n) {
    // Caso base
    if (n == 0 || n == 1) {
        return 1;
    }
    // Caso recursivo
    return n * fatorial(n - 1);
}

// fatorial(5) = 5 * fatorial(4)
// fatorial(4) = 4 * fatorial(3)
// fatorial(3) = 3 * fatorial(2)
// fatorial(2) = 2 * fatorial(1)
// fatorial(1) = 1
// Resultado: 5 * 4 * 3 * 2 * 1 = 120
```

### Exemplo 2: Sequência de Fibonacci

```c
int fibonacci(int n) {
    // Casos base
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// fibonacci(5):
// 0, 1, 1, 2, 3, 5
```

### Exemplo 3: Soma de Elementos de um Array

```c
int somaArray(int arr[], int tamanho) {
    // Caso base
    if (tamanho == 0) {
        return 0;
    }
    // Caso recursivo
    return arr[tamanho - 1] + somaArray(arr, tamanho - 1);
}
```

### Exemplo 4: Potenciação

```c
int potencia(int base, int expoente) {
    // Caso base
    if (expoente == 0) {
        return 1;
    }
    // Caso recursivo
    return base * potencia(base, expoente - 1);
}

// potencia(2, 3) = 2 * potencia(2, 2)
//                = 2 * 2 * potencia(2, 1)
//                = 2 * 2 * 2 * potencia(2, 0)
//                = 2 * 2 * 2 * 1 = 8
```

### Exemplo 5: Inversão de String

```c
void inverteString(char *str, int inicio, int fim) {
    // Caso base
    if (inicio >= fim) {
        return;
    }

    // Troca caracteres
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    // Caso recursivo
    inverteString(str, inicio + 1, fim - 1);
}

// Uso
char palavra[] = "recursao";
inverteString(palavra, 0, strlen(palavra) - 1);
printf("%s\n", palavra); // "oasrucer"
```

### Recursividade vs Iteração

| Recursividade | Iteração |
|---------------|----------|
| Código mais limpo e elegante | Geralmente mais eficiente |
| Pode causar stack overflow | Usa menos memória |
| Melhor para problemas naturalmente recursivos | Melhor para loops simples |

### Quando Usar Recursividade

- Estruturas de dados recursivas (árvores, grafos)
- Problemas de busca e backtracking
- Algoritmos de divisão e conquista
- Problemas matemáticos (fatorial, fibonacci)

**⚠️ Importante:** Sempre garanta que há uma condição de parada, caso contrário o programa entrará em loop infinito e causará estouro de pilha.

---

## 4. Ponteiros

**Ponteiros** são variáveis que armazenam endereços de memória de outras variáveis. São fundamentais para manipulação eficiente de memória e estruturas de dados complexas.

**O que é um ponteiro?**
Um ponteiro é uma variável especial que, ao invés de armazenar um valor comum (como 10 ou "João"), armazena o **endereço de memória** onde outro valor está localizado.

**Por que ponteiros são importantes?**
- **Eficiência**: Passar endereços é mais rápido que copiar valores grandes
- **Modificação direta**: Alterar valores originais através de funções
- **Alocação dinâmica**: Criar estruturas de tamanho variável
- **Estruturas complexas**: Implementar listas, árvores, grafos
- **Arrays e strings**: Manipulação avançada e eficiente

**Analogia:**
Imagine que a memória é um prédio de apartamentos. Cada apartamento (variável) tem um número (endereço). Um ponteiro é como um papel com o número do apartamento escrito. Em vez de levar o conteúdo do apartamento, você só leva o endereço.

### Conceito Básico

```c
int a = 5;
int *p;     // Declara um ponteiro para int
p = &a;     // p recebe o endereço de a

printf("Valor de a: %d\n", a);        // 5
printf("Endereço de a: %p\n", &a);    // endereço
printf("Valor de p: %p\n", p);        // endereço de a
printf("Valor apontado por p: %d\n", *p); // 5
```

### Operadores

| Operador | Nome | Função |
|----------|------|--------|
| `&` | Endereço de | Retorna o endereço de uma variável |
| `*` | Desreferência | Acessa o valor no endereço apontado |

### Declaração e Inicialização

```c
int *p1;           // Ponteiro não inicializado (perigoso!)
int *p2 = NULL;    // Ponteiro inicializado com NULL (seguro)
int x = 10;
int *p3 = &x;      // Ponteiro inicializado com endereço de x
```

### Ponteiros e Variáveis

```c
int a = 10;
int *p = &a;

printf("%d\n", *p);  // 10

*p = 20;             // Modifica o valor de a através do ponteiro
printf("%d\n", a);   // 20
```

### Tipo Base e sizeof()

O **tipo base** do ponteiro define o tamanho do dado apontado:

```c
printf("Tamanho de int: %ld bytes\n", sizeof(int));
printf("Tamanho de float: %ld bytes\n", sizeof(float));
printf("Tamanho de double: %ld bytes\n", sizeof(double));
printf("Tamanho de char: %ld bytes\n", sizeof(char));
printf("Tamanho de ponteiro: %ld bytes\n", sizeof(int*));
```

### Aritmética de Ponteiros

Ponteiros podem ser incrementados e decrementados:

```c
int v[] = {10, 20, 30, 40, 50};
int *p = v;  // p aponta para v[0]

printf("%d\n", *p);      // 10
p++;                     // p agora aponta para v[1]
printf("%d\n", *p);      // 20
p += 2;                  // p agora aponta para v[3]
printf("%d\n", *p);      // 40
```

**Importante:** Ao incrementar um ponteiro, ele avança pelo tamanho do tipo base:

```c
int *pi;
char *pc;

pi++;  // Avança 4 bytes (sizeof(int))
pc++;  // Avança 1 byte (sizeof(char))
```

### Ponteiros e Vetores

O nome de um vetor é um ponteiro constante para o primeiro elemento:

```c
int v[5] = {1, 2, 3, 4, 5};
int *p = v;

// Formas equivalentes de acessar elementos:
printf("%d\n", v[2]);      // 3
printf("%d\n", *(v + 2));  // 3
printf("%d\n", p[2]);      // 3
printf("%d\n", *(p + 2));  // 3
```

### Ponteiros e Strings

Strings são vetores de caracteres, portanto podem ser manipuladas com ponteiros:

```c
char str[] = "Hello";
char *p = str;

while (*p != '\0') {
    printf("%c", *p);
    p++;
}
// Imprime: Hello
```

### Ponteiros para Ponteiros

Um ponteiro pode apontar para outro ponteiro:

```c
int a = 10;
int *p = &a;
int **pp = &p;

printf("%d\n", a);     // 10
printf("%d\n", *p);    // 10
printf("%d\n", **pp);  // 10

**pp = 20;
printf("%d\n", a);     // 20
```

### Ponteiros Nulos

Um ponteiro pode ser inicializado com `NULL` para indicar que não aponta para nada:

```c
int *p = NULL;

if (p == NULL) {
    printf("Ponteiro não inicializado\n");
}
```

**⚠️ Boas Práticas:**
- Sempre inicialize ponteiros
- Verifique se o ponteiro é NULL antes de usar
- Evite ponteiros "soltos" (dangling pointers)

---

## 5. Ponteiros e Funções

A combinação de ponteiros com funções permite modificar valores originais, trabalhar eficientemente com estruturas de dados grandes e criar funções mais flexíveis.

**Por que usar ponteiros em funções?**

1. **Modificar o valor original**: Sem ponteiros, a função trabalha com cópias
2. **Eficiência**: Evitar copiar grandes estruturas de dados
3. **Retornar múltiplos valores**: Uma função pode modificar várias variáveis
4. **Trabalhar com arrays**: Arrays são sempre passados por referência

**Conceito-chave: Passagem por Valor vs Passagem por Referência**

- **Por Valor**: A função recebe uma *cópia* do valor. Alterações não afetam o original.
- **Por Referência**: A função recebe o *endereço* da variável. Alterações afetam o original.

### Passagem por Referência

Permite que uma função modifique o valor original de uma variável:

```c
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    printf("Antes: x=%d, y=%d\n", x, y);

    troca(&x, &y);

    printf("Depois: x=%d, y=%d\n", x, y);
    // Saída: x=20, y=10
    return 0;
}
```

### Funções e Strings

Strings são sempre passadas por referência:

```c
void maiuscula(char *s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            *s = *s - 32; // Converte para maiúscula
        }
        s++;
    }
}

int main() {
    char texto[] = "hello world";
    maiuscula(texto);
    printf("%s\n", texto); // "HELLO WORLD"
    return 0;
}
```

### Função para Contar Caracteres

```c
int contaChar(char *s, char c) {
    int count = 0;
    while (*s) {
        if (*s == c) {
            count++;
        }
        s++;
    }
    return count;
}

int main() {
    char texto[] = "banana";
    int n = contaChar(texto, 'a');
    printf("Quantidade de 'a': %d\n", n); // 3
    return 0;
}
```

### Funções e Vetores

Vetores são automaticamente passados por referência:

```c
void preencheVetor(int *v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        v[i] = i * 2;
    }
}

void imprimeVetor(int *v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int vetor[5];
    preencheVetor(vetor, 5);
    imprimeVetor(vetor, 5);
    // Saída: 0 2 4 6 8
    return 0;
}
```

### Funções e Matrizes

#### Forma 1: Especificando número de colunas

```c
void imprimeMatriz(int m[][3], int linhas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
    imprimeMatriz(matriz, 2);
    return 0;
}
```

#### Forma 2: Usando ponteiro simples

```c
void imprimeMatriz(int *m, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", *(m + i * colunas + j));
        }
        printf("\n");
    }
}

int main() {
    int matriz[2][3] = {{1, 2, 3}, {4, 5, 6}};
    imprimeMatriz((int*)matriz, 2, 3);
    return 0;
}
```

### Funções que Retornam Ponteiros

Uma função pode retornar um ponteiro:

```c
char* buscaChar(char c, char *s) {
    while (*s != '\0' && *s != c) {
        s++;
    }
    return s; // Retorna ponteiro para o caractere encontrado ou '\0'
}

int main() {
    char texto[] = "programacao";
    char *resultado = buscaChar('g', texto);

    if (*resultado != '\0') {
        printf("Encontrado: %c\n", *resultado);
        printf("Restante: %s\n", resultado);
    }
    // Saída: Encontrado: g
    //        Restante: gramacao
    return 0;
}
```

### Modificando Múltiplos Valores

```c
void calculaCirculo(float raio, float *area, float *perimetro) {
    *area = 3.14159 * raio * raio;
    *perimetro = 2 * 3.14159 * raio;
}

int main() {
    float raio = 5.0;
    float area, perimetro;

    calculaCirculo(raio, &area, &perimetro);

    printf("Raio: %.2f\n", raio);
    printf("Área: %.2f\n", area);
    printf("Perímetro: %.2f\n", perimetro);
    return 0;
}
```

### Array de Ponteiros

```c
void imprimeStrings(char *strings[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("%s\n", strings[i]);
    }
}

int main() {
    char *nomes[] = {"João", "Maria", "Pedro", "Ana"};
    imprimeStrings(nomes, 4);
    return 0;
}
```

**⚠️ Cuidado:** Nunca retorne o endereço de uma variável local:

```c
// ERRADO!
int* funcaoErrada() {
    int x = 10;
    return &x; // x deixa de existir ao sair da função
}

// CORRETO - usando alocação dinâmica
int* funcaoCorreta() {
    int *p = malloc(sizeof(int));
    *p = 10;
    return p; // memória persiste após o retorno
}
```

---

## 6. Alocação Dinâmica de Memória

**Alocação dinâmica** permite que o programa reserve memória durante a execução, possibilitando estruturas de dados de tamanho variável. A memória alocada dinamicamente fica na **heap** e deve ser gerenciada manualmente.

**Por que usar alocação dinâmica?**

1. **Tamanho desconhecido**: Quando não sabemos o tamanho dos dados em tempo de compilação
2. **Flexibilidade**: Estruturas que crescem ou diminuem durante a execução
3. **Grandes estruturas**: A heap tem mais espaço que a stack
4. **Persistência**: Dados na heap persistem até serem liberados manualmente

**Importante entender:**
- **Stack (Pilha)**: Memória automática, limitada, rápida, gerenciada pelo compilador
- **Heap (Monte)**: Memória dinâmica, maior, mais lenta, gerenciada pelo programador

**⚠️ Responsabilidade do Programador:**
Com grande poder vem grande responsabilidade! Você deve:
- Verificar se a alocação foi bem-sucedida
- Liberar TODA memória alocada
- Não usar memória após liberá-la
- Não liberar a mesma memória duas vezes

### Diferença entre Memória Estática e Dinâmica

| Estática (Stack) | Dinâmica (Heap) |
|------------------|-----------------|
| Tamanho fixo em tempo de compilação | Tamanho definido em tempo de execução |
| Liberada automaticamente | Deve ser liberada manualmente |
| Mais rápida | Mais lenta |
| Tamanho limitado (~1-8 MB) | Tamanho maior disponível (GB) |
| Vida útil: escopo da variável | Vida útil: até chamar `free()` |

### Funções Principais

#### malloc() - Memory Allocation

Aloca um bloco de memória **não inicializado** e retorna um ponteiro para o início.

**Sintaxe:** `void* malloc(size_t size)`

**Quando usar:**
- Você precisa alocar memória mas não se importa com o conteúdo inicial
- Vai preencher os valores logo em seguida
- Quer performance (não inicializa, então é mais rápido que calloc)

```c
#include <stdlib.h>

int *p = (int*) malloc(sizeof(int));
if (p == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}

*p = 42;
printf("%d\n", *p);

free(p); // SEMPRE libere a memória!
```

#### calloc() - Contiguous Allocation

Aloca memória e **inicializa todos os bytes com zero**.

**Sintaxe:** `void* calloc(size_t num, size_t size)`

**Quando usar:**
- Você quer garantir que todos os valores iniciem em zero
- Está alocando arrays que precisam estar limpos
- Segurança: evitar valores lixo na memória

```c
int *v = (int*) calloc(10, sizeof(int));
if (v == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}

// Todos os elementos são 0
for (int i = 0; i < 10; i++) {
    printf("%d ", v[i]); // 0 0 0 0 0 0 0 0 0 0
}

free(v);
```

#### realloc() - Reallocation

Redimensiona um bloco de memória já alocado (pode aumentar ou diminuir).

**Sintaxe:** `void* realloc(void* ptr, size_t new_size)`

**Quando usar:**
- Estruturas dinâmicas que crescem (listas, arrays dinâmicos)
- Você precisa de mais espaço mas quer manter os dados existentes
- Otimizar memória reduzindo um bloco que ficou grande demais

**Importante:**
- Pode retornar um endereço diferente (copia os dados se necessário)
- Sempre atribua o retorno a uma variável (não perca o ponteiro original)
- Se falhar, retorna NULL mas o bloco original permanece válido

```c
int *v = (int*) malloc(5 * sizeof(int));

// Preenche o vetor
for (int i = 0; i < 5; i++) {
    v[i] = i + 1;
}

// Aumenta o tamanho para 10
v = (int*) realloc(v, 10 * sizeof(int));
if (v == NULL) {
    printf("Erro ao redimensionar!\n");
    exit(1);
}

// Preenche os novos elementos
for (int i = 5; i < 10; i++) {
    v[i] = i + 1;
}

free(v);
```

#### free() - Free Memory

Libera a memória alocada dinamicamente, devolvendo-a ao sistema.

**Sintaxe:** `void free(void* ptr)`

**Regras de Ouro:**
- SEMPRE libere memória que você alocou (evitar memory leaks)
- NUNCA use um ponteiro após liberá-lo (dangling pointer)
- NUNCA libere o mesmo ponteiro duas vezes (double free)
- É seguro chamar `free(NULL)` (não faz nada)

**Boa prática:** Após liberar, atribua NULL ao ponteiro

```c
int *p = malloc(sizeof(int));
*p = 100;
free(p);
// p agora é um ponteiro solto, não use mais!
p = NULL; // Boa prática
```

### Vetor Dinâmico

```c
int tamanho;
printf("Digite o tamanho do vetor: ");
scanf("%d", &tamanho);

int *vetor = (int*) malloc(tamanho * sizeof(int));
if (vetor == NULL) {
    printf("Erro de alocação!\n");
    return 1;
}

// Preenche
for (int i = 0; i < tamanho; i++) {
    vetor[i] = i * 2;
}

// Usa
for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
}

free(vetor);
```

### String Dinâmica

```c
char *str = (char*) malloc(100 * sizeof(char));
if (str == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}

printf("Digite um texto: ");
fgets(str, 100, stdin);

// Remove o \n do final
str[strcspn(str, "\n")] = '\0';

// Inverte a string
int len = strlen(str);
for (int i = 0; i < len/2; i++) {
    char temp = str[i];
    str[i] = str[len-1-i];
    str[len-1-i] = temp;
}

printf("String invertida: %s\n", str);
free(str);
```

### Matriz Dinâmica (Forma 1: Array Unidimensional)

Trata a matriz como um array único e calcula os índices:

```c
int linhas, colunas;
printf("Digite linhas e colunas: ");
scanf("%d %d", &linhas, &colunas);

float *matriz = (float*) malloc(linhas * colunas * sizeof(float));
if (matriz == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}

// Preenche
for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
        *(matriz + i * colunas + j) = i + j;
    }
}

// Imprime
for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
        printf("%.1f ", *(matriz + i * colunas + j));
    }
    printf("\n");
}

free(matriz);
```

### Matriz Dinâmica (Forma 2: Ponteiro para Ponteiro)

Cria uma matriz "real" com cada linha alocada separadamente:

```c
int linhas, colunas;
printf("Digite linhas e colunas: ");
scanf("%d %d", &linhas, &colunas);

// Aloca array de ponteiros (linhas)
int **matriz = (int**) malloc(linhas * sizeof(int*));
if (matriz == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}

// Aloca cada linha
for (int i = 0; i < linhas; i++) {
    matriz[i] = (int*) malloc(colunas * sizeof(int));
    if (matriz[i] == NULL) {
        printf("Erro de alocação!\n");
        exit(1);
    }
}

// Preenche
for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
        matriz[i][j] = i * colunas + j;
    }
}

// Imprime
for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}

// Libera cada linha
for (int i = 0; i < linhas; i++) {
    free(matriz[i]);
}
// Libera o array de ponteiros
free(matriz);
```

### Estruturas Dinâmicas

```c
typedef struct {
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int n;
printf("Quantas pessoas? ");
scanf("%d", &n);

Pessoa *pessoas = (Pessoa*) malloc(n * sizeof(Pessoa));
if (pessoas == NULL) {
    printf("Erro de alocação!\n");
    exit(1);
}

// Preenche
for (int i = 0; i < n; i++) {
    printf("Nome: ");
    scanf(" %[^\n]", pessoas[i].nome);
    printf("Idade: ");
    scanf("%d", &pessoas[i].idade);
    printf("Altura: ");
    scanf("%f", &pessoas[i].altura);
}

// Exibe
for (int i = 0; i < n; i++) {
    printf("\nPessoa %d:\n", i+1);
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Idade: %d\n", pessoas[i].idade);
    printf("Altura: %.2f\n", pessoas[i].altura);
}

free(pessoas);
```

### Exemplo Completo: Lista Redimensionável

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int tamanho;
    int capacidade;
} Lista;

Lista* criaLista() {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    lista->capacidade = 2;
    lista->tamanho = 0;
    lista->dados = (int*) malloc(lista->capacidade * sizeof(int));
    return lista;
}

void adiciona(Lista *lista, int valor) {
    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2;
        lista->dados = (int*) realloc(lista->dados,
                                      lista->capacidade * sizeof(int));
    }
    lista->dados[lista->tamanho++] = valor;
}

void imprimeLista(Lista *lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->dados[i]);
    }
    printf("\n");
}

void liberaLista(Lista *lista) {
    free(lista->dados);
    free(lista);
}

int main() {
    Lista *lista = criaLista();

    for (int i = 1; i <= 10; i++) {
        adiciona(lista, i * 10);
    }

    imprimeLista(lista);

    liberaLista(lista);
    return 0;
}
```

### Comparação entre malloc, calloc e realloc

| Função | Inicialização | Parâmetros | Uso Principal |
|--------|---------------|------------|---------------|
| `malloc(size)` | Não inicializa (lixo) | Tamanho total em bytes | Alocação rápida quando vai preencher depois |
| `calloc(n, size)` | Inicializa com zeros | Número de elementos + tamanho | Arrays que precisam iniciar em zero |
| `realloc(ptr, size)` | Mantém valores existentes | Ponteiro existente + novo tamanho | Redimensionar estruturas dinâmicas |

### Erros Comuns com Alocação Dinâmica

#### 1. Memory Leak (Vazamento de Memória)
```c
// ERRADO - nunca libera a memória
for (int i = 0; i < 1000; i++) {
    int *p = malloc(sizeof(int));
    *p = i;
    // Esqueceu de liberar!
}

// CORRETO
for (int i = 0; i < 1000; i++) {
    int *p = malloc(sizeof(int));
    *p = i;
    free(p);
}
```

#### 2. Dangling Pointer (Ponteiro Solto)
```c
// ERRADO - usa ponteiro após liberar
int *p = malloc(sizeof(int));
*p = 10;
free(p);
printf("%d\n", *p); // ERRO! Memória já foi liberada

// CORRETO
int *p = malloc(sizeof(int));
*p = 10;
free(p);
p = NULL; // Marca como inválido
if (p != NULL) {
    printf("%d\n", *p);
}
```

#### 3. Double Free
```c
// ERRADO - libera duas vezes
int *p = malloc(sizeof(int));
free(p);
free(p); // ERRO! Já foi liberado

// CORRETO
int *p = malloc(sizeof(int));
free(p);
p = NULL;
if (p != NULL) {
    free(p); // Não será executado
}
```

#### 4. Não Verificar se Alocação Foi Bem-Sucedida
```c
// ERRADO - não verifica NULL
int *p = malloc(1000000000000); // Pode falhar!
*p = 10; // CRASH se malloc falhou

// CORRETO
int *p = malloc(1000000000000);
if (p == NULL) {
    printf("Erro: memória insuficiente!\n");
    exit(1);
}
*p = 10;
free(p);
```

**⚠️ Regras de Ouro da Alocação Dinâmica:**

1. **Sempre verifique se a alocação foi bem-sucedida** (`if (ptr == NULL)`)
2. **Sempre libere a memória alocada** com `free()` quando não precisar mais
3. **Evite vazamento de memória** (memory leak) - cada `malloc` precisa de um `free`
4. **Não use ponteiros após liberá-los** (dangling pointer) - atribua NULL após free
5. **Não libere a mesma memória duas vezes** (double free) - causa crash
6. **Use ferramentas de detecção**: Valgrind (Linux) ou AddressSanitizer ajudam a encontrar erros

---


## 📚 Resumo Geral

| Conceito | Descrição | Uso Principal |
|----------|-----------|---------------|
| **struct** | Agrupa dados heterogêneos | Representar entidades complexas |
| **union** | Compartilha memória entre membros | Economizar memória |
| **enum** | Define constantes nomeadas | Melhorar legibilidade do código |
| **typedef** | Cria sinônimos para tipos | Simplificar declarações |
| **Funções** | Modularizam o código | Reutilização e organização |
| **Recursividade** | Função que chama a si mesma | Problemas divisíveis em subproblemas |
| **Ponteiros** | Armazenam endereços de memória | Manipulação eficiente de dados |
| **Passagem por Referência** | Passa endereço da variável | Modificar valores originais |
| **malloc()** | Aloca memória dinamicamente | Estruturas de tamanho variável |
| **free()** | Libera memória alocada | Evitar vazamento de memória |

---

## 📖 Conceitos-Chave

### Boas Práticas

✅ **Sempre fazer:**
- Inicializar ponteiros
- Verificar se `malloc()` retornou `NULL`
- Liberar memória com `free()`
- Usar nomes descritivos para variáveis e funções
- Modularizar o código
- Comentar partes complexas

❌ **Nunca fazer:**
- Usar ponteiros não inicializados
- Esquecer de liberar memória alocada
- Acessar memória após liberá-la
- Retornar endereço de variável local
- Usar variáveis globais em excesso

### Performance

- **Ponteiros**: Mais rápido que copiar grandes estruturas
- **Recursão**: Elegante mas pode ser ineficiente (usar com cuidado)
- **Alocação dinâmica**: Overhead de gerenciamento, usar quando necessário
- **Arrays estáticos**: Mais rápidos, preferir quando o tamanho é conhecido

---

## 🎯 Dicas de Estudo e Boas Práticas

### Estratégias de Aprendizado

1. **Pratique regularmente**: Resolva exercícios diariamente, mesmo que pequenos
2. **Entenda antes de decorar**: Foque em compreender conceitos, não memorizar sintaxe
3. **Desenhe a memória**: Visualize como ponteiros, arrays e structs funcionam na memória
4. **Comece simples**: Domine o básico antes de partir para problemas complexos
5. **Leia código de outros**: Analise diferentes abordagens para o mesmo problema
6. **Revise conceitos básicos**: Quando travar, volte aos fundamentos

### Debugging e Ferramentas

1. **Use ferramentas de debug**: GDB (Linux), LLDB (Mac), Visual Studio Debugger (Windows)
2. **Compile com warnings**: `gcc -Wall -Wextra -g arquivo.c -o programa`
3. **Valgrind para memória**: Detecta leaks e erros de memória (Linux)
4. **Print statements**: Às vezes, simples `printf` ajudam mais que debuggers complexos
5. **Leia mensagens de erro**: Compiladores dão dicas valiosas sobre o problema

### Escrevendo Código de Qualidade

1. **Nomes descritivos**: `calcularMedia()` é melhor que `calc()`
2. **Funções pequenas**: Se faz muitas coisas, divida em funções menores
3. **Comente o porquê, não o quê**: O código mostra o que faz, comentários explicam por quê
4. **Evite magic numbers**: Use constantes ou enums para valores fixos
5. **Verifique retornos**: Sempre verifique se malloc, scanf, fopen etc. tiveram sucesso
6. **Libere recursos**: Toda memória alocada e arquivo aberto deve ser liberado/fechado
7. **Indentação consistente**: Use 2 ou 4 espaços, mas seja consistente

### Erros Comuns a Evitar

❌ **Ponteiros não inicializados**
```c
int *p;  // NÃO FAÇA ISSO
*p = 10; // CRASH!
```

❌ **Esquecer o `&` no scanf**
```c
int x;
scanf("%d", x);  // ERRADO
scanf("%d", &x); // CORRETO
```

❌ **Buffer overflow em strings**
```c
char nome[10];
scanf("%s", nome); // Perigoso! Usuário pode digitar mais de 10 caracteres
fgets(nome, 10, stdin); // Mais seguro
```

❌ **Comparar strings com `==`**
```c
char s1[] = "teste";
char s2[] = "teste";
if (s1 == s2) // ERRADO - compara endereços
if (strcmp(s1, s2) == 0) // CORRETO - compara conteúdo
```

❌ **Esquecer `\0` em strings**
```c
char str[5] = {'t', 'e', 's', 't', 'e'}; // ERRADO - não é uma string válida
char str[6] = {'t', 'e', 's', 't', 'e', '\0'}; // CORRETO
```

---

## 📚 Recursos Adicionais

### Referências Online
- [Documentação Oficial C](https://en.cppreference.com/) - Referência completa da linguagem
- [Tutorial C - GeeksforGeeks](https://www.geeksforgeeks.org/c-programming-language/) - Tutoriais e exercícios
- [Visualizador de Código C](https://pythontutor.com/c.html) - Visualize a execução passo a passo
- [C Programming - Wikibooks](https://en.wikibooks.org/wiki/C_Programming) - Livro gratuito online

### Ferramentas Recomendadas
- **Compiladores**: GCC, Clang, Visual Studio
- **IDEs**: Visual Studio Code, CLion, Code::Blocks
- **Debuggers**: GDB, Valgrind, LLDB
- **Online**: Replit, OnlineGDB, Compiler Explorer

### Livros Recomendados
- "C Programming: A Modern Approach" - K.N. King
- "The C Programming Language" - Kernighan & Ritchie (o clássico)
- "C: Como Programar" - Deitel & Deitel

---

## 🔍 Referência Rápida

### Operadores com Ponteiros
```c
int x = 10;
int *p = &x;    // & = endereço de
int valor = *p; // * = valor apontado (desreferência)
```

### Alocação Dinâmica - Cheat Sheet
```c
// Alocar
int *p = malloc(sizeof(int));
int *arr = calloc(10, sizeof(int));
arr = realloc(arr, 20 * sizeof(int));

// Sempre verificar
if (p == NULL) { /* erro */ }

// Sempre liberar
free(p);
p = NULL;
```

### Structs - Sintaxe Rápida
```c
// Definir
typedef struct {
    int id;
    char nome[50];
} Pessoa;

// Usar
Pessoa p1;
Pessoa *p2 = malloc(sizeof(Pessoa));

// Acessar
p1.id = 1;
p2->id = 2;
```

### Funções - Padrões Comuns
```c
// Modificar valor original
void funcao(int *p) {
    *p = 10;
}
int x = 0;
funcao(&x); // x agora é 10

// Trabalhar com arrays
void preenche(int arr[], int tam) {
    for(int i = 0; i < tam; i++)
        arr[i] = i;
}
```

### Strings - Operações Essenciais
```c
#include <string.h>

strlen(str);           // Tamanho
strcpy(dest, src);     // Copiar
strcmp(s1, s2);        // Comparar (0 = iguais)
strcat(dest, src);     // Concatenar
```

### Compilação - Comandos Úteis
```bash
# Compilar simples
gcc arquivo.c -o programa

# Com warnings e debug
gcc -Wall -Wextra -g arquivo.c -o programa

# Executar
./programa

# Debug com Valgrind (verificar memória)
valgrind --leak-check=full ./programa
```

---

## 📝 Checklist para Exercícios

Antes de entregar um exercício, verifique:

- [ ] O código compila sem erros
- [ ] Não há warnings do compilador
- [ ] Todos os ponteiros são inicializados
- [ ] Toda memória alocada é liberada
- [ ] Todos os arquivos abertos são fechados
- [ ] Funções têm nomes descritivos
- [ ] Código está indentado corretamente
- [ ] Testou com casos extremos (vazio, muito grande, etc.)
- [ ] Não há magic numbers (use constantes)
- [ ] Comentou partes complexas do código

---

## 🎓 Conclusão

Este guia cobre os fundamentos essenciais de **Algoritmos e Programação B**. Dominar estes conceitos é crucial para:

- Desenvolver programas eficientes e organizados
- Trabalhar com estruturas de dados complexas
- Gerenciar memória de forma segura e eficiente
- Preparar-se para disciplinas avançadas (Estruturas de Dados, Algoritmos)
- Construir uma base sólida para qualquer carreira em programação

**Lembre-se:** Programação se aprende **praticando**. Não basta ler - você precisa escrever código, cometer erros e aprender com eles. Cada erro é uma oportunidade de aprendizado!

---

## 📝 Licença

Este material é de livre uso para fins educacionais.

---

**Desenvolvido como material de estudo para a disciplina de Algoritmos e Programação B**
**Curso: Sistemas de Informação | Período: 2025**
*Um guia completo e prático para dominar programação em C*
