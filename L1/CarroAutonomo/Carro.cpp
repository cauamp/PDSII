#include "Carro.hpp"
#include "Pessoa.hpp"
#include <iostream>
#include <cmath>


#ifndef M_PI
#define M_PI 3.1415
#endif

using namespace std;

Carro ::Carro(double x, double y, double th)
{
    this->x = x;
    this->y = y;
    this->th = th;
}

double Carro::getX()
{
    return this->x;
}

double Carro::getY()
{
    return this->y;
}

double Carro::getTH()
{
    return this->th;
}

void Carro::girar(double w, double t)
{
    this->th += w * t;
}

void Carro::mover(double v, double t)
{
    double h = v * t;

    this->x += h * cos(this->th);
    this->y += h * sin(this->th);
}

double Carro::calcular_angulo_pessoa(Pessoa *pessoa)
{
    return atan2(pessoa->y - this->y, pessoa->x - this->x) - this->th;
}

double Carro::calcular_distancia_pessoa(Pessoa *pessoa)
{
    return sqrt(pow(this->x - pessoa->x, 2) + pow(this->y - pessoa->y, 2));
}

bool Carro::movimentacao_permitida(Pessoa **pessoas, int n)
{
    bool livre = true;
    for (int i = 0; i < n; i++)
    {
        double ang = calcular_angulo_pessoa(pessoas[i]) *180/M_PI ;
        double dist = calcular_distancia_pessoa(pessoas[i]);

        if (ang >= -45 && ang <= 45 && dist < 5)
        {
            cout << "Alerta!\t" << i << "\t" << ang<< "\t" << dist << endl;
            livre = false;
        }
    }
    return livre;
}

void Carro::navegar(Pessoa **pessoas, int n, double w, double v, double t)
{
    if (movimentacao_permitida(pessoas, n))
    {
        this->girar(w, t);
        this->mover(v, t);
    }
}