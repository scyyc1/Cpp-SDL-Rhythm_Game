#include "Button_rank.h"

void Button_rank::virtDoUpdate(int iCurrentTime)
{
	if (isDragged)
		*this->stateId = 7;
}
