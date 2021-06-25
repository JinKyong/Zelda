#pragma once
#include "stdafx.h"

#define TILEX	64
#define TILEY	64

typedef struct tagTile {
	int r, g, b;
	float x, y, z;

	int sizeX;
	int sizeY;

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

/********** Z축 **********/
#define Z0	0
#define Z1	1
#define Z2	2

/********** RED(COLLISION) **********/
#define PASSABLE	0		//지나갈 수 있음
//#define HALFPASSABLE
#define IMPASSABLE	255		//지나갈 수 없음



/********** GREEN(BOOL) **********/
#define IMMUTABLE	0		//불변
#define THROWABLE	30		//던지기 가능(들기 가능)
#define BREAKABLE	60		//파괴 가능



/********** BLUE(TILE ID) **********/
#define	PLAYER		0

//========= bush =========//
#define BUSH		1
#define BUSHOFF		2
#define GRASS		3
#define GRASSOFF	4
#define WEED		5
#define RUG			6

//========= tree =========//
#define TREELEAF1		7
#define TREELEAF2		8
#define TREELEAF3		9
#define TREELEAF4		10
#define TREELEAF5		11
#define TREELEAF6		12
#define TREELEAF7		13
#define TREELEAF8		14
#define TREESTUMP1		15
#define TREESTUMP2		16
#define TREESTUMP3		17
#define TREESTUMP4		18
#define TREESTUMP5		19
#define TREESTUMP6		20
#define TREESTUMP7		21
#define TREESTUMP8		22
#define TREESTUMP9		23
#define TREESTUMP10		24
#define TREESTUMP11		25
#define TREESTUMP12		26
#define TREELEAFINTER1	27
#define TREELEAFINTER2	28
#define TREESTUMPINTER1	29
#define TREESTUMPINTER2	30
#define TREESTUMPINTER3	31

//========= stone =========//
#define STONE			32
#define STONEB			33
#define BIGSTONE1		34
#define BIGSTONE2		35
#define BIGSTONE3		36
#define BIGSTONE4		37
#define BIGSTONEB1		38
#define BIGSTONEB2		39
#define BIGSTONEB3		40
#define BIGSTONEB4		41
#define ST5NE1			42
#define ST5NE2			43
#define ST5NE3			44
#define ST5NE4			45

//========= house =========//
#define HOUSE1		46
#define HOUSE2		47
#define HOUSE3		48
#define HOUSE4		49
#define HOUSE5		50
#define HOUSE6		51
#define HOUSE7		52
#define HOUSE8		53
#define HOUSE9		54
#define HOUSE10		55
#define HOUSE11		56
#define HOUSE12		57
#define HOUSE13		58
#define HOUSE14		59
#define HOUSE15		60
#define HOUSE16		61
#define HOUSE17		62
#define HOUSE18		63
#define HOUSE19		64
#define HOUSE20		65
#define HOUSE21		66
#define HOUSE22		67
#define HOUSE23		68
#define HOUSE24		69
#define HOUSE25		70
#define HOUSE26		71
#define HOUSE27		72
#define HOUSE28		73
#define HOUSE29		74
#define HOUSE30		75
#define HOUSE31		76
#define HOUSE32		77
#define HOUSE33		78
#define HOUSE34		79
#define HOUSE35		80
#define HOUSE36		81
#define HOUSE37		82
#define HOUSE38		83

//========= ground =========//
#define FENCE1		84
#define FENCE2		85
#define FENCE3		86
#define FENCE4		87
#define FENCE5		88

#define CLIFF1		89
#define CLIFF2		90
#define CLIFF3		91
#define CLIFF4		92
#define CLIFF5		93
#define CLIFF6		94
#define CLIFF7		95
#define CLIFF8		96
#define CLIFF9		97
#define CLIFF10		98
#define CLIFF11		99
#define CLIFF12		100
#define CLIFF13		101
#define CLIFF14		102
#define CLIFF15		103
#define CLIFF16		104
#define CLIFF17		105
#define CLIFF18		106
#define CLIFF19		107
#define CLIFF20		108
#define CLIFF21		109
#define CLIFF22		110
#define CLIFF23		111
#define CLIFF24		112
#define CLIFF25		113
#define CLIFF26		114
#define CLIFF27		115

#define CLIFFIN1	116
#define CLIFFIN2	117
#define CLIFFIN3	118
#define CLIFFIN4	119
#define CLIFFIN5	120
#define CLIFFIN6	121
#define CLIFFIN7	122
#define CLIFFIN8	123
#define CLIFFIN9	124
#define CLIFFIN10	125