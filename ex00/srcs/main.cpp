#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "The argument is required" << std::endl;
        return (1);
    }
    if (argc != 2)
    {
        std::cerr << "Please, input line as one arguments" << std::endl;
        return (1);
    }
    str arg = argv[1];
    ScalarConverter::convert(arg);
    return (0);
}