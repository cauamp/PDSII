#ifndef LivroInfantil_HPP
#define LivroInfantil_HPP
#include "Livro.hpp"

class LivroInfantil : public Livro
{
private:
    int _faixaEtariaMinima;

public:
    LivroInfantil(std :: string titulo, std :: string autor, int anoPublicacao, int faixaEtariaMinima);
    ~LivroInfantil() override;
    void print_info() override;
};

#endif