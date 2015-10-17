#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <queue>

using namespace std;


typedef string lang;

struct word
{
    word(string text, int len) : text(text), len(len) {}
    string text;
    int len;
};

struct edge
{
    edge(lang conLang, word conWord) : conLang(conLang), conWord(conWord) {}
    lang conLang;
    word conWord;
};


const int INF = 200000000;


int nEdges;
lang start, end;

map<lang, vector<edge> >              adjList;
map<lang, map<lang, vector<word> > >  adjMat;

typedef pair<int, lang> il;
priority_queue<il, vector<il>, greater<il> > pq;
map<lang, int> dist;


int main()
{
    while(cin >> nEdges && nEdges != 0)
    {
        adjList.clear();
        adjMat.clear();
        while(!pq.empty())
            pq.pop();
        dist.clear();
        
        
        cin >> start >> end;
        for(int e = 0; e < nEdges; ++e)
        {
            lang nA, nB;
            string wordText;
            cin >> nA >> nB >> wordText;
            
            dist[nA] = dist[nB] = INF;
            
            word tempWord(wordText, wordText.length());
            
            adjList[nA].push_back(edge(nB, tempWord));
            adjList[nB].push_back(edge(nA, tempWord));
            
            adjMat[nA][nB].push_back(tempWord);
            adjMat[nB][nA].push_back(tempWord);
        }
        
        
        dist[start] = 0;
        pq.push(il(0, start));
        
        while(!pq.empty())
        {
            il t = pq.top();
            pq.pop();
            
            int td = t.first;
            lang tl = t.second;
            
            
        }
    }
    
    return 0;
}
