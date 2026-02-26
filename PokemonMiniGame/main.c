#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h>

///////////////////////////////  상수파트
#pragma region 상수
#define PokemonDot_Garo 19
#define PokemonDot_Sero 22
#define BattleField_Garo 50
#define BattleField_Sero 50
#define BackGr_Garo 50
#define BackGr_Sero 50
#define EncountEnemy 1
#define Explain 2
#define EnemyTurn 3
#define Enemy1Turn 4
#define Enemy2Turn 5
#define PickEnemy 6
#define UsingSkill 7
#define Up 72
#define Down 80
#define Left 75
#define Right 77
#define TextZone_Garo 10
#define TextZone_Sero 50
#define Normal 0
#define Fire 1
#define Water 2
#define Leaf 3
/////////////////////////////////////////// 색 상수파트
#define Black 0
#define Blue 1
#define Green 2
#define Cyan 3
#define Red 4
#define Magenta 5
#define Yellow 6
#define LightGrey 7
#define DarkGrey 8
#define LightBlue 9
#define LightGreen 10
#define LightCyan 11
#define LightRed 12
#define LightMagenta 13
#define LightYellow 14
#define White 15
#pragma endregion

//빈 배경 초기화
int BattleField[BattleField_Garo][BattleField_Sero] = {
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98},
	{98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98}
};

//텍스트존 초기화
int TextZone[TextZone_Garo][TextZone_Sero] = {
	{77,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,80},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{79,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,79},
	{81,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,82}
};

////////////////////구조체///////////////////////////
////////////////적 포켓몬 구조체 선언
struct Pokemon {
	int PokeNum;  //포켓몬 고유 번호
	char* name;   //포켓몬의 이름
	int monhp;    //포켓몬의 체력
	char* type;   //포켓몬의 타입
	int typeNum;  //포켓몬타입 고유 번호
	int DotPokemon[PokemonDot_Garo][PokemonDot_Sero]; //정면 도트 배열
};

/////////// 적 포켓몬 구조체 초기화
struct Pokemon pokemon[3] = {
			{1,"파이리",100,"불",Fire,{{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,Black,99,99,99,99},
		{99,99,99,99,99,Black,Black,Black,99,99,99,99,99,99,99,99,Black,Red,Black,99,99,99},
		{99,99,99,Black,Black,Yellow,Yellow,Yellow,Black,99,99,99,99,99,99,99,Black,Red,Red,Black,99,99},
		{99,99,Black,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Black,99,99,99,99,99,99,Black,Red,Red,Black,99,99},
		{99,99,Black,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Black,99,99,99,99,99,Black,Red,Red,Yellow,Red,Black,99},
		{99,Black,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Black,99,99,99,99,Black,Red,Yellow,LightYellow,Red,Black,99},
		{99,Black,Yellow,Yellow,Yellow,Yellow,White,Black,Yellow,Yellow,Black,99,99,99,99,Black,Red,LightYellow,LightYellow,Red,Black,99},
		{Black,Yellow,Yellow,Yellow,Yellow,Yellow,Blue,Black,Yellow,Yellow,Black,99,99,99,99,99,Black,LightYellow,Yellow,Black,99,99},
		{Black,Yellow,Yellow,Yellow,Yellow,Yellow,Black,Black,Yellow,Yellow,Black,99,99,99,99,99,Black,Red,Black,99,99,99},
		{99,Black,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Black,99,99,99,99,Black,Yellow,Black,99,99,99},
		{99,99,Black,Black,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Yellow,Black,99,99,99,Black,Yellow,Yellow,Black,99,99,99},
		{99,99,99,99,Black,Black,LightYellow,Yellow,Yellow,DarkGrey,Yellow,Yellow,Black,99,Black,Yellow,Yellow,Black,99,99,99,99},
		{99,99,99,99,99,Black,LightYellow,LightYellow,DarkGrey,Red,Yellow,Yellow,Yellow,Black,Yellow,Yellow,Yellow,Black,99,99,99,99},
		{99,99,99,99,99,Black,LightYellow,LightYellow,DarkGrey,Yellow,LightYellow,DarkGrey,Yellow,Yellow,DarkGrey,Yellow,Black,99,99,99,99,99},
		{99,99,99,99,Black,Red,Red,LightYellow,LightYellow,DarkGrey,DarkGrey,Yellow,Yellow,Yellow,DarkGrey,Black,99,99,99,99,99,99},
		{99,99,99,99,Black,DarkGrey,Red,DarkGrey,LightYellow,LightYellow,Yellow,Yellow,Yellow,Red,Black,99,99,99,99,99,99,99},
		{99,99,99,99,99,Black,Black,Black,Black,DarkGrey,Red,Yellow,Red,Black,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,Black,White,Red,White,Black,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,Black,Black,Black,99,99,99,99,99,99,99,99,99}
		}},//여기까지 파이리
			{2,"꼬부기",100,"물",Water,{{99,99,99,Black,Black,Black,Black,99,99,99,99,99,99,99,99,99,Black,Black,Black,99,99,99},
		{99,99,Black,Cyan,LightBlue,LightBlue,LightBlue,Black,Black,99,99,99,99,99,99,Black,LightBlue,LightBlue,LightBlue,Black,99,99},
		{99,Black,LightBlue,LightBlue,LightBlue,LightBlue,LightBlue,LightBlue,Cyan,Black,Black,99,99,99,Black,LightBlue,LightBlue,LightBlue,Cyan,Cyan,Black,99},
		{99,Black,LightBlue,LightBlue,LightBlue,LightBlue,LightBlue,LightBlue,LightBlue,DarkGrey,Yellow,Black,Black,99,Black,LightBlue,LightBlue,Cyan,DarkGrey,Cyan,Black,99},
		{Black,LightBlue,LightBlue,LightBlue,LightBlue,Cyan,LightBlue,LightBlue,LightBlue,Cyan,DarkGrey,LightYellow,Yellow,Black,Cyan,LightBlue,Cyan,DarkGrey,Cyan,Cyan,Black,99},
		{Black,LightBlue,LightBlue,LightBlue,Cyan,White,Black,LightBlue,LightBlue,Cyan,DarkGrey,Yellow,LightYellow,Yellow,DarkGrey,Cyan,Cyan,DarkGrey,Cyan,Black,99,99},
		{Black,LightBlue,LightBlue,LightBlue,Cyan,Black,Black,LightBlue,Cyan,Cyan,DarkGrey,White,Yellow,LightYellow,DarkGrey,Cyan,Cyan,DarkGrey,Black,99,99,99},
		{99,Black,LightBlue,LightBlue,LightBlue,Black,LightGrey,Cyan,Cyan,DarkGrey,White,White,Yellow,LightYellow,Yellow,DarkGrey,Cyan,Black,99,99,99,99},
		{99,99,Black,DarkGrey,Cyan,Cyan,Cyan,Cyan,DarkGrey,Cyan,DarkGrey,White,White,Yellow,LightYellow,DarkGrey,Cyan,Black,99,99,99,99},
		{99,99,Black,Cyan,DarkGrey,DarkGrey,DarkGrey,Yellow,LightYellow,DarkGrey,LightBlue,DarkGrey,White,Yellow,Yellow,DarkGrey,Black,99,99,99,99,99},
		{99,99,99,Black,Black,LightYellow,LightYellow,LightYellow,DarkGrey,LightBlue,LightBlue,LightBlue,DarkGrey,Yellow,LightYellow,Black,99,99,99,99,99,99},
		{99,99,99,99,99,Black,Yellow,Yellow,DarkGrey,LightBlue,LightBlue,Cyan,DarkGrey,Yellow,LightYellow,Black,99,99,99,99,99,99},
		{99,99,99,99,Black,Cyan,DarkGrey,LightYellow,LightYellow,DarkGrey,Cyan,DarkGrey,DarkGrey,White,Black,99,99,99,99,99,99,99},
		{99,99,99,99,Black,Cyan,Cyan,Black,Yellow,Yellow,DarkGrey,DarkGrey,Cyan,DarkGrey,Black,99,99,99,99,99,99,99},
		{99,99,99,99,99,Black,Black,99,Black,DarkGrey,LightBlue,Cyan,Cyan,Black,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,Black,Cyan,Cyan,Cyan,Black,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,Black,Black,Black,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99}
		}}, //여기까지 꼬부기
			{3,"이상해씨",100,"풀",Leaf,{{99,99,99,99,99,99,99,99,99,99,99,99,0,99,0,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,0,10,0,10,0,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,0,0,2,10,2,0,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,0,0,2,9,9,2,9,2,0,0,99,99,99,99},
		{99,99,99,99,99,99,99,0,2,2,9,2,9,2,9,2,2,9,0,99,99,99},
		{99,99,99,0,99,99,0,9,2,9,2,2,9,2,2,9,2,2,9,0,99,99},
		{99,99,0,10,0,0,8,9,9,9,2,9,2,2,2,2,9,2,9,0,99,99},
		{99,99,0,10,10,10,2,8,8,9,9,9,2,2,2,2,9,9,9,0,99,99},
		{99,99,0,10,10,2,9,9,2,8,9,9,9,9,9,9,9,9,9,0,99,99},
		{99,0,10,10,10,9,9,9,10,2,8,8,8,9,9,9,9,9,0,99,99,99},
		{99,0,2,10,10,10,10,10,10,10,10,10,8,9,9,9,8,0,99,99,99,99},
		{0,4,9,10,10,10,2,10,10,10,10,8,2,8,8,8,2,0,99,99,99,99},
		{0,10,10,10,10,9,10,8,0,8,10,2,2,2,2,2,9,9,0,99,99,99},
		{99,0,10,10,10,10,0,0,15,15,2,2,2,8,2,2,9,9,0,99,99,99},
		{99,0,2,10,10,10,0,4,15,2,2,2,9,9,8,2,2,2,0,99,99,99},
		{99,99,0,0,2,2,2,2,2,2,8,2,9,9,8,2,15,0,99,99,99,99},
		{99,99,99,99,0,0,0,0,0,0,2,2,2,2,8,0,0,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,0,15,2,15,8,0,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,0,0,0,0,99,99,99,99,99,99,99,99}
		}}  //여기까지 이상해씨
};

