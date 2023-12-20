#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    this->_materia = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->_materia[i];
    delete [] this->_materia;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    this->_materia = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        this->_materia[i] = other._materia[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            delete this->_materia[i];
        delete [] this->_materia;
        this->_materia = new AMateria*[4];
        for (int i = 0; i < 4; i++)
            this->_materia[i] = other._materia[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] == NULL)
        {
            this->_materia[i] = m;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
            return this->_materia[i]->clone();
    }
    return NULL;
}
