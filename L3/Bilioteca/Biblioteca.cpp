#include "Biblioteca.hpp"

Biblioteca ::~Biblioteca()
{
    for (unsigned int i = 0; i < _livros.size(); i++)
    {
        delete (this->_livros[i]);
    }
}
void Biblioteca ::add_livro(Livro *livro)
{
    _livros.push_back(livro);
}
void Biblioteca ::list_livros()
{
    for (unsigned int i = 0; i < _livros.size(); i++)
    {
        this->_livros[i]->print_info();
    }
}
void Biblioteca ::find_livro(int id)
{
    for (unsigned int i = 0; i < _livros.size(); i++)
    {
        if (this->_livros[i]->get_id() == id)
        {
            this->_livros[i]->print_info();
            return;
        }
    }

    std ::cout << "Erro ao pesquisar: livro com ID " << id << " nao encontrado" << std ::endl;
}
void Biblioteca ::remove_livro(int id)
{
    for (auto livro = _livros.begin(); livro !=  _livros.end(); livro++)
    {
        if((*livro)->get_id() == id){
            delete(*livro);
            _livros.erase(livro);
            return;
        }
    }
    std ::cout << "Erro ao remover: livro com ID " << id << " nao encontrado" << std ::endl;
}
