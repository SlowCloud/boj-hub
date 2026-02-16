# [Diamond IV] KSA 수열과 쿼리 - 33494 

[문제 링크](https://www.acmicpc.net/problem/33494) 

### 성능 요약

메모리: 21320 KB, 시간: 4888 ms

### 분류

자료 구조, 정렬, 이분 탐색, 제곱근 분할법

### 제출 일자

2026년 2월 16일 13:22:30

### 문제 설명

<p>길이가 $N$인 수열 $A_1, A_2, \cdots, A_N$과 정수 $K$가 주어진다. 이때, 다음 쿼리를 $Q$개 수행하는 프로그램을 작성해 보자.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>1</code></span> <span style="color:#e74c3c;">$s_i$ $e_i$</span>: $A_{s_i}, A_{s_i+1}, \cdots, A_{e_i}$에 $1$을 더한다.</li>
	<li><span style="color:#e74c3c;"><code>2</code></span> <span style="color:#e74c3c;">$s_i$ $e_i$</span>: $(A_{s_i}\bmod K) +(A_{s_i+1}\bmod K) +\cdots +(A_{e_i}\bmod K)$를 출력한다.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 두 개의 정수 $N$, $K$가 공백으로 구분되어 주어진다.</p>

<p>두 번째 줄에 $N$개의 정수 $A_1,A_2,\cdots,A_N$이 공백으로 구분되어 주어진다.</p>

<p>세 번째 줄에 정수 $Q$가 주어진다.</p>

<p>다음 $Q$개의 줄에 쿼리들의 정보가 주어지며, 그 중 $i$번째 줄에는 세 개의 정수 $q_i$, $s_i$, $e_i$가 공백으로 구분되어 주어진다. $q_i$는 $i$번째 쿼리의 종류를 나타낸다.</p>

### 출력 

 <p>$q_i = 2$인 쿼리에 대해 각 줄에 쿼리의 답을 한 줄에 하나씩 순서대로 출력한다.</p>

