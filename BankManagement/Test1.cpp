//
// Created by DELL on 30-Apr-25.
//
#include <iostream>
#include <string>
using namespace std;

int main(){
    const int size=100;
    int ids[size];
    string name[size];
    int count=0;
    int choice;
    while(true){
        cout<<"Choose Menu "<<endl;
        cout<<"1. Create\n";
        cout<<"2. Read\n";
        cout<<"3. Update\n";
        cout<<"4. Delete\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice==1) {
            if (count < size) {
                cout << "Enter ID: ";
                cin >> ids[count];
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name[count]);
                count++;
                cout << "Record ded successfully" << endl;
            } else {
                cout << "Database Full";
            }

        }
        else if(choice==2){
            cout<<"Record \n";
            for(int i=0; i<count;i++){
                cout<<"ID: "<<ids[i]<<"\n Name: "<<name[i]<<endl;
            }
        }
        else if(choice==3){
            int findid;
            cout<<"Enter ID to update: ";
            cin>>findid;
            bool found=false;
            for(int i=0; i<count; i++){
                if (ids[i]==findid){
                    cout<<"Enter new name:";
                    cin.ignore();
                    getline(cin, name[i]);
                    cout<<"Record updated\n";
                    found=true;
                    break;
                }
            }
            if(!found){
                cout<<"ID not found.\n";
            }
        }
        else if(choice==4){
            int deleteid;
            cout<<"Enter ID to Delete: ";
            cin>>deleteid;
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (ids[i] == deleteid) {
                    for (int j = i; j < count - 1; j++) {
                        ids[j] = ids[j + 1];
                        name[j] = name[j + 1];
                    }
                    count--;
                    cout << "Record deleted.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "ID not found.\n";
            }
        } else if (choice == 5) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}






