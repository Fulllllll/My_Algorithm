//#include<bits/stdc++.h>
//using namespace std;
// 
// 
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    最优三角剖分	
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//struct Point {
//    int x, y;
//};
//void MinWeightTriangulation(int n, float t[20][20], int s[20][20]);
//float Weight(int a, int b, int c);
//int N;
//Point p[20];
//
//int main()
//{
//    cin >> N;
//    for (int i = 0; i < N; i++)
//    { 
//    	cin >> p[i].x >> p[i].y;
//    }
//
//    //N = 4;
//    //p[0].x = 0; p[0].y = 0;
//    //p[1].x = 2; p[1].y = 0;
//    //p[2].x = 2; p[2].y = 1;
//    //p[3].x = 0; p[3].y = 2;
//
//    int s[20][20];
//    float t[20][20];
//    MinWeightTriangulation(N-1, t, s);
//
//    cout << t[1][N - 1];
//    return 0;
//}
//
//void Print(float t[20][20], int n)
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            cout << t[i][j] << "    ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//    cout << endl;
//
//}
////void MinWeightTriangulation(int n, float t[20][20], int s[20][20])
////{
////    for (int i = 1; i <= n; i++)
////    {
////        t[i][i] = 0;
////    }
////    for (int i = 1; i <= n; i++)
////    {
////        for (int j = 1; j <= n; j++)
////        {
////            t[i][j] = 0;
////        }
////
////    }
////    Print(t, n);
////    for (int delta = 1; delta <= n - 1; delta++)
////    {
////        for (int i = 1; i <= n - delta; i++)
////        {
////            int j = i + delta;
////            t[i][j] = t[i][j - delta] + t[i + 1][j] + Weight(i-1, j - delta, j);
////            s[i][j] = 0;//
////            for (int k = 1; k < delta; k++)
////            {
////                float now = t[i][j - delta + k] + t[i + 1 + k][j] + Weight(i-1, j - delta, j);
////                if (now < t[i][j])
////                {
////                    t[i][j] = now;
////                    s[i][j] = 0;
////                }
////                Print(t, n);
////
////            }
////        }
////
////    }
////}
//
// 
// 
//void MinWeightTriangulation(int n, float t[20][20], int s[20][20])
//{
//    for (int i = 1; i <= n; i++)
//    {
//        t[i][i] = 0;
//    }
//    for (int delta = 1; delta <= n - 1; delta++)
//    {
//        for (int i = 1; i <= n - delta; i++)
//        {
//            int j = i + delta;
//            t[i][j] = t[i][j - delta] + t[i + 1][j] + Weight(i - 1, j - delta, j);
//            s[i][j] = 0;///
//            for (int k = 1; k < delta; k++)
//            {
//                float now = t[i][j - delta + k] + t[i + 1 + k][j] + Weight(i - 1, j - delta + k, j);
//                if (now < t[i][j])
//                {
//                    t[i][j] = now;
//                    s[i][j] = 0;///
//                }
//            }
//        }
//    }
//}
//
//float distance1(Point u, Point v) {
//    float dX = u.x - v.x;
//    float dY = u.y - v.y;
//    return sqrt(dX * dX + dY * dY);
//}
//float Weight(int a, int b, int c)
//{
//    float ret = 0;
//    if (b - a > 1) ret += distance1(p[a], p[b]);
//    if (c - b > 1) ret += distance1(p[c], p[b]);
//    return ret;
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          图像压缩
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int length(int i)
//{
//	int k = 1;
//	i /= 2;
//	while (i > 0)
//	{
//		k++;
//		i /= 2;
//	}
//	return k;
//}
//
//void Compress(int n, int p[], int s[], int l[], int b[], int bb[])
//{
//	int Lmax = 256, header = 11;
//	s[0] = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		b[i] = length(p[i]);
//		int bmax = b[i];
//		s[i] = s[i - 1] + bmax;
//		l[i] = 1;
//		for (int k = 2; k <= i && k <= Lmax; k++)
//		{
//			if (bmax < b[i - k + 1])
//			{
//				bmax = b[i - k + 1];
//				bb[i] = bmax;
//			}
//			if (s[i] > s[i - k] + k * bmax)
//			{
//				s[i] = s[i - k] + k * bmax;
//				l[i] = k;
//			}
//		}
//		s[i] = s[i] + header;
//	}
//}


