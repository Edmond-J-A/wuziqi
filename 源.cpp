#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<graphics.h>
using namespace std;
int GAME = 1;
int map[10][10] = { 0 };
int x = 10, y = 10, x2 = 10, y2 = 10;
int jx, jy;                             //�����ж���Ӯ����
int turn = 0;                             //�غ�
int jn1 = 0;                              //jn1=4ʱ����Ӯ��
void bjudge()
{
	if (map[jx][jy + 1] == 1 || map[jx][jy - 1] == 1)                                            //�����ж�
	{
		for (int i = 1; map[jx][jy + i] == 1 && jy + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx][jy - i] == 1 && jy - i >= 0; i++)
		{
			jn1++;
		}
		if (jn1 == 4)
		{
			GAME = 2;
		}
		else
		{
			jn1 = 0;
		}
	}
	if (map[jx + 1][jy] == 1 || map[jx - 1][jy] == 1)                                            //�����ж�
	{
		for (int i = 1; map[jx + i][jy] == 1 && jx + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx - i][jy] == 1 && jx - i >= 0; i++)
		{
			jn1++;
		}
		if (jn1 == 4)
		{
			GAME = 2;
		}
		else
		{
			Sleep(10);
			jn1 = 0;
		}
	}
	if (map[jx + 1][jy + 1] == 1 || map[jx - 1][jy - 1] == 1)
	{
		for (int i = 1; map[jx + i][jy + i] == 1 && jx + i <= 9 && jy + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx - i][jy - i] == 1 && jx - i >= 0 && jy - i >= 0; i++)
		{
			jn1++;
		}
		if (jn1 == 4)
		{
			GAME = 2;
		}
		else
		{
			jn1 = 0;
		}
	}
	if (map[jx - 1][jy + 1] == 1 || map[jx + 1][jy - 1] == 1)
	{
		for (int i = 1; map[jx - i][jy + i] == 1 && jx - i >= 0 && jy + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx + i][jy - i] == 1 && jy - i >= 0 && jx + i <= 9; i++)
		{
			jn1++;

		}
		if (jn1 == 4)
		{
			GAME = 2;
		}
		else
		{
			jn1 = 0;
		}
	}
}
void wjudge()
{
	if (map[jx][jy + 1] == 2 || map[jx][jy - 1] == 2)                                            //�����ж�
	{
		for (int i = 1; map[jx][jy + i] == 2 && jy + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx][jy - i] == 2 && jy - i >= 0; i++)
		{
			jn1++;
		}
		if (jn1 == 4)
		{
			GAME = 0;
		}
		else
		{
			jn1 = 0;
		}
	}
	if (map[jx + 1][jy] == 2 || map[jx - 1][jy] == 2)                                            //�����ж�
	{
		for (int i = 1; map[jx + i][jy] == 2 && jx + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx - i][jy] == 2 && jx - i >= 0; i++)
		{
			jn1++;
		}
		if (jn1 == 4)
		{
			GAME = 0;
		}
		else
		{
			jn1 = 0;
		}
	}
	if (map[jx + 1][jy + 1] == 2 || map[jx - 1][jy - 1] == 2)
	{
		for (int i = 1; map[jx + i][jy + i] == 2 && jx + i <= 9 && jy + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx - i][jy - i] == 2 && jx - i >= 0 && jy - i >= 0; i++)
		{
			jn1++;
		}
		if (jn1 == 4)
		{
			GAME = 0;
		}
		else
		{
			jn1 = 0;
		}
	}
	if (map[jx - 1][jy + 1] == 2 || map[jx + 1][jy - 1] == 2)
	{
		for (int i = 1; map[jx - i][jy + i] == 2 && jx - i >= 0 && jy + i <= 9; i++)
		{
			jn1++;
		}
		for (int i = 1; map[jx + i][jy - i] == 2 && jy - i >= 0 && jx + i <= 9; i++)
		{
			jn1++;
		}
		if (jn1 == 4)
		{
			GAME = 0;
		}
		else
		{
			jn1 = 0;
		}
	}
}
void move()
{
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN)
	{
	for (int i = 0; i < 10; i++)
	{
		if (i * 51 <= m.x && m.x < (1 + i) * 51)
		{
			x = i;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		if (i * 51 <= m.y && m.y < (1 + i) * 51)
		{
			y = i;
			break;
		}
	}
}
	jx = x, jy = y;
	if (turn == 1)                                                                //W��
	{
		if (x >= 0 && x < 10 && y >= 0 && y < 10)
		{
			if (map[x][y] == 0)
			{
				map[x][y] = 2;
				turn = 0;
			}
			else
			{

			}

		}
	}
	else																		  //��д��ĸ
	{
		if (x >= 0 && x < 10 && y >= 0 && y < 10)
		{
			if (map[x][y] == 0)
			{
				map[x][y] = 1;
				turn = 1;
			}
			else
			{

			}

		}
	}
	x = y = 20;
}
void map1()
{
	MOUSEMSG m;
	for (int i = 0; i < 512; i+=51)
	{
		setpolyfillmode(WINDING);
		setfillcolor(WHITE);
		solidrectangle(i, 0, i + 2, 511);
	}
	for (int i = 0; i < 512; i += 51)
	{
		setpolyfillmode(WINDING);
		setfillcolor(WHITE);
		solidrectangle(0,i ,511 ,i + 2 );
	}
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (map[i][k] == 1)
			{
				setpolyfillmode(WINDING);
				setfillcolor(BLUE);
				solidcircle(i*51+27,k*51+27,23);
			}
			else if (map[i][k] == 2)
			{
				setpolyfillmode(WINDING);
				setfillcolor(WHITE);
				solidcircle(i * 51 + 27, k * 51 + 27, 23);
			}
			else
			{
				setpolyfillmode(WINDING);
				setfillcolor(BLACK);
				solidcircle(i * 51 + 27, k * 51 + 27, 23);
			}
		}
	}
}
int main()
{
	initgraph(511, 511);
	while (GAME == 1)
	{
		move();
		map1();
		bjudge();
		wjudge();		
	}
	if (GAME == 0)
	{
		closegraph();
		cout << "white win!!!" << endl;
	}
	else
	{
		closegraph();
		cout << "blue win!!!" << endl;
	}
	getchar();
	
}
