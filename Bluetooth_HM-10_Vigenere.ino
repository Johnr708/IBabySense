#include <SoftwareSerial.h>
#include<stdio.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
void setup() {
Serial.begin(9600);
Serial.println("AT commands: ");
BTSerial.begin(9600); // HM-10
}


void ecp(char* message, char key)
{
int msgLen = strlen(msg), keyLen = strlen(key), i, j;

    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    //encryption
    for(i = 0; i < msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A'; //convert into alphabets

    encryptedMsg[i] = '\0';

    return 0;
}

void loop(){
char oass[] = "MEDGAREVERSCOLLEGE";
int k = "HELLO";
ecp(oass, k);
Serial.println(oass);
delay(1000);
}