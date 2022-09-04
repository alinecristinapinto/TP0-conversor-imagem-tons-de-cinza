#include "imagemPPM.hpp"

/**
* @brief Le a imagem em formato ppm e salva nos atributos
* 
* @param imagem - Arquivo da imagem
*/
void ImagemPPM::ler(FILE *imagem){
  char tipo[2];
  // Le header (3 primeiras linhas) e inicializa altura, largura e valor maximo
  fscanf(imagem, "%s\n %d %d\n %d", tipo, &this->largura, &this->altura, &this->valor_maximo);

  // Aloca memoria para pixmap
  this->pixmap = new struct Pixel*[this->altura];
  // erroAssert(this->pixmap == NULL, "Erro ao alocar memoria para PixMap!");

  for (int i = 0; i < this->altura; i++) {
    this->pixmap[i] = new struct Pixel[this->largura];
    // erroAssert(this->pixmap[i] == NULL, "Erro ao alocar memoria para PixMap!");
  }

  // Preenche a matriz pixmap
  for (int i = 0; i < this->altura; i++) {
    for (int j = 0; j < this->largura; j++) {
      fscanf(imagem, "%d %d %d ", &this->pixmap[i][j].r, &this->pixmap[i][j].g, &this->pixmap[i][j].b); 
    }
  }
};

void ImagemPPM::imprimirPixmap(){
  for (int i = 0; i < this->altura; i++) {
    for (int j = 0; j < this->largura; j++) {
      std::cout << this->pixmap[i][j].r << " " << this->pixmap[i][j].g << " " << this->pixmap[i][j].b << " ";
    }
    std::cout << std::endl;
  }
}

ImagemPPM::ImagemPPM(FILE *imagem){
    this->ler(imagem);
}
