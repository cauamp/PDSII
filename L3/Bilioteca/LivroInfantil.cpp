#include "LivroInfantil.hpp"

LivroInfantil ::LivroInfantil(std ::string titulo, std ::string autor, int anoPublicacao, int faixaEtariaMinima) : Livro ::Livro(titulo, autor, anoPublicacao), _faixaEtariaMinima(faixaEtariaMinima)
{
    this->set_genero("Infantil");
}
LivroInfantil ::~LivroInfantil()
{
    std ::cout << "Destrutor LivroInfantil" << std ::endl;
}
void LivroInfantil ::print_info()
{
    Livro ::print_info();
    std ::cout << "\tFaixa etaria minima: " << this->_faixaEtariaMinima << std ::endl;
}