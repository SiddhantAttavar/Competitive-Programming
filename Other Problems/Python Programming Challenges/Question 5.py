class Solution:

    def __init__(self):
        self.string = ''

    def getString(self):
        self.string = input()
    
    def printString(self):
        print(self.string)

solution = Solution()
solution.getString()
solution.printString()