#include "imagemPGM.hpp"

ImagemPGM::ImagemPGM(int altura, int largura){
  this->tipo = TIPO_ASCII_PGM;
  this->altura = altura;
  this->largura = largura;
  this->valor_maximo = VALOR_MAXIMO_TOM_CINZA_PGM;
}

void ImagemPGM::alocarAlturaGrayMap(){
  this->graymap = new int*[this->altura];
  erroAssert(!(graymap == NULL), "Erro ao alocar memoria para GrayMap!");
}

void ImagemPGM::alocarLarguraGrayMap(int i){
  this->graymap[i] = new int[this->largura];
  erroAssert(!(graymap[i] == NULL), "Erro ao alocar memoria para GrayMap!");
}

void ImagemPGM::setTom(int tom, int i, int j){
  this->graymap[i][j] = tom;
}

int** ImagemPGM::getGrayMap() const {
  return this->graymap;
}

void ImagemPGM::escrever(std::string nome_imagem){
  std::ofstream imagem;
  imagem.open(nome_imagem + FORMATO_PGM);
  erroAssert(imagem.is_open(), "Erro ao criar arquivo pgm!");

  imagem << this->tipo << std::endl; 
  imagem << this->largura << " " << this->altura << std::endl;
  imagem << this->valor_maximo << std::endl;

  for(int i=0; i<this->altura; i++){
    for(int j=0; j<this->largura; j++){
      if(j == this->largura - 1) imagem << this->graymap[i][j] << std::endl;
      else imagem << this->graymap[i][j] << " ";

      LEMEMLOG((long int) &this->graymap[i][j], sizeof (int), MEMLOG_PGM_ID);
    }
  }

  imagem.close();
};