//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//int n;
//int dp[107][107];
//int a[107];
//const int MAX = 0x3f3f3f3f;
//
//int findMin(int l, int r)
//{
//	if (dp[l][r])
//		return dp[l][r];
//	if (l == r)
//		return 0;
//	int _min = MAX;
//	int s = 0;
//	for (int i = l; i <= r; i++)
//		s += a[i];//区间总和，最后一下合并 
//	for (int i = l; i < r; i++)
//		_min = min(_min, findMin(l, i) + findMin(i + 1, r) + s);
//	dp[l][r] = _min;
//	return dp[l][r];
//}
//
//int findMax(int l, int r)
//{
//	if (dp[l][r])
//		return dp[l][r];
//	if (l == r)
//		return 0;
//	int _max = -1;
//	int s = 0;
//	for (int i = l; i <= r; i++)
//		s += a[i];//区间总和，最后一下合并 
//	for (int i = l; i < r; i++)
//		_max = max(_max, findMax(l, i) + findMax(i + 1, r) + s);
//	dp[l][r] = _max;
//	return dp[l][r];
//}
//int main()
//{
//	while (scanf("%d", &n) != EOF)
//	{
//		memset(dp, 0, sizeof(dp));
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		cout << findMin(1, n) << " ";
//		memset(dp, 0, sizeof(dp));
//		cout << findMax(1, n) << endl;
//	}
//}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          活动安排
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include<bits/stdc++.h>
//using namespace std;
//
//int N;
//typedef struct Event {
//	int s;
//	int f;
//}Event;
//Event event[20];
//
//int Compare_Event(const void* p1, const void* p2)
//{
//	return ((Event*)p1)->f > ((Event*)p2)->f;
//}
//int main()
//{
//	cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> event[i].s >> event[i].f;
//	}
//	qsort(event + 1, N, sizeof(Event), Compare_Event);
//
//	int ans = 1;
//	int now = event[1].f;
//	for (int i = 2; i <= N; i++)
//	{
//		if (event[i].s >= now)
//		{
//			now = event[i].f;
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//          背包问题
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include<bits/stdc++.h>
//#include<queue>
//using namespace std;
//
//int N;
//typedef struct Stuff {
//	double w;
//	double v;
//	bool operator<(const Stuff& b) const {
//		return b.v / b.w > this->v / this->w;
//	}
//}Stuff;
//int C;
//
//priority_queue<Stuff> stuff;
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		Stuff temp;
//		cin >> temp.w >> temp.v;
//		stuff.push(temp);
//	}
//	cout << stuff.top().v / stuff.top().w;
// 未完，太麻烦
//	return 0;
//}

//#include<bits/stdc++.h>
//#include<queue>
//using namespace std;
//
//int N;
//typedef struct Stuff {
//	double w;
//	double v;
//}Stuff;
//Stuff stuff[20];
//double C, V;
//
//int Compare_Stuff(const void* p1, const void* p2)
//{
//	return (((Stuff*)p1)->v / ((Stuff*)p1)->w) < (((Stuff*)p2)->v / ((Stuff*)p2)->w);
//}
//int main()
//{
//	cin >> N >> C;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> stuff[i].w >> stuff[i].v;
//	}
//	qsort(stuff, N, sizeof(Stuff), Compare_Stuff);
//	for (int i = 0; i < N; i++)
//	{
//		if (C > stuff[i].w)
//		{
//			V += stuff[i].v;
//			C -= stuff[i].w;
//		}
//		else if (C < stuff[i].w)
//		{
//			V += C * (stuff[i].v / stuff[i].w);
//			C = 0;
//			break;
//		}
//	}
//	cout << V << endl;
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         单源最短路径
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
5 7
1 2 10
1 4 30
1 5 100
2 3 50
3 5 10
4 3 20
4 5 60
*/
//#include<bits/stdc++.h>
//using namespace std;
//
//const int N = 10; 
//const int MAX = 0x3fffffff;
//
//int c[N][N];
//int dist[N], prev[N];
//
//int n, m;
//
//
//void Dijkstra(int n, int v);
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= n; j++)
//		{
//			c[i][j] = MAX;
//		}
//	}
//	for (int i = 1; i <= n; i++)
//	{
//		dist[i] = MAX;
//	}
//	int u, v, w;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> u >> v >> w;
//		c[u][v] = w;
//	}
//	Dijkstra(n, 1);
//	
//	cout << endl;
//	for (int i = 2; i <= n; i++)
//	{
//		cout << dist[i] << " ";
//	}
//	return 0;
//}
//
//void Dijkstra(int n, int v)
//{
//	set<int> waiting;
//	for (int i = 1; i <= n; i++)
//	 {
//		waiting.insert(i);
//	}
//	dist[v] = 0;   //自己到自己距离为 0
//	int now = v;
//	waiting.erase(v);
//
//
//	int count = n;
//	while (count--)
//	{
//		for (auto i : waiting)
//		{
//			dist[i] = min(dist[i], dist[now]  + c[now][i]);
//		}
//
//		int min = MAX;
//		int new_now = now;
//		for (auto i : waiting)
//		{
//			if (dist[i] < min)
//			{
//				min = dist[i];
//				new_now = i; 
//			}
//		}
//		now = new_now;
//		waiting.erase(new_now);
//	}
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         最小生成树
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 10; 
const int MAX = 0x3fffffff;

int c[N][N];	//输入图
int n, m;

bool ans[N][N];		//最小生成树
int anscost;		//最小生成树权值和

