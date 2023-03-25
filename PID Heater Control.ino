
/////////////////////////////////////////
// MECH 310 Lab 1 - PID heater control //
//                                     //
// Trifko Basic and Matthew Robertson  //
// F2021                               //
/////////////////////////////////////////

float trans = 5; // transistor
float sens = A0; // themistor

float temp;
float val;
float error;
float de;
float P_output;
float PD_output;
float PID_output;
float setpoint;
float elapsedTime;
float cumError, rateError;
float lastError;

int Kp1 = 2;
int Kp2 = 10; //Proportional gains
int Kp3 = 0.5;

int Ki1 = 0.9;
int Ki2 = 1.2; //Integral gains
int Ki3 = 5;

int Kd1 = 80;
int Kd2 = 500; //Derivative gains
int Kd3 = 5000;

const unsigned long eventInterval = 180000; // 3 mins
unsigned long previousTime;
unsigned long currentTime;

//*** Choose some constants ***
int Kp = Kp1; // Proportional constant
int Ki = Ki1; // Integral constant
int Kd = Kd1; // derivative constant
//***^^^***

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  setpoint = 40; // Set heater to reach this temperature

  currentTime = millis();
  val = analogRead(sens);
  temp = Thermistor(val);

  elapsedTime = currentTime - previousTime;
  error = setpoint - temp;
  de = error - lastError;

  rateError = abs(de / elapsedTime);
  cumError += error * elapsedTime;


  P_output = Kp * error;
  PD_output = Kp * error + Kd * rateError;
  PID_output = Kp * error + Kd * rateError + Ki * cumError;

  //*** You can Modify down below ***
  analogWrite(trans, <output>); //Change second argument to P_output, PD_output or PID_output
  Serial.println(temp);
  //*** ^^^ ***
  
  do {
    analogWrite(trans, 0);
    val = analogRead(sens);
    temp = Thermistor(val);
    error = setpoint - temp;
    Serial.println(temp);
  } while (error < 0);

  if (currentTime >= eventInterval) {
    do {
      analogWrite(trans, 0);
      val = analogRead(sens);
      temp = Thermistor(val);
      Serial.println("It's been 3 mins, cooling down, hit reset to restart once temp returns to initial value");
      Serial.println(temp);
      delay(1000);
    } while (1);
  }
  lastError = error;
  previousTime = currentTime;

}

//***************Functions******************
float Thermistor(int RawADC) {
  float Temp;
  Temp = log(((10240000 / RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
  
  //CHANGE the constant <43.6> in the line below
  Temp = Temp - 273.15 + 43.6;              // Convert Kelvin to Celsius
  
  //Temp = (Temp * 9.0) / 5.0 + 32.0; // Celsius to Fahrenheit - comment out this line if you need F
  return Temp;
}
