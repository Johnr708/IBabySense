#include <SoftwareSerial.h>
#include<stdio.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
void setup() {
Serial.begin(9600);
BTSerial.begin(38400); // HC-05
}


void ecp(char* message, int key)// encrypton for string
  {
   char ch;
   int i; 
   for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
    }
}

void loop(){
char oass[] = "BaBy";
int k = 5;
ecp(oass, k);
Serial.println(oass);
delay(1000);
}
