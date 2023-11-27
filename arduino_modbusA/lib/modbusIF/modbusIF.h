class modbusIF{
  public:
    modbusIF();
    void writeCoil(byte pin, bool val);
    uint16_t readCoil(byte pin);
    void writeFloat(byte pin, byte val);
    uint16_t readFloat(byte pin);

  private:

    enum func {WRITE_COIL, READ_COIL, WRITE_FLOAT, READ_FLOAT};
    void sendMsg(func function);

};

void modbusIF::writeCoil(byte pin, bool val){

}

uint16_t modbusIF::readCoil(byte pin){
  uint16_t val;
  return val;
}

void modbusIF::writeFloat(byte pin, byte val){

}

uint16_t modbusIF::readFloat(byte pin){
  uint16_t val;
  return val;
}

void modbusIF::sendMsg(func function){
  for(byte i = 0; i < 3; i++) Serial1.write(0x00);
  Serial1.write((byte)function);
}

modbusIF::modbusIF(uint32_t baud){
  Serial1.begin(baud);
  pinMode(, OUTPUT);
  digitalWrite(13, LOW);
}