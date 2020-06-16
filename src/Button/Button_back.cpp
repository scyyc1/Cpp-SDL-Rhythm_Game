#include "Button_back.h"

void Button_back::virtDoUpdate(int iCurrentTime)
{
	if (isDragged) {
		*stateId = 1;
	}
}
