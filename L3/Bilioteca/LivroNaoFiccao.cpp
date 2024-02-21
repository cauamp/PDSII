#include "LivroNaoFiccao.hpp"
LivroNaoFiccao ::LivroNaoFiccao(std ::string titulo, std ::string autor, int anoPublicacao, std ::string assunto) : Livro(titulo, autor, anoPublicacao), _assunto(assunto)
{
    this->set_genero("NaoFiccao");
}
LivroNaoFiccao ::~LivroNaoFiccao()
{
    std ::cout << "Destrutor LivroNaoFiccao" << std ::endl;
}
void LivroNaoFiccao ::print_info()
{
    Livro ::print_info();
    std ::cout << "\tAssunto: " << this->_assunto << std ::endl;
}