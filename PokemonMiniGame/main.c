#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


////////////////////구조체///////////////////////////
struct Pokemon {
	int PokeNum;  //포켓몬 고유 번호
	char* name;   //포켓몬의 이름
	int monhp;    //포켓몬의 체력
	char* type;   //포켓몬의 타입
	int typeNum;  //타입 고유 번호
	int DotPokemon[19][22]; //도트 배열
};
struct Pokemon pokemon[3] = {
			{1,"파이리",100,"불",1,{{99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,0,99,99,99,99},
		{99,99,99,99,99,0,0,0,99,99,99,99,99,99,99,99,0,6,0,99,99,99},
		{99,99,99,0,0,13,13,6,0,99,99,99,99,99,99,99,0,6,6,0,99,99},
		{99,99,0,13,13,13,13,13,6,0,99,99,99,99,99,99,0,6,6,0,99,99},
		{99,99,0,13,13,13,13,13,13,0,99,99,99,99,99,0,6,6,13,6,0,99},
		{99,0,13,13,13,13,6,13,13,6,0,99,99,99,99,0,6,13,14,6,0,99},
		{99,0,13,13,13,6,15,0,13,13,0,99,99,99,99,0,6,14,14,6,0,99},
		{0,13,13,13,13,4,9,0,13,6,0,99,99,99,99,99,0,14,6,0,99,99},
		{0,13,13,13,13,13,0,0,6,6,0,99,99,99,99,99,0,6,0,99,99,99},
		{99,0,6,13,13,13,6,6,6,6,6,0,99,99,99,99,0,13,0,99,99,99},
		{99,99,0,0,6,6,6,6,6,6,6,0,99,99,99,0,13,13,0,99,99,99},
		{99,99,99,99,0,0,2,6,6,8,6,6,0,99,0,6,13,0,99,99,99,99},
		{99,99,99,99,99,0,14,14,8,4,13,6,6,0,6,6,6,0,99,99,99,99},
		{99,99,99,99,99,0,14,14,8,13,6,8,6,6,8,6,0,99,99,99,99,99},
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
	int Grass[50][50]; //풀숲 배경
}BackGr;

////////////////
////함수////////
///////////////

//도트 색 변경 함수 선언
static void SetColor(int color, int back);

//도트 출력 함수 선언
void DotPrintPokemon(struct Pokemon pokemon, int clsNum, int a, int b, int i, struct BackGr BackGr, int k, int l);

//배경 출력 함수 선언
void DotPrintBG(struct BackGr BackGr, int clsNum, struct Pokemon pokemon);

//더블 배틀 출력 함수 선언
void DotDB(struct BackGr BackGr, int clsNum, struct Pokemon *pokemon);

//더블 배틀 함수 선언
int DoubleBattle(struct Pokemon* pokemon, int* hp);

//배틀 함수 선언
int Battle(struct Pokemon pokemon, int* hp);

//콘솔 화면 크기
static int SetConsoleSizeStable(short cols, short lines, short scrollLine);


////////////////메인 함수////////////////////
int main(void)
{
	SetConsoleSizeStable(100, 50, 200);
	while (1)
	{
		////////////
		///초기화///
		///////////

		////////////////포켓몬 초기화   몬스터 번호, 이름, 체력, 타입, 타입 번호, 도트
		/*struct Pokemon pokemon[3] = {
			{1,"파이리",100,"불",1,{{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,15,15,15,15},
		{15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,0,6,0,15,15,15},
		{15,15,15,0,0,13,13,6,0,15,15,15,15,15,15,15,0,6,6,0,15,15},
		{15,15,0,13,13,13,13,13,6,0,15,15,15,15,15,15,0,6,6,0,15,15},
		{15,15,0,13,13,13,13,13,13,0,15,15,15,15,15,0,6,6,13,6,0,15},
		{15,0,13,13,13,13,6,13,13,6,0,15,15,15,15,0,6,13,14,6,0,15},
		{15,0,13,13,13,6,15,0,13,13,0,15,15,15,15,0,6,14,14,6,0,15},
		{0,13,13,13,13,4,9,0,13,6,0,15,15,15,15,15,0,14,6,0,15,15},
		{0,13,13,13,13,13,0,0,6,6,0,15,15,15,15,15,0,6,0,15,15,15},
		{15,0,6,13,13,13,6,6,6,6,6,0,15,15,15,15,0,13,0,15,15,15},
		{15,15,0,0,6,6,6,6,6,6,6,0,15,15,15,0,13,13,0,15,15,15},
		{15,15,15,15,0,0,2,6,6,8,6,6,0,15,0,6,13,0,15,15,15,15},
		{15,15,15,15,15,0,14,14,8,4,13,6,6,0,6,6,6,0,15,15,15,15},
		{15,15,15,15,15,0,14,14,8,13,6,8,6,6,8,6,0,15,15,15,15,15},
		{15,15,15,15,0,4,4,14,14,8,8,6,6,6,8,0,15,15,15,15,15,15},
		{15,15,15,15,0,2,4,8,2,2,6,6,6,4,0,15,15,15,15,15,15,15},
		{15,15,15,15,15,0,0,0,0,8,4,6,4,0,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,0,15,4,15,0,15,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15}}},//여기까지 파이리
			{2,"꼬부기",100,"물",2,{{15,15,15,0,0,0,0,15,15,15,15,15,15,15,15,15,0,0,0,15,15},
		{15,15,0,3,9,9,9,0,0,15,15,15,15,15,15,0,9,9,9,0,15},
		{15,0,9,9,9,9,9,9,3,0,0,15,15,15,0,9,9,9,3,3,0},
		{15,0,9,9,9,9,9,9,9,8,2,0,0,15,0,9,9,3,8,3,0},
		{0,9,9,9,9,3,9,9,9,3,8,10,2,0,3,9,3,8,3,3,0},
		{0,9,9,9,3,15,0,9,9,3,8,2,10,2,8,3,3,8,3,0,15},
		{0,9,9,9,3,0,0,9,3,3,8,15,2,10,8,3,3,8,0,15,15},
		{15,0,9,9,9,0,10,3,3,8,15,15,2,10,2,8,3,0,15,15,15},
		{15,15,0,8,3,3,3,3,8,3,8,15,15,2,10,8,3,0,15,15,15},
		{15,15,0,3,8,8,8,10,14,8,9,8,15,2,2,8,0,15,15,15,15},
		{15,15,15,0,0,14,14,14,8,9,9,9,8,2,10,0,15,15,15,15,15},
		{15,15,15,15,15,0,10,10,8,9,9,3,8,2,10,0,15,15,15,15,15},
		{15,15,15,15,0,3,8,14,14,8,3,8,8,15,0,15,15,15,15,15,15},
		{15,15,15,15,0,3,3,0,10,10,8,8,3,8,0,15,15,15,15,15,15},
		{15,15,15,15,15,0,0,15,0,8,9,3,3,0,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,0,3,3,3,0,15,15,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15}}}, //여기까지 꼬부기
			{3,"이상해씨",100,"풀",3,{{15,15,15,15,15,15,15,15,15,15,15,15,0,15,0,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15,15,0,10,0,10,0,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15,0,0,2,10,2,0,15,15,15,15},
		{15,15,15,15,15,15,15,15,0,0,2,9,9,2,9,2,0,0,15,15},
		{15,15,15,15,15,15,15,0,2,2,9,2,9,2,9,2,2,9,0,15},
		{15,15,15,0,15,15,0,9,2,9,2,2,9,2,2,9,2,2,9,0},
		{15,15,0,10,0,0,8,9,9,9,2,9,2,2,2,2,9,2,9,0},
		{15,15,0,10,10,10,2,8,8,9,9,9,2,2,2,2,9,9,9,0},
		{15,15,0,10,10,2,9,9,2,8,9,9,9,9,9,9,9,9,9,0},
		{15,0,10,10,10,9,9,9,10,2,8,8,8,9,9,9,9,9,0,15},
		{15,0,2,10,10,10,10,10,10,10,10,10,8,9,9,9,8,0,15,15},
		{0,4,9,10,10,10,2,10,10,10,10,8,2,8,8,8,2,0,15,15},
		{0,10,10,10,10,9,10,8,0,8,10,2,2,2,2,2,9,9,0,15},
		{15,0,10,10,10,10,0,0,15,15,2,2,2,8,2,2,9,9,0,15},
		{15,0,2,10,10,10,0,4,15,2,2,2,9,9,8,2,2,2,0,15},
		{15,15,0,0,2,2,2,2,2,2,8,2,9,9,8,2,15,0,15,15},
		{15,15,15,15,0,0,0,0,0,0,2,2,2,2,8,0,0,15,15,15},
		{15,15,15,15,15,15,15,15,15,0,15,2,15,8,0,15,15,15,15,15},
		{15,15,15,15,15,15,15,15,15,15,0,0,0,0,15,15,15,15,15,15}}}  //여기까지 이상해씨
		};*/
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

			DotPrintBG(BackGr, 1, pokemon[0]);
			printf("\n\n1: %s      타입:%s \n\n\n", pokemon[0].name, pokemon[0].type);
			Sleep(1000);

			DotPrintBG(BackGr, 1, pokemon[1]);
			printf("\n\n2: %s      타입:%s \n\n\n", pokemon[1].name, pokemon[1].type);
			Sleep(1000);

			DotPrintBG(BackGr, 1, pokemon[2]);
			printf("\n\n3: %s      타입:%s \n\n\n", pokemon[2].name, pokemon[2].type);
			Sleep(1000);

			DotDB(BackGr, 1, pokemon);
			printf("\n\n4: %s      타입:%s      %s       타입:%s \n\n\n", pokemon[0].name, pokemon[0].type, pokemon[1].name, pokemon[1].type);
			Sleep(1000);

			//////////////야생 포켓몬 선택
			pokeNum = _getch();
			if (pokeNum != 49 && pokeNum != 50 && pokeNum != 51 && pokeNum != 52)
			{
				system("cls");
				continue;   /////선택지 외의 숫자 선택 시 다시 선택
			}

			if(pokeNum == 52)
				win = DoubleBattle(pokemon, &hp);
			else
				win = Battle(pokemon[pokeNum - 49], &hp); //////////////////배틀함수 호출

			//int battle(struct Pokemon pokemon, int* hp);
			//win = Battle(pokemon[pokeNum - 49], &hp); //////////////////배틀함수 호출

			///////////////////////////////승패에 따른 보상
			if (win == 0) {
				xp += 25;
				printf("경험치를 획득했습니다!\n");
				printf("%d/100\n\n", xp);
				system("pause");
				system("cls");
			}
			else if (win == 1)
			{
				printf("패배하였습니다.\n체력이 회복됩니다.\n\n");
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

/////////////////도트 출력 함수
void DotPrintPokemon(struct Pokemon pokemon, int clsNum, int a, int b, int i, struct BackGr BackGr, int k, int l)
{
	if (clsNum == 0)
		system("cls");
	
	for (; i < a; i++)
	{
		for (int j=0; j < b; j++)
		{
			if (pokemon.DotPokemon[i][j] == 99)
			{
				SetColor(BackGr.Grass[i + k][j + l], BackGr.Grass[i + k][j + l]);
			}
			else if (pokemon.DotPokemon[i][j] == 15)
			{
				SetColor(15, 15);
			}
			else if (pokemon.DotPokemon[i][j] == 0)
			{
				SetColor(0, 0);
			}
			else if (pokemon.DotPokemon[i][j] == 13)
			{
				SetColor(13, 13);
			}
			else if (pokemon.DotPokemon[i][j] == 6)
			{
				SetColor(6, 6);
			}
			else if (pokemon.DotPokemon[i][j] == 4)
			{
				SetColor(4, 4);
			}
			else if (pokemon.DotPokemon[i][j] == 14)
			{
				SetColor(14, 14);
			}
			else if (pokemon.DotPokemon[i][j] == 12)
			{
				SetColor(12, 12);
			}
			else if (pokemon.DotPokemon[i][j] == 8)
			{
				SetColor(8, 8);
			}
			else if (pokemon.DotPokemon[i][j] == 10)
			{
				SetColor(10, 10);
			}
			else if (pokemon.DotPokemon[i][j] == 9)
			{
				SetColor(9, 9);
			}
			else if (pokemon.DotPokemon[i][j] == 2)
			{
				SetColor(2, 2);
			}
			else if (pokemon.DotPokemon[i][j] == 3)
			{
				SetColor(3, 3);
			}
			printf("  ");
		}
		if (i < a-1)
			printf("\n");
	}
	SetColor(15, 0);
}

//////배경 출력 함수
void DotPrintBG(struct BackGr BackGr, int clsNum, struct Pokemon pokemon)
{
	int a = 0, b = 22;
	if (clsNum == 0)
		system("cls");

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i >= 2 && i<=20 && j == 14)
			{
				DotPrintPokemon(pokemon, 1, i - 1, b, i - 2, BackGr, i, j);
				j += 22;
			}

			if (BackGr.Grass[i][j] == 15)
			{
				SetColor(15, 15);
			}
			else if (BackGr.Grass[i][j] == 0)
			{
				SetColor(0, 0);
			}
			else if (BackGr.Grass[i][j] == 13)
			{
				SetColor(13, 13);
			}
			else if (BackGr.Grass[i][j] == 6)
			{
				SetColor(6, 6);
			}
			else if (BackGr.Grass[i][j] == 4)
			{
				SetColor(4, 4);
			}
			else if (BackGr.Grass[i][j] == 14)
			{
				SetColor(14, 14);
			}
			else if (BackGr.Grass[i][j] == 12)
			{
				SetColor(12, 12);
			}
			else if (BackGr.Grass[i][j] == 8)
			{
				SetColor(8, 8);
			}
			else if (BackGr.Grass[i][j] == 10)
			{
				SetColor(10, 10);
			}
			else if (BackGr.Grass[i][j] == 9)
			{
				SetColor(9, 9);
			}
			else if (BackGr.Grass[i][j] == 2)
			{
				SetColor(2, 2);
			}
			else if (BackGr.Grass[i][j] == 3)
			{
				SetColor(3, 3);
			}
			printf("  ");
		}
		printf("\n");
	}
	SetColor(15, 0);
}

void DotDB(struct BackGr BackGr, int clsNum, struct Pokemon *pokemon)
{
	int a = 0, b = 22;
	if (clsNum == 0)
		system("cls");

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i >= 2 && i <= 20 && j == 2)
			{
				DotPrintPokemon(pokemon[0], 1, i - 1, b, i - 2, BackGr, i, j);
				j += 22;
			}
			else if (i >= 2 && i <= 20 && j == 26)
			{
				DotPrintPokemon(pokemon[1], 1, i - 1, b, i - 2, BackGr, i, j);
				j += 22;
			}

