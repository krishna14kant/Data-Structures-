#include <iostream>
using namespace std;
#define max 99

int stack[100],top = -1;

void push(int value){
    if(top >= max){
        cout << "Stack Overflow" << endl;
    }
    else{
        top++;
        stack[top] = value;
    }
}

void pop(){
    if(top <= -1){
        cout << "Stack Underflow" << endl;
    }
    else{
        cout << "The popped element is: " << stack[top] << endl;
        top--;
    }
}

void peek(){
    if(top>=0 && top<=max){
        cout << "The peek element is: " << stack[top] << endl;
    }
    else if(top>max){
        cout << "Stack Overflow" << endl;
    }
    else{
        cout << "Stack Underflow" << endl;
    }
}

void display(){
    if(top >= 0){
        cout << "Stack elements are:" << endl;
        for(int i{top}; i>=0; --i){
            cout << stack[i] << endl;
        }
    }
    else{
        cout << "Stack is empty" << endl;
    }
}
int main(){
    int choice,value;
    cout << "1. Push operation" << endl;
    cout << "2. Pop operation" << endl;
    cout << "3. Peek operation" << endl;
    cout << "4. Display stack" << endl;
    cout << "5. Exit" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter value to be pushed: ";
                cin >> value;
                push(value);
                cout << value << " pushed" << endl;
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exited" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid Choice" << endl;
        }
    }while (choice != 5);
    return 0;
}
