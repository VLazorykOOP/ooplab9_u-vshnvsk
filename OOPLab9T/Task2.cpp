/*STL3Alg3. Дано список L. Видалити перший і останній нульовий елемент списку. 
Якщо нульових елементів немає, список не змінювати, якщо нульовий елемент лише один, то видалити
тільки його. 
Використовувати два виклики алгоритму find та два виклик функції-члена Erase.
Вказівка. Наявні в класі list функція-член remove у даному випадку використовувати не можна, 
тому що вона видаляє всі елементи із певним значенням.*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() 
{
    list<int> L = {0, 1, 2, 3, 0, 4, 5, 0};

    auto first_zero = find(L.begin(), L.end(), 0);
    if (first_zero != L.end()) {
        L.erase(first_zero);
    }

    auto last_zero = find(L.rbegin(), L.rend(), 0);
    if (last_zero != L.rend()) {
        L.erase(next(last_zero).base());
    }

    auto only_zero = find(L.begin(), L.end(), 0);
    if (only_zero != L.end() && next(only_zero) == L.end()) {
        L.erase(only_zero);
    }

    for (int x : L) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}