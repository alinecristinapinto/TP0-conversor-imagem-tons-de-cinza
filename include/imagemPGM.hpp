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
   * @param nome_imagem - Nome da imagem
   */
  void escrever(std::string nome_imagem);

  /**
   * @brief Converte uma imagem ppm para o formato pgm
   * 
   * @param nome_imagem - Nome da imagem
   */
  void converterDePixMap(int altura, int largura, Pixel **pixmap);

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
