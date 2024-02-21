#include "LivroFiccao.hpp"

LivroFiccao ::LivroFiccao(std ::string titulo, std ::string autor, int anoPublicacao, std ::string subgenero) : Livro ::Livro(titulo, autor, anoPublicacao), _subgenero(subgenero)
{
    this->set_genero("Ficcao");
}
LivroFiccao ::~LivroFiccao()
{
    std ::cout << "Destrutor LivroFiccao" << std ::endl;
}
void LivroFiccao ::print_info()
{
    Livro::print_info();
    std ::cout << "\tSubgenero: " << this->_subgenero << std ::endl;
}