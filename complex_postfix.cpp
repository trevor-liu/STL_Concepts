#include <iostream>
#include <utility> // importing pair
#include <stack> // importing stack
using namespace std;

int main()
{
    char instruction;
    bool calculatorrunning = true;

    // declare a stack with pairs
    stack<pair<int,int>> calculatormemory;

    while (calculatorrunning)
    {
        // decide which instruction to run
        cin >> instruction;

        if (instruction == 'V')
        {
            // push complex number on to the stack
            long long real, notreal;
            cin >> real >> notreal;
            calculatormemory.push(make_pair(real, notreal));
        }
        else if (instruction == 'B')
        {
            // Binary operator
            char op;
            cin >> op;
            long long a, b, c, d;
            
            // the top pair in stacks is the second complex number during calculation
            b = calculatormemory.top().first;
            d = calculatormemory.top().second;
            calculatormemory.pop();
            a = calculatormemory.top().first;
            c = calculatormemory.top().second;
            calculatormemory.pop();

            // depends on user input, carry out task respectively
            if (op == '+')
            {
                calculatormemory.push(make_pair(a+b, c+d));
            }
            else if (op == '-')
            {
                calculatormemory.push(make_pair(a-b, c-d));
            }
            else if (op == '*')
            {
                calculatormemory.push(make_pair(a*b-c*d, a*d+c*b));
            }
        }
        else if (instruction == 'U')
        {
            // Unary operator
            char op;
            cin >> op;
            long long a, b;

            // only require last complex number
            a = calculatormemory.top().first;
            b = calculatormemory.top().second;
            calculatormemory.pop();
            if (op == '-')
            {
                // negate the complex number
                a = 0-a;
                b = 0-b;
                calculatormemory.push(make_pair(a,b));
            }
            else if (op == 'c')
            {
                // only negate the complex part of complex number
                b = 0-b;
                calculatormemory.push(make_pair(a,b));
            }
        }
        else if (instruction == 'S')
        {
            // printing out the result
            calculatorrunning = false;
            cout << calculatormemory.top().first << " " << calculatormemory.top().second << endl;
        }

    }
}