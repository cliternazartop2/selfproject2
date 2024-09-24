#include <iostream>
#include <fstream>
#include <string>
#include "staryblox.h"

int main() {
    setlocale(LC_ALL, "rus");
    loadBooks();
    int choice;

    do {
        std::cout << "ИНВЕНТАРИЗАЦИЯ КНИЖНОГО МАГАЗИНА" << std::endl;
        std::cout << "1. Добавить книгу" << std::endl;
        std::cout << "2. Отредактировать книгу" << std::endl;
        std::cout << "3. Показать книги" << std::endl;
        std::cout << "4. найти книгу по дате" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string title, author, date;
            std::cout << "Введите заголовок: ";
            std::getline(std::cin, title);
            std::cout << "Введите автора: ";
            std::getline(std::cin, author);
            std::cout << "Введите дату: ";
            std::getline(std::cin, date);
            addBook(title, author, date);
        }
        else if (choice == 2) {
            int index;
            std::cout << "Введите номер книги для редактирования: ";
            std::cin >> index;
            std::cin.ignore();
            editBook(index - 1);
        }
        else if (choice == 3) {
            displayBooks();
        }
        else if (choice == 4) {
            std::string choice1;
            std::cin >> choice1;
            searchBooksByDate(choice1);
        }
        else if (choice > 4) {
            std::cout << "неправильный ввод" << std::endl;
        }
    } while (choice != 0);

    return 0;
}