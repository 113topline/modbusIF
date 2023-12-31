#include <Arduino.h>
#include <modbusIF.h>

modbusIF MAX485(13, 9600);

void setup() {
  Serial.begin(9600);
  Serial.println("iniciando teste...");
  delay(2000);
  MAX485.writeCoil(10, ON);
  delay(1000);
  MAX485.readCoil(10);
  delay(1000);
  MAX485.writeFloat(10, 512);
  delay(1000);
  MAX485.readFloat(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}




// TESTE MODBUS n sei como funciona github aaaaaaaaaaaaaaaaaa
/*
  ----------------- CÒDIGO NO ARQUIVO "modbusIF.h" EM lib > modbusIF -----------------

  para manter uma coerência para o envio de dados, eu (Samuel) pensei em fazer o seguinte:
  como o sor quer apenas que dois Arduinos se comuniquem, acho que não precisa enviar nenhuma ID.
  haveria três bytes 0 no início e no final para abrir e encerrar a mensagem.
  como funções, estava pensando em apenas WRITE_COIL, READ_COIL (leitura/escrita digital) e
  WRITE_FLOAT, READ_FLOAT (leitura de pino analógico e escrita em pino PWM). Não sei oq vcs acham, tá de bom tamanho?
  daí como seria a sintaxe para cada tipo de function code (FCODE):

//-----------------------------------------------------------

  WRITE_COIL (0x01):
  0x00, 0x00, 0x00, 0x01, 0x26, 0x01, 0x00, 0x00, 0x00
    (msg. begin)  (FCODE)  |  (estado)        |
                      (pino hex.)        (msg. end)

  resposta: espelho da mensagem

//-----------------------------------------------------------

  READ_COIL (0x02):
  0x00, 0x00, 0x00, 0x02, 0x26, 0x00, 0x00, 0x00
    (msg. begin)  (FCODE)  |            |
                      (pino hex.)  (msg. end)


  resposta: valor do pino x (exemplo: 0)

  0x00, 0x00, 0x00, 0x02, 0x26, 0x00, 0x00, 0x00, 0x00
    (msg. begin)  (FCODE)  |  (estado)       |
                      (pino hex.)       (msg. end)


//-----------------------------------------------------------          

  WRITE_FLOAT (0x03):
  0x00, 0x00, 0x00, 0x03, 0x26, 0xA6, 0x00, 0x00, 0x00
    (msg. begin)  (FCODE)  |   (00-FF)        |
                      (pino hex.)        (msg. end)

  resposta: espelho da mensagem

//----------------------------------------------------------- 

  READ_FLOAT (0x04):
  0x00, 0x00, 0x00, 0x04, 0x26, 0x00, 0x00, 0x00
    (msg. begin)  (FCODE)  |            |
                      (pino hex.)  (msg. end)

  resposta: valor do pino x (exemplo: 752)

  0x00, 0x00, 0x00, 0x02, 0x26, 0x02, 0xFO, 0x00, 0x00, 0x00
    (msg. begin)  (FCODE)  |    (MSB) (LSB)       |
                      (pino hex.)             (msg. end)

//-----------------------------------------------------------

*/



//teste
