#ifndef PokemonExplosivo_H
#define PokemonExplosivo_H

#include "Pokemon.hpp"
#include <iostream>
class PokemonExplosivo : public Pokemon
{
private:
    double _temperatura_explosao;
    double calcular_dano();

public:
    PokemonExplosivo(std ::string nome, std ::string tipo_ataque, double forca_ataque, double litros_jato);
    void falar_tipo_ataque();
    double ataque_explosivo();
};

#endif