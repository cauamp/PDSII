#include "PokemonAquatico.hpp"
#include <iostream>

double PokemonAquatico ::calcular_dano(){
    return this->get_forca_ataque() + this->_litros_jato;
}

PokemonAquatico ::PokemonAquatico(std ::string nome, std ::string tipo_ataque, double forca_ataque, double litros_jato) : Pokemon(nome, tipo_ataque, forca_ataque), _litros_jato(litros_jato) {}

void PokemonAquatico ::falar_tipo_ataque()
{
    Pokemon::falar_tipo_ataque();
    std ::cout << "Splash!" << std ::endl;
}
double PokemonAquatico ::ataque_aquatico() {
    return this->calcular_dano();
}
