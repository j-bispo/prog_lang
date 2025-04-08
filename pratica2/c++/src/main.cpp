
#include <iostream>
#include "./include/list.h"

int main() {

    char comma;
    float altura, peso;

    std::cout << "Informe sua altura e peso para o calculo do IMC: ";
    std::cin >> altura >> comma >> peso;

    calc_health(altura, peso);

    return 0;
}