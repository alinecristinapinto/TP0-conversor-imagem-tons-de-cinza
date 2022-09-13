#include "conversorImagem.hpp"

ImagemPGM* ConversorImagem::converterImagemPPMParaPGM(const ImagemPPM& imagemPPM){
  Pixel** aux_pixmap = imagemPPM.getPixMap();
  TomCinza** aux_graymap;

  // Aloca memoria para graymap 
  aux_graymap = new struct TomCinza*[imagemPPM.getAltura()];
  erroAssert(!(aux_graymap == NULL), "Erro ao alocar memoria para GrayMap!");

  for (int i = 0; i < imagemPPM.getAltura(); i++) {
    aux_graymap[i] = new struct TomCinza[imagemPPM.getLargura()];
    erroAssert(!(aux_graymap[i] == NULL), "Erro ao alocar memoria para GrayMap!");
  }

  // Preenche valores no graymap
  for (int i = 0; i < imagemPPM.getAltura(); i++) {
    for (int j = 0; j < imagemPPM.getLargura(); j++) {
      aux_graymap[i][j].valor = (49/255) * (0.3 * aux_pixmap[i][j].r +
      							   0.59 * aux_pixmap[i][j].g +
      							   0.11 * aux_pixmap[i][j].b);
    }
  }

  return new ImagemPGM(imagemPPM.getAltura(), imagemPPM.getLargura(), aux_graymap);
}