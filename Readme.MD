### Conjunto de estruturas de dados em C/C++

# ArrayList - Estrutura de Dados em C/C++

## Descrição

O `ArrayList` é uma implementação simples de uma lista dinâmica em C/C++, projetada para fornecer funcionalidades básicas de armazenamento e manipulação de elementos.

## Características

- **Alocação Dinâmica:** A estrutura utiliza alocação dinâmica de memória para permitir o crescimento automático conforme a necessidade.
- **Tipos Genéricos:** Pode ser usado com diferentes tipos de dados, incluindo inteiros, floats, caracteres, etc.
- **Operações Básicas:** Inclui operações comuns, como adicionar elementos, remover elementos, obter um elemento pelo índice, encontrar o índice de um elemento, verificar se está vazia, entre outras.
- **Iteração:** Suporta a iteração através dos elementos usando a função `forEach`.

## funçoes
- **Add(T element);**: adiciona na lista.
- **Add(T element, int pos);**: adiciona na lista em uma posição especifica.
- **remove(int index);**: remove o elemento na posição especificada.
- **get(int index);**: retorna o elemento na posição especificada.
- **indexOf(T elemento);**: retorna o índice da primeira ocorrência do elemento na lista.
- **length();**: retorna o tamanho da lista.
- **clear();**: limpa a lista.
- **isEmpty*();**:* verifica se a lista está vazia.
- **toArray();**: retorna um array contendo os elementos da lista.
- **forEach(void (*func)(T));**: executa a função fornecida em cada elemento da lista.
- **copyList(ArrayList<T>& listaParaCopiar);**: copia os elementos da lista atual para outra lista.
- **print();**: imprime os elementos da lista.

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
```

# LinkedList - Estrutura de Dados em C/C++

## Descrição

A `LinkedList` é uma implementação simples de uma lista ligada em C/C++, projetada para fornecer funcionalidades básicas de armazenamento e manipulação de elementos.

## Características

- **Alocação Dinâmica:** A estrutura utiliza alocação dinâmica de memória para permitir o crescimento automático conforme a necessidade.
- **Operações Básicas:** Inclui operações comuns, como adicionar elementos no início e no final, remover elementos do início e do final, obter um elemento pelo índice, verificar o tamanho da lista, entre outras.
- **Tipos Genéricos:** Pode ser usado com diferentes tipos de dados, incluindo inteiros, floats, caracteres, etc.
- **Iteração:** Suporta a iteração através dos elementos usando a função `forEach`.

## funçoes
- **addToFront(T element);**: Adiciona um elemento na base da lista.
- **addToBack(T element);**: Adiciona um elemento no final da lista.
- **removeBack();**: Remove o elemento do final da lista.
- **removeFront();**: Remove o elemento do inicio da lista.
- **forEach(void (*func)(T));**: executa a função fornecida em cada elemento da lista.
- **toArray();**: Obtem a lista como array.
- **clear();**: limpa a lista.

## Uso Básico

```cpp
#include "LinkedList.h"

int main() {
    // Criando uma instância da LinkedList
    LinkedList<int> lista;

    // Adicionando elementos no início e no final
    lista.addToFront(5);
    lista.addToFront(3);
    lista.addToBack(8);

    // Removendo elementos do início e do final
    lista.removeFront();
    lista.removeBack();

    // Obtendo um elemento pelo índice
    int elemento = lista.get(0);

    // Obtendo o tamanho da lista
    int tamanho = lista.length();

    // Obtendo a lista como array
    int* array = lista.toArray();

    return 0;
}
```

# Stack - Estrutura de Dados em C/C++

## Descrição

A desenvolver...