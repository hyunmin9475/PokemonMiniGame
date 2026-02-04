#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include <string.h>

///////////////////////////////  상수파트
#define PokemonDot_Garo 19
#define PokemonDot_Sero 22
#define BattleField_Garo 50
#define BattleField_Sero 50
#define BackGr_Garo 50
#define BackGr_Sero 50
#define EncountEnemy 1
#define Explain 2
#define EnemyTurn 3

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

////////////////////구조체///////////////////////////
struct Pokemon {
	int PokeNum;  //포켓몬 고유 번호
	char* name;   //포켓몬의 이름
	int monhp;    //포켓몬의 체력
	char* type;   //포켓몬의 타입
	int typeNum;  //타입 고유 번호
	int DotPokemon[PokemonDot_Garo][PokemonDot_Sero]; //도트 배열
};

/////////// 포켓몬 구조체 초기화
struct Pokemon pokemon[3] = {
			{1,"파이리",100,"불",1,{{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,0,99,99,99,99},
		{99,99,99,99,99,0,0,0,99,99,99,99,99,99,99,99,0,6,0,99,99,99},
		{99,99,99,0,0,12,12,6,0,99,99,99,99,99,99,99,0,6,6,0,99,99},
		{99,99,0,12,12,12,12,12,6,0,99,99,99,99,99,99,0,6,6,0,99,99},
		{99,99,0,12,12,12,12,12,12,0,99,99,99,99,99,0,6,6,12,6,0,99},
		{99,0,12,12,12,12,6,12,12,6,0,99,99,99,99,0,6,12,14,6,0,99},
		{99,0,12,12,12,6,15,0,12,12,0,99,99,99,99,0,6,14,14,6,0,99},
		{0,12,12,12,12,4,9,0,12,6,0,99,99,99,99,99,0,14,6,0,99,99},
		{0,12,12,12,12,12,0,0,6,6,0,99,99,99,99,99,0,6,0,99,99,99},
		{99,0,6,12,12,12,6,6,6,6,6,0,99,99,99,99,0,12,0,99,99,99},
		{99,99,0,0,6,6,6,6,6,6,6,0,99,99,99,0,12,12,0,99,99,99},
		{99,99,99,99,0,0,2,6,6,8,6,6,0,99,0,6,12,0,99,99,99,99},
		{99,99,99,99,99,0,14,14,8,4,12,6,6,0,6,6,6,0,99,99,99,99},
		{99,99,99,99,99,0,14,14,8,12,6,8,6,6,8,6,0,99,99,99,99,99},
		{99,99,99,99,0,4,4,14,14,8,8,6,6,6,8,0,99,99,99,99,99,99},
		{99,99,99,99,0,2,4,8,2,2,6,6,6,4,0,99,99,99,99,99,99,99},
		{99,99,99,99,99,0,0,0,0,8,4,6,4,0,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,0,99,4,99,0,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,0,0,0,99,99,99,99,99,99,99,99,99}}},//여기까지 파이리
			{2,"꼬부기",100,"물",2,{{99,99,99,0,0,0,0,99,99,99,99,99,99,99,99,99,0,0,0,99,99,99},
		{99,99,0,3,9,9,9,0,0,99,99,99,99,99,99,0,9,9,9,0,99,99},
		{99,0,9,9,9,9,9,9,3,0,0,99,99,99,0,9,9,9,3,3,0,99},
		{99,0,9,9,9,9,9,9,9,8,2,0,0,99,0,9,9,3,8,3,0,99},
		{0,9,9,9,9,3,9,9,9,3,8,10,2,0,3,9,3,8,3,3,0,99},
		{0,9,9,9,3,15,0,9,9,3,8,2,10,2,8,3,3,8,3,0,99,99},
		{0,9,9,9,3,0,0,9,3,3,8,99,2,10,8,3,3,8,0,99,99,99},
		{99,0,9,9,9,0,10,3,3,8,99,99,2,10,2,8,3,0,99,99,99,99},
		{99,99,0,8,3,3,3,3,8,3,8,99,99,2,10,8,3,0,99,99,99,99},
		{99,99,0,3,8,8,8,10,14,8,9,8,99,2,2,8,0,99,99,99,99,99},
		{99,99,99,0,0,14,14,14,8,9,9,9,8,2,10,0,99,99,99,99,99,99},
		{99,99,99,99,99,0,10,10,8,9,9,3,8,2,10,0,99,99,99,99,99,99},
		{99,99,99,99,0,3,8,14,14,8,3,8,8,15,0,99,99,99,99,99,99,99},
		{99,99,99,99,0,3,3,0,10,10,8,8,3,8,0,99,99,99,99,99,99,99},
		{99,99,99,99,99,0,0,99,0,8,9,3,3,0,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,0,3,3,3,0,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,0,0,0,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99},
		{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99}}}, //여기까지 꼬부기
			{3,"이상해씨",100,"풀",3,{{99,99,99,99,99,99,99,99,99,99,99,99,0,99,0,99,99,99,99,99,99,99},
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
		{99,99,99,99,99,99,99,99,99,99,0,0,0,0,99,99,99,99,99,99,99,99}}}  //여기까지 이상해씨
};

