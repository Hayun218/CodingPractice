- 문제링크 : <https://www.acmicpc.net/problem/9205>

####처음문제 푼 날짜 : 2018.11.18

- 내가 이해한 문제내용
	- 1000m 이내의 장소만 움직일 수 있음
	- 주어진 조건을 만족시키면서 출발점까지 갈 수 있는지 확인

- 접근 방식
	- c++의 가장 기초 공부
	- 다른 이의 풀이를 보며 이해
	- 플로이드 활용  
	(모든 정점 사이의 거리 구함)

- 어려웠던 점
	- 새로운 내용이어서 어려웠음
	- 혼자서 할려면 못할것 같음
	- 여전히 이해 부족 

- 복잡도
	- 시간복잡도: 3중 반복문을 사용하기 때문에 O(N^3)
	- 배열의 크기 (N)* 자료형의 크기 (N) 공간복잡도: O(N^2)

----

#### 두번째 : 2019.08.09 ***(Floyd Warshall 공부 (TIL)*** ~ 

- 이해한 문제내용
	- 출발점, 도착점, 그리고 입력으로 주어지는 간선을 활용할 때 거리가 50*20 즉 1000 이하라면 HAPPY 아니라면 SAD
		- 편의점을 방문할 때마다 맥주를 full로 채운다면 최대한 갈 수 있는 거리가 1000이므로

- 접근방식
	- 플로이드 와샬

- 어려웠던점

- 배운점

- 시간복잡도 : 