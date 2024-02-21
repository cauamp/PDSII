#ifndef LivroFiccao_HPP
#define LivroFiccao_HPP
#include "Livro.hpp"

class LivroFiccao : public Livro
{
private:
    std::string _subgenero;

public:
    LivroFiccao(std ::string titulo, std ::string autor, int anoPublicacao, std ::string subgenero);
    ~LivroFiccao() override;
    void print_info() override;
};

#endif