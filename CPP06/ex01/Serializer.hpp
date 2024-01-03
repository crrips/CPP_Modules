#pragma once

#include <iostream>

class Serializer
{
    public:
        typedef struct Data
        {
            int i;
        } Data;

        Serializer();
        ~Serializer();
        Serializer(const Serializer &other);
        Serializer &operator=(const Serializer &other);

        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};
