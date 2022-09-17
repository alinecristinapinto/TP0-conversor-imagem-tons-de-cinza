#ifndef LEITORLINHACOMANDO_H
#define LEITORLINHACOMANDO_H

#include <string>

#include "msgassert.hpp" 

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

  /**
   * @brief Retorna nome do arquivo para memlog
   * 
   * @param argc Numero de parametros
   * @param argv String com comando digitado
   * @return string Nome do arquivo de log
   */
  static std::string buscar_nome_memlog(int argc, char* argv[]);

  /**
   * @brief Retorna se devem ser registrados os acessos a memoria ou apenas o tempo de execucao.
   * 
   * @param argc Numero de parametros
   * @param argv String com comando digitado
   * @return bool registro de acesso a memoria
   */
  static bool verificar_registro_acesso(int argc, char* argv[]);

  private:
  /**
   * @brief Retorna argumento do terminal baseado na opcao passada
   * 
   * @param argc Numero de parametros
   * @param argv String com comando digitado
   * @param opcao Opcao de uso ex: -i, -p, -o
   * @return string Argumento do terminal referente a opcao
   */
  static std::string buscar_argumento(int argc, char* argv[], std::string opcao); 

  /**
   * @brief Retorna se parametro se encontra no comando recebido
   * 
   * @param argc Numero de parametros
   * @param argv String com comando digitado
   * @param parametro Opcao de uso ex: -i, -l, -o
   * @return bool verdadeiro/falso para presenca de parametro no comando
   */
  static bool verificar_parametro_presente(int argc, char* argv[], std::string parametro); 

};

#endif
