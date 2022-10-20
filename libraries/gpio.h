//Soner Ayar

#ifndef GPIO_H_
#define GPIO_H_

//TODO: move them to definitions.h file

#ifndef _STDINT_H 
#include<stdint.h>
#endif

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#define _IO	volatile

#define sbi(reg, bit)	do{ reg |= (1<<bit);  }while(0)
#define cbi(reg, bit)	do{ reg &= ~(1<<bit); }while(0)

//-----------------------todo

//TODO: move them to 328pRegisters.h file

/** Register Addresses ***************************/
#define ADDR_PINB	(0x23)
#define ADDR_DDRB	(0x24)
#define ADDR_PORTB	(0x25)

#define ADDR_PINC	(0x26)
#define ADDR_DDRC	(0x27)
#define ADDR_PORC	(0x28)

#define ADDR_PIND	(0x29)
#define ADDR_DDRD	(0x2A)
#define ADDR_PORTD	(0x2B)

/** Structs and Unions ***************************/
typedef struct{
	u8 pin0: 1;
	u8 pin1: 1;
	u8 pin2: 1;
	u8 pin3: 1;
	u8 pin4: 1;
	u8 pin5: 1;
	u8 pin6: 1;
	u8 pin7: 1;
}s_pin_t;

typedef union{
	s_pin_t pins;
	u8 value;	
}u_gpio_t;

typedef struct{
	_IO u_gpio_t* pinB;
	_IO u_gpio_t* ddrB;
	_IO u_gpio_t* portB;
	_IO u_gpio_t* pinC;
	_IO u_gpio_t* ddrC;
	_IO u_gpio_t* portC;
	_IO u_gpio_t* pinD;
	_IO u_gpio_t* ddrD;
	_IO u_gpio_t* portD;
}s_io_dev;

static s_io_dev gpio = {
	.pinB = (_IO u_gpio_t* const)(ADDR_PINB),
	.ddrB = (_IO u_gpio_t* const)(ADDR_DDRB),
	.portB =(_IO u_gpio_t* const)(ADDR_PORTB),

	.pinC = (_IO u_gpio_t* const)(ADDR_PINC),
	.ddrC = (_IO u_gpio_t* const)(ADDR_DDRC),
	.portC =(_IO u_gpio_t* const)(ADDR_PORTC),

	.pinD = (_IO u_gpio_t* const)(ADDR_PIND),
	.ddrD = (_IO u_gpio_t* const)(ADDR_DDRD),
	.portD =(_IO u_gpio_t* const)(ADDR_PORTD)
};

#endif /* GPIO_H_ */
