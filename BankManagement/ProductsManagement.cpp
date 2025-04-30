//
// Created by DELL on 30-Apr-25.
//
#include <iostream>
#include <string>
using namespace std;
const int max_products=100;
struct Product {
    int id;
    string name;
    float price;

};
void addProduct(Product products[], int &count);
void showProduct(const Product products[], int count);
void updateProduct(Product products[], int count);
void deleteProduct(Product products[], int &count);

void addProduct(Product products[],int &count){
    if(count>=max_products){
        cout<<"Inventory is Full.\n";
        return;
    }
    cout<<"Enter Product ID: ";
    cin>>products[count].id;
    cout<<"Enter Product Name: ";
    cin.ignore();
    getline(cin,products[count].name);
    cout<<"Enter Product Price: ";
    cin>>products[count].price;
    count++;
    cout<<"Product added successfully.\n";
}
void showProduct(const Product products[],int count){
    if(count==0){
        cout<<"No products available.\n";
     return;
    }
   cout<<"**Product List**\n";
    for(int i=0;i<count;i++){
        cout<<"ID: "<<products[i].id<<"\nName: "<<products[i].name<<"\nPrice: $"<<products[i].price<<endl;
    }
}
void updateProduct(Product products[],int count){
    int id;
    cout<<"Enter Product ID to update: ";
    cin>>id;
  // bool found=false;
    for(int i=0;i<count;i++) {
        if (products[i].id == id) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, products[i].name);
            cout << "Enter new price:";
            cin >> products[i].price;
            cout << "Product updated Successfully.\n";
        }
        else if(products[i].id != id){
            cout << "ID not found.\n";
        }

    }
}
void deleteProduct(Product products[],int &count){
    int id;
    cout<<"Enter Product ID to delete: ";
    cin>>id;
    for(int i=0;count;i++) {
        if (products[i].id == id) {
            for (int j = i; count - 1; j++) {
                products[j] = products[j + 1];

            }
            count--;
            cout << "Product deleted Successfully.\n";
            return;
        } else if (products[i].id != id) {
            cout << "ID not found.\n";
        }
    }

}

int main(){
    Product products[max_products];
    int count=0;
    int choice;
    while(true){
        cout<<"**Product Inventory**\n";
        cout<<"1. Add Product\n";
        cout<<"2. Show Product\n";
        cout<<"3. Update Product\n";
        cout<<"4. Delete Product\n";
        cout<<"5. Exit\n";
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch(choice){
            case 1:addProduct(products,count); break;
            case 2:showProduct(products,count); break;
            case 3:updateProduct(products,count); break;
            case 4:deleteProduct(products,count); break;
            case 5:return 0;
            default: cout<<"Invalid choice.\n";
        }
    }

}


