class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        addr=set()
        for s in emails:
            name,domain=s.split('@')
            name=name.replace('.','').split('+')[0]
            addr.add(name+'@'+domain)
        return len(addr)