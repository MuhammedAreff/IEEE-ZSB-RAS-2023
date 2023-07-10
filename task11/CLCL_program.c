#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "CLCL_interface.h"
#include "util/delay.h"


void CLCD_voidSendCommand( u8 CLCD_u8Command)
{
	/*set Rs=>0*/
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_LOW,DIO_PIN0);
	/*set RW=>0*/
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_LOW,DIO_PIN1);
	/*send command */
	DIO_voidSetPortVal(DIO_PORTD,CLCD_u8Command);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_HIGH,DIO_PIN2);
	_delay_ms(1);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_LOW,DIO_PIN2);




}
void CLCD_voidSendData( u8 CLCD_u8Data)
{
	/*set Rs=>0*/
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_HIGH,DIO_PIN0);
	/*set RW=>0*/
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_LOW,DIO_PIN1);
	/*send command */
	DIO_voidSetPortVal(DIO_PORTD,CLCD_u8Data);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_HIGH,DIO_PIN2);
	_delay_ms(1);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_LOW,DIO_PIN2);


}
void CLCD_voidInit(void)
{
	DIO_voidSetPortDir(DIO_PORTD,DIO_PORT_OUT);
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN_DIR_OUT,DIO_PIN0);
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN_DIR_OUT,DIO_PIN1);
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN_DIR_OUT,DIO_PIN2);
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00001100);
	_delay_ms(1);
	CLCD_voidSendCommand(0b00000001);
	_delay_ms(2);
}
void CLCD_voidSendString(u8 * pvString)
{
	u8 i=0;
	while(pvString[i]!='\0')
	{
		CLCD_voidSendData(pvString[i]);
		i++;
	}
}
void CLCD_voidGoToPosition(u8 CLCD_u8x,u8 CLCD_u8y)
{
	u8 CLCD_u8Position;
	if(CLCD_u8x==0)
	{
		CLCD_u8Position=CLCD_u8y;
	}
	else if(CLCD_u8x==1)
	{
		CLCD_u8Position=CLCD_u8y+0x40;
	}
	CLCD_voidSendCommand(CLCD_u8Position+128);
}
void CLCD_voidClear(void)
{
	CLCD_voidSendCommand(0x01);
}
void LCD_displayCharacter(u8 data)
{
	DIO_voidSetPinVal(DIO_PORTC, DIO_PIN_VAL_HIGH,DIO_PIN0);
	_delay_ms(1);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_HIGH, DIO_PIN2);
	_delay_ms(1);
	DIO_voidSetPortVal(DIO_PORTD, data);
	_delay_ms(1);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN_VAL_LOW, DIO_PIN2);
	_delay_ms(1);
}
void CLCD_voidSend_Num(u32 _NUM)
{
	u8 arr[10],i=0,j=0;
	if(_NUM==0)
	{
		CLCD_voidSendData('0');
	}
	else
	{
		while(_NUM)
		{
			arr[i]=_NUM%10+'0';
			_NUM/=10;
			i++;
		}
		for(j=i;j>0;j--)
		{
			CLCD_voidSendData(arr[j-1]);
		}

	}
}



