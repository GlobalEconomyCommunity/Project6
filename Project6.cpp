#include <iostream>
#include <memory>
#include <stdexcept> // Для std::out_of_range

template <typename T>
class Node {
public:
    T data;                        // Данные узла
    std::shared_ptr<Node<T>> next; // Указатель на следующий узел

    Node(T val) : data(val), next(nullptr) {} // Конструктор
};

template <typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head; // Указатель на первый узел
    std::shared_ptr<Node<T>> tail; // Указатель на последний узел
    size_t list_size;              // Размер списка

public:
    LinkedList() : head(nullptr), tail(nullptr), list_size(0) {} // Конструктор

    // Метод добавления элемента в начало списка
    void push_front(T val) {
        auto newNode = std::make_shared<Node<T>>(val);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head; // Если список был пуст, обновляем tail
        }
        list_size++;
    }

    // Метод добавления элемента в конец списка
    void push_back(T val) {
        auto newNode = std::make_shared<Node<T>>(val);
        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode; // Если список был пуст, обновляем head
        }
        tail = newNode;
        list_size++;
    }

    // Метод получения элемента по индексу
    T at(size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Индекс выходит за пределы списка.");
        }
        auto current = head;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    // Метод печати списка
    void print() {
        auto current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl; // Конец списка
    }

    // Метод проверки списка на пустоту
    bool is_empty() const {
        return head == nullptr;
    }

    // Метод получения размера списка
    size_t size() const {
        return list_size;
    }
};

// Реализация класса ArrayList
template <typename T>
class ArrayList {
private:
    LinkedList<T> list; // Используем LinkedList как базу

public:
    // Метод добавления элемента в конец списка
    void push_back(T val) {
        list.push_back(val);
    }

    // Метод получения элемента по индексу
    T at(size_t index) {
        return list.at(index); // Используем метод at из LinkedList
    }

    // Метод печати списка
    void print() {
        list.print();
    }

    // Метод проверки списка на пустоту
    bool is_empty() const {
        return list.is_empty();
    }

    // Метод получения размера списка
    size_t size() const {
        return list.size();
    }
};

// Пример использования
int main() {
    ArrayList<int> arrayList;

    // Добавление элементов
    arrayList.push_back(1);
    arrayList.push_back(2);
    arrayList.push_back(3);

    // Печать списка
    std::cout << "Содержимое списка: ";
    arrayList.print();

    // Доступ к элементам
    try {
        std::cout << "Элемент по индексу 1: " << arrayList.at(1) << std::endl; // Ожидаем 2
        std::cout << "Элемент по индексу 3: " << arrayList.at(3) << std::endl; // Ожидаем исключение
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}ы меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
