
#ifndef GPIO_H_
#define GPIO_H_

#ifndef _STDINT_H
#include<stdint.h>
#endif

//TODO: move them to definitions.h file
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#define _IO	volatile

#define sbi(reg, bit)	do{ reg |= (1<<bit);  }while(0)
#define cbi(reg, bit)	do{ reg &= ~(1<<bit); }while(0)


//TODO: move them to 328pRegisters.h file
/** Offsets **************************************/
#define _GPIO_BASE_ADDRESS	0x03
#define _SFR_OFFSET			    0x20
#define _GPIO_B_OFFSET		  0x00
#define _GPIO_C_OFFSET		  0x03
#define _GPIO_D_OFFSET		  0x06
#define _GPIO_PIN_OFFSET	  0x00
#define _GPIO_DDR_OFFSET	  0x01
#define _GPIO_PORT_OFFSET	  0x02

/** Register Addresses ***************************/
#define _GPIO_B_ADDRESS		(_GPIO_BASE_ADDRESS + _SFR_OFFSET + _GPIO_B_OFFSET)
#define _GPIO_C_ADDRESS		(_GPIO_BASE_ADDRESS + _SFR_OFFSET + _GPIO_C_OFFSET)
#define _GPIO_D_ADDRESS		(_GPIO_BASE_ADDRESS + _SFR_OFFSET + _GPIO_D_OFFSET)

#define GPIO_B_PIN_ADDRESS	(_GPIO_B_ADDRESS + _GPIO_PIN_OFFSET)
#define GPIO_B_DDR_ADDRESS	(_GPIO_B_ADDRESS + _GPIO_DDR_OFFSET)
#define GPIO_B_PORT_ADDRESS	(_GPIO_B_ADDRESS + _GPIO_PORT_OFFSET)

#define GPIO_C_PIN_ADDRESS	(_GPIO_C_ADDRESS + _GPIO_PIN_OFFSET)
#define GPIO_C_DDR_ADDRESS	(_GPIO_C_ADDRESS + _GPIO_DDR_OFFSET)
#define GPIO_C_PORT_ADDRESS	(_GPIO_C_ADDRESS + _GPIO_PORT_OFFSET)

#define GPIO_D_PIN_ADDRESS	(_GPIO_D_ADDRESS + _GPIO_PIN_OFFSET)
#define GPIO_D_DDR_ADDRESS	(_GPIO_D_ADDRESS + _GPIO_DDR_OFFSET)
#define GPIO_D_PORT_ADDRESS	(_GPIO_D_ADDRESS + _GPIO_PORT_OFFSET)

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
	.pinB = (_IO u_gpio_t* const)(GPIO_B_PIN_ADDRESS),
	.ddrB = (_IO u_gpio_t* const)(GPIO_B_DDR_ADDRESS),
	.portB =(_IO u_gpio_t* const)(GPIO_B_PORT_ADDRESS),

	.pinC = (_IO u_gpio_t* const)(GPIO_C_PIN_ADDRESS),
	.ddrC = (_IO u_gpio_t* const)(GPIO_C_DDR_ADDRESS),
	.portC =(_IO u_gpio_t* const)(GPIO_C_PORT_ADDRESS),

	.pinD = (_IO u_gpio_t* const)(GPIO_D_PIN_ADDRESS),
	.ddrD = (_IO u_gpio_t* const)(GPIO_D_DDR_ADDRESS),
	.portD =(_IO u_gpio_t* const)(GPIO_D_PORT_ADDRESS)
};

#endif /* GPIO_H_ */
