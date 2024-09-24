#pragma once
#include <iostream>
#include <fstream>
#include <string>

void loadBooks();
void saveBooks();
void addBook(const std::string& title, const std::string& author, const std::string& date);
void editBook(int index);
void displayBooks();
void searchBooksByDate(const std::string& searchDate);