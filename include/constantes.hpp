#ifndef TIPO_IMAGEM_H
#define TIPO_IMAGEM_H

#include <string>

const std::string TIPO_ASCII_PGM = "P2";
const std::string TIPO_ASCII_PPM = "P3";

const std::string FORMATO_PGM = ".pgm";

const int VALOR_MAXIMO_TOM_CINZA_PGM = 49;

const int MEMLOG_PPM_ID = 0;
const int MEMLOG_PGM_ID = 1;

/**
 * @brief Representacao do RGB em pixels
 */
struct Pixel{
  int r, g, b;
};

#endif