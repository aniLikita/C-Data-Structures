//
// Created by HP on 2/17/2025.
//
#include <iostream>

using namespace std;

template<typename E>
class Deque{
private:
    E* queue;
    int topIndex;
    int size;
    int capacity;
public:
    Deque(int const c){
        capacity = c;
        queue = new E[c];
        size = 0;
    }

    bool isEmpty(){
        return size = 0;
    }
    int _size(){
        return size;
    }
    void insertFront(const int newVal){
        if(size != capacity){
            for (int i = size; i > 0; i--) {
                if (size == 0) break;
                queue[i] = queue[i-1];
            }
            queue[0] = newVal;
            topIndex++;
        }
        else{
            cout<<"Deque is full"<<endl;
        }
    }
    void insertBack(const int newVal){

    }
};