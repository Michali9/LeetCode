class Solution(object):
    
    def gcdOfStrings(self, str1, str2):
        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
        if(len(str1) > len(str2)):
            strmin = str2
            strmax = str1
        else:
            strmin = str1
            strmax = str2

        gcd = Solution().maybeGcd(strmin)
        if(gcd == ""):
            return ""
        temp = (gcd * (len(strmax) / len(gcd)))
        if(temp == strmax):
            return gcd
        else:
            return ""

    def maybeGcd(self, strmin, i=1):
        if(i >= len(strmin)):
            return ""
        gcd = ""
        gcd += strmin[i-1]
        tmp = (gcd * (len(strmin) / i))
        if(tmp == strmin):  
            return gcd
        else:
            return self.maybeGcd(strmin, i+1)
