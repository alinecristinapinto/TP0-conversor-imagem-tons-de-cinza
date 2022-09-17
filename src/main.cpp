//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Conversor de tons de cinza
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>

#include "memlog.hpp"
#include "msgassert.hpp" 

#include "imagemPPM.hpp" 
#include "imagemPGM.hpp" 
#include "conversorImagem.hpp"
#include "leitorLinhaComando.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    LeitorLinhaComando linha_comando;

    string nome_imagem_entrada = linha_comando.buscar_nome_imagem_entrada(argc, argv);
    string nome_imagem_saida = linha_comando.buscar_nome_imagem_saida(argc, argv); 
    string nome_memlog = linha_comando.buscar_nome_memlog(argc, argv); 
    bool ativar_registro_acesso = linha_comando.verificar_registro_acesso(argc, argv); 

    iniciaMemLog((char * ) nome_memlog.c_str());

    if (ativar_registro_acesso){ 
        ativaMemLog();
    } else {
        desativaMemLog();
    }

    ImagemPPM* ppm = new ImagemPPM();
    ppm->ler(nome_imagem_entrada);

    ConversorImagem conversor;
    ImagemPGM* pgm = conversor.converterImagemPPMParaPGM(*ppm);
  
    pgm->escrever(nome_imagem_saida);

    return finalizaMemLog();
}