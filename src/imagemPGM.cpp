#include "imagemPGM.hpp"

// double converterRGBParaCinza(Pixel * pixel){
// 	double y = (49/255) * (0.3 * pixel->r + 0.59 * pixel->g + 0.11 * pixel->b);
// 	erroAssert(y > this->valor_maximo, "Mais de 50 tons de cinza!");

// 	return y;
// }

void ImagemPGM::converterDePixMap(int altura, int largura, Pixel **pixmap){
  this->altura = altura;
  this->largura = largura;

  // Aloca memoria para graymap 
  this->graymap = new std::string*[this->altura];
  erroAssert(!(this->graymap == NULL), "Erro ao alocar memoria para GrayMap!");

  for (int i = 0; i < this->altura; i++) {
    this->graymap[i] = new std::string[this->largura];
    erroAssert(!(this->graymap[i] == NULL), "Erro ao alocar memoria para GrayMap!");
  }

  // Preenche valores no pixmap
  for (int i = 0; i < this->altura; i++) {
    for (int j = 0; j < this->largura; j++) {
      graymap[i][j] = (49/255) * (0.3 * this->pixmap[i][j].r +
      							  0.59 * this->pixmap[i][j].g +
      							  0.11 * this->pixmap[i][j].b);
    }
  }

}

void ImagemPGM::escrever(std::string nome_imagem){
  ofstream imagem;
  imagem.open(nome_imagem);
  erroAssert(imagem, "Erro na criacao do arquivo!");


  imagem.close();
};

void ImagemPGM::imprimirMap(){

}

