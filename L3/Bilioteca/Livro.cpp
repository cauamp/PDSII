#include "Livro.hpp"

int Livro :: _prox_id = 1;

Livro ::Livro(std ::string titulo, std ::string autor, int anoPublicacao) : _id(_prox_id), _titulo(titulo), _autor(autor), _anoPublicacao(anoPublicacao)
{
    _prox_id++;
}
Livro ::~Livro()
{
    std ::cout << "Destrutor Livro" << std ::endl;
}
void Livro ::print_info()
{
    std ::cout << "Info: Livro " << this->_id << std::endl;
    std ::cout << "\tTitulo: " << this->_titulo << std ::endl;
    std ::cout << "\tAutor: " << this->_autor << std ::endl;
    std ::cout << "\tAno de publicacao: " << this->_anoPublicacao << std ::endl;
    std ::cout << "\tGenero: " << this->_genero << std ::endl;
}
void Livro ::set_genero(std ::string genero) { this->_genero = genero; }

int Livro ::get_id()
{
    return this->_id;
}
