#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
using namespace std;

struct Password {
    string site;
    string pass;
};

vector<Password> vault;
string filename = "passwords.txt";

void load() {
    ifstream file(filename);
    Password p;
    while (file >> p.site >> p.pass) {
        vault.push_back(p);
    }
    file.close();
}

void save() {
    ofstream file(filename);
    for (Password p : vault) {
        file << p.site << " " << p.pass << endl;
    }
    file.close();
}

void add() {
    Password p;
    cout << "Сайт: ";
    cin >> p.site;
    cout << "Пароль: ";
    cin >> p.pass;
    vault.push_back(p);
    cout << "Готово!\n";
}

void show() {
    if (vault.empty()) {
        cout << "Нет записей.\n";
        return;
    }
    for (int i = 0; i < vault.size(); i++) {
        cout << i + 1 << ". " << vault[i].site << " - " << vault[i].pass << endl;
    }
}

void find() {
    string site;
    cout << "Сайт: ";
    cin >> site;
    for (Password p : vault) {
        if (p.site == site) {
            cout << "Пароль: " << p.pass << endl;
            return;
        }
    }
    cout << "Не найдено.\n";
}

void remove() {
    string site;
    cout << "Сайт: ";
    cin >> site;
    for (int i = 0; i < vault.size(); i++) {
        if (vault[i].site == site) {
            vault.erase(vault.begin() + i);
            cout << "Удалено.\n";
            return;
        }
    }
    cout << "Не найдено.\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    load();
    int choice;

    do {
        cout << "\n=== МЕНЕДЖЕР ПАРОЛЕЙ ===\n";
        cout << "1. Добавить\n";
        cout << "2. Показать все\n";
        cout << "3. Найти\n";
        cout << "4. Удалить\n";
        cout << "5. Выход\n";
        cout << "Выбери: ";
        cin >> choice;

        switch (choice) {
        case 1: add(); break;
        case 2: show(); break;
        case 3: find(); break;
        case 4: remove(); break;
        case 5: save(); cout << "Пока!\n"; break;
        default: cout << "Нет такого пункта.\n";
        }
    } while (choice != 5);

    return 0;
}