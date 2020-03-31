- 내가 이해한 문제 내용
	- 2차원 평면상에 있는 n개의 점들 중 가장 가까운 두 점 사이의 거리를 제곱하여 출력한다.

- 접근방식
	- 처음에는 단순하게 이중 for문과 두 점 사이의 거리를 구하는 공식을 활용하여 구하고자 하였으나 실패 => 시간초과
	- 스위핑 알고리즘을 공부해봄
	- 이론은 조금 이해했으나.. 너무 어려웠다 ㅠㅠ
	- 결국 블로그 답안을 참고하여 주석을 남기면서 이해하고자 함
		- y좌표에서는 +/- d 범주안에서만 찾고 x좌표에서는 sort를 통해 순서대로 정렬하고 가까운 점들끼리의 비교로 불필요한 search 방지

- 어려웠던 점
	- 새로운 함수들과 익숙하지 않은 부분들 => 공부해야 할 부분들 (<map>, <set>, structure, <vector>)
	- 순서대로 정리하며 이해할 때 이해되지 않는 부분은 없었지만 기술적인 부분 + 혼자 방법 구안과 구현이 아직은 어려움
	- 처음 참고한 블로그의 코드 자체가 컴파일 에러를 만듬.. 수정해 보았지만 결국 안되서 다른 코드 참조하여 살펴보고 제출했음 - 같은 원리로 위와 같은 접근 방식 사용 

- 복잡도
	- 시간복잡도: O(NlogN) 
	- 공간복잡도: O(NlogN) 
	

- 처음 참고한 코드 출처: https://www.acmicpc.net/blog/view/25 
- 제출한 코드 출처: https://www.crocus.co.kr/807

=> 두 코드의 알고리즘은 엄청 비슷했다. 똑같은 방식으로 조금 다른 구현방식을 가지고 있었음