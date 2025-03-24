
// 9/24/24 – Volt Div MATLAB Exp. Testing - Dan week 2 
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



//dan week 2: datastream 
//TOTAL DELAY VOID LOOP () shld = delay(100) --> week 2 dan, so each if else can take the 100 or u can do 
// (50) for if else  and then use the remainder (50) for rest of void loop fxn,ex. two diff serialprints and delay(25)





/*

VOLTAGE DIVIDER CIRCUIT: 5V INPUT, R1=10KOHM, R2=VARIABLE WOOL FELT SENSOR

1.the serial monitor prints VOLT readings from pin a0, relative to 5V total input to the circuit 
    0 (0V min) - 1023 (5V max for mega)
(but accounting for some loss at the pins so lets say 4.7V is max volt coming into circuit )
    0 (0V min) - 1023 (4.7V max for mega)


Variable/resistive wool felt sensor, at analogRead(A0), the Serial monitor prints following range: 
200 (when i apply forceful pressure) -- 900 
average = 860 consistently


Meaning of 200-900 analogRead() output: 
- 900 number is close to the max 1023 (4.7volt), proportionally i can make a guess that 900 = 4.2 volt
- since my sensor is outputing 4.2 volts, I'll use this equation to calculate the sensor's resistance value:
 volt_out = (volt_in x R2)
            --------------
              (R1 + R2)

 4.2 = (5v x 10kohm)
       --------------
      (R1??  + 10kohm)
      
R1 wool felt resistance = 1904.762 ohms OR 1.9Kohm 

volt_in = 5V 
volt_out = 4.2V =  sensorValue * (5.0 / 1023.0) = 860 * (5.0 / 1023.0);
R1 (resistor closest to VIN/5v/source pwr) = ? wool felt sensor
R2 (resistor closest to GND) = 10kohm


CALCULATE: https://ohmslawcalculator.com/voltage-divider-calculator


ARDUINO MEGA 08/22/24
https://www.kobakant.at/DIY/?p=6102
https://www.kobakant.at/DIY/?p=8649


*/