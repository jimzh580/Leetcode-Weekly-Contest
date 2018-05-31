# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master:
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """

class Solution:
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        while len(wordlist) > 1:
            match = {}
            for word in wordlist:#分析单词相似
                match[word] = defaultdict(int)
                for word2 in wordlist:
                    match[word][sum(1 for x, y in zip(word, word2) if x == y)] += 1

            best =  min(wordlist, key=lambda word: max(match[word][i] for i in range(7)))

            score = master.guess(best)
            #保留和匹配最相关的项
            wordlist = [word for word in wordlist if sum(1 for x, y in zip(word, best) if x == y) == score]
        master.guess(wordlist[0])