#include "Campeonato.hpp"

Campeonato ::~Campeonato()
{
    for (Treinador *treinador : _treinadores)
    {
        delete (treinador);
    }
}
void Campeonato ::cadastrar_treinador(std::string nome)
{
    Treinador *treinador = new Treinador(nome);
    _treinadores.push_back(treinador);
}
void Campeonato ::cadastrar_pokemon_eletrico(int idt, std ::string nome, std ::string tipo_ataque, double forca_ataque, double potencia_raio)
{
    this->_treinadores[idt]->cadastrar_pokemon_eletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
}
void Campeonato ::cadastrar_pokemon_aquatico(int idt, std ::string nome, std ::string tipo_ataque, double forca_ataque, double litros_jato)
{
    this->_treinadores[idt]->cadastrar_pokemon_aquatico(nome, tipo_ataque, forca_ataque, litros_jato);
}
void Campeonato ::cadastrar_pokemon_explosivo(int idt, std ::string nome, std ::string tipo_ataque, double forca_ataque, double temperatura_explosao)
{
    this->_treinadores[idt]->cadastrar_pokemon_explosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao);
}
void Campeonato ::imprimir_informacoes_treinador(int idt)
{
    this->_treinadores[idt]->imprimir_informacoes();
}
void Campeonato ::executar_batalha(int idt1, int idpk1, int idt2, int idpk2)
{
    Treinador *T1 = this->_treinadores[idt1];
    Pokemon *P1 = T1->usar_pokemon(idpk1);
    Treinador *T2 = this->_treinadores[idt2];
    Pokemon *P2 = T2->usar_pokemon(idpk2);

    std::cout << "### Batalha ###" << std::endl;
    std::cout << T1->get_nome() << " (" << P1->get_nome() << ") vs. " << T2->get_nome() << " (" << P2->get_nome() << ")" << std::endl;

    P1->atacar(P2);
    P2->imprimir_status();
    
    std::cout << "#########" << std::endl;
}