
// Reese Chahal -  9/24/24 – Volt Div MATLAB Exp. Testing -  week 2 
//  CIRCUIT USED IN TESTING: VOLTAGE DIVIDER 
//int sensorPin = A0;   // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int motorpin = 13; 

void setup() {
  Serial.begin(9600); 
}


void loop() {
  float time = micros()/ 1e6;
  sensorValue = analogRead(A0); // volt output in 0 -1023 analog pin range
  float voltage= sensorValue * (5.0 / 1023.0); //convert it to voltage out 
  delay(100); 

  //print time in seconds
  Serial.print(time); 
  Serial.print(", ");
  Serial.println(voltage);

}



// week 2: datastream 
//TOTAL DELAY VOID LOOP () shld = delay(100) --> week 2 dan, so each if else can take the 100 or u can do 
// (50) for if else  and then use the remainder (50) for rest of void loop fxn,ex. two diff serialprints and delay(25)





/*

VOLTAGE DIVIDER CIRCUIT USED: 5V INPUT, R1=10KOHM, R2=VARIABLE WOOL FELT SENSOR

1.the serial monitor prints VOLT readings from pin a0, relative to 5V total input to the circuit 
    0 (0V min) - 1023 (5V max for mega)
(but accounting for some loss at the pins so lets say 4.7V is max volt coming into circuit )
    0 (0V min) - 1023 (4.7V max for mega)


Variable/resistive wool felt sensor, at analogRead(A0), the Serial monitor prints following range: 
200 (when i apply forceful pressure) -- 900 
average = 860 consistently
*/