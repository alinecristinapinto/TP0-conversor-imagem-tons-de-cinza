#ifndef IMAGEMPPM_H
#define IMAGEMPPM_H

#include "imagem.hpp"

/**
 * @brief Representacao do RGB em pixels
 */
struct Pixel{
  int r, g, b;
};

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das informacoes
 * de uma imagem em formato .ppm.
 *
 */
class ImagemPPM : public Imagem {
 public:
  /**
   * @brief Construtor que inicializa todas as variaveis da classe.
   *
   * @param imagem Arquivo imagem em formato ppm usava para preenchimento de todos os atributos
   */
  ImagemPPM(FILE *imagem);

  /**
   * @brief Le a imagem em formato ppm
   * 
   * @param imagem - Arquivo da imagem
   */
  void ler(FILE *imagem) override;

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
