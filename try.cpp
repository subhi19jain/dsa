#include <bits/stdc++.h>
using namespace std;

void insert(int hash[][2], int key) {
    int loc = key % 10; 

   
    while (hash[loc][0] != -1) {
        if (hash[loc][0] == key) {
           
            return;
        }
      
        int displaced = hash[loc][0]; 
        hash[loc][0] = key;  

       
        int nextLoc = (loc + 1) % 10;
        while (hash[nextLoc][0] != -1) {
            nextLoc = (nextLoc + 1) % 10;  
        }

        
        hash[nextLoc][0] = displaced;
        hash[loc][1] = -1;  
        return; 
    }

   
    hash[loc][0] = key;
    hash[loc][1] = -1;  
}

void display(int hash[][2]) {
    cout << "Ind  Hash\n";
    for (int i = 0; i < 10; i++) {
        cout << i << "    " << hash[i][0] << "\n";
    }
}

bool isFull(int hash[][2]) {
    for (int i = 0; i < 10; i++) {
        if (hash[i][0] == -1) {
            return false; 
        }
    }
    return true;  
}

int main() {
    int hash[10][2];  
    for (int i = 0; i < 10; i++) {
        hash[i][0] = -1;  
        hash[i][1] = -1; 
    }

    string menu = "Enter your choice: \n1. Add\n2. Display\n3. Exit";
    int opt;
    do {
        cout << menu << endl;
        cout << "Your choice: ";
        cin >> opt;
        switch (opt) {
            case 1: {
                cout << "\nEnter the element: ";
                int key;
                cin >> key;
                if (isFull(hash)) {
                    cout << "Hash table is full.\n";
                } else {
                    insert(hash, key);
                }
                break;
            }
            case 2:
                display(hash);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "\nPlease enter a correct option\n";
                break;
        }
    } while (opt != 3);

    return 0;
}
