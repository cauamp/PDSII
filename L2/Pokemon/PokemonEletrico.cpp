#include "PokemonEletrico.hpp"
#include <iostream>

double PokemonEletrico ::calcular_dano()
{
    return this->get_forca_ataque() * this->_potencia_raio;
}

PokemonEletrico ::PokemonEletrico(std ::string nome, std ::string tipo_ataque, double forca_ataque, double potencia_raio) : Pokemon(nome, tipo_ataque, forca_ataque), _potencia_raio(potencia_raio) {}
void PokemonEletrico ::falar_tipo_ataque()
{
    Pokemon::falar_tipo_ataque();
    std ::cout << "Bzzzz!" << std ::endl;
}
double PokemonEletrico ::ataque_eletrico()
{
    return this->calcular_dano();
}