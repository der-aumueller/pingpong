#include <Wire.h> //I2C Bibliothe einbinden
#include <Servo.h>  //Servo Bibliothek einbinden
#include <wiinunchuck.h> //Nunchuk Bibliothek einbinden
int richtungA           =12; //Pin 12 für die Richtung Motor A
int pwmA                =3;  //Pin für die Geschwindigkeit Motor A
int bremseA             =9;  //Pin 9 für die Bremse Motor A 
int richtungB         =13;  //Pin 13 für die Richtung Motor B
int pwmB              =11;  //Pin 11 für die Geschwindigkeit Motor B
int bremseB           =8;   //Pin 8 für die Bremse Motor b
int geschwindigkeit   =255; //Geschwindigkeit festlegen
Servo ausloeser; //Servo als ausloeser ansprechen

void setup() {
  Serial.begin(9600); //Beginn der seriellen Kommunikation
  nunchuk_init(); // Nunchuk initialisieren
  delay(100); //Verzögerung 100ms
  nunchuk_get_data();
  delay(100); //Verzögerung 100ms
  ausloeser.attach(6); //Servo an Pin 6
  pinMode(richtungA, OUTPUT); //Richtung A als output deklarieren
  pinMode(richtungB, OUTPUT); //Richtung B als output deklarieren
  pinMode(bremseA, OUTPUT); //Bremse A als output deklarieren
  pinMode(bremseB, OUTPUT); //Bremse B als output deklarieren
  analogWrite(pwmA, geschwindigkeit); //Wert geschwindigkeit auf Pin 3 schreiben
  analogWrite(pwmB, geschwindigkeit); //Wert geschwindigkeit auf Pin  11 schreiben
  ausloeser.write(147); //Ausloeser auf 147 Grad
}

void loop() {
    nunchuk_get_data(); // Daten vom Nunchuk empfangen
    delay(10); // Verzögerung 10ms
    if (nunchuk_zbutton() == 1) { //Wenn Z-Button gedrückt
    digitalWrite(bremseA, LOW);     //Bremse A lösen
    digitalWrite(bremseB, LOW);     //Bremse B lösen
    digitalWrite(richtungA ,HIGH);  //Motor A vorwärts
    digitalWrite(richtungB ,HIGH);  //Motor B vorwärts
    }
    else{ //ansonsten
      digitalWrite(bremseA, HIGH);
      digitalWrite(bremseB, HIGH);
    }
    if (nunchuk_cbutton() == 1) { //Wenn C-Button gedrückt
      ausloeser.write(55); //Ausloeser auf 55 Grad
      }
     else{ //ansonsten
      ausloeser.write(147); // Ausloeser auf 147 Grad
     }
     }
