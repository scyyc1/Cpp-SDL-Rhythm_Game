#pragma once
#include "header.h"
#include "TileManager.h"
#include "ImageManager.h"
using namespace std;
constexpr auto LIFE_IS_COST = 0;

class lifeManager :
	public TileManager
{
public:
	lifeManager();
	~lifeManager();
	void virtDrawTileAt(BaseEngine* pEngine, 
		DrawingSurface* pSurface, int iMapX, int iMapY, 
		int iStartPositionScreenX, int iStartPositionScreenY) const override;

	// Return how many time left for missing notes
	int getLife() { return life; };
	// Cost 1 life each time for 1 miss of note
	void costLife() 
	{ 
		if (life > 0)
		{
			this->life -= 1;
		}
		cout << life << endl;
	};

	// Return the coordinate of life in the life-tileManager
	int getLifeX() { return (this->life - 1) % m_iMapWidth; };
	int getLifeY() { return (this->life - 1) / m_iMapWidth; };

private:
	int life;
	SimpleImage image;
};

