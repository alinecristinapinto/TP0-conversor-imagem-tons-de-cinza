//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Conversor de tons de cinza
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>
#include <getopt.h>

#include "imagemPPM.hpp" 
#include "imagemPGM.hpp" 
#include "conversorImagem.hpp"

#include "constantesTerminal.hpp"
#include "msgassert.h" 
#include "memlog.h"

using namespace std;

void parse_args(int argc, char* argv[]) {
    cout << *argv << endl;
}

int main(int argc, char* argv[]) {
    parse_args(argc, argv);

    ImagemPPM* ppm = new ImagemPPM();
    ppm->ler("img-samples/bolao.ppm");

    ConversorImagem conversor;
    ImagemPGM* pgm = conversor.converterImagemPPMParaPGM(*ppm);
  
    pgm->escrever("img-samples/balao-convertido.pgm");

    return 0;
}