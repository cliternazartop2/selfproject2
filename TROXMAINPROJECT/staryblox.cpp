#include "staryblox.h"
#include <iostream>
#include <fstream>
#include <string>
const int MAX_BOOKS = 100; // ������������ ���������� ����
const std::string FILENAME = "starybox.txt"; // ��� ����� � �������

struct Book {
    std::string title;
    std::string author;
    std::string date;
};

Book books[MAX_BOOKS]; // ������ ����
int bookCount = 0; // ������� ����

void loadBooks() {
    std::ifstream file(FILENAME);
    if (file.is_open()) {
        while (file.good() && bookCount < MAX_BOOKS) {
            std::getline(file, books[bookCount].title);
            std::getline(file, books[bookCount].author);
            std::getline(file, books[bookCount].date);
            if (!books[bookCount].title.empty()) {
                bookCount++;
            }
        }
        file.close();
    }
    else {
        std::cerr << "������ ��� �������� �����!" << std::endl;
    }
}

void saveBooks() {
    std::ofstream file(FILENAME);
    if (file.is_open()) {
        for (int i = 0; i < bookCount; ++i) {
            file << books[i].title << std::endl;
            file << books[i].author << std::endl;
            file << books[i].date << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "������ ��� �������� �����!" << std::endl;
    }
}

void addBook(const std::string& title, const std::string& author, const std::string& date) {
    if (bookCount < MAX_BOOKS) {
        books[bookCount].title = title;
        books[bookCount].author = author;
        books[bookCount].date = date;
        bookCount++;
        saveBooks();
    }
    else {
        std::cerr << "���������� ������������ ���������� ����!" << std::endl;
    }
}

void editBook(int index) {
    if (index >= 0 && index < bookCount) {
        std::string newTitle, newAuthor, newDate;
        std::cout << "������� ����� ������ ��� ����� " << (index + 1) << ":" << std::endl;

        std::cout << "����� ���������: ";
        std::getline(std::cin, newTitle);
        std::cout << "����� �����: ";
        std::getline(std::cin, newAuthor);
        std::cout << "����� ����: ";
        std::getline(std::cin, newDate);

        books[index].title = newTitle;
        books[index].author = newAuthor;
        books[index].date = newDate;

        saveBooks(); // ��������� ��������� � ����
        std::cout << "����� ���������������!" << std::endl;
    }
    else {
        std::cerr << "������������ ����� �����!" << std::endl;
    }
}

void displayBooks() {
    for (int i = 0; i < bookCount; ++i) {
        std::cout << "����� " << (i + 1) << ":" << std::endl;
        std::cout << "���������: " << books[i].title << std::endl;
        std::cout << "�����: " << books[i].author << std::endl;
        std::cout << "���� �������: " << books[i].date << std::endl;
        std::cout << std::endl;
    }
}
void searchBooksByDate(const std::string& searchDate) {
    bool found = false;
    for (int i = 0; i < bookCount; ++i) {
        if (books[i].date == searchDate) {
            std::cout << "������� �����: #" << i + 1 << std::endl; // ������� ����� (������ + 1)
            std::cout << "��������: " << books[i].title << std::endl;
            std::cout << "�����: " << books[i].author << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "����� � ��������� ����� �� �������." << std::endl;
    }
}