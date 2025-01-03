#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int number=0;
    for(int i = 0 ; i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                number = nums[i]+nums[j]+nums[k];
                int temp=0;
                for(int m=1;m<=number;m++){
                    if(number%m==0){
                        temp++;
                    }
                }
                    if(temp==2){
                        answer++;
                    }
            }
        }
    }

    return answer;
}