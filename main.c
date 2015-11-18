#include <graphics.h> 
#include <X11/Xlib.h>

#define MAX_WIDTH 320
#define MAX_HEIGHT 200
#define DELTA 10

typedef struct{
	int x;
	int y;
} TPoint;

typedef struct{
	TPoint leftUp;
	TPoint rightDown;
} TRectangle;

void DrawRectangle(const TRectangle *const rect){
	rectangle(rect->leftUp.x, rect->leftUp.y, rect->rightDown.x, rect->rightDown.y);
}

char IncHeight(TRectangle *const rect) {
	if (rect->leftUp.y - DELTA  > 0){
		rect->leftUp.y -= DELTA;
		return 1;
	} else {
		return 0;
	}
}

char IncWidth(TRectangle *const rect) {
	if (rect->rightDown.x + DELTA < MAX_WIDTH) {
		rect->rightDown.x += DELTA;
		return 1;
	} else {
		return 0;
	}
}

char DecHeight(TRectangle *const rect) {
	if (rect->leftUp.y + DELTA < MAX_HEIGHT) {
		rect->leftUp.y += DELTA;
		return 1;
	} else {
		return 0;
	}
}

char DecWidth(TRectangle *const rect) {
	if (rect->rightDown.x - DELTA > 0) {
		rect->rightDown.x -= DELTA;
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
	if (rect->rightDown.x + DELTA < MAX_WIDTH) {
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
	if (rect->leftUp.y + DELTA < MAX_HEIGHT) {
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
	
	XInitThreads();
	int gd = DETECT,gm;	
	initgraph(&gd,&gm,"C:\\TC\\BGI");

	
	char c;
	TRectangle myRectangle;
	myRectangle.leftUp.x = 1;
	myRectangle.leftUp.y = 1;
	myRectangle.rightDown.x = 51;
	myRectangle.rightDown.y = 101;
	
	Refresh(&myRectangle);
  
	do {		
		c = getch();
		switch(c) {
			case 'u':
				if (IncHeight(&myRectangle)) {
					//printf("ddd");
					Refresh(&myRectangle);					
				}
				break;
			case 'j':
				if (DecHeight(&myRectangle)) {
					//printf("ddd");
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
			case 'k':
				if (IncWidth(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
			case 'h':
				if (DecWidth(&myRectangle)) {
					Refresh(&myRectangle);
				}
				break;
		}	
	}while (c != 32);
	//delay(5000);
	closegraph();
	return 0;
}
