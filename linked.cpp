// Online C++ compiler to run C++ program online
#include <iostream>
#include <memory>
#include <string> 
#include <chrono>


template <class T> struct Node {
  T data;
  std::shared_ptr<Node<T>> link = nullptr;
};

template <class T> struct LinkedList {
    private:
        std::shared_ptr<Node<T>> head;
        size_t counter;
        
        std::shared_ptr<Node<T>> getNode(int idx) const {
            if(idx < 0 || idx >= counter){
                throw std::out_of_range("Fuera de rango");
            }
            std::shared_ptr<Node<T>> aux = head;
            for(int i=0 ; i < idx; ++i){
                aux = aux->link;
            }
            return aux;
        }
    public:
        LinkedList(): head(nullptr), counter(0){}
        
        void add(const T& item){
            auto newNode = std::make_shared<Node<T>>();
            newNode->data = item;
            
            if(!head){
                head = newNode;
            }
            else{
                std::shared_ptr<Node<T>> aux = head;
                while(aux->link){
                    aux = aux->link;
                }
                aux->link = newNode;
            }
            this->counter++;
           
        }
        int size() {
            return this->counter;
        }
        bool remove(const T& item){
           if(!head){
               return false;
           }
           
           if(head->data == item){
               head = head->link;
               counter--;
               return true;
           }
           auto current = head;
           std::shared_ptr<Node<T>> prev = nullptr;
           
           while(current){
               if(current->data == item){
                   prev->link = current->link;
                   this->counter--;
                   return true;
               }
               prev = current;
               current = current->link;
           }
           
           return false; 
        }
        const T& operator[](int index) const {
            std::shared_ptr<Node<T>> node = getNode(index);
            return node->data;
        }
        
        T& operator[](int index){
            std::shared_ptr<Node<T>> node = getNode(index);
            return node->data;
        }
        
        friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list){
            os << "[ ";
            auto aux = list.head;
            for(int i = 0; i < list.counter; ++i){
                os << aux->data ;
                if(aux->link != nullptr){
                    os << ", ";
                    aux = aux->link;
                }
            }
            os << " ]";
            return os;
        }
};

int main() {
    // Write C++ code here
    auto start = std::chrono::high_resolution_clock::now();
    
    LinkedList<int> linked;
    
    for(int i = 0; i < 10; ++i){
        linked.add(i+1);
    }
    linked[6] = 20;
     std::cout << linked <<std::endl; 
     std::cout << linked[6] <<std::endl; 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << std::endl;
    
    return 0;
}
