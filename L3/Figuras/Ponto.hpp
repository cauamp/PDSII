#ifndef Ponto_H
#define Ponto_H

class Ponto
{
private:
    double _x;
    double _y;

public:
    Ponto(double x = 0, double y = 0) : _x(x), _y(y) {}

    double getX() const { return _x; }
    double getY() const { return _y; }
};

#endif