#include <iostream>
#include <string>

using namespace std;

struct Tourist {
    string surname;
    string name;
    int age;
    char gender;
};

int main() {

    setlocale(LC_ALL,"rus");
    int n=35;

    Tourist group[n];

    cout << "Введите информацию о 35ти туристах (фамилия, имя, возраст, пол - м/ж) " << endl;
    for (int i = 0; i<n; i++){
        cout << "Турист № " << i+1 << ": ";
        cin >> group[i].surname >> group[i].name >> group[i].age >> group[i].gender; 
    }

    int count_male = 0;
    int sum_age_male = 0;
    int min_age_male = 1000;
    int max_age_male = 0;

    int index_max_age = 0;
    int index_min_age = 0;

    for (int i=0; i<n; i++){
        if (group[i].gender == 'М' || group[i].gender == 'м'){
            count_male++;
            sum_age_male += group[i].age;

            if (group[i].age < min_age_male){
                min_age_male = group[i].age;
                index_min_age = i;
            }

            if (group[i].age > max_age_male){
                max_age_male = group[i].age;
                index_max_age = i;
            }
        }
    }

    cout << "Количество мужчин: " << count_male << endl;

    if (count_male > 0){
        cout << "Средний возраст мужчин: " << sum_age_male/count_male << endl;

        cout << "Самый младший мужчина: " << group[index_min_age].surname << " " << group[index_min_age].name << ", возраст: " << group[index_min_age].age << endl;

        cout << "Самый старший мужчина: " << group[index_max_age].surname << " " << group[index_max_age].name << ", возраст: " << group[index_max_age].age << endl;
    } else {
        cout << "Отсутсвуют мужчины в группе!" << endl;
    }
    for (int i=0; i<n; i++){
        cout << group[i].name << endl;
    }



    return 0;
}
