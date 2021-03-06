#
# [155] Min Stack
#
# https://leetcode.com/problems/min-stack/description/
#
# algorithms
# Easy (32.47%)
# Total Accepted:    206.2K
# Total Submissions: 635K
# Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
#
# 
# Design a stack that supports push, pop, top, and retrieving the minimum
# element in constant time.
# 
# 
# push(x) -- Push element x onto stack.
# 
# 
# pop() -- Removes the element on top of the stack.
# 
# 
# top() -- Get the top element.
# 
# 
# getMin() -- Retrieve the minimum element in the stack.
# 
# 
# 
# 
# Example:
# 
# MinStack minStack = new MinStack();
# minStack.push(-2);
# minStack.push(0);
# minStack.push(-3);
# minStack.getMin();   --> Returns -3.
# minStack.pop();
# minStack.top();      --> Returns 0.
# minStack.getMin();   --> Returns -2.
# 
# 
#
class MinStack:
    def __init__(self):
        self.__data = []
        self.__minList = []
    def push(self, x):
        self.__data.append(x)
        if self.__minList == []: self.__minList.append(x)
        elif x <= self.__minList[-1]: self.__minList.append(x)

    # @return nothing
    def pop(self):
        x = self.__data.pop()
        if self.__minList != [] and x == self.__minList[-1]:
            self.__minList.pop()

    # @return an integer
    def top(self):
        return self.__data[-1]

    # @return an integer
    def getMin(self):
        return self.__minList[-1]

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