///////////////아군 포켓몬 구조체 선언
struct MyPokemon {
	int PokeNum;
	int Skill1;
	int Skill2;
	int Skill3;
	char* name;
	int monhp;
	char* type;
	int typeNum;
	int DotPokemon[PokemonDot_Garo][PokemonDot_Sero];
};

////////////아군 포켓몬 구조체 초기화
struct MyPokemon MyPokemon[3] = {
	{1,1,0,4,"파이리", 100,"불",Fire,
	{
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White}
    }},
	{2,2,0,4,"꼬부기",100,"물",Water,
	{
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White}
    }},
	{3,3,0,4,"이상해씨",100,"풀",Leaf,
	{
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
	{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White,White}
    }}
};

//////////////////풀숲 배경 선언
struct BackGr {
	int Grass[BackGr_Garo][BackGr_Sero];
};

////////////////////////풀숲 배경 초기화
struct BackGr BackGr = { {
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green},
	{Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,Green}
}};

/////////// 포켓몬 기술 선언
struct Skill {
	int Num; //스킬 고유 번호
	char* name; //스킬 이름
	int typeNum; //스킬 타입 번호
	int Dmg; //스킬 데미지
};
/////////// 포켓몬 기술 정의
struct Skill skill[5] = {
	{0, "몸통박치기", Normal, 20},
	{1, "불꽃세례", Fire, 30},
	{2, "물대포", Water, 30},
	{3, "덩굴채찍", Leaf, 30},
	{4, "HP회복", Normal, 50}
};



////////////////
////함수////////
///////////////

#pragma region 함수선언
//도트 색 변경 함수 선언
static void SetColor(int color, int back);

//화면 출력 함수 선언
void DotPrintScreen();

//좌표함수 선언
void gotoxy(int x, int y);

//더블 배틀 함수 선언
int DoubleBattle(struct Pokemon* pokemon, struct MyPokemon MyPokemon);

//단일 배틀 함수 선언
int Battle(struct Pokemon pokemon, struct MyPokemon MyPokemon);

//콘솔 화면 크기
int SetConsoleSizeStable(short cols, short lines, short scrollLine);

//빈 배경에 포켓몬 입히기
void DotSetPokemon(struct Pokemon pokemon, int StartX, int StartY);

//빈 배경에 배경 입히기
void DotSetBG(struct BackGr BackGr);

//텍스트존 출력 함수
void PrintTextZone();

//스킬창 텍스트 출력 함수
void PrintSkillText(struct MyPokemon Eevee);

//설명창 텍스트 출력 함수
void PrintExplainText(char *Text, struct Pokemon pokemon, struct MyPokemon MyPokemon, int Situation, int skillNum);

//적 몬스터 선택창 출력 함수
void PrintPickEnemyText(char* Enemy1, char* Enemy2, char* Enemy3, char* Enemy4);

//설명창 텍스트 출력 함수
void PrintExplainTextDB(char* Text,  int Situation);

//화살표 및 스킬 선택 함수
int ChoiceSkill(struct MyPokemon MyPokemon);

//화살표 및 상대 몬스터 선택 함수
int ChoiceOption(int NMax, int GMax);

//화살표 및 더블배틀 스킬 타켓 선택 함수
int ChoiceTarget();

//커서 숨기기 함수
void CursorView(char show);

//아군 포켓몬 선택 함수
int ChoicePokeText();

//아군 포켓몬 선택지 출력 함수
void PrintPickPokeText(int num);

//아군 포켓몬 도트 입히기 함수
void DotSetMyPokemon(struct MyPokemon MyPokemon, int StartX, int StartY);

//스킬 사용 시 상호작용 함수
int ResultSkill(struct Pokemon pokemon, struct MyPokemon MyPokemon, int skillNum);

//스킬 사용 시 상호작용 더블배틀 함수
int ResultSkillDB(int target, struct MyPokemon MyPokemon, int skillNum);

#pragma endregion


