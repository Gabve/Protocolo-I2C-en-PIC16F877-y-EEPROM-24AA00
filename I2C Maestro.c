#include <16F877.h>
#FUSES HS,NOWDT
#USE DELAY (CLOCK = 4M)
#DEFINE USE_PORTB_KBD TRUE
#INCLUDE <kbd4X4_1.C>
#use standard_io(b)
#use standard_io(c)
#include <stdlib.h>
#USE I2C (MASTER, SDA= PIN_C4, SLOW, SCL= PIN_C3, NOFORCE_SW)

void main () {
int dispositivo;
char k='0';
int i=0;
kbd_init();
port_b_pullups(true); 

while(1){ 
k=kbd_getc();
i=(k-48);
if(k=='A'){Dispositivo=0;}
if(k=='B'){Dispositivo=1;}
if(k=='C'){Dispositivo=2;}
if((i>-1)&&(i<10)){

if(Dispositivo==0){
i2c_start();
i2c_write(0xA0);
i2c_write(0x00); 
i2c_write(0x00); 
i2c_write(i); 
i2c_stop();  
delay_ms(100); 
i=0;}

if(Dispositivo==1){
i2c_start();
i2c_write(0xA2);
i2c_write(0x00);
i2c_write(0x00); 
i2c_write(i); 
i2c_stop();  
delay_ms(100); 
i=0;
}


if(Dispositivo==2){
i2c_start();
i2c_write(0xA4);
i2c_write(0x00); 
i2c_write(0x00); 
i2c_write(i); 
i2c_stop();  
delay_ms(100); 
i=0;
}
}
} 
}  

