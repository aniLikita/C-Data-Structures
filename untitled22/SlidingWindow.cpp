#include<iostream>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int value;

};

class SlidingWindow{
    Node* head;
    Node* trailer;
    int capacity;
    int size;
public:
    SlidingWindow(int c){
        head = nullptr;
        trailer = nullptr;
        capacity = c;
        size = 0;
    }
    bool isEmpty(){
        return head == nullptr;
    }
    void Add(const int val){
        Node* node = new Node();
        node->value = val;
        node->next = nullptr;
        node->prev = nullptr;
        if (!isEmpty()){
            if(size == capacity){
                Node* temp = head;
                head = temp->next;
                head->prev = nullptr;
                delete temp;
            }
            trailer->next = node;
            node->prev = trailer;
        }
        else{
            head = node;
            trailer = node;
        }
        trailer = node;
        size++;

    }
    void Remove(int pos){
        Node* current = head;
        for (int i = 1; i < pos; i++) {
            current = current->next;
        }
        if (current->prev != nullptr){
            current->prev->next = current->next;
        }else{
            head = current->next;
        }

        if (current->next != nullptr){
            current->prev->next = current->next;
        }else{
            trailer = current->prev;
        }

        delete current;
        size--;
    }

    void display(){
        Node* current = head;
        while(current != nullptr){
            cout<<current->value<<endl;
            current = current->next;
        }
    }
};

int main(){
    SlidingWindow s(10);
    s.isEmpty();
    s.Add(1);
    s.Add(2);
    s.Add(3);
    s.Add(9);
    s.Add(7);
    s.Add(0);
    s.display();
    s.isEmpty();

    s.Remove(2);
    s.display();

};



