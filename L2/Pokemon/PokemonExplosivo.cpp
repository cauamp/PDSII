#include "PokemonExplosivo.hpp"
#include <iostream>

double PokemonExplosivo ::calcular_dano(){
    return this->get_forca_ataque() / this->_temperatura_explosao;
}

PokemonExplosivo ::PokemonExplosivo(std ::string nome, std ::string tipo_ataque, double forca_ataque, double temperatura_explosao) : Pokemon(nome, tipo_ataque, forca_ataque), _temperatura_explosao(temperatura_explosao) {}

void PokemonExplosivo ::falar_tipo_ataque()
{
    Pokemon::falar_tipo_ataque();
    std ::cout << "Boom!" << std ::endl;
}
double PokemonExplosivo ::ataque_explosivo() {
    return this->calcular_dano();
}