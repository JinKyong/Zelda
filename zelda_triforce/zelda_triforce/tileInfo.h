#pragma once
#include "stdafx.h"

#define TILEX	64
#define TILEY	64

typedef struct tagTile {
	int r, g, b;
	float x, y, z;

	image* img;
	RECT body;

	tagTile(int R, int G, int B,
		float X, float Y, float Z,
		image* IMG) {
		r = R;
		g = G;
		b = B;
		x = X;
		y = Y;
		z = Z;
		img = IMG;
		body = RectMake(X, Y, TILEX, TILEY);
	}
} TILE, *PTILE;



/********** RED **********/
#define PASSABLE	0		//지나갈 수 있음
#define IMPASSABLE	255		//지나갈 수 없음



/********** GREEN **********/
#define IMMUTABLE	0		//불변
#define BREAKABLE	60		//파괴 가능



/********** BLUE **********/
#define	PLAYER		0
#define BASE		255

//========= tree =========//

#define TREE1		10
#define TREE2		11
#define TREE3		12
#define TREE4		13
#define TREE5		14
#define TREE6		15
#define TREE7		16
#define TREE8		17
#define TREE9		18
#define TREE10		19
#define TREE11		20
#define TREE12		21
#define TREEDOWN1	22
#define TREEDOWN2	23
#define TREEDOWN3	24
#define TREEDOWN4	25
#define TREEDOWN5	26
#define TREEDOWN6	27
#define TREEDOWN7	28
#define TREEDOWN8	29





///********** Z축 **********/
//#define ZBRIDGE	0
//#define ZTEST1	0
//#define ZTEST2	0
//#define ZTEST3	0
//#define ZTEST4	0