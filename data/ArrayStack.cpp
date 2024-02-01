#include <iostream>

using namespace std;


template<typename T>
class ArrayStack{
    private:
        int size;
        T* array;
        int capacity;

        void grow(){
            if(size >= capacity){
                capacity = (capacity + 10);
                array = static_cast<T*>(realloc(array, capacity * sizeof(T)));
            }
        }

        void shrink() {
            if((capacity/2) > size){
                capacity /= 2;
                array = static_cast<T*>(realloc(array, capacity * sizeof(T)));
            }
        }

    public:

        ArrayStack(){
            array = nullptr;
            size = 0;
            capacity = 2;
            array =  static_cast<T*>(malloc(capacity * sizeof(T)));
        }

        ~ArrayStack(){
            free(array);
            size = 0;
            capacity = 2;
        }

        void push(const T element){
            grow();
            array[size] = element;
            size++;
        }

        T pop(){
            if(size >= 0){
                T rmv = array[size-1];
                size--;
                shrink();

                return rmv;
            }

            throw std::out_of_range("empty stack");
        }

        T peek(){
            if(size >= 0){
                T rmv = array[size-1];
                return rmv;
            }
            throw std::out_of_range("empty stack");
        }

        bool isEmpty(){
            return size ==0;
        }

        void forEach(void (*func)(T)){
            while(!isEmpty()){
                func(pop());
            }
        }

        T* toArray() const {
            T* copyArray = static_cast<T*>(malloc((size+1) * sizeof(T)));

            for (int i = 0; i < size; i++) {
                copyArray[i] = array[i];
            }

            return copyArray;
        }

        void clear(){
            free(array);
            size = 0;
            capacity = 2;
            array =  static_cast<T*>(malloc(capacity * sizeof(T)));
        }
};

int main(){
    ArrayStack<int> stack;

    stack.push(1);
    stack.push(5);
    stack.clear();

    cout << stack.isEmpty() << endl;

    return 0;
}