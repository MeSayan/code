#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

bool isOperator(char c) {
	return (!isalpha(c) && !isdigit(c));
}


int getPriority(char C) {
	if( C == '-' || C == '+') return 1;
	else if ( C == '*' || C == '/') return 2;
	else if ( C == '^') return 3;
	return 0;
}

std::string infixToPostfix(std::string infix) {
	infix = '(' + infix + ')';
	int l = infix.size();
	std::stack<char> char_stack;
	std::string output;
	
	for( int i = 0 ; i < l; i++) {
		
		if( isalpha(infix[i]) || isdigit(infix[i]) )
			output += infix[i];
		
		else if ( infix[i] == '(') 
			char_stack.push('(');
		
		else if ( infix[i] == ')') {
			
			while( char_stack.top() != '(') {
				output += char_stack.top();
				char_stack.pop();
			}
			char_stack.pop(); // Remove '(' from the stack
		}
		
		else {
			// Operator
			if ( isOperator(char_stack.top()) ) { 
				while( getPriority(infix[i]) 
					   <= getPriority(char_stack.top()) ) {
				output += char_stack.top();
				char_stack.pop();
				}	
			// Push current Operator on stack
				char_stack.push(infix[i]);
			}
		}
	}
	return output;
}

std::string infixToPrefix(std::string infix) {
	/*
	 * Reverse String
	 * Replace ( with ) and vice versa
	 * Get Postfix
	 * Reverse Postfix
	 * 
	*/
	int l = infix.size();
	
	// Reverse infix 
	reverse(infix.begin(),infix.end());
	// Replace ( with ) and vice versa
	for (int  i = 0; i < l; i++) {
		
		if ( infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if ( infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}
	
	std::string prefix = infixToPostfix(infix);
	//Reverse postfix
	reverse(prefix.begin(), prefix.end());
	return prefix;
}
	

int main() {
	std::string s = ("(a-b/c)*(a/k-l)");
	std::cout << infixToPrefix(s) << std::endl;
	return 0;
}

