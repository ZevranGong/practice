#Calculate the minimum numbers required whose square sum is equal to a given
#number using DP and memoization in Python

def memoize(f):
    memo={}
    end = 101
    for i in xrange(end):
        memo[i**2] = 1
    def helper(x):
        if x not in memo:
            memo[x]=f(x)
        return memo[x]
    return helper

@memoize
def answer(n):
    temp=[]
    if n==2:
        return 2
    elif n==3:
        return 3
    else:
        largestNumber = int(n**.5)
        for i in range(largestNumber-1,0,-1):
            if (n-i**2 == 0):
                return 1
            temp += [answer(n-i**2)]
        return 1+min(temp)
