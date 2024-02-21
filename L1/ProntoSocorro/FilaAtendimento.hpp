#ifndef FilaAtendimento_H
#define FilaAtendimento_H
#include <string>
#include <iostream>
#include "Paciente.hpp"

struct FilaAtendimento
{
    Paciente * inicio = nullptr;
    Paciente * fim = nullptr;
    int proximaSenha = 1;

    void adicionar_paciente(int prioridade, std :: string nome, int idade);
    Paciente *chamar_paciente_por_prioridade();
    Paciente *chamar_paciente_por_idade();
    Paciente *buscar_paciente_mais_velho();
    void estimativa_tempo_para_atendimento(int senha);
    void imprimir_fila();
};

#endif