#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 1000000
#include <util/delay.h>

volatile unsigned int counter = 0;
volatile int secs_0 = 0;
volatile int secs_1 = 0;
volatile int hours_1 = 0;
volatile int hours_0 = 0;
volatile int mins_1 = 0;
volatile int mins_0 = 0;

volatile int sec = 0;
volatile int min1 = 0;
volatile int hour = 0;

volatile int PIR_Flag = 0;

int speed = 130;

void INT0_INIT(void)
{
  
  DDRD &= ~(1<<PD2);
  PORTD |= (1<<PD2);
  GICR |= (1<<INT0);
  MCUCR |= (1<<ISC01);
  SREG |= (1<<7);

}

void INT1_INIT(void)
{
  
  DDRD &= ~(1<<PD3);
  PORTD |= (1<<PD3);
  GICR |= (1<<INT1);
  MCUCR |= (1<<ISC11) | (1<<ISC10);
  SREG |= (1<<7);

}
void INT2_INIT(void)
{
  
  DDRD &= ~(1<<PB2);
  PORTD |= (1<<PB2);
  GICR |= (1<<INT2);
  MCUCSR &= ~(1<<ISC2);
  SREG |= (1<<7);

}



void Timer1_CTC(void)
{
	TCCR1B = (1<<WGM12) | (1<<CS12) | (1<<CS10);
	TCNT1 = 0;
	OCR1A = 1000;
	TIMSK |= (1<<OCIE1A);
	TCCR1A = (1<<FOC1A);
	SREG |= (1<<7);

  
}

ISR(INT0_vect)
{
  
  if(speed < 255)
  {
	speed += 25;

  if (speed >= 255)
  {
    speed = 255;
  }
  }

  
}

ISR(INT2_vect)
{
  if (speed >= 30){
	speed -= 25;
  if (speed == 5)
  {
    speed = 0;
  }
  if (speed <= 0)
  {
    speed = 0;
  }
  }
	
}

ISR(INT1_vect)
{
	
  PIR_Flag ^= (1<<0);
	
}



ISR(TIMER1_COMPA_vect)
{
	counter++;

  secs_0 = counter % 10;
  secs_1 = (counter / 10) % 6;
  mins_0 = (counter / 60) % 10;
  mins_1 = (counter / 600) % 6;
  hours_0 = (counter / 3600) % 10;
  hours_1 = (counter / 36000) % 10;

}

void TIMER0_PWM(int PWM)
{
  TCNT0 = 0;
  OCR0 = PWM;
  DDRB |= (1<<PB3);

  TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}

int main()
{
	DDRC = 0x0F;
	//DDRA = 0x3F;
  DDRA = 0xFF;
  DDRD |= (1<<PD3);
	
	DDRB = (1<<PB0) | (1<<PB1) | (1<<PB3);
	DDRD &= ~((1<<PD3));
  DDRB &= ~((1<<PB4) | (1<<PB5));
	
	Timer1_CTC();
  INT1_INIT();
  INT0_INIT();
  INT2_INIT();
  

	
	
	while(1)
	{

  if(PIR_Flag == 1){
     
  PORTB |= (1<<PB0);

  TIMER0_PWM(speed);

  PORTC = (PORTC & 0xf0) | (hours_1 & 0x0f);
  PORTA |= (1<<PA0);
	_delay_ms(0.1);
  PORTA &= ~(1<<PA0);
	
	PORTA |= (1<<1);
	PORTC = (PORTC & 0xf0) | (hours_0 & 0x0f);
	_delay_ms(0.1);
  PORTA &= ~(1<<PA1);
	
	PORTA |= (1<<2);
	PORTC = (PORTC & 0xf0) | (mins_1 & 0x0f);
	_delay_ms(0.1);
  PORTA &= ~(1<<PA2);
	
	PORTA |= (1<<3);
	PORTC = (PORTC & 0xf0) | (mins_0 & 0x0f);
	_delay_ms(0.1);
  PORTA &= ~(1<<PA3);
	
	PORTA |= (1<<4);
	PORTC = (PORTC & 0xf0) | (secs_1 & 0x0f);
	_delay_ms(0.1);
  PORTA &= ~(1<<PA4);
	
	PORTA |= (1<<5);
	PORTC = (PORTC & 0xf0) | (secs_0 & 0x0f);
	_delay_ms(0.1);
  PORTA &= ~(1<<PA5);
	}

  else if(PIR_Flag == 0)
  {

    PORTA = 0x00;
    counter = 0;
    PORTB &= ~(1<<PB0);
    
    TIMER0_PWM(0);
  }

  if(PINB & (1<<PB5))
  {
    PORTB &= ~((1<<PB0) | (1<<PB1));
    speed = 0;
    TIMER0_PWM(0);
    TCCR1B &= ~((1<<CS12) | (1<<CS10));
    TCCR0 &= ~(1<<CS01);
    
  }
  else if(PINB & (1<<PB4))
  {
    PORTB |= (1<<PB0);
    speed = 130;
    TIMER0_PWM(speed);
    TCCR1B |= ((1<<CS12) | (1<<CS10));
    TCCR0 |= (1<<CS01);
  }

  }

}