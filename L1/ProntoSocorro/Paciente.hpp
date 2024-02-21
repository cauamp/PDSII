#ifndef Paciente_H
#define Paciente_H

#include <string>
using namespace std;

struct Paciente
{
    int _senha;
    int _prioridade;
    int _idade;
    std :: string _nome;
    Paciente * _proximo;

    int getID();
    int getPrioridade();
    int getIdade();
    string getNome();

    Paciente(int prioridade, string nome, int idade, int senha);

    int tempo_reservado_atendimento();

    void imprimir_dados();
};

#endif