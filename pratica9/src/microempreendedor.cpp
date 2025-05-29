#include "./include/microempreendedor.hpp"

MicroEmpreendedor::MicroEmpreendedor(const std::string& nome, int cpf, int cnpj): Pessoa(nome, idade, cpf), Empresa(cnpj) {}

void MicroEmpreendedor::exibe() {
    std::cout << "Informações:" << std::endl << "Microempreendedor: " << nome << std::endl << "CPF: " << cpf << std::endl << "CNPJ: " << cnpj << std::endl << std::endl;
}

MicroEmpreendedor::~MicroEmpreendedor() {
    std::cout << "Destruindo Microempreendedor " << std::endl;
}

