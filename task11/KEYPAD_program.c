#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "util/delay.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "KEYPAD_config.h"
#include "KEYPAD_private.h"

void KPD_voidInit(void)
{
   //ROWS INPUT PULLUP
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_IN,KPAD_R0);
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_IN,KPAD_R1);
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_IN,KPAD_R2);
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_IN,KPAD_R3);

	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_R0);
	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_R1);
	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_R2);
	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_R3);


	//COLS OUTPUT HIGH
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_OUT,KPAD_C0);
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_OUT,KPAD_C1);
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_OUT,KPAD_C2);
	DIO_voidSetPinDir(KPAD_PORT,DIO_PIN_DIR_OUT,KPAD_C3);

	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_C0);
	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_C1);
	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_C2);
	DIO_voidSetPinVal(KPAD_PORT,DIO_PIN_VAL_HIGH,KPAD_C3);

}



u8 KPD_u8Getkey(void)
{

	    u8 Local_u8RetrunedValue = 255 ;
	    u8 Local_u8GetPressed   ;
	    u8 Local_u8Col            ;
	    u8 Local_u8Row          ;

	    for(Local_u8Col = 0 + KPAD_COL_INIT ; Local_u8Col < KPAD_COL_END + 1 ; Local_u8Col++ )
	    {
	        DIO_voidSetPinVal(KPAD_PORT , Local_u8Col , DIO_PIN_VAL_LOW);
	        for(Local_u8Row = 0 + KPAD_ROW_INIT ; Local_u8Row < KPAD_ROW_END + 1 ; Local_u8Row++)
	        {

	           Local_u8GetPressed = DIO_u8GetPinVal(KPAD_PORT , Local_u8Row);
	           if(Local_u8GetPressed == 0)
	           {
	            /*  Debouncing */
	            _delay_ms(50);
	            Local_u8GetPressed = DIO_u8GetPinVal(KPAD_PORT , Local_u8Row);
	            if(Local_u8GetPressed == 0)
	            {
	                Local_u8RetrunedValue = KPAD_Au8Values[Local_u8Row - KPAD_ROW_INIT][Local_u8Col - KPAD_COL_INIT];
	            }
	            while(Local_u8GetPressed ==0 )
	            {
	                Local_u8GetPressed = DIO_u8GetPinVal(KPAD_PORT , Local_u8Row);

	            }

	           }

	        }

	        DIO_voidSetPinVal(KPAD_PORT , Local_u8Col , DIO_PIN_VAL_HIGH);
	    }


	    return Local_u8RetrunedValue ;

}

