/**
*    Bare necessities for reading buttons imported from ezkitutilities.c
*    Compatible with BF533 only.
*
*    Saracut Stelian - Adrian
*    2018
*/

#include "buttons.h"

ADI_FLAG_ID ezButtonToFlag[] = {
    ADI_FLAG_PF8,           // button 0
    ADI_FLAG_PF9,           // button 1
    ADI_FLAG_PF10,          // button 2
    ADI_FLAG_PF11           // button 3
};

void ezInitButton(u32 Button) // enables a button
{

    // make sure the button is valid
    if (Button >= EZ_NUM_BUTTONS) return;

    // open the flag and make it an input
    adi_flag_Open(ezButtonToFlag[Button]);
    adi_flag_SetDirection(ezButtonToFlag[Button], ADI_FLAG_DIRECTION_INPUT);

}

u32 ezIsButtonPushed(u32 Button)        // returns TRUE if button is pushed, FALSE otherwise
{
    u32 Value;

    // make sure the button is valid
    if (Button >= EZ_NUM_BUTTONS) return (FALSE);

    // sense it
    adi_flag_Sense(ezButtonToFlag[Button], &Value);

    // return
    return (Value);

}
