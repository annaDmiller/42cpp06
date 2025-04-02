#include "Serializer.hpp"

int main(void)
{
    Data example;
    example.id = 1;
    example.name = "Test";

    Data* ptr = &example;
    std::cout << "Initial pointer of the Data struct - " << ptr << std::endl;
    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "UINTPTR value - " << raw << std::endl;
    Data *result_ptr = Serializer::deserialize(raw);
    std::cout << "Resulting pointer of the Data struct - " << result_ptr << std::endl;
    std::cout << "Testing to reach name via resulting pointer - " << result_ptr->name << std::endl;
    return (0);
}