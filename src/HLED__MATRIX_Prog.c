#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_Interface.h"
#include "SYSTIC_Inteface.h"
#include "HLED__MATRIX_Interface.h"
#include "HLED__MATRIX_Cfg.h"

u8* HLEDMAT_u8Frame;
u8 HLEDMAT_u8CurrentIdx ;
void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		/* Disable all Columns */
	   LEDMATRIX_voidDisableColumns();

	   /* Row Value */

	   LEDMATRIX_voiRowdVal(Copy_u8Frame[i]);

	   /* Active Current Column */
	   if(i==0)
	   {
		   DIO_WritePin(LEDMAT_COL_0,LOW);  //(PINB5 -PINB10)
	   }
	   else if(i==1)
	   {
		   DIO_WritePin(LEDMAT_COL_1,LOW);  //PINB12 - PINB13
	   }
	   else if(i==2)
	   {
		   DIO_WritePin(LEDMAT_COL_2,LOW);  //PINB12 - PINB13
	   }
	   else if(i==3)
	   {
		   DIO_WritePin(LEDMAT_COL_3,LOW);  //PINB12 - PINB13
	   }
	   else if(i==4)
	   {
		   DIO_WritePin(LEDMAT_COL_4,LOW);  //PINB12 - PINB13
	   }
	   else if(i==5)
	   {
		   DIO_WritePin(LEDMAT_COL_5,LOW);  //PINB12 - PINB13
	   }
	   else if(i==6)
	   {
		   DIO_WritePin(LEDMAT_COL_6,LOW);  //PINB12 - PINB13
	   }
	   else if(i==7)
	   {
		   DIO_WritePin(LEDMAT_COL_7,LOW);  //PINB12 - PINB13
	   }


	   MYSYSTICK_VoidDelayUs(2500);
	}

}

void LED_MATRIX_Animation(u8(*arr)[8],u8 arr_rows,u8 arr_cols)
{
	u16 size=arr_rows*arr_cols;
	for(u8 i=0;i<size;i++)
	{
		HLEDMAT_voidDisplayFrame((u8*)arr+i);
		MYSYSTICK_VoidDelayMs(30);

	}
}
void LED_MATRIX_Animation2(u8(*arr)[8],u8 arr_rows,u8 size)
{

	for(u8 i=0;i<size;i++)
	{
		HLEDMAT_voidDisplayFrame(arr[i]);
		MYSYSTICK_VoidDelayMs(500);

	}
}
void LedMatrix_Off(void)
{
	LEDMATRIX_voidDisableColumns();
}


void LEDMATRIX_voidDisableColumns(void)
{
	DIO_WritePin(LEDMAT_COL_0,HIGH);
	DIO_WritePin(LEDMAT_COL_1,HIGH);
	DIO_WritePin(LEDMAT_COL_2,HIGH);
	DIO_WritePin(LEDMAT_COL_3,HIGH);
	DIO_WritePin(LEDMAT_COL_4,HIGH);
	DIO_WritePin(LEDMAT_COL_5,HIGH);
	DIO_WritePin(LEDMAT_COL_6,HIGH);
	DIO_WritePin(LEDMAT_COL_7,HIGH);
}
void LEDMATRIX_voiRowdVal(u8 val)
{
	DIO_WritePin(LEDMAT_ROW_0,READ_BIT(val,0));
	DIO_WritePin(LEDMAT_ROW_1,READ_BIT(val,1));
	DIO_WritePin(LEDMAT_ROW_2,READ_BIT(val,2));
	DIO_WritePin(LEDMAT_ROW_3,READ_BIT(val,3));
	DIO_WritePin(LEDMAT_ROW_4,READ_BIT(val,4));
	DIO_WritePin(LEDMAT_ROW_5,READ_BIT(val,5));
	DIO_WritePin(LEDMAT_ROW_6,READ_BIT(val,6));
	DIO_WritePin(LEDMAT_ROW_7,READ_BIT(val,7));

}
