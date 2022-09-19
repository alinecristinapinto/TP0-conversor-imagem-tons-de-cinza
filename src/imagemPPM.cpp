#include "imagemPPM.hpp"

ImagemPPM::ImagemPPM(){
  this->tipo = TIPO_ASCII_PPM;
}

void ImagemPPM::alocarAlturaPixMap(){
  this->pixmap = new struct Pixel*[this->altura];
  erroAssert(!(this->pixmap == NULL), "Erro ao alocar memoria para PixMap!");
}

void ImagemPPM::alocarLarguraPixMap(int i){
  this->pixmap[i] = new struct Pixel[this->largura];
  erroAssert(!(this->pixmap[i] == NULL), "Erro ao alocar memoria para PixMap!");
}

void ImagemPPM::ler(std::string nome_imagem){
  std::ifstream imagem(nome_imagem);
  erroAssert(imagem.is_open(), "Erro ao ler arquivo de entrada!");

  // Le header (3 primeiras linhas) e inicializa as propriedades
  imagem >> this->tipo >> this->largura >> this->altura >> this->valor_maximo;
  erroAssert(this->tipo == TIPO_ASCII_PPM, "Imagem de entrada nao possui formato .ppm");
  erroAssert(this->largura > 0, "Largura da imagem invalida");
  erroAssert(this->altura > 0, "Largura da imagem invalida");

  this->alocarAlturaPixMap();

  for (int i = 0; i < this->altura; i++) {
    this->alocarLarguraPixMap(i);

    for (int j = 0; j < this->largura; j++) {
      imagem >> this->pixmap[i][j].r >> this->pixmap[i][j].g >> this->pixmap[i][j].b;

      ESCREVEMEMLOG((long int) &this->pixmap[i][j].r, sizeof (int), MEMLOG_PPM_ID);
      ESCREVEMEMLOG((long int) &this->pixmap[i][j].g, sizeof (int), MEMLOG_PPM_ID);
      ESCREVEMEMLOG((long int) &this->pixmap[i][j].b, sizeof (int), MEMLOG_PPM_ID);
    }
  }

  imagem.close();
};

Pixel** ImagemPPM::getPixMap() const {
  return this->pixmap;
}
