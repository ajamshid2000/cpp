
#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

int main(int ac, char **argv)
{
    int i = 1;
    string str;
    string arg_value;

    (void)ac;
    while(argv[i])
    {
        arg_value = argv[i];
        transform(arg_value.begin(), arg_value.end(), arg_value.begin(), [](unsigned char c) { return std::toupper(c); });
        i++;
        cout<<arg_value;
    }

    return 0;
}