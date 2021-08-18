/*
 * GccApplication1.c
 *
 * Created: 11/8/2021 15:45:28
 * Author : Nicolas
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Prototipos
void initPorts();
void initTimers();
//Variables Globales
volatile uint8_t delay250Aprox;
volatile uint8_t flagByte;

//Interrupciones
ISR(TIMER0_OVF_vect){
		delay250Aprox--;
		if(!delay250Aprox){
			delay250Aprox=25;
			if(PORTB & (1<<PORTB5))
				PORTB &= ~(1<< PORTB5);
			else
				PORTB |= (1<< PORTB5);
			
		}
}

void initPorts(){
	//Configuro PIN del LED como salida (PB5 Arduino UNO, PB7 Arduino 2560)
	DDRB = (1 << DDB5); //ASIGNANDO b00100000
	//DDRB |= (1 << DDB5);//asignando DDRB=DDRB | b00100000

	PORTB |= (1<<PORTB5);
}

void initTimers(){
	TCCR0A=0x00;// modo normal del timer 0
	TIFR0=TIFR0;//borro lo q tenga TIFR0
	TIMSK0=(1<<TOIE0) //HABILITO INTERRUPCION
	TCCR0B =0x05; //PRESCALADOR EN 1024
}

int main(void)
{
	delay250Aprox=15;
	sei();//HABILITO INTERRUPCIONES
	//cli(); DESABILITAR INTERRUPCIONES
	initPorts();
	initTimers();
    /* Replace with your application code */
    while (1) 
    {
		
	//	if(PORTB & (1<<PORTB5))
	//		PORTB &= ~(1<< PORTB5);
	//	else
	//		PORTB |= (1<< PORTB5);
	
	//delayApox250ms=15;
	//while(delayApox250ms){
	//	if(TIFR0 & (1<<TOV0)){// (1<<TOV0) 1 desplazado 0 veces para compararlo con el bit 0 de TIFR0 
	//		TIFR0|=(1<<TOV0);//si la bandera esta en 1 le escribo otro 1 para volverla a cero
	//		delayApox250ms--;
	//	}
	//}
	//	_delay_ms(250);
    }
}

