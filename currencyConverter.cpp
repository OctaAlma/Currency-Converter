#include <iostream>
#include <vector>
#include <fstream>
using std::string, std::cout, std::cin, std::endl, std::vector;

class currency{
    private:
        string name;
        string abreviation;
        double value;
    public:
        currency(string name, string abreviation, double value):name(name),abreviation(abreviation),value(value){}
        string getName(){return name;}
        string getAbreviation(){return abreviation;}
        double getValue(){return value;}
};

void readData(string fileName, vector<currency>& currencies){
    std::ifstream file;
    file.open(fileName);

    string name;
    string abreviation;
    double value;

    while (!file.eof()){
        file >> name;
        file >> abreviation;
        file >> value;
        currency newCurrency(name,abreviation,value);
        currencies.push_back(newCurrency);
    }
    file.close();
}

double toUSD(vector<currency> currencies, string currencyToLookFor, double quantity){
    for (size_t i = 0; i < currencies.size(); i++){
        if ((currencies.at(i).getAbreviation() == currencyToLookFor) || (currencies.at(i).getAbreviation() == currencyToLookFor)){
            return quantity/currencies.at(i).getValue();
        }
    }
}

double fromUSD(vector<currency> currencies, string currencyToLookFor, double quantity){
    for (size_t i = 0; i < currencies.size(); i++){
        if ((currencies.at(i).getAbreviation() == currencyToLookFor)){
            return quantity*currencies.at(i).getValue();
        }
    }
}

void printAbreviation(vector<currency> currencies){
    cout << "\n-------------------------------\n";
    for (size_t i = 0; i < currencies.size(); i++){
        cout << "   " << currencies.at(i).getAbreviation() << " ---------------- " << currencies.at(i).getName() << "\n";
    }
    cout << "-------------------------------\n\n";
}

void UI(vector<currency> currencies){
    while (true){
        int input;
        cout << "---------------------------------------------------------------------\n";
        cout << "Welcome to currency converter. Please select one of the following:\n";
        cout << "---------------------------------------------------------------------\n";
        cout << "   1. Convert TO US dollars\n   2. Convert FROM US dollars\n   3. Show country currencies\n   4. Exit\n";
        cout << "---------------------------------------------------------------------\n";
        cin >> input;

        if (input == 1){
            cout << "\nSelect a currency:\n";
            for (size_t i = 0; i < currencies.size(); i++){
                cout << i+1 << ". " << currencies.at(i).getAbreviation() <<" \n";
            }
            int index;
            cin >> index;
            index--;
            // Check if the input is within the range:
            if (index < 0 || index >= currencies.size()){cout << "bruh\n";continue;}
            else{
                double quantity;
                cout << "Enter how much " << currencies.at(index).getAbreviation() << " you want to convert: ";
                cin >> quantity;
                cout << quantity << " " << currencies.at(index).getAbreviation() << " is "<< toUSD(currencies, currencies.at(index).getAbreviation(),quantity) << " USD\n\n";
            }
        }

        else if (input == 2){
            cout << "\nSelect a currency:\n";
            for (size_t i = 0; i < currencies.size(); i++){
                cout << i+1 << ". " << currencies.at(i).getAbreviation() <<" \n";
            }
            
            int index;
            cin >> index;
            index--;
            // Check if the input is within the range:
            if (index < 0 || index >= currencies.size()){cout << "bruh\n";continue;}
            else{
                double quantity;
                cout << "Enter how many USD you want to convert: ";
                cin >> quantity;
                cout << quantity << " USD is "<< fromUSD(currencies, currencies.at(index).getAbreviation(),quantity) << " " << currencies.at(index).getAbreviation() << "\n\n";
            }
        }
        else if (input == 3){printAbreviation(currencies);}
        else{break;}
    }
}

int main(){
    vector<currency> currencies;
    string fileName = "toUSD.txt";
    readData(fileName, currencies);
    UI(currencies);
}