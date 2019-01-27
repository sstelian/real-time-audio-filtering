/**
*    Bare necessities for reading buttons imported from ezkitutilities.h
*    Compatible with BF533 only.
*
*    Saracut Stelian - Adrian
*    2018
*/

#ifndef __Buttons_DEFINED
#define __Buttons_DEFINED

#include <services/services.h>      // system service includes
#include <sysreg.h>                 // system config definitions

#define EZ_NUM_BUTTONS  (4)         // number of buttons on the board
#define EZ_FIRST_BUTTON     (0)                         // First Button
#define EZ_LAST_BUTTON     (EZ_NUM_BUTTONS - 1)        // Last Button

ADI_FLAG_ID ezButtonToFlag[]; //structure containing the pf mappings for buttons

void    ezInitButton        (u32 Button);   // enables/configures a button for use
u32     ezIsButtonPushed    (u32 Button);   // senses if a button is pushed

#endif
