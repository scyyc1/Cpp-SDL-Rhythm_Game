#include "Button_start.h"
#include "../Scyyc1Engine.h"

void Button_start::virtDoUpdate(int iCurrentTime)
{
	if (isDragged) {
		*stateId = 2;
	}
}
