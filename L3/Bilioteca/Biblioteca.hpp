#ifndef Biblioteca_HPP
#define Biblioteca_HPP
#include "Livro.hpp"
#include "LivroFiccao.hpp"
#include "LivroNaoFiccao.hpp"
#include "LivroInfantil.hpp"
#include <vector>

class Biblioteca
{
private:
    std ::vector<Livro *> _livros;

public:
    ~Biblioteca();

    void add_livro(Livro *livro);
    void list_livros();
    void find_livro(int id);
    void remove_livro(int id);
};

#endif
