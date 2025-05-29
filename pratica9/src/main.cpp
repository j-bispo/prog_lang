#include "./include/pessoa.hpp"
#include "./include/empregado.hpp"
#include "./include/empresa.hpp"
#include "./include/microempreendedor.hpp"

int main() {
    Pessoa p("Lucas", 30, 987654321);
    Empregado e("Luis", 23, 1000.00);
    MicroEmpreendedor mei("João", 123456789, 159);
    Empresa empresa(357);

    p.exibe();
    e.exibe();
    mei.exibe();
    empresa.exibe();

    return 0;
}