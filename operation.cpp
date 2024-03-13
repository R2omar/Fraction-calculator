#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int add(int a, int b, int c, int d) {
    int up = 0, down = 0;
    if (b == d) {
        up = a + c;
        down = b;
    } else {
        up = a * d + b * c;
        down = b * d;
    }
    cout << up << '/' << down;
    return 1;
}

int subtract(int a, int b, int c, int d) {
    int up = 0, down = 0;
    if (b == d) {
        up = a - c;
        down = b;
    } else {
        up = a * d - b * c;
        down = b * d;
    }
    cout << up << '/' << down;
    return 1;
}

int multiply(int a, int b, int c, int d) {
    int up = 0, down = 0;
    up = a * c;
    down = b * d;
    cout << up << '/' << down;
    return 1;
}

int divide(int a, int b, int c, int d) {
    if (c == 0) {
        cout << "Error: Division by zero!";
        return 0;
    }
    int up = 0, down = 0;
    up = a * d;
    down = b * c;
    cout << up << '/' << down;
    return 1;
}

int main() {
    char operation;
    int a, b, c, d;
    cin >> operation >> a >> b >> c >> d;
    switch (operation) {
        case '+':
            cout << "Result: ";
            add(a, b, c, d);
            break;
        case '-':
            cout << "Result: ";
            subtract(a, b, c, d);
            break;
        case '*':
            cout << "Result: ";
            multiply(a, b, c, d);
            break;
        case '/':
            cout << "Result: ";
            divide(a, b, c, d);
            break;
        default:
            cout << "Invalid operation!";
    }

    return 0;
}