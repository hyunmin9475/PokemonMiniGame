#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

static void SetColor(int color, int back)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (back << 4));
}

//파이리!
void Charmander(void)
{
	int Charmander[22][22] = {
		{15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,15,15,15,15},
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
		{15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15,15}
    };

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (Charmander[i][j] == 15)
			{
				SetColor(15, 15);
			}
			else if (Charmander[i][j] == 0)
			{
				SetColor(0, 0);
			}
			else if (Charmander[i][j] == 13)
			{
				SetColor(13, 13);
			}
			else if (Charmander[i][j] == 6)
			{
				SetColor(6, 6);
			}
			else if (Charmander[i][j] == 4)
			{
				SetColor(4, 4);
			}
			else if (Charmander[i][j] == 14)
			{
				SetColor(14, 14);
			}
			else if (Charmander[i][j] == 12)
			{
				SetColor(12, 12);
			}
			else if (Charmander[i][j] == 8)
			{
				SetColor(8, 8);
			}
			else if (Charmander[i][j] == 10)
			{
				SetColor(10, 10);
			}
			else if (Charmander[i][j] == 9)
			{
				SetColor(9, 9);
			}
			else if (Charmander[i][j] == 2)
			{
				SetColor(2, 2);
			}
			printf("  ");
		}
		printf("\n");
	}
	SetColor(15, 0);
}

//꼬부기
void Squirtle(void)
{
	int Squirtle[22][22] = {
		{15,15,15,0,0,0,0,15,15,15,15,15,15,15,15,15,0,0,0,15,15},
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
		{15,15,15,15,15,15,15,15,15,15,0,0,0,15,15,15,15,15,15,15,15}
	};

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (Squirtle[i][j] == 3)
			{
				SetColor(9, 9);
			}
			else if (Squirtle[i][j] == 9)
			{
				SetColor(3, 3);
			}
			else if (Squirtle[i][j] == 15)
			{
				SetColor(15,15);
			}
			else if (Squirtle[i][j] == 0)
			{
				SetColor(0,0);
			}
			else if (Squirtle[i][j] == 8)
			{
				SetColor(8,8);
			}
			else if (Squirtle[i][j] == 14)
			{
				SetColor(14,14);
			}
			else if (Squirtle[i][j] == 10)
			{
				SetColor(10,10);
			}
			else if (Squirtle[i][j] == 2)
			{
				SetColor(2,2);
			}
			printf("  ");
		}
		printf("\n");
	}
	SetColor(15, 0);
}

//이상해씨
void Bulbasaur(void)
{
	int Bulbasaur[22][22] = {
		{15,15,15,15,15,15,15,15,15,15,15,15,0,15,0,15,15,15,15,15},
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
		{15,15,15,15,15,15,15,15,15,15,0,0,0,0,15,15,15,15,15,15}
	};

	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			if (Bulbasaur[i][j] == 2)
			{
				SetColor(2, 2);
			}
			else if (Bulbasaur[i][j] == 10)
			{
				SetColor(10, 10);
			}
			else if (Bulbasaur[i][j] == 9)
			{
				SetColor(80,80);
			}
			else if (Bulbasaur[i][j] == 0)
			{
				SetColor(0,0);
			}
			else if (Bulbasaur[i][j] == 15)
			{
				SetColor(15,15);
			}
			else if (Bulbasaur[i][j] == 8)
			{
				SetColor(8,8);
			}
			else if (Bulbasaur[i][j] == 4)
			{
				SetColor(4,4);
			}
			printf("  ");
		}
		printf("\n");
	}
	SetColor(15, 0);
}
//구조체에 더 많은 정보
struct Pokemon {
	int monster;
	char* name;
	int monhp;
	char* type;
	int typeNum;
};

