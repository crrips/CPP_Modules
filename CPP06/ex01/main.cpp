#include "Serializer.hpp"

int main()
{
    Serializer s;
    Serializer::Data data;

    data.i = 42;
    uintptr_t raw = s.serialize(&data);
    std::cout << "raw: " << raw << std::endl;
    std::cout << "data: " << s.deserialize(raw)->i << std::endl;
    return 0;
}