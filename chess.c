#include <stdio.h>
#include <stdlib.h>
#include <getch.h>
#include <stdbool.h>

int x = 7,y = 7;
char board[15][15]={};
bool five(int c,int d);		//判断五子连珠
void init_board();		//初始化棋盘
void show_board(void);	//显示棋盘
void get_key(void);		//判断落子
char role='@';

int main(int argc,const char* argv[])
{
	
	init_board();
	for(;;)
	{
		system("clear");
		show_board();
		get_key();
		if(five(x,y))
		{
			printf("游戏结束\n");
			return 0;
		}
	}
}

void init_board(void)		//初始化
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			board[i][j]='*';
		}
		printf("\n");
	}	
}
void show_board(void)		//显示棋盘
{
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++)
		{
			printf(" %c",board[i][j]);
		}
		printf("\n");
	}
}

void get_key(void)		//落子
{	
	printf("\33[%d;%dH",x+1,(y+1)*2);
	switch(getch())
	{
		case 183: x>0 && x--;break;
		case 184: x<14 && x++;break;
		case 185: y<14 && y++;break;
		case 186: y>0 && y--;break;
		case 10: if('*'==board[x][y])
		{
			board[x][y]=role;
			if('@'==role)
			{
				role='$';
			}
			else role='@';
		}
		else return;break;
	}
}

bool five(int c,int d)
{
    int k, c1, c2, xx, yy;
	int DX[4] = {1,0,1,1};
	int DY[4] = {0,1,1,-1};
	for(k = 0; k < 4; k++) 
	{
		c1 = c2 = 0;
		for(xx = c + DX[k],yy = d + DY[k];(board[xx][yy] == board[c][d])&&(board[xx][yy] != '*'); xx +=DX[k],yy += DY[k]) 
		{
			c1++;
		}
		for(xx = c - DX[k],yy = d - DY[k];(board[xx][yy]== board[c][d])&&(board[xx][yy] != '*'); xx -= DX[k],yy -= DY[k])
		{
			c2++;
		}
	 	if(c1+c2>=4)return true;
	}
	return false;
}
