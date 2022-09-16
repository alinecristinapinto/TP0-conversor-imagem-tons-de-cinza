# TP0-conversor-imagem-tons-de-cinza

### Executando o projeto

No diretório do projeto, executar:

`./bin/run.out -i ./img-samples/nome_imagem.ppm -o imagem.pgm -p log.out -l`

No qual:

-i  "nome do arquivo de entrada"  (entrada em formato .ppm)                   
-o  "nome do arquivo de saída"    (saída em formato .pgm)
-p  log.out            (registro de desempenho)
-l                     (padrão de acesso e localidade)

Exemplo de uso:

`./bin/run.out -i ./img-samples/bolao.ppm -o ./img-samples/balao-convertido.pgm -p log.out -l`
