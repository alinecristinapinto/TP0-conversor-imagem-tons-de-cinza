#include "leitorLinhaComando.hpp"

#include <iostream>

std::string LeitorLinhaComando::buscar_argumento(int argc, char* argv[], std::string opcao) {
    std::string argumento = "";

    for(int i=0; i<argc; i++){
        if(argv[i] == opcao && (i+1)< argc) {
            argumento = argv[i + 1];
        }; 
    }

    return argumento;
}

std::string LeitorLinhaComando::buscar_nome_imagem_entrada(int argc, char* argv[]) {
    std::cout << argc << std::endl;
    std::cout << *argv << std::endl;

    for(int i=0; i<argc; i++){
        if(argv[i] == I_NOME_ARQUIVO_ENTRADA) return argv[i + 1]; 
    }

    return "";
}

std::string LeitorLinhaComando::buscar_nome_imagem_saida(int argc, char* argv[]) {
    return "";
}
