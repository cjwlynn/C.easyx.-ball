#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
struct ball {
	int x1;
	int y1;
	int dx;
	int dy;
}b1;
struct wall {
	int m1;
	int n1;
	int m2;
	int n2;
	int dm;
}w1;
void drawball() {
	cleardevice();
	setcolor(RED);
	setfillcolor(RED);
	fillcircle(b1.x1, b1.y1, 15);
}
void drawwall() {
	
	setcolor(YELLOW);
	setfillcolor(YELLOW);
	fillrectangle(w1.m1, w1.n1, w1.m2, w1.n2);
}
void movementball() {
	if (b1.x1 + 15 >= 800 || b1.x1 - 15 <= 0)
		b1.dx = -b1.dx;
	if ( b1.y1 - 15 <= 0 ||(b1.x1 < w1.m2 && b1.x1 > w1.m1 && b1.y1>785 ))
		b1.dy = -b1.dy;
	if ((b1.x1 >= w1.m2 || b1.x1 <= w1.m1) && b1.y1 > 785) {
		printf("\n\n\n\n\n\n\t\t\t\t\t\t\t游戏结束\n");
		exit(0);
	}
	b1.x1 += b1.dx;
	b1.y1 += b1.dy;
}
void movementwall() {
	ExMessage msg;
	while (peekmessage(&msg)) {
		switch (msg.message) {
		case WM_LBUTTONDOWN:
			w1.m1 -= w1.dm;
			w1.m2 -= w1.dm;
			break;
		case WM_RBUTTONDOWN:
			w1.m1 += w1.dm;
			w1.m2 += w1.dm;
			break;
		}
	}
}

int main()
{
	initgraph(800, 800);
	setbkcolor(CYAN);
	cleardevice();
	srand(time(NULL));
	b1 = { rand()%800,rand()%800,5,4};
	w1 = { 200,780,300,800 ,20};
	while (1) {
		drawball();
		movementball();
		drawwall();
		movementwall();
		Sleep(40);
	}
	closegraph();




	return 0;
}