#include <iostream>

char    only_maj(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main(int argc, char **argv)
{
    int i, j;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (i = 1; i < argc; i++)
            for (j = 0; argv[i][j]; j++)
                std::cout << only_maj(argv[i][j]);
        std::cout << std::endl;
    }
    return 0;
}