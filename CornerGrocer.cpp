#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

map<string, int> itemCount;

void LoadFile();
void PrintMenu();
void SearchItem();
void PrintAll();
void PrintHistogram();
void SaveToFile();

int main() {
    LoadFile();
    SaveToFile();

    int choice = 0;

    while (choice != 4) {
        PrintMenu();
        cin >> choice;

        if (choice == 1) {
            SearchItem();
        }
        else if (choice == 2) {
            PrintAll();
        }
        else if (choice == 3) {
            PrintHistogram();
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

void LoadFile() {
    ifstream inFS;
    string item;

    inFS.open("CS210_Project_Three_Input_File.txt");

    if (!inFS.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    while (inFS >> item) {
        itemCount[item]++;
    }

    inFS.close();
}

void PrintMenu() {
    cout << "\nMenu:\n";
    cout << "1. Search for item\n";
    cout << "2. Print all items\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

void SearchItem() {
    string item;
    cout << "Enter item name: ";
    cin >> item;

    if (itemCount.count(item) > 0) {
        cout << item << " was purchased " << itemCount[item] << " times.\n";
    }
    else {
        cout << item << " was not found.\n";
    }
}

void PrintAll() {
    for (auto pair : itemCount) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void PrintHistogram() {
    for (auto pair : itemCount) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void SaveToFile() {
    ofstream outFS;

    outFS.open("frequency.dat");

    for (auto pair : itemCount) {
        outFS << pair.first << " " << pair.second << endl;
    }

    outFS.close();
}