#ifndef IMAGEM_H
#define IMAGEM_H

#include <iostream>
#include "msgassert.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de uma imagem.
 *
 */
class Imagem {
 public:
  /**
   * @brief Le a imagem
   * 
   * @param imagem - Arquivo da imagem
   */
  virtual void ler(FILE *imagem) = 0;

  /**
   * @brief Destrutor da classe
   *
   */
  virtual ~Imagem() = default;

 protected:
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
