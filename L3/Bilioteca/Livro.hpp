#ifndef Livro_HPP
#define Livro_HPP
#include <iostream>
#include <string>

class Livro
{
private:
    int _id;
    static int _prox_id;
    std ::string _titulo;
    std ::string _autor;
    int _anoPublicacao;
    std ::string _genero = "Livro";

public:

    Livro(std ::string titulo, std ::string autor, int anoPublicacao);
    virtual ~Livro();
    virtual void print_info();
    
    void set_genero(std ::string genero);
    int get_id();
};

#endif