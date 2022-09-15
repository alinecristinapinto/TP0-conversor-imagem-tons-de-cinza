#include "conversorImagem.hpp"

ImagemPGM* ConversorImagem::converterImagemPPMParaPGM(const ImagemPPM& imagemPPM){
  Pixel** pixmap = imagemPPM.getPixMap();
  int** graymap;

  // Aloca memoria para graymap 
  graymap = new int*[imagemPPM.getAltura()];
  erroAssert(!(graymap == NULL), "Erro ao alocar memoria para GrayMap!");

  for (int i = 0; i < imagemPPM.getAltura(); i++) {
    graymap[i] = new int[imagemPPM.getLargura()];
    erroAssert(!(graymap[i] == NULL), "Erro ao alocar memoria para GrayMap!");
  }

  // Preenche valores no graymap
  for (int i = 0; i < imagemPPM.getAltura(); i++) {
    for (int j = 0; j < imagemPPM.getLargura(); j++) {
      double tom = (49.0 / 255.0) * 
                   (0.3 * pixmap[i][j].r + 0.59 * pixmap[i][j].g + 0.11 * pixmap[i][j].b);
      erroAssert(!(tom > VALOR_MAXIMO_TOM_CINZA_PGM || tom < 0), "Tom de cinza invalido!");
      
      graymap[i][j] = int(tom);
    }
  }

  return new ImagemPGM(imagemPPM.getAltura(), imagemPPM.getLargura(), graymap);
}