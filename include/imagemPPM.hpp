#ifndef IMAGEMPPM_H
#define IMAGEMPPM_H

#include "imagem.hpp"

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de uma imagem em formato .ppm.
 */
class ImagemPPM : public Imagem {
 public:
  /**
   * @brief Construtor default
   */
  ImagemPPM();

  /**
   * @brief Le a imagem em formato ppm
   * 
   * @param nome_imagem - Nome da imagem
   */
  void ler(std::string nome_imagem);

  /**
   * @brief Aloca memoria para altura de imagem .ppm
   */
  void alocarAlturaPixMap();

  /**
   * @brief Aloca memoria para largura de imagem .ppm
   * 
   * @param i - Posição a ser alocada em relacao a altura da matriz
   */
  void alocarLarguraPixMap(int i);

  /*
   * @brief Retorna pixmap da imagem .ppm
   * 
   * @return Pixel** Matriz de pixmap
   */
  Pixel** getPixMap() const;

  /**
   * @brief Destrutor da classe
   */
  virtual ~ImagemPPM() = default;
  
 private:
  /**
   * @brief Matriz para PixMap
   */
  Pixel** pixmap;
};

#endif
