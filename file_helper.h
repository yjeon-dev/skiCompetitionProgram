/* DIGITAL SIGNATURE(S):
   ====================
   List the student author(s) of this code below:
   Fullname                    Seneca Email Address         Student#
   --------------------------- ---------------------------- ----------------------------
   1) Yeseul Jeon              yjeon12@myseneca.ca          148011190
   2) Dhruv Bipinbhai Patel    dbpatel31@myseneca.ca        142572197
   3) Sewon Choi               schoi23@myseneca.ca          123717209

   +--------------------------------------------------------+
   |                   FILE: file_helper.h                  |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ 
*/

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#define MAX_NAME 30
#define MAX_TIME 5

struct SkierInfo
{
    char name[MAX_NAME + 1];
    int age;
    char raceLength;
    double startTime;
    double midwayTime;
    double finishTime;
    int withdrawn;
    int rank;
    double recordTime;
};

// Clear the standard input buffer
void clearKeyboard(void);

// getInt:
int getInt(void);

// getIntInRange:
int getIntInRange(int min, int max);

// yes:
int yes(void);

// readTiem:
double readTime(FILE*);

// menu:
int menu(void);

// rankSkierInfo:
void rankSkierInfo(struct SkierInfo info[], char);

// SML:
char SML(void);

// getCategory:
char getCategory();

// selectMenu:
void selectMenu(struct SkierInfo info[]);

// getAgeGroup:
char* getAgeGroup(int);

// kmGroup:
int kmGroup(char);

// getHour:
int getHour(double);

// getMinute:
int getMinute(double);

// printInfoHeader:
void printInfoHeader(int);

// printSkierInfo:
void printSkierInfo(struct SkierInfo*, int);

// findSlkier:
struct SkierInfo* findSlkier(struct SkierInfo info[], char, int);

// findLastRank:
int findLastRank(struct SkierInfo info[], char);

// displayAllSkiers:
void displayAllSkiers(struct SkierInfo info[], char);

// displayTopThree:
void displayTopThree(struct SkierInfo info[], char);

// displayLastThree:
void displayLastThree(struct SkierInfo info[], char);

// displayWinners:
void displayWinners(struct SkierInfo info[]);

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!        DO NOT ALTER THE CONTENTS BELOW       !!!*/
/*!!!             ( function prototype )           !!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

int readFileRecord(FILE*, struct SkierInfo info[]);

#endif