
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define CELL_MAX 100

class Brain
{
    private:
        std::string _cell[CELL_MAX];
    public:
        Brain();
        Brain(const Brain& a);
        Brain& operator=(const Brain& a);
        ~Brain();

        std::string getCell(int i) const;
        void setCell(std::string cell, int i);
};

#endif