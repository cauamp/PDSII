#include "Treinador.hpp"

#include <iostream>
#include <vector>
#include "Pokemon.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonExplosivo.hpp"

Treinador ::Treinador(std ::string nome) : _nome(nome) {}

Treinador ::~Treinador()
{
    for (unsigned int i = 0; i < this->_pokemons.size(); i++)
    {
        delete (this->_pokemons[i]);
    }
}

std::string Treinador ::get_nome(){return this->_nome;};

void Treinador ::cadastrar_pokemon_eletrico(std ::string nome, std ::string tipo_ataque, double forca_ataque, double potencia_raio)
{
    PokemonEletrico *pokemon = new PokemonEletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
    _pokemons.push_back(pokemon);
}
void Treinador ::cadastrar_pokemon_aquatico(std ::string nome, std ::string tipo_ataque, double forca_ataque, double litros_jato)
{
    PokemonAquatico *pokemon = new PokemonAquatico(nome, tipo_ataque, forca_ataque, litros_jato);
    _pokemons.push_back(pokemon);
}
void Treinador ::cadastrar_pokemon_explosivo(std ::string nome, std ::string tipo_ataque, double forca_ataque, double temperatura_explosao)
{
    PokemonExplosivo *pokemon = new PokemonExplosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao);
    _pokemons.push_back(pokemon);
}
Pokemon *Treinador ::usar_pokemon(int idpk)
{
    return this->_pokemons[idpk];
}
void Treinador ::imprimir_informacoes()
{
    std::cout << "Nome: " << this->_nome << std::endl;

    std::cout << "----------" << std::endl;

    if (this->_pokemons.size() == 0)
    {
        std::cout << "Nenhum Pokemon cadastrado!" << std::endl;
        std::cout << "----------" << std::endl;
    }

    for (Pokemon *pokemon : this->_pokemons)
    {
        pokemon->imprimir_informacoes();
        std::cout << "----------" << std::endl;
    }
}