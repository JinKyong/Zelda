#pragma once
#include "singletonBase.h"
#include "item.h"

class item;

class inventoryManager : public singletonBase<inventoryManager>
{
private:
	typedef vector<item*>			itemList;
	typedef vector<item*>::iterator itemIter;

private:
	itemList _vItem;
	itemIter _viItem;

	image* _bgImg;

	item* _boomerang;
	item* _candela;
	item* _mushroom;

	int _a, _b;

	RECT _selItemRc;
	image* _selImg;
	float _count;
	int _index;

	bool _open;

public:
	inventoryManager() {};
	~inventoryManager() {};

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	void addItem(item* item);

	void controlKey();
	void controlFrame();

	void setOpen(bool open) { _open = open; }
	bool isOpen() { return _open; }
};