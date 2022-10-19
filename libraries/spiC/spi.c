#include "spi.h"

/*
Pin	Direction, Master SPI	Direction, Slave SPI
MOSI	User defined 			Input
MISO	Input 				User defined
SCK 	User defined 			Input
SS 	User defined 			Input
*/

void _spi_init(uint8_t selection){
	if(selection == _spi__MASTER){
		spi.ddr->mosi = _OUTPUT;
		spi.ddr->sck = _OUTPUT;
		spi.ddr->ss = _OUTPUT;
	
		spi.bits->clockRate = _spi_clockRate__FCPU_DIV_64__2X_FCPU_DIV_32;
		spi.bits->master = _spi__MASTER;
		spi.bits->enable = _ENABLE;		
	}
	
	if(selection == _spi__SLAVE){
		spi.ddr->miso = _INPUT;
		spi.bits->enable = _ENABLE;
	}

	
}
void _spi_masterSendByte(uint8_t u8data){
	
	spi.bits->data = u8data;
	while(_spi__BUSY);
	
}

