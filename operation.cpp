#include<iostream>
#include<string>
#include<regex>
#include<cmath>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    
    return a;
}
int add(int a, int b, int c, int d) {
    int up = 0, down = 0;
    if (b == d) {
        up = a + c;
        down = b;
    } else {
        up = a * d + b * c;
        down = b * d;
    }
    int commonGCD = gcd(up, down);
    up /= commonGCD;
    down /= commonGCD;
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
    int commonGCD = gcd(up, down);
    up /= commonGCD;
    down /= commonGCD;
    cout << up << '/' << down;
    return 1;
}

int multiply(int a, int b, int c, int d) {
    int up = 0, down = 0;
    up = a * c;
    down = b * d;
    int commonGCD = gcd(up, down);
    up /= commonGCD;
    down /= commonGCD;
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
    int commonGCD = gcd(up, down);
    up /= commonGCD;
    down /= commonGCD;
    cout << up << '/' << down;
    return 1;
}

int main(){
    char operation;
    int num1, den1, num2, den2;
    string input;
    cout << "Enter operation in the format 'num1/den1 operation num2/den2': ";
    getline(cin, input);
    regex pattern("([+-]?\\d+)/(\\d+) ([+\\-*/]) ([+-]?\\d+)/(\\d+)");
    regex pattern2("([+-]?\\d+) ([+\\-*/]) ([+-]?\\d+)/(\\d+)");
    regex pattern3("([+-]?\\d+)/(\\d+) ([+\\-*/]) ([+-]?\\d+)");
    regex pattern4("([+-]?\\d+) ([+\\-*/]) ([+-]?\\d+)");
    smatch matches;
    if(regex_match(input, matches, pattern)){
        num1 = stoi(matches[1]);
        den1 = stoi(matches[2]);
        operation = matches[3].str()[0];
        num2 = stoi(matches[4]);
        den2 = stoi(matches[5]);
        
        cout << "Valid input." << endl;
    }
    else if(regex_match(input, matches, pattern2)){
        num1 = stoi(matches[1]);
        den1 = 1;
        operation = matches[3].str()[0];
        num2 = stoi(matches[4]);
        den2 = stoi(matches[5]);
        
        cout << "Valid input." << endl;
    }
    else if(regex_match(input, matches, pattern3)){
        num1 = stoi(matches[1]);
        den1 = stoi(matches[2]);
        operation = matches[3].str()[0];
        num2 = stoi(matches[4]);
        den2 =1;
        
        cout << "Valid input." << endl;
    }
    else if(regex_match(input, matches, pattern4)){
        num1 = stoi(matches[1]);
        den1 = 1;
        operation = matches[3].str()[0];
        num2 = stoi(matches[4]);
        den2 = 1;
        
        cout << "Valid input." << endl;
    }
    else {
        cout << "Invalid input!";
    }
    cout << "Result: ";
    switch (operation) {
        case '+':
            add(num1, den1, num2, den2);
            break;
        case '-':
            subtract(num1, den1, num2, den2);
            break;
        case '*':
            multiply(num1, den1, num2, den2);
            break;
        case '/':
            divide(num1, den1, num2, den2);
            break;
        default:
            cout << "Invalid operation!";
        }
    
    return 0;
}
