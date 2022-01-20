#include <unordered_map>
#include <iostream>
#include<set>
#include<bits/stdc++.h>

#define pi pair<int,int>

using namespace std;

struct News {
    int readCount;
    int newsId;
    int heap_index;
};

struct Heap
{
	int cnt;
	News* data[50005];

	void clear()
	{
		cnt = 0;
	}

	bool compare(int a, int b)
	{
		int cmp = data[b]->readCount - data[a]->readCount;
		if (cmp == 0)
			cmp = data[b]->newsId - data[a]->newsId;
		return cmp < 0;
	}

	void swap(int a, int b)
	{
		data[a]->heap_index = b;
		data[b]->heap_index = a;
		News* r = data[a];
		data[a] = data[b];
		data[b] = r;
	}

	int updateUp(int index)
	{
		while (true) {
			if (index == 0)
				break;
			int parent = (index - 1) / 2;
			if (compare(parent, index))
				break;
			swap(parent, index);
			index = parent;
		}
		return index;
	}

	int updateDown(int index)
	{
		while (true) {
			int child1 = index * 2 + 1;
			int child2 = index * 2 + 2;
			if (child1 >= cnt)
				break;
			int child = child1;
			if (child2 < cnt)
				child = compare(child1, child2) ? child1 : child2;
			if (compare(index, child))
				break;
			swap(index, child);
			index = child;
		}
		return index;
	}

	void push(News* rest)
	{
		data[cnt] = rest;
		rest->heap_index = cnt;
		cnt++;
		updateUp(cnt - 1);
	}

	News* pop()
	{
		if (cnt == 0)
			return nullptr;
		News* ret = data[0];
		swap(0, cnt - 1);
		cnt--;
		updateDown(0);
		return ret;
	}

	News* getMax()
	{
		return data[0];
	}

	void update(News* rest)
	{
		int index = updateUp(rest->heap_index);
		updateDown(index);
	}

	void erase(News* rest)
	{
		int index = rest->heap_index;
		swap(index, cnt - 1);
		cnt--;
		index = updateUp(index);
		updateDown(index);
	}
};

unordered_map<int,int> interestedTo; //interestedTo[user] = section
int section[50005]; //section[newsId] = section
int readCount[50005];

Heap sectionWisePriority[11];
News allNews[50005];

void init()
{
    for (int i = 0; i < 50005; i++) {
		if (i < 10) sectionWisePriority[i].clear();
        if (i < 50005) readCount[i] = 0, allNews[i] = News();
    }
	interestedTo.clear();
}

void addNews(int mSection, int mNewsId)
{
    section[mNewsId] = mSection;
    News nNews = News();
    nNews.readCount = 0;
    nNews.newsId = mNewsId;
    allNews[mNewsId] = nNews;
    sectionWisePriority[mSection].push(&allNews[mNewsId]);
}

void eraseNews(int mNewsId)
{
    int s = section[mNewsId];
    sectionWisePriority[s].erase(&allNews[mNewsId]);
}

void readNews(int mUserId, int mNewsId)
{
    int s = section[mNewsId];

    //update
    readCount[mNewsId]++;
    allNews[mNewsId].readCount = readCount[mNewsId];
    sectionWisePriority[s].update(&allNews[mNewsId]);

    interestedTo[mUserId] = section[mNewsId] + 1;
}

void changeSection(int mNewsId, int mSection)
{
    int s = section[mNewsId];
    sectionWisePriority[s].erase(&allNews[mNewsId]);

    section[mNewsId] = mSection;
    sectionWisePriority[mSection].push(&allNews[mNewsId]);
}


int getList(int mUserId, int mList[])
{
    set<pi>ranking;
    for (int i = 0; i < 10; i++) { //section
        int cnt = 0;
        vector<News*>temp;
        while(sectionWisePriority[i].cnt != 0) {
            cnt++;
            News* n = sectionWisePriority[i].getMax();
            temp.push_back(n);
            sectionWisePriority[i].pop();

			set<pi>::iterator it = ranking.begin();
            if (i + 1 == interestedTo[mUserId]) {
				pi neww;
				neww = { n->readCount + 10, n->newsId };
				if (ranking.size() == 10 && neww > (*it)) ranking.insert(neww);
				else ranking.insert(neww);
            }
            else {
				pi neww;
				neww = { n->readCount, n->newsId };
				if (ranking.size() == 10 && neww > (*it)) ranking.insert(neww);
				else ranking.insert(neww);
            }
            if (cnt == 10) break;
        }

        for (int ii = 0; ii < temp.size(); ii++) {
            sectionWisePriority[i].push(temp[ii]);
        }
    }

    int cnt = 0;
    set<pi>::reverse_iterator revIt = ranking.rbegin();
    while (revIt != ranking.rend()) {
        cnt++;
        mList[cnt - 1] = (*revIt).second;
        //cout << mList[cnt - 1] << " ";
        if (cnt == 10) break;
        revIt++;
    }
    //cout<<endl;

    return cnt;
}
