#include <iostream>

using namespace std;

struct Node{
    string song;
    Node* next;
};

class Playlist{
    Node* cursor;
    int size;

public:
    Playlist(){
        size = 0;
        cursor = NULL;
    }
    bool isEmpty(){
        return cursor == NULL;
    }
    void addSong(const string& s){
        Node* node = new Node();
        node->song = s;
        if(isEmpty()){
            node->next = node;
            cursor = node;
        }
        else{
            node->next = cursor->next;
            cursor->next = node;
        }
    }
    string front(){
        return cursor->song;
    }
    string back(){
        return cursor->next->song;
    }
    void remove(){
        if (!isEmpty()){
            Node* temp = cursor->next;
            cursor->next = temp->next;
            delete temp;
        }
    }
    void advance(){
        if (!isEmpty()){
            cursor = cursor->next;
        }
        else{
            return;
        }
    }

};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
