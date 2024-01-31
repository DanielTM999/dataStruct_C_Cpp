### Conjunto de estruturas de dados em C/C++

# ArrayList - Estrutura de Dados em C/C++

## Descrição

O `ArrayList` é uma implementação simples de uma lista dinâmica em C/C++, projetada para fornecer funcionalidades básicas de armazenamento e manipulação de elementos.

## Características

- **Alocação Dinâmica:** A estrutura utiliza alocação dinâmica de memória para permitir o crescimento automático conforme a necessidade.
- **Tipos Genéricos:** Pode ser usado com diferentes tipos de dados, incluindo inteiros, floats, caracteres, etc.
- **Operações Básicas:** Inclui operações comuns, como adicionar elementos, remover elementos, obter um elemento pelo índice, encontrar o índice de um elemento, verificar se está vazia, entre outras.
- **Iteração:** Suporta a iteração através dos elementos usando a função `forEach`.

## Uso Básico

```cpp
#include "ArrayList.h"

int main() {
    // Criando uma instância da ArrayList
    ArrayList<int> lista;

    // Adicionando elementos
    lista.Add(5);
    lista.Add(10);
    lista.Add(15);

    // Iterando e imprimindo os elementos
    lista.forEach([](int elemento) {
        printf("%d ", elemento);
    });

    // Removendo um elemento
    lista.remove(1);

    // Obtendo o tamanho da lista
    int tamanho = lista.lenght();

    return 0;
}

