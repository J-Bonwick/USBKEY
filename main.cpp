#include <Arduino.h>
#include <Keyboard.h>
#include <SD.h>

//Define Pins
static const int binarySwitchPin1 = 2;
static const int binarySwitchPin2 = 3;
static const int binarySwitchPin4 = 4;
static const int binarySwitchPin8 = 5;

static const int repeatButtonPin = 6;
static const int statusLedPin = 7;

static const int chipSelect = 10;

bool execute = true;
File file;

void setup() {
    //Init Pins
    pinMode(binarySwitchPin1, INPUT_PULLUP);
    pinMode(binarySwitchPin2,INPUT_PULLUP);
    pinMode(binarySwitchPin4,INPUT_PULLUP);
    pinMode(binarySwitchPin8, INPUT_PULLUP);

    Keyboard.begin();

    SD.begin(chipSelect);
}

//Return the name of the script name
String readDecadeSwitch(){
    int counter = 0;
    if(digitalRead(binarySwitchPin1) == LOW){
        counter += 1;
    }
    if(digitalRead(binarySwitchPin2) == LOW){
        counter += 2;
    }
    if(digitalRead(binarySwitchPin4) == LOW){
        counter += 4;
    }
    if(digitalRead(binarySwitchPin8) == LOW){
        counter += 8;
    }
    String value = counter + ".tx";
    return value;
}

void loop() {
    if (digitalRead(repeatButtonPin)){
        execute = true;
    }
    if(execute){
        //Read and run code here
        file = SD.open(execute + "t");
        file = SD.open("File.txt");

        //Stop loop repeating
        execute = false;
    }   
}