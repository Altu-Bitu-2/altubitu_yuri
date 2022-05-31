#include <iostream>

using namespace std;

string solution(int x, int n) {
	if (n > 1 && n % 2 == 1) { //만약 프로그램이 지문에 주어진 조건에 의해 컴파일에 실패할 경우 ERROR를 출력
		return "ERROR";
	}
	if (n == 1 && x < 0) { //만약 프로그램이 무한히 많은 수를 출력한다면 INFINITE를 출력
		return "INFINITE";
	}
	if (n == 1 || x <= 0) {
		return "0";
	}
	if (n == 0) {
		return "INFINITE";
	}
	return to_string((x - 1) / (n / 2)); //만약 프로그램이 정상적으로 종료된다면 프로그램이 출력한 수의 개수를 출력
}

/**
 * [화살표 연산자]
 *
 * 1. n이 1보다 큰 홀수인 경우 -> ERROR
 * 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 * 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 5. 나머지 경우엔 (x - 1)을 (n / 2)로 나눈 몫을 출력
 *    - 연산했을 때 1 이상이 남을 때까지만 출력을 할 수 있으므로 1을 뺀 값에서 몫을 구함
 */

int main() { //main함수
	int x, n; //정수형 변수

	//입력
	cin >> x >> n; //변수 x의 초기값을 뜻하는 정수 X와 화살표의 길이를 뜻하는 정수 N 입력

	//연산 & 출력
	cout << solution(x, n); //실행 결과 출력
	return 0;
}