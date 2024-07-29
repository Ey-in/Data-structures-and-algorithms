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

        t = 0; // ���� t Ϊ��ǰ������������

        for (int order = 1; order <= h * l; order++)
        {
            bool found = false;  // ��־λ
            for (int i = 1; i <= h && !found; i++)
            {
                for (int j = 1; j <= l && !found; j++)
                {
                    if (m[i][j] == order)
                    {
                        found = true;  // �ҵ�Ŀ�공�����˳���ѭ��
                        
                        // ���������������ʱ��
                        t += (i - 1) * 20;

                        // ���㴫�ʹ��ƶ�����ʱ��
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

                        // ȡ�����������
                        m[i][j] = -1;
                      
                        // ���¾���ģ�⴫�ʹ��ƶ�
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
