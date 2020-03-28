//정답! vector 로 돌리고 따로 함수로 빼고 0으로 처리하는 것이 아니라 바로 안에서 for 문 계산하니까 정답으로 처리됨!
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> nan;
int sum;

void answer(){
  for(int i = 0; i < 8; i++){
    for(int j = 1; j < 9; j++){
      if(sum - nanjangi[i] - nanjangi[j] == 100){
        for(int k = 0; k < 9; k++)
        if(k != i && k != j)
        printf("%d\n",nanjangi[k]);
        return;
      }
    }
  }
}

int main(){
  sum = 0;
  for(int i = 0; i < 9; i++){
    int num;
    scanf("%d", &num);
    nanjangi.push_back(num);
    sum += num;
  }
  sort(nanjangi.begin(), nanjangi.end());
  answer();
  return 0;
}
