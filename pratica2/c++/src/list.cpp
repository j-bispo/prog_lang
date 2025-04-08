
#include <iostream>
#include "./include/list.h"

void calc_health(float height, float weight){

    float imc;

    imc = weight / (height * height);

    std::cout << "Your IMC is " << imc << std::endl;

    if(imc <= 22){
        std::cout << "You are on low weight." << std::endl;
    }

    if(imc > 22 && imc < 25){
        std::cout << "You are on normal weight." << std::endl;
    }

    if(imc > 25 && imc < 30){
        std::cout << "You are on over weight." << std::endl;
    }

    if(imc >= 30){
        std::cout << "You are on obesidade." << std::endl;
    }
}