			if (BackGr.Grass[i][j] == 15)
			{
				SetColor(15, 15);
			}
			else if (BackGr.Grass[i][j] == 0)
			{
				SetColor(0, 0);
			}
			else if (BackGr.Grass[i][j] == 13)
			{
				SetColor(13, 13);
			}
			else if (BackGr.Grass[i][j] == 6)
			{
				SetColor(6, 6);
			}
			else if (BackGr.Grass[i][j] == 4)
			{
				SetColor(4, 4);
			}
			else if (BackGr.Grass[i][j] == 14)
			{
				SetColor(14, 14);
			}
			else if (BackGr.Grass[i][j] == 12)
			{
				SetColor(12, 12);
			}
			else if (BackGr.Grass[i][j] == 8)
			{
				SetColor(8, 8);
			}
			else if (BackGr.Grass[i][j] == 10)
			{
				SetColor(10, 10);
			}
			else if (BackGr.Grass[i][j] == 9)
			{
				SetColor(9, 9);
			}
			else if (BackGr.Grass[i][j] == 2)
			{
				SetColor(2, 2);
			}
			else if (BackGr.Grass[i][j] == 3)
			{
				SetColor(3, 3);
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
	DotPrintBG(BackGr, 0, pokemon);
	printf("%s 가 승부를 걸어왔다. \n\n", pokemon.name);
	printf("%s \n", pokemon.name);
	printf("HP: %d  타입: %s \n\n", pokemon.monhp, pokemon.type);
	Sleep(1000);

	while (1)
	{
		int i = 0;
		DotPrintBG(BackGr, 0, pokemon);
		printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
		i = _getch();
		DotPrintBG(BackGr, 0, pokemon);
		if (i == 49)
		{
			printf("\n불꽃세례!!\n");
			if (pokemon.typeNum == 3)
			{
				pokemon.monhp -= 30 * 2;
			}
			else
			{
				pokemon.monhp -= 30;
			}
			printf("%s의 체력이 %d로 줄었다! \n\n", pokemon.name, pokemon.monhp);
		}
		else if (i == 50)
		{
			printf("\n물대포!!\n");
			if (pokemon.typeNum == 1)
			{
				pokemon.monhp -= 30 * 2;
			}
			else
			{
				pokemon.monhp -= 30;
			}
			printf("%s의 체력이 %d로 줄었다!\n\n", pokemon.name, pokemon.monhp);
		}
		else if (i == 51)
		{
			printf("\n덩굴채찍!!\n");
			if (pokemon.typeNum == 2)
			{
				pokemon.monhp -= 30 * 2;
			}
			else
			{
				pokemon.monhp -= 30;
			}
			printf("%s의 체력이 %d으로 줄었다!\n\n", pokemon.name, pokemon.monhp);
		}
		else if (i == 52)
		{
			printf("체력을 회복했다!\n");
			*hp += 50;
			if (*hp > 100)*hp = 100;
			printf("체력이 %d가 되었다.\n\n", *hp);
		}
		else
		{
			printf("존재하지 않는 선택지입니다. \n\n");
			continue;
		}
		system("pause");

		if (pokemon.monhp <= 0)
		{
			system("cls");
			printf("전투에서 승리했다! \n");
			return 0;
		}

		//상대 턴
		DotPrintBG(BackGr, 0, pokemon);
		printf("%s의 몸통박치기!\n", pokemon.name);
		*hp -= 30;
		printf("체력이 30 줄었다! %d/100 \n\n", *hp);
		system("pause");

		if (*hp <= 0)
		{
			system("cls");
			printf("눈 앞이 하얘졌다!\n\n");
			return 1;
		}
	}
}

////////////////////더블 배틀 함수
int DoubleBattle(struct Pokemon* pokemon, int* hp)
{
	DotDB(BackGr, 0, pokemon);
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
		if (pokemon[0].monhp > 0 && pokemon[1].monhp > 0)
		{
			DotDB(BackGr, 0, pokemon);
			printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
			Fskill = _getch();  ///////////////////////1번 스킬 선택

			if (Fskill != 49 && Fskill != 50 && Fskill != 51 && Fskill != 52) ////////// 스킬 재선택
			{
				printf("존재하지 않는 선택지 입니다. \n");
				continue;
			}

			DotDB(BackGr, 0, pokemon);
			printf("누구에게 사용할까? \n");
			printf("1. %s       2. %s\n", pokemon[0].name, pokemon[1].name);
			choice1 = _getch(); ///////////////////////////1번 스킬 대상 지정

			if (choice1 != 49 && choice1 != 50) ////////////////////////////////////// 대상 재선택
			{
				printf("존재하지 않는 선택지 입니다. \n");
				continue;
			}

			DotDB(BackGr, 0, pokemon);
			printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
			Sskill = _getch(); ////////////////////2번 스킬 선택

			if (Sskill != 49 && Sskill != 50 && Sskill != 51 && Sskill != 52) ///////// 스킬 재선택
			{
				printf("존재하지 않는 선택지 입니다. \n");
				continue;
			}

			DotDB(BackGr, 0, pokemon);
			printf("누구에게 사용할까? \n");
			printf("1. %s       2. %s\n", pokemon[0].name, pokemon[1].name);
			choice2 = _getch(); ///////////////////////////2번 스킬 대상 지정

			if (choice2 != 49 && choice2 != 50) ////////////////////////////////////// 대상 재선택
			{
				printf("존재하지 않는 선택지 입니다. \n");
				continue;
			}

			if (Fskill == 49) { ///////////////////////////////////////////////////////////////////////////////////////////////////////////1번 스킬 1번
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
			else if (Fskill == 50) { ///////////////////////////////////////////////////////////////1번 스킬 2번
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
			else if (Fskill == 51) { ////////////////////////////////////////////////////////////1번 스킬 3번
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
			else if (Fskill == 52) { //////////////////////////////////////////////////////////1번 스킬 4번
				printf("체력을 회복했다!\n");
				*hp += 50;
				if (*hp > 100)*hp = 100;
				printf("체력이 %d가 되었다.\n\n", *hp);
				Sleep(1000);
			}

			if (Sskill == 49) { /////////////////////////////////////////////////////////////////////////////////////////////////////////////////2번 스킬 1번
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
			else if (Sskill == 50) { ///////////////////////////////////////////////////////////////2번 스킬 2번
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
			else if (Sskill == 51) { ////////////////////////////////////////////////////////////2번 스킬 3번
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
			else if (Sskill == 52) { //////////////////////////////////////////////////////////2번 스킬 4번
				printf("체력을 회복했다!\n");
				*hp += 50;
				if (*hp > 100)*hp = 100;
				printf("체력이 %d가 되었다.\n\n", *hp);
				system("pause");
			}

			if (pokemon[0].monhp <= 0 && pokemon[1].monhp <= 0) ////////////// 클리어
			{
				system("cls");
				printf("전투에서 승리했다! \n");
				return 0;
			}

			if (pokemon[0].monhp <= 0)
			{
				system("cls");
				printf("%s는 쓰러졌다.\n",pokemon[0].name);
				system("pause");
			}
			else if (pokemon[1].monhp <= 0)
			{
				system("cls");
				printf("%s는 쓰러졌다.\n",pokemon[1].name);
				system("pause");
			}

			/////////////////// 상대턴
			if (pokemon[1].monhp <= 0 && pokemon[0].monhp > 0) //////////////////////////파이리만 공격턴
			{
				DotPrintBG(BackGr, 0, pokemon[0]);
				printf("%s의 몸통박치기!\n", pokemon[0].name);
				*hp -= 20;
				printf("체력이 20 줄었다! %d/100 \n\n", *hp);
				Sleep(1000);

				if (*hp <= 0)
				{
					system("cls");
					printf("눈 앞이 하얘졌다!\n\n");
					return 1;
				}
			}
			else if (pokemon[0].monhp <= 0 && pokemon[1].monhp > 0) //////////////////////// 꼬부기만 공격턴
			{
				DotPrintBG(BackGr, 0, pokemon[1]);
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
			else
			{
				DotDB(BackGr, 0, pokemon); ///// 파이리 공격턴
				printf("%s의 몸통박치기!\n", pokemon[0].name);
				*hp -= 20;
				printf("체력이 20 줄었다! %d/100 \n\n", *hp);
				Sleep(1000);

				if (*hp <= 0)
				{
					system("cls");
					printf("눈 앞이 하얘졌다!\n\n");
					return 1;
				}

				DotDB(BackGr, 0, pokemon); ///// 꼬부기 공격턴
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
		else if (pokemon[0].monhp > 0 && pokemon[1].monhp <= 0) ////////////////////////////////////////////////////// 파이리만 생존
		{
			DotPrintBG(BackGr, 0, pokemon[0]);
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

			DotPrintBG(BackGr, 0, pokemon[0]); /////////////////////////////////////////파이리 공격턴
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
		else if (pokemon[0].monhp <= 0 && pokemon[1].monhp > 0) /////////////////////////////////////////////// 꼬부기만 생존
		{
			DotPrintBG(BackGr, 0, pokemon[1]);
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

			DotPrintBG(BackGr, 0, pokemon[1]); /////꼬부기 공격턴
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