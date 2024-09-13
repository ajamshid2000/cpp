
#include <iostream>
using namespace std;

int main()
{
char* p;
int myage = 24;
double float_number = 35e3;
char charecter= 'a';
string str = "str";
bool myboolean = true;
int x = 1, y = 2, z = 3;
cout << "hello world" << '\n';
cout << "how are you?" << endl;
cout << "i am " << myage << " years old" << '\n';
cout << "this is a float number "<<float_number + float_number << '\n';
cout << str.length() << " " << str.size() <<'\n';
cout << str.at(str.length() - 1);  // Last character
cout << min(5, 10) <<'\n';
cout << max(5, 10) <<'\n';
cout << (5 > 10)<<'\n';

int time = 20;
string result = (time < 18) ? "Good day." : "Good evening.";

int day = 4;
switch (day) { /// break; and default: are optional in cases but program might be faster if used
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        cout << "the entered number does not correspond with any day";
}
// cin >> p;
// cout << p;

return (0);
}
