#include <iostream>
#include "Dataset.hpp"
#include "Object.hpp"
#include "Recognizer.hpp"
#include "avaliacao_basica_recognizer.hpp"
#include <vector>
#include <list>
#include <string>

int main()
{

    Recognizer recognizer = Recognizer();
    char comando;
    std ::string category;

    while (std ::cin >> comando)
    { // Lendo o caractere que define o comando

        // Executando o comando informado
        switch (comando)
        {

        case 'd':
        {
            std ::cin >> category;
            recognizer.add_dataset(category);
            break;
        }
        case 'o':
        {
            std ::cin >> category;

            std ::string name;
            int vsize;
            std ::cin >> name >> vsize;
            std::vector<double> featureVector;

            for (int i = 0; i < vsize; i++)
            {
                double num;
                std ::cin >> num;
                featureVector.push_back(num);
            }
            recognizer.add_object(category, name, featureVector);
            break;
        }

        case 'm':
        {
            std ::cin >> category;

            std ::string name;
            std ::cin >> name;
            recognizer.remove_object(category, name);
            break;
        }
        case 'p':
        {
            std ::cin >> category;

            recognizer.print_dataset_summary(category);
            break;
        }
        case 'r':
        {
            std ::cin >> category;

            int vsize;
            std ::cin >> vsize;
            std::vector<double> featureVector;

            for (int i = 0; i < vsize; i++)
            {
                double num;
                std ::cin >> num;
                featureVector.push_back(num);
            }
            recognizer.recognize_object(category, featureVector);
            break;
        }
        case 'b':
        {
            avaliacao_basica();
            break;
        }
        }
    }
    return 0;
}
