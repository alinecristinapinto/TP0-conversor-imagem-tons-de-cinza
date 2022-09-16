//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Conversor de tons de cinza
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>

#include "imagemPPM.hpp" 
#include "imagemPGM.hpp" 
#include "conversorImagem.hpp"
#include "leitorLinhaComando.hpp"

#include "memlog.h"
#include "msgassert.h" 

using namespace std;

int main(int argc, char* argv[]) {
    LeitorLinhaComando linha_comando;

    string nome_imagem_entrada = linha_comando.buscar_nome_imagem_entrada(argc, argv);
    string nome_imagem_saida = linha_comando.buscar_nome_imagem_saida(argc, argv); 

    char nome_log[20] = "log.out";
    iniciaMemLog(nome_log);

    ImagemPPM* ppm = new ImagemPPM();
    ppm->ler(nome_imagem_entrada);

    ConversorImagem conversor;
    ImagemPGM* pgm = conversor.converterImagemPPMParaPGM(*ppm);
  
    pgm->escrever(nome_imagem_saida);

    return 0;
}