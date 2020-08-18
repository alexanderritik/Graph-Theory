/*
    Author  : <<grenade24>>
    Email   : << rakeshkusrivastav@gmail.com >>
    Date    : 2020-06-07 01:48:11
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>


using namespace std;


/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
/* typedef ends */

/* macro starts */


#define mp             make_pair
#define pb             push_back
#define eb             emplace_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (int i = x; i <= y; i ++)
#define repi(i, x, y)  for (int i = x; i >= y; i --)
#define fore(itr, x)   for (auto itr:x)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI
#define value_at_index(x) find_by_order(x)
#define index_of(x) order_of_key(x)

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
	return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
	int i, j, n;
	n = data.size();

	for (i = 0; i < (1 << n); i++) {
		for (j = 0; j < n; j++) {
			if (i & (1 << j)) {
				cout << data[j] << " ";
			}
		}
		cout << "\n";
	}
}

/* function ends */
pii start, stop;
int n, m;

char graph[1000][1000];
bool visited[1000][1000];

vector< stack<char> > allPath;

void DFS(int i , int j , stack<char>path)
{
	if (i == stop.fi && j == stop.se)
	{
		allPath.pb(path);
		return;
	}

	if (i >= n || j >= m || i < 0 || j < 0)
	{
		return;
	}

	if (graph[i][j] == '#' || (visited[i][j])) {
		return;
	}

	visited[i][j] = true;


	path.push('L') ;
	DFS(i , j - 1 , path);

	path.top() = 'R';
	DFS(i , j + 1 , path);

	path.top() = 'D';
	DFS(i + 1 , j , path);

	path.top() = 'U';
	DFS(i - 1 , j , path);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fastIO;

	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 'A')
				start = mp(i, j);
			else if (graph[i][j] == 'B')
				stop = mp(i, j);

			visited[i][j] = false;
		}
	}

	// cout << start.fi << " " << start.se << endl;
	// cout << stop.fi << " " << stop.se << endl;

	stack<char>path;
	DFS(start.fi , start.se , path );


	int len = INT_MAX;
	string ans;
	for (auto i : allPath)
	{
		string str = "";
		while (!i.empty())
		{
			str = i.top() + str;
			i.pop();
		}
		int size2 = str.size();

		if (len > size2) {
			ans = str;
			len = size2;
		}
	}

	if (len == INT_MAX)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		cout << ans.size() << endl;
		cout << ans << endl;
	}



	// // BFS

	// int row[4] = {1, -1, 0, 0};
	// int col[4] = {0, 0, 1, -1};

	// map<pair<int, int>, pair<pair<int, int>, char> > parent;

	// queue<pii>q;
	// q.push({start.fi , start.se});
	// while (!q.empty())
	// {

	// 	pii pos = q.front();
	// 	int a = pos.fi;
	// 	int b = pos.se;
	// 	q.pop();
	// 	// cout << "main" << a << " " << b << endl;

	// 	for (auto i : row) {
	// 		for (auto j : col) {
	// 			if ((a + i) < n && (b + j) < m && (a + i) >= 0 && (b + j) >= 0 && (abs(i) != abs(j))  && graph[a + i][b + j] != '#' && !(visited[a + i][b + j]))
	// 			{

	// 				char ch;
	// 				if (i == 1 && j == 0)
	// 					ch = 'D';
	// 				if (i == -1 && j == 0)
	// 					ch = 'U';
	// 				if (j == 1 && i == 0)
	// 					ch = 'R';
	// 				if (j == -1 && i == 0)
	// 					ch = 'L';

	// 				parent[ {(a + i), (b + j)}] = mp(mp(a, b), ch);
	// 				// cout << a + i << " " << b + j << " " << graph[a + i][b + j] << endl;


	// 				if (graph[a + i][b + j] == 'B') {

	// 					auto end = mp(a + i, b + j);
	// 					string res = "";
	// 					while (true) {
	// 						res += parent[end].se;
	// 						end = parent[end].fi;
	// 						// cout << end.fi << " " << end.se << " " << graph[end.fi][end.se] << endl;
	// 						if (graph[end.fi][end.se] == 'A')
	// 							break;
	// 					}
	// 					reverse(all(res));
	// 					cout << "YES\n";
	// 					cout << res.size() << endl;
	// 					cout << res << endl;
	// 					return 0;
	// 				}

	// 				visited[a + i][b + j] = 1;
	// 				q.push(make_pair(a + i, b + j));
	// 			}

	// 		}
	// 	}



	// }
	// cout << "NO" << endl;

	return 0;
}