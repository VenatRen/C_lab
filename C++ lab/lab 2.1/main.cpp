#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
using namespace::std;

// Определите класс с именем "state"
class state {
public:
    string name;
    string id;
    string price;
    string available;
    string demand;
    string purchases;
public:
    // Конструктор для класса "state"
    state(string a ,string b,string c,string p,string s, string g){
        name = a;
        id = b;
        price=c;
        available = p;
        demand = s;
        purchases = g;
    }

    // Метод получения входных данных от пользователя для всех атрибутов класса "state"
    void fullstruct() {
        cout << "name" << endl;
        cin >> name;
        cout << "id" << endl;
        cin >> id;
        cout << "price" << endl;
        cin >> price;
        cout << "available" << endl;
        cin >> available;
        cout << "demand" << endl;
        cin >> demand;
        cout << "purchases" << endl;
        cin >> purchases;
    }

    // Метод для вывода всех атрибутов класса "state"
    string output() {
        string output = name + id + price + available + demand + purchases;
        cout << "name=";
        cout << name << endl;
        cout << "id=";
        cout << id << endl;
        cout << "price=";
        cout << price << endl;
        cout << "available=";
        cout << available << endl;
        cout << "demand=";
        cout << demand << endl;
        cout << "purchases=";
        cout << purchases << endl;
        return output;
    }

    // Метод сохранения атрибутов класса "state" в файл
    void savec() {
        ofstream f;
        f.open("C://soxr.txt", ios::app);
        f << name <<" "<< id<< " " << price << " " << available<< " " << demand<< " " << purchases
          << endl;
        f.close();
    }
};

// Определите класс шаблона с именем "Node"
template<typename T>
class Node {
public:
    T* state; // Указатель на объект класса "state"
    Node* next;  // Указатель на следующий элемент в связанном списке
};

// Определите класс шаблона с именем "LinkedList"
template<typename T>
class LinkedList {
private:
    Node<T>* head; // Указатель на первый элемент в связанном списке
public:
    string res1;
    LinkedList(): head(nullptr) {}

    // Способ добавления элемента в связанный список
    void add(state* state) {
        Node<T>* node = new Node<T>; // Создайте новый узел и выделите для него память
        node->state = state;
        node->next = head;
        head = node;
    }

    // Способ удаления элемента из связанного списка
    void remove(state* state) {
        Node<T>* current = head;  // Указатель на текущий элемент в связанном списке
        Node<T>* previous = nullptr; // Указатель на предыдущий элемент в связанном списке
        while (current != nullptr) {
            if (current->state == state) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current; // Освободите память для текущего узла
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    // Способ поиска элемента в связанном списке по имени
    state* find(string name) {
        Node<T>* current = head; // Указатель на текущий элемент в связанном списке
        while (current != nullptr) {
            if (current->state->name == name) {
                cout<<current->state->name<<endl;
                cout<<current->state->id<<endl;
                cout<<current->state->price<<endl;
                cout<<current->state->available<<endl;
                cout<<current->state->demand<<endl;
                cout<<current->state->purchases<<endl;
                return current->state;
            }
            current = current->next;
        }
        return nullptr;
    }

    // Способ сохранения всех элементов в связанном списке в файл
    void save() {
        res1 = "";
        Node<T>* current = head; // Указатель на текущий элемент в связанном списке
        while ((current != nullptr)) {
            res1+= current->state->output();
            current = current->next;
        }
        cout<<res1;
        ofstream f;
        f.open("C://objects.txt", ios::app);
        f << res1 << endl;
        f.close();
    }

    // Способ печати всех элементов в связанном списке
    string print1() {
        res1 = "";
        Node<T>* current = head; // Указатель на текущий элемент в связанном списке
        while ((current != nullptr)) {
            res1 = res1 + current->state->output();
            current = current->next;
        }
        return res1;
    }
};

// Функция для тестирования метода "добавить" связанного списка
string test_add(state* a, state* b ){
    string current1 = a->output();
    string current2 = b->output();
    string necessary1 = "rus23.23.23ivan3000240024";
    string necessary2 = "bel12.12.12vlad200012006";
    if (strcmp(current1.c_str(), necessary1.c_str()) == 0){
    cout << "\nadd method is successful! (1/2)\n";
    }
    else {
        cout << "\nadd method error!\n";}

    if (strcmp(current2.c_str(), necessary2.c_str()) == 0) {
            cout << "\nadd method is successful!(2/2)\n";
        }
    else {
            cout << "\nadd method error!\n";
        }
    }

// Функция для проверки метода "find" связанного списка
string testFind(state* f){
    string expected = "bel12.12.12vlad200012006";
    string result = f->output();
    cout<<result;
    if (strcmp(result.c_str(), expected.c_str()) == 0) {

        cout << "\n find method is successful!\n";
    }
    else {
        cout << "\nfind method error!\n";
    }
}

// Функция для проверки метода "remove" из связанного списка
string test_remove(string result,string expected){

    if (strcmp(result.c_str(), expected.c_str()) == 0) {

        cout << "\nremove method is successful!\n";
    }
    else {
        cout << "\nreomve method error!\n";
    }
}

// Main функция
int main() {
    LinkedList<state> list;
    state *a = new state(" ", " ", " ", " ", " ", " ");
    state *b = new state(" ", " ", " ", " ", " ", " ");
    state *c = new state(" ", " ", " ", " ", " ", " ");
    a->fullstruct();
    b->fullstruct();
    c->fullstruct();
    list.add(a);
    list.add(b);
    list.add(c);
    list.print1();
    list.remove(c);
    cout<<"without the third element"<<endl;
    list.print1();
    list.save();
    string find;
    cin>>find;
    test_add(a,b);
   state* f = list.find(find);
   testFind(f);
    string listall = list.print1();
    string str = list.print1();
    string expected = "bel12.12.12vlad200012006rus23.23.23ivan3000240024";
    test_remove(str,expected);
    delete(a);
    delete(b);
    delete(f);
    delete(c);

}