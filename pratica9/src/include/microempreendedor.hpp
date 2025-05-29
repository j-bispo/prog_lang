#ifndef MICROEMPREENDEDOR_HPP
#define MICROEMPREENDEDOR_HPP

#include "pessoa.hpp"
#include "empresa.hpp"

class MicroEmpreendedor : public Pessoa, public Empresa {
private:
public:
    MicroEmpreendedor(const std::string& nome, int cpf, int cnpj);
    void exibe();
    virtual ~MicroEmpreendedor();
};

#endif /* MICROEMPREENDEDOR_HPP */