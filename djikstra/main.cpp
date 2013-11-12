#include <iostream>
#include <climits>

using namespace std;

#define heap
#ifdef heap

#include<iostream>
#include<vector>
#include<set>
  
const int infty = 1000000000; // uwaga na limit
int n,m;
vector< pair<int,int> > adj[100000];
 
vector<int> waga;
 
struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

struct cmp
{
    // czy a jest mniejsze od b
    bool operator() (const int &a, const int &b)
    {
        if (waga[a] < waga[b]) return true;
        if (waga[a] > waga[b]) return false;
        return a<b;
    }
};
 
set<int, cmp> kopiec1; 

set<int, cmp> kopiec; // ;-)
 
void dijkstra(int s)
{
    int v, u, c;
    waga.clear(); // kasuje wektor
    waga.resize(n, infty); //
 
    waga[s] = 0;
    kopiec.clear();
    for (int i=0; i<n; i++) kopiec.insert(i);
 
    while( !kopiec.empty() )
    {
        u = *(kopiec.begin());
        kopiec.erase(kopiec.begin());
 
        for (int i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i].first;
            c = adj[u][i].second;
            if (waga[u]+c < waga[v])
            {
                // uaktualniamy wagę wierzchołka v
                kopiec.erase(kopiec.find(v));
                waga[v] = waga[u]+c;
                kopiec.insert(v);
            }
        }
    }
 
 
}
 
int main(void)
{
    int a,b,c, s,t;
 
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        cin >> a >> b >> c; // c = koszt krawędzi od a do b
        adj[a].push_back( pair<int,int>(b,c) );
    }
 
    cin >> s >> t; // s - źródło, t - wierzchołek, do którego najkrótszej odległości szukamy
 
    dijkstra(s); // alg. Dijkstry wypełni całą tablicę waga[..] najkrótszymi odległościami
    cout << waga[t];
    return 0;
}

#else
const int MAX_N = 100; // maksymalna ilość wierzchołków w grafie
const int INF = INT_MAX;

struct TNode
{
  int node;            // numer wierzchołka
  int weight;          // waga krawędzi
  struct TNode * next; // następny element listy
};

main()
{
  int i,j,u,n,m,x,y,z,v0;
  int d[MAX_N+1],p[MAX_N+1];
  bool QS[MAX_N+1];
  struct TNode *L[MAX_N+1],*pw;
  
// Inicjujemy struktury danych

  for(i = 1; i <= MAX_N; i++)
  {
    d[i]  = INF;    // koszty dojścia
    p[i]  = 0;      // poprzednik na ścieżce
    QS[i] = false; // przynależność do Q (false) lub S (true)
    L[i]  = NULL;   // lista sąsiedztwa
  }
  n = 0;

// Odczytujemy dane wejściowe

  cin >> v0; // odczytujemy numer wierzchołka startowego
  cin >> m;  // odczytujemy ilość krawędzi
  for(i = 1; i <= m; i++)
  {
    cin >> x >> y >> z; // odczytujemy krawędź
    if(x > n) n = x;
    if(y > n) n = y;
    pw = new TNode;
    pw->next = L[x]; pw->node = y; pw->weight = z; L[x] = pw;
  }
  cout << endl;

  d[v0] = 0; // koszt dojścia dla v0 jest zerowy
  
  for(i = 1; i <= n; i++)
  {

// szukamy wierzchołka w Q o najmniejszym d

    u = -1;
    for(j = 1; j <= n; j++)
      if(!QS[j] && ((u == -1) || (d[j] < d[u]))) u = j;

// znaleziony wierzchołek przenosimy do S

    QS[u] = true;

// Modyfikujemy odpowiednio wszystkich sąsiadów z Q

    pw = L[u];
    while(pw)
    {
      if(!QS[pw->node] && (d[pw->node] > d[u] + pw->weight))
      {
        d[pw->node] = d[u] + pw->weight;
        p[pw->node] = u;
      }
      pw = pw->next;
    }
  }

// Gotowe, wyświetlamy wyniki

  int stos[MAX_N],ws;
  
  for(i = 1; i <= n; i++)
  {
    cout << i << ": ";
    ws = 0; j = i;

// Wierzchołki z końca ścieżki umieszczamy na stosie

    while(j)
    {
      stos[ws++] = j; j = p[j];
    }

// Wypisujemy kolejne wierzchołki ze szczytu stosu

    while(ws) cout << stos[--ws] << " ";
    
// Wypisujemy koszt dojścia

    cout << "#" << d[i] << endl;    
  }        
  char s[1];
  cin.getline(s,1);
  cin.getline(s,1);
}

////////
#endif