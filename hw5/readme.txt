學號：406315017
系級：心理四
姓名：鄧智宇
作業概述：
For this homework, I use an adjacent array to represent a graph, 
and "all pairs shotest-path(solution 2)" to find out the minimum path.

First, we use a 2-d char array to represent names we input.
And then an adjacent array is used for the indirect graph.
If there is an edge from s to d, we put the weight into (d,s) and (s,d)

Now,it is the way we find a shortest path from one point to every other one.
At first, we use an array to record the last intermediate vertex of the shortest path form i to j.
And then convert the adjacent arrayof the graph to the shortest path array, 
which's (i,j) means the shortest path from i to j, without go through any other point.
We use "for" loop to find out the shortest paths.
Let the kth  a(i,j) represent the shortest path length, but it can only pass 1~k.
Determin  the smaller of "the length of the path from i to j through k" and 
"the length of the path from i to j without k", 
record it in a(i,j),and record the last intermediate point passed.

Calculate the sum of the shortest path from each point to each point, find the smallest one
Print  out the relevant information of that point, finally we got answer.