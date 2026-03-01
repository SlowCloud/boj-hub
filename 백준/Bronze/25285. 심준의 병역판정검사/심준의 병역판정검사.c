
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#define FOR(i,a,b) for(auto i=a;i<b;i++)



// [low, high)
bool between(int64_t target, int64_t low, int64_t high) {
	return low <= target && target < high;
}

int main() {

	int T;
	scanf("%d", &T);

	FOR(_, 0, T) {
		int64_t h, w;
		scanf("%lld %lld", &h, &w);

		w *= 1e8;

		int64_t tmp = w / (h * h);

		int res = 0;
		if (h <= 140) {
			res = 6;
		}
		else if (h < 146) {
			res = 5;
		}
		else if (h < 159) {
			res = 4;
		}
		else if (h < 161) {
			if (between(tmp, 160000, 350000)) {
				res = 3;
			}
			else {
				res = 4;
			}
		}
		else if (h < 204) {
			if (between(tmp, 200000, 250000)) {
				res = 1;
			}
			else if (between(tmp, 185000, 300000)) {
				res = 2;
			}
			else if (between(tmp, 160000, 350000)) {
				res = 3;
			}
			else {
				res = 4;
			}
		}
		else {
			res = 4;
		}

		printf("%d\n", res);
	}

	return 0;
}