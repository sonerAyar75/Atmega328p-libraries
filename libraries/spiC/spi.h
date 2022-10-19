#ifndef SPI_H_
#define SPI_H_
#ifndef STDINT_H
#include <stdint.h>
#endif

#ifndef INTERRUPT_H
#include <avr/interrupt.h>
#endif

#define _IO				volatile

#define BASE_ADDR_SPI	0x4C
#define BASE_ADDR_GPIO	0x23
#define OFFSET_GPIOB	0x00
#define OFFSET_REG_PIN	0x00
#define OFFSET_REG_DDR	0x01
#define OFFSET_REG_PORT	0x02

#define REG_ADDR_PINB	BASE_ADDR_GPIO + OFFSET_GPIOB + OFFSET_REG_PIN  //23 + 0 + 0 -> 23
#define REG_ADDR_DDRB	BASE_ADDR_GPIO + OFFSET_GPIOB + OFFSET_REG_DDR  //23 + 0 + 1 -> 24
#define REG_ADDR_PORTB	BASE_ADDR_GPIO + OFFSET_GPIOB + OFFSET_REG_PORT //23 + 0 + 2 -> 25

#define _DUMY_DATA		0xFF

/*				
SPI2X	SPR1	SPR0	SPR	SCK Frequency
0		0		0		0	fosc/4
0		0		1		1	fosc/16
0		1		0		2	fosc/64
0		1		1		3	fosc/128
				
1		0		0		0	fosc/2
1		0		1		1	fosc/8
1		1		0		2	fosc/32
1		1		1		3	fosc/64
SPR0 and SPR1 are written as 2 bit SPR				
*/	

#define	_spi_clockRate__FCPU_DIV_4__2X_FCPU_DIV_2		0
#define	_spi_clockRate__FCPU_DIV_16__2X_FCPU_DIV_8		1
#define	_spi_clockRate__FCPU_DIV_64__2X_FCPU_DIV_32		2
#define	_spi_clockRate__FCPU_DIV_128__2X_FCPU_DIV_64	3

/*
SPI Mode	Conditions 		Leading Edge 		Trailing Edge
0			CPOL=0, CPHA=0 	Sample (rising) 	Setup (falling)
1			CPOL=0, CPHA=1 	Setup (rising) 		Sample (falling)
2			CPOL=1, CPHA=0 	Sample (falling) 	Setup (rising)
3			CPOL=1, CPHA=1 	Setup (falling) 	Sample (rising)
*/	

#define	_spi_mode__0_SAMPLE_RISING_SETUP_FALLING	0
#define	_spi_mode__1_SETUP_RISING_SAMPLE_FALLING	1
#define	_spi_mode__2_SAMPLE_FALLING_SETUP_RISING	2
#define	_spi_mode__3_SETUP_FALLING_SAMPLE_RISING	3

#define _spi__SLAVE		0
#define _spi__MASTER	1

#define _spi_dataOrder__MSB_FIRST	0
#define _spi_dataOrder__LSB_FIRST	1

#define _DISABLE	0
#define _ENABLE		1

#define _INPUT	0
#define _OUTPUT 1

#define _LOW	0
#define _HIGH	1

#define _spi__BUSY	spi.bits->intFlag == 0

typedef struct{
	uint8_t _res0:2;
	uint8_t ss:1;
	uint8_t mosi:1;
	uint8_t miso:1;
	uint8_t sck:1;
	uint8_t _res1:2;
}s_spi_gpio_t;

typedef struct{
	uint8_t	clockRate:2;
	uint8_t	mode:2;
	uint8_t	master:1;
	uint8_t	dataOrder:1;
	uint8_t	enable:1;
	uint8_t	intEnable:1;
	uint8_t	doubleSpeed:1;
	uint8_t	_res:5;
	uint8_t	writeColFlag:1;
	uint8_t	intFlag:1;
	uint8_t data:8;
}s_spi_t;

//void _spi_initStatic(void(*function)(uint8_t));
void _spi_init(uint8_t);
void _spi_masterSendByte(uint8_t);

typedef struct{
	_IO s_spi_t* bits;
	_IO s_spi_gpio_t* pin;
	_IO s_spi_gpio_t* ddr;
	_IO s_spi_gpio_t* port;
	void (*init)(uint8_t);
	void (*sendByte)(uint8_t);
}s_spi_dev;

static const s_spi_dev spi = {
	.bits = (_IO s_spi_t*)(BASE_ADDR_SPI),
	.pin = (_IO s_spi_gpio_t*)(REG_ADDR_PINB),
	.ddr = (_IO s_spi_gpio_t*)(REG_ADDR_DDRB),
	.port = (_IO s_spi_gpio_t*)(REG_ADDR_PORTB), 
	.init = _spi_init,
	.sendByte = _spi_masterSendByte,
};

#endif /* SPI_H_ */









/*
static void _spi_masterInit(){
	spi.ddr->mosi = _OUTPUT;
	spi.ddr->sck = _OUTPUT;
	spi.ddr->ss = _OUTPUT;
	spi.bits->master = _spi__MASTER;
	
	spi.bits->clockRate = _spi_clockRate__FCPU_DIV_64__2X_FCPU_DIV_32;
	spi.bits->mode = _spi_mode__0_SAMPLE_RISING_SETUP_FALLING;
	spi.bits->dataOrder = _spi_dataOrder__MSB_FIRST;
	
	spi.bits->enable = _ENABLE;
	
}

void _spi_masterSendByte(uint8_t u8data){
	spi.bits->data = u8data;
	while(_spi__BUSY);
}

*/