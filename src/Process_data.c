#include "Talkthrough.h"
#include "filters.h"
#include "buttons.h"

//--------------------------------------------------------------------------//
// Function:	Process_Data()												//
//																			//
// Description: This function is called from inside the SPORT0 ISR every 	//
//				time a complete audio frame has been received. The new 		//
//				input samples can be found in the variables iChannel0LeftIn,//
//				iChannel0RightIn, iChannel1LeftIn and iChannel1RightIn 		//
//				respectively. The processed	data should be stored in 		//
//				iChannel0LeftOut, iChannel0RightOut, iChannel1LeftOut,		//
//				iChannel1RightOut, iChannel2LeftOut and	iChannel2RightOut	//
//				respectively.												//
//--------------------------------------------------------------------------//

#define FILTER

extern volatile int filterIndex;


void Process_Data(void)
{
	u32 i;
	
	for (i = EZ_FIRST_BUTTON; i < EZ_NUM_BUTTONS; i++)
	{
        if (ezIsButtonPushed(i))
        {
        	filterIndex = i;	
        }
    }
    
	#ifdef FILTER

	iChannel0LeftOut = filter(iChannel0LeftIn, left0);
	iChannel0RightOut = filter(iChannel0RightIn, right0);
	iChannel1LeftOut = filter(iChannel1LeftIn, left1);
	iChannel1RightOut = filter(iChannel1RightIn, right1);

	#else
	
	iChannel0LeftOut = iChannel0LeftIn;
	iChannel0RightOut = iChannel0RightIn;
	iChannel1LeftOut = iChannel1LeftIn;
	iChannel1RightOut = iChannel1RightIn;
	
	#endif
}
