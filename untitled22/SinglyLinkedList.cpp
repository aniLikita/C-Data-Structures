//
// Created by HP on 2/16/2025.
//


#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class SinglyLinkedList{
    Node* head;
    int size;

public:
    SinglyLinkedList(){
        head = nullptr;
        size = 0;
    }
    bool isEmpty(){
        return head == nullptr;
    };
    void add(const int val){
        Node* node = new Node();
        if(!isEmpty()){
            node->next = nullptr;
            head = node;
        }
        else{
            node->next = head->next;
            head = node;
        }
        size++;
    }
    void remove(){
        Node* temp = head;
        head = temp->next;
        size--;
        delete temp;
    }
    int front(){
        return head->value;
    }
};