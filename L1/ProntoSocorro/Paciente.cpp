#include <string>
#include <iostream>
#include "Paciente.hpp"

Paciente ::Paciente(int prioridade, std::string nome, int idade, int senha)
{
    _prioridade = prioridade;
    _nome = nome;
    _idade = idade;
    _senha = senha;
    _proximo = nullptr;
}

int Paciente ::getID()
{
    return _senha;
}
int Paciente ::getPrioridade()
{
    return _prioridade;
}
int Paciente ::getIdade()
{
    return _idade;
}
string Paciente ::getNome()
{
    return _nome;
}

int Paciente ::tempo_reservado_atendimento()
{
    int retorno;
    switch (_prioridade)
    {
    case 0:
    {
        retorno = 20;
        break;
    }

    case 1:
    {
        retorno = 18;
        break;
    }

    case 2:
    {
        retorno = 12;
        break;
    }

    case 3:
    {
        retorno = 8;
        break;
    }

    case 4:
    {
        retorno = 6;
        break;
    }
    }
    return retorno;
}

void Paciente ::imprimir_dados()
{
    char prioridade[] = "VLADZ";

    cout << prioridade[_prioridade] << "\t" << _senha << "\t" << _nome << "\t" << _idade << endl;
}
