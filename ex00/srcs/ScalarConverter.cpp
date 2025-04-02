#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
    return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void) other;
    return ;
}

ScalarConverter::~ScalarConverter(void)
{
    return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void) other;
    return (*this);
}

void ScalarConverter::convert(const str& line)
{
    unsigned char   car = 0;
    int             int_num = 0;
    double          doub_num = 0;
    float           fl_num = 0;
    str             temp = line;

    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    if (line.length() == 1)
    {
        if (isDigit(line[0]) == true)
        {
            int_num = static_cast<int>(line[0] - '0');
            doub_num = static_cast<double>(int_num);
            fl_num = static_cast<float>(int_num);
            car = static_cast<char>(int_num);
        }
        else
        {
            car = line[0];
            int_num = line[0];
            doub_num = static_cast<double>(int_num);
            fl_num = static_cast<float>(int_num);
        }
        printScalars(car, int_num, doub_num, fl_num, false);
        return ;
    }
    if (isPseudo(temp, doub_num, fl_num) == true)
    {
        printScalars(car, int_num, doub_num, fl_num, true);
        return ;
    }
    try
    {
        doub_num = std::atof(line.c_str());
        if (checkDoubleCorrectConversion(doub_num, line) == false)
            throw ScalarConverter::TooBigDoubleNumberException();
        fl_num = static_cast<float>(doub_num);
        if (checkFloatCorrectConversion(fl_num, line) == false)
            throw ScalarConverter::TooBigFloatNumberException();
        int_num = static_cast<int>(doub_num);
        car = static_cast<char>(int_num);
        if (doub_num > INT_MAX || doub_num < INT_MIN)
            printScalars(car, int_num, doub_num, fl_num, true);
        else
            printScalars(car, int_num, doub_num, fl_num, false);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return ;
}

bool ScalarConverter::isPrintable(const unsigned char& car)
{
    if (car < 32 || car > 126)
        return (false);
    return (true);
}

bool ScalarConverter::isDigit(const unsigned char& car)
{
    if (car >= '0' && car <= '9')
        return (true);
    return (false);
}

bool ScalarConverter::isPseudo(const std::string &line, double& num_double, float& num_fl)
{
    const std::string pseudos[] = {"nan", "inf", "+inf", "-inf"};
    int ind = 0;

    while (ind < 4)
    {
        if (line == pseudos[ind])
            break ;
        ind++;
    }

    if (ind == 4)
        return (false);

    switch (ind)
    {
    case 0:
        num_double = std::numeric_limits<double>::quiet_NaN();
        num_fl = std::numeric_limits<float>::quiet_NaN();
        break ;
    case 1:
        num_double = std::numeric_limits<double>::infinity();
        num_fl = std::numeric_limits<float>::infinity();
        break ;
    case 2:
        num_double = std::numeric_limits<double>::infinity();
        num_fl = std::numeric_limits<float>::infinity();
        break ;
    case 3:
        num_double = -std::numeric_limits<double>::infinity();
        num_fl =  -std::numeric_limits<float>::infinity();
        break ;
    default:
        break;
    }
    return (true);
}

bool ScalarConverter::checkDoubleCorrectConversion(double num_d, const str& line)
{
    std::ostringstream oss;
    oss.precision(std::numeric_limits<double>::digits10 + 1);
    oss << num_d;

    if (oss.str() != line)
        return (false);
    return (true);
}

bool ScalarConverter::checkFloatCorrectConversion(float num_f, const str& line)
{
    std::ostringstream oss;
    oss.precision(std::numeric_limits<float>::digits10 + 1);
    oss << num_f;

    if (oss.str() != line)
        return (false);
    return (true);
}

void ScalarConverter::printScalars(unsigned char car, int num, double num_double, float num_float, bool isPseudo)
{
    std::cout << "char: ";
    if (isPseudo == true || num < 0)
        std::cout << "impossible" << std::endl;
    else if (isPrintable(car))
        std::cout << "'" << car << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
    std::cout << "int: ";
    if (isPseudo == true)
        std::cout << "impossible" << std::endl;
    else
        std::cout << num << std::endl;
    std::cout << "float: ";
    if (std::isinf(num_float) == true && num_float > 0)
        std::cout << "+" << num_float << "f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << num_float << "f" << std::endl; 
    std::cout << "double: ";
    if (std::isinf(num_double) && num_double > 0)
        std::cout << "+" << num_double << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << num_double << std::endl; 
    return ;
}

const char* ScalarConverter::TooBigDoubleNumberException::what() const throw()
{
    std::cerr << "EXCEPTION CAUGHT" << std::endl;
    return ("MOD of input value is too big for accurate precision of double variable");
}

const char* ScalarConverter::TooBigFloatNumberException::what() const throw()
{
    std::cerr << "EXCEPTION CAUGHT" << std::endl;
    return ("MOD of input value is too big for accurate precision of float variable");
}