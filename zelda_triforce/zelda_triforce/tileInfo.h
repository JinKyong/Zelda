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

/********** Z�� **********/
#define Z0	0
#define Z1	1
#define Z2	2

/********** RED **********/
#define PASSABLE	0		//������ �� ����
#define IMPASSABLE	255		//������ �� ����



/********** GREEN **********/
#define IMMUTABLE	0		//�Һ�
#define BREAKABLE	60		//�ı� ����



/********** BLUE **********/
#define	PLAYER		0

//========= bush =========//
#define BUSH	1
#define BUSHOFF	2

//========= tree =========//
#define TREELEAF1		10
#define TREELEAF2		11
#define TREELEAF3		12
#define TREELEAF4		13
#define TREELEAF5		14
#define TREELEAF6		15
#define TREELEAF7		16
#define TREELEAF8		17
#define TREELEAF9		18
#define TREELEAF10		19
#define TREESTUMP1		20
#define TREESTUMP2		21
#define TREESTUMP3		22
#define TREESTUMP4		23
#define TREESTUMP5		24
#define TREESTUMP6		25
#define TREESTUMP7		26
#define TREESTUMP8		27
#define TREESTUMP9		28
#define TREESTUMP10		29