struct BackGr {
	int Grass[BackGr_Garo][BackGr_Sero]; //풀숲 배경
}BackGr;

/////////// 내 포켓몬 이브이 선언
struct MyPokemon {
	char* name; // 이브이의 이름
	int monhp;  // 체력
	char* type; // 타입
	char* Skill1; // 스킬목록
	char* Skill2;
	char* Skill3;
	char* Skill4;
};

////////////// 내 포켓몬 이브이 초기화
struct MyPokemon Eevee[] = {
	{"이브이", 100, "노말", "불꽃세례", "물대포", "덩굴채찍", "HP회복"}
};

////////////////
////함수////////
///////////////

//도트 색 변경 함수 선언
static void SetColor(int color, int back);

//화면 출력 함수 선언
void DotPrintScreen();

//좌표함수 선언
void gotoxy(int x, int y);

//더블 배틀 함수 선언
int DoubleBattle(struct Pokemon* pokemon, int* hp);

//단일 배틀 함수 선언
int Battle(struct Pokemon pokemon, int* hp);

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
void PrintExplaneText(char *Text, struct Pokemon pokemon, int Situation);

//적 몬스터 선택창 출력 함수
void PrintPickEnemyText(char* Enemy1, char* Enemy2, char* Enemy3, char* Enemy4);


