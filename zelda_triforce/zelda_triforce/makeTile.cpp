#include "tileManager.h"

PTILE tileManager::makeTile(float x, float y, int ID)
{
	PTILE tile;

	switch (ID) {


	case BUSH:
		tile = new TILE(IMPASSABLE, BREAKABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;
	case BUSHOFF:
		tile = new TILE(PASSABLE, BREAKABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;
	case GRASS:
	case GRASSOFF:
	case WEED:
	case RUG:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;




	case TREELEAF1:
	case TREELEAF2:
	case TREELEAF3:
	case TREELEAF4:
	case TREELEAF5:
	case TREELEAF6:
	case TREELEAF7:
	case TREELEAF8:
	case TREELEAFINTER1:
	case TREELEAFINTER2:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, 2, IMAGEMANAGER->findImage(ID));
		break;

	case TREESTUMP1:
	case TREESTUMP2:
	case TREESTUMP3:
	case TREESTUMP4:
	case TREESTUMP5:
	case TREESTUMP6:
	case TREESTUMP7:
	case TREESTUMP8:
	case TREESTUMP10:
	case TREESTUMP11:
	case TREESTUMPINTER1:
	case TREESTUMPINTER2:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;
	case TREESTUMP9:
	case TREESTUMP12:
	case TREESTUMPINTER3:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;




	case STONE:
	case STONEB:
		tile = new TILE(IMPASSABLE, BREAKABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;
	case BIGSTONE1:
	case BIGSTONE2:
	case BIGSTONE3:
	case BIGSTONE4:
	case BIGSTONEB1:
	case BIGSTONEB2:
	case BIGSTONEB3:
	case BIGSTONEB4:
	case ST5NE1:
	case ST5NE2:
	case ST5NE3:
	case ST5NE4:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;



	case HOUSE1:
	case HOUSE2:
	case HOUSE3:
	case HOUSE4:
	case HOUSE5:
	case HOUSE6:
	case HOUSE7:
	case HOUSE8:
	case HOUSE9:
	case HOUSE10:
	case HOUSE11:
	case HOUSE12:
	case HOUSE13:
	case HOUSE14:
	case HOUSE15:
	case HOUSE16:
	case HOUSE17:
	case HOUSE18:
	case HOUSE19:
	case HOUSE20:
	case HOUSE21:
	case HOUSE22:
	case HOUSE23:
	case HOUSE24:
	case HOUSE25:
	case HOUSE26:
	case HOUSE27:
	case HOUSE28:
	case HOUSE29:
	case HOUSE30:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, 2, IMAGEMANAGER->findImage(ID));
		break;

	case HOUSE31:
	case HOUSE32:
	case HOUSE33:
	case HOUSE34:
	case HOUSE35:
	case HOUSE36:
	case HOUSE37:
	case HOUSE38:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;



	case FENCE1:
	case FENCE2:
	case FENCE3:
	case FENCE4:
	case FENCE5:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;

	case CLIFF1:
	case CLIFF2:
	case CLIFF3:
	case CLIFF4:
	case CLIFF5:
	case CLIFF6:
	case CLIFF7:
	case CLIFF8:
	case CLIFF9:
	case CLIFF10:
	case CLIFF11:
	case CLIFF12:
	case CLIFF13:
	case CLIFF14:
	case CLIFF15:
	case CLIFF16:
	case CLIFF17:
	case CLIFF18:
	case CLIFF19:
	case CLIFF20:
	case CLIFF21:
	case CLIFF22:
	case CLIFF23:
	case CLIFF24:
	case CLIFF25:
	case CLIFF26:
	case CLIFF27:
		tile = new TILE(IMPASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;

	case CLIFFIN1:
	case CLIFFIN2:
	case CLIFFIN3:
	case CLIFFIN4:
	case CLIFFIN5:
	case CLIFFIN6:
	case CLIFFIN7:
	case CLIFFIN8:
	case CLIFFIN9:
	case CLIFFIN10:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, 0, IMAGEMANAGER->findImage(ID));
		break;


	default:
		tile = new TILE(PASSABLE, IMMUTABLE, ID, x, y, 0, nullptr);
		break;
	}

	return tile;
}