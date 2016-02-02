class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        #Number of leaves is one more than non-leaf nodes
        #Since pre-order, the number of non-leaf nodes should be at least as leaf nodes until the last node
        leafNum = 1 # #s of leaves needed
        for val in preorder.split(","):
            if leafNum == 0: #pre-exit
                return False
            if val == "#":
                leafNum-=1
            else:
                leafNum+=1
        return (leafNum==0)
