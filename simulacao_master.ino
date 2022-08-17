#include <LiquidCrystal_I2C.h> //importa a biblioteca para uso do lcd com i2c


/*
 * 
 * 
 * Autor: Aislan Silva Costa
 * Data: 20/10/2021
 * 
 * Objetico: O código a seguir tem por objetivo ler dados de um sensor de nivel d'agua conectado a porta analogica A0 do arduino,
 * o valor lido fica entre 0 e 1023 bits, valor da porta analogica. Através da função MAP, remapeamos esse escopo para um novo escopo,
 * tanto 0 a 100% para indicar o nivel de volume d'agua, como 0 a 255 para repassar o valor para o pino de pwm que aciona o motor.
 * Nesse mesmo codigo conectamos um display lcd 16x2 e imprimos o valor do nivel e potencia, tambem enviamos atraves da serial nativa
 * os valores de nivel e potencia codificados com um caracter de identificação.
 * 
 
 */

LiquidCrystal_I2C lcd(0x20 , 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //configura o lcd 16x2 i2c.

int sensorNivelAgua = A0; //sensor de nivel d'agua conecta a porta analogica A0;
int bomba = 9; //pino de pwm do arduino uno
void setup() {

  lcd.begin(16, 2); //configura o lcd para  a configuração 16x2
  lcd.backlight(); //ativa a luz de fundo do lcd

  imprimeMensagem(0, 0, "Bem-Vindo"); // imprime a mensagem "Bem-Vindo", apartir da coluna 0, na linha 0.
  //a função imprimeMensagem recebe 3 paramentros, a coluna de inicio da mensagem, a linha de inicio da mensagem, e o texto a imprimir
  delay(1000); //atrasa a rotina em 1 segundo
  pinMode(sensorNivelAgua, INPUT); //define o pino do sensor de nivel d'agua como entrada de dados
  pinMode(bomba, OUTPUT); //define o pino de pwm como saida de dados
  Serial.begin(9600); //inicia a serial nativa em 9600

}

void loop() {

  lcd.clear(); //limpa o lcd

  int nivel = map( analogRead(sensorNivelAgua), 0, 1023, 0, 100); //remapeia o valor do nivel de agua do escopo de 0 a 1023 para 0 a 100%
  int potencia_bomba = map( analogRead(sensorNivelAgua), 0, 1023, 255, 0); //remapeia o valor do sensor de nivel d'agua de 0 a 1023 para 255 a 0, aqui o valor fica inversamente proporcional, ou seja,
  //quando o nivel marca 0%(0 bits), o pwm será 255, quando o valor do sensor for 100%(1023 bits), o pwm sera 0
  int potencia_porcentagem =  map( potencia_bomba, 0, 255, 0, 100);//remapeia o valor do pwm de 0 a 255 para 0 a 100%
  
  
  
  String s_nivel = String(nivel); //converte o valor inteiro do nivel em string tanto para imprimir no lcd como enviar via serial
  String texto_nivel = "Nivel: " + s_nivel + "%"; //concate o texto
  imprimeMensagem(0, 0, texto_nivel); //imprime o texto do nivel no lcd
  
  
   String s_potencia = String(potencia_porcentagem); //converte o valor inteiro da potencia em string tanto para imprimir no lcd como enviar via serial
   String texto_potencia = "Potencia: " + s_potencia + "%"; //concate o texto
  imprimeMensagem(0, 1, texto_potencia); //imprime o texto da potencia no lcd
  
  
  
  Serial.println("*" + s_nivel); //imprime na serial nativa o valor do nivel codificando com um caracter de identificacao
  Serial.println("#" + s_potencia);//imprime na serial nativa o valor do nivel codificando com um caracter de identificacao
  
  acionarMotor(potencia_bomba);//aciona a bomba, a funcao acionarMotor recebe um unico parametro que é o valor de pwm para acionar o motor

  delay(500); //atrasa a rotina em 0.5 segundo

}

void acionarMotor(int potencia) {
  analogWrite(bomba, potencia);  //chama a funcao analogWrite para acionar o pwm no pino definido como bomba, o segundo parametro e o valor do pwm.
}

void imprimeMensagem(int coluna, int linha, String mensagem) {
  lcd.setCursor(coluna, linha); //define a posicao inicial da impressao do texto
  lcd.print(mensagem); //imprime a mensagem na ultima posicao configurada
}
