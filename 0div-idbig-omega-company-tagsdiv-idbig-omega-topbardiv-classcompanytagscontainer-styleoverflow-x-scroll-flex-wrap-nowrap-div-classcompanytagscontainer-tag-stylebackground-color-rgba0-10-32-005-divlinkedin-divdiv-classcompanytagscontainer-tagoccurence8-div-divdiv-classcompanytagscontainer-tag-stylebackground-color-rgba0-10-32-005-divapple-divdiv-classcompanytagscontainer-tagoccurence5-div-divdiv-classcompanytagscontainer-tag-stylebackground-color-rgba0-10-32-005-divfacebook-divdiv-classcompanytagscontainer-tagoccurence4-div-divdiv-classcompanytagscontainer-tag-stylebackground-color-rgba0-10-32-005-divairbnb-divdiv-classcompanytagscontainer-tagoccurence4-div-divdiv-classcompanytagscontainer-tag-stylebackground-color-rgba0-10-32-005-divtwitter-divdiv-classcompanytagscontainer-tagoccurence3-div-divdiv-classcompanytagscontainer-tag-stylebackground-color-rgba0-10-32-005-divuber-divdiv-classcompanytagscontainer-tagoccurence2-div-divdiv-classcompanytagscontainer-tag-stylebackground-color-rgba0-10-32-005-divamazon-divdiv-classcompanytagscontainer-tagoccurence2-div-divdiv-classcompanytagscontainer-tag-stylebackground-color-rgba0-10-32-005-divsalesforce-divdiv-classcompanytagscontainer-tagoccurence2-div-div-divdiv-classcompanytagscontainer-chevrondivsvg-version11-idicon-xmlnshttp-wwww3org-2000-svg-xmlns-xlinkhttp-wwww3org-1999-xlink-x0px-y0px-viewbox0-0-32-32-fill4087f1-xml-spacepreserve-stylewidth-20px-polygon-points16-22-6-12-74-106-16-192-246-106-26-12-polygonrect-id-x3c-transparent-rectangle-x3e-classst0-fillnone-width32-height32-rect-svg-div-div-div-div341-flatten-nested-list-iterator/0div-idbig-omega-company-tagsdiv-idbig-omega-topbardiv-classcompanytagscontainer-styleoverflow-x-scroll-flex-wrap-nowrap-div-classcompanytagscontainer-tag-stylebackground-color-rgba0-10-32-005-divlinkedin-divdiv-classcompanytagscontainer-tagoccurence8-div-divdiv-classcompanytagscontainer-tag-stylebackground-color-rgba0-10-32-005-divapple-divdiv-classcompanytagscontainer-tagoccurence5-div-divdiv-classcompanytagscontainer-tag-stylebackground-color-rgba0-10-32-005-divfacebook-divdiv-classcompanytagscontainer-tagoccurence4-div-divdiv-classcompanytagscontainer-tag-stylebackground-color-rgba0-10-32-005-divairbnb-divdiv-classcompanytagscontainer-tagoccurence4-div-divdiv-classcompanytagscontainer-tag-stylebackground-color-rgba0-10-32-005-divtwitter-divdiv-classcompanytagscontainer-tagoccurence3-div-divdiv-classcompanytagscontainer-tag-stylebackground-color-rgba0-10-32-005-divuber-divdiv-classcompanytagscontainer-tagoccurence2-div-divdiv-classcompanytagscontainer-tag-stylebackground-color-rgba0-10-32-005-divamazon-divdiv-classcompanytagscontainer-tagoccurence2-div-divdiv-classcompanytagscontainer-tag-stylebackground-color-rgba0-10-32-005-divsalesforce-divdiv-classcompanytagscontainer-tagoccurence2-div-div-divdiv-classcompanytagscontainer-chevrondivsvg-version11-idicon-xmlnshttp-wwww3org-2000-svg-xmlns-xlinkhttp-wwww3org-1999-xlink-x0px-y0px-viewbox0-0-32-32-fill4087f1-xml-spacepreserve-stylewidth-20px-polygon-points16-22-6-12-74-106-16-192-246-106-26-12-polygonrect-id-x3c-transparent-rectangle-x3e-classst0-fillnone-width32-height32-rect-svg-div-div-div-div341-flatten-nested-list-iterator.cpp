/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    private:
    stack<NestedInteger> stack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
      for (int i = nestedList.size() - 1; i >= 0; --i) {
            stack.push(nestedList[i]);
      }   
    }
    
    int next() {
       hasNext();
        int result = stack.top().getInteger();
        stack.pop();
        return result;  
    }
    
    bool hasNext() {
       while (!stack.empty() && !stack.top().isInteger()) {
            vector<NestedInteger> nestedList = stack.top().getList();
            stack.pop();
            for (int i = nestedList.size() - 1; i >= 0; --i) {
                stack.push(nestedList[i]);
            }
        }
        return !stack.empty();  
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */