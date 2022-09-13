#ifndef TIPO_IMAGEM_H
#define TIPO_IMAGEM_H

#include <string>

const std::string TIPO_ASCII_PGM = "P2";
const std::string TIPO_ASCII_PPM = "P3";

const int VALOR_MAXIMO_TOM_CINZA_PGM = 49;

/**
 * @brief Representacao do RGB em pixels
 */
struct Pixel{
  int r, g, b;
};

#endif