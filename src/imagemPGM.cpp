#include "imagemPGM.hpp"

ImagemPGM::ImagemPGM(){
  this->tipo = TIPO_ASCII_PGM;
}

ImagemPGM::ImagemPGM(int altura, int largura){
  this->tipo = TIPO_ASCII_PGM;
  this->altura = altura;
  this->largura = largura;
}

void ImagemPGM::escrever(std::string nome_imagem){
  std::ofstream imagem;
  imagem.open(nome_imagem);
  erroAssert(imagem, "Erro na criacao do arquivo!");


  imagem.close();
};

void ImagemPGM::imprimirMap(){
  std::cout << " altura " << this->altura  << std::endl;
  std::cout << " largura " << this->largura  << std::endl;
  // for (int i = 0; i < this->altura; i++) {
  //   for (int j = 0; j < this->largura; j++) {
  //     std::cout << this->graymap[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
}

