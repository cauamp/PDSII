#ifndef PokemonEletrico_H
#define PokemonEletrico_H

#include "Pokemon.hpp"
#include <iostream>
class PokemonEletrico : public Pokemon
{
private:
    double _potencia_raio;
    double calcular_dano();

public:
    PokemonEletrico(std ::string nome, std ::string tipo_ataque, double forca_ataque, double potencia_raio);
    void falar_tipo_ataque();
    double ataque_eletrico();
};

#endif
