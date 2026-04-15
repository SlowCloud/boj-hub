# [Platinum V] shapex - 33562 

[문제 링크](https://www.acmicpc.net/problem/33562) 

### 성능 요약

메모리: 2248 KB, 시간: 12 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2026년 2월 27일 21:33:29

### 문제 설명

<p>shapex는 각 사분면에 원형, 사각형, 풍차, 별 모양이 배치된 도형들을 자르고, 합치고, 색칠하여 복잡하고 다채로운 도형들을 만들어내는 것이 목표인 게임이다.</p>

<p>도형들과 그 도형들에 대한 조작이 주어졌을 때 만들어지는 도형을 구하는 프로그램을 작성해 보자.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 150px; height: 150px; max-width: 100%;"><img alt="" src="" style="width: 150px; height: 150px; max-width: 100%;"><img alt="" src="" style="width: 150px; height: 150px; max-width: 100%;"><img alt="" src="" style="width: 150px; height: 150px; max-width: 100%;"></p>

<p>shapex에서는 도형을 쉽게 나타내기 위해 도형 코드를 사용한다. 다음은 도형 코드에 대한 설명이다.</p>

<ul>
	<li><strong>기본 도형</strong>

	<ul>
		<li>기본 도형은 총 네 가지로 종류와 코드는 다음과 같다.
		<ul>
			<li>원형(<img alt="" src="" style="height: 22px; width: 22px;">, Circle): <code>C</code></li>
			<li>사각형(<img alt="" src="" style="height: 22px; width: 22px;">, Rectangle): <code>R</code></li>
			<li>풍차(<img alt="" src="" style="height: 22px; width: 22px;">, Windmill): <code>W</code></li>
			<li>별(<img alt="" src="" style="height: 22px; width: 22px;">, Star): <code>S</code></li>
		</ul>
		</li>
	</ul>
	</li>
	<li><strong>색상</strong>
	<ul>
		<li>색상은 총 여덟 가지로 종류와 코드는 다음과 같다.
		<ul>
			<li>빨강(<img alt="" src="" style="height: 13px; width: 13px;">, Red): <code>r</code></li>
			<li>초록(<img alt="" src="" style="height: 13px; width: 13px;">, Green): <code>g</code></li>
			<li>파랑(<img alt="" src="" style="height: 13px; width: 13px;">, Blue): <code>b</code></li>
			<li>노랑(<img alt="" src="" style="height: 13px; width: 13px;">, Yellow): <code>y</code></li>
			<li>보라(<img alt="" src="" style="height: 13px; width: 13px;">, Purple): <code>p</code></li>
			<li>시안(<img alt="" src="" style="height: 13px; width: 13px;">, Cyan): <code>c</code></li>
			<li>색칠되지 않음(<img alt="" src="" style="height: 13px; width: 13px;">, Uncolored): <code>u</code></li>
			<li>하양(<img alt="" src="" style="height: 13px; width: 13px;">, White): <code>w</code></li>
		</ul>
		</li>
	</ul>
	</li>
	<li><strong>도형</strong>
	<ul>
		<li>기본 도형과 색상을 조합하여 하나의 완전한 도형을 만들 수 있다.</li>
		<li>도형 한 층은 북동쪽, 남동쪽, 남서쪽, 북서쪽 사분면으로 나뉜다.</li>
		<li>한 사분면에는 하나의 기본 도형이 존재하거나 비어 있을 수 있다.</li>
		<li>하나의 기본 도형은 하나의 색상을 가진다.</li>
		<li>이런 층들을 최소 1층부터 최대 4층까지 쌓아 한 도형을 만들 수 있다.</li>
		<li>최고층 이하에 모든 사분면이 비어 있는 층이 있는 도형은 올바르지 않은 도형이다.</li>
		<li>그림에서 높은 층의 도형은 아래층보다 작게 보인다. 도형의 크기는 그림에만 나타나며 문제 풀이와 관련이 없다.</li>
	</ul>
	</li>
	<li><strong>도형 코드</strong>
	<ul>
		<li>기본 도형과 색상의 코드를 조합하여 도형을 코드로 나타낼 수 있다.</li>
		<li>도형 한 층의 코드는 '(기본 도형)(색상)(기본 도형)(색상)(기본 도형)(색상)(기본 도형)(색상)'의 형식으로 나타낼 수 있다. 이때 (기본 도형)(색상) 쌍은 순서대로 북동쪽, 남동쪽, 남서쪽, 북서쪽 사분면의 정보를 나타낸다.</li>
		<li>비어 있는 사분면의 코드는 '<code>--</code>'으로 나타낸다.</li>
		<li>1층부터 가장 높은 층까지 각 층의 코드를 '<code>:</code>'로 구분하여 나타낸다.</li>
		<li>다음은 문제 상단에 있는 도형들의 코드 예시이다.</li>
	</ul>
	</li>
</ul>

<table align="center" border="1" cellpadding="1" cellspacing="1" class="table table-bordered td-center th-center" style="width: 500px;">
	<thead>
		<tr>
			<th scope="col" style="text-align: center;">도형</th>
			<th scope="col" style="text-align: center;">도형 코드</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center;"><img alt="" src="" style="height: 22px; width: 22px;"></td>
			<td style="text-align: center;"><code>CuCuCuCu</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><img alt="" src="" style="height: 22px; width: 22px;"></td>
			<td style="text-align: center;"><code>CbCbCbRb:CwCwCwCw</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><img alt="" src="" style="height: 22px; width: 22px;"></td>
			<td style="text-align: center;"><code>RuCw--Cw:----Ru--</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><img alt="" src="" style="height: 22px; width: 22px;"></td>
			<td style="text-align: center;"><code>CbCuCbCu:Sr------:--CrSrCr:CwCwCwCw</code></td>
		</tr>
	</tbody>
</table>

<p>도형을 조작하는 여러 가지 기계로 더욱 복잡한 도형을 만들 수 있다. 다음은 도형 조작을 위한 기계들에 대한 설명이다.</p>

<ul>
	<li><strong>절단기</strong>

	<ul>
		<li>한 도형을 서쪽 절반과 동쪽 절반으로 나눈다.</li>
		<li>절단 후 어떤 층이 완전히 빈 경우, 즉 '<code>--------</code>'이 되는 경우에는 그 층이 사라지고 그 층보다 높은 층들을 한 층씩 내린다.</li>
		<li>절단 후 모든 층이 완전히 빈 경우, 아무런 도형도 생성되지 않는다.</li>
	</ul>
	</li>
	<li><strong>회전기</strong>
	<ul>
		<li>한 도형을 정해진 각도(90도, 180도, 270도)만큼 시계방향으로 회전시킨다.</li>
	</ul>
	</li>
	<li><strong>결합기</strong>
	<ul>
		<li>두 도형을 하나의 도형으로 결합한다.</li>
		<li>즉, 두 번째로 입력된 도형을 첫 번째로 입력된 도형의 위에서부터, 두 도형에 포함된 기본 도형이 서로 겹쳐 더이상 내리지 못하거나 가장 낮은 층이 1층에 도달할 때까지 내린 후 한 도형으로 합친다.</li>
		<li>결합 후 도형이 4층을 초과할 경우, 초과한 층은 사라진다.</li>
	</ul>
	</li>
	<li><strong>색칠기</strong>
	<ul>
		<li>한 도형의 비어 있지 않은 모든 층, 모든 사분면에 색을 칠한다.</li>
		<li>기존에 있던 색은 모두 새로운 색으로 덮어씌워진다.</li>
		<li>'색칠되지 않음'으로는 색칠할 수 없다.</li>
	</ul>
	</li>
</ul>

<p>다음은 기계의 작동 예시이다.</p>

<table align="center" class="table table-bordered td-center th-center">
	<thead>
		<tr>
			<th colspan="3" scope="col">절단기</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center;">입력</td>
			<td style="text-align: center;">서쪽 절반 출력</td>
			<td style="text-align: center;">동쪽 절반 출력</td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CrRwWu--</code></td>
			<td style="text-align: center;"><code>----Wu--</code></td>
			<td style="text-align: center;"><code>CrRw----</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CuCu----:--RuRu--:Wu------</code></td>
			<td style="text-align: center;"><code>----Ru--</code></td>
			<td style="text-align: center;"><code>CuCu----:--Ru----:Wu------</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>--Rc----:Sw------</code></td>
			<td style="text-align: center;">생성되지 않음</td>
			<td style="text-align: center;"><code>--Rc----:Sw------</code></td>
		</tr>
	</tbody>
</table>

<table align="center" class="table table-bordered td-center th-center">
	<thead>
		<tr>
			<th colspan="3" scope="col">회전기</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center;">입력</td>
			<td style="text-align: center;">회전 각도</td>
			<td style="text-align: center;">출력</td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CrRwWu--</code></td>
			<td style="text-align: center;">90도</td>
			<td style="text-align: center;"><code>--CrRwWu</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CuCu----:--RuRu--:Wu------</code></td>
			<td style="text-align: center;">180도</td>
			<td style="text-align: center;"><code>----CuCu:Ru----Ru:----Wu--</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CuCu----:--RuRu--:Wu------</code></td>
			<td style="text-align: center;">270도</td>
			<td style="text-align: center;"><code>Cu----Cu:RuRu----:------Wu</code></td>
		</tr>
	</tbody>
</table>

<table align="center" class="table table-bordered td-center th-center">
	<thead>
		<tr>
			<th colspan="3" scope="col">결합기</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center;">첫 번째 입력</td>
			<td style="text-align: center;">두 번째 입력</td>
			<td style="text-align: center;">출력</td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CuCu----</code></td>
			<td style="text-align: center;"><code>----RuRu</code></td>
			<td style="text-align: center;"><code>CuCuRuRu</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CuCu----</code></td>
			<td style="text-align: center;"><code>--RuRu--</code></td>
			<td style="text-align: center;"><code>CuCu----:--RuRu--</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>Ru----Ru:Ru----Ru:RuRuRuRu</code></td>
			<td style="text-align: center;"><code>--CuCu--:--CuCu--</code></td>
			<td style="text-align: center;"><code>Ru----Ru:Ru----Ru:RuRuRuRu:--CuCu--</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>RuRuRuRu:RuRuRuRu:RuRu----:RuRu----</code></td>
			<td style="text-align: center;"><code>----CuCu:CuCuCuCu:CuCuCuCu</code></td>
			<td style="text-align: center;"><code>RuRuRuRu:RuRuRuRu:RuRu----:RuRuCuCu</code></td>
		</tr>
	</tbody>
</table>

<table align="center" class="table table-bordered td-center th-center">
	<thead>
		<tr>
			<th colspan="3" scope="col">색칠기</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td style="text-align: center;">입력</td>
			<td style="text-align: center;">색상</td>
			<td style="text-align: center;">출력</td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CrRwWu--</code></td>
			<td style="text-align: center;"><code>c</code></td>
			<td style="text-align: center;"><code>CcRcWc--</code></td>
		</tr>
		<tr>
			<td style="text-align: center;"><code>CuCw----:--RyRg--:Wb------</code></td>
			<td style="text-align: center;"><code>b</code></td>
			<td style="text-align: center;"><code>CbCb----:--RbRb--:Wb------</code></td>
		</tr>
	</tbody>
</table>

<p>도형 조작을 위해 레지스터를 사용한다. 다음은 레지스터에 대한 설명이다.</p>

<ul>
	<li>도형 조작을 위해 $100$개의 레지스터를 사용할 수 있다.</li>
	<li>레지스터에는 순서대로 $R_1$, $R_2$, $\cdots$, $R_{100}$으로 이름이 매겨져 있다.</li>
	<li>처음 주어지는 $N$개의 도형은 $R_1$, $R_2$, $\cdots$, $R_N$에 저장되어 있다.</li>
	<li>나머지 $100−N$개의 레지스터에는 <em>None</em>이 저장되어 있다.</li>
	<li>레지스터에 저장된 값은 다른 값이 저장되지 않는 이상 유지된다.</li>
</ul>

### 입력 

 <p>첫 번째 줄에 처음 주어지는 도형의 개수 $N$($1 \le N \le 10$)과 조작의 개수 $M$($1 \le M \le 10\,000$)이 공백으로 구분되어 주어진다.</p>

<p>다음 $N$개의 줄에 처음 주어지는 도형의 코드가 순서대로 주어진다. 주어지는 도형들은 모두 1층만 있다. 올바른 도형 코드만 입력으로 주어진다.</p>

<p>다음 $M$개의 줄에 조작이 다음과 같은 형식으로 순서대로 주어진다. 주어지는 모든 레지스터 번호는 $1$ 이상 $100$ 이하의 정수이다.</p>

<ul>
	<li>$1$ $i$ $j$ $k$ $(j \neq k)$
	<ul>
		<li>$R_i$에 저장된 도형을 절단기에 넣어 서쪽 절반을 $R_j$에, 동쪽 절반을 $R_k$에 저장한다.</li>
		<li>$R_i$에 저장된 값이 <em>None</em>일 경우 $R_j$, $R_k$에 저장되는 값도 <em>None</em>이다.</li>
		<li>어느 쪽 절반에서 도형이 생성되지 않을 경우 그 절반에 해당하는 레지스터에 저장되는 값도 <em>None</em>이다.</li>
	</ul>
	</li>
	<li>$2$ $i$ $j$ $k$ ($k \in$ {$1$, $2$, $3$})
	<ul>
		<li>$R_i$에 저장된 도형을 $k \times 90$도 회전기에 넣어 생성되는 도형을 $R_j$에 저장한다.</li>
		<li>$R_i$에 저장된 값이 <em>None</em>일 경우 $R_j$에 저장되는 값도 <em>None</em>이다.</li>
	</ul>
	</li>
	<li>$3$ $i$ $j$ $k$
	<ul>
		<li>$R_i$, $R_j$에 저장된 도형을 순서대로 결합기에 넣어 생성되는 도형을 $R_k$에 저장한다.</li>
		<li>$R_i$, $R_j$에 저장된 값 중에 <em>None</em>이 있을 경우 $R_k$에 저장되는 값도 <em>None</em>이다.</li>
	</ul>
	</li>
	<li>$4$ $i$ $j$ $k$ ($k \in$ {'<code>r</code>', '<code>g</code>', '<code>b</code>', '<code>y</code>', '<code>p</code>', '<code>c</code>', '<code>w</code>'})
	<ul>
		<li>$R_i$에 저장된 도형을 색칠기에 넣어 색상 $k$로 칠해서 $R_j$에 저장한다.</li>
		<li>$R_i$에 저장된 값이 <em>None</em>일 경우 $R_j$에 저장되는 값도 <em>None</em>이다.</li>
	</ul>
	</li>
</ul>

### 출력 

 <p>모든 조작을 완료한 후 $R_{100}$에 저장된 값을 출력한다. 도형일 경우 도형 코드를 출력하고, <em>None</em>일 경우 <span style="color:#e74c3c;"><code>None</code></span>을 출력한다.</p>

