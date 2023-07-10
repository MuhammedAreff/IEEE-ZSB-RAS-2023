#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>

#include"DIO_interface.h"

#include "CLCL_interface.h"

#include "KEYPAD_Interface.h"

int main()
{
	CLCD_voidInit();
	KPD_voidInit();
	u8 count;
	u8 c = 0;

	u8 Local_u8PressedKey;
	u8 pressed_Keys[10];
	u8 pass[10] = "arefmm";

	CLCD_voidSendData('*');

	while(1)
	{

		u8 key_Pressed = KPD_u8Getkey();
		_delay_ms(300);

				if(key_Pressed == 1){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '1';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 2){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '2';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 3){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '3';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 4){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '4';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 5){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '5';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 6){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '6';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 7){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '7';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 8){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '8';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 9){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '9';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == '*'){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '*';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == 0){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '0';
					c++;
					_delay_ms(35);
				}

				if(key_Pressed == '#'){
					LCD_displayCharacter('*');
					pressed_Keys[c] = '#';
					c++;
					_delay_ms(35);
				}

				if(c == 6){
					for(int i = 0; i < 5; i++){
						if(pressed_Keys[i] == pass[i]){
							CLCD_voidClear();
							CLCD_voidSendString("Correct Password");
							_delay_ms(35);
							CLCD_voidClear();
							CLCD_voidSendString("welcome");
							break;
						}
						else{
							CLCD_voidClear();
							CLCD_voidSendString("wrong pass");
							break;
						}
					}

				}




	}
}
