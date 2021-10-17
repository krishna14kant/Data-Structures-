#pragma once
#include<string>

using namespace std;

class i_Stack {
	private:
		int *array;
		int top;
	
	public:
		i_Stack(int size) {
			this->top = -1;
			array = new int(size);
		}
		void push(int num) {
			array[++top] = num;
		}
		int pop() {
			if (!isEmpty()) {
				int num = array[top];
				top--;
				return num;
			}
			return -1;
		}
		bool isEmpty() {
			if (this->top == -1) return true;
			return false;
		}
		int topper() {
			return this->array[this->top];
		}
};

class c_Stack {
	private:
		char *array;
		int top;

	public:
		c_Stack(int size) {
			this->top = -1;
			array = new char(size);
		}
		void push(char chr) {
			array[++top] = chr;
		}
		char pop() {
			if (!isEmpty()) {
				char chr = array[top];
				top--;
				return chr;
			}
			return -1;
		}
		bool isEmpty() {
			if (this->top == -1) return true;
			return false;
		}
		char toper() {
			return this->array[this->top];
		}
};


struct node {
public :
	string String;
	struct node* next = NULL;
};

class s_Stack{
private:
	struct node* first ;
	struct node* last ;

public:
	s_Stack() {
		first = NULL;
		last = NULL;
	}
	void push(string str) {
		struct node* current = new struct node();
		current->String = str ;
		if (!first) {
			first = last = current;
		}
		else {
			last->next = current;
			last = current;
		}
	}
	string pop() {
		if (!isEmpty()) {
			struct node* current = first;
			while (current->next != NULL && current->next != last )
					current = current->next;
			
			string str = last->String;
			delete last;
			last = current;
			last->next = NULL;
			return str;
		}
		return NULL;
	}
	bool isEmpty() {
		if (!first) return true;
		return false;
	}
	string toper() {
		return last->String;
	}
};
