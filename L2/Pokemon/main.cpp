#include "Pokemon.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonExplosivo.hpp"
#include "Treinador.hpp"
#include "Campeonato.hpp"
#include "avaliacao_basica_pokemon.hpp"
#include <iostream>

#include "Pokemon.cpp"
#include "PokemonEletrico.cpp"
#include "PokemonAquatico.cpp"
#include "PokemonExplosivo.cpp"
#include "Treinador.cpp"
#include "Campeonato.cpp"

int main(int argc, char const *argv[])
{
    char comando;
    Campeonato *campeonato = new Campeonato();

    while (std ::cin >> comando)
    { // Lendo o caractere que define o comando

        // Executando o comando informado
        switch (comando)
        {

        case 't':
        {
            std ::string nome;
            std ::cin >> nome;

            campeonato->cadastrar_treinador(nome);

            break;
        }
        case 'i':
        {
            int idt;
            std ::cin >> idt;

            campeonato->imprimir_informacoes_treinador(idt);
            break;
        }

        case 'e':
        {
            int idt;
            std ::string nome;
            std ::string tipo_ataque;
            double forca_ataque;
            double potencia_raio;

            std ::cin >> idt >> nome >> tipo_ataque >> forca_ataque >> potencia_raio;

            campeonato->cadastrar_pokemon_eletrico(idt, nome, tipo_ataque, forca_ataque, potencia_raio);

            break;
        }
        case 'q':
        {
            int idt;
            std ::string nome;
            std ::string tipo_ataque;
            double forca_ataque;
            double litros_jato;

            std ::cin >> idt >> nome >> tipo_ataque >> forca_ataque >> litros_jato;

            campeonato->cadastrar_pokemon_aquatico(idt, nome, tipo_ataque, forca_ataque, litros_jato);

            break;
        }
        case 'x':
        {
            int idt;
            std ::string nome;
            std ::string tipo_ataque;
            double forca_ataque;
            double temperatura_explosao;

            std ::cin >> idt >> nome >> tipo_ataque >> forca_ataque >> temperatura_explosao;

            campeonato->cadastrar_pokemon_explosivo(idt, nome, tipo_ataque, forca_ataque, temperatura_explosao);

            break;
        }
        case 'h':
        {   
            int idt1, idpk1, idt2, idpk2;

            std :: cin >> idt1 >> idpk1 >> idt2 >> idpk2;
            
            campeonato->executar_batalha(idt1, idpk1, idt2, idpk2);

            break;
        }
        case 'b':
        {
            avaliacao_basica();
            break;
        }
        }
    }

    delete (campeonato);
    return 0;
}
