#include <string>
#include <iostream>
#include "FilaAtendimento.hpp"
#include "Paciente.hpp"

using namespace std;

void FilaAtendimento ::adicionar_paciente(int prioridade, string nome, int idade)
{
    Paciente *novoPaciente = new Paciente(prioridade, nome, idade, proximaSenha++);

    if (inicio == nullptr)
    {
        inicio = novoPaciente;
        fim = novoPaciente;
    }
    else
    {
        Paciente *atual = inicio;
        Paciente *anterior = nullptr;

        while (atual != nullptr && atual->_prioridade <= prioridade)
        {
            anterior = atual;
            atual = atual->_proximo;
        }

        // Caso nao haja nenhum paciente com prioridade maior que o novo paciente
        if (anterior == nullptr)
        {
            novoPaciente->_proximo = inicio;
            inicio = novoPaciente;
        }

        // Caso o novo paciente esteja no fim da fila (todos tem prioridade maior que a dele)
        else if (atual == nullptr)
        {
            fim->_proximo = novoPaciente;
            fim = novoPaciente;
        }

        // Caso o novo paciente esteja no meio da fila
        else
        {
            anterior->_proximo = novoPaciente;
            novoPaciente->_proximo = atual;
        }
    }
}

Paciente *FilaAtendimento ::chamar_paciente_por_prioridade()
{

    if (inicio == nullptr)
    {
        cout << "Nenhum paciente!" << endl;
        return nullptr;
    }
    Paciente *pacienteChamado = inicio;
    inicio = inicio->_proximo;
    return pacienteChamado;
}
Paciente *FilaAtendimento ::chamar_paciente_por_idade()
{

    Paciente *pacienteRemovido = buscar_paciente_mais_velho();

    if (inicio == nullptr || pacienteRemovido == nullptr)
    {
        return nullptr;
    }

    Paciente *anterior = nullptr;
    Paciente *atual = inicio;

    while (atual != pacienteRemovido)
    {
        anterior = atual;
        atual = atual->_proximo;
    }

    if (anterior == nullptr)
    {
        // Caso o paciente a ser removido seja o primeiro da fila
        inicio = inicio->_proximo;
    }
    else
    {
        // Caso o paciente a ser removido estiver no meio da fila
        anterior->_proximo = pacienteRemovido->_proximo;
    }

    return pacienteRemovido;
}
Paciente *FilaAtendimento ::buscar_paciente_mais_velho()
{
    if (inicio == nullptr)
    {
        cout << "Nenhum paciente!" << endl;
        return nullptr;
    }

    Paciente *ptr = inicio;
    Paciente *pacienteMaisVelho = inicio;

    while (ptr != nullptr)
    {
        if (ptr->getIdade() > pacienteMaisVelho->getIdade())
        {
            pacienteMaisVelho = ptr;
        }
        ptr = ptr->_proximo;
    }

    return pacienteMaisVelho;
}

void FilaAtendimento ::estimativa_tempo_para_atendimento(int senha)
{
    if (senha >= proximaSenha)
    {
        cout << "Paciente nao esta na fila!" << endl;
        return;
    }
    Paciente *paciente = inicio;
    int espera = 0;
    while (paciente != nullptr && paciente->getID() != senha)
    {
        espera += paciente->tempo_reservado_atendimento();
        paciente = paciente->_proximo;
    }

    if (paciente != nullptr)
    {
        cout << "Tempo estimado para atendimento de " << paciente->_nome << " (senha=" << senha << ") eh " << espera << " minutos" << endl;
    }
    else
    {
        cout << "Paciente nao esta na fila!" << endl;
    }
}
void FilaAtendimento ::imprimir_fila()
{
    if (inicio == nullptr)
    {
        cout << "Nenhum paciente!" << endl;
    }
    else
    {
        Paciente *ptr = inicio;
        while (ptr != nullptr)
        {
            ptr->imprimir_dados();
            ptr = ptr->_proximo;
        }
    }
}