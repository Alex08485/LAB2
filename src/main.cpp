#include <iostream>
#include "rpn.h"
#include <stdexcept>

using namespace std;

int main () {
    string expression;
    cout << "Enter RPN expression";
    getline(cin,expression);

    try {
        double result = evaluate_rpn(expression);
        cout << "Result: " << result << endl;
    
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;

    
}
    