#include "conversorImagem.hpp"

ImagemPGM* ConversorImagem::converterImagemPPMParaPGM(const Imagem& imagemPPM){
  // ImagemPGM* imagemPGM = new ImagemPGM(imagemPPM.altura, imagemPPM.largura);

  // // Aloca memoria para graymap 
  // this->graymap = new std::string*[this->altura];
  // erroAssert(!(this->graymap == NULL), "Erro ao alocar memoria para GrayMap!");

  // for (int i = 0; i < this->altura; i++) {
  //   this->graymap[i] = new std::string[this->largura];
  //   erroAssert(!(this->graymap[i] == NULL), "Erro ao alocar memoria para GrayMap!");
  // }

  // // Preenche valores no pixmap
  // for (int i = 0; i < this->altura; i++) {
  //   for (int j = 0; j < this->largura; j++) {
  //     graymap[i][j] = (49/255) * (0.3 * pixmap[i][j].r +
  //     							   0.59 * pixmap[i][j].g +
  //     							   0.11 * pixmap[i][j].b);
  //   }
  // }

  return new ImagemPGM(600, 500);
}