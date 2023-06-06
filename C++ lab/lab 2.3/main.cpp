#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Определите класс под названием "product"
class product {
public:
    string name;
    string id;
    string price;
    string available;

public:
    // Конструктор по умолчанию
    product(){
        price = "None";
        name ="None";
        id="None";
        available="None";
    }

    // Параметризованный конструктор
    product(string a ,string b,string c,string d){
        name = a;
        id=c;
        price = b;
        available = d;
    }

    // Метод для ввода всех атрибутов состояния
    void inputAttributes(){
        cout << "name" << endl;
        cin >> name;
        cout << "id" << endl;
        cin >> id;
        cout << "price" << endl;
        cin >> price;
        cout << "available" << endl;
        cin >> available;
    }

    // Метод для печати всех атрибутов состояния
    void printAttributes(){
        cout << "name=";
        cout << name << endl;
        cout << "id=";
        cout << id << endl;
        cout << "price=";
        cout << price << endl;
        cout << "available=";
        cout << available << endl;
    }

    // Метод изменения доступности
    void changeAvalible(){
        string d;
        cout << "enter new available" << endl;
        cin >> d;
        available = d;
    }

    // Способ сменить id
    void changeId() {
        cout << "enter a new id" << endl;
        cin >> id;
    }

    // Способ изменения цены
    void pop() {
        cout << "enter new price" << endl;
        cin >> price;
    }

    // Способ сохранения атрибутов состояния в файл
    void saveAttributes() {
        ofstream f;
        f.open("C://soxr.txt", ios::app);
        f << name <<" "<< id << " " << price<< " " << available << endl;
        f.close();
    }
};

// Определите класс с именем "demand", который наследуется от "product".
class demand : public product {
public:
    int requirement;
    string average_demand_season;
    string purchases;

    // Конструктор по умолчанию
    demand() : product() {};

    // Способ изменения потребности
    void changeRequirment() {
        int r;
        cout << "enter new requirement" << endl;
        cin >> r;
        requirement = r;
    }

    // Способ изменения среднего спроса за сезон
    void changeAvgDemandSeason() {
        string r;
        cout << "enter new average demand season" << endl;
        cin >> r;
        average_demand_season = r;
    }

    // Способ ввода всех атрибутов спроса
    void SubInputAttributes() {
        cout << "enter requirement" << endl;
        cin >> requirement;
        cout << "enter new average daily temperature" << endl;
        cin >> average_demand_season;
        cout << "endter purchases" << endl;
        cin >> purchases;
    }

    // Способ печати всех атрибутов спроса
    void SubPrintAttributes() {
        cout << "requirement=";
        cout << requirement << endl;
        cout << "average daily temperature=";
        cout << average_demand_season << endl;
        cout << "purchases=";
        cout << purchases << endl;

    }

    // Способ сохранения атрибутов спроса в файл
    void dsaveAttributes() {
        ofstream f;
        f.open("C://soxr.txt", ios::app);
        f << name << " " << id << " " << price << " " << available << " " << requirement << " "
          << average_demand_season << " " << purchases << endl;
        f.close();
    }
    string tstr(){
        string end;
        end += name + id + price + available + average_demand_season + purchases;
        return end;
    }

};

// Определение функции-предикат, которая будет использоваться при сортировке спроса по потребности
bool mypred(demand a,demand b){           
    return (a.requirement < b.requirement);
};

// Определение функции перегрузки оператора для сравнения двух спросов
bool operator== (demand a, demand b){  
    return(a.name == b.name);
}
void testsort(vector<demand> digits){
    int shet=0;
    for (int l = 0 ;l< (digits.size()-1); l++) {
        for(int j = 1;j<(digits.size());j++)
        {
            if (digits[l].requirement < digits[j].requirement) {
                shet = shet +  0;
            }
            else {
                shet = shet + 1;
            }
        }
    }
    if (shet==0){
        cout<<"method sort complete sucsefull!"<<endl;}
    else if (shet!=0){
        cout<<"method sort error!"<<endl;
    }
};

void testfullstr(vector<demand> digits){
    string strok;
    int counter = 0;
    for (int i = 0; i<digits.size();i++){
        strok+=digits[i].tstr();
        counter += digits[i].requirement;
    }
    string expected = "ruvov77555577belvla88771045";
    int exch = 100;
    if ((counter==exch)&&(strok==expected)){
        cout<<"fullstruct sucsefull! "<<endl;
    }
    else{
        cout<<"fullstruct error!"<<endl;
    }

}
void testchnum(vector<demand> digits, int n,int num){
    if (digits[num].requirement == n ){
    cout<<"change number sucsefull! "<<endl;
}
else{
        cout<<"change number error! "<<endl;
}
}
int main() {
    int n;
    cout << "enter the size" << endl;
    cin >> n;
    vector<demand> digits(n);
    int menu;
    do{
        cout<<"1 to full the array."<<endl;
        cout<<"2 to display the array."<<endl; 
        cout<<"3 to change one element."<<endl;
        cout<<"4 for delete element last element."<<endl; 
        cout<<"5 for saveAttributes."<<endl; 
        cout<<"6 for delete array."<<endl; 
        cout<<"7 for sort."<<endl;
        cout<<"8 for find."<<endl;
        cout<<"0 for exit."<<endl;
        cin>>menu;
        if (menu==1) {
            for (int i = 0; i < digits.size(); i++) {
                digits[i].inputAttributes();
                digits[i].SubInputAttributes();
            }
        }
        else if (menu==2){
            for (int i=0;i < digits.size();i++){
                digits[i].printAttributes();
                digits[i].SubPrintAttributes();
            }

        }
        else if(menu==3){
            int num;
            cout<<"enter which element you want to change"<<endl;
            cin>>num;
            int choice;
            cout<<"1 change available."<<endl;
            cout<<"2 to change the id."<<endl;
            cout<<"3 to change the requirement of price."<<endl;
            cout<<"4 to change demand requirement."<<endl;
            cout<<"5 to change average daily temperature."<<endl;
            cin>>choice;
            if (choice==1){
                digits[num].changeAvalible();
            }
            else if (choice==2){
                digits[num].changeId();
            }
            else if (choice==3){
                digits[num].pop();
            }
            else if (choice==4){
                digits[num].changeRequirment();
            }
            else if (choice==5){
                digits[num].changeAvgDemandSeason();
            }
        }
        else if (menu==4){
            digits.pop_back();
        }
        else if (menu==5){
            for (int i=0;i < digits.size();i++){
                digits[i].saveAttributes();
            }
        }
        else if (menu ==7){
            sort(digits.begin(),digits.end(),mypred);
        }
        else if (menu ==8) {
            int poisk;
            cin >> poisk;
            poisk-=1;
            auto d = find(digits.begin(),digits.end(),digits[poisk]);
            d->printAttributes();
            d->SubPrintAttributes();
        }
        else if (menu ==6){
            digits.clear();
            cout<<"mas empty"<<endl;
        }
        else if (menu ==0){
            digits.clear();
            cout<<"exit"<<endl;
        }
        else if (menu==77){
            testsort(digits);
        }
        else if (menu == 11){
            testfullstr(digits);
        }
    }while( menu!=0 );
}