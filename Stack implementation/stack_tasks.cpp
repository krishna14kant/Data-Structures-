//--- SarmadFromPakistan

#include<iostream>
#include "custom_stack.h"
#include<string>
#include<sstream>

using namespace std;

class StringFunctions{
	
public :
	
	string reverse(string a) {
		c_Stack stack(a.length());

		int i = 0;
		while (a[i])
			stack.push(a[i++]);

		int index = 0;
		while (!stack.isEmpty())
			a[index++] = stack.pop();

		return a;
	}


	bool palindrom(string a) {
		c_Stack stack(a.length());

		int i = 0;
		while (a[i])
			stack.push(a[i++]);

		bool palindrom = true;
		i = 0;
		while (!stack.isEmpty()) {
			if (a[i] != stack.pop()) {
				palindrom = false;
				return palindrom;
			}
			i++;
		}
		return palindrom;
	}


	bool parenthesisMatching(string a) {
		c_Stack stack(a.length());

		bool balanced = true;
		int i = 0;
		while (a[i]) {
			if (a[i] == '[' || a[i] == '{' || a[i] == '(')
				stack.push(a[i]);
			else if (a[i] == ']' || a[i] == '}' || a[i] == ')') {
				if (stack.isEmpty()) {
					balanced = false;
					return balanced;
				}
				char pop = stack.pop();
				if ((a[i] == ']' && pop != '[') || (a[i] == '}' && pop != '{') || (a[i] == ')' && pop != '(')) {
					balanced = false;
					return balanced;
				}
			}
			i++;
		}
		if (!stack.isEmpty()) {
			balanced = false;
			return balanced;
		}
		return balanced;
	}

private:
	
	int precedence(char a) {
		if (a == '+' || a == '-') return 1;
		else if (a == '*' || a == '/') return 2;
	}

public:
	
	string postfix(string a) {
		c_Stack stack(a.length());

		int i = 0;
		string postfix = "";
		while (a[i]) {
			if (a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/')
				postfix += a[i++];
			else {
				if (stack.isEmpty())
					stack.push(a[i++]);
				else if (precedence(stack.toper()) >= a[i])
					postfix += stack.pop();
				else
					stack.push(a[i++]);
			}
		}
		while (!stack.isEmpty())
			postfix += stack.pop();

		return postfix;
	}


	int EvalPostfix(string a) {
		i_Stack stack(a.length());

		int i = 0;
		while (a[i]) {
			if ((a[i]>='a' && a[i]<='z') || (a[i] >= 'A' && a[i] <= 'Z')) {
				int var = 0;
				cout << "Give Value To '" << a[i] << "' :";
				cin >> var;
				stack.push(var);
			}
			else if (a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/')
				stack.push(a[i] - '0');
			else {
				int x = stack.pop();
				int y = stack.pop();

				if (a[i] == '+') stack.push(y + x);
				else if (a[i] == '-') stack.push(y - x);
				else if (a[i] == '*') stack.push(y * x);
				else if (a[i] == '/') stack.push(y / x);
			}
			i++;
		}
		return stack.pop();
	}


	string postfix_to_infix(string a) {
		s_Stack stack;
		string infix = "";
		int i = 0;
		while (a[i]) {
			if (a[i] != '+' && a[i] != '-' && a[i] != '*' && a[i] != '/') {
				stringstream ss;
				ss << a[i];
				string g = ss.str();
				stack.push(g);
			}	
			else {
				string x = stack.pop();
				string y = stack.pop();

				if (a[i] == '+') stack.push(y + " + " + x);
				else if (a[i] == '-') stack.push(y + " - " + x);
				else if (a[i] == '*') stack.push(y + " * " + x);
				else if (a[i] == '/') stack.push(y + " / " + x);
			}
			i++;
		}
		return stack.pop();
	}
};



int main() {
	string text;
	StringFunctions SF;
	int opt;
	do{
		cout<<"\n Enter 1 to Reverse ";
		cout<<"\n Enter 2 to check Palindrome ";
		cout<<"\n Enter 3 to check Parenthesis Matching ";
		cout<<"\n Enter 4 to convert Infix to Postfix";
		cout<<"\n Enter 5 to Evaluate postfix";
		cout<<"\n Enter 6 to convert postfix to infix";
		cout<<"\n Enter 0 to Exit";
		cout<<"\n Enter your option: "; cin>>opt;
		
		
	switch(opt)
	{
		case 0: break;
		case 1: {
			cout <<"\n Enter String : ";
			cin>>text;
			string x = SF.reverse(text);
			cout <<x<<"\n\n";
			break;
		}
		case 2: {
			cout <<"\n Enter String : ";
			cin>>text;
			bool x = SF.palindrom(text);
			if(x) cout<<"\n Yes! it is Palindrome"<<"\n\n";
			else cout<<"\n No! it is not Palindrome"<<"\n\n";
			break;
		}
		case 3:{
			cout <<"\n Enter String : ";
			cin>>text;
			bool x = SF.parenthesisMatching(text);
			if(x) cout<<"\n Yes! Balanced"<<"\n\n";
			else cout<<"\n Not Balanced"<<"\n\n";
			break;
		}
		case 4: {
			cout <<"\n Enter String : ";
			cin>>text;
			string x = SF.postfix(text);
			cout <<x<<"\n\n";
			break;
		}	
		case 5: {
			cout <<"\n Enter String : ";
			cin>>text;
			int x = (int)SF.EvalPostfix(text);
			cout<<x<<"\n\n";
			break;
		}
		case 6:{
			cout <<"\n Enter String : ";
			cin>>text;
			string x = SF.postfix_to_infix(text);
			cout <<x<<"\n\n";
			break;
		}
		default:
			cout<<"\n Wrong option";
		}	
	}while(opt!=0);
	
}
