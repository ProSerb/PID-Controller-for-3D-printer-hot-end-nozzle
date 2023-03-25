## PID-Controller-for-3D-printer-hot-end-nozzle
#### Description:
C++ program that reads thermistor values and is put through a PID controller that controls a transistor, to get the hot-end nozzle to reach the desired user-set temperature and then maintain zero error between the desired temperature and actual temperature of the nozzle.

_Independant Variables_: Desired Temperature in (Celcius), Controller used: P-Control, PD-Control, PID-control

This is a closed-loop feedback control system where it calculates the error between the actual reading (thermistor temperature reading) and desired reading (desired temperature) and outputs a dutycycle value to be applied to a transistor that varies the current flow coming from the power supply to the hot-end nozzle.


