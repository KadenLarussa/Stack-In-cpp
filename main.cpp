#include <algorithm> //for string reversal
#include <iostream>

class Stack {
public:
    int top;
    char charStack[50];

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
            char ch = peek();

            if (charStack[top] != stringToPop[i]) {
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

    char pop() {
        if(!isStackEmpty()){
            char c = charStack[top];
            top--;
            return c;
        } else {
            std::cout << "Empty";
        }
    }

    char peek() {
    return charStack[top];
    }

    void showStack() {
        if(!isStackEmpty()) {
            for (int i = top; i >= 0; i--) {
                std::cout << charStack[i] << " ";
            }
        }
        else {
            std::cout << "Stack is empty!" << std::endl;
        }
    }
    //testcase for debugging purposes
    /*
    static void testCase(std::string testString) {
        Stack stack;
        char c;

        stack.pushString(testString);

        while (!stack.isStackEmpty()){
            std::cout << stack.pop() << " ";
        }
        std::cout << std::endl;
    }
    */

};

int main() {
    Stack stack{};
    stack.init();

    std::string strings[] = {"bob", "aet nomel", "snoino dna revil etah I", "SELUR LOBOC"};

    for (const std::string &str : strings) {
        std::cout << "Pushing string: " << str << std::endl;
        stack.pushString(str);
        std::cout << "Current stack printout: ";
        stack.showStack();
        std::cout << std::endl;
        std::cout << "Popping string: ";
        stack.popString(str);
        std::cout << "Current stack printout: ";
        stack.showStack();
        std::cout << std::endl;
    }

    return 0;
}
