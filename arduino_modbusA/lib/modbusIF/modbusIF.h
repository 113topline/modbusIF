// DADOS: pino LOW = Receiver HIGH e Driver LOW   --> só recebe
//        pino HIGH = Receiver LOW e Driver HIGH  --> só envia


class modbusIF{
  public:
    modbusIF(byte pin, uint32_t baud);                // função para criar instância
    void writeCoil(byte pin, bool val);               // escreve FCODE = 1
    uint16_t readCoil(byte pin);                      // escreve FCODE = 2
    void writeFloat(byte pin, byte val);              // escreve FCODE = 3 
    uint16_t readFloat(byte pin);                     // escreve FCODE = 4

  private:
    byte DE_RE_pin = 13;                              //pino utilizado para DE/RE
    enum func {WRITE_COIL = 1, READ_COIL, WRITE_FLOAT, READ_FLOAT};   //FCODE
    void send(func function);                         // função para envio dos dados

};

void modbusIF::writeCoil(byte pin, bool val){
  Serial.println("comando escrever valor " + String(val) + " na bobina " + String(pin));

}

uint16_t modbusIF::readCoil(byte pin){
  Serial.println("comando ler valor digital da bobina " + String(pin));
  uint16_t val = 0;
  return val;
}

void modbusIF::writeFloat(byte pin, byte val){
  Serial.println("comando escrever valor float " + String(val) + " na bobina " + String(pin));

}

uint16_t modbusIF::readFloat(byte pin){
  Serial.println("comando ler valor float da bobina " + String(pin));
  uint16_t val = 512;
  return val;
}

void modbusIF::send(func function){
  for(byte i = 0; i < 3; i++) Serial1.write(0x00);
  Serial1.write((byte)function);
}

modbusIF::modbusIF(byte pin, uint32_t baud){
  DE_RE_pin = pin;
  Serial1.begin(baud);
  pinMode(DE_RE_pin, OUTPUT);
  digitalWrite(DE_RE_pin, LOW);
  Serial.println("Serial connection started");
}