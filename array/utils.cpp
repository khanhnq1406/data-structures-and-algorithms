#include <iostream>
#include <string.h>
using namespace std;
class interface
{
    public: static void printFuncName(string msg)
    {
        cout << endl << "*****************************" << endl;
        cout << msg << endl;
        cout << "- - - - - - - - - - - - - - -" << endl;
    }
};