#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
	vector<int> L(N);
	vector<int> J(N);
	for (int i = 0; i < N; i++)
	{
		cin >> L[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> J[i];
	}
	int maxJoy = 0;
	int maxHealth = 100;
	for (int i = 0; i < (1 << N); i++)
	{
		int currentHealth = maxHealth;
		int currentJoy = 0;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				currentHealth -= L[j];
				currentJoy += J[j];
			}
		}
		if (currentHealth > 0)
		{
			maxJoy = max(maxJoy, currentJoy);
		}
	}
	cout << maxJoy << endl;

    return 0;
}
