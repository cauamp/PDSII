#include "ConversorMoedas.hpp"

void ConversorMoedas::definirTaxaCambio(std::string de, std::string para, double taxa)
{
	if (taxa < 0)
	{
		throw cexc::valor_invalido();
	}
	if (!checarMoedaValida(de) || !checarMoedaValida(para))
	{
		throw cexc::moeda_invalida();
	}
	this->taxasCambio[de + para] = taxa;
}

bool ConversorMoedas::checarMoedaValida(std::string moeda)
{
	for (const auto &moedaValida : this->MOEDAS_VALIDAS)
	{
		if (moedaValida == moeda)
		{
			return true;
		}
	}
	return false;
}

bool ConversorMoedas::possuiTaxaCambio(std::string de, std::string para)
{
	return this->taxasCambio.find(de + para) != this->taxasCambio.end();
}

double ConversorMoedas::converter(std::string de, std::string para, double valor)
{
	if (valor < 0)
	{
		throw cexc::valor_invalido();
	}
	if (!(checarMoedaValida(de) && checarMoedaValida(para)))
	{
		throw cexc::moeda_invalida();
	}
	if (!possuiTaxaCambio(de, para))
	{
		throw cexc::conversao_inexistente();
	}
	return valor * this->taxasCambio[de + para];
}
