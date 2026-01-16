# 🚀 Compressor de Arquivos - Algoritmo de Huffman (C++)

Projeto desenvolvido em **C++** focado em eficiência de armazenamento e manipulação de baixo nível (Bitwise Operations).

Diferente de implementações acadêmicas que apenas simulam a compressão usando Strings, este projeto implementa um **BitWriter** real, capaz de manipular bits individuais na memória e gravar arquivos binários (`.huff`) fisicamente menores que os originais.

## 📌 Objetivo do Projeto

Aplicar conceitos avançados de **Estrutura de Dados** e **Arquitetura de Computadores** para criar uma ferramenta funcional de compressão. O foco principal foi sair da abstração de alto nível e controlar a escrita de bytes no disco manualmente.

**Principais Desafios Técnicos:**
* Implementação de Árvores Binárias e Filas de Prioridade (Heap).
* Manipulação de memória bit a bit (operadores `<<`, `|`, `&`).
* Gerenciamento de buffer e I/O de arquivos binários.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++ (STL Standard Template Library)
* **Algoritmos:** Huffman Coding (Greedy Algorithm)
* **Estruturas de Dados:** `priority_queue`, `map`, `struct` (Árvores)
* **Técnicas:** Bit shifting e Bitwise masking

## 🧩 Estrutura do Sistema

O projeto foi modularizado para separar a lógica de I/O da lógica algorítmica:

* **💾 BitWriter (Engine):** Classe responsável por acumular bits em um *buffer* de 1 byte (8 bits) e despejar no disco apenas quando o byte está completo. Garante a compactação real.
* **🌳 Huffman Logic:** Responsável pela contagem estatística de frequência, construção da árvore "bottom-up" e geração da tabela de códigos.
* **🖥️ Main System:** Interface de linha de comando (CLI) que gerencia entradas de usuário e leitura de arquivos `.txt`.

## 🎯 Funcionalidades

* **Compressão de Strings:** Entrada manual de texto para testes rápidos.
* **Compressão de Arquivos:** Leitura de arquivos `.txt` e geração automática de arquivos `.huff`.
* **Relatório de Performance:** Cálculo matemático da taxa de compressão e economia de espaço em disco.
* **Tratamento de Padding:** Algoritmo de *flush* para garantir que bits remanescentes não sejam perdidos no final do arquivo.

## 🔍 Exemplo de Execução

Teste realizado com uma entrada de texto simples para validar a lógica de compactação:

```text
=== COMPRESSOR DE HUFFMAN ===
1. Digitar mensagem manualmente
2. Ler arquivo de texto (.txt)
Escolha uma opcao: 1

Digite a mensagem: Igor Dias

Comprimindo para 'saida_padrao.huff'...

--- Relatorio Final ---
Arquivo Original: 9 bytes
Arquivo Comprimido (.huff): 4 bytes
Economia de espaco: 55.5556%
SUCESSO: Compressao realizada!
```

## ▶️ Como Executar

Este projeto foi desenvolvido em C++ modular. Para executá-lo, é necessário compilar todos os arquivos fonte (`.cpp`) simultaneamente.

### 📋 Pré-requisitos
* Compilador C++ instalado (GCC/G++, MinGW ou Clang).
* Git (opcional, para clonar o repositório).

### 🚀 Compilação e Execução

1.  **Baixe o código** e acesse a pasta do projeto pelo terminal/cmd.

2.  **Compile o projeto:**
    Utilize o comando abaixo para compilar o `main` junto com as implementações do `BitWriter` e `Huffman`:
    ```bash
    g++ *.cpp -o huffman
    ```
    *(Isso instrui o compilador a pegar o `main.cpp`, `BitWriter.cpp` e `Huffman.cpp` e gerar um executável chamado `huffman`)*.

3.  **Execute a aplicação:**
    * **No Windows:**
        ```bash
        huffman.exe
        ```
    * **No Linux/macOS:**
        ```bash
        ./huffman
        ```

4.  **Testando com Arquivos:**
    Para testar a opção de leitura de arquivo, certifique-se de que o arquivo de texto (ex: `teste.txt`) esteja **na mesma pasta** onde o executável foi gerado.
