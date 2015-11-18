#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define DELTA 10

typedef struct{
	int x;
	int y;
} TPoint;

typedef struct{
	TPoint leftUp;
	TPoint rightDown;
	int color;
} TRectangle;

void DrawRectangle(const TRectangle *const rect){
	rectangle(rect->leftUp.x, rect->leftUp.y, rect->rightDown.x, rect->rightDown.y);
}

char IncHeight(TRectangle *const rect) {
	if (rect->leftUp.y - (DELTA / 2) > 0 && rect->rightDown.y + (DELTA / 2) < getmaxy()){
		rect->leftUp.y -= DELTA / 2;
		rect->rightDown.y += DELTA / 2;
		return 1;
	} else {
		return 0;
	}
}

char IncWidth(TRectangle *const rect) {
	if (rect->rightDown.x + (DELTA / 2) < getmaxx() && rect->leftUp.x - (DELTA / 2) > 0) {
		rect->rightDown.x += DELTA / 2;
		rect->leftUp.x -= DELTA / 2;
		return 1;
	} else {
		return 0;
	}
}

char DecHeight(TRectangle *const rect) {
	if (rect->leftUp.y + (DELTA / 2) < rect->rightDown.y - (DELTA / 2)){
		rect->leftUp.y += DELTA / 2;
		rect->rightDown.y -= DELTA / 2;
		return 1;
	} else {
		return 0;
	}
}

char DecWidth(TRectangle *const rect) {
	if (rect->leftUp.x + (DELTA / 2) < rect->rightDown.x - (DELTA / 2)){
		rect->rightDown.x -= DELTA / 2;
		rect->leftUp.x += DELTA / 2;
		return 1;
	} else {
		return 0;
	}
}

char MoveLeft(TRectangle *const rect) {
	if (rect->leftUp.x - DELTA > 0) {
		rect->leftUp.x -= DELTA;
		rect->rightDown.x -= DELTA;
		return 1;
	} else {
		return 0;
	}
}

char MoveRight(TRectangle *const rect) {
	if (rect->rightDown.x + DELTA < getmaxx()) {
		rect->rightDown.x += DELTA;
		rect->leftUp.x += DELTA;
		return 1;
	} else {
		return 0;
	}
}

char MoveUp(TRectangle *const rect) {
	if (rect->leftUp.y - DELTA > 0) {
		rect->leftUp.y -= DELTA;
		rect->rightDown.y -= DELTA;
		return 1;
	} else {
		return 0;
	}
}

char MoveDown(TRectangle *const rect) {
	if (rect->rightDown.y + DELTA < getmaxy()) {
		rect->leftUp.y += DELTA;
		rect->rightDown.y += DELTA;
		return 1;
	} else {
		return 0;
	}
}

void Refresh(TRectangle *const rect) {
	cleardevice();
	DrawRectangle(rect);
}

int main()
{
	
	char c;
	TRectangle myRectangle;
	
	int gd = DETECT,gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	
	myRectangle.leftUp.x = 1;
	myRectangle.leftUp.y = 1;
	myRectangle.rightDown.x = 51;
	myRectangle.rightDown.y = 101;

	Refresh(&myRectangle);

	do {
		c = getch();
		switch(c) {
			case '+':
				if (IncHeight(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case '-':
				if (DecHeight(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case 'w':
				if (MoveUp(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case 's':
				if (MoveDown(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case 'd':
				if (MoveRight(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case 'a':
				if (MoveLeft(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case '.':
				if (IncWidth(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case ',':
				if (DecWidth(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case '1':
				setcolor(BLUE);
				Refresh(&myRectangle);
				break;
			case '2':
				setcolor(WHITE);
				Refresh(&myRectangle);
				break;
			case '3':
				setcolor(RED);
				Refresh(&myRectangle);
				break;
			case '4':
				setcolor(YELLOW);
				Refresh(&myRectangle);
		}	
	}while (c != 'c');
	closegraph();
	return 0;
}
