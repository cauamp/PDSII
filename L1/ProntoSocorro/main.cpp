//#include "avaliacao_basica_atendimento.hpp"
#include "Paciente.hpp"
#include "FilaAtendimento.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    FilaAtendimento *fila = new FilaAtendimento;
    int prioridade, idade;
    string nome;
    int senha;
    char comando;
    while (cin >> comando)
    { // Lendo o caractere que define o comando

        // Executando o comando informado
        switch (comando)
        {

            case 'a':
            {
                // Comando para adicionar um novo paciente na fila
                cin >> prioridade;
                cin >> nome;
                cin >> idade;
                fila->adicionar_paciente(prioridade, nome, idade);
                break;
            }
            case 'p':
            {
                // Comando para imprimir o estado atual da fila
                fila->imprimir_fila();
                break;
            }
            case 'r':
            {
                // Comando para chamar um paciente da fila considerando a prioridade e ordem de inserção
                fila->chamar_paciente_por_prioridade();
                break;
            }
            case 'i':
            {
                // Comando para chamar um paciente da fila considerando a idade e ordem de inserção
                fila->chamar_paciente_por_idade();
                break;
            }
            case 'm':
            {
                // Comando para recuperar e imprimir os dados do paciente mais velho na fila
                Paciente * maisVelho = fila->buscar_paciente_mais_velho();
                maisVelho->imprimir_dados();
                break;
            }
            case 'e':
            {
                // Comando para imprimir a estimativa de tempo para atendimento do paciente com a senha informada
                cin >> senha;
                fila->estimativa_tempo_para_atendimento(senha);
                break;
            }
            case 'b':
            {
                // Comando para chamar a função 'avaliacao_basica()'
                //avaliacao_basica(); 
                break;
            }
        }
    }

    delete fila;

    return 0;
}