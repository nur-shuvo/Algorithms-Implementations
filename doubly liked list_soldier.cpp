#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6

extern void init();
extern void hire(int mID, int mTeam, int mScore);
extern void fire(int mID);
extern void updateSoldier(int mID, int mScore);
extern void updateTeam(int mTeam, int mChangeScore);
extern int bestSoldier(int mTeam);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_SOLDIER:
            scanf("%d %d", &mID, &mScore);
            updateSoldier(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_SOLDIER:
            scanf("%d", &mTeam);
            userAns = bestSoldier(mTeam);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}


const int MIN_ID = 1;
const int MAX_ID = 100000;
const int MIN_TEAM = 1;
const int MAX_TEAM = 5;
const int MIN_SCORE = 1;
const int MAX_SCORE = 5;

struct Node
{
    int id;
    int team;
    Node *prev;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;

    //member method
    static void link(Node *front, Node *back)
    {
        front->next = back;
        back->prev = front;
    }

    //member method
    static void erase(Node *node)
    {
        link(node->prev, node->next);
    }

    //Link garbage head and tail for empty list.
    void initialize()
    {
        head = new Node();
        tail = new Node();
        link(head, tail);
    }

    void insert(Node *node)
    {
        link(tail->prev, node);
        link(node, tail);
    }

    bool isEmpty()
    {
        return (head->next == tail);
    }

    //Add a list to the current list.
    void splice(List *list)
    {
        if (list->isEmpty())
            return;
        link(tail->prev, list->head->next);
        link(list->tail->prev, tail);
        list->initialize();
    }
};

Node soldier[MAX_ID + 1];
List soldierGroup[MAX_TEAM + 1][MAX_SCORE + 1];

void init()
{
    for (int i = MIN_TEAM; i <= MAX_TEAM; i++)
        for (int j = MIN_SCORE; j <= MAX_SCORE; j++)
            soldierGroup[i][j].initialize();
}

void hire(int mID, int mTeam, int mScore)
{
    soldier[mID].id = mID;
    soldier[mID].team = mTeam;
    soldierGroup[mTeam][mScore].insert(&soldier[mID]);
}

void fire(int mID)
{
    List::erase(&soldier[mID]);
}

void updateSoldier(int mID, int mScore)
{
    List::erase(&soldier[mID]);
    soldierGroup[soldier[mID].team][mScore].insert(&soldier[mID]);
}

void updateTeam(int mTeam, int mChangeScore)
{
    if (mChangeScore > 0)
    {
        for (int i = MAX_SCORE; i >= MIN_SCORE; i--)
        {
            int newScore = i + mChangeScore;
            if (newScore > MAX_SCORE)
                newScore = MAX_SCORE;
            if(newScore != i) soldierGroup[mTeam][newScore].splice(&soldierGroup[mTeam][i]);
        }
    }
    else if (mChangeScore < 0)
    {
        for (int i = MIN_SCORE; i <= MAX_SCORE; i++)
        {
            int newScore = i + mChangeScore;
            if (newScore < MIN_SCORE)
                newScore = MIN_SCORE;
            if(newScore != i) soldierGroup[mTeam][newScore].splice(&soldierGroup[mTeam][i]);
        }
    }
}

int bestSoldier(int mTeam)
{
    List maxScoreGroup;
    for (int i = MAX_SCORE; i >= MIN_SCORE; i--)
    {
        if (!soldierGroup[mTeam][i].isEmpty())
        {
            maxScoreGroup = soldierGroup[mTeam][i];
            break;
        }
    }

    int maxId = MIN_ID - 1;
    Node *maxScoreSoldier = maxScoreGroup.head->next;
    while (maxScoreSoldier != (maxScoreGroup.tail))
    {
        if (maxId < maxScoreSoldier->id)
            maxId = maxScoreSoldier->id;
        maxScoreSoldier = maxScoreSoldier->next;
    }
    return maxId;
}
