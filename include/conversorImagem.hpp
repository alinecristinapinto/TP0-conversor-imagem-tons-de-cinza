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
   * @param imagemPPM Imagem em formato .ppm que será convertida
   * @return ImagemPGM* Imagem em formato .pgm
   */
  static ImagemPGM* converterImagemPPMParaPGM(const ImagemPPM& imagemPPM);

  private:
  /**
   * @brief Converte pixel em tom de cinza
   * 
   * @param pixel Pixel em forato rgb
   * @return int Tom de cinza convertido
   */
  static int converterPixelParaTomCinza(Pixel pixel);
};

#endif