////////////////메인 함수////////////////////
int main(void)
{
	SetConsoleSizeStable(100, 50, 50); ////// 콘솔 창 설정
	while (1)
	{
		//////////////// 배경 초기화
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
			{
				BackGr.Grass[i][j] = 10;
			}
		}

		//////////////////////////////////플레이어 초기화
		int hp = 100;   //플레이어 체력
		int xp = 0;     //플레이어 경험치
		int pokeNum = 0;//상대 선택용 변수
		int win = 0, quit = 0; //승패 기록용, 다시하기 여부 변수

		//게임시작!!!!!!!!!!!!!!!
		while (1)
		{
			pokemon[0].monhp = 100;
			pokemon[1].monhp = 100;
			printf("세 포켓몬 중 누구와 싸울텐가?\n\n"); //////////선택지 제시, 야생 몬스터 도트 출력과 정보 표시
			Sleep(1500);

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
			Sleep(1000);

			//////////////야생 포켓몬 선택
			pokeNum = _getch();

			if (pokeNum == 52)
				win = DoubleBattle(pokemon, &hp);  //////////////////////////////////////////////더블 배틀 함수 호출
			else if (pokeNum != 49 && pokeNum != 50 && pokeNum != 51 && pokeNum != 52)
			{
				system("cls");
				continue;   /////선택지 외의 숫자 선택 시 다시 선택
			}
			else
				win = Battle(pokemon[pokeNum - 49], &hp); //////////////////배틀함수 호출

			//int battle(struct Pokemon pokemon, int* hp);
			//win = Battle(pokemon[pokeNum - 49], &hp); //////////////////배틀함수 호출

			///////////////////////////////승패에 따른 보상
			if (win == 0) {
				xp += 25;
				PrintExplaneText("경험치를 획득했습니다. ",pokemon[0], Explain);
				printf("%d/100\n\n", xp);
				system("pause");
				system("cls");
			}
			else if (win == 1)
			{
				PrintExplaneText("체력이 회복됐다. ", pokemon[0], Explain);
				hp = 100;
				system("pause");
				system("cls");
				continue;
			}
			/////////////////////////경험치 다 채우면 나가기
			if (xp >= 100)
			{
				system("cls");
				break;
			}
		}
		printf("다시 플레이 하시겠습니까?\n");  /////////////////다시하기 기능
		printf("YES: 1    NO:Other Number \n\n");
		quit = _getch();
		system("cls");

		if (quit != 49)
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
			if (BattleField[i][j] == 15)
			{
				SetColor(15, 15);
			}
			else if (BattleField[i][j] == 0)
			{
				SetColor(0, 0);
			}
			else if (BattleField[i][j] == 13)
			{
				SetColor(13, 13);
			}
			else if (BattleField[i][j] == 6)
			{
				SetColor(6, 6);
			}
			else if (BattleField[i][j] == 4)
			{
				SetColor(4, 4);
			}
			else if (BattleField[i][j] == 14)
			{
				SetColor(14, 14);
			}
			else if (BattleField[i][j] == 12)
			{
				SetColor(12, 12);
			}
			else if (BattleField[i][j] == 8)
			{
				SetColor(8, 8);
			}
			else if (BattleField[i][j] == 10)
			{
				SetColor(10, 10);
			}
			else if (BattleField[i][j] == 9)
			{
				SetColor(9, 9);
			}
			else if (BattleField[i][j] == 2)
			{
				SetColor(2, 2);
			}
			else if (BattleField[i][j] == 3)
			{
				SetColor(3, 3);
			}
			else if (BattleField[i][j] == 7)
			{
				SetColor(7, 7);
			}
			printf("  ");
		}
		printf("\n");
	}
	SetColor(15, 0);
}


