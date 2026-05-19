
#include <iostream>
#include <string>

int main(int ac, char **argv)
{
    int i = 1;
    int j;
    std::string arg_value;

    (void)ac;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (i < ac)
        {
            j = 0;
            while (argv[i][j])
            {
                arg_value += std::toupper(argv[i][j]);
                j++;
            }
            i++;
        }
        std::cout << arg_value << std::endl;
    }

    return 0;
}
