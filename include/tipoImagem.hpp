#ifndef TIPO_IMAGEM_H
#define TIPO_IMAGEM_H

#include <string>

const std::string TIPO_ASCII_PGM = "P2";
const std::string TIPO_ASCII_PPM = "P3";

/**
 * @brief Representacao do RGB em pixels
 */
struct Pixel{
  int r, g, b;
};

/**
 * @brief Representacao dos tons de cinza
 */
struct TomCinza{
  int valor, tom_maximo;
};

#endif