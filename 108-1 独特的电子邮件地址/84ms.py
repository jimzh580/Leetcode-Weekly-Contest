class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        def change(s):
            a,b=s.split('@')
            c=''
            for i in a:
                if i!='.' and i!='+':
                    c+=i
                elif i=='+':
                    break
            return c+'@'+b
        
        d=set()
        for i in emails:
            d.add(change(i))
            
        return len(d)