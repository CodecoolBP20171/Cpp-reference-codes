// StackDojo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.hpp"

int main()
{
    Stack stack(3);

    try {
        cout << "peek: " << stack.peek() << endl;
    }
    catch (StackEmptyException& e) {
        cout << "Received exception: " << e.what() << endl;
    }

    stack.push(0);
    stack.push(1);
    stack.push(2);

    try {
        stack.push(3);
    }
    catch (StackOverflowException& e) {
        cout << "Received exception: " << e.what() << endl;
    }

    cout << "peek: " << stack.peek() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    try {
        cout << stack.pop() << endl;
    }
    catch (StackUnderflowException& e) {
        cout << "Received exception: " << e.what() << endl;
    }

    cout << "size: " << stack.size() << endl;

    int a;
    cin >> a;

    return 0;
}

