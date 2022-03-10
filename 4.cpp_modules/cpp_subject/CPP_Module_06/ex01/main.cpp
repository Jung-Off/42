#include "Data.hpp"

int main()
{
    Data dummy;
    uintptr_t d_serial;
    
    std::cout << " ===== base ===== " << std::endl;

    std::cout << "dummy data " << dummy.getName() << ", " << dummy.getTall() <<
    ", " << dummy.getWeight() << std::endl;
    std::cout << "dummy address [" << &dummy << "]" << std::endl << std::endl;

    std::cout << "serialize dummy " << std::endl;
    d_serial = serialize(&dummy);
    std::cout << d_serial << ", [" << std::hex << d_serial << "]" << std::endl << std::dec << std::endl;

    Data *d_dserial = deserialize(d_serial);

    std::cout << "deserialize dummy " << std::endl;
    std::cout << "dummy data " << d_dserial->getName() << ", " << d_dserial->getTall() <<
    ", " << d_dserial->getWeight() << std::endl;
    std::cout << "d_serial address [" << d_dserial << "]" << std::endl << std::endl;

    std::cout << " ===== ====  ===== " << std::endl;


    Data person(200, 100.23, "jji");
    uintptr_t p_serial;
    
    std::cout << "person data " << person.getName() << ", " << person.getTall() <<
    ", " << person.getWeight() << std::endl;
    std::cout << "person address [" << &person << "]" << std::endl << std::endl;

    std::cout << "serialize person " << std::endl;
    p_serial = serialize(&person);
    std::cout << p_serial << ", [" << std::hex << p_serial << "]" << std::endl << std::dec << std::endl;

    Data *p_dserial = deserialize(p_serial);

    std::cout << "deserialize person " << std::endl;
    std::cout << "person data " << p_dserial->getName() << ", " << p_dserial->getTall() <<
    ", " << p_dserial->getWeight() << std::endl;
    std::cout << "p_serial address [" << p_dserial << "]" << std::endl;

    //system("leaks Serialize");
}