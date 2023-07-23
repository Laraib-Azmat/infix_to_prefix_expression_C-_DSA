#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;



bool isOperand(char c) {
    return (isalpha(c) || isdigit(c));
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void reverseExp(char str[]) {
  int count=0, i=0;

  while(str[i] != '\0'){
  	
  	count++;
  	
  	i++;
  }
  
 
  reverse(str, str + count);

  
   }


void infixToPrefix(char infix[], char prefix[]) {

	int k=0;
 	reverseExp(infix);
  
  while(infix[k]!='\0'){
  	
        if (infix[k] == '(') {
            infix[k] = ')';
        }
        else if (infix[k] == ')') {
            infix[k] = '(';
        }
  	
  	k++;
  }
	
    char stack[100];
    int top = -1, i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];
        if (isOperand(c)) {
            prefix[j] = c;
            j++;
        } 
		
			else if (isOperator(c)) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(c)) {
                prefix[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = c;
        } else if (c == '(') {
            top++;
            stack[top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                prefix[j] = stack[top];
                j++;
                top--;
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            } else {
                cout << "Invalid expression: Unmatched ')'" << endl;
                return;
            }
        }
        i++;
    }

    while (top >= 0) {
        if (stack[top] == '(') {
            cout << "Invalid expression: Unmatched '('" << endl;
            return;
        }
        prefix[j] = stack[top];
        j++;
        top--;
    }

    prefix[j] = '\0';
    reverseExp(prefix);
}

int main() {
    char infix	[100];
    char prefix[100];

    cout << "Enter an infix expression: ";
    cin.getline(infix, 100);

    infixToPrefix(infix, prefix);

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}