//
// Created by HP on 2/17/2025.
//
#include<iostream>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
};

class SlidingWindow {
    Node* head;
    Node* trailer;
    int capacity;
    int size;

public:
    SlidingWindow(int c) {
        head = nullptr;
        trailer = nullptr;
        capacity = c;
        size = 0;
    }

    ~SlidingWindow() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void Add(const int val) {
        Node* node = new Node();
        node->value = val;
        node->next = nullptr;
        node->prev = nullptr;

        if (isEmpty()) {
            head = node;
            trailer = node;
        } else {
            if (size == capacity) {
                Node* temp = head;
                head = temp->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    trailer = nullptr; // If head becomes nullptr, trailer should also be nullptr
                }
                delete temp;
                size--;
            }
            trailer->next = node;
            node->prev = trailer;
            trailer = node;
        }
        size++;
    }

    void Remove(int pos) {
        if (pos < 1 || pos > size) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* current = head;
        for (int i = 1; i < pos; ++i) {
            current = current->next;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            trailer = current->prev;
        }

        delete current;
        size--;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << endl;
            current = current->next;
        }
    }
};

int main() {
    SlidingWindow s(10);
    s.Add(1);
    s.Add(2);
    s.Add(3);
    s.display();

    s.Remove(2);
    s.display();

    return 0;
}