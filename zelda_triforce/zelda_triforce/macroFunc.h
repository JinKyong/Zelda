#pragma once

//============================================
// ## macroFunc ## - 21.04.23
//============================================

inline void pen(HDC hdc, int thick, COLORREF color) {
	//�� ��ü ����       (�� ��Ÿ��, ����, ����)
	HPEN pen = CreatePen(PS_SOLID, thick, color);
	//hdc�� ������ �� ��ü ����, ���� ��ü ��ȯ
	HPEN oldPen = (HPEN)SelectObject(hdc, pen);

	SelectObject(hdc, oldPen);
	DeleteObject(pen);
}
inline void brush(HDC hdc) {
	//�귯�� ��ü ����
	HBRUSH brush = CreateSolidBrush(RGB(50, 50, 100));
	//hdc�� ������ �귯�� ��ü ����, ���� ��ü ��ȯ
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);
}
inline void pixel(HDC hdc) {
	SetPixel(hdc, 200, 50, RGB(255, 0, 0));
	for (int i = 0; i < 100; i++)
		SetPixel(hdc, 200 + i, 50, RGB(255, 0, 0));
}

//Point
inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };

	return pt;
}

//���߱��Լ�(�׷���DC, ������ǥX, ������ǥY, ����ǥ X, ����ǥY)
inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2) {
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2, int width) {	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

//�簢��
inline void Rectangle(HDC hdc, RECT& rc) {
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}
//��ǥ(x, y)�� LeftTop���� �ϴ� �簢��(width, height)�� ����
inline void RectangleMake(HDC hdc, int x, int y, int width, int height) {
	Rectangle(hdc, x, y, x + width, y + height);
}
//��ǥ(x, y)�� �߽����� �ϴ� �簢��(width, height)�� ����
inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height) {
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

//��
inline void Ellipse(HDC hdc, RECT& rc) {
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}
//��ǥ(x, y)�� LeftTop���� �ϴ� ��(width, height)�� ����
inline void EllipseMake(HDC hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x, y, x + width, y + height);
}
//��ǥ(x, y)�� �߽����� �ϴ� ��(width, height)�� ����
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height) {
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}

//============================================
// ## macroFunc ## - 21.04.26
//============================================

//RECT
inline RECT RectMake(int x, int y, int width, int height) {
	RECT rc = { x, y, x + width, y + height };

	return rc;
}
inline RECT RectMakeCenter(int x, int y, int width, int height) {
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };

	return rc;
}