#include <bits/stdc++.h>
using namespace std;

long long fail(long long fail, long long time_cur, long long time_prev) {
    return fail * (time_cur + time_prev) + time_cur;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    long long l,r,m;
    l=1,r=1e9;
    
    while(l<=r) {
        m = l + r >> 1;
        long long answer = times[0];
        for(int i=1;i<diffs.size();i++) {
            long long diff = diffs[i];
            answer += fail(max(0ll, diff - m), times[i], times[i-1]);
            if(answer > limit || answer < 0) break;
        }
        if(answer > limit || answer <= 0) {
            l = m + 1;
        }
        else r = m - 1;
    }
    
    
    return l;
}