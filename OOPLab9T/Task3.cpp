/*STL5Assoc3. Даний вектор V0, ціле число N (> 0) і набір векторів V1, …, VN. 
Відомо, що розмір вектора V0 не перевищує розміру будь-якого з векторів V1, …, VN. 
Знайти кількість векторів VI, I = 1, …, N, у яких містяться всі елементи вектора V0 
(з урахуванням їх повторень). 
Використати алгоритм includes, застосовуючи його в циклі до двох мультимножеств 
(контейнерів типу multiset), одне з яких створено на основі вектора V0, а інше на черговій ітерації
містить елементи чергового з векторів VI, I = 1, …, N.*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v0 = {1, 2, 3};
    int N = 3, count = 0;
    vector<vector<int>> vN = {{1, 2, 3}, {2, 1, 3}, {2, 6, 0}};

    multiset<int> set1(v0.begin(), v0.end());

    for(int i = 0; i < N; i++)
    {
        multiset<int> set2(vN[i].begin(), vN[i].end());

        if(includes(set2.begin(), set2.end(), set1.begin(), set1.end()))
        { 
            count++;
        }
    }

    cout << count << endl;

    return 0;
}