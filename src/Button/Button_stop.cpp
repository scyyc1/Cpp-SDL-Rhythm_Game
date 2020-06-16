#include "Button_stop.h"

void Button_stop::virtDoUpdate(int iCurrentTime)
{
	if(isDragged)
		*isDraw = true;
}
