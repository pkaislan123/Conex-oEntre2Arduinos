#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3
SoftwareSerial wifi(rxPin, txPin);  // RX, TX


void setup() {


  Serial.begin(115200);
  
  delay(200);

  wifi.begin(38400);

}

void loop() {

  //ler valores do nodemcu
  if (wifi.available()) {
    String texto_recebido = wifi.readString();
    descodificar(texto_recebido);
  }

 


}  

void enviarNodemcu(String texto_envio){
   wifi.println(texto_envio);
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

  
