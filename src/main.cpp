//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : Conversor de tons de cinza
// Autor        : Aline Cristina Pinto (alinecristinapinto@ufmg.br)
//---------------------------------------------------------------------

#include <iostream>

#include "msgassert.hpp" 
#include "imagemPPM.hpp" 
#include "imagemGM.hpp" 

using namespace std;

void imprimirOpcoes(){
    cout << "\t Conversor de imagem para tons de cinza" << endl;
    cout << "-i <nome_do_arquivo_entrada> - (entrada em formato .ppm)" << endl;
    cout << "-o <nome_do_arquivo_saida> - (entrada em formato .pgm)" << endl;
    cout << "-p - registro de desempenho" << endl;
    cout << "-l - padrão de acesso e localidade" << endl;
}

int main(int argc, char* argv[]) {
    imprimirOpcoes();

    ImagemPPM ppm;
    ppm.ler("img-samples/bolao.ppm");
    ppm.imprimirMap();

    ImagemPPM pgm;
    pgm.escrever("img-samples/balao-convertido.pgm");
    pgm.imprimirMap();

    return 0;
}