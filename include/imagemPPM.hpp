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
   * @brief Le a imagem em formato ppm
   * 
   * @param nome_imagem - Nome da imagem
   */
  void ler(std::string nome_imagem);

  /**
   * @brief Imprime PixMap
   */
  void imprimirMap() override; 
  
 private:
  /**
   * @brief Matriz para PixMap
   */
  Pixel** pixmap;
};

#endif
