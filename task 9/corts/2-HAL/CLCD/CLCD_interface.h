#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
#include "STD_TYPES.h"
#include "CLCD_private.h"

void CLCD_voidSendData(u8 CLCD_u8Data);
void CLCD_voidSendCommand(u8 CLCD_u8Command);
void CLCD_voidInit(void);
void CLCD_voidClear(void);
void CLCD_void_Save_in_CGRAM(void);
void CLCD_voidString(u8*pvString);
void CLCD_voidGoToPosition(u8 CLCD_u8x,u8 CLCD_u8y);


#endif
