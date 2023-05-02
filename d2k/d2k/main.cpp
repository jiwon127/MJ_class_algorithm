#include <iostream>
#include <queue>
#include <cstring>
using namespace std;



int y_ar[4] = { 0,0,-1,1 };
int x_ar[4] = { 1,-1,0,0 };
int n;
int arr[125][125];
int dist[125][125];

void dijkstra() 
{

	priority_queue <pair<int, pair<int, int>>> pq;
	pq.push(make_pair(1 * arr[0][0], make_pair(0, 0)));
	dist[0][0] = arr[0][0];

	while (!pq.empty()) 
	{
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		for (int i = 0; i < 4; i++) 
		{
			int ny = y + y_ar[i];
			int nx = x + x_ar[i];

			int ncost = arr[ny][nx];

			if (ny >= 0 && ny < n && nx >= 0 && nx < n) 
			{
				int before_v = dist[ny][nx];
				int current_v = dist[y][x] + ncost;

				if (before_v > current_v) 
				{
					dist[ny][nx] = current_v;
					pq.push(make_pair(1 * current_v, make_pair(ny, nx)));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cnt = 1;

	while (1) 
	{
		cin >> n;
		if (n == 0)
			break;

		srand((unsigned int)time(NULL));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//cin >> arr[i][j];
				arr[i][j] = rand() % 10;
				dist[i][j] = 2000000000;
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}

		dijkstra();
		cout << "Problem " << cnt++ << ": " << dist[n - 1][n - 1] << "\n";
	}


	return 0;
}