#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
    private:
        std::string _name;
        int         _tall;
        double      _weight;
    
    public:
        Data();
        Data(const Data& d);
        Data& operator=(const Data& d);
        ~Data();
        
        Data(int t, double w, std::string name);

        std::string getName() const;
        int getTall() const;
        double getWeight() const;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif