#include "Wire.h"

const byte a_port = A4;
const byte b_port = A5;
const byte addition_mcp23017 = 0x20;

void setup() 
{
  Wire.begin();

  Wire.beginTransmission(addition_mcp23017);
  Wire.write(0x01);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(addition_mcp23017);
  Wire.write(b_port);
  Wire.write(0);
  Wire.endTransmission();

  Serial.begin(9600);
}

void loop() 
{
  if (Serial.available()) {
    Wire.beginTransmission(addition_mcp23017);
    Wire.write(b_port);
    Wire.write(Serial.parseInt());
    Wire.endTransmission();
  }
}