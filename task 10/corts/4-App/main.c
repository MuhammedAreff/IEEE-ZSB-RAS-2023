#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "util/delay.h"

#define spongebob 0
#define tetris 1
#define blocks 2

void main(void)
{
	CLCD_voidInit();
	CLCD_void_Save_in_CGRAM();


	int x=0,y=0;

	u8 switch1;
	u8 switch2;
	u8 switch3;
	u8 switch4;



	CLCD_voidGoToPosition(0,x);
	CLCD_voidString("1)");
	CLCD_voidSendData(tetris);
	CLCD_voidString("2)");
	CLCD_voidSendData(blocks);
	CLCD_voidString("3)");
	CLCD_voidSendData(spongebob);
	CLCD_voidString("4)CLR");
	CLCD_voidGoToPosition(1,x);
	CLCD_voidString("press to start  ");
	_delay_ms(250);

	DIO_voidSetPortVal(DIO_PORTD,0xFF);
	_delay_ms(50);
	while(1){

		switch1 = DIO_u8GetPinVal(DIO_PORTD,DIO_PIN0);
		switch2 = DIO_u8GetPinVal(DIO_PORTD,DIO_PIN1);
		switch3 = DIO_u8GetPinVal(DIO_PORTD,DIO_PIN2);
		switch4 = DIO_u8GetPinVal(DIO_PORTD,DIO_PIN3);
		_delay_ms(100);

		if(!switch1)
		{

			CLCD_voidSendData(tetris);
			_delay_ms(100);

			y++;
			x++;
		}
		if(!switch2)
		{

			CLCD_voidSendData(blocks);
			_delay_ms(100);
			y++;
			x++;
		}
		if(!switch3)
		{

			CLCD_voidSendData(spongebob);
			_delay_ms(100);
			y++;
			x++;
		}
		if(!switch4)
		{
			CLCD_voidClear();
			x=0;
		}
		if(x==15)
		{
			CLCD_voidGoToPosition(1,0);
		}
		if(x==31||(y==1))
		{
			CLCD_voidClear();
			x=0;

		}

		DIO_voidSetPinVal(DIO_PORTD,DIO_PIN0,HIGH);
		DIO_voidSetPinVal(DIO_PORTD,DIO_PIN1,HIGH);
		DIO_voidSetPinVal(DIO_PORTD,DIO_PIN2,HIGH);
		DIO_voidSetPinVal(DIO_PORTD,DIO_PIN3,HIGH);

	}


}

