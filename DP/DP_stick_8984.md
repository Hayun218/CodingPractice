#####8984번 - 막대기 - DP문제

- 내가 이해한 문제 내용
	- 두 개의 평행한 수평선 사이를 선 (t,d) 로 연결하였을 때 다음의 조건 3개를 만족하는 경우 중 선의 길이가 가장 긴 길이를 출력 (선의 길이 = 수평선 사이의 길이 + |t-d|)
		1. 막대기는 끝점을 제외하고는 교차하지 않는다.
		2. 세개 이상의 막대기 끝이 한 점에서 만나지 않는다.
		3. 모든 막대기는 연결되어 있다.

- 접근방식
 	- 조건 하나하나 마다 필요한 요소들을 생각하였을 때:
		1. 끝점만 교차 => 한개의 t와 연결된 d의 갯수 혹은 그 반대의 경우를 search
		2. 세개 이상 X => 1번에서의 방법대로 찾았을 때 3개 이상이면 delete
		3. 모든 막대기는 연결 => 1번의 조건이 충족할 경우 자연스럽게 충족됨
	- 막대기의 길이를 메모이제이션으로 배열에 저장하고 그 막대기와 겹치는 다른 막대기가 있을 때 호출하여 사용
	- 페어 안에 좌표값을 넣기.. 그 이후에 이 페어를 어떻게 활용하지..?
	- 각각의 t와 d를 벡터로 구현하여서 정렬시켜서 겹치는 부분 찾기 (찾는건 binary search를 통해서)
	
-
<문제풀이를 참고해서 나온 내용>

- unique() 와 clear() 함수를 활용해서 중복되는 부분을 없앤다 (겹치는 부분을 search 말고 단순하게 없애고 lower_bound 를 통해 후에 구현)
- DP 배열이 두개 
	- dp_V[x] : x번째 v의 좌표점에서 끝나는 지그재그의 최장길이
	- dp_D[x] : x번째 d의 좌표점에서 끝나는 지그재그의 최장길이
- 페어로 만든 stick 변수 또한 sort하고 lower_bound에서 기준점이 됨 


- 어려웠던 점
	- 새로운 함수들을 배웠다 => unique, clear, lower_bound
	- pair인 stick과 위 아래로 있는 두개의 수평선 위에 있는 점들을 어떤식으로 연결할지 고민했었다
	- 풀이를 참고하고 코드를 보며 이해할 때 새로운 함수를 이해하고 생각하지 못했던 부분들도 있어서 재밌었는데 그 중 메모이제이션 함수 이해하는게 엄청 오래걸렸다.
	- 해당 배열에 넣은게 없는데 idx값만 넣어도 특정 값을 출력한다는 부분에서 이해가 너무 안되서 예시를 하나하나 적용해 보았지만 막혔다.. 먼가 가물가물하게 이해할 것 같은 기분 

~~~
dp_T[t_idx] = max(top, down + len);
dp_D[d_idx] = max(down, top + len); // 이 부분..
~~~

- 구현하고자 했지만 우선 생각하는 부분에서 막혀서 자료들만 보고 다시 생각했고 결국 코드를 보고 이해해 보고자 했다. 일단 개념부터 잡고 새로운 내용을 익히기 위해 새로 접한 부분들을 찾아보고 알아보았다. 시간을 많이 들일 수 있었어서 구현은 혼자 못했지만 조금이나마 배운 듯해서 알찼다고 생각한다!

- 시간복잡도: O(NlogN)

- [코드 참고한 곳] <https://sshwas.tistory.com/14>


~~~
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

int N, L;
pair<int, int> stick[MAX];
vector <int> t, d;
long long dp_T[MAX];
long long dp_D[MAX];

int main(){
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &stick[i].first, &stick[i].second);
        t.push_back(stick[i].first);
        d.push_back(stick[i].second);
    }
    sort(stick, stick+N);
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());

    t.erase(unique(t.begin(), t.end()), t.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    long long ans = 0;

    for(int i = 0; i < N; i++){
        int t_idx = lower_bound(t.begin(), t.end(), stick[i].first) - t.begin(); // 말그대로 index 구하는거! => len 구하기 위한 Idx
        int d_idx = lower_bound(d.begin(), d.end(), stick[i].second) - d.begin();
        int len = L + (abs(stick[i].second - stick[i].first));

        long long top = dp_T[t_idx]; 
        long long down = dp_D[d_idx];

        dp_T[t_idx] = max(top, down + len);
        dp_D[d_idx] = max(down, top + len);
        ans = max(dp_T[t_idx], max(ans, dp_D[d_idx]));
    }
    printf("%lld\n", ans);
    return 0;
}
~~~

###적용한 개념들

#### 알고리즘 - 다이나믹 프로그래밍 
	- 다이나믹 프로그래밍 
		- 하나의 문제는 한번만 푼다 (효율성 upgrade)
			- 메모이제이션!! 
		- 다음과 같은 가정이 있을 때 DP 가능:
			1. 큰 문제를 작은 문제로 나눌 수 있다.
			2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하게 적용된다.
		- 요약 => 하나의 큰 문제를 작은 문제로 잘게 나누어 해결한 이후에 조합하여 전체의 답을 구한다.
			
	- 메모이제이션 (memoization)
		- 이미 계산한 결과를 배열에 저장함으로써 후에 필요할 때마다 반환하여서 적용
	
	- 2가지 방법
		* top-down
			- 문제를 작은 문제로 나누어 풀고 전체 문제를 구함
			- 가장 먼저 호출하는 문제가 가장 큰 문제이므로 위에서 아래로 간다는 의미
			- 주로 재귀함수 활용
			- 가독성이 좋고 점화식 이해가 용이
		* bottom-up
			- 가장 작은 문제부터 풀고 문제의 크기를 늘려가면서 전체문제를 품
			- 주로 반복문 활용 
			- 함수를 별개로 호출하지 않으므로 메모리와 시간을 절약


#### lower_bound 
	- 일종의 이진탐색으로 정렬된 데이터에서만 가능
	- (시작위치, 끝위치, 찾고자 하는 데이터)
	- 찾고자 하는 데이터가 8일 경우 8 이상인 값이 처음 나오는 위치를 구한다
	- Ex)
		- {1, 3, 5, 7, 9, 11}에서, 8 이상인 값이 처음 나오는 위치를 구하는 과정: 
			1) 시작 위치= 1, 끝 위치= 6으로 설정한다.
			2) 시작 위치 1과 끝 위치 6의 중간 위치인 3((1+6) / 2)번째 값을 8과 비교한다.
			3) 5는 8보다 작으므로 시작 위치를 3 다음인 4로 설정한다.
			4) 시작 위치 4와 끝 위치 6의 중간 위치인 5번째 값을 8과 비교한다.
			5) 9는 8보다 크다. 이때에는 이분 탐색과 달리, 끝 위치를 중간 위치인 5로 설정한다.
				- 왜냐하면, 8 이상인 값이 처음 나오는 위치를 구하는 것이므로, 
				9가 Lower Bound가 될 수도 있다. 따라서 끝 값까지 포함한다.
			6) 시작 위치=4, 끝 위치=5이므로 중간 위치인 4번째 값을 8과 비교한다.
			7) 7은 8보다 작다. 따라서 시작 위치를 중간 위치+1 = 5로 설정한다.
			8) 시작 위치 = 끝 위치 = 5이므로 5번째 값인 9가 Lower Bound가 된다.
