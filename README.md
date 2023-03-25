## PID-Controller-for-3D-printer-hot-end-nozzle
#### Description:
C++ program that reads thermistor values and is put through a PID controller that controls a transistor, to get the hot-end nozzle to reach the desired user-set temperature and then maintain zero error between the desired temperature and actual temperature of the nozzle.

_Independant Variables_: Desired Temperature in (Celcius), Controller used: P-Control, PD-Control, PID-control

The controller takes in the thermistors readings and calculates the error based 


Once the independant variables are set a timer is set for 3 minutes, where the controller works to get the hot-end nozzle to reach and maintain the desired temperature and once 3 minutes is reached, the time and temperature readings of the themistor during those 3 minutes is outputted. 
