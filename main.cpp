#include <iostream>

class Stack {
public:
    char s[20];
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
        s[top] = c;

    }
    char pop() {
        char c = s[top];
        top--;
        return c;
    }
    void showStack() {
        for (int i = 0; i <= top; i++) {
            std::cout << s[i] << " ";
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
Stack stack;
    stack.testCase("TestString");
}