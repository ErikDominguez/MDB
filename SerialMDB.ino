const int NUM_BYTES = 16;
byte data[NUM_BYTES];
const int NUM_BYTES2 = 18;
byte data1[NUM_BYTES2];

int i=0x00;
int respuesta0=0x00;
int respuesta1=0x00;

void setup ()
{
  Serial.begin (9600,SERIAL_8N1,true);  // 9 bit mode
  Serial.println ("--- starting ---");
  delay(2000);      
        
        Serial.write9bit(0x108);  // send RESET
        delay(1);
        Serial.write9bit(0x008);  // send Checksum
        delay(5);
        respuesta0=Serial.read();
        Serial.print("La respuesta al RESET es: ");
        Serial.println(respuesta0, HEX);
        delay(2000);
        
}  // end of setup


void loop () 
{
//digitalWrite(13, HIGH);       // sets the digital pin 13 on
//delay(1);
//      
//      for (i =0x00 ; i <= 0x1FF; i++){
//        Serial.write9bit(i);  // send another byte
//        delay(2);
//        //Serial.write(data, dataLength);
//      }
//     
//digitalWrite(13, LOW);        // sets the digital pin 13 off
//delay(1);


        
        Serial.write9bit(0x10B);  // send POLL
        delay(1);
        Serial.write9bit(0x00B);  // send Checksum
        delay(5);
        Serial.readBytes(data, uint8_t(16));
        Serial.print("La respuesta al POLL es: ");
          for(int i=0;i<16;i++){

            Serial.print(data[i],HEX);
            Serial.print(" ");
          
          }
        Serial.println(" ");
        delay(2000);


        Serial.write9bit(0x10A);  // send tube status
        delay(1);
        Serial.write9bit(0x00A);  // send Checksum
        delay(5);
        Serial.readBytes(data1, uint8_t(18));
        Serial.print("La respuesta al TUBE STATUS es: ");
          for(int i=0;i<18;i++){

            Serial.print(data1[i],DEC);
            Serial.print(" ");
          
          }
        Serial.println(" ");
        delay(2000);


        Serial.write9bit(0x10D);  // send dispense
        delay(1);
        Serial.write9bit(0x111);  //send type number
        delay(1);
        Serial.write9bit( (0x10D + 0x111) && (0xFF) );  // send Checksum
        delay(5);
        respuesta0 = Serial.read();
        Serial.print("La respuesta al dispense es: ");
        Serial.println(respuesta0, BIN);
        delay(4000);


}  // end of loop


