#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "serial.h"
int main()
{
	int count=1;
	DDRB=0b11111111;
	DDRC=0b11111000;
	comm_init();
		while(1)
			{	if(PINC==0b00000101)
				{
					forward();
				}
				else if(PINC==0b00000111)
				{
					forward();
				}
				else if(PINC==0b000000001)
				{
					left();
				}
				else if(PINC==0b00000100)
				{
					right();
				}
				else if(PINC==0b00000011)
				{
					while(PINC!=0b00000101)
					{
						left();
					}
				}
				else if(PINC==0b00000110)
				{
					while(PINC!=0b00000101)
						{
							right();
						}
				}
				else if(PINC==0b00000000)
				{
					if(count<7)
					{	send_data(count+48);
						while(PINC!=0b00000101)
						{	
							forward();
						}
						
						count++;
					}
					else
					{
						while(1)
							{
								 PORTB=0b11111111;
								 _delay_ms(200);
								 PORTB=0b00000000;
							}
					}
				}
			}
return 0;
}
void forward()
{	
	PORTB=0b00001010;
	_delay_us(30);
	PORTB=0b00000000;
	_delay_us(70);
}
void right()
{	
	PORTB=0b00001001;
	_delay_us(30);
	PORTB=0b00000000;
	_delay_us(70);
}
void left()
{	
	PORTB=0b00000110;
	_delay_us(30);
	PORTB=0b00000000;
	_delay_us(70);
}

 void stop()
 {
 PORTB=0b00000000;
 _delay_us(100);
 }
