#include "Biblioteca.hpp"

void Biblioteca::adicionarLivro(std::string titulo)
{
	livros[titulo] = new Livro(titulo);
}

void Biblioteca::emprestarLivro(std::string titulo, std::string usuario)
{
	if (livros.find(titulo) != livros.end())
	{
		if (livros[titulo]->estaDisponivel())
		{
			livros[titulo]->emprestar(usuario);
		}
		else
		{
			throw biblioteca_excp::ExcecaoLivroIndisponivel(titulo);
		}
	}
}

void Biblioteca::devolverLivro(std::string titulo, std::string usuario)
{
	if (livros.find(titulo) != livros.end())
	{
		if (!livros[titulo]->estaDisponivel() && livros[titulo]->getEmprestadoPara() == usuario)
		{
			livros[titulo]->devolver();
		}
		else
		{
			throw biblioteca_excp::ExcecaoDevolucaoNaoAutorizada(titulo, usuario);
		}
	}
}

void Biblioteca::listarLivros()
{
	std::cout << "Livros na Biblioteca:" << std::endl;
	for (auto const &livro : livros)
	{
		std::cout << livro.first << " - " << (livro.second->estaDisponivel() ? "Disponível" : "Indisponível") << std::endl;
	}
}
