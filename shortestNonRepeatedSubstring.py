def memoize(f):
    memo={}
    def helper(x):
        if x not in memo:
            memo[x]=f(x)
        return memo[x]
    return helper



def test(chunk,word):
    return helper((chunk,word))

@memoize
def helper(tup):
    chunk=tup[0]
    word=tup[1]
    l=[]
    minC = 20
    raw=[]
    if word in chunk:
        idx=0
        wordlen = len(word)
        for i in xrange(len(chunk)):
            if chunk[i:i+wordlen]==word:
                temp = chunk[:i]+chunk[i+wordlen:]
                one =helper((temp,word))
                l+=[one]
        #Find the shortest non-repeated substring
        for i in xrange(len(l)):
            if len(l[i]) < minC:
                minC=len(l[i])
        #if several have same length, use alphabetical order
        for i in xrange(len(l)):
            if len(l[i])==minC:
                raw+=[l[i]]
        res = sorted(raw)
        return res[0]
    return chunk
                
                
        
    
                
    
    
        
