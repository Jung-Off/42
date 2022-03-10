
#include "utils.hpp"

int main()
{
    Base* random_pointer = generate();
    identify(random_pointer);

    // sleep(1);

    Base* random_base_refer = generate();
    Base& random_refer = *random_base_refer;
    identify(random_refer);

    delete random_pointer;
    delete random_base_refer;

    // system("leaks Identify");
}