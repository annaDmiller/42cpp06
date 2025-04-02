#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <stdlib.h>

Base* generate(void)
{
    Base *ret_ptr;

    srand(time(NULL));
    int rnd_choice = rand() % 3;

    switch (rnd_choice)
    {
    case 0:
        ret_ptr = new A();
        std::cout << "Pointer to A object is created randomly" << std::endl;
        break ;
    case 1:
        ret_ptr = new B();
        std::cout << "Pointer to B object is created randomly" << std::endl;
        break ;
    case 2:
        ret_ptr = new C();
        std::cout << "Pointer to C object is created randomly" << std::endl;
        break ;
    default:
        break ;
    }
    return (ret_ptr);
}

void identify(Base* p)
{
    if (p == NULL)
        return ;
    
    std::cout << "The actual type of the object referenced by reference p - ";
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown" << std::endl;
    return ;
}

void identify(Base& p)
{
    std::cout << "The actual type of the object referenced by reference p - ";
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    std::cout << "unknown" << std::endl;
    return ;
}