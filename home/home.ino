int Relay1 = 2;
int Relay2 = 3;
int Relay3 = 4;

int valueRelay1 = HIGH;
int valueRelay2 = HIGH;
int valueRelay3 = HIGH;

unsigned int temperatureValue = 0;
unsigned int temperatureValue1 = 1;

int val;

void setup() {
  Serial.begin(9600);
  pinMode(8,OUTPUT);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
}

void loop() {
    
    temperatureValue1 = analogRead(A0);
    digitalWrite(Relay1, valueRelay1);
    digitalWrite(Relay2, valueRelay2);
    digitalWrite(Relay3, valueRelay3);
    analogWrite(8,230);
    
    if(temperatureValue != temperatureValue1){
      temperatureValue = temperatureValue1;
      Serial.println(temperatureValue);
    }

    if (Serial.available()) {
      val = Serial.read();
      if (val == '1') {
        valueRelay1 = HIGH;
      }
      if (val == '2') {
        valueRelay1 = LOW;
      }
      
      if (val == '3') {
        valueRelay2 = HIGH;
      }
      if (val == '4') {
        valueRelay2 = LOW;
      }
      if (val == '5') {
        valueRelay3 = HIGH;
      }
      if (val == '6') {
        valueRelay3 = LOW;
      }
    }
}
