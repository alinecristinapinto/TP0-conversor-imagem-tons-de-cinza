#ifndef LEITORLINHACOMANDO_H
#define LEITORLINHACOMANDO_H

#include <string>

#include "msgassert.h" 

const std::string I_NOME_ARQUIVO_ENTRADA = "-i";
const std::string O_NOME_ARQUIVO_SAIDA = "-o";
const std::string P_REGISTRO_DESEMPENHO = "-p";
const std::string L_PADRAO_ACESSO_LOCALIDADE = "-l";

class LeitorLinhaComando {
  public:
  /**
   * @brief Retorna nome da imagem de entrada
   * 
   * @param argc Numero de parametros
   * @param argv String com comando digitado
   * @return string Nome da imagem de entrada 
   */
  static std::string buscar_nome_imagem_entrada(int argc, char* argv[]);

  /**
   * @brief Retorna nome da imagem de saida
   * 
   * @param argc Numero de parametros
   * @param argv String com comando digitado
   * @return string Nome da imagem de saida 
   */
  static std::string buscar_nome_imagem_saida(int argc, char* argv[]);

  private:
  /**
   * @brief Retorna argumento do terminal baseado na opcao passada
   * 
   * @param argc Numero de parametros
   * @param argv String com comando digitado
   * @param opcao Opcao de uso ex: -i, -l, -o
   * @return string Argumento do terminal referente a opcao
   */
  static std::string buscar_argumento(int argc, char* argv[], std::string opcao); 

};

#endif
