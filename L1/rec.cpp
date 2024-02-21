#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <numeric>
#include <limits>

using namespace std;
int main(int argc, char const *argv[])
{
    string frase, vogais;
    vector<string> palavras;
    string palavra;
    string palavraCorrigida;
    vector<string> palavrasComProblema;
    vector<string> palavrasCorrigidas;
    string fraseCorrigida;
    bool temProblema = false;
    
    cin.clear();
    cin >> vogais;
    fflush(stdin);
    getline(cin, frase);
    
    // Gera um vetor de strings com as palvavras da frase
    for (char c : frase)
    {
        if (c == ' ')
        {
            palavras.push_back(palavra);
            palavra.clear();
        }
        else
        {
            palavra += c;
        }
    }
    palavras.push_back(palavra);

    // Passa por cada palavra
    for (const string &p : palavras)
    {
        palavraCorrigida.clear();
        
        // Passa por cada letra de cada palavra
        for (char c : p)
        {
            // Se a letra for um * substitiu pela vogal respectiva e salva na string corrigida
            if (c == '*')
            {
                if (!vogais.empty())
                {
                    char vogal = vogais[0];
                    vogais = vogais.substr(1);
                    palavraCorrigida += vogal;
                    temProblema = true;
                }
                else
                {
                    palavraCorrigida += c;
                }
            }
            // Se realmente for uma letra, salva na string corrigida
            else
            {
                palavraCorrigida += c;
            }
        }
        
        // Apos passaar por toda a palavra, se havia algum *, salva a palavra no vetor de palavras com problema
        if (temProblema == true)
        {
            palavrasComProblema.push_back(palavraCorrigida);
            temProblema = false;
        }
        
        // Salva a palvra corrigda no vetor de palavras corrigidas
        palavrasCorrigidas.push_back(palavraCorrigida);
    }

    // Transforma o vetor de palavras corrigidas em uma so string (remonta a frase)
    for (const string &p : palavrasCorrigidas)
    {
        fraseCorrigida += p + " ";
    }
    
    
    // OUTPUT:
    cout << "Frase corrigida: " << fraseCorrigida << endl;
    cout << "Total de " << palavrasComProblema.size() << " palavra(s) com problema:\n";

    for (const string &p : palavrasComProblema)
    {
        cout << p << "\n";
    }

    return 0;
}
