#include <avr/io.h>
#include <util/delay.h>

unsigned char display[] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X47D, 0X07, 0X7F, 0X6F};

int main(void)
{
	int ones, tens = 0;
	DDRA = 0XFF;
	DDRB = 0XFF;
	DDRD = 0XFF;
	while (1)
	{
		PORTD = 0b00000001;//RED
		for (int i = 99; i >= 0; i--)
		{
			ones = i % 10;
			tens = i / 10;
			
			
			for (int j = 0; j <50; j++)
			{
				PORTB = 0b00000010;
				PORTA = display[tens];//T
				
				_delay_ms(10);
				
				PORTB = 0b00000001;
				PORTA = display[ones];//O
				
				_delay_ms(10);
			}
		}
		
		PORTD = 0b00000100;//GREEN
		for (int i = 30; i >= 0; i--)
		{
			ones = i % 10;
			tens = i / 10;
			
			
			for (int j = 0; j <50; j++)
			{
				PORTB = 0b00000010;
				PORTA = display[tens];//T
				
				_delay_ms(10);
				
				PORTB = 0b00000001;
				PORTA = display[ones];//O
				
				_delay_ms(10);
			}
		}
		PORTD = 0b00000010;//YELLOW
		for(int i = 0; i <10; i++)
		{
			
			for (int j = 0; j <50; j++)
			{
				PORTB = 0b00000010;
				PORTA = display[0];
				
				_delay_ms(10);
				
				PORTB = 0b00000001;
				PORTA = display[0];
				
				_delay_ms(10);
			}
			for (int j = 0; j <50; j++)
			{
				PORTB = 0b00000010;
				PORTA = 0X00;
				
				_delay_ms(10);
				
				PORTB = 0b00000001;
				PORTA = 0X00;
				
				_delay_ms(10);
			}
		}
	}
}

