#ifndef LivroNaoFiccao_HPP
#define LivroNaoFiccao_HPP
#include "Livro.hpp"

class LivroNaoFiccao : public Livro
{
private:
    std::string _assunto;

public:
    LivroNaoFiccao(std ::string titulo, std ::string autor, int anoPublicacao, std ::string assunto);
    ~LivroNaoFiccao() override;
    void print_info() override;
};

#endif