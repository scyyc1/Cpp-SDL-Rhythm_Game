#include "Button_load.h"

void Button_load::virtDoUpdate(int iCurrentTime)
{
	if (isDragged) {
		*this->stateId = 3;
	}
}
