#include <iostream>

class Stack {
public:
    char charStack[100];
    int top;
    void init() {
        top = -1;
    }
    bool isStackEmpty() {
        bool answer = false;
        if (top == -1) {
            answer = true;
        }
        return answer;
    }
    void push(char c) {
        top++;
        charStack[top] = c;
    }
    void pushString(const std::string &word) {
        for (int i = 0; i < word.length(); i++) {
                push(word[i]);
        }
    }
    std::string stringPop() {

    }

    char pop() {
        char c = charStack[top];
        top--;
        return c;
    }
    void showStack() {
        if(!isStackEmpty()) {
            for (int i = 0; i <= top; i++) {
                std::cout << charStack[i] << " ";
            }
        }
        else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }

    void testCase(std::string testString) {
    Stack stack; char c;
        stack.init();
            for (int i = 0; i < testString.length(); i++) {
                c = testString[i];
                stack.push(c);
            }
        stack.showStack();
        while (!stack.isStackEmpty()){
            std::cout << stack.pop() << " ";
        }
    }
};

int main() {
    malloc(20);
    std::cout << "Start" << std::endl;
    Stack stack;
    stack.init();
    std::cout << "2" << std::endl;
    std::cout << std::endl;
    stack.pushString("bob");
    stack.showStack();
    stack.pop
    stack.pushString("aet normel");
    stack.showStack();
    std::cout << std::endl;
    std::cout << std::endl;
    stack.pushString("snoino dna revil etah");
    stack.showStack();
    std::cout << std::endl;
    std::cout << std::endl;
    stack.pushString("SELUR LOBOC");

    stack.showStack();
    return 0;
}