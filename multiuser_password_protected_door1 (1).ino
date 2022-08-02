#include <Keypad.h>
#include <Servo.h>

const int ROWS = 4;
const int COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPin[ROWS] = {9, 8, 7, 6};
byte colPin[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPin, colPin, ROWS, COLS);
String v_passcode = "";
Servo servo_10;
Servo servo_11;


void setup()
{
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  servo_10.attach(10);
  servo_11.attach(11);
  servo_10.write(0);
  servo_11.write(0);
}

void loop()
{
  char key = keypad.getKey();
  
  if(key != NO_KEY){
    
    v_passcode = v_passcode + key;
    
    if(key == '*'){
      Serial.println("enter password ending with D");
      v_passcode = "";
    }
    
    if(key == '#'){
      Serial.println("enter password again with D");
      v_passcode = "";
      Serial.println(v_passcode);
    }
    
    if(key == 'D'){
      Serial.println("validating the password");
      
      if(v_passcode == "589D"){
        Serial.println("access granted");
        servo_10.write(90);
        delay(100);
        servo_10.write(0);
        v_passcode = "";
        
      }else if(v_passcode == "123D"){
        Serial.println("access granted");
        servo_11.write(90);
        delay(100);
        servo_11.write(0);
        v_passcode = "";
        
      }else{
        Serial.println("access denied");
        v_passcode = "";
      }
    }
  }      
}