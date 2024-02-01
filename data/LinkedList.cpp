#include <iostream>
#include <functional>

template<typename T>
class LinkedList
{
    private:
        struct Node
        {
            T data;
            Node* next;

            Node(const T value){
                data = value;
                next = nullptr;
            }
        };
        int size;
        Node* head;

    public:

        LinkedList(){
            head = nullptr;
            size = 0;
        }

        ~LinkedList() {
            head = nullptr;
            size = 0;
        }

        void addToFront(const T element){
            Node* novo = new Node(element);
            if(head == nullptr){
                head = novo;
            }else{
                novo->next = head;
                head = novo;
            }
            size++;
        }

        void addToBack(const T element){
            Node* novo = new Node(element);
            if(head == nullptr){
                head = novo;
            }else{
                Node* current = head;
                while (current->next)
                {
                    current = current->next;
                }
                current->next = novo;
            }
            size++;
        }

        void removeFront(){
            if (head){
                head = head->next;
                size--;
            }
        }
        
        void removeBack(){
            if (head){
                if (!head->next){
                    delete head;
                    head = nullptr;
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
            }
            size--;
        }

        T get(const int index){
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of bounds");
            }   
 
            Node* current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }

            return current->data;
            
        }

        bool isEmpty(){
            return size == 0;
        }

        int lenght(){
            return size;
        }
        
        T* toArray(){
            T* list = static_cast<T*>(malloc(size * sizeof(T)));

            Node* temp = head;
            for (int i = 0; i < size; i++)
            {
                list[i] = temp->data;
                temp = temp->next;
            }
            
            return list;
        }

        void clear(){

            Node* current = head;
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            size = 0;
            head = nullptr;
        }

        void forEach(void (*func)(T)){
            Node* temp = head;
            while (temp->next)
            {
                func(temp->data);
                temp = temp->next;
            }
            func(temp->data);
        }

        void print(){
            Node* temp = head;
            while(temp){
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
        }

};

int main(){
    LinkedList<int> link;
    link.addToFront(2);
    link.addToFront(3);
    link.addToFront(4);

    link.forEach([](int elemento) {
        std::cout << "Elemento: " << elemento << std::endl;
    });
    return 0;
}
