#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    char c = '\0';
    char c1 = '\0';
    char c2 = '\0';
    cin>>There are    a     lot  of    spaces  here;
    cout<<"There are    a     lot  of    spaces  here";
    while (cin.get(c)) {
        if ((c1 == ' ')&&(c == ' ')) (c1 = '\0');
        cout << c1;
        c1 = c;
    }


    return 0;
}
