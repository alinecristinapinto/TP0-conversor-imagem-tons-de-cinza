#include "leitorLinhaComando.hpp"

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

bool LeitorLinhaComando::verificar_parametro_presente(int argc, char* argv[], std::string parametro){
    for(int i=0; i<argc; i++){
        if(argv[i] == parametro) return true;
    }

    return false;
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

std::string LeitorLinhaComando::buscar_nome_memlog(int argc, char* argv[]){
    std::string registro = buscar_argumento(argc, argv, P_REGISTRO_DESEMPENHO);
    erroAssert(registro != "", "Nome do arquivo para registro de desemprenho obrigatorio!");

    return registro;
}

bool LeitorLinhaComando::verificar_registro_acesso(int argc, char* argv[]){
    return verificar_parametro_presente(argc, argv, L_PADRAO_ACESSO_LOCALIDADE);
}
