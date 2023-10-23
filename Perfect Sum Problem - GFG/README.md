# Perfect Sum Problem
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr</strong>&nbsp;of non-negative integers and an integer <strong>sum</strong>, the task is to count&nbsp;all subsets of the given array with a sum equal to a given <strong>sum</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> Answer can be very large, so, output answer modulo <strong>10<sup>9</sup>+7</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: <br>N = 6<br>arr = [5, 2, 3, 10, 6, 8]
sum = 10
<strong>Output:</strong> <br>3</span>
<span style="font-size: 18px;"><strong>Explanation</strong>: <br>{5, 2, 3}, {2, 8}, {10} are possible subsets.</span></pre>
<div><span style="font-size: 18px;"><strong>Example 2:</strong></span></div>
<pre><span style="font-size: 18px;"><strong>Input</strong>: <br>N = 5<br>arr = [2, 5, 1, 4, 3]
sum = 10
<strong>Output:</strong> <br>3</span>
<span style="font-size: 18px;"><strong>Explanation</strong>: <br>{2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.</span></pre>
<div><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Complete the function <strong><code>perfectSum</code>()&nbsp;</strong>which takes <strong>N, </strong>array<strong> arr</strong>&nbsp;and <strong>sum </strong>as input parameters and returns an integer value.</span></div>
<div><span style="font-size: 18px;"><strong><br>Expected Time Complexity:</strong> O(N*sum)<br><strong>Expected Auxiliary Space:</strong> O(N*sum)<br><strong><br>Constraints:</strong><br>1 ≤ N*sum ≤ 10<sup>6</sup></span></div>
<div><span style="font-size: 18px;">0 ≤ arr[i] ≤&nbsp;10<sup>6</sup></span></div></div>