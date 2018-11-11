class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        let = sorted([x for x in logs if not x.split()[1].isdigit()], key=lambda x: x.split()[1:])
        dig = [x for x in logs if x.split()[1].isdigit()]
        return let + dig