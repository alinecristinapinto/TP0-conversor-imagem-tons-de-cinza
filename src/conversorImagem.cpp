#include "conversorImagem.hpp"

int ConversorImagem::converterPixelParaTomCinza(const Pixel& pixel){
  double tom = (49.0 / 255.0) * 
               (0.3 * pixel.r + 0.59 * pixel.g + 0.11 * pixel.b);
  erroAssert(!(tom > VALOR_MAXIMO_TOM_CINZA_PGM || tom < 0), "Tom de cinza invalido!");

  LEMEMLOG((long int) &pixel.r, sizeof (int), MEMLOG_PPM_ID);
  LEMEMLOG((long int) &pixel.g, sizeof (int), MEMLOG_PPM_ID);
  LEMEMLOG((long int) &pixel.b, sizeof (int), MEMLOG_PPM_ID);

  return (int) tom;
}

ImagemPGM* ConversorImagem::converterImagemPPMParaPGM(const ImagemPPM& imagemPPM){
  ImagemPGM* pgm = new ImagemPGM(imagemPPM.getAltura(), imagemPPM.getLargura());

  pgm->alocarAlturaGrayMap();

  for (int i = 0; i < imagemPPM.getAltura(); i++) {
    pgm->alocarLarguraGrayMap(i);
    
    for (int j = 0; j < imagemPPM.getLargura(); j++) {
      pgm->setTom(converterPixelParaTomCinza(imagemPPM.getPixMap()[i][j]), i, j);
      
      ESCREVEMEMLOG((long int) &pgm->getGrayMap()[i][j], sizeof (int), MEMLOG_PGM_ID);
    }
  }

  return pgm;
}