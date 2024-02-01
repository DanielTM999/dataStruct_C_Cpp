#include <iostream>

using namespace std;


template<typename T>
class LinkedStack
{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node* preview;

            Node(const T value){
                data = value;
                next = nullptr;
            }
        };
        Node* head;
        Node* end;
        int size;

    public:

        LinkedStack(){
            head = nullptr;
            size = 0;
        }

        ~LinkedStack(){
            head = nullptr;
            size = 0;
        }

        void push(const T element){
            Node* novo = new Node(element);
            if(head == nullptr){
                head = novo;
                end = head;
            }else{
                end->next = novo;
                end->preview = end;
                end = end->next;
            }
            size++;
        }

        T pop(){
            T valor_pop = end->data;

            if(end == head){
                delete end;
                head = end = nullptr;
            }else{
                Node* current = head;
                Node* previous = nullptr;
                while (current->next)
                {
                    previous = current;
                    current = current->next;
                }
                delete current;
                previous->next = nullptr;
            }

            return valor_pop;
        }

        T peek(){
            return end->data;
        }

        bool isEmpty(){
            return head == nullptr;
        }

        void clear(){
            head = nullptr;
            end = nullptr;
            size = 0;
        }

        void forEach(void (*func)(T)){
            Node* temp = head;
            while(!isEmpty()){
                func(temp->data);
                temp = temp->next;
            }
        }

        T* toArray() {
            T* copyArray = static_cast<T*>(malloc((size+1) * sizeof(T)));
        
            Node* temp = head;
            for (int i = 0; i < size; i++) {
                copyArray[i] = temp->data;
                temp = temp->next;
            }

            return copyArray;
        }
};

int main(){

    LinkedStack<int> stack;

    stack.push(5);
    stack.push(4);
    stack.push(3);

    stack.forEach([](int x){
        cout << x << endl;  
    });

    return 0;
}