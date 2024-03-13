#include<iostream>
#include<string>
#include<cmath>
#include<regex>
using namespace std;
// Function to calculate greatest_common_divisor to simplify the result
int greatest_common_div(int num1, int num2) {
    while (num2 != 0) {
        int t = num2;
        num2 = num1 % num2;
        num1 = t;
    }
    return num1;
}

// Function to add two fractions
int add(int a, int b, int c, int d) {
    int numerator = 0, denominator = 0;
    if (b == d) {
        numerator = a + c;
        denominator = b;
    } else {
        numerator = a * d + b * c;
        denominator = b * d;
    }
    // Simplifying the result
    int gcd = greatest_common_div(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    // Handling special cases where the denominator is 1
    if (denominator == 1) {
        cout << numerator;
        return 1;
    }
    if(abs(numerator) > denominator){
        cout << numerator / denominator << " " << abs(numerator) % denominator << "/" << denominator;
        return 1;
    }
    cout << numerator << '/' << denominator;
    return 1;
}

// Function to subtract two fractions
int subtract(int a, int b, int c, int d) {
    int numerator = 0, denominator = 0;
    if (b == d) {
        numerator = a - c;
        denominator = b;
    } else {
        numerator = a * d - b * c;
        denominator = b * d;
    }
    // Simplifying the result
    int gcd = greatest_common_div(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    // Handling special cases where the denominator is 1
    if (denominator == 1) {
        cout << numerator;
        return 1;
    }
    if(abs(numerator) > denominator){
        cout << numerator / denominator << " " << abs(numerator) % denominator << "/" << denominator;
        return 1;
    }
    cout << numerator << '/' << denominator;
    return 1;
}

// Function to multiply two fractions
int multiply(int a, int b, int c, int d) {
    int numerator = a * c;
    int denominator = b * d;
    // Simplifying the result
    int gcd = greatest_common_div(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    // Handling special cases where the denominator is 1
    if (denominator == 1) {
        cout << numerator;
        return 1;
    }
    if(abs(numerator) > denominator){
        cout << numerator / denominator << " " << abs(numerator) % denominator << "/" << denominator;
        return 1;
    }
    cout << numerator << '/' << denominator;
    return 1;
}

// Function to divide two fractions
int divide(int a, int b, int c, int d) {
    int numerator = a * d;
    int denominator = b * c;
    // Simplifying the result
    int gcd = greatest_common_div(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    // Handling special cases where the denominator is 1
    if (denominator == 1) {
        cout << numerator;
        return 1;
    }
    if(abs(numerator) > denominator){
        cout << numerator / denominator << " " << abs(numerator) % denominator << "/" << denominator;
        return 1;
    }
    cout << numerator << '/' << denominator;
    return 1;
}

int main() {
    // Declaration of variables
    char operation;
    int num1, den1, num2, den2;
    string input;

    //make the user enter the operation in a specific format
    cout << "Enter operation in the format 'num1 operation num2': ";
    getline(cin, input);

    // Defining regular expression patterns to control the input
    regex pattern1("([+-]?\\d+)/(\\d+) ([+\\-*/]) ([+-]?\\d+)/(\\d+)");
    regex pattern2("([+-]?\\d+) ([+\\-*/]) ([+-]?\\d+)/(\\d+)");
    regex pattern3("([+-]?\\d+)/(\\d+) ([+\\-*/]) ([+-]?\\d+)");
    regex pattern4("([+-]?\\d+) ([+\\-*/]) ([+-]?\\d+)");
    smatch matches;

    // Loop to handle input validation
    while (true) {
            //Handling invalid pattern
        if (!regex_match(input, matches, pattern1) && !regex_match(input, matches, pattern2) &&
            !regex_match(input, matches, pattern3) && !regex_match(input, matches, pattern4)) {
            cin.clear();
            cout << "Invalid Input. Please enter your operation in this format 'num1 operation num2': ";
            getline(cin, input);
            continue;
        }
        else {
            // control the input based on the matched pattern
            if (regex_match(input, matches, pattern1)) {
                num1 = stoi(matches[1]);
                den1 = stoi(matches[2]);
                operation = matches[3].str()[0];
                num2 = stoi(matches[4]);
                den2 = stoi(matches[5]);
            }
            else if (regex_match(input, matches, pattern2)) {
                num1 = stoi(matches[1]);
                den1 = 1;
                operation = matches[2].str()[0];
                num2 = stoi(matches[3]);
                den2 = stoi(matches[4]);
            }
            else if (regex_match(input, matches, pattern3)) {
                num1 = stoi(matches[1]);
                den1 = stoi(matches[2]);
                operation = matches[3].str()[0];
                num2 = stoi(matches[4]);
                den2 = 1;
            }
            else if (regex_match(input, matches, pattern4)) {
                num1 = stoi(matches[1]);
                den1 = 1;
                operation = matches[2].str()[0];
                num2 = stoi(matches[3]);
                den2 = 1;
            }

            // Handling division by zero
            if (den1 == 0 || den2 == 0 || (operation == '/' && num2 == 0)) {
                cin.clear();
                cout << "Error: Division by zero!\nPlease enter your operation in this format 'num1 operation num2': ";
                getline(cin, input);
                continue;
            }
            //if it can exceed all of this break
            break;
        }
    }

    // Outputting the result of the operation
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
    }
    return 0;
}