////////////////메인 함수////////////////////
int main(void)
{
	CursorView(0);
	SetConsoleSizeStable(100, 50, 50); ////// 콘솔 창 설정
	while (1)
	{
		//////////////// 배경 초기화
		

		//////////////////////////////////플레이어 초기화
		int xp = 0;     //플레이어 경험치
		int pokeNum = 0;//상대 선택용 변수
		int win = 0, quit = 0; //승패 기록용, 다시하기 여부 변수

		//게임시작!!!!!!!!!!!!!!!
		while (1)
		{
			int MyPoke = 0;
			pokemon[0].monhp = 100;
			MyPokemon[0].monhp = 100;
			pokemon[1].monhp = 100;
			MyPokemon[1].monhp = 100;
			pokemon[2].monhp = 100;
			MyPokemon[2].monhp = 100;

			DotSetBG(BackGr);
			PrintTextZone();
			DotPrintScreen();
			PrintExplainText("어떤 포켓몬과 함께 전투 하시겠습니까?", pokemon[0], MyPokemon[0], Explain, 1);
			system("pause");

			DotSetBG(BackGr);
			PrintTextZone();
			DotSetPokemon(pokemon[0], 2, 15);
			DotPrintScreen();
			PrintPickPokeText(1);
			Sleep(1000);

			DotSetBG(BackGr);
			PrintTextZone();
			DotSetPokemon(pokemon[1], 2, 15);
			DotPrintScreen();
			PrintPickPokeText(2);
			Sleep(1000);

			DotSetBG(BackGr);
			PrintTextZone();
			DotSetPokemon(pokemon[2], 2, 15);
			DotPrintScreen();
			PrintPickPokeText(3);
			Sleep(1000);

			system("pause");
			MyPoke = ChoicePokeText();

			DotSetBG(BackGr);
			PrintTextZone();
			DotPrintScreen();
			PrintExplainText("상대 포켓몬 중 누구와 싸우겠습니까?", pokemon[0], MyPokemon[0], Explain, 1);
			system("pause");

			DotSetBG(BackGr);
			PrintTextZone();
			DotSetPokemon(pokemon[0], 2, 15);
			DotPrintScreen();
			PrintPickEnemyText("1: 파이리   타입 : 불", " ", " ", " ");
			Sleep(1000);

			DotSetBG(BackGr);
			PrintTextZone();
			DotSetPokemon(pokemon[1], 2, 15);
			DotPrintScreen();
			PrintPickEnemyText("1: 파이리   타입 : 불", "2: 꼬부기   타입: 물", " ", " ");
			Sleep(1000);

			DotSetBG(BackGr);
			PrintTextZone();
			DotSetPokemon(pokemon[2], 2, 15);
			DotPrintScreen();
			PrintPickEnemyText("1: 파이리   타입 : 불", "2: 꼬부기   타입: 물", "3: 이상해씨   타입: 풀", " ");
			Sleep(1000);

			DotSetBG(BackGr);
			PrintTextZone();
			DotSetPokemon(pokemon[0], 2, 2);
			DotSetPokemon(pokemon[1], 2, 28);
			DotPrintScreen();
			PrintPickEnemyText("1: 파이리   타입 : 불", "2: 꼬부기   타입: 물", "3: 이상해씨   타입: 풀", "4: 파이리  타입: 불   꼬부기  타입: 물 ");
			system("pause");

			//////////////야생 포켓몬 선택
			pokeNum = ChoiceOption(4, 2);

			if (pokeNum == 3)
				win = DoubleBattle(pokemon, MyPokemon[MyPoke-1]);  //////////////////////////////////////////////더블 배틀 함수 호출
			else if (pokeNum != 0 && pokeNum != 1 && pokeNum != 2 && pokeNum != 3)
			{
				system("cls");
				continue;   /////선택지 외의 숫자 선택 시 다시 선택
			}
			else
				win = Battle(pokemon[pokeNum], MyPokemon[MyPoke]); //////////////////배틀함수 호출

			//int battle(struct Pokemon pokemon, int* hp);
			//win = Battle(pokemon[pokeNum - 49], &hp); //////////////////배틀함수 호출

			///////////////////////////////승패에 따른 보상
			if (win == 0) {
				xp += 25;
				DotPrintScreen();
				PrintExplainText("경험치를 획득했습니다. ",pokemon[0], MyPokemon[0], Explain, 1);
				printf("%d/100 \n", xp);
				system("pause");
				system("cls");
			}
			else if (win == 1)
			{
				PrintExplainText("패배했다. ", pokemon[0], MyPokemon[0], Explain, 1);
				system("pause");
				system("cls");
				continue;
			}
			/////////////////////////경험치 다 채우면 나가기
			if (xp >= 100)
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainText("목표를 달성했습니다. ", pokemon[0], MyPokemon[0], Explain, 1);
				system("pause");
				system("cls");
				break;
			}
		}
		printf("다시 플레이 하시겠습니까?\n");  /////////////////다시하기 기능
		printf("YES: C    NO:Other Keys \n\n");
		quit = _getch();
		system("cls");

		if (quit != 99)
		{
			printf("이용해주셔서 감사합니다.\n");
			break;
		}
	}

	return 0;
}

////////////////////
/////함수함수함수//////////////////////////////////////////////////////////////////////////
////////////////////

/////////////////색 변경 함수
static void SetColor(int color, int back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (back << 4));
}

//////배경 출력 함수
void DotPrintScreen()
{
	system("cls");

	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (BattleField[i][j] == Black)
			{
				SetColor(0, 0);
			}
			else if (BattleField[i][j] == Blue)
			{
				SetColor(1, 1);
			}
			else if (BattleField[i][j] == Green)
			{
				SetColor(2, 2);
			}
			else if (BattleField[i][j] == Cyan)
			{
				SetColor(3, 3);
			}
			else if (BattleField[i][j] == Red)
			{
				SetColor(4, 4);
			}
			else if (BattleField[i][j] == Magenta)
			{
				SetColor(5, 5);
			}
			else if (BattleField[i][j] == Yellow)
			{
				SetColor(6, 6);
			}
			else if (BattleField[i][j] == LightGrey)
			{
				SetColor(7, 7);
			}
			else if (BattleField[i][j] == DarkGrey)
			{
				SetColor(8, 8);
			}
			else if (BattleField[i][j] == LightBlue)
			{
				SetColor(9, 9);
			}
			else if (BattleField[i][j] == LightGreen)
			{
				SetColor(10, 10);
			}
			else if (BattleField[i][j] == LightCyan)
			{
				SetColor(11, 11);
			}
			else if (BattleField[i][j] == LightRed)
			{
				SetColor(12, 12);
			}
			else if (BattleField[i][j] == LightMagenta)
			{
				SetColor(13, 13);
			}
			else if (BattleField[i][j] == LightYellow)
			{
				SetColor(14, 14);
			}
			else if (BattleField[i][j] == White)
			{
				SetColor(15, 15);
			}
			else if (BattleField[i][j] == 78)
			{
				SetColor(0, 7);
				printf("──");
			}
			else if (BattleField[i][j] == 79)
			{
				SetColor(0, 7);
				printf("│ ");
			}
			else if (BattleField[i][j] == 77)
			{
				SetColor(0, 7);
				printf("┌─");
			}
			else if (BattleField[i][j] == 80)
			{
				SetColor(0, 7);
				printf("┐ ");
			}
			else if (BattleField[i][j] == 82)
			{
				SetColor(0, 7);
				printf("┘ ");
			}
			else if (BattleField[i][j] == 81)
			{
				SetColor(0, 7);
				printf("└─");
			}
			if (BattleField[i][j] != 78 && BattleField[i][j] != 79 && BattleField[i][j] != 80 && BattleField[i][j] != 81 && BattleField[i][j] != 82 && BattleField[i][j] != 77)
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	SetColor(15, 0);
}


