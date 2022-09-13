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
   * @brief Construtor default
   */
  ImagemPGM();

  /**
   * @brief Construtor que inicializa algumas variaveis da classe.
   *
   * @param altura Altura da imagem
   * @param largura Largura da imagem
   */
  ImagemPGM(int altura, int largura);

  /**
   * @brief Escreve a imagem em formato pgm
   * 
   * @param nome_imagem - Nome da imagem
   */
  void escrever(std::string nome_imagem);

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
