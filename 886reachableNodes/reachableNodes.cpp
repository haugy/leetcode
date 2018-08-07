/*===========================================
*    
*    leetcode for Weekly Contest 96
*    
*    Created by Haugy on 07/08/2018
*    Copyright (c) 2018 Haugy. All right reserved.
*    
*===========================================*/

/*886细分图中的可到达结点
从具有 0 到 N-1 的结点的无向图（“原始图”）开始，对一些边进行细分。

该图给出如下：edges[k] 是整数对 (i, j, n) 组成的列表，使 (i, j) 是原始图的边。

n 是该边上新结点的总数

然后，将边 (i, j) 从原始图中删除，将 n 个新结点 (x_1, x_2, ..., x_n) 添加到原始图中，

将 n+1 条新边 (i, x_1), (x_1, x_2), (x_2, x_3), ..., (x_{n-1}, x_n), (x_n, j) 添加到原始图中。

现在，你将从原始图中的结点 0 处出发，并且每次移动，你都将沿着一条边行进。

返回最多 M 次移动可以达到的结点数。

示例：
输入：edges = [[0,1,10],[0,2,1],[1,2,2]], M = 6, N = 3
输出：13

解释：输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], M = 10, N = 4
输出：23

提示：

    0 <= edges.length <= 10000
    0 <= edges[i][0] < edges[i][1] < N
    不存在任何 i != j 情况下 edges[i][0] == edges[j][0] 且 edges[i][1] == edges[j][1].
    原始图没有平行的边。
    0 <= edges[i][2] <= 10000
    0 <= M <= 10^9
    1 <= N <= 3000

*/

int reachableNodes(int** edges, int edgesRowSize, int *edgesColSizes, int M, int N) {
    int x_y[N][N];
    //init x_y N*N
    for (int m = 0; m < N; m++) {
        for (int n = 0; n < N; n++) {
            if (m == n) {
                x_y[m][n] = 0;
            }
            else {
                x_y[m][n] = 1;
            }
        }
    }
    for (int i = 0; i < edgesRowSize; i++) {
        int p0 = edges[i][0];
        int p1 = edges[i][1];
        //
        x_y[p0][p1] = edges[i][2] + 1;
        x_y[p1][p0] = edges[i][2] + 1;
    }
    
    //0 -> p len
    int num = 1;
    //while (num < N) {
        for (int i = num; i < N; i++) {
            int len = 0;//x_y[n][n - 1];
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                len = x_y[i][num - 1] + x_y[i][j];
                if (len < x_y[num - 1][j]) {
                    x_y[num - 1][j] = len;
                    x_y[j][num - 1] = len;
                }
            }
        }
       // num++;
    //}
    
    //0到两端点的距离l
    //2M - l > edges[row][2]则该线段的点能全部到达,否则有edges[row][2] - (2M - l)个点未能到达
    int sum_p = N;//总点数初始为N
    int unsum_p = 0;//未经过点数
    int l = 0;
    for (int row = 0; row < edgesRowSize; row++) {
        int p0 = edges[row][0];
        int p1 = edges[row][1];
        sum_p += edges[row][2];
        l = x_y[0][p0] + x_y[0][p1];//0到两端点距离
        if ((2 * M - l) > edges[row][2]) {
            continue;
        }
        else {
            unsum_p += edges[row][2] - (2 * M - l);
        }
    }
    
    return sum_p - unsum_p;

}
