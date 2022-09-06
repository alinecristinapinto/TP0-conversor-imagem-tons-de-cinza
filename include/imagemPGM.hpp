#ifndef IMAGEMPGM_H
#define IMAGEMPGM_H

#include "imagem.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de uma imagem em formato .pgm.
 */
class ImagemPGM : public Imagem {
 public:
  /**
   * @brief Escreve a imagem em formato pgm
   * 
   * @param imagem - Arquivo da imagem
   */
  void escrever();

  /**
   * @brief Imprime GrayMap
   */
  void imprimirMap() override;
  
 private:
  /**
   * @brief Matriz para GrayMap
   */
  std::string** graymap;
};

#endif
