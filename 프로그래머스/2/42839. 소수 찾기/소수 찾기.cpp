#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool Isprime(int number)
{
    if(number == 1 || number == 0) return false;
    for(int i=2;i*i<=number;i++)
    {
        if(number%i==0)
        {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> prime;
    // numbers로 조합가능한 숫자
    sort(numbers.begin(),numbers.end());
    do
    {
        for(int i=1;i<=numbers.size();i++)
        {
            int number = stoi(numbers.substr(0,i));
            if(Isprime(number))
            {
                prime.insert(number);
            }
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    answer = prime.size();
    return answer;
}