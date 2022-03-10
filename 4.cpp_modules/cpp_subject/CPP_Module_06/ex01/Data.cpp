#include "Data.hpp"

Data::Data()
	: _name("Dummy"), _tall(213), _weight(130.5)
	{}

Data::Data(const Data& d)
	: _name(d.getName()), _tall(d.getTall()), _weight(d.getWeight())
	{}

Data& Data::operator=(const Data& d)
{
	if (this != &d)
	{
		_name = getName();
		_tall = getTall();
		_weight = getWeight();
	}
	return (*this);
}

Data::~Data()
	{}

Data::Data(int t, double w, std::string name)
	: _name(name), _tall(t), _weight(w)
	{}

std::string Data::getName() const
{
	return (_name);
}

int Data::getTall() const
{
	return (_tall);
}

double Data::getWeight() const
{
	return (_weight);
}

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}