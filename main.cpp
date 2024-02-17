#include <iostream>
#include <fstream>
#include <cctype> //isdigit
#include <algorithm>

class Stack {
public:
    int top;
    int intStack[50];

    void init() {
        top = -1;
    }

    bool isStackEmpty() {
        return top == -1; //returns t/f
    }

    void push(int value) {
        if (top < (50 - 1)) { //overflow protection
            intStack[++top] = value;
        } else {
            std::cerr << "overflow" << std::endl;
        }
    }

    void pushString(const std::string &word) {
        for (char ch : word) {
            push(ch);
        }
    }

    void popString(const std::string &stringToPop) {
        std::string poppedString;
        bool isMismatch = false;

        for(int i = stringToPop.length() - 1; i >= 0; i--) {
            if(isStackEmpty()) {
                isMismatch = true;
                break;
            }

            if (intStack[top] != stringToPop[i]) {
                    isMismatch = true;
                    break;
            }
            poppedString += pop();

        }
        //reverse and printout
        if (!isMismatch && poppedString.length() == stringToPop.length()) {
            std::reverse(poppedString.begin(), poppedString.end());
            std::cout << "String popped: " << poppedString << std::endl;
        } else {
            std::cout << "Mismatch or error in popping the string." << std::endl;
        }
    }

    int pop() {
        if (!isStackEmpty()) {
            return intStack[top--];
        } else {
            return -1; // error
        }
    }

    int peek() {
        if (!isStackEmpty()) {
            return intStack[top];
        } else {
            std::cerr << "empty" << std::endl;
            return -1;
        }
    }

    void showStack() {
        if(!isStackEmpty()) {
            for (int i = top; i >= 0; i--) {
                std::cout << intStack[i] << " ";
            }
        }
        else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }



    bool validateParenthesisAndBalance(const std::string &input) {
        init();
        for (char ch : input) {
            if (ch == '(') {
                push(0); // using 0 as a placeholder i dont know how else to do it
            } else if (ch == ')') {
                if (isStackEmpty() || peek() != 0) { // check for placeholder
                    return false;
                }
                pop();
            }
        }
        return isStackEmpty(); // unmatch check
    }

    int evaluatePostfix(const std::string &postfix) {
        Stack operandStack;
        operandStack.init();

        std::string numberBuffer;

        for (char ch : postfix) {
            if (isdigit(ch)) {
                numberBuffer += ch;
            } else if (ch == ' ') {
                if (!numberBuffer.empty()) {

                    operandStack.push(std::stoi(numberBuffer));
                    numberBuffer.clear();
                }
            } else if (isOperator(ch)) {
                int val2 = operandStack.pop();
                int val1 = operandStack.pop();
                switch (ch) {
                    case '+': operandStack.push(val1 + val2); break;
                    case '-': operandStack.push(val1 - val2); break;
                    case '*': operandStack.push(val1 * val2); break;
                    case '/': operandStack.push(val1 / val2); break;
                }
            }
        }

        return operandStack.pop(); // should be remaining number if not then i dont know what went wrong
    }


    std::string infixToPostfix(const std::string &infix) {
        Stack operatorStack;
        operatorStack.init();
        std::string postfix;
        std::string numberBuffer;

        for (char ch : infix) {
            if (isdigit(ch)) {
                numberBuffer += ch;
            } else {
                if (!numberBuffer.empty()) {
                    postfix += numberBuffer + " ";
                    numberBuffer.clear();
                }
                if (ch == '(') {
                    operatorStack.push(ch);
                } else if (ch == ')') {
                    while (!operatorStack.isStackEmpty() && operatorStack.peek() != '(') {
                        postfix += operatorStack.pop();
                        postfix += " ";
                    }
                    operatorStack.pop(); // remove '('
                } else if (isOperator(ch)) {
                    while (!operatorStack.isStackEmpty() && precedence(operatorStack.peek()) >= precedence(ch) && operatorStack.peek() != '(') {
                        postfix += operatorStack.pop();
                        postfix += " ";
                    }
                    operatorStack.push(ch);
                }
            }
        }

        // append remaining
        if (!numberBuffer.empty()) {
            postfix += numberBuffer + " ";
        }

        // aop remaining
        while (!operatorStack.isStackEmpty()) {
            postfix += operatorStack.pop();
            postfix += " ";
        }

        return postfix;
    }

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }


};

    int main() {
        Stack stack;
        std::string currentLine;

        std::ifstream inputFile(R"(C:\Users\taxy\CLionProjects\postfix and infix\input.txt)");
        if (!inputFile.is_open()) {
            std::cerr << "Could not open the file." << std::endl << std::endl;
            return 1;
    }
        int count = 1;
        while (std::getline(inputFile, currentLine)) {

            std::cout << "Line " << count++ << ":" << std::endl;

            // validation
            if (stack.validateParenthesisAndBalance(currentLine)) {
            std::cout << "Parentheses are balanced." << std::endl;

            // infix to postfix
            std::string postfix = stack.infixToPostfix(currentLine);
            std::cout << "Infix to postfix: " << postfix << std::endl;

            // postfix eval
                int result = stack.evaluatePostfix(postfix);
                std::cout << "Postfix evaluation result: " << result << std::endl << std::endl;
            } else {
            std::cout << "Parentheses are not balanced." << std::endl << std::endl;
        }
    }
        return 0;
}


