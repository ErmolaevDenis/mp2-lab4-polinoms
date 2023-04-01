#include "polinoms.h"

enum CHOOSE {add, sub, mul, dmul};

int main()
{
    Polinom a, b, res;
    double coef = 0;
    CHOOSE ch = add;
    cout << "The degree of each variable in the polynom must be equal or greater than 0 and less than 10" << endl << endl <<
        "Enter 0 if you want to add polynoms" << endl <<
        "Enter 1 if you want to subtract polynoms" << endl <<
        "Enter 2 if you want to multiply polynoms" << endl <<
        "Enter 3 if you want to multiply a polynom by a number" << endl;
    scanf_s("%d", &ch);
    cout << endl;
    try
    {
        switch (ch)
        {
        case add:
            cout << "Enter a first polynom" << endl;
            a.Set();
            cout << endl << "Enter a second polynom" << endl;
            b.Set();
            res = a + b;
            cout << endl << "The answer is:   ";
            res.Print();
            break;
        case sub:
            cout << "Enter a first polynom" << endl;
            a.Set();
            cout << endl << "Enter a second polynom" << endl;
            b.Set();
            res = a - b;
            cout << endl << "The answer is:   ";
            res.Print();
            break;
        case mul:
            cout << "Enter a first polynom" << endl;
            a.Set();
            cout << endl << "Enter a second polynom" << endl;
            b.Set();
            res = a * b;
            cout << endl << "The answer is:   ";
            res.Print();
            break;
        case dmul:
            cout << "Enter a polynom" << endl;
            a.Set();
            cout << endl << "Enter a number" << endl;
            cin >> coef;
            res = a * coef;
            cout << endl << "The answer is:   ";
            res.Print();
            break;
        default:
            cout << "Incorrect input";
            break;
        }
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }
}