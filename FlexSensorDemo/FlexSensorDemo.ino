/* How to use a flex sensor/resistro - Arduino Tutorial
   Fade an LED with a flex sensor
   More info: http://www.ardumotive.com/how-to-use-a-flex-sensor-en.html
   Dev: Michalis Vasilakis // Date: 9/7/2015 // www.ardumotive.com  */


//Constants:
const int ledPin2 = 2;   //pin 2 has PWM funtion
const int ledPin3 = 3;
const int ledPin4 = 4;
const int ledPin5 = 5;
const int flexPinA2 = A2; // yellow
const int flexPinA3 = A3; // blue
const int flexPinA4 = A4; // green
const int flexPinA5 = A5; // black

//Variables:
int valueYellowA2; //save analog value
int valueBlueA3;
int valueGreenA4;
int valueBlackA5;

int initYellow;
int initBlue;
int initGreen;
int initBlack;

void setup() {

  pinMode(ledPin2, OUTPUT);  //Set pin 4 as 'output'
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  initYellow = analogRead(flexPinA2);
  initBlue = analogRead(flexPinA3);
  initGreen = analogRead(flexPinA4);
  initBlack = analogRead(flexPinA5);

  Serial.begin(9600);       //Begin serial communication

}

void loop() {

  valueYellowA2 = analogRead(flexPinA2);        //Read and save analog value from potentiometer
  valueBlueA3 = analogRead(flexPinA3);
  valueGreenA4 = analogRead(flexPinA4);
  valueBlackA5 = analogRead(flexPinA5);

  touched(valueYellowA2, ledPin2);
  touched(valueBlueA3, ledPin3);
  touched(valueGreenA4, ledPin4);
  touched(valueBlackA5, ledPin5);

  Serial.println(valueYellowA2); //Print value
  Serial.println(valueBlueA3);
  Serial.println(valueGreenA4);
  Serial.println(valueBlackA5);
  Serial.println();
  //  valueYellowA2 = map(valueYellowA2, 700, 900, 0, 255);//Map value 0-1023 to 0-255 (PWM)
  //  valueBlueA3 = map(valueBlueA3, 400, 600, 0, 255);
  //  valueGreenA4 = map(valueGreenA4, 400, 600, 0, 255);
  //  valueBlackA5 = map(valueBlackA5, 400, 600, 0, 255);
  //     Serial.println(valueYellowA2); //Print value
  // Serial.println(valueBlueA3);
  // Serial.println(valueGreenA4);
  // Serial.println(valueBlackA5);
 // analogWrite(ledPin2, valueYellowA2);          //Send PWM value to led
  //  analogWrite(ledPin3, valueBlueA3);
  //  analogWrite(ledPin4, valueGreenA4);
  //  analogWrite(ledPin5, valueBlackA5);
  delay(500);                          //Small delay
}

boolean touched(int value, int ledPin) {
  if(value < 900) {
    analogWrite(ledPin, 100);
  } else {
    analogWrite(ledPin, 0);
  }
}


