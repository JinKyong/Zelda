#pragma once
#include "stdafx.h"

/********* 타일 정보 *********/

#define TILEX	64
#define TILEY	64

typedef struct tagTile {
	float x, y, z;
	int r, g, b;
	RECT body;
}TILE, *PTILE;



/********* 타일 ID 값 *********/

#define sdfsd	15