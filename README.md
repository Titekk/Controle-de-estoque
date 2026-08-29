# 📦 Controle de Estoque em C++

[![C++](https://img.shields.io/badge/C++-11%2B-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-success.svg)]()

Um sistema simples, eficiente e direto via terminal (CLI) desenvolvido em **C++** para gerenciamento e controle de estoque de produtos, permitindo cadastrar itens, dar baixa em quantidades, listar o estoque em tempo real e exportar os registros para um arquivo de texto.

---

## 📋 Sumário

- [Visão Geral](#-visão-geral)
- [Funcionalidades](#-funcionalidades)
- [Estrutura do Repositório](#-estrutura-do-repositório)
- [Pré-requisitos](#-pré-requisitos)
- [Como Compilar e Executar](#-como-compilar-e-executar)
  - [Opção 1: Compilação Direta com G++](#opção-1-compilação-direta-com-g)
  - [Opção 2: Compilação Direta com Clang++](#opção-2-compilação-direta-com-clang)
  - [Opção 3: Usando CMake](#opção-3-usando-cmake)
- [Exemplo de Uso](#-exemplo-de-uso)
- [Persistência dos Dados (`estoque.txt`)](#-persistência-dos-dados-estoquetxt)
- [Documentação Técnica](#-documentação-técnica)
- [Roadmap de Melhorias](#-roadmap-de-melhorias)
- [Contribuindo](#-contribuindo)
- [Autor e Licença](#-autor-e-licença)

---

## 🔍 Visão Geral

O **Controle de Estoque** foi criado com foco no aprendizado e aplicação prática de conceitos fundamentais da linguagem C++, tais como:
- Entrada e saída padrão (`std::cin`, `std::cout`, `std::setw`)
- Manipulação de arquivos (`std::ofstream`)
- Estruturas de dados de tamanho fixo (`std::array`)
- Tratamento e validação de fluxo de dados de entrada (`cin.fail()`, `cin.clear()`, `cin.ignore()`)
- Modularização com funções (`printMenu()`, `removeItem()`, `printEstoque()`)

---

## ✨ Funcionalidades

- ➕ **Adicionar Item:** Cadastra novos produtos com seus respectivos nomes e quantidades em estoque.
- ➖ **Remover / Dar Baixa:** Permite subtrair quantidades específicas ou zerar o estoque de um produto existente, com validação de saldo insuficiente.
- 📋 **Listar Estoque:** Exibe todos os itens cadastrados e suas respectivas quantidades atuais de forma formatada.
- 💾 **Exportação para Arquivo:** Ao encerrar o programa, os dados são automaticamente gravados no arquivo `estoque.txt`.
- 🛡️ **Validação de Entrada:** Tratamento contra entradas inválidas no menu principal, prevenindo loops infinitos.

---

## 📂 Estrutura do Repositório

```plaintext
Controle-de-estoque/
├── docs/
│   └── DOCUMENTACAO_TECNICA.md   # Arquitetura detalhada, fluxogramas e explicação das funções
├── .gitignore                    # Arquivos ignorados pelo Git (executáveis, builds, etc.)
├── CMakeLists.txt                # Arquivo de configuração de build multiplataforma
├── LICENSE                       # Licença do projeto (MIT)
├── main.cpp                      # Código-fonte principal da aplicação
└── README.md                     # Documentação geral do projeto
```

---

## 💻 Pré-requisitos

Para compilar e executar o projeto, você precisará de:
- Um compilador C++ com suporte a **C++11** ou superior:
  - **GCC / G++** (MinGW no Windows, nativo no Linux)
  - **Clang++** (macOS / Linux / Windows)
  - **MSVC** (Visual Studio no Windows)
- *(Opcional)* **CMake** (versão 3.10+)

---

## 🚀 Como Compilar e Executar

Clone o repositório em sua máquina:
```bash
git clone https://github.com/Titekk/Controle-de-estoque.git
cd Controle-de-estoque
```

### Opção 1: Compilação Direta com G++

**No Linux / macOS / Windows (MinGW):**
```bash
# Compilar
g++ -std=c++11 main.cpp -o controle_estoque

# Executar no Windows
controle_estoque.exe

# Executar no Linux / macOS
./controle_estoque
```

### Opção 2: Compilação Direta com Clang++
```bash
clang++ -std=c++11 main.cpp -o controle_estoque
./controle_estoque
```

### Opção 3: Usando CMake

```bash
# Criar diretório de build
mkdir build
cd build

# Gerar arquivos de compilação
cmake ..

# Compilar
cmake --build .

# Executar o programa
./controle_estoque   # ou controle_estoque.exe no Windows
```

---

## 🖥️ Exemplo de Uso

Ao iniciar a aplicação, você verá o seguinte menu interativo:

```text
==============================
       Controle de estoque
==============================
Selecione uma opção:
1. Adicionar item
2. Remover item
3. Listar estoque
4. Sair
Opção: 1

Digite o nome do item: Teclado
Digite a quantidade de items: 15
Item adicionado com sucesso!
Deseja continuar o programa: s/n? s

==============================
       Controle de estoque
==============================
Selecione uma opção:
1. Adicionar item
2. Remover item
3. Listar estoque
4. Sair
Opção: 3

=============================
  Estoque Atual
=============================
Nome do item: Teclado
Quantidade: 15
```

---

## 💾 Persistência dos Dados (`estoque.txt`)

Ao finalizar o programa (escolhendo a opção `4` ou respondendo `n` à pergunta de continuação), o sistema gera um arquivo chamado `estoque.txt` no mesmo diretório de execução:

```text
=============
   estoque
=============

Teclado
15
```

---

## 📖 Documentação Técnica

Para entender mais a fundo como as funções operam, ver os diagramas de fluxo em **Mermaid** e a análise das estruturas de dados utilizadas, confira o documento dedicado:
👉 [**docs/DOCUMENTACAO_TECNICA.md**](docs/DOCUMENTACAO_TECNICA.md)

---

## 🗺️ Roadmap de Melhorias

- [ ] Implementar Programação Orientada a Objetos com classes `Item` e `Estoque`.
- [ ] Leitura e carregamento automático de `estoque.txt` na inicialização.
- [ ] Substituir `std::array` estático por `std::vector` ou `std::unordered_map` dinâmicos.
- [ ] Impedir duplicidade de itens (somando a quantidade caso o item já exista).
- [ ] Adicionar campos extras como preço unitário e código de barras / SKU.

---

## 🤝 Contribuindo

Contribuições são super bem-vindas! Sinta-se à vontade para:
1. Fazer um Fork do projeto
2. Criar uma branch para sua funcionalidade (`git checkout -b feature/minha-feature`)
3. Commitar suas alterações (`git commit -m 'feat: Adiciona persistência na inicialização'`)
4. Fazer o push para a branch (`git push origin feature/minha-feature`)
5. Abrir um Pull Request

---

## 👤 Autor

Desenvolvido por **Nilmar Delgado** ([@Titekk](https://github.com/Titekk))

📧 Contato: deltite4@gmail.com

---

## 📄 Licença

Este projeto está licenciado sob a licença MIT - consulte o arquivo [LICENSE](LICENSE) para mais detalhes.