///////////////// 배틀함수
int Battle(struct Pokemon pokemon, struct MyPokemon MyPokemon)
{
	DotSetBG(BackGr);
	DotSetMyPokemon(MyPokemon, 20, 2);
	PrintTextZone();
	DotSetPokemon(pokemon, 0, 27);
	DotPrintScreen();
	PrintExplainText("", pokemon, MyPokemon, EncountEnemy, 1);
	Sleep(1500);

	while (1)
	{
		int result = 0;
		int Pskill = 0;
		DotSetBG(BackGr);
		DotSetMyPokemon(MyPokemon, 20, 2);
		PrintTextZone();
		DotSetPokemon(pokemon, 0, 27);
		DotPrintScreen();
		PrintSkillText(MyPokemon);
		printf("상대 체력: %d        내 체력: %d \n", pokemon.monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
		system("pause");
		Pskill = ChoiceSkill(MyPokemon);
		DotSetBG(BackGr);
		DotSetMyPokemon(MyPokemon, 20, 2);
		PrintTextZone();
		DotSetPokemon(pokemon, 0, 27);
		DotPrintScreen();

		PrintExplainText(" ", pokemon, MyPokemon, UsingSkill, Pskill);
		result = ResultSkill(pokemon, MyPokemon, Pskill);
		Sleep(1000);

		if (result == 0)
		{
			pokemon.monhp -= skill[MyPokemon.Skill1].Dmg / 2;
			PrintExplainText("효과가 별로였다. ", pokemon, MyPokemon, Explain, 1);
		}
		else if (result == 1)
		{
			pokemon.monhp -= skill[MyPokemon.Skill1].Dmg;
			PrintExplainText("효과는 보통이었다. ", pokemon, MyPokemon, Explain, 1);
		}
		else if (result == 2)
		{
			pokemon.monhp -= skill[MyPokemon.Skill1].Dmg * 2;
			PrintExplainText("효과가 굉장했다! ", pokemon, MyPokemon, Explain, 1);
		}
		else if (result == 3)
		{
			pokemon.monhp -= skill[MyPokemon.Skill2].Dmg;
			PrintExplainText("효과는 보통이었다. ", pokemon, MyPokemon, Explain, 1);
		}
		else if (result == 4)
		{
			MyPokemon.monhp += skill[MyPokemon.Skill3].Dmg;
			if (MyPokemon.monhp > 100)MyPokemon.monhp = 100;
			PrintExplainText("체력을 회복했다. ", pokemon, MyPokemon, Explain, 1);
		}
		else continue;
		if (pokemon.monhp < 0)pokemon.monhp = 0;
		printf("상대 체력: %d        내 체력: %d \n", pokemon.monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
		system("pause");

		if (pokemon.monhp <= 0)
		{
			DotSetBG(BackGr);
			PrintTextZone();
			DotPrintScreen();
			PrintExplainText("전투에서 승리했다! ", pokemon, MyPokemon, Explain, 1);
			system("pause");
			return 0;
		}

		//상대 턴
		DotSetBG(BackGr);
		DotSetMyPokemon(MyPokemon, 20, 2);
		PrintTextZone();
		DotSetPokemon(pokemon, 0, 27);
		DotPrintScreen();
		PrintExplainText(" ", pokemon, MyPokemon, EnemyTurn, 1);
		Sleep(1000);
		MyPokemon.monhp -= 30;
		if (MyPokemon.monhp < 0) MyPokemon.monhp = 0;
		DotPrintScreen();
		PrintExplainText("효과는 보통이었다. ", pokemon, MyPokemon, Explain, 1);
		printf("상대 체력: %d        내 체력: %d \n", pokemon.monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
		system("pause");

		if (MyPokemon.monhp <= 0)
		{
			DotSetBG(BackGr);
			PrintTextZone();
			DotPrintScreen();
			PrintExplainText("눈 앞이 새하얘졌다.. ", pokemon, MyPokemon, Explain, 1);
			system("pause");
			return 1;
		}
	}
}

////////////////////더블 배틀 함수
int DoubleBattle(struct Pokemon* pokemon, struct MyPokemon MyPokemon)
{
	DotSetBG(BackGr);
	DotSetPokemon(pokemon[0], 0, 5);
	DotSetPokemon(pokemon[1], 0, 27);
	DotSetMyPokemon(MyPokemon, 20, 2);
	PrintTextZone();
	DotPrintScreen();
	PrintExplainTextDB("", EncountEnemy);
	printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
	Sleep(1000);

	while (1)
	{
		int result = 0;
		int Fskill = 0; //1번 스킬
		int Sskill = 0; //2번 스킬
		int choice1 = 0; //1번 대상 지정
		int choice2 = 0; //2번 대상 지정
		if (pokemon[0].monhp > 0 && pokemon[1].monhp > 0) //////////////////////////////////////파이리 꼬부기 모두 살아있을 때
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 0, 5);
			DotSetPokemon(pokemon[1], 0, 27);
			DotSetMyPokemon(MyPokemon, 20, 2);
			PrintTextZone();
			DotPrintScreen();
			PrintSkillText(MyPokemon);
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");
			Fskill = ChoiceSkill(MyPokemon);  ///////////////////////1번 스킬 선택
			if (Fskill == 0) ////////// 스킬 재선택
			{
				continue;
			}
			else if (Fskill == 1 || Fskill == 2)
			{
				DotSetBG(BackGr);
				DotSetPokemon(pokemon[0], 0, 5);
				DotSetPokemon(pokemon[1], 0, 27);
				DotSetMyPokemon(MyPokemon, 20, 2);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB("", PickEnemy);
				printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
				system("pause");
				choice1 = ChoiceTarget(); ///////////////////////////1번 스킬 대상 지정

				if (choice1 == 0) ////////////////////////////////////// 대상 재선택
				{
					continue;
				}
			}

			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 0, 5);
			DotSetPokemon(pokemon[1], 0, 27);
			DotSetMyPokemon(MyPokemon, 20, 2);
			PrintTextZone();
			DotPrintScreen();
			PrintSkillText(MyPokemon);
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");
			Sskill = ChoiceSkill(MyPokemon); ////////////////////2번 스킬 선택

			if (Sskill == 0) ///////// 스킬 재선택
			{
				continue;
			}
			else if (Sskill == 1 || Sskill == 2)
			{
				DotSetBG(BackGr);
				DotSetPokemon(pokemon[0], 0, 5);
				DotSetPokemon(pokemon[1], 0, 27);
				DotSetMyPokemon(MyPokemon, 20, 2);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB("", PickEnemy);
				printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
				system("pause");
				choice2 = ChoiceTarget(); ///////////////////////////1번 스킬 대상 지정

				if (choice2 == 0) ////////////////////////////////////// 대상 재선택
				{
					continue;
				}
			}
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 0, 5);
			DotSetPokemon(pokemon[1], 0, 27);
			DotSetMyPokemon(MyPokemon, 20, 2);
			PrintTextZone();
			DotPrintScreen();

			PrintExplainText(" ", pokemon[0], MyPokemon, UsingSkill, Fskill);
			result = ResultSkillDB(choice1, MyPokemon, Fskill);
			Sleep(1000);

			if (result == 0)
			{
				pokemon[choice1 - 1].monhp -= skill[MyPokemon.Skill1].Dmg / 2;
				PrintExplainText("효과가 별로였다. ", pokemon[choice1 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 1)
			{
				pokemon[choice1 - 1].monhp -= skill[MyPokemon.Skill1].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[choice1 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 2)
			{
				pokemon[choice1 - 1].monhp -= skill[MyPokemon.Skill1].Dmg * 2;
				PrintExplainText("효과가 굉장했다! ", pokemon[choice1 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 3)
			{
				pokemon[choice1 - 1].monhp -= skill[MyPokemon.Skill2].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[choice1 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 4)
			{
				MyPokemon.monhp += skill[MyPokemon.Skill3].Dmg;
				if (MyPokemon.monhp > 100)MyPokemon.monhp = 100;
				PrintExplainText("체력을 회복했다. ", pokemon[choice1 - 1], MyPokemon, Explain, 1);
			}
			else continue;
			if (pokemon[0].monhp < 0)pokemon[0].monhp = 0;
			if (pokemon[1].monhp < 0)pokemon[1].monhp = 0;
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");
			DotPrintScreen();

			PrintExplainText(" ", pokemon[1], MyPokemon, UsingSkill, Sskill);
			result = ResultSkillDB(choice2, MyPokemon, Sskill);
			Sleep(1000);

			if (result == 0)
			{
				pokemon[choice2 - 1].monhp -= skill[MyPokemon.Skill1].Dmg / 2;
				PrintExplainText("효과가 별로였다. ", pokemon[choice2 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 1)
			{
				pokemon[choice2 - 1].monhp -= skill[MyPokemon.Skill1].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[choice2 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 2)
			{
				pokemon[choice2 - 1].monhp -= skill[MyPokemon.Skill1].Dmg * 2;
				PrintExplainText("효과가 굉장했다! ", pokemon[choice2 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 3)
			{
				pokemon[choice2 - 1].monhp -= skill[MyPokemon.Skill2].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[choice2 - 1], MyPokemon, Explain, 1);
			}
			else if (result == 4)
			{
				MyPokemon.monhp += skill[MyPokemon.Skill3].Dmg;
				if (MyPokemon.monhp > 100)MyPokemon.monhp = 100;
				PrintExplainText("체력을 회복했다. ", pokemon[choice2 - 1], MyPokemon, Explain, 1);
			}
			else continue;
			if (pokemon[0].monhp < 0)pokemon[0].monhp = 0;
			if (pokemon[1].monhp < 0)pokemon[1].monhp = 0;
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");

			if (pokemon[0].monhp <= 0 && pokemon[1].monhp <= 0) ////////////// 클리어 시
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB ("전투에서 승리했다! ", Explain);
				system("pause");
				return 0;
			}

			if (pokemon[0].monhp <= 0) ////////// 파이리 사망
			{
				DotSetBG(BackGr);
				DotSetMyPokemon(MyPokemon, 20, 2);
				DotSetPokemon(pokemon[1], 0, 27);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB ("파이리는 쓰러졌다. ", Explain);
				system("pause");
			}
			else if (pokemon[1].monhp <= 0) ///////// 꼬부기 사망
			{
				DotSetBG(BackGr);
				DotSetMyPokemon(MyPokemon, 20, 2);
				DotSetPokemon(pokemon[0], 0, 27);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB ("꼬부기는 쓰러졌다. ", Explain);
				system("pause");
			}
		}
		else if (pokemon[0].monhp > 0 && pokemon[1].monhp <= 0) ////////////////////////////////////////////////////// 파이리만 생존
		{
			DotSetBG(BackGr);
			DotSetMyPokemon(MyPokemon, 20, 2);
			DotSetPokemon(pokemon[0], 0, 27);
			PrintTextZone();
			DotPrintScreen();
			PrintSkillText(MyPokemon);
			printf("상대 체력: %d        내 체력: %d \n", pokemon[0].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");
			Fskill = ChoiceSkill(MyPokemon);
			DotSetBG(BackGr);
			DotSetMyPokemon(MyPokemon, 20, 2);
			DotSetPokemon(pokemon[0], 0, 27);
			PrintTextZone();
			DotPrintScreen();

			PrintExplainText(" ", pokemon[0], MyPokemon, UsingSkill, Fskill);
			result = ResultSkill(pokemon[0], MyPokemon, Fskill);
			Sleep(1000);

			if (result == 0)
			{
				pokemon[0].monhp -= skill[MyPokemon.Skill1].Dmg / 2;
				PrintExplainText("효과가 별로였다. ", pokemon[0], MyPokemon, Explain, 1);
			}
			else if (result == 1)
			{
				pokemon[0].monhp -= skill[MyPokemon.Skill1].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[0], MyPokemon, Explain, 1);
			}
			else if (result == 2)
			{
				pokemon[0].monhp -= skill[MyPokemon.Skill1].Dmg * 2;
				PrintExplainText("효과가 굉장했다! ", pokemon[0], MyPokemon, Explain, 1);
			}
			else if (result == 3)
			{
				pokemon[0].monhp -= skill[MyPokemon.Skill2].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[0], MyPokemon, Explain, 1);
			}
			else if (result == 4)
			{
				MyPokemon.monhp += skill[MyPokemon.Skill3].Dmg;
				if (MyPokemon.monhp > 100)MyPokemon.monhp = 100;
				PrintExplainText("체력을 회복했다. ", pokemon[0], MyPokemon, Explain, 1);
			}
			else continue;
			if (pokemon[0].monhp < 0)pokemon[0].monhp = 0;
			printf("상대 체력: %d        내 체력: %d \n", pokemon[0].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");

			if (pokemon[0].monhp <= 0 && pokemon[1].monhp <= 0) ///////////////// 클리어
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB ("전투에서 승리했다! ", Explain);
				system("pause");
				return 0;
			}
		}
		else if (pokemon[0].monhp <= 0 && pokemon[1].monhp > 0) /////////////////////////////////////////////// 꼬부기만 생존
		{
			DotSetBG(BackGr);
			DotSetMyPokemon(MyPokemon, 20, 2);
			DotSetPokemon(pokemon[1], 0, 27);
			PrintTextZone();
			DotPrintScreen();
			PrintSkillText(MyPokemon);
			printf("상대 체력: %d        내 체력: %d \n", pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");
			Fskill = ChoiceSkill(MyPokemon);
			DotSetBG(BackGr);
			DotSetMyPokemon(MyPokemon, 20, 2);
			DotSetPokemon(pokemon[1], 0, 27);
			PrintTextZone();
			DotPrintScreen();

			PrintExplainText(" ", pokemon[1], MyPokemon, UsingSkill, Fskill);
			result = ResultSkill(pokemon[1], MyPokemon, Fskill);
			Sleep(1000);

			if (result == 0)
			{
				pokemon[1].monhp -= skill[MyPokemon.Skill1].Dmg / 2;
				PrintExplainText("효과가 별로였다. ", pokemon[1], MyPokemon, Explain, 1);
			}
			else if (result == 1)
			{
				pokemon[1].monhp -= skill[MyPokemon.Skill1].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[1], MyPokemon, Explain, 1);
			}
			else if (result == 2)
			{
				pokemon[1].monhp -= skill[MyPokemon.Skill1].Dmg * 2;
				PrintExplainText("효과가 굉장했다! ", pokemon[1], MyPokemon, Explain, 1);
			}
			else if (result == 3)
			{
				pokemon[1].monhp -= skill[MyPokemon.Skill2].Dmg;
				PrintExplainText("효과는 보통이었다. ", pokemon[1], MyPokemon, Explain, 1);
			}
			else if (result == 4)
			{
				MyPokemon.monhp += skill[MyPokemon.Skill3].Dmg;
				if (MyPokemon.monhp > 100)MyPokemon.monhp = 100;
				PrintExplainText("체력을 회복했다. ", pokemon[1], MyPokemon, Explain, 1);
			}
			else continue;
			if (pokemon[1].monhp < 0)pokemon[1].monhp = 0;
			printf("상대 체력: %d        내 체력: %d \n", pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");

			if (pokemon[0].monhp <= 0 && pokemon[1].monhp <= 0) //////// 클리어
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB ("전투에서 승리했다! ", Explain);
				system("pause");
				return 0;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 상대 포켓몬 공격턴
		if (pokemon[0].monhp > 0 && pokemon[1].monhp > 0)////////////////////////////////////////////////////////////////////////////둘 다 생존 시 상대 공격
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 0, 5);
			DotSetPokemon(pokemon[1], 0, 27);
			DotSetMyPokemon(MyPokemon, 20, 2);
			PrintTextZone();
			DotPrintScreen();
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			PrintExplainTextDB (" ", Enemy1Turn);
			Sleep(1000);
			MyPokemon.monhp -= 20;
			DotPrintScreen();
			PrintExplainTextDB ("효과는 평범했다. ", Explain);
			if (MyPokemon.monhp < 0)MyPokemon.monhp = 0;
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");

			if (MyPokemon.monhp <= 0)
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB ("눈 앞이 새하얘졌다.. ", Explain);
				system("pause");
				return 1;
			}
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 0, 5);
			DotSetPokemon(pokemon[1], 0, 27);
			DotSetMyPokemon(MyPokemon, 20, 2);
			PrintTextZone();
			DotPrintScreen();
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			PrintExplainTextDB(" ", Enemy2Turn);
			Sleep(1000);
			MyPokemon.monhp -= 20;
			DotPrintScreen();
			PrintExplainTextDB("효과는 평범했다. ", Explain);
			if (MyPokemon.monhp < 0)MyPokemon.monhp = 0;
			printf("1번 체력: %d    2번 체력: %d     내 체력: %d \n", pokemon[0].monhp, pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");

			if (MyPokemon.monhp <= 0)
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB("눈 앞이 새하얘졌다.. ", Explain);
				system("pause");
				return 1;
			}
		}
		else if (pokemon[0].monhp > 0 && pokemon[1].monhp <= 0) ///////////////////////////////////////////////////////////////////////////파이리만 생존 시 상대 공격턴
		{
			DotSetBG(BackGr);
			DotSetMyPokemon(MyPokemon, 20, 2);
			DotSetPokemon(pokemon[0], 0, 27);
			PrintTextZone();
			DotPrintScreen();
			printf("상대 체력: %d        내 체력: %d \n", pokemon[0].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			PrintExplainTextDB(" ", Enemy1Turn);
			Sleep(1000);
			MyPokemon.monhp -= 20;
			DotPrintScreen();
			PrintExplainTextDB("효과는 평범했다. ", Explain);
			if (MyPokemon.monhp < 0)MyPokemon.monhp = 0;
			printf("상대 체력: %d        내 체력: %d \n", pokemon[0].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");

			if (MyPokemon.monhp <= 0)
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB("눈 앞이 새하얘졌다.. ", Explain);
				system("pause");
				return 1;
			}
		}
		else if (pokemon[0].monhp <= 0 && pokemon[1].monhp > 0) //////////////////////////////////////////////////////////////////////꼬부기만 생존 시 상대 공격턴
		{
			DotSetBG(BackGr);
			DotSetMyPokemon(MyPokemon, 20, 2);
			DotSetPokemon(pokemon[1], 0, 27);
			PrintTextZone();
			DotPrintScreen();
			printf("상대 체력: %d        내 체력: %d \n", pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			PrintExplainTextDB(" ", Enemy2Turn);
			Sleep(1000);
			MyPokemon.monhp -= 20;
			DotPrintScreen();
			PrintExplainTextDB("효과는 평범했다. ", Explain);
			if (MyPokemon.monhp < 0)MyPokemon.monhp = 0;
			printf("상대 체력: %d        내 체력: %d \n", pokemon[1].monhp, MyPokemon.monhp); /////////////////////////////////// 임시 체력 표시
			system("pause");

			if (MyPokemon.monhp <= 0)
			{
				DotSetBG(BackGr);
				PrintTextZone();
				DotPrintScreen();
				PrintExplainTextDB("눈 앞이 새하얘졌다.. ", Explain);
				system("pause");
				return 1;
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////콘솔창 설정 함수
static int SetConsoleSizeStable(short cols, short lines, short scrollLine)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut == INVALID_HANDLE_VALUE) return 0;

	if (scrollLine < lines) scrollLine = lines;


	COORD maxWin = GetLargestConsoleWindowSize(hOut);
	if (maxWin.X > 0 && cols > maxWin.X) cols = maxWin.X;
	if (maxWin.Y > 0 && lines > maxWin.Y) lines = maxWin.Y;

	SMALL_RECT tiny = { 0, 0, 0, 0 };
	if (!SetConsoleWindowInfo(hOut, TRUE, &tiny)) return 0;

	COORD buf = { cols,scrollLine };
	if (!SetConsoleScreenBufferSize(hOut, buf)) return 0;

	SMALL_RECT win = { 0, 0, (short)(cols - 1),(short)(lines - 1) };
	if (!SetConsoleWindowInfo(hOut, TRUE, &win)) return 0;

	return 1;
}
//////////////////////////////////////////////////////////////////////////////////////////////// 포켓몬 입히기 함수
void DotSetPokemon(struct Pokemon pokemon, int StartX, int StartY)
{
	for (int i = StartX; i < StartX + 19; i++)
	{
		for (int j = StartY; j < StartY + 22; j++)
		{
			if (pokemon.DotPokemon[i - StartX][j - StartY] == 99) continue;
			else BattleField[i][j] = pokemon.DotPokemon[i - StartX][j - StartY];
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////// 아군 포켓몬 입히기 함수
void DotSetMyPokemon(struct MyPokemon MyPokemon, int StartX, int StartY)
{
	for (int i = StartX; i < StartX + 19; i++)
	{
		for (int j = StartY; j < StartY + 22; j++)
		{
			if (MyPokemon.DotPokemon[i - StartX][j - StartY] == 99) continue;
			else BattleField[i][j] = MyPokemon.DotPokemon[i - StartX][j - StartY];
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////// 스킬사용 결과 함수
int ResultSkill(struct Pokemon pokemon, struct MyPokemon MyPokemon, int skillNum)
{
	int result = 0;
	if (skillNum == 1)
	{
		if (skill[MyPokemon.Skill1].typeNum == Fire)
		{
			if (pokemon.typeNum == Fire)
			{
				result = 1;
			}
			else if (pokemon.typeNum == Leaf)
			{
				result = 2;
			}
			else if (pokemon.typeNum == Water)
			{
				result = 0;
			}
		}
		else if (skill[MyPokemon.Skill1].typeNum == Water)
		{
			if (pokemon.typeNum == Fire)
			{
				result = 2;
			}
			else if (pokemon.typeNum == Leaf)
			{
				result = 0;
			}
			else if (pokemon.typeNum == Water)
			{
				result = 1;
			}
		}
		else if (skill[MyPokemon.Skill1].typeNum == Leaf)
		{
			if (pokemon.typeNum == Fire)
			{
				result = 0;
			}
			else if (pokemon.typeNum == Leaf)
			{
				result = 1;
			}
			else if (pokemon.typeNum == Water)
			{
				result = 2;
			}
		}
	}
	else if (skillNum == 2)
	{
		result = 3;
	}
	else if (skillNum == 3)
	{
		result = 4;
	}
	return result;;
}
///////////////////////////////////////////////////////////////////////////////////////////// 스킬사용 결과 함수 더블 배틀
int ResultSkillDB(int target, struct MyPokemon MyPokemon, int skillNum)
{
	int result = 0;
	if (target == 1)
	{
		if (skillNum == 1)
		{
			if (skill[MyPokemon.Skill1].typeNum == Fire)
			{
				result = 1;
			}
			else if (skill[MyPokemon.Skill1].typeNum == Water)
			{
				result = 2;
			}
			else if (skill[MyPokemon.Skill1].typeNum == Leaf)
			{
				result = 0;
			}
		}
		else if (skillNum == 2)
		{
			result = 3;
		}
		else if (skillNum == 3)
		{
			result = 4;
		}
	}
	else if (target == 2)
	{
		if (skillNum == 1)
		{
			if (skill[MyPokemon.Skill1].typeNum == Fire)
			{
				result = 0;
			}
			else if (skill[MyPokemon.Skill1].typeNum == Water)
			{
				result = 1;
			}
			else if (skill[MyPokemon.Skill1].typeNum == Leaf)
			{
				result = 2;
			}
		}
		else if (skillNum == 2)
		{
			result = 3;
		}
		else if (skillNum == 3)
		{
			result = 4;
		}
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////// 배경 입히기
void DotSetBG(struct BackGr BackGr)
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			BattleField[i][j] = BackGr.Grass[i][j];
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////// 텍스트존 입히기
void PrintTextZone()
{
	for (int i = 30; i < 40; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			BattleField[i][j] = TextZone[i-30][j];
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////// 스킬 선택창 출력
void PrintSkillText(struct MyPokemon MyPokemon)
{
	SetColor(0, 7);
	gotoxy(21, 32);
	printf(" %s", skill[MyPokemon.Skill1].name);
	gotoxy(56, 32);
	printf(" %s", skill[MyPokemon.Skill2].name);
	gotoxy(21, 37);
	printf(" %s", skill[MyPokemon.Skill3].name);
	SetColor(15, 0);
	gotoxy(0, 41);
}

/////////////////////////////////////////////////////////////////////////////////////////// 적 몬스터 선택창 출력
void PrintPickEnemyText(char* Enemy1, char* Enemy2, char* Enemy3, char* Enemy4)
{
	SetColor(0, 7);
	gotoxy(22, 32);
	printf("%s", Enemy1);
	gotoxy(57, 32);
	printf("%s", Enemy2);
	gotoxy(22, 37);
	printf("%s", Enemy3);
	gotoxy(57, 37);
	printf("%s", Enemy4);
	SetColor(15, 0);
	gotoxy(0, 41);
}


/////////////////////////////////////////////////////////////////////////////////////////// 설명창 출력
void PrintExplainText(char* Text, struct Pokemon pokemon, struct MyPokemon MyPokemon, int Situation, int skillNum)
{
	SetColor(0, 7);
	if (Situation == EncountEnemy)
	{
		gotoxy(38, 32);
		printf("%s 가 승부를 걸어왔다. ", pokemon.name);
		gotoxy(38, 35);
		printf("%s ", pokemon.name);
		gotoxy(38, 37);
		printf("HP: %d  타입: %s ", pokemon.monhp, pokemon.type);
	}
	else if (Situation == Explain)
	{
		gotoxy(35, 34);
		printf("%s", Text);
	}
	else if (Situation == EnemyTurn)
	{
		gotoxy(38, 34);
		printf("%s의 몸통박치기! ", pokemon.name);
	}
	else if (Situation == UsingSkill)
	{
		gotoxy(38, 34);
		if (skillNum == 1)
		{
			printf("%s!", skill[MyPokemon.Skill1].name);
		}
		else if (skillNum == 2)
		{
			printf("%s!", skill[MyPokemon.Skill2].name);
		}
		else if (skillNum == 3)
		{
			printf("%s!", skill[MyPokemon.Skill3].name);
		}
	}
	SetColor(15, 0);
	gotoxy(0, 41);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////// 더블배틀 설명창 출력
void PrintExplainTextDB(char* Text, int Situation)
{
	SetColor(0, 7);
	if (Situation == EncountEnemy)
	{
		gotoxy(30, 32);
		printf("%s와 %s가 승부를 걸어왔다. ", pokemon[0].name, pokemon[1].name);
		gotoxy(30, 35);
		printf("%s                 %s ", pokemon[0].name, pokemon[1].name);
		gotoxy(30, 37);
		printf("HP: %d  타입: %s      HP: %d  타입: %s", pokemon[0].monhp, pokemon[0].type, pokemon[1].monhp, pokemon[1].type);
	}
	else if (Situation == Explain)
	{
		gotoxy(38, 34);
		printf("%s", Text);
	}
	else if (Situation == Enemy1Turn)
	{
		gotoxy(38, 34);
		printf("%s의 몸통박치기! ", pokemon[0].name);
	}
	else if (Situation == Enemy2Turn)
	{
		gotoxy(38, 34);
		printf("%s의 몸통박치기! ", pokemon[1].name);
	}
	else if (Situation == PickEnemy)
	{
		gotoxy(35, 32);
		printf("누구에게 사용하시겠습니까? ");
		gotoxy(30, 35);
		printf(" %s                   %s ", pokemon[0].name, pokemon[1].name);
	}
	SetColor(15, 0);
	gotoxy(0, 41);
}

/////////////////////////////////////////////////////////////////////////////////////////// 스킬 고르기 함수
int ChoiceSkill(struct MyPokemon MyPokemon)
{
	int ChoiceNum = 1;

	SetColor(0, 7);
	gotoxy(20, 32);
	printf("▶");
	SetColor(15, 0);
	while (1)
	{
		int ArrowKeys = _getch();
		if (ArrowKeys == 224 || ArrowKeys == 0)
		{
			ArrowKeys = _getch();
			if (ChoiceNum == 1)
			{
				if (ArrowKeys == Right)
				{
					PrintSkillText(MyPokemon);
					SetColor(0, 7);
					gotoxy(55, 32);
					printf("▶");
					SetColor(15, 0);
					ChoiceNum = 2;
				}
				else if (ArrowKeys == Down)
				{
					PrintSkillText(MyPokemon);
					SetColor(0, 7);
					gotoxy(20, 37);
					printf("▶");
					SetColor(15, 0);
					ChoiceNum = 3;
				}
				else continue;
			}
			else if (ChoiceNum == 2)
			{
				if (ArrowKeys == Left)
				{
					PrintSkillText(MyPokemon);
					SetColor(0, 7);
					gotoxy(20, 32);
					printf("▶");
					SetColor(15, 0);
					ChoiceNum = 1;
				}
				else continue;
			}
			else if (ChoiceNum == 3)
			{
				if (ArrowKeys == Up)
				{
					PrintSkillText(MyPokemon);
					SetColor(0, 7);
					gotoxy(20, 32);
					printf("▶");
					SetColor(15, 0);
					ChoiceNum = 1;
				}
				else continue;
			}
			else continue;
		}
		else if (ArrowKeys == 99)
		{
			break;
		}
		else if (ArrowKeys == 120)
		{
			ChoiceNum = 0;
			break;
		}
		else continue;
	}
	return ChoiceNum;
}

///////////////////////////////////////////// 대전 상대 선택 함수
int ChoiceOption(int NMax, int GMax)
{
	int NumMax = NMax - 1;
	int GaroMax = GMax;
	int SeroMax = NMax / GMax;
	if (NMax % GMax > 0) SeroMax += 1;
	int temp = 0;
	int ChoiceNum = 0;

	SetColor(0, 7);
	gotoxy(20, 32);
	printf("▶");
	while (1)
	{
		int ArrowKeys = _getch();
		if (ArrowKeys == 224 || ArrowKeys == 0)
		{
			gotoxy(20 + ChoiceNum % GaroMax * 35, 32 + ChoiceNum / GaroMax * 5);
			printf("  ");
			ArrowKeys = _getch();
			if (ArrowKeys == Up)
			{
				ChoiceNum -= GaroMax;
				temp = ChoiceNum;
				if (ChoiceNum < 0)ChoiceNum = GaroMax * SeroMax + temp;
				if (ChoiceNum > NumMax)ChoiceNum -= GaroMax;
			}
			else if (ArrowKeys == Down)
			{
				ChoiceNum += GaroMax;
				temp = ChoiceNum;
				if (ChoiceNum > NumMax) ChoiceNum = temp % GaroMax;
			}
			else if (ArrowKeys == Right)
			{
				ChoiceNum += 1;
				temp = ChoiceNum ;
				if (ChoiceNum % GaroMax == 0)ChoiceNum -= GaroMax;
				else if (ChoiceNum > NumMax)ChoiceNum = GaroMax * SeroMax - GaroMax;
			}
			else if (ArrowKeys == Left)
			{
				ChoiceNum -= 1;
				temp = ChoiceNum + 1;
				if (ChoiceNum == GaroMax * (temp / GaroMax) - 1 || ChoiceNum < 0)ChoiceNum += GaroMax;
				if (ChoiceNum > NumMax)ChoiceNum = NumMax;
			}
			gotoxy(20 + ChoiceNum % GaroMax * 35, 32 + ChoiceNum / GaroMax * 5);
			printf("▶");
		}
		else if (ArrowKeys == 99)break;
		else continue;
	}
	SetColor(15, 0);
	return ChoiceNum;
}

/////////////////////////////////////////////////////////////////////////////// 스킬의 타켓 함수
int ChoiceTarget()
{
	int ChoiceNum = 1;

	SetColor(0, 7);
	gotoxy(29, 35);
	printf("▶");
	SetColor(15, 0);

	while (1)
	{
		int ArrowKeys = _getch();
		if (ArrowKeys == 224 || ArrowKeys == 0)
		{
			ArrowKeys = _getch();
			if (ChoiceNum == 1)
			{
				if (ArrowKeys == Right)
				{
					PrintExplainTextDB(" ", PickEnemy);
					SetColor(0, 7);
					gotoxy(54, 35);
					printf("▶");
					SetColor(15, 0);
					ChoiceNum = 2;
				}
				else continue;
			}
			else if (ChoiceNum == 2)
			{
				if (ArrowKeys == Left)
				{
					PrintExplainTextDB(" ", PickEnemy);
					SetColor(0, 7);
					gotoxy(29, 35);
					printf("▶");
					SetColor(15, 0);
					ChoiceNum = 1;
				}
				else continue;
			}
		}
		else if (ArrowKeys == 99)
		{
			break;
		}
		else if (ArrowKeys == 120)
		{
			ChoiceNum = 0;
			break;
		}
	}
	return ChoiceNum;
}

//////////////////////////////////////////////////// 커서 없애기 함수
void CursorView(char show)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = show;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

//////////////////////////////////////////////// 아군 포켓몬 선택 함수
int ChoicePokeText()
{
	int ChoiceNum = 0;

	SetColor(0, 7);
	gotoxy(39, 32);
	printf("▶");

	while (1)
	{
		int ArrowKeys = _getch();
		if (ArrowKeys == 224 || ArrowKeys == 0)
		{
			gotoxy(39, 32 + ChoiceNum * 2);
			printf("  ");
			ArrowKeys = _getch();
			if (ArrowKeys == Up)
			{
				ChoiceNum -= 1;
				if (ChoiceNum < 0)ChoiceNum += 3;
			}
			else if (ArrowKeys == Down)
			{
				ChoiceNum += 1;
				if (ChoiceNum > 2)ChoiceNum -= 3;
			}
			gotoxy(39, 32 + ChoiceNum * 2);
			printf("▶");
		}
		else if (ArrowKeys == 99) break;
		else continue;
	}
	SetColor(15, 0);
	return ChoiceNum;
}

void PrintPickPokeText(int num)
{
	SetColor(0, 7);
	if (num <= 3)
	{
		gotoxy(41, 32);
		printf("%s    %s", MyPokemon[0].name, MyPokemon[0].type);
	}
	if (num <= 3 && num > 1)
	{
		gotoxy(41, 34);
		printf("%s    %s", MyPokemon[1].name, MyPokemon[1].type);
	}
	if (num <= 3 && num > 2)
	{
		gotoxy(41, 36);
		printf("%s    %s", MyPokemon[2].name, MyPokemon[2].type);
	}
	SetColor(15, 0);
	gotoxy(0, 41);
}
