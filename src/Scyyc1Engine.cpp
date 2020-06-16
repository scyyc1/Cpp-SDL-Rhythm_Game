#include "header.h"
#include "Scyyc1Engine.h"
#include "Configuration.h"

int Scyyc1Engine::virtInitialise()
{
	getBackgroundSurface()->setDrawPointsFilter(&Translation);
	getForegroundSurface()->setDrawPointsFilter(&Translation);
	return BaseEngine::virtInitialise();
}

void Scyyc1Engine::virtSetupBackgroundBuffer()
{
	s->virtSetupBackgroundBuffer();
}

int Scyyc1Engine::virtInitialiseObjects()
{
	s->virtInitialiseObjects();
	return 0;
}

void Scyyc1Engine::virtDrawStringsOnTop()
{
	s->virtDrawStringsOnTop();
}

void Scyyc1Engine::virtDrawStringsUnderneath()
{
	s->virtDrawStringsUnderneath();
}

// When releasing a key, the controller 
void Scyyc1Engine::virtKeyUp(int iKeyCode)
{
	s->virtKeyUp(iKeyCode);
}

void Scyyc1Engine::virtKeyDown(int iKeyCode)
{
	switch (iKeyCode) {
	case SDLK_i:Translation.changeOffset(0, -5); break;
	case SDLK_k:Translation.changeOffset(0, 5); break;
	case SDLK_j:Translation.changeOffset(-5, 0); break;
	case SDLK_l:Translation.changeOffset(5, 0); break;
	}
	redrawDisplay();
	s->virtKeyDown(iKeyCode);
}

void Scyyc1Engine::virtMouseDown(int iButton, int iX, int iY)
{
	s->virtMouseDown(iButton, iX, iY);
}


void Scyyc1Engine::virtMouseUp(int iButton, int iX, int iY)
{
	s->virtMouseUp(iButton, iX, iY);
}

void Scyyc1Engine::virtMouseMoved(int iX, int iY)
{
	s->virtMouseMoved(iX, iY);
}

void Scyyc1Engine::virtMainLoopDoBeforeUpdate()
{
	s->virtMainLoopDoBeforeUpdate();
}

void Scyyc1Engine::virtMainLoopDoAfterUpdate()
{
	s->virtMainLoopDoAfterUpdate();
}

void Scyyc1Engine::virtMainLoopPreUpdate()
{
	s->virtMainLoopPreUpdate();
}

void Scyyc1Engine::virtMainLoopPostUpdate()
{
	if (currentState!=stateNum) {
		createObjectArray(0);
		clearContents();
		stateNum = currentState;
		switchState(stateNum);
	}
}

void Scyyc1Engine::virtMainLoopStartIteration()
{
}

void Scyyc1Engine::copyAllBackgroundBuffer()
{
	s->copyAllBackgroundBuffer();
}

bool Scyyc1Engine::mapCoordinates(double& x, double& y, const SimpleImage& image)
{
	
	if (!checkRotateBorder(x, y, image))
		return false;

	x -= image.getWidth() / 2;
	y -= image.getHeight() / 2;

	double angle = atan(y / (x + 0.0001));
	if (x < 0)
		angle += M_PI;
	double hyp = ::sqrt(x * x + y * y);
	int offset = getModifiedTime() / 10;
	angle += (double)offset / 100;

	x = hyp * ::cos(angle);
	y = hyp * ::sin(angle);

	x += image.getWidth() / 2;
	y += image.getHeight() / 2;
	
	if (!checkRotateBorder(x, y, image))
		return false;
	return false;
}

bool Scyyc1Engine::checkRotateBorder(double& x, double& y, const SimpleImage& image)
{
	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= (image.getWidth() - 0.5)) return false;
	if (y >= (image.getHeight() - 0.5)) return false;
}
