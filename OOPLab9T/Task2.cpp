/*STL3Alg3. Дано список L. Видалити перший і останній нульовий елемент списку. 
Якщо нульових елементів немає, список не змінювати, якщо нульовий елемент лише один, то видалити
тільки його. 
Використовувати два виклики алгоритму find та два виклик функції-члена Erase.
Вказівка. Наявні в класі list функція-член remove у даному випадку використовувати не можна, 
тому що вона видаляє всі елементи із певним значенням.*/
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    list<int> L = {0, 3, 6, 7, 0, 3, 1, 10, 0};

    auto firstZero = find(L.begin(), L.end(), 0);
    auto lastZero = find(L.rbegin(), L.rend(), 0);

    if(firstZero != L.end())
    {
        if(lastZero.base() != firstZero)
        {
            L.erase(firstZero);
            L.erase(prev(lastZero.base()));
        } 
        else 
        {
            L.erase(firstZero);
        }
    }

    for(auto &elem : L)
    {
        cout << elem << ' ';
    }
    return 0;
}