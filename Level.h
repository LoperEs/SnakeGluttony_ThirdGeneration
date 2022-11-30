/*
    Developer: zhijie Duan
    ProjectName: SnakeGluttony 3.0
*/
#pragma once
#define LEVEL_ONE_MAXNUM 30
#define LEVEL_TWO_MAXNUM 10
#define LEVEL_THREE_MAXNUM 20

void InitLevel();
void UpdateEarWarnPosition();
void Level_one();
void Level_two();
void Level_Three();
void UpdateFlyObjPosition();

extern int countMath = 0;
extern int Level_Three_count = 0;
int Color[3][LEVEL_ONE_MAXNUM];

class Barrier
{
public:
    int size = 20;
    POINT coor[LEVEL_ONE_MAXNUM];
}barr;//Level_one_Barrier

class FlyingObjects
{
public:
    int size=20;
    POINT coor[LEVEL_TWO_MAXNUM];
}flyobj;

class EarlyWarning
{
public:
    int size = 200;
    bool flag = true;
    bool Key = false;
    bool FoodShow = true;
    POINT coor[LEVEL_THREE_MAXNUM];
}EarWarn;



void UpdateFlyObjPosition()
{
    srand(GetTickCount());
    for (int i = 0; i < LEVEL_TWO_MAXNUM; i++)
    {
        flyobj.coor[i].x = ((rand() % 779) / 20) * 20;
        flyobj.coor[i].y = ((rand() % 579) / 20) * 20;
    }
}

void InitLevel()
{
    srand(GetTickCount());
    //Level_One
    for (int i = 0; i < LEVEL_ONE_MAXNUM; i++)
    {
        barr.coor[i].x = ((rand() % 778) / 20) * 20;
        barr.coor[i].y = ((rand() % 578) / 20) * 20;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < LEVEL_ONE_MAXNUM; j++)
        {
            Color[i][j] = rand() % 256;
        }
    }
    //Level_Two
    for (int m = 0; m < LEVEL_TWO_MAXNUM; m++)
    {
        flyobj.coor[m].x = ((rand() % 777) / 20) * 20;
        flyobj.coor[m].y = ((rand() % 577) / 20) * 20;
    }
}

void Level_one()
{
    srand(GetTickCount());
    auto temp = 0;
    for (int i = 0; i < LEVEL_ONE_MAXNUM; i++)
    {
        setfillcolor(RGB(Color[temp][i], Color[temp + 1][i], Color[temp + 2][i]));
        setlinecolor(RGB(rand() % 256, rand() % 256, rand() % 256));
        fillrectangle(barr.coor[i].x, barr.coor[i].y, barr.coor[i].x + barr.size, barr.coor[i].y + barr.size);
    }
}

void Level_two()
{
    auto temp = 0;
    for (int i = 0; i < LEVEL_TWO_MAXNUM; i++)
    {
        setfillcolor(RGB(Color[temp][i], Color[temp + 1][i], Color[temp + 2][i]));
        setlinecolor(BLACK);
        fillrectangle(flyobj.coor[i].x, flyobj.coor[i].y, flyobj.coor[i].x + flyobj.size, flyobj.coor[i].y + flyobj.size);
        UpdateFlyObjPosition();
    }
}

void UpdateEarWarnPosition()
{
    srand(GetTickCount());
    for (int i = 0; i < LEVEL_THREE_MAXNUM; i++)
    {
        EarWarn.coor[i].x = ((rand() % 700) / 20) * 20;
        EarWarn.coor[i].y = ((rand() % 560) / 20) * 20;
    }
}

void Level_Three()
{
    EarWarn.FoodShow = false;
    srand(GetTickCount());
    auto Time = 5;
    for (int i = 0; i < LEVEL_THREE_MAXNUM; i++)
    {
        auto RColor = rand() % 256;
        auto GColor = rand() % 256;
        auto BColor = rand() % 256;
        if (RColor>=  210 && GColor <= 30 && BColor <= 30||EarWarn.Key)
        {
            EarWarn.flag = FALSE;
            EarWarn.Key = true;
            setfillcolor(RED);
            setfillcolor(RED);
            fillrectangle(EarWarn.coor[i].x, EarWarn.coor[i].y, EarWarn.coor[i].x + EarWarn.size, EarWarn.coor[i].y + EarWarn.size);
            countMath++;
            if (countMath == 1000)
            {
                EarWarn.flag = true;
                EarWarn.Key = FALSE;
                UpdateEarWarnPosition();
                countMath = 0;
                Level_Three_count++;
            }
        }
        if (Level_Three_count > 5)
        {
            EarWarn.FoodShow = true;
        }
        if (EarWarn.flag)
        {
            setfillcolor(RGB(RColor, GColor, BColor));
            fillrectangle(EarWarn.coor[i].x, EarWarn.coor[i].y, EarWarn.coor[i].x + EarWarn.size, EarWarn.coor[i].y + EarWarn.size);
        }
    }
}
