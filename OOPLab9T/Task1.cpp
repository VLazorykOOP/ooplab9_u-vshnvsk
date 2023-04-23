/*STL7Mix3. Вихідна послідовність містить відомості про клієнтів фітнес-центру. 
Кожен елемент послідовності включає такі цілі поля:
<Рік> <Номер місяця> <Тривалість занять(У годинах)> <Код клієнта>
Визначити рік, у якому сумарна тривалість занять всіх клієнтів була найбільшою, і вивести цей рік
та найбільшу сумарну тривалість. 
Якщо таких років було кілька, то вивести найменший із них.
Вказівка. Порівн. із STL7Mix1(Використовуйте алгоритм max_element з предикатом). 
Для угруповання по полю «рік» використовуйте допоміжне відображення.*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    ifstream file;
    file.open("STL7Mix3.txt");

    map<int, int> durationByYear;

    int year, month, hour, id;
    if (!file.is_open())
    {
        cout << "Sorry, but file is not open(";
    } 

    cout << "Year Month Hour Id" << endl;
    while (file >> year >> month >> hour >> id)
    {
        durationByYear[year] += hour;
        cout << year << ' ' << month << ' ' << hour << ' ' << id << endl;
    }
    file.close();

    auto maxDurationByYear = max_element(durationByYear.begin(), durationByYear.end(), 
         [](const pair<int, int>& a, const pair<int, int>& b)
         {
            return a.second < b.second;
         });
    
    ofstream out;
    out.open("STL7Mix3_result.txt", ios::app);
    
    out << "The year with the highest total duration is " << maxDurationByYear->first
         << " with a total duration of " << maxDurationByYear->second << endl;
    
    out.close();

    cout << "The year with the highest total duration is " << maxDurationByYear->first
         << " with a total duration of " << maxDurationByYear->second << endl;

    return 0;
}