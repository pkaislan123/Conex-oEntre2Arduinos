# ConexãoEntre2Arduinos

  Objetico: O código a seguir tem por objetivo ler dados de um sensor de nivel d'agua conectado a porta analogica A0 do arduino,
  o valor lido fica entre 0 e 1023 bits, valor da porta analogica. Através da função MAP, remapeamos esse escopo para um novo escopo,
  tanto 0 a 100% para indicar o nivel de volume d'agua, como 0 a 255 para repassar o valor para o pino de pwm que aciona o motor.
  Nesse mesmo codigo conectamos um display lcd 16x2 e imprimos o valor do nivel e potencia, tambem enviamos atraves da serial nativa
  os valores de nivel e potencia codificados com um caracter de identificação.
 

  Objetico: O código a seguir tem por objetivo receber dados de uma conexao serial com outro arduino 
  e repassar para a serial.
  
  os pinos rx/tx nativos do arduino uno estão conectados ao rx/tx de outro arduino.
  Com a biblioteca SoftwareSerial criamos uma outra conexao rx/tx virtual e dela conectamos ao computador(necessário 
  conversor ttl->usb para a conversão dos dados)

<p align="center">
  <img src=https://raw.githubusercontent.com/pkaislan123/Conex-oEntre2Arduinos/main/simulacao_master_slave.png title="hover text">
</p>
