#include <iostream>
#include <regex>
#include <fstream>
#include <string>

using namespace std;

// Регулярные выражения. Лабораторая 3. Вариант 1: В программу передается текст из файла. В этом тексте должно быть подсчитано количество прилагательных, наречий и глаголов.
int main()
{
    setlocale(LC_ALL, "Russian");
    ifstream file("lab_3.txt");
    if (!file) {
        cout << "Не удалось открыть файл.\n";
        return 1;
    }

    string text((istreambuf_iterator<char>(file)), {});

    cout << "Исходный текст из файла:\n" << text << endl;

    // Регулярное выражение для поиска прилагательных 
    regex adjectives(R"([А-Яа-яЁё]+(ый|ий|ая|ое|ые|ую|их))", regex::icase);

    // Регулярное выражение для поиска наречий
    regex adverbs(R"((?:^|[\s.,!?])[А-Яа-яЁё]{3,}(о|е)(?=[\s.,!?]|$))", regex::icase);

    // Регулярное выражение для поиска глаголов
    regex verbs(R"((?:^|[\s.,!?])[А-Яа-яЁё]{3,}(ть|ет|ешь|л|ла|ют|им|ите|ил|или|ли|ем|ется|ться)(?=[\s.,!?]|$))", regex::icase);

    int adj_count = distance(
        sregex_iterator(text.begin(), text.end(), adjectives),
        sregex_iterator()
    );

    int adv_count = distance(
        sregex_iterator(text.begin(), text.end(), adverbs),
        sregex_iterator()
    );

    int verb_count = distance(
        sregex_iterator(text.begin(), text.end(), verbs),
        sregex_iterator()
    );

    cout << "Количество прилагательных: " << adj_count << "\nКоличество наречий: " << adv_count << "\nКоличество глаголов: " << verb_count << endl;

    return 0;
}
