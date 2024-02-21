#ifndef Figura_H
#define Figura_H
#include <iostream>
#include "Ponto.hpp"

class Figura
{
public:
    virtual bool contem(const Ponto &p) const = 0;

    virtual ~Figura();

    friend Figura *operator+(Figura &f1, Figura &f2);
    friend Figura *operator-(Figura &f1, Figura &f2);
};

class FiguraComposta : public Figura
{
private:
    Figura *_f1;
    Figura *_f2;
    char _tipo;

public:
    bool contem(const Ponto &p) const;

    FiguraComposta(Figura *f1, Figura *f2, char tipo);
    ~FiguraComposta();
};

#endif