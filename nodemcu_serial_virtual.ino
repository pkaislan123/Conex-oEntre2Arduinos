#include <SoftwareSerial.h>


#define rxPin D1
#define txPin D0
SoftwareSerial arduino(rxPin, txPin); // RX, TX

void setup() {

  arduino.begin(38400);

  Serial.begin(115200);


}

void loop() {

  //ler valores do arduino
  if (arduino.available()) {
    String texto_recebido = arduino.readString();
    descodificar(texto_recebido);
  }

}

void descodificar(String texto_recebido) {

  Serial.print("Requicao: ");
  Serial.println(texto_recebido);

  int arroba = texto_recebido.indexOf("@");
  int hifen = texto_recebido.indexOf("-");
  int asterisco = texto_recebido.indexOf("*");
  int e_com = texto_recebido.indexOf("&");
  int hashtag = texto_recebido.indexOf("#");
  int sifrao = texto_recebido.indexOf("$");

  //Exemplo: @17#123$
  if (arroba == 0 && hashtag > 0 && sifrao > 0) {
    //tratar
  }

  //Exemplo: #312@18$
  if (hashtag == 0 && arroba > 0 && sifrao > 0) {
    //tratar
  }

}


void enviarArduino(String texto_envio) {
  arduino.println(texto_envio);
}
