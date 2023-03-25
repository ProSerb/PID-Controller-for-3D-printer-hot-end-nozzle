## PID-Controller-for-3D-printer-hot-end-nozzle
#### Description:
C++ program that reads thermistor values and is put through a PID controller that controls a transistor, to get the hot-end nozzle of a 3D printer to reach the desired user-set temperature and then maintain zero error between the desired temperature and actual temperature of the nozzle. This is a closed-loop feedback control system where it calculates the error between the actual reading (thermistor temperature reading) and desired reading (desired temperature) and outputs a dutycycle value that is applied to a transistor that varies the current flow coming from the power supply to the hot-end nozzle.

#### Work flow:
_Independant Variables_: Desired Temperature in (Celcius), Controller used: P-Control, PD-Control, PID-control

Once independant variables are set, a three minute timer is set to allocate enough time for the controller to reach the desired temperature and settle around that temperature. When the timer reaches three minutes the thermistor readings are outputted during that time, and the tranisistors dutycycle is set to 0 allowing no current to flow to the hot-end nozzle allowing it to cool down.  


