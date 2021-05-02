/* DIGITAL SIGNATURE(S):
   ====================
   List the student author(s) of this code below:
   Fullname                    Seneca Email Address         Student#
   --------------------------- ---------------------------- ----------------------------
   1) Yeseul Jeon              yjeon12@myseneca.ca          148011190
   2) Dhruv Bipinbhai Patel    dbpatel31@myseneca.ca        142572197
   3) Sewon Choi               schoi23@myseneca.ca          123717209

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
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
#include "file_helper.h"

#define MAX_NUM 2000

struct SkierInfo sinfo[MAX_NUM] = { {0} };

int main(void)
{
	FILE* fp;
	fp = fopen("data.txt", "r");

	if (fp == NULL)
	{
		printf("The file does not exist\n");
	}
	else
	{
		readFileRecord(fp, sinfo);
		fclose(fp);
	}

	rankSkierInfo(sinfo, 'S');
	rankSkierInfo(sinfo, 'M');
	rankSkierInfo(sinfo, 'L');
	selectMenu(sinfo);

	return 0;
}