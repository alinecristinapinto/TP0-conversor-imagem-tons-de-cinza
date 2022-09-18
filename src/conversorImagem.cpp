#include "conversorImagem.hpp"

int ConversorImagem::converterPixelParaTomCinza(Pixel pixel){
  double tom = (49.0 / 255.0) * 
               (0.3 * pixel.r + 0.59 * pixel.g + 0.11 * pixel.b);
  erroAssert(!(tom > VALOR_MAXIMO_TOM_CINZA_PGM || tom < 0), "Tom de cinza invalido!");

  LEMEMLOG((long int) &pixel.r, sizeof (int), MEMLOG_PPM);
  LEMEMLOG((long int) &pixel.g, sizeof (int), MEMLOG_PPM);
  LEMEMLOG((long int) &pixel.b, sizeof (int), MEMLOG_PPM);

  return int(tom);
}

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
      graymap[i][j] = converterPixelParaTomCinza(pixmap[i][j]);
      
      ESCREVEMEMLOG((long int) &graymap[i][j], sizeof (int), MEMLOG_PGM);
    }
  }

  return new ImagemPGM(imagemPPM.getAltura(), imagemPPM.getLargura(), graymap);
}