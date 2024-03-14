#include "StdTypes.h"
#include "Utils.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Cfg.h"


void SPI_Master_Init(void)
{
	//CLK_Val
	SPI1->CR1&=~(THREE_BIT_MASK<<3);
	SPI1->CR1|=(SPI_SCALER<<3);


	//Polarity
	WRITE_BIT(SPI1->CR1,CPOL,SPI_CLK_POLARITY);

	//Phase
	WRITE_BIT(SPI1->CR1,CPHA,SPI_CLK_PHASE);


	//Data Format
	WRITE_BIT(SPI1->CR1,DF,SPI_DATA_FORMAT);


	// MSB-LSB
	WRITE_BIT(SPI1->CR1,LSBFIRST,SPI_FRAME_FORMAT);

	//Master Select  -SPI Enable
	SPI1->CR1|=(1<<MSTR) |(1<<SPE);



	//SPI Enable
	//SPI1->CR1=(1<<SPE);



}

void SPI_Slave_Init(void)
{
	//Data Format
	WRITE_BIT(SPI1->CR1,DF,SPI_DATA_FORMAT);
	//Polarity
	WRITE_BIT(SPI1->CR1,CPOL,SPI_CLK_POLARITY);

	//Phase
	WRITE_BIT(SPI1->CR1,CPHA,SPI_CLK_PHASE);

	// MSB-LSB
	WRITE_BIT(SPI1->CR1,LSBFIRST,SPI_FRAME_FORMAT);

	//Slave Select  -SPI Enable
	SPI1->CR1=((SPI1->CR1)&(~(1<<MSTR)) |(1<<SPE));





}

u16 SPI_Send_Receive(u16 data)
{
	while(!READ_BIT(SPI1->SR,TXE));
	SPI1->DR=data;

  while(!READ_BIT(SPI1->SR,RXNE));


	return (SPI1->DR);

}
