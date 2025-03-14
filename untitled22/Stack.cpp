//
// Created by HP on 2/17/2025.
//
#include <iostream>
using namespace std;

template <typename E>

class ArrayStack{
    E* stack;
    int topIndex;
    int capacity;
public:
    ArrayStack(int s){
        stack = new E[s];
        capacity = s;
        topIndex = -1;
    }
    bool isEmpty(){
        return topIndex == -1;
    }
    bool isFull(){
        return topIndex+1 == capacity;
    }
    void push(const E& newVal){
        if(isFull()){
            cout<<"Max capacity reached!"<<endl;
        }
        else{
            topIndex++;
            stack[topIndex] = newVal;
        }
    }
    void pop(){
        if (!isEmpty()){
            top();
            topIndex--;
        }
        else{
            cout<<"Error"<<endl;
        }
    }
    void top(){
        cout<<stack[topIndex]<<endl;
    }
};

int main(){
    ArrayStack<int> stack(10);
    stack.push(2);
    stack.push(10);
    stack.push(3);
    stack.pop();
    stack.top();

}