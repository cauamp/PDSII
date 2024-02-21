#include <iostream>
#include <string>
#include "Biblioteca.hpp"
#include "Livro.cpp"
#include "LivroInfantil.cpp"
#include "LivroFiccao.cpp"
#include "LivroNaoFiccao.cpp"
#include "Biblioteca.cpp"

int main()
{
    Biblioteca biblioteca;

    std::string comando;
    while (std::cin >> comando)
    {
        switch (comando[0])
        {
        case 'a':
            if (comando == "add_f")
            {
                std::string titulo, autor, subgenero;
                int anoPublicacao;
                std::cin >> titulo >> autor >> anoPublicacao >> subgenero;

                LivroFiccao *novo = new LivroFiccao(titulo, autor, anoPublicacao, subgenero);
                biblioteca.add_livro(novo);
            }
            else if (comando == "add_nf")
            {
                std::string titulo, autor, assunto;
                int anoPublicacao;
                std::cin >> titulo >> autor >> anoPublicacao >> assunto;

                LivroNaoFiccao *novo = new LivroNaoFiccao(titulo, autor, anoPublicacao, assunto);
                biblioteca.add_livro(novo);
            }
            else if (comando == "add_i")
            {
                std::string titulo, autor;
                int faixaEtariaMinima;
                int anoPublicacao;
                std::cin >> titulo >> autor >> anoPublicacao >> faixaEtariaMinima;

                LivroInfantil *novo = new LivroInfantil(titulo, autor, anoPublicacao, faixaEtariaMinima);
                biblioteca.add_livro(novo);
            }
            break;
        case 'r':
            if (comando == "rm")
            {
                int id;
                std::cin >> id;
                biblioteca.remove_livro(id);
            }
            break;
        case 'f':
            if (comando == "find")
            {
                int id;
                std::cin >> id;
                biblioteca.find_livro(id);
            }
            break;
        case 'l':
            if (comando == "list")
            {
                biblioteca.list_livros();
            }
            break;
        case '\n':
            std::cout << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}