///////////////// 배틀함수
int Battle(struct Pokemon pokemon, int* hp)
{
	DotSetBG(BackGr);
	PrintTextZone();
	DotSetPokemon(pokemon, 2, 15);
	DotPrintScreen();
	PrintExplaneText("", pokemon, EncountEnemy);
	Sleep(1500);

	while (1)
	{
		int Pskill = 0;
		DotSetBG(BackGr);
		PrintTextZone();
		DotSetPokemon(pokemon, 2, 15);
		DotPrintScreen();
		PrintSkillText(Eevee[0]);
		Pskill = _getch();
		DotSetBG(BackGr);
		PrintTextZone();
		DotSetPokemon(pokemon, 2, 15);
		DotPrintScreen();
		if (Pskill == 49)
		{
			PrintExplaneText("불꽃세례! ", pokemon, Explain);
			Sleep(1000);
			if (pokemon.typeNum == 3)
			{
				pokemon.monhp -= 30 * 2;
				PrintExplaneText("효과가 굉장했다! ", pokemon, Explain);
			}
			else if (pokemon.typeNum == 1)
			{
				pokemon.monhp -= 30;
				PrintExplaneText("효과는 보통이었다. ", pokemon, Explain);
			}
			else if (pokemon.typeNum == 2)
			{
				pokemon.monhp -= 30 / 2;
				PrintExplaneText("효과가 별로였다. ", pokemon, Explain);
			}
		}
		else if (Pskill == 50)
		{
			PrintExplaneText("물대포! ", pokemon, Explain);
			Sleep(1000);
			if (pokemon.typeNum == 1)
			{
				pokemon.monhp -= 30 * 2;
				PrintExplaneText("효과가 굉장했다! ", pokemon, Explain);
			}
			else if (pokemon.typeNum == 2)
			{
				pokemon.monhp -= 30;
				PrintExplaneText("효과는 보통이었다. ", pokemon, Explain);
			}
			else if (pokemon.typeNum == 3)
			{
				pokemon.monhp -= 30 / 2;
				PrintExplaneText("효과가 별로였다. ", pokemon, Explain);
			}
		}
		else if (Pskill == 51)
		{
			PrintExplaneText("덩굴채찍! ", pokemon, Explain);
			Sleep(1000);
			if (pokemon.typeNum == 2)
			{
				pokemon.monhp -= 30 * 2;
				PrintExplaneText("효과가 굉장했다! ", pokemon, Explain);
			}
			else if (pokemon.typeNum == 3)
			{
				pokemon.monhp -= 30;
				PrintExplaneText("효과는 보통이었다. ", pokemon, Explain);
			}
			else if (pokemon.typeNum == 1)
			{
				pokemon.monhp -= 30 / 2;
				PrintExplaneText("효과가 별로였다. ", pokemon, Explain);
			}
		}
		else if (Pskill == 52)
		{
			PrintExplaneText("HP회복! ", pokemon, Explain);
			Sleep(1000);
			*hp += 50;
			if (*hp > 100)*hp = 100;
			PrintExplaneText("체력을 회복했다. ", pokemon, Explain);
		}
		else
		{
			PrintExplaneText("존재하지 않는 선택지입니다. ", pokemon, Explain);
			system("pause");
			continue;
		}
		system("pause");

		if (pokemon.monhp <= 0)
		{
			DotSetBG(BackGr);
			PrintTextZone();
			DotPrintScreen();
			PrintExplaneText("전투에서 승리했다! ", pokemon, Explain);
			system("pause");
			return 0;
		}

		//상대 턴
		DotSetBG(BackGr);
		PrintTextZone();
		DotSetPokemon(pokemon, 2, 15);
		DotPrintScreen();
		PrintExplaneText(" ", pokemon, EnemyTurn);
		Sleep(1000);
		*hp -= 30;
		DotSetBG(BackGr);
		PrintTextZone();
		DotSetPokemon(pokemon, 2, 15);
		DotPrintScreen();
		PrintExplaneText("효과는 보통이었다. ", pokemon, Explain);
		system("pause");

		if (*hp <= 0)
		{
			DotSetBG(BackGr);
			PrintTextZone();
			DotPrintScreen();
			PrintExplaneText("눈 앞이 새하얘졌다.. ", pokemon, Explain);
			system("pause");
			return 1;
		}
	}
}

