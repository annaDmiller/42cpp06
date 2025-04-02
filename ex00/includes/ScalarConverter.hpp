#pragma once

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include <exception>
# include <bits/stdc++.h>
# include <cmath>
# include <sstream>

typedef std::string str;

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

    public:
        ~ScalarConverter(void);

        static void convert(const str& line);

        static bool isPrintable(const unsigned char& car);
        static bool isDigit(const unsigned char& car);
        static bool isPseudo(const std::string& line, double& num_double, float& num_fl);

        static bool checkDoubleCorrectConversion(double num_d, const str& line);
        static bool checkFloatCorrectConversion(float num_f, const str& line);

        static void printScalars(unsigned char car, int num, double num_double, float num_float, bool isPseudo);

        class TooBigDoubleNumberException : public std::exception
        {
            virtual const char* what() const throw();
        };

        class TooBigFloatNumberException : public std::exception
        {
            virtual const char* what() const throw();
        };
};