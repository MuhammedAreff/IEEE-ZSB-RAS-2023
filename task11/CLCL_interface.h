#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand( u8 CLCD_u8Command);
void CLCD_voidSendData( u8 CLCD_u8Data);
void CLCD_voidInit(void);
void CLCD_voidSendString(u8 * pvString);
void CLCD_voidGoToPosition(u8 CLCD_u8x,u8 CLCD_u8y);
void CLCD_voidSend_Num(u32 _NUM);
void LCD_displayCharacter(u8 data);
void CLCD_voidClear(void);









#endif
