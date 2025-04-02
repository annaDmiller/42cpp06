#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void);
void identify(Base& p);
void identify(Base* p);

int main(void)
{
    Base *rnd_ptr = generate();
    std::cout << std::endl;

    identify(rnd_ptr);
    std::cout << std::endl;

    identify(*rnd_ptr);

    delete(rnd_ptr);
    return (0);
}