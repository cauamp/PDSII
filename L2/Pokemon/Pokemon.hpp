#ifndef Pokemon_H
#define Pokemon_H

#include <iostream>

class Pokemon
{
private:
    std ::string _nome;
    std ::string _tipo_ataque;
    double _forca_ataque;
    double _energia = 100;
    void receber_dano(double valor_dano);

public:
    Pokemon(std ::string nome, std ::string tipo_ataque, double forca_ataque);
    virtual ~Pokemon(){};

    std ::string get_nome();
    std ::string get_tipo_ataque();
    double get_forca_ataque();


    virtual void falar_tipo_ataque();
    void falar_nome();
    void imprimir_status();
    void imprimir_informacoes();
    virtual double calcular_dano() = 0;
    void atacar(Pokemon *outro_pokemon);
};

#endif