////////////////////더블 배틀 함수
int DoubleBattle(struct Pokemon* pokemon, int* hp)
{
	DotSetBG(BackGr);
	DotSetPokemon(pokemon[0], 2, 2);
	DotSetPokemon(pokemon[1], 2, 28);
	DotPrintScreen();
	printf("%s와 %s 가 승부를 걸어왔다. \n\n", pokemon[0].name, pokemon[1].name);
	printf("%s            %s \n", pokemon[0].name, pokemon[1].name);
	printf("HP: %d  타입: %s    HP: %d  타입: %s\n\n", pokemon[0].monhp, pokemon[0].type, pokemon[1].monhp, pokemon[1].type);
	Sleep(1000);

	while (1)
	{
		int Fskill = 0; //1번 스킬
		int Sskill = 0; //2번 스킬
		int choice1 = 0; //1번 대상 지정
		int choice2 = 0; //2번 대상 지정
		if (pokemon[0].monhp > 0 && pokemon[1].monhp > 0) //////////////////////////////////////파이리 꼬부기 모두 살아있을 때
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 2, 2);
			DotSetPokemon(pokemon[1], 2, 28);
			DotPrintScreen();
			PrintSkillText(Eevee[0]);
			printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
			Fskill = _getch();  ///////////////////////1번 스킬 선택

			if (Fskill != 49 && Fskill != 50 && Fskill != 51 && Fskill != 52) ////////// 스킬 재선택
			{
				printf("존재하지 않는 선택지 입니다. \n");
				continue;
			}
			else if (Fskill == 49 || Fskill == 50 || Fskill == 51)
			{
				DotSetBG(BackGr);
				DotSetPokemon(pokemon[0], 2, 2);
				DotSetPokemon(pokemon[1], 2, 28);
				DotPrintScreen();
				printf("누구에게 사용할까? \n");
				printf("1. %s       2. %s\n", pokemon[0].name, pokemon[1].name);
				choice1 = _getch(); ///////////////////////////1번 스킬 대상 지정

				if (choice1 != 49 && choice1 != 50) ////////////////////////////////////// 대상 재선택
				{
					printf("존재하지 않는 선택지 입니다. \n");
					continue;
				}
			}

			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 2, 2);
			DotSetPokemon(pokemon[1], 2, 28);
			DotPrintScreen();
			PrintSkillText(Eevee[0]);
			printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
			Sskill = _getch(); ////////////////////2번 스킬 선택

			if (Sskill != 49 && Sskill != 50 && Sskill != 51 && Sskill != 52) ///////// 스킬 재선택
			{
				printf("존재하지 않는 선택지 입니다. \n");
				continue;
			}
			else if (Sskill == 49 || Sskill == 50 || Sskill == 51)
			{
				DotSetBG(BackGr);
				DotSetPokemon(pokemon[0], 2, 2);
				DotSetPokemon(pokemon[1], 2, 28);
				DotPrintScreen();
				printf("누구에게 사용할까? \n");
				printf("1. %s       2. %s\n", pokemon[0].name, pokemon[1].name);
				choice2 = _getch(); ///////////////////////////1번 스킬 대상 지정

				if (choice2 != 49 && choice2 != 50) ////////////////////////////////////// 대상 재선택
				{
					printf("존재하지 않는 선택지 입니다. \n");
					continue;
				}
			}
			if (Fskill == 49) { /////////////////////////////////////////////////////////////////////////////////////////////////////////// 둘 다 생존) 1번 스킬로 1번 선택
				printf("불꽃세례! \n");
				if (choice1 == 49) {
					pokemon[0].monhp -= 30;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
					Sleep(1000);
				}
				else
				{
					pokemon[1].monhp -= 10;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
					Sleep(1000);
				}
			}
			else if (Fskill == 50) { /////////////////////////////////////////////////////////////// 둘 다 생존) 1번 스킬로 2번 선택
				printf("물대포! \n");
				if (choice1 == 49) {
					pokemon[0].monhp -= 30 * 2;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
					Sleep(1000);
				}
				else
				{
					pokemon[1].monhp -= 30;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
					Sleep(1000);
				}
			}
			else if (Fskill == 51) { //////////////////////////////////////////////////////////// 둘 다 생존) 1번 스킬로 3번 선택
				printf("덩굴채찍! \n");
				if (choice1 == 49) {
					pokemon[0].monhp -= 10;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
					Sleep(1000);
				}
				else
				{
					pokemon[1].monhp -= 30 * 2;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
					Sleep(1000);
				}
			}
			else if (Fskill == 52) { ////////////////////////////////////////////////////////// 둘 다 생존) 1번 스킬로 4번(회복) 선택
				printf("체력을 회복했다!\n");
				*hp += 50;
				if (*hp > 100)*hp = 100;
				printf("체력이 %d가 되었다.\n\n", *hp);
				Sleep(1000);
			}

			if (Sskill == 49) { /////////////////////////////////////////////////////////////////////////////////////////////////////////////////둘 다 생존) 2번 스킬 1번
				printf("불꽃세례! \n");
				if (choice2 == 49) {
					pokemon[0].monhp -= 30;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
					system("pause");
				}
				else
				{
					pokemon[1].monhp -= 10;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
					system("pause");
				}
			}
			else if (Sskill == 50) { ///////////////////////////////////////////////////////////////둘 다 생존) 2번 스킬 2번
				printf("물대포! \n");
				if (choice2 == 49) {
					pokemon[0].monhp -= 30 * 2;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
					system("pause");
				}
				else
				{
					pokemon[1].monhp -= 30;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
					system("pause");
				}
			}
			else if (Sskill == 51) { ////////////////////////////////////////////////////////////둘 다 생존) 2번 스킬 3번
				printf("덩굴채찍! \n");
				if (choice2 == 49) {
					pokemon[0].monhp -= 10;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
					system("pause");
				}
				else
				{
					pokemon[1].monhp -= 30 * 2;
					printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
					system("pause");
				}
			}
			else if (Sskill == 52) { //////////////////////////////////////////////////////////둘 다 생존) 2번 스킬 4번
				printf("체력을 회복했다!\n");
				*hp += 50;
				if (*hp > 100)*hp = 100;
				printf("체력이 %d가 되었다.\n\n", *hp);
				system("pause");
			}

			if (pokemon[0].monhp <= 0 && pokemon[1].monhp <= 0) ////////////// 클리어 시
			{
				system("cls");
				printf("전투에서 승리했다! \n");
				return 0;
			}

			if (pokemon[0].monhp <= 0) ////////// 파이리 사망
			{
				system("cls");
				printf("%s는 쓰러졌다.\n", pokemon[0].name);
				system("pause");
			}
			else if (pokemon[1].monhp <= 0) ///////// 꼬부기 사망
			{
				system("cls");
				printf("%s는 쓰러졌다.\n", pokemon[1].name);
				system("pause");
			}
		}
		else if (pokemon[0].monhp > 0 && pokemon[1].monhp <= 0) ////////////////////////////////////////////////////// 파이리만 생존
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 2, 15);
			DotPrintScreen();
			PrintSkillText(Eevee[0]);
			printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
			Fskill = _getch();
			if (Fskill == 49)
			{
				pokemon[0].monhp -= 30;
				printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
				system("pause");
			}
			else if (Fskill == 50)
			{
				pokemon[0].monhp -= 30 * 2;
				printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
				system("pause");
			}
			else if (Fskill == 51)
			{
				pokemon[0].monhp -= 10;
				printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[0].name, pokemon[0].monhp);
				system("pause");
			}
			else if (Fskill == 52)
			{
				printf("체력을 회복했다!\n");
				*hp += 50;
				if (*hp > 100)*hp = 100;
				printf("체력이 %d가 되었다.\n\n", *hp);
				system("pause");
			}

			if (pokemon[0].monhp <= 0 && pokemon[1].monhp <= 0) ///////////////// 클리어
			{
				system("cls");
				printf("전투에서 승리했다! \n");
				return 0;
			}
		}
		else if (pokemon[0].monhp <= 0 && pokemon[1].monhp > 0) /////////////////////////////////////////////// 꼬부기만 생존
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[1], 2, 15);
			DotPrintScreen();
			PrintSkillText(Eevee[0]);
			printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
			Fskill = _getch();
			if (Fskill == 49)
			{
				pokemon[1].monhp -= 10;
				printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
				system("pause");
			}
			else if (Fskill == 50)
			{
				pokemon[1].monhp -= 30;
				printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
				system("pause");
			}
			else if (Fskill == 51)
			{
				pokemon[1].monhp -= 30 * 2;
				printf("%s의 체력이 %d로 줄었다! \n\n", pokemon[1].name, pokemon[1].monhp);
				system("pause");
			}
			else if (Fskill == 52)
			{
				printf("체력을 회복했다!\n");
				*hp += 50;
				if (*hp > 100)*hp = 100;
				printf("체력이 %d가 되었다.\n\n", *hp);
				system("pause");
			}

			if (pokemon[0].monhp <= 0 && pokemon[1].monhp <= 0) //////// 클리어
			{
				system("cls");
				printf("전투에서 승리했다! \n");
				return 0;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////// 상대 포켓몬 공격턴
		if (pokemon[0].monhp > 0 && pokemon[1].monhp > 0)////////////////////////////////////////////////////////////////////////////둘 다 생존 시 상대 공격
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 2, 2);
			DotSetPokemon(pokemon[1], 2, 28); ///////////////////////////////////////// 둘 다 생존 시) 파이리 공격턴
			DotPrintScreen();
			printf("%s의 몸통박치기!\n", pokemon[0].name);
			*hp -= 20;
			printf("체력이 20 줄었다! %d/100 \n\n", *hp);
			system("pause");

			if (*hp <= 0)
			{
				system("cls");
				printf("눈 앞이 하얘졌다!\n\n");
				return 1;
			}
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 2, 2);
			DotSetPokemon(pokemon[1], 2, 28); ////////////////////////////////////////// 둘 다 생존 시) 꼬부기 공격턴
			DotPrintScreen();
			printf("%s의 몸통박치기!\n", pokemon[1].name);
			*hp -= 20;
			printf("체력이 20 줄었다! %d/100 \n\n", *hp);
			system("pause");

			if (*hp <= 0)
			{
				system("cls");
				printf("눈 앞이 하얘졌다!\n\n");
				return 1;
			}
		}
		else if (pokemon[0].monhp > 0 && pokemon[1].monhp <= 0) ///////////////////////////////////////////////////////////////////////////파이리만 생존 시 상대 공격턴
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[0], 2, 15);
			DotPrintScreen();
			printf("%s의 몸통박치기!\n", pokemon[0].name);
			*hp -= 20;
			printf("체력이 20 줄었다! %d/100 \n\n", *hp);
			system("pause");

			if (*hp <= 0)
			{
				system("cls");
				printf("눈 앞이 하얘졌다!\n\n");
				return 1;
			}
		}
		else if (pokemon[0].monhp <= 0 && pokemon[1].monhp > 0)
		{
			DotSetBG(BackGr);
			DotSetPokemon(pokemon[1], 2, 15);
			DotPrintScreen();
			printf("%s의 몸통박치기!\n", pokemon[1].name);
			*hp -= 20;
			printf("체력이 20 줄었다! %d/100 \n\n", *hp);
			system("pause");

			if (*hp <= 0)
			{
				system("cls");
				printf("눈 앞이 하얘졌다!\n\n");
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
			BattleField[i][j] = 7;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////// 스킬 선택창 출력
void PrintSkillText(struct MyPokemon Eevee)
{
	SetColor(0, 7);
	gotoxy(22, 32);
	printf("1: %s", Eevee.Skill1);
	gotoxy(57, 32);
	printf("2: %s", Eevee.Skill2);
	gotoxy(22, 37);
	printf("3: %s", Eevee.Skill3);
	gotoxy(57, 37);
	printf("4: %s", Eevee.Skill4);
	SetColor(15, 0);
	gotoxy(0, 41);
}

/////////////////////////////////////////////////////////////////////////////////////////// 적 몬스터 선택창 출력
void PrintPickEnemyText(char* Enemy1, char* Enemy2, char* Enemy3, char* Enemy4)
{
	SetColor(0, 7);
	gotoxy(18, 32);
	printf("%s", Enemy1);
	gotoxy(53, 32);
	printf("%s", Enemy2);
	gotoxy(18, 37);
	printf("%s", Enemy3);
	gotoxy(53, 37);
	printf("%s", Enemy4);
	SetColor(15, 0);
	gotoxy(0, 41);
}

/////////////////////////////////////////////////////////////////////////////////////////// 설명창 출력
void PrintExplaneText(char* Text, struct Pokemon pokemon, int Situation)
{
	SetColor(0, 7);
	if (Situation == EncountEnemy)
	{
		gotoxy(38, 32);
		printf("%s 가 승부를 걸어왔다. ", pokemon.name);
		gotoxy(38, 35);
		printf(" % s ", pokemon.name);
		gotoxy(38, 37);
		printf("HP: %d  타입: %s ", pokemon.monhp, pokemon.type);
	}
	else if (Situation == Explain)
	{
		gotoxy(38, 34);
		printf("%s", Text);
	}
	else if (Situation == EnemyTurn)
	{
		gotoxy(38, 34);
		printf("%s의 몸통박치기! ", pokemon.name);
	}
	SetColor(15, 0);
	gotoxy(0, 41);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}