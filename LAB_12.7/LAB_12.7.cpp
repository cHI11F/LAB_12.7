#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура елемента списку
struct Textbook {
    string author;
    string title;
    int approvalReviews;
    Textbook* next;
};

// Функція для додавання елемента в кінець списку
void appendToList(Textbook*& head, string author, string title, int approvalReviews) {
    Textbook* newNode = new Textbook;
    newNode->author = author;
    newNode->title = title;
    newNode->approvalReviews = approvalReviews;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Textbook* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Функція для виведення списку на екран
void printList(Textbook* head) {
    Textbook* current = head;
    while (current != nullptr) {
        cout << "Author: " << current->author << ", Title: " << current->title << ", Approval Reviews: " << current->approvalReviews << endl;
        current = current->next;
    }
}

// Функція для створення нового списку на основі критерію кількості схвальних відгуків
Textbook* createRecommendedList(Textbook* head, int threshold) {
    Textbook* recommendedHead = nullptr;
    Textbook* current = head;

    while (current != nullptr) {
        if (current->approvalReviews >= threshold) {
            appendToList(recommendedHead, current->author, current->title, current->approvalReviews);
        }
        current = current->next;
    }

    return recommendedHead;
}

// Функція для виведення списку на екран
void printList(Textbook* head, string listName) {
    cout << "=== " << listName << " List ===" << endl;
    printList(head);
    cout << endl;
}

// Функція для звільнення пам'яті, що використовується списком
void freeList(Textbook*& head) {
    while (head != nullptr) {
        Textbook* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Textbook* textbooks = nullptr; // Голова вихідного списку
    Textbook* recommendedTextbooks = nullptr; // Голова списку рекомендованих підручників

    // Зчитування даних з файлу або введення з клавіатури
    // Приклад зчитування з клавіатури:
    // Прізвище_Автора Назва_Підручника Кількість_Схвальних_Відгуків
    // При завершенні введення введіть "end"
    string author, title;
    int approvalReviews;
    cout << "Enter author, title and approval reviews (separated by spaces), type 'end' to finish input:\n";
    while (cin >> author && author != "end") {
        cin >> title >> approvalReviews;
        appendToList(textbooks, author, title, approvalReviews);
    }

    // Виведення вихідного списку
    printList(textbooks, "Original");

    // Запит користувача на критерій кількості схвальних відгуків
    int threshold;
    cout << "Enter the threshold for approval reviews: ";
    cin >> threshold;

    // Формування списку рекомендованих підручників
    recommendedTextbooks = createRecommendedList(textbooks, threshold);

    // Виведення рекомендованого списку
    printList(recommendedTextbooks, "Recommended");

    // Звільнення пам'яті, що використовується списками
    freeList(textbooks);
    freeList(recommendedTextbooks);

    return 0;
}
