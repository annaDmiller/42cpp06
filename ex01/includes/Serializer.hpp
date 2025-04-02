#pragma once

# include <iostream>
# include <string>
# include <stdint.h>

typedef std::string str;

typedef struct  s_Data
{
    unsigned int    id;
    str             name;
}               Data;

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);

    public:
        ~Serializer(void);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};