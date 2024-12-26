#include <iostream>
using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    double num3 = 0;
    num3 = (double)num1 / (double)num2;
    answer = num3 * 1000;
    return answer;
}