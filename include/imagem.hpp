#ifndef IMAGEM_H
#define IMAGEM_H

#include <iostream>
#include <fstream>
#include "tipoImagem.hpp"
#include "msgassert.hpp"

/**
 * @brief Representacao do RGB em pixels
 */
struct Pixel{
  int r, g, b;
};

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de uma imagem.
 *
 */
class Imagem {
 public:
  // /**
  //  * @brief Le a imagem
  //  * 
  //  * @param imagem - Arquivo da imagem
  //  */
  // virtual void ler(FILE *imagem) {};

  // /**
  //  * @brief Escreve a imagem
  //  */
  // virtual void escrever() {};

  /*
   * @brief Retorna altura da imagem
   * 
   * @return int Altura da imagem
   */
  int getAltura() const { return this->altura; }

  /*
   * @brief Retorna largura da imagem
   * 
   * @return int Largura da imagem
   */
  int getLargura() const { return this->largura; }

  /**
   * @brief Imprime o map da imagem
   */
  virtual void imprimirMap() = 0;

  /**
   * @brief Destrutor da classe
   */
  virtual ~Imagem() = default;

 protected:
  /**
   * @brief Tipo da imagem em ASCII. Ex: P1, P2 ou P3
   */
  std::string tipo;

  /**
   * @brief Altura da imagem 
   */
  int altura;

  /**
   * @brief Largura da imagem
   */
  int largura;

  /**
   * @brief Valor maximo 
   */
  int valor_maximo;
};

#endif
