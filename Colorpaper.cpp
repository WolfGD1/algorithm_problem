#include <iostream>

int arr[130][130], white, blue;
int ColorCheck(int len, int x, int y)
{
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++)
			if (arr[i][j] != arr[x][y]) return 0;
	}
	return 1;
}

void Cut(int xx, int yy, int x, int y)
{
	int i, j;
	bool chk = ColorCheck(x - xx + 1, xx, yy);
	if (chk) {
		arr[xx][yy] == 0 ? white++ : blue++;
		return;
	}
	else {
		Cut(xx, yy, (xx + x) / 2, (yy + y) / 2);
		Cut((xx + x) / 2 + 1, yy, x, (yy + y) / 2);
		Cut(xx, (yy + y) / 2 + 1, (xx + x) / 2, y);
		Cut((xx + x) / 2 + 1, (yy + y) / 2 + 1, x, y);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);	cin.tie(0);
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) { for (j = 0; j < n; j++) cin >> arr[i][j]; }
	Cut(1, 1, n, n);
	cout << white << '\n' << blue;
} //c++