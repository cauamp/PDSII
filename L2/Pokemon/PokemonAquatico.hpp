#ifndef PokemonAquatico_H
#define PokemonAquatico_H

#include "Pokemon.hpp"
#include <iostream>
class PokemonAquatico : public Pokemon
{
private:
    double _litros_jato;
    double calcular_dano();

public:
    PokemonAquatico(std ::string nome, std ::string tipo_ataque, double forca_ataque, double litros_jato);
    void falar_tipo_ataque();
    double ataque_aquatico();
};

#endif
