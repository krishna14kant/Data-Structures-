// Take a Stack as an input and check if the input stack is Overflow or Underflow (i.e. Empty or Full) by using BOOL function and return the result.
// Also, write a function to display the elements of the stack.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 10

class Stack
{
    int top;
    int arr[MAX];
    
public:
    Stack()
    {
        top = -1;
    }
    
    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }
    
    bool isFull()
    {
        if(top == MAX-1)
            return true;
        else
            return false;
    }
    
    void push(int x)
    {
        if(isFull())
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            arr[top] = x;
        }
    }
    
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            top--;
            return popValue;
        }
    }

    int getTop()
    {
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
            return arr[top];
    }
    
    void display()
    {
        if(isEmpty())
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "Stack elements are: ";
            for(int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, item;
    bool flag = true;
    
    while(flag)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Get Top" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "Enter the element to be pushed: ";
                cin >> item;
                s.push(item);
                break;
                
            case 2:
                cout << "Popped element is: " << s.pop() << endl;
                break;
                
            case 3:
                s.display();
                break;
            
            case 4:
                cout << "Top element is: " << s.getTop() << endl;
                break;
                
            case 5:
                flag = false;
                break;
            
            default:
                cout << "Invalid choice" << endl;
        }
    }
    
    return 0;
}