#ifndef CONVERSOR_IMAGEM_H
#define CONVERSOR_IMAGEM_H

#include "imagemPPM.hpp" 
#include "imagemPGM.hpp" 

/**
 * @brief Classe responsavel por converter formatos de imagem
 */
class ConversorImagem {
  public:
  /**
   * @brief Converte uma imagem .ppm para .pgm
   * 
   * @param imagemPPM Imagem .ppm que será convertida
   * @return ImagemPGM* Imagem .pgm
   */
  ImagemPGM* converterImagemPPMParaPGM(const Imagem& imagemPPM);
};

#endif