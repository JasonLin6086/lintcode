/*
@Copyright:LintCode
@Author:   jerhaulin
@Problem:  http://www.lintcode.com/problem/submatrix-sum
@Language: Java
@Datetime: 15-09-28 23:42
*/

public class Solution {
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    public int[][] submatrixSum(int[][] matrix) {
        // Write your code here
        int[][] result = new int[2][2];
        int M = matrix.length;
        if (M == 0) return result;
        int N = matrix[0].length;
        if (N == 0) return result;
        // pre-compute: sum[i][j] = sum of submatrix [(0, 0), (i, j)]
        int[][] sum = new int[M+1][N+1];
        for (int j=0; j<=N; ++j) sum[0][j] = 0;
        for (int i=1; i<=M; ++i) sum[i][0] = 0;
        for (int i=0; i<M; ++i) {
            for (int j=0; j<N; ++j)
                sum[i+1][j+1] = matrix[i][j] + sum[i+1][j] + sum[i][j+1] - sum[i][j];
        }
        for (int l=0; l<M; ++l) {
            for (int h=l+1; h<=M; ++h) {
                Map<Integer, Integer> map = new HashMap<Integer, Integer>();
                for (int j=0; j<=N; ++j) {
                    int diff = sum[h][j] - sum[l][j];
                    if (map.containsKey(diff)) {
                        int k = map.get(diff);
                        result[0][0] = l;   result[0][1] = k;
                        result[1][0] = h-1; result[1][1] = j-1;
                        return result;
                    } else {
                        map.put(diff, j);
                    }
                }
            }
        }
        return result;
    }
}
