using System;
using System.Collections.Generic;

public class Solution {
    private long[,] memo;
    private int[] robots;
    private int[][] factories;

    public long MinimumTotalDistance(IList<int> robot, int[][] factory) {
        robots = new int[robot.Count];
        robot.CopyTo(robots, 0);
        Array.Sort(robots);

        factories = (int[][])factory.Clone();
        Array.Sort(factories, (a, b) => a[0].CompareTo(b[0]));

        int n = robots.Length;
        int m = factories.Length;

        memo = new long[n + 1, m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                memo[i, j] = -1;
            }
        }

        return Dfs(0, 0);
    }

    private long Dfs(int i, int j) {
        if (i == robots.Length) return 0;           // all robots repaired
        if (j == factories.Length) return long.MaxValue / 2; // impossible (but won't happen)

        if (memo[i, j] != -1) return memo[i, j];

        // Option 1: Skip this factory
        long ans = Dfs(i, j + 1);

        // Option 2: Use this factory for 1 to limit robots (consecutive)
        long cost = 0;
        int limit = factories[j][1];
        int pos = factories[j][0];

        for (int k = 0; k < limit && i + k < robots.Length; k++) {
            cost += Math.Abs((long)robots[i + k] - pos);
            long next = Dfs(i + k + 1, j + 1);
            if (next != long.MaxValue / 2) {
                ans = Math.Min(ans, cost + next);
            }
        }

        memo[i, j] = ans;
        return ans;
    }
}