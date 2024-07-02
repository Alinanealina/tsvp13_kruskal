#include <iostream>
using namespace std;
const int N = 10;
struct graf { int w; int v1; int v2; };
int main()
{
	setlocale(LC_ALL, "Russian");
	graf gr[N * N], ost[N], obm;
	bool f = false, g = false;
	int i, j, j1, j2, k, n = 0, m = 1, l = 1, sum = 0, sv[N][N] = { 0 } , A[N - 1][N] = {
		/*0, 20, 0, 0, 0, 23, 1,
		0, 0, 5, 0, 0, 0, 4,
		0, 0, 0, 3, 0, 0, 9,
		0, 0, 0, 0, 17, 0, 16,
		0, 0, 0, 0, 0, 28, 25,
		0, 0, 0, 0, 0, 0, 36,*/
		0, 3, 0, 5, 9, 0, 0, 0, 0, 0,
		0, 0, 8, 0, 3, 9, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 3, 2, 0, 0, 0,
		0, 0, 0, 0, 14, 0, 0, 10, 9, 0,
		0, 0, 0, 0, 0, 8, 0, 6, 6, 0,
		0, 0, 0, 0, 0, 0, 14, 0, 10, 8,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 3,
		0, 0, 0, 0, 0, 0, 0, 0, 11, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 7,
	};
	for (i = 0; i < N - 1; i++)
	{
		for (j = i; j < N; j++)
		{
			if (A[i][j] != 0)
			{
				gr[n].w = A[i][j];
				gr[n].v1 = i + 1;
				gr[n].v2 = j + 1;
				n++;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (gr[j].w < gr[k].w)
				k = j;
		}
		if (k != i)
		{
			obm = gr[i];
			gr[i] = gr[k];
			gr[k] = obm;
		}
	}
	for (i = 0; i < n; i++)
		cout << " Вес:" << gr[i].w << "\tВершина 1: " << gr[i].v1 << "\tВершина 2: " << gr[i].v2 << endl;

	ost[0] = gr[0];
	sv[0][0] = ost[0].v1;
	sv[0][1] = ost[0].v2;
	for (i = 1; i < n; i++)
	{
		f = false;
		g = false;
		for (j = 0; j < l; j++)
		{
			for (k = 0; sv[j][k] != 0; k++)
			{
				if (!f && sv[j][k] == gr[i].v1)
				{
					f = true;
					j1 = j;
				}
				if (!g && sv[j][k] == gr[i].v2)
				{
					g = true;
					j2 = j;
				}
			}
		}
		if (!f && !g)
		{
			ost[m] = gr[i];
			sv[l][0] = ost[m].v1;
			sv[l][1] = ost[m].v2;
			m++;
			l++;
		}
		else if (f && g)
		{
			if (j1 != j2)
			{
				ost[m++] = gr[i];
				if (j1 > j2)
				{
					j = j1;
					j1 = j2;
					j2 = j;
				}
				for (j = 0; sv[j1][j] != 0; j++);
				for (k = 0; sv[j2][k] != 0; k++, j++)
				{
					sv[j1][j] = sv[j2][k];
					sv[j2][k] = 0;
				}
				l--;
				for (j = j2; j < l; j++)
				{
					for (k = 0; k < N; k++)
					{
						j1 = sv[j][k];
						sv[j][k] = sv[j + 1][k];
						sv[j + 1][k] = j1;
					}
				}
			}
		}
		else
		{
			ost[m] = gr[i];
			if (f)
			{
				for (j = 0; sv[j1][j] != 0; j++);
				sv[j1][j] = ost[m].v2;
			}
			else if (g)
			{
				for (j = 0; sv[j2][j] != 0; j++);
				sv[j2][j] = ost[m].v1;
			}
			m++;
		}
		/*for (j = 0; j < l; j++)
		{
			for (k = 0; sv[j][k] != 0; k++)
				cout << " " << sv[j][k];
			cout << endl;
		}
		cout << endl;*/
	}
	cout << "\n Минимальный остов: ";
	for (i = 0; i < m; i++)
	{
		cout << "(" << ost[i].v1 << "," << ost[i].v2 << ")";
		sum += ost[i].w;
	}
	cout << "\n Вес: " << sum;
	return 0;
}