/********************************************************************/
set<int> waiting;
set<int> now;	
void PrimMST();   /*int n, c[][], ans[][], int anscost*/
/********************************************************************/
struct Edge {
	int u;
	int v;
	int val;
}edge[N * N];
int area[N];
void Kruskal();		/*int n, c[][], ans[][], int anscost*/ 
/********************************************************************/

void PrintMST();

int main()
{

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			c[i][j] = MAX;
		}
	}
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		c[u][v] = w;
		c[v][u] = w;
	}

	cout << endl << "Prim算法" << endl;
	PrimMST();
	
	//cout << endl << "Kruskal算法" << endl;
	//Kruskal();
	

	//输出答案
	PrintMST();
	cout << endl << "最小权值" << anscost << endl;
	return 0;
}

void PrimMST()		/*int n, c[][], ans[][], int anscost*/
{
	for (int i = 2; i <= n; i++)
	{
		waiting.insert(i);
	}
	now.insert(1);

	int count = n - 1;
	while (count--)				//MST有n-1条边
	{
		int newnode = 0;
		int min = MAX;
		int begin = 0, end = 0;
		for (auto i : now)
		{
			for (auto j : waiting)
			{
				if (c[i][j] < min)
				{
					min = c[i][j];
					begin = i;
					end = j;
					newnode = j;
				}
			}
		}
		ans[begin][end] = true;
		ans[end][begin] = true;
		anscost += c[begin][end];

		waiting.erase(newnode);
		now.insert(newnode);
	}
}

bool cmp(Edge a, Edge b)
{
	return a.val < b.val;
}
void Kruskal()
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (c[i][j] == MAX) continue;
			else
			{
				edge[++count] = { i, j, c[i][j] };
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		area[i] = i;
	}
	sort(edge + 1, edge + m + 1, cmp);

	for (int i = 1; i <= m; i++)
	{
		if (area[edge[i].u] != area[edge[i].v])
		{
			ans[edge[i].u][edge[i].v] = 1;
			ans[edge[i].v][edge[i].u] = 1;
			anscost += edge[i].val;
			
			int now = area[edge[i].v];		//注意: area[edge[i].v] 如果不另存，在后面可能被修改导致出错
			for (int j = 1; j <= n; j++)
			{
				if (area[j] == now)
				area[j] = area[edge[i].u];  //就这里！
			}
		}
	}
}

void PrintMST()		/*int n, ans[][]*/
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//         哈夫曼编解码
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include<bits/stdc++.h>
//#include<queue>
//using namespace std;
//
//
//
//struct HuffmanNode {
//	int val;
//	char c;
//	HuffmanNode* l, * r;
//	bool operator<(const HuffmanNode& n)const {
//		return this->val < n.val;
//	}
//};
//
//class compare {
//public:
//	bool operator()(HuffmanNode* h1, HuffmanNode* h2)
//	{
//		return h1->val > h2->val;
//	}
//};
//
//void Code(HuffmanNode* root, char num);
//void DestroyTree(HuffmanNode* root);
//
//map<char, int> MAP;
//priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> Queue;
//map<char, string> char_code;
//
//int main()
//{
//
//	string s;
//	getline(cin, s);
//	//统计次数
//	for (auto i : s)
//	{
//		MAP[i]++;
//	}
//	//建立结点并排序
//	for (auto i : MAP)
//	{
//		HuffmanNode* temp = new HuffmanNode();
//		(*temp).c = i.first;
//		(*temp).val = i.second;
//		(*temp).l = NULL;
//		(*temp).r = NULL;
//		Queue.push(temp);
//	}
//	//建树
//	HuffmanNode* Root = NULL;
//	while (Queue.size() > 1)
//	{
//		HuffmanNode* root = new HuffmanNode();
//		root->l = Queue.top();
//		Queue.pop();
//		root->r = Queue.top();
//		Queue.pop();
//		root->val = root->l->val + root->r->val;
//		root->c = '*';
//		Queue.push(root);
//		Root = root;
//	}
//	//编码
//	Code(Root, '*');
//	//输出
//	for (auto i : char_code)
//	{
//		cout << i.first << ":" << i.second << endl;
//	}
//	//销毁
//	DestroyTree(Root);
//
//	return 0;
//}
//
//
//void Code(HuffmanNode* root, char num)
//{
//	static string s;
//	if (num == '0')
//		s.push_back('0');
//	else if (num == '1')
//		s.push_back('1');
//
//	if (!root->l && !root->r)
//	{
//		char_code[root->c] = s;
//		return;
//	}
//
//	Code(root->l, '0');
//	s.pop_back();
//	Code(root->r, '1');
//	s.pop_back();
//}
//
//void DestroyTree(HuffmanNode* root)
//{
//	if (root == NULL)
//		return ;
//
//	DestroyTree(root->l);
//	DestroyTree(root->r);
//	free(root);
//	root =NULL;
//}