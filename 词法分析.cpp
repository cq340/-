#define   _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


using namespace std;
char prog[1000], ch, token[8];
int p = 0, syn, n, i;
char *keyword[8] = { "begin", "end", "if", "continue", "else","for","while","break"};
void scaner();
int sentenceIndex=0;

void main()
{
	int select = -1;
	p = 0;
	printf("please input sentences, end of '#' !\n");
	do
	{
		ch = getchar();
		prog[p++] = ch;
		if (ch != '\n')
		 sentenceIndex++;
	} while (ch != '#');
		p = 0;
		do
		{
			scaner();
			switch (syn)
			{
			case -1:printf("词法分析 出错\n"); break;
			default:printf("<%s,类别编码%d>\n", token, syn); break;
			}
		} while (syn != 0);
		printf("词法分析 成功\n");
		system("pause");
}
	
	

void scaner()
{
	for (n = 0; n<8; n++)
	{
		token[n] = '\0';
	}
	n = 0;
	ch = prog[p++];
	while (ch == ' '){ ch = prog[p++]; }

	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
	{
		do{
			token[n++] = ch;
			ch = prog[p++];
		} while ((ch >= 'a'&&ch <= 'z') || (ch >= 'a'&&ch <= 'z') || (ch >= '0'&&ch <= '9'));
		syn = 6;

		for (n = 0; n<5; n++)
		{
			if (strcmp(token, keyword[n]) == 0)
			{
				syn = n + 1;

			}
		}
		p--;
		//return;
	}
	else if (ch >= '0'&&ch <= '9')
	{
		p--;
		do
		{
			if (prog[p] == '+' || prog[p] == '-')
			{
				if (prog[p+1] < '0' ||prog[p+1] > '9')
				{
					break;
				}
			}
			token[n++] = prog[p++];
			ch = prog[p];
		} while (ch >= '0'&&ch <= '9'||ch=='.'||ch=='+'||ch=='-');
		syn = 7;
		return;
	}
	else
	{

		switch (ch)
		{
		case '+':syn = 15; token[0] = ch;
			ch = prog[p++];
			if (ch == '+'){ token[1] = ch; syn = 22; }
			else p--;
			break;
		case '-':syn = 16; token[0] = ch;
			ch = prog[p++];
			if (ch == '-'){ token[1] = ch; syn = 23; }
			else p--;
			break;
		case '*':syn = 17; token[0] = ch; break;
		case '/':syn = 18; token[0] = ch; break;
		case ':':syn = 19; token[0] = ch;
			ch = prog[p++];
			if (ch == '='){ token[1] = ch; syn=14; }
			else p--;
			break;
		case '<':syn = 8; token[0] = ch;
			ch = prog[p++];
			if (ch == '>'){ token[1] = ch; syn=11; }
			else if (ch == '='){ token[1] = ch; syn = 9; }
			else p--;
			break;
		case '>':syn = 12; token[0] = ch;
			ch = prog[p++];
			if (ch == '='){ token[1] = ch; syn=13; }
			else p--;
			break;
		case '=':syn = 10; token[0] = ch; break;
		case ';':syn = 26; token[0] = ch; break;
		case '(':syn = 27; token[0] = ch; break;
		case ')':syn = 28; token[0] = ch; break;
		case '#':syn = 0; token[0] = ch; break;

		default: printf("词法分析出错! 请检查是否输入非法字符\n"); syn = -1; break;

		}	
	}

}
