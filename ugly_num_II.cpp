#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

/**
 * Write a program to find the n-th ugly number.
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5
 * First attempt: using priority_queue, as c++ template library implementations of 
 *                priority_queues use sorted sequence rather than heap, the speed 
 *                is not ideal.
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        std::priority_queue<int, vector<int>, std::greater<int>>q;
        int num;
        long last = 0;
        q.push(1);
        while(n && !q.empty()){
            num = q.top();
            q.pop();
            if (num!=last){
                if (num < INT_MAX / 2) q.push(num*2);
                if (num < INT_MAX / 3) q.push(num*3);
                if (num < INT_MAX / 5) q.push(num*5);
                last = num;
                n--;
            }
        }
        return last;
    }
};

/**
 * Second attemp: a bottom-up DP
 * Note: the three if's effectively deal with duplicates.
 */
class Solution {
public:
    int nthUglyNumber(int n) {
        int two = 0, three = 0, five = 0;
        vector<int> v(n);
        if (n==1) return 1;
        v[0]=1;
        for (int i = 1; i < n ; ++i){
            v[i] = min(min(v[two]*2, v[three]*3),v[five]*5);
            if (v[i]==v[two]*2) two++;
            if (v[i]==v[three]*3) three++;
            if (v[i]==v[five]*5) five++;
        }
        return v[n-1];
    }
};
