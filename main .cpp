#include <iostream>
#include <string>
using namespace std;

int main()
{
    int gold, a = 0;
    char* result = new char[1000000];
    int Price[2][9];
    cin >> gold;

    //заполнение
    for (int i = 0; i < 9; i++) {
        cin >> Price[0][i];
        Price[1][i] = i + 1;
    }

    //сортировка
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8 - i; ++j)
        {
            if (Price[0][j] > Price[0][j + 1])
            {
                swap(Price[0][j], Price[0][j + 1]);
                swap(Price[1][j], Price[1][j + 1]);
            }
        }
    }

    //проверка на возможность одной цифры
    if (!(gold >= Price[0][0]))
    {
        cout << -1;
        exit(0);
    }

    int nums = 0;
    while (Price[0][nums] == Price[0][nums + 1] && nums <8 )
    {
        nums++;
    }

    result[a++] = static_cast<char>(Price[1][nums] + 48);
    gold -= Price[0][nums];

    int counter = 1;
    while (gold - Price[0][nums] >= 0)
    {
        result[a++] = static_cast<char>(Price[1][nums] + 48);
        gold -= Price[0][nums];
        counter++;
    }

    int zamena=0;
    int k = nums;
    while (gold > 0 && zamena<counter)
    {
        gold += Price[0][int(result[zamena])-49];

        if (zamena)
            k=0;

        while (gold >= Price[0][k] && k < 9)
        {
            if(k)
            {
                if(gold<Price[0][k+1])
                    if(!(Price[1][k]>Price[1][k-1]))
                    {
                        break;
                    }
            }
            k++;
        }

        if (Price[1][nums] > Price[1][k-1])
        {
            cout << result;
            exit(0);
        }


        if (Price[1][nums] < Price[1][k])
        {
            result[zamena] = static_cast<char>(Price[1][k - 1]+48);
            zamena++;
            gold-=Price[0][k-1];
        }
    }

    cout << result<<endl;

    return 0;
}



