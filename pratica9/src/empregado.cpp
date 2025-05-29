#include "./include/empregado.hpp"

Empregado::Empregado(const std::string& nome, int idade, double salario): Pessoa(nome, idade, cpf), salario(salario) {}

void Empregado::exibe() {
    std::cout << "Informações:" << std::endl << "Empregado: " << nome << std::endl << "Idade: " << idade << std::endl << "Salário: " << salario << std::endl << std::endl;
}

Empregado::~Empregado() {
    std::cout << "Destruindo Empregado " << std::endl;
}