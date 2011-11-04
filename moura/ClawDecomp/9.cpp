#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int g[301][3];
int d[301];

bool can2colors()
{
	stack<int> wstack, bstack;
	vector<short> color(301);
	wstack.push(1);

	while(true) {
		int u;
		if(!wstack.empty()) {
			u = wstack.top();
			wstack.pop();
			if(color[u] == 1)
				continue;
			else if(color[u] == 2)
				return false;
			color[u] = 1;
			bstack.push(g[u][0]);
			bstack.push(g[u][1]);
			bstack.push(g[u][2]);
		}
		else if(!bstack.empty()) {
			u = bstack.top();
			bstack.pop();
			if(color[u] == 2)
				continue;
			if(color[u] == 1)
				return false;
			color[u] = 2;
			wstack.push(g[u][0]);
			wstack.push(g[u][1]);
			wstack.push(g[u][2]);
		} else {
			return true;
		}
	}
	return true;
}

int main()
{
	int v, a, b;

	while(true) {	
		cin >> v;
		if(v ==0)
			return 0;

		for(int i = 0; i <=v; i++)
			g[i][0] = g[i][1] = g[i][2] = d[i] = 0;

		while(true) {
			cin >> a >> b;
			if( a == b && a == 0)
				break;
			g[a][d[a]++] = b;
			g[b][d[b]++] = a;
		}

		if(can2colors())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
