#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:

    public:
        Fixed();
        Fixed(Fixed& fixed);
        Fixed operator=(Fixed &fixed);
        ~Fixed();
};

#endif