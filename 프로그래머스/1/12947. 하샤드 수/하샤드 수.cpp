#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int num=x;
    int sum=0;
    do{
        sum+=num%10;
        num/=10;
    }while(num>0);
    answer = x%sum==0?answer:!answer;
    
    cout<<x<<"의 모든 자릿수의 합은 "<<sum<<"입니다. "<<x;
    
    // 하샤드 수입니다.
    if(answer){
        //는
        if((x%10 == 2) || (x%10 == 4) || (x%10 == 5) || (x%10 == 6)){
        cout<<"는 "<<sum;
            //으로
            if((sum==0) || (sum==3) || (sum==6)){
            cout<<"으로 나누어 떨어지므로 "<<x<<"는 하샤드 수입니다.";
            }
            //로
            else{
                 cout<<"로 나누어 떨어지므로 "<<x<<"는 하샤드 수입니다.";
            }
        }
        //은
        else{
            cout<<"은 "<<sum;
            //으로
            if((sum==0) || (sum==3) || (sum==6)){
            cout<<"으로 나누어 떨어지므로 "<<x<<"은 하샤드 수입니다.";
            }
            //로
            else{
                 cout<<"로 나누어 떨어지므로 "<<x<<"은 하샤드 수입니다.";
            }
        }
    }
    // 하샤드 수가 아닙니다.
    else{
        //는
        if((x%10 == 2) || (x%10 == 4) || (x%10 == 5) || (x%10 == 6)){
        cout<<"는 "<<sum;
            //으로
            if((sum==0) || (sum==3) || (sum==6)){
            cout<<"으로 나누어 떨어지므로 "<<x<<"는 하샤드 수가 아닙니다.";
            }
            //로
            else{
                 cout<<"로 나누어 떨어지므로 "<<x<<"는 하샤드 수가 아닙니다.";
            }
        }
        //은
        else{
            cout<<"은 "<<sum;
            //으로
            if((sum==0) || (sum==3) || (sum==6)){
            cout<<"으로 나누어 떨어지므로 "<<x<<"은 하샤드 수가 아닙니다.";
            }
            //로
            else{
                 cout<<"로 나누어 떨어지므로 "<<x<<"은 하샤드 수가 아닙니다.";
            }
        }
    }
    
    return answer;
}