//
// Created by DELL on 03-May-25.
//
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>

using namespace std;
const int max_user=100;
struct User{
    string username,email,password,phonenum,address,age;
};
bool isDuplicateUsername(const string& username) {
    ifstream inFile("userslist.txt");
    string line, existingUsername;

    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, existingUsername, ',');
        if (existingUsername == username) {
            return true;
        }
    }
    return false;
}

bool isValidUsername(const string& username) {
    for (char ch : username) {
        if (!isalpha(ch) && ch != ' ') {
            return false;
        }
    }
    return !username.empty();
}
bool isEmail(const string& email){
    string domain = "@gmail.com";
    if (email.length() <= domain.length()){

     return false;}

    if (email.substr(email.length() - domain.length()) != domain)
    {
        return false;
    }
    string startemail= email.substr(0, email.length() - domain.length());
    if (startemail.empty()) {
        return false;
    }

    for(char ch : startemail) {
        if (!islower(ch) && !isdigit(ch)) {
            return false;
        }
    }

    return true;
}
bool isValidAge(const string& age) {
if (age.empty()){
    return false;
}
    for (char ch : age) {
        if (!isdigit(ch)) {
            return false;
        }

    }
    int agevalue= stoi(age);
        return agevalue>0;
}
bool isValidPhone(const string& phonenum){
    if(phonenum.length()!=11){
        return false;
    }
    for(char ch: phonenum){
        if(!isdigit(ch )){
            return false;
        }
    }
    return !phonenum.empty();
}
bool isValidAddress(const string& address){
    for (char ch : address) {
        if (!isalpha(ch)&& ch!=' ') {
            return false;
        }
    }
    return !address.empty();
}
void adduser(User users[], int &count) {

    ofstream outFile("userslist.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening file for writing.\n";
        return;
    }

    cin.ignore();
    string temp;
    while (true) {
        cout << "Enter user name: ";
        getline(cin, temp);

        if (!isValidUsername(temp)) {
            cout << "Invalid username. Use letters only.\n";
            continue;
                }
        if (isDuplicateUsername(temp)) {
            cout << "This username already exists. Try another one.\n";
            continue;
        }
        users[count].username=temp;
        break;
    }

    while (true) {
        cout << "Enter email: ";
        getline(cin, temp);
        if (isEmail(temp)) {
            users[count].email = temp;
            break;
        } else {
            cout << "Invalid email. Must be like example123@gmail.com\n";
        }
    }


    while(true) {

    cout << "Enter phone: ";
    getline(cin,temp);
    if(isValidPhone(temp)){
        users[count].phonenum=temp;
        break;
    }
    else{
        cout << "Invalid phone number. Enter numbers only .\n";
    }
}

    while (true) {
        cout << "Enter age: ";
        getline(cin, temp);
        if (isValidAge(temp)) {
            users[count].age = temp;
            break;
        } else {
            cout << "Invalid age. Enter numbers only and no negative values.\n";
        }
    }
while(true){
    cout << "Enter address: ";
    getline(cin, temp);
    if(isValidAddress(temp)){
        users[count].address=temp;
        break;
    }
    else{
        cout<<"Invalid address. Use letters only.\n";
    }
}


    outFile << users[count].username << ','
            << users[count].email << ','
            << users[count].phonenum << ','
            << users[count].age << ','
            << users[count].address << endl;

    outFile.close();
    count++;
    cout << "User added successfully.\n";
}
void readUser() {
    ifstream inFile("userslist.txt");
    string line;

    if (inFile.is_open()) {
        int lineNumber = 1;
        while (getline(inFile, line)) {
            cout << lineNumber++ << ". " << line << '\n';
        }
        inFile.close();
    } else {
        cout << "No userlist found for " <<  ".\n";
    }
}
void updateUser(User users[],int &count) {
    ifstream inFile("userslist.txt");
    string line;
    string username;
    bool found=false;

    count = 0;

    if (!inFile.is_open()) {
        cout << "Error opening file for reading.\n";
        return;
    }

    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, users[count].username, ',');
        getline(ss, users[count].email, ',');
        getline(ss, users[count].phonenum, ',');

        getline(ss,users[count].age,',');
        getline(ss, users[count].address);
        count++;
    }
    inFile.close();
    cin.ignore();
        cout << "Enter username to Update: ";
        getline(cin, username);
        for(int i=0;i<count;i++) {
            if (users[i].username == username) {

                string temp;
                while (true) {
                    cout << "Enter new email: ";
                    getline(cin, temp);
                    if (isEmail(temp)) {
                        users[i].email = temp;
                        break;
                    } else {
                        cout << "Invalid email. Must be like example123@gmail.com\n";
                    }
                }
                while(true) {

                    cout << "Enter new phone: ";
                    getline(cin,temp);
                    if(isValidPhone(temp)){
                        users[i].phonenum=temp;
                        break;
                    }
                    else{
                        cout << "Invalid phone number. Enter numbers only .\n";
                    }
                }

                while (true) {
                    cout << "Enter new age: ";
                    getline(cin, temp);
                    if (isValidAge(temp)) {
                        users[i].age = temp;
                        break;
                    } else {
                        cout << "Invalid age. Enter numbers only and no negative values.\n";
                    }
                }
                while(true){
                    cout << "Enter  new address: ";
                    getline(cin, temp);
                    if(isValidAddress(temp)){
                        users[i].address=temp;
                        break;
                    }
                    else{
                        cout<<"Invalid address. Use letters only.\n";
                    }
                }

                found = true;
                break;
            }
            } if(!found) {
                cout << "User not found";

            }
                ofstream outFile("userslist.txt");
                if (outFile.is_open()) {
                    for (int i = 0; i < count; i++) {
                        outFile << users[i].username << ","
                                << users[i].email << ","
                                << users[i].phonenum << ","
                                << users[i].age << ","
                                << users[i].address << endl;
                    }
                    outFile.close();
                    cout << "User updated successfully.\n";
                }

            }

