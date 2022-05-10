#include <iostream>

using namespace std;


int main() {
	int N, M, B;
	int map[500][500];
	int leastTime = 0x7f7f7f7f;
	int mostHeight;
	cin >> N >> M >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
		for (int h = 0; h <= 256; h++) {
			int build = 0;
			int remove = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					int height = map[i][j] - h;
					if (height > 0) {
						remove += height;
					}
					else if (height < 0) {
						build -= height;
					}
				}
			}
			if (remove + B >= build) {
				int time = remove * 2 + build;
				if (leastTime >= time) {
					leastTime = time;
					mostHeight = h;
				}
			}
		}
		cout << leastTime << ' ' << mostHeight << '\n';
}