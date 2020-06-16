#include "Button_exit.h"

void Button_exit::virtDoUpdate(int iCurrentTime)
{
	if (isDragged) {
		getEngine()->setExitWithCode(0);
	}
}
