#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_Interface.h"
//choose from these
       /*
            INFREE\
            INPULL
		    INDOWN
		    INANALOG
		    OUT_LOWSPEED_PP
            OUT_LOWSPEED_OD
			OUT_LOWSPEED_AF_PP
			OUT_LOWSPEED_AF_OD
			OUT_MEDIUMSPEED_PP
			OUT_MEDIUMSPEED_OD
			OUT_MEDIUMSPEED_AF_PP
			OUT_MEDIUMSPEED_AF_OD
			OUT_HIGHSPEED_PP
			OUT_HIGHSPEED_OD
			OUT_HIGHSPEED_AF_PP
			OUT_HIGHSPEED_AF_OD

		*/


DIO_PinStatus_t DIO_ArrStatus[TOTAL_PINS]=
{
		OUT_LOWSPEED_PP,       /*  PINA0       */
		OUT_LOWSPEED_PP,       /*  PINA1       */
		OUT_LOWSPEED_PP,       /*  PINA2       */
		OUT_LOWSPEED_PP,       /*  PINA3       */
		OUT_LOWSPEED_AF_PP,       /*  PINA4       */
		OUT_LOWSPEED_AF_PP,       /*  PINA5       */
		OUT_LOWSPEED_AF_PP,       /*  PINA6       */
		OUT_LOWSPEED_AF_PP,       /*  PINA7       */
		OUT_LOWSPEED_PP,       /*  PINA8       */
		OUT_LOWSPEED_AF_PP,       /*  PINA9       */
		OUT_LOWSPEED_AF_PP,       /*  PINA10      */
		OUT_LOWSPEED_PP,       /*  PINA11      */
		OUT_LOWSPEED_PP,       /*  PINA12      */
		OUT_LOWSPEED_PP,       /*  PINA13      */
		OUT_LOWSPEED_PP,       /*  PINA14      */
		OUT_LOWSPEED_PP,       /*  PINA15      */
		OUT_LOWSPEED_PP,       /*  PINB0       */
		OUT_LOWSPEED_PP,       /*  PINB1       */
		OUT_LOWSPEED_PP,	   /*  PINB2       */
		OUT_LOWSPEED_PP,	   /*  PINB3       */
		OUT_LOWSPEED_PP,	   /*  PINB4       */
		OUT_LOWSPEED_PP,	   /*  PINB5       */
		OUT_LOWSPEED_PP,	   /*  PINB6       */
		OUT_LOWSPEED_PP,	   /*  PINB7       */
		OUT_LOWSPEED_PP,       /*  PINB8       */
		OUT_LOWSPEED_PP,       /*  PINB9       */
		OUT_LOWSPEED_PP,	   /*  PINB10      */
		OUT_LOWSPEED_PP,	   /*  PINB11      */
		OUT_LOWSPEED_PP,	   /*  PINB12      */
		OUT_LOWSPEED_PP,	   /*  PINB13      */
		OUT_LOWSPEED_PP,	   /*  PINB14      */
		OUT_LOWSPEED_PP,	   /*  PINB15      */
		OUT_LOWSPEED_PP,	   /*  PINC13      */
		OUT_LOWSPEED_PP,       /*  PINC14      */
		OUT_LOWSPEED_PP,	   /*  PINC15      */
};



