#include "imagemPPM.hpp"

ImagemPPM::ImagemPPM(){
  this->tipo = TIPO_ASCII_PPM;
}

void ImagemPPM::ler(std::string nome_imagem){
  std::ifstream imagem(nome_imagem);
  erroAssert(imagem.is_open(), "Erro ao ler arquivo de entrada!");

  // Le header (3 primeiras linhas) e inicializa tipo, altura, largura e valor maximo
  imagem >> this->tipo >> this->largura >> this->altura >> this->valor_maximo;

  // Aloca memoria para pixmap 
  this->pixmap = new struct Pixel*[this->altura];
  erroAssert(!(this->pixmap == NULL), "Erro ao alocar memoria para PixMap!");

  for (int i = 0; i < this->altura; i++) {
    this->pixmap[i] = new struct Pixel[this->largura];
    erroAssert(!(this->pixmap[i] == NULL), "Erro ao alocar memoria para PixMap!");
  }

  // Preenche valores no pixmap
  for (int i = 0; i < this->altura; i++) {
    for (int j = 0; j < this->largura; j++) {
      imagem >> this->pixmap[i][j].r >> this->pixmap[i][j].g >> this->pixmap[i][j].b;

      ESCREVEMEMLOG((long int) &this->pixmap[i][j].r, sizeof (int), 0);
      ESCREVEMEMLOG((long int) &this->pixmap[i][j].g, sizeof (int), 0);
      ESCREVEMEMLOG((long int) &this->pixmap[i][j].b, sizeof (int), 0);
    }
  }

  imagem.close();
};

Pixel** ImagemPPM::getPixMap() const {
  return this->pixmap;
}

void ImagemPPM::imprimirMap(){
  for (int i = 0; i < this->altura; i++) {
    for (int j = 0; j < this->largura; j++) {
      std::cout << this->pixmap[i][j].r << " " << this->pixmap[i][j].g << " " << this->pixmap[i][j].b << " ";
    }
    std::cout << std::endl;
  }
}
