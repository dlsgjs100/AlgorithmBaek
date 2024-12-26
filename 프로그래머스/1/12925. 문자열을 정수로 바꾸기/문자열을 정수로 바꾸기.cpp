#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int size = s.size();
	int digit = 0;

	if (s[0] == '+') {
		int temp = 1;
		digit = size - 1;
		for (int i = 1; i < size; i++) {
			for (int j = i; j < digit; j++) {
				temp *= 10;
			}
			answer += (s[i] - '0') * temp;
			temp = 1;
		}
	}
	else if (s[0] == '-') {
		int temp = 1;
		digit = size - 1;
		for (int i = 1; i < size; i++) {
			for (int j = i; j < digit; j++) {
				temp *= 10;
			}
			answer += (s[i] - '0') * temp;
			temp = 1;
		}
		answer *= -1;
	}
	else {
		int temp = 1;
		digit = size;
		for (int i = 0; i < size; i++) {
			for (int j = i; j < digit - 1; j++) {
				temp *= 10;
			}
			answer += (s[i] - '0') * temp;
			temp = 1;
		}
	}
	return answer;
}