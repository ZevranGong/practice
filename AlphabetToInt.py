#Return a list of strings ordered by mapping alphabet to integer(a=1,b=2,etc.)
#List is in descending order
#Assuming only lower case alphabet a~z are used
#Breaking ties by lexicographical order, eg. bb>ac>aab
class Name(object):
    def __init__(self,name):
        self.name = name
        initial = 0
        for i in xrange(len(name)):
            initial+=ord(name[i])
        self.count = initial-(ord("a")-1)*len(name)
    
    def __cmp__(this, that):
        return cmp(this.count,that.count)
    
    def alphaCmp(self,this,that):
        return cmp(this.name, that.name)
        

def mySort(nameList,method):
    if len(nameList)<2:
        return nameList
    else:
        left=[]
        right=[]
        middle=[]
        head = nameList[0]
        if (method==""):
            for i in xrange(len(nameList)):
                if head<nameList[i]:
                    left+=[nameList[i]]
                elif head==nameList[i]:
                    middle+=[nameList[i]]
                else:
                    right+=[nameList[i]]
            return mySort(left,"")+mySort(middle,"alpha")+mySort(right,"")
        else:
            for i in xrange(len(nameList)):
                item = nameList[i]
                if (nameList[i].alphaCmp(head,item))==1:
                    right+=[nameList[i]]
                elif (nameList[i].alphaCmp(head,item))==0:
                    middle+=[nameList[i]]
                else:
                    left+=[nameList[i]]
            return left+middle+right

def answer(names):
    start = []
    res =[]
    for i in xrange(len(names)):
        start+=[Name(names[i])]
    middle = mySort(start,"")
    for i in xrange(len(middle)):
        res+=[middle[i].name]
    return res
