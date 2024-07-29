#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

const int N = 51;
int n;
int h, l;
int m[N][N];
int t;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &h, &l);
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= l; j++)
            {
                scanf("%d", &m[i][j]);
            }

        t = 0; // 重置 t 为当前测试用例清零

        for (int order = 1; order <= h * l; order++)
        {
            bool found = false;  // 标志位
            for (int i = 1; i <= h && !found; i++)
            {
                for (int j = 1; j <= l && !found; j++)
                {
                    if (m[i][j] == order)
                    {
                        found = true;  // 找到目标车辆，退出内循环
                        
                        // 计算电梯上下所需时间
                        t += (i - 1) * 20;

                        // 计算传送带移动所需时间
                        int left_shift = j - 1;
                        int right_shift = l - j + 1;

                        if (left_shift <= right_shift)
                        {
                            t += left_shift * 5;
                        }
                        else
                        {
                            t += right_shift * 5;
                        }

                        // 取出车辆并标记
                        m[i][j] = -1;
                      
                        // 更新矩阵，模拟传送带移动
                        int new_row[N];
                        for (int y = 1; y <= l; y++)
                        {
                            if (left_shift <= right_shift)
                            {
                                new_row[y] = m[i][(y + left_shift - 1) % l + 1];
                            }
                            else
                            {
                                new_row[y] = m[i][(y - right_shift - 1 + l) % l + 1];
                            }
                        }
                        for (int y = 1; y <= l; y++)
                        {
                            m[i][y] = new_row[y];
                        }
                    }
                }
            }
        }

        cout << t << endl;
    }

    return 0;
}
