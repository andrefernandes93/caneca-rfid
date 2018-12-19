/* PROGRAMAÇÃO BASE PARA CONTROLE DE CANECA RFID 
   Esta versão possui as rotinas de leitura e armazenamento de
   diferentes TAGs pertencentes à diferentes canecas.
*/

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   //Cria uma instância MFRC522

void setup() {
  Serial.begin(9600);   //Dá inicio a comunicação Serial com velocidade de 9600
  SPI.begin();          //Inicia o barramento SPI
  mfrc522.PCD_Init();   //Inicia a biblioteca MFRC522
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()){   //Busca novos cartões
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial()){     //Seleciona um dos cartões
    return;
  }
  Serial.print("UID da TAG: ");
  String conteudo = "";
  byte letra;
  for(byte i=0;i<mfrc522.uid.size;i++){
    Serial.print(mfrc522.uid.uidByte[i] <0x10 ? " 0": " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0": " "));
    conteudo.concat(String(mrfc522.uid.uidByte[i], HEX));
  }
}
