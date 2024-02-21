#include "Livro.hpp"

Livro::Livro(std::string titulo) : _titulo(titulo), _disponivel(true), _emprestado_para("") {}

bool Livro::estaDisponivel() { return _disponivel; }

std::string Livro::getTitulo() { return _titulo; }

std::string Livro::getEmprestadoPara() { return _emprestado_para; }

void Livro::emprestar(std::string usuario)
{
	if (_disponivel)
	{
		_disponivel = false;
		_emprestado_para = usuario;
	}
}

void Livro::devolver()
{
	_disponivel = true;
	_emprestado_para = "";
}
