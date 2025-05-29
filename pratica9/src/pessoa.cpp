#include "./include/pessoa.hpp"

Pessoa::Pessoa(const std::string& nome, int idade, int cpf) : nome(nome), idade(idade), cpf(cpf) {}

const std::string& Pessoa::pega_nome() {
    return nome;
}

void Pessoa::exibe() {
    std::cout << "Informações:" << std::endl << "Pessoa: " << nome << std::endl << "Idade: " << idade << std::endl << "CPF: " << cpf << std::endl << std::endl;
}

Pessoa::~Pessoa() {
    std::cout << "Destruindo Pessoa: " << nome << std::endl;
}