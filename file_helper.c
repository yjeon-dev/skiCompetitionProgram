/* DIGITAL SIGNATURE(S):
   ====================
   List the student author(s) of this code below:
   Fullname                    Seneca Email Address         Student#
   --------------------------- ---------------------------- ----------------------------
   1) Yeseul Jeon              yjeon12@myseneca.ca          148011190
   2) Dhruv Bipinbhai Patel    dbpatel31@myseneca.ca        142572197
   3) Sewon Choi               schoi23@myseneca.ca          123717209

   +--------------------------------------------------------+
   |                   FILE: file_helper.c                  |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "file_helper.h"

// clearKeyboard function:
void clearKeyboard(void)
{
	while (getchar() != '\n');
}

// getInt function:
int getInt(void)
{
	char result='x';
	int value;
	
	scanf("%d%c", &value, &result);
	if (result != '\n')
	{
		clearKeyboard();
	}
	while (result != '\n')
	{
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &value, &result);
		if (result != '\n')
		{
			clearKeyboard();
		}
	}
	return value;
}

// getIntInRange function:
int getIntInRange(int min, int max)
{
	int intInRange;
	do {
		intInRange = getInt();
		if (intInRange > max || intInRange < min) {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (intInRange > max || intInRange < min);

	return intInRange;
}

// yes function:
int yes(void)
{
	char ch = '!', nl = '!';
	int rvalue = 0;
	while (nl != '\n' || (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N'))
	{
		scanf("%c%c", &ch, &nl);
		printf("\n");
		if (nl != '\n')
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
		else if (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else if ((nl == '\n' && ch == 'y') || ch == 'Y')
		{
			rvalue = 1;
		}
	}
	return rvalue;
}

// readTime function:
double readTime(FILE* fp)
{
	int hour, min;

	fscanf(fp, "%d%*c", &hour);
	fscanf(fp, "%d", &min);

	return hour + (min / 60.0);
}

// readFileRecord function:
int readFileRecord(FILE* fp, struct SkierInfo info[])
{
	int  ch;
	int i;
	for (i = 0; !feof(fp); i++)
	{
		fscanf(fp, "%[^,]%*c", info[i].name);
		fscanf(fp, "%d", &info[i].age);
		fscanf(fp, " %c", &info[i].raceLength);
		info[i].startTime = readTime(fp);
		info[i].midwayTime = readTime(fp);
		info[i].finishTime = readTime(fp);
		ch = fgetc(fp);
		info[i].withdrawn = 0;

		if (ch == ' ')
		{
			ch = fgetc(fp);
			info[i].withdrawn = ch == 'W';
			ch = fgetc(fp);
		}

		while (!feof(fp) && ch != '\n')
		{
			ch = fgetc(fp);
		}

		if (info[i].withdrawn == 0)
		{
			info[i].recordTime = info[i].finishTime - info[i].startTime;
		}
		else
		{
			info[i].recordTime = 0.0;
		}
	}
	return 1;
}

// menu function:
int menu(void)
{
	printf("What would you like to do?\n\n");
	printf("1 - Print top 3 skiers in a category\n");
	printf("2 - Print all skiers in a category\n");
	printf("3 - Print last 3 skiers in a category\n");
	printf("4 - Print winners in all categories\n");
	printf("0 - Exit\n");
	printf("\nSelect an option (0-4):> ");
	return getIntInRange(0, 4);
}

// rankSkierInfo function:
void rankSkierInfo(struct SkierInfo info[], char category)
{
	int i, j, count = 0;
	int rank = 0;
	for (i = 0; info[i].name[0] != 0; i++)
	{
		if (category == info[i].raceLength)
		{
			info[i].rank = 1;
			if (info[i].withdrawn == 0)
			{
				for (j = 0; info[j].name[0] != 0; j++)
				{
					if (i != j &&
						category == info[j].raceLength &&
						info[j].withdrawn == 0 &&
						info[i].recordTime >= info[j].recordTime
						)
					{
						if (info[i].recordTime == info[j].recordTime)
						{
							if (i > j) 
								info[i].rank++;
						}
						else
							info[i].rank++;
					}
				}
			}
			else
			{
				info[i].rank = 0;
			}
		}
	}
}

// SML function:
char SML(void) 
{
	char ch = '!', nl = '!';
	int rvalue = 0;

	while (nl != '\n' || (ch != 'S' && ch != 'M' && ch != 'L' && ch != 's' && ch != 'm' && ch != 'l'))
	{
		scanf("%c%c", &ch, &nl);
		if (nl != '\n')
		{
			printf("*** INVALID ENTRY *** <Only S or M or L are acceptable>: ");
			clearKeyboard();
		}
		else if (ch != 'S' && ch != 'M' && ch != 'L' && ch != 's' && ch != 'm' && ch != 'l')
		{
			printf("*** INVALID ENTRY *** <Only S or M or L are acceptable>: ");
		}
		else
		{
			rvalue = ch;
		}
	}
	return rvalue;
}

// getCategory function:
char getCategory()
{
	char value;
	printf("Which category? (S, M, L):> ");
	value = SML();
	printf("\n");
	return toupper(value);
}

// selectMenu function:
void selectMenu(struct SkierInfo info[])
{
	int keepGoing = 1;
	char category;

	printf("***** X-Country Ski Race Reporting *****\n\n");
	do
	{
		switch (menu())
		{
		case 0:
			printf("\nDo you want to exit? (Y or N) :> ");
			if (yes())
			{
				printf("Keep on Skiing!!!\n");
				keepGoing = 0;
			}
			break;
		case 1:
			printf("\n");
			category = getCategory();
			displayTopThree(info, category);
			printf("\n");
			break;
		case 2:
			printf("\n");
			category = getCategory();
			displayAllSkiers(info, category);
			printf("\n");
			break;
		case 3:
			printf("\n");
			category = getCategory();
			displayLastThree(info, category);
			printf("\n"); 
			break;
		case 4:
			printf("\n");
			displayWinners(info);
			printf("\n");
			break;
		}
	} while (keepGoing);
}

// getAgeGroup function:
char* getAgeGroup(int age)
{
	static char agegroup[40];

	if (age < 21)
		strcpy(agegroup, "Junior");
	else if (age < 35)
		strcpy(agegroup, " Adult");
	else
		strcpy(agegroup, "Senior");
	return agegroup;
}

// kmGroup function:
int kmGroup(char raceLenght)
{
	int kmgroup;

	if (raceLenght == 'S')
		kmgroup = 10;
	else if (raceLenght == 'M')
		kmgroup = 25;
	else
		kmgroup = 50;
	return kmgroup;
}

// getHour function:
int getHour(double rtime)
{
	return (int)rtime;
}

// getMinute function:
int getMinute(double rtime)
{
	return (int)(((rtime - (int)rtime)) * 60.0 + 0.5);
}

// printInfoHeader function:
void printInfoHeader(int option)
{
	switch (option)
	{
	case 1:case 3:
		printf("Skier                    Age Group Time\n");
		printf("---------------------------------------\n");
		break;
	case 2:
		printf("Skier		         Age Group Time Withdrew\n");
		printf("------------------------------------------------\n");
		break;
	case 4:
		printf("Skier                    Age Group Category Time\n");
		printf("------------------------------------------------\n");
		break;
	}
}

// printSkierInfo function:
void printSkierInfo(struct SkierInfo* pinfo, int option)
{
	if (pinfo != NULL)
	{
		switch (option)
		{
		case 1:
			if (pinfo->withdrawn == 0)
				printf("%-28s%s% 02d:%02d\n", pinfo->name, getAgeGroup(pinfo->age), getHour(pinfo->recordTime), getMinute(pinfo->recordTime));
			else
				printf("%-28s%s Withdrawn\n", pinfo->name, getAgeGroup(pinfo->age));
			break;
		case 2:
			if (pinfo->withdrawn == 0)
				printf("%-28s%s% 02d:%02d       No\n", pinfo->name, getAgeGroup(pinfo->age), getHour(pinfo->recordTime), getMinute(pinfo->recordTime));
			else
				printf("%-28s%s  N/A      Yes\n", pinfo->name, getAgeGroup(pinfo->age));
			break;
		case 3:
			if (pinfo->withdrawn == 0)
				printf("%-28s%s% 02d:%02d\n", pinfo->name, getAgeGroup(pinfo->age), getHour(pinfo->recordTime), getMinute(pinfo->recordTime));
			else
				printf("%-28s%s Withdrawn\n", pinfo->name, getAgeGroup(pinfo->age));
			break;
		case 4:
			if (pinfo->withdrawn == 0)
				printf("%-28s%s%6d km% 02d:%02d\n", pinfo->name, getAgeGroup(pinfo->age), kmGroup(pinfo->raceLength), getHour(pinfo->recordTime), getMinute(pinfo->recordTime));
			else
				printf("%-28s%s     Withdrawn\n", pinfo->name, getAgeGroup(pinfo->age));
			break;
		}
	}
	else
	{
		printf("Not Awarded\n");
	}
}

// findSlkier function:
struct SkierInfo* findSlkier(struct SkierInfo info[], char category, int rank)
{
	int i;
	struct SkierInfo* pSkier = NULL;
	for (i = 0; info[i].name[0] != '\0'; i++)
	{
		if (category == info[i].raceLength && info[i].rank == rank && info[i].withdrawn == 0)
			pSkier = &info[i];
	}
	return pSkier;
}

// findLastRank function:
int findLastRank(struct SkierInfo info[], char category)
{
	int i;
	int rank = 0;
	for (i = 0; info[i].name[0] != '\0'; i++)
	{
		if (category == info[i].raceLength)
			if (rank < info[i].rank)
				rank = info[i].rank;
	}

	return rank;
}

// displayAllSkiers function:
void displayAllSkiers(struct SkierInfo info[], char category)
{
	int i;
	int rank;
	int lastrank = findLastRank(info, category);
	printInfoHeader(2);

	for (rank = 1; rank <= lastrank; rank++)
		printSkierInfo(findSlkier(info, category, rank), 2);
	for (i = 0; info[i].name[0] != '\0'; i++)
	{
		if (info[i].rank == 0 && category == info[i].raceLength)
			printSkierInfo(&info[i], 2);
	}
}

// displayTopThree function:
void displayTopThree(struct SkierInfo info[], char category)
{
	int rank;
	printInfoHeader(1);
	for (rank = 1; rank <= 3; rank++)
		printSkierInfo(findSlkier(info, category, rank), 1);
}

// displayLastThree function:
void displayLastThree(struct SkierInfo info[], char category)
{
	int rank;
	int lastrank = findLastRank(info, category);

	printInfoHeader(3);
	for (rank = lastrank; rank > lastrank - 3; rank--)
	{
		printSkierInfo(findSlkier(info, category, rank), 3);
	}
}

// displayWinners function:
void displayWinners(struct SkierInfo info[])
{
	printInfoHeader(4);
	printSkierInfo(findSlkier(info, 'S', 1), 4);
	printSkierInfo(findSlkier(info, 'M', 1), 4);
	printSkierInfo(findSlkier(info, 'L', 1), 4);
}