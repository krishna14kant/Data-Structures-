#include <bits/stdc++.h> 
using namespace std; 
  
bool isOperand(char x){ 
   return((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')); 
} 
  
string postfixToInfix(string postfix_exp){ 
    stack<string> s; 
  
    for(int i=0; postfix_exp[i]!='\0'; i++){ 

        if(isOperand(postfix_exp[i])){ 
           string op(1, postfix_exp[i]); 
           s.push(op); 
        } 
  
        else{ 
            string op1 = s.top(); 
            s.pop(); 
            string op2 = s.top(); 
            s.pop(); 
            s.push("(" + op2 + postfix_exp[i] + op1 + ")"); 
        } 
    } 
    return s.top(); 
} 
int main(){
  //taking ABC/-AD/E- for example
    string postfix_exp = "ABC/-AD/E-*"; 
    cout<<"Infix : "<<postfixToInfix(postfix_exp); 
    return 0; 
}
