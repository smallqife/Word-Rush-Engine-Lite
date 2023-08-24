#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
int chosen=0;
char key;
short mouseX=0,mouseY=0;
string mes[3] = {//存储说明文本的数组
	"This is Map 1.   Wow!                     ",
	"This is Map 2.   Well.                    ",
	"This is Map 3.   They are almost the same.",
};
char maps[3][11][24]={//存储地图的数组
{
	{1,0,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,0,0,0} , //0代表空气，1代表物体
	{1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,0,0,0,0},
	{1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,0,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
	{0,1,0,1,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0},
},
{
	{1,0,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0},
	{1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},
	{1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
	{0,1,0,1,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0},
},
{
	{1,0,0,0,1,0,0,1,1,1,0,0,1,1,1,1,0,0,1,1,1,0,0,0},
	{1,1,0,1,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},
	{1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,0,0,1,1,1,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0},
	{1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,1,1,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1,0,0,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,1,1,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0},
	{1,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0},
	{0,1,0,1,0,0,1,0,0,0,1,0,1,1,1,1,0,1,1,1,1,0,0,0},
},
};
void ShowCursor (bool visible) {//显隐光标
  CONSOLE_CURSOR_INFO cursor_info = {20, visible}                         ;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info)     ;
}
void gotoxy (int x, int y) {//设置光标位置
  COORD coord                                                             ;
  coord.X = x                                                             ;
  coord.Y = y                                                             ;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)        ;
}
void drawmap() {//画出地图
	gotoxy(0,0)                                                             ;
	cout << mes[chosen] << endl << endl                                     ;
	for( int i = 0 ; i < 13 ; i++ ){
		if(i==0||i==12){
			cout<<"     +-------------------------+"<<endl                      ;
    }else{
			cout<<"     |"                                                      ;
			for ( int j = 0 ; j < 25 ; j++ ) {
				if ( i-1 == mouseY && j == mouseX ) {
					cout << "O"                                                     ;
				} else if (maps[chosen][i-1][j] == 0) {
					cout << " "                                                     ;
				} else if (maps[chosen][i-1][j] == 1) {
					cout << "M"                                                     ;
				}
			}
			cout << "|" << endl                                                 ;
		}
	}
	cout << endl                                                            ;
	cout << "Click W/A/S/D to move the cursor,click ~ to back."             ;
}
void intomap() {//进入地图操作
	system("cls")                                                           ;
	while(1){
	drawmap()                                                               ;
	key=_getch()                                                            ;
		if(key=='W'||key=='w'){
			if(mouseY>0) mouseY--                                               ;
		}if(key=='S'||key=='s'){
			if(mouseY<10) mouseY++                                              ;
		}if(key=='A'||key=='a'){
			if(mouseX>0) mouseX--                                               ;
		}if(key=='D'||key=='d'){
			if(mouseX<24) mouseX++                                              ;
		}if(key=='`'||key=='~'){
			break                                                               ;
		}
	}
}

int main() {
	ShowCursor(false)                                                       ;
  while(1){
		gotoxy(0,0)                                                           ;
		cout<<"+---------------------+"<<endl                                 ;
		cout<<"|Word Rush Engine Lite|"<<endl                                 ;
		cout<<"+---------------------+"<<endl                                 ;
		cout<<" Made by QiFe  Ver:1.0 "<<endl<<endl                           ;
    cout<<"   [Load Map1]"<<(chosen==0?"<=":"  ")<<endl                   ;
    cout<<"   [Load Map2]"<<(chosen==1?"<=":"  ")<<endl                   ;
		cout<<"   [Load Map3]"<<(chosen==2?"<=":"  ")<<endl                   ;
    cout<<"   [Exit Game]"<<(chosen==3?"<=":"  ")<<endl<<endl             ;
    cout<<"Click W/S to move the cursor,click enter to select."<<endl     ;
    key=_getch()                                                          ;
    if(key=='W'||key=='w'){
    	if(chosen>0) chosen--                                               ;
    	else chosen=3                                                       ;
		}else if(key=='S'||key=='s'){
			if(chosen<3) chosen++                                               ;
    	else chosen=0                                                       ;
		}else if(key=='\r'){
			if(chosen==3) exit(0)                                               ;
			intomap()                                                           ;
			system("cls")                                                       ;
		}
  }
  return 0                                                                ;
}

