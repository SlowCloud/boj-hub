# [Gold III] 멘헤라 - 35293 

[문제 링크](https://www.acmicpc.net/problem/35293) 

### 성능 요약

메모리: 2044 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그리디 알고리즘, 그래프 탐색, 너비 우선 탐색

### 제출 일자

2026년 2월 21일 23:24:50

### 문제 설명

<p style="text-align: center;"><img alt="" src="" style="width: 500px; height: 400px;"></p>

<p style="text-align: center;"><small>급성 멘헤라가 온 wlgh7407</small></p>

<p>멘헤라가 된 wlgh7407은 마음의 안정을 찾기 위해 알코올을 섭취하여 목표 단위 취기에 도달하고자 한다. wlgh7407의 앞에는 용량이 동일한 네 가지 선택지가 놓여 있다.</p>

<table class="table table-bordered">
<thead>
<tr>
<td><strong>선택지</strong></td>
<td><strong>취기 변화량</strong></td>
</tr>
</thead>
<tbody>
<tr>
<td>순하리 레몬진 9도</td>
<td>$+9$ 단위</td>
</tr>
<tr>
<td>순하리 레몬진 7도</td>
<td>$+7$ 단위</td>
</tr>
<tr>
<td>순하리 레몬진 4.5도</td>
<td>$+4.5$ 단위</td>
</tr>
<tr>
<td>생수</td>
<td>$-2$ 단위</td>
</tr>
</tbody>
</table>

<p>wlgh7407은 목표 취기 $N$에 도달하기 위해 마셔야 하는 전체 액체의 양을 최소화하고 싶어 한다. wlgh7407이 정확히 $N$ 단위 취기에 도달할 수 있는 선택의 최소 횟수를 알아내는 프로그램을 작성하시오.</p>

<p>초기 취기는 $0$이고, 취기는 음수가 될 수 없다.</p>

### 입력 

 <p>첫 번째 줄에 목표 취기 $N$이 주어진다. $N$은 음이 아닌 실수이다. ($0 \le N < 10^{16} + 1$)</p>

<p>$N$은 소수점 첫째 자리까지 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 목표 취기에 도달하기 위한 최소 섭취 횟수를 출력한다. 만약 어떠한 조합으로도 정확히 $N$을 만들 수 없다면 <code><span style="color:#e74c3c;">-1</span></code>을 출력한다.</p>

