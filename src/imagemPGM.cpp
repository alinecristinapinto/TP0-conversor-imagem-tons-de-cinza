#include "imagemPGM.hpp"

ImagemPGM::ImagemPGM(){
  this->tipo = TIPO_ASCII_PGM;
  this->valor_maximo = VALOR_MAXIMO_TOM_CINZA_PGM;
}

ImagemPGM::ImagemPGM(int altura, int largura, int** graymap){
  this->tipo = TIPO_ASCII_PGM;
  this->altura = altura;
  this->largura = largura;
  this->graymap = graymap;
  this->valor_maximo = VALOR_MAXIMO_TOM_CINZA_PGM;
}

void ImagemPGM::escrever(std::string nome_imagem){
  std::ofstream imagem;
  imagem.open(nome_imagem + FORMATO_PGM);
  erroAssert(imagem, "Erro na criacao do arquivo!");

  imagem << this->tipo << std::endl; 
  imagem << this->largura << " " << this->altura << std::endl;
  imagem << this->valor_maximo << std::endl;

  for(int i=0; i<this->altura; i++){
    for(int j=0; j<this->largura; j++){
      if(j == this->largura - 1) imagem << this->graymap[i][j] << std::endl;
      else imagem << this->graymap[i][j] << " ";
    }
  }

  imagem.close();
};

void ImagemPGM::imprimirMap(){
  for (int i = 0; i < this->altura; i++) {
    for (int j = 0; j < this->largura; j++) {
      std::cout << this->graymap[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

