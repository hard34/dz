#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

void sort(int* a, int n)
{
    int a1, b1, a2, b2;
    bool chk;
    for (int j = 1; j < n - 1; ++j)
    {
        do {
            chk = false;
            for (int i = j; i >= 1; --i)
            {
                if (a[i][j - i] < a[i - 1][j - (i - 1)])
                {
                    swap(a[i][j - i], a[i - 1][j - (i - 1)]);
                    chk = true;
                }
            }
        } while (chk);
    }

    for (int j = 1; j < n; ++j)
    {
        do {
            chk = false;
            for (int i = j; i >= 1; --i)
            {
                a1 = n - 1 - j + (i - 1);
                b1 = n - 1 - (i - 1);

                a2 = n - 1 - j + i;
                b2 = n - 1 - i;
                if (a[a1][b1] > a[a2][b2])
                {
                    swap(a[a1][b1], a[a2][b2]);
                    chk = true;
                }
            }
        } while (chk);
    }
}

int main(void)
{
    int n, m, i, j,
        int a[8][8];
    cin >> n >> m;
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j)
            cin >> a[i][j];
    //сортируем
    sort(a);

    //выводим
    cout << n << "\t" << m << "\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << setw(5) << a[i][j];
        cout << "\n";
    }
    in.close(); out.close();
    return 0;
}