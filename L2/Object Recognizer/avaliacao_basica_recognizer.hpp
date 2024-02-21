#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include "Recognizer.hpp"

using namespace std;

void avaliacao_basica() {
    
    Recognizer recognizer;

    cout << "----------" << endl;

    recognizer.print_dataset_summary("DA");

    cout << "----------" << endl;

    recognizer.add_dataset("DA");
    recognizer.print_dataset_summary("DA");
    
    recognizer.add_object("DA", "OA3", {3.23, 6.56, 9.89});
    recognizer.add_object("DA", "OA2", {2.23, 5.56, 8.89});
    recognizer.add_object("DA", "OA1", {1.23, 4.56, 7.89});
    
    recognizer.print_dataset_summary("DA");

    cout << "----------" << endl;

    recognizer.add_object("DB", "OB1", {1.11, 2.22, 3.33});
    recognizer.print_dataset_summary("DB");    

    cout << "----------" << endl;

    recognizer.print_dataset_summary("DC");

    cout << "----------" << endl;

    recognizer.remove_object("DA", "OA1");
    recognizer.print_dataset_summary("DA");
    
    recognizer.remove_object("DA", "OA2");
    recognizer.print_dataset_summary("DA");

    cout << "----------" << endl;

    double d = recognizer.calc_vector_distance({0.0}, {2.0});
    cout << d << endl;

    d = recognizer.calc_vector_distance({0.0, 0.0}, {2.0, 2.0});
    cout << d << endl;

    d = recognizer.calc_vector_distance({0.0, 0.0, 0.0}, {2.0, 2.0, 2.0});
    cout << d << endl;

    cout << "----------" << endl;

    recognizer.add_object("DA", "OA4", {2.23, 5.56, 8.89});
    recognizer.add_object("DA", "OA5", {1.23, 4.56, 7.89});

    recognizer.recognize_object("DA", {{2.20, 5.46, 8.69}});

    recognizer.remove_object("DA", "OA4");

    recognizer.recognize_object("DA", {{2.20, 5.46, 8.69}});

    cout << "----------" << endl;

}

#endif