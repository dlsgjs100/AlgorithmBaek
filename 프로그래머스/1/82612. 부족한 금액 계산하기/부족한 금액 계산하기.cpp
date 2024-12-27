using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long longMoney = money;
    long long totalPrice = 0;
    
    for(int i=1;i<=count;i++){
        totalPrice += price*i;
    }
    
    answer = totalPrice-longMoney>0 ? totalPrice-longMoney : 0;

    return answer;
}