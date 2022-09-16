#include "leitorLinhaComando.hpp"

#include <iostream>

std::string LeitorLinhaComando::buscar_argumento(int argc, char* argv[], std::string opcao) {
    std::string argumento = "";

    for(int i=0; i<argc; i++){
        if(argv[i] == opcao && (i+1)< argc) {
            argumento = argv[i + 1];
            return argumento;
        }; 
    }

    return argumento;
}

std::string LeitorLinhaComando::buscar_nome_imagem_entrada(int argc, char* argv[]) {
    std::string entrada = buscar_argumento(argc, argv, I_NOME_ARQUIVO_ENTRADA);
    erroAssert(entrada != "", "Nome do arquivo de entrada obrigatorio!");

    return entrada;
}

std::string LeitorLinhaComando::buscar_nome_imagem_saida(int argc, char* argv[]) {
    std::string saida = buscar_argumento(argc, argv, O_NOME_ARQUIVO_SAIDA);
    erroAssert(saida != "", "Nome do arquivo de saida obrigatorio!");

    return saida;
}
