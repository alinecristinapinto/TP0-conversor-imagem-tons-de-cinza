#include "imagemPPM.hpp"

ImagemPPM::ImagemPPM(){
  this->tipo = TIPO_ASCII_PPM;
}

void ImagemPPM::ler(std::string nome_imagem){
  std::ifstream imagem(nome_imagem);
  erroAssert(imagem.is_open(), "Erro ao ler arquivo de entrada!");

  // Le header e inicializa as propriedades
  imagem >> this->tipo >> this->largura >> this->altura >> this->valor_maximo;
  erroAssert(this->tipo == TIPO_ASCII_PPM, "Imagem de entrada nao possui formato .ppm");
  erroAssert(this->largura > 0, "Largura da imagem invalida");
  erroAssert(this->altura > 0, "Largura da imagem invalida");

  // Aloca memoria para pixmap e preenche valores
  this->pixmap = new struct Pixel*[this->altura];
  erroAssert(!(this->pixmap == NULL), "Erro ao alocar memoria para PixMap!");

  for (int i = 0; i < this->altura; i++) {
    this->pixmap[i] = new struct Pixel[this->largura];
    erroAssert(!(this->pixmap[i] == NULL), "Erro ao alocar memoria para PixMap!");

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
