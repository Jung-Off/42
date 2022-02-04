#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

#define RED 	"\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW 	"\x1b[33m"
#define BLUE 	"\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN	"\x1b[36m"
#define RESET 	"\x1b[0m"

class Karen
{
    private:
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
        void (Karen::*_f[4])(void);
    public:
        void complain (std::string level);
        Karen();
        ~Karen();
};

#endif