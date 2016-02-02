#Scan the list to find the highest past data
def scan(l):
    high = 0
    res =[]
    for i in xrange(len(l)):
        if high<l[i]:
            high=l[i]
        res+=[high]
    return res

#main function for solution 
def answer(heights):
    leftHigh = scan(heights)
    revHeights = heights[::-1] #reverse array
    rightHigh = scan(revHeights)
    res =0
    for i in xrange(len(heights)):
        res+=min(leftHigh[i],rightHigh[len(heights)-1-i])-heights[i]
    return res
