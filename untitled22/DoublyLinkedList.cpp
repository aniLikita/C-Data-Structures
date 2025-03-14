//
// Created by HP on 2/16/2025.
//
#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
    Node* prev;
};

class DoubleLinkedList{
    Node* header;
    Node* trailer;
    int size;
public:
    DoubleLinkedList(){
        header = nullptr;
        trailer = nullptr;
        size = 0;
    }
    bool isEmpty(){
        return header == nullptr;
    }
    void addFront(const int n){
        Node* node = new Node();
        node->value = n;
        node->prev = header;
        if (header!=nullptr){
            node->next = header;
            header->prev = node;
            header = node;
            node->prev = nullptr;
        }
        else {
            node->next = nullptr;
            header = node;
            trailer = node;
        }
        size++;
    }
    void addBack(const int n){
        Node* node = new Node();
        node->value = n;
        if(trailer!=nullptr){
            node->next = trailer->next;
            node->prev = trailer;
            trailer = node;
        }else{
            node->next = nullptr;
            trailer = node;
        }
        size++;
    };
    void removeFront(){
        if(!isEmpty()){
            Node* temp = header;
            header = temp->next;
            header->prev = nullptr;
            delete temp;
            size--;
        }
        else{
            cout<<"List is Empty"<<endl;
        }
    }
    void removeBack(){
        if(!isEmpty()){
            Node* temp = trailer;
            trailer = temp->prev;
            trailer->next = nullptr;
            delete temp;
            size--;
        }
        else{
            cout<<"List is Empty"<<endl;
        }
    };
    int back(){
        return trailer->value;
    }
    int front(){
        return header->value;
    }

};