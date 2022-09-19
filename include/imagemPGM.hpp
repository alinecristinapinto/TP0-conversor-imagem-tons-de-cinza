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
   * @brief Aloca memoria para altura de imagem .pgm
   */
  void alocarAlturaGrayMap();

  /**
   * @brief Aloca memoria para largura de imagem .pgm
   * 
   * @param i - Posição a ser alocada em relacao a altura da matriz
   */
  void alocarLarguraGrayMap(int i);

  /**
   * @brief Adiciona tom a graymap
   * 
   * @param tom - Tom de cinza
   * @param i - Posição referente a altura da matriz
   * @param j - Posição referente a largura da matriz
   */
  void setTom(int tom, int i, int j);

  /*
   * @brief Retorna graymap da imagem .pgm
   * 
   * @return int** Matriz de graymap
   */
  int** getGrayMap() const;

  /**
   * @brief Destrutor da classe
   */
  virtual ~ImagemPGM() = default;
  
 private:
  /**
   * @brief Matriz para GrayMap
   */
  int** graymap;
};

#endif
