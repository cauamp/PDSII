#include "Pokemon.hpp"

#include <iostream>

void Pokemon ::receber_dano(double valor_dano)
{
    this->_energia -= valor_dano;

    if (this->_energia <= 0)
    {
        this->_energia = 0;
        std ::cout << this->_nome << " morreu!" << std::endl;
    }
}

Pokemon ::Pokemon(std ::string nome, std ::string tipo_ataque, double forca_ataque) : _nome(nome), _tipo_ataque(tipo_ataque), _forca_ataque(forca_ataque) {}

std ::string Pokemon ::get_nome() { return this->_nome; };

std ::string Pokemon ::get_tipo_ataque() { return this->_tipo_ataque; };

double Pokemon ::get_forca_ataque() { return this->_forca_ataque; };

void Pokemon ::falar_nome()
{
    std ::cout << this->_nome << "!" << std::endl;
}
void Pokemon ::falar_tipo_ataque()
{
    std ::cout << this->_tipo_ataque << "!" << std::endl;
}
void Pokemon ::imprimir_status()
{
    this->falar_nome();
    std ::cout << "Energia: " << this->_energia << std::endl;
}
void Pokemon ::imprimir_informacoes()
{
    std ::cout << "Pokemon: " << this->_nome << std::endl;
    std ::cout << "Tipo ataque: " << this->_tipo_ataque << std::endl;
    std ::cout << "Dano: " << this->calcular_dano() << std::endl;
    std ::cout << "Energia: " << this->_energia << std::endl;
}
void Pokemon ::atacar(Pokemon *outro_pokemon)
{
    this->falar_nome();
    this->falar_tipo_ataque();

    double dano = this->calcular_dano();
    std ::cout << "Dano: " << dano << std::endl;
    outro_pokemon->receber_dano(dano);
}

