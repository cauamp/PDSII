#ifndef Pessoa_H
#define Pessoa_H

struct Pessoa
{
    double x, y;

    Pessoa(double x, double y);
    
    double getX();

    double getY();

    void mover(double dx, double dy);

};

#endif