void deleteUser(User users[],int &count){
    ifstream inFile("userslist.txt");
    string line;
    string username;
    bool found=false;
    count = 0;

    if (!inFile.is_open()) {
        cout << "Error opening file for reading.\n";
        return;
    }
        while (getline(inFile, line)) {
            stringstream ss(line);
            getline(ss, users[count].username, ',');
            getline(ss, users[count].email, ',');
            getline(ss, users[count].phonenum, ',');
            getline(ss,users[count].age);
            getline(ss, users[count].address);
            count++;
        }
        inFile.close();
        cin.ignore();
        cout << "Enter username to Delete: ";

        getline(cin, username);
    for(int i=0;i<count;i++) {
        if (users[i].username == username) {
            found=true;
            for(int j=i;j<count-1;j++){
                users[j]=users[j+1];
            }
            count--;
            break;
        }
    }
    if(!found) {
        cout << "User not found";

    }
    ofstream outFile("userslist.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < count; i++) {
            outFile << users[i].username << ","
                    << users[i].email << ","
                    << users[i].phonenum << ","
                    << users[i].age << ","
                    << users[i].address << endl;
        }
        outFile.close();
        cout << "User deleted successfully.\n";
    }

}
void searchUser() {
    ifstream inFile("userslist.txt");
    string keyword, line;
    bool found = false;

    cin.ignore();
    cout << "Enter username to search: ";
    getline(cin, keyword);

    if (inFile.is_open()) {
        int lineNumber = 1;
        cout << "\n--- Search Results ---\n";
        while (getline(inFile, line)) {
            if (line.find(keyword) != string::npos) {
                cout << lineNumber << ". " << line << '\n';
                found = true;
            }
            lineNumber++;
        }
        inFile.close();

        if (!found) {
            cout << "No matching username found.\n";
        }
    } else {
        cout << "No username found for ";
    }
}

int main(){

    User users[max_user];
    int count=0;
    int choice;
    do{
        cout<<"---Users list---\n";
        cout<<"1.Add New user.\n";
        cout<<"2.Show Users list.\n";
        cout<<"3.Search user by name.\n";
        cout<<"4.Update user by name.\n";
        cout<<"5.Delete user by name.\n";
        cout<<"6.Exit...\n";
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch (choice) {
            case 1:adduser(users,count);
                break;
            case 2:readUser();
                break;
            case 3:searchUser();break;
            case 4:updateUser(users,count);
                break;
            case 5:
                deleteUser(users,count);break;
            case 6:
                cout<<"Exit...";break;
            default:
                cout<<"Invalid Choice";

        }
    }while(choice!=6);

}
