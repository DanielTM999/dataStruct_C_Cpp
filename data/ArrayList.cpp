#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <typeinfo>
#include <iostream>

template <typename T>
class ArrayList{
private:
    T* data;
    int capacity;
    int size;

    void grow(){
        if(size >= capacity){
            capacity = (capacity + 10);
            data = static_cast<T*>(realloc(data, capacity * sizeof(T)));
        }
    }

    void shrink() {
        if((capacity/2) > size){
            capacity /= 2;
            data = static_cast<T*>(realloc(data, capacity * sizeof(T)));
        }
    }

public:
    ArrayList(){
        data = nullptr;
        size = 0;
        capacity = 2;
        data =  static_cast<T*>(malloc(capacity * sizeof(T)));
    }

    ~ArrayList(){
        free(data);
        size = 0;
        capacity = 2;
    }

    void Add(const T element){
        grow();
        data[size] = element;
        size++;
    }

    void Add(const T element, int position){
        grow();
        if (position < 0 || position > size){
            Add(element);
        }else{
            for (int i = size; i > position; i--){
                data[i] = data[i - 1];
            }
            data[position] = element;
        }
        size++;
    }

    void remove(const int index){
        if(index >= 0 && index < size){
            for(int i = index; i < size; i++){
                data[i] = data[i + 1];
            }
            size--;
        }
        shrink();
    }

    T get(int index) {
        if(index < 0 || index >= size){
            int temp = size -1;
            return data[temp];
        }
        return data[index];
    }

    int indexOf(const T element){
        for(int i = 0; i < size; i++){
            if(data[i] == element){
                return i;
            }
        }
        return -1;
    }

    int lenght() const {
        return size;
    }

    void clear(){
        free(data);
        size = 0;
        capacity = 2;
        data =  static_cast<T*>(malloc(capacity * sizeof(T)));
    }

    bool isEmpty(){
        return size == 0;
    }

    T* toArray() const {
        T* array = static_cast<T*>(malloc(capacity * sizeof(T)));

        for (int i = 0; i < size; i++) {
            array[i] = data[i];
        }

        return array;
    }

    void forEach(void (*func)(T elemento)){
        for (int i = 0; i < size; i++) {
            func(data[i]);
        }
    }

    void copyList(ArrayList<T>& listToCopy){
        for(int i = 0; i < size; i++){
            listToCopy.Add(data[i]);
        }
    }

    void print(){
        for (int i = 0; i < size; i++) {
            std::cout<< data[i] << std::endl;
        }
    }

};


int main(){
    ArrayList<int> lista;

    lista.Add(1);
    lista.Add(5);

    lista.print();
}

