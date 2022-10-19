# Atmega328p-libraries
 C/Cpp Libraries based on Register Modellings with Structs and Unions  
 
 The usage of these libraries is very affective for beginners. 
 Adjustment of register settings is very simple and there is no need to remember registers and bit field names.
 
 
 Example Usages:
 
   gpio.ddrD->value = _ALL_OUTPUT; 
   
   gpio.portD->pind.pin0 = _HIGH; 
   
   adc.core->interrupt = _ENABLE; 
   
   spi.ddr->ss = _OUTPUT; 
   
   spi.port->ss = _HIGH; 
   
   lcd.sendString_x_y(1, 0, strArr);