int Battle(struct Pokemon*pokemon, int* hp)
{
	int skill = 0;
	if (pokemon->monster == 1)
	{
		Charmander();
	}
	else if (pokemon->monster == 2)
	{
		Squirtle();
	}
	else if (pokemon->monster == 3)
	{
		Bulbasaur();
	}
	printf("%s 가 승부를 걸어왔다. \n\n", pokemon->name);
	printf("%s \n", pokemon->name);
	printf("HP: %d  타입: %s \n\n", pokemon->monhp, pokemon->type);

	while (1)
	{
		int i = 0;
		printf("1: 불꽃세례  2: 물대포  3: 덩굴채찍 4: 상처약\n");
		scanf_s("%d", &i);
		if (i == 1)
		{
			printf("\n불꽃세례!!\n");
			if (pokemon->typeNum == 3)
			{
				pokemon->monhp -= 30 * 2;
			}
			else
			{
				pokemon->monhp -= 30;
			}
			printf("%s의 체력이 %d로 줄었다! \n\n", pokemon->name, pokemon->monhp);
		}
		else if (i == 2)
		{
			printf("\n물대포!!\n");
			if (pokemon->typeNum == 1)
			{
				pokemon->monhp -= 30 * 2;
			}
			else
			{
				pokemon->monhp -= 30;
			}
			printf("%s의 체력이 %d로 줄었다!\n\n", pokemon->name, pokemon->monhp);
		}
		else if (i == 3)
		{
			printf("\n덩굴채찍!!\n");
			if (pokemon->typeNum == 2)
			{
				pokemon->monhp -= 30 * 2;
			}
			else
			{
				pokemon->monhp -= 30;
			}
			printf("%s의 체력이 %d으로 줄었다!\n\n", pokemon->name, pokemon->monhp);
		}
		else if (i == 4)
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

		if (pokemon->monhp <= 0)
		{
			printf("전투에서 승리했다! \n");
			return 0;
		}

		//상대 턴
		printf("%s의 몸통박치기!\n", pokemon->name);
		*hp -= 30;
		printf("체력이 30 줄었다! %d/100 \n\n", *hp);

		if (*hp <= 0)
		{
			printf("눈 앞이 하얘졌다!\n\n");
			return 1;
		}
	}
}

int main(void)
{
	while (1)
	{
		//플레이어 정보
		int hp = 100;
		int xp = 0;
		int i = 0;
		int win = 0, quit = 0;

		while (1)
		{
			//포켓몬 정보
			struct Pokemon pokemon[3] = {
				{1,"파이리",100,"불",1},
				{2,"꼬부기",100,"물",2},
				{3,"이상해씨",100,"풀",3}
			};

			printf("세 포켓몬 중 누구와 싸울텐가?\n\n");
			Charmander();
			printf("\n\n\n1: %s      타입:%s \n\n", pokemon[0].name, pokemon[0].type);
			Squirtle();
			printf("\n\n\n2: %s      타입:%s \n\n", pokemon[1].name, pokemon[1].type);
			Bulbasaur();
			printf("\n\n\n3: %s      타입:%s \n\n", pokemon[2].name, pokemon[2].type);

			scanf_s("%d", &i);
			if (i != 1 && i != 2 && i != 3)
				continue;
			//int battle(int monster, int* name, int monhp, int type, int* hp)
			win = Battle(&pokemon[i-1], &hp);
			//승패에 따른 보상
			if (win == 0) {
				xp += 25;
				printf("경험치를 획득했습니다!\n");
				printf("%d/100\n\n", xp);
			}
			else if (win == 1)
			{
				printf("패배하였습니다.\n체력이 회복됩니다.\n\n");
				hp = 100;
				continue;
			}

			if (xp >= 100)
			{
				break;
			}
		}
		printf("다시 플레이 하시겠습니까?\n");
		printf("YES: 1    NO:Other Number \n\n");
		scanf_s("%d", &quit);

		if (quit != 1)
		{
			printf("이용해주셔서 감사합니다.\n");
			break;
		}
	}
	
	return 0;
}