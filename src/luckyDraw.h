#pragma once
#include "header.h"
#include "TileManager.h"
#include "Configuration.h"
using namespace std;

class luckyDraw :
	public TileManager
{
public:
	luckyDraw() : TileManager(200, 200, 3, 1)
	{
		SimpleImage e = ImageManager::get()->getImagebyURL("./images/e.png", true, true);
		SimpleImage b = ImageManager::get()->getImagebyURL("./images/b.png", true, true);
		SimpleImage a = ImageManager::get()->getImagebyURL("./images/a.png", true, true);
		SimpleImage c = ImageManager::get()->getImagebyURL("./images/c.png", true, true);
		SimpleImage d = ImageManager::get()->getImagebyURL("./images/d.png", true, true);
		SimpleImage cherry = ImageManager::get()->getImagebyURL("./images/b_cherry.png", true, true);
		SimpleImage lemon = ImageManager::get()->getImagebyURL("./images/b_lemon.png", true, true);
		SimpleImage watermelon = ImageManager::get()->getImagebyURL("./images/b_watermelon.png", true, true);
		SimpleImage kiwi = ImageManager::get()->getImagebyURL("./images/b_kiwi.png", true, true);

		pictures.push_back(e);
		pictures.push_back(b);
		pictures.push_back(a);
		pictures.push_back(c);
		pictures.push_back(d);
		pictures.push_back(cherry);
		pictures.push_back(lemon);
		pictures.push_back(watermelon);
		pictures.push_back(kiwi);
	};
	~luckyDraw() {};
	void virtDrawTileAt(BaseEngine* pEngine,
		DrawingSurface* pSurface, int iMapX, int iMapY,
		int iStartPositionScreenX, int iStartPositionScreenY) const override;

private:
	vector<SimpleImage> pictures;
	int value_size = 9;
};

