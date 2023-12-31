#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        virtual ~Ice();
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        virtual AMateria *clone() const;
        virtual void use(ICharacter &target);
};

#endif