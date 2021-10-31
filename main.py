class Solution:
   def solve(self, friends):
      nodes = len(friends)
      visited = [False for _ in range(nodes)]
      ans = 0
      def dfs(vertex, visited): visited[vertex] = True
         for nei in friends[vertex]:
            if not visited[nei]:
               dfs(nei, visited)
      for i in range(nodes):
         if not visited[i]:
            dfs(i, visited)
            ans += 1
      return ans
ob = Solution()
friends = [ [0, 1, 5], [1, 0], [2], [3, 4], [4, 3], [5, 0] ]
print(ob.solve(friends))