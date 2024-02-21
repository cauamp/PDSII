#include "ConversorMoedas.hpp"
#include "doctest.h"

TEST_CASE("Teste de definirTaxaCambio") {
    ConversorMoedas conversor;
    conversor.definirTaxaCambio("USD", "BRL", 5.3);
    CHECK(conversor.possuiTaxaCambio("USD", "BRL") == true);
}

TEST_CASE("Teste de checarMoedaValida true") {
    ConversorMoedas conversor;
    CHECK(conversor.checarMoedaValida("BRL") == true);
}

TEST_CASE("Teste de checarMoedaValida false") {
    ConversorMoedas conversor;
    CHECK(conversor.checarMoedaValida("JPY") == false);
}


TEST_CASE("Teste de converter") {
    ConversorMoedas conversor;
    conversor.definirTaxaCambio("USD", "BRL", 5.3);
    CHECK(conversor.converter("USD", "BRL", 100) == doctest::Approx(530));
}

TEST_CASE("Teste de exceção de valor inválido ao definir taxa de câmbio") {
    ConversorMoedas conversor;
    CHECK_THROWS_AS(conversor.definirTaxaCambio("USD", "BRL", -1), cexc::valor_invalido);
}

TEST_CASE("Teste de exceção de moeda inválida ao definir taxa de câmbio") {
    ConversorMoedas conversor;
    CHECK_THROWS_AS(conversor.definirTaxaCambio("AAA", "BRL", 2), cexc::moeda_invalida);
}

TEST_CASE("Teste de exceção de conversão inexistente") {
    ConversorMoedas conversor;
    CHECK_THROWS_AS(conversor.converter("USD", "JPY", 100), cexc::conversao_inexistente);
}

TEST_CASE("Teste de definirTaxaCambio para mesma moeda") {
    ConversorMoedas conversor;
    CHECK_THROWS_AS(conversor.definirTaxaCambio("USD", "USD", 1.0), cexc::conversao_inexistente);
}

TEST_CASE("Teste de exceção de valor inválido ao converter") {
    ConversorMoedas conversor;
    CHECK_THROWS_AS(conversor.converter("USD", "USD", -100), cexc::valor_invalido);
}

TEST_CASE("Teste de exceção de conversão inexistente ao converter") {
    ConversorMoedas conversor;
    CHECK_THROWS_AS(conversor.converter("JPY", "BRL", 100), cexc::conversao_inexistente);
}
