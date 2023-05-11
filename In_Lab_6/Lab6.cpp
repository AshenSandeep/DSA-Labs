#include<iostream>
#include<ctime>
#include<chrono>
using namespace std;
class StackArray{
    private:
    int size;
    int* stack;
    int top;

    public:
    StackArray(int size){
        top=-1;
        this->size = size;
        stack = new int(size);
    }
    ~ StackArray()
    {
        delete[] stack;
    }

    void push(int data);
    int pop();
    bool IsEmpty();
    bool IsFull();
    void Display();
};

bool StackArray::IsFull(){
    if(top == size-1){
        return true;
    }else{
        return false;
    }
}
bool StackArray::IsEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

void StackArray::push(int data)
{
    if(IsFull())
    {
        cout<<"Stack overflow"<<endl;
        return;
    }
    else
    {
        top++;
        stack[top] = data;
    }
}

int StackArray::pop()
{
    if(IsEmpty())
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    else
    {
        int pop_data = stack[top];
        top--;
        return pop_data;
    }
}
void StackArray::Display()
{
    for(int i = top; i>-1; i--)
    {
        cout<<stack[i]<<endl;
    }
}
