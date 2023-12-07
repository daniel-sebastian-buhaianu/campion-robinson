#include <fstream>
using namespace std;
int main()
{
	ifstream f("robinson.in");
	int m, n, l, c;
	f >> m >> n >> l >> c;
	f.close();
	int a[m+2][m+2], i, j;
	for (i = 0; i <= m+1; i++)
	{
		a[0][i] = a[m+1][i] = -1;
		a[i][0] = a[i][m+1] = -1;
	}
	for (i = 1; i <= m; i++)
		a[1][i] = a[i][1] = n + i-1;
	for (i = 2; i <= m; i++)
		for (j = 2; j <= m; j++)
			a[i][j] = (a[i-1][j] + a[i][j-1])%1000;
	ofstream g("robinson.out");
	g << a[m][m] << '\n';
	int dx[] = {-1,0,1,0};
	int dy[] = {0,1,0,-1};
	while (a[l][c] != -1)
	{
		g << l << ' ' << c << '\n';
		int r = a[l][c]%4;
		a[l][c] = -1;
		l += dx[r];
		c += dy[r];
	}
	g.close();
	return 0;
}

