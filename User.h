#include <bits/stdc++.h>

using namespace std;

class Contact{

    private:
        string viewName;
        string FirstName;
        string LastName;
        string number;
        string email;
        string blood;
        string relationship;
        string address;

    public:

        Contact() {

        }

        Contact(string number) {
            this->number = number;
            this->viewName = number;
        }

        Contact(string FirstName, string LastName, string number) {
            this->FirstName = FirstName;
            this->LastName = LastName;
            this->number = number;
            this->viewName = FirstName.append(" " + LastName);
        }

        Contact(string FirstName, string LastName, string number, string email, string blood, string relationship,string address){
            this->FirstName = FirstName;
            this->LastName = LastName;
            this->number = number;
            this->email = email;
            this->blood = blood;
            this->relationship = relationship;
            this->address = address;
            this->viewName = FirstName.append(" " + LastName); 
        }

        string getViewName() {
            return this->viewName;
        }

        void setFirstName(string FirstName) {
            this->FirstName = FirstName;
            this->viewName = FirstName + " " + this->LastName;
        }

        string getFirstName() {
            return this->FirstName;
        }

        void setLastName(string LastName) {
            this->LastName = LastName;
            this->viewName = this->FirstName + " " + LastName;
        }

        string getLastName() {
            return this->LastName;
        }

        void setNumber(string number) {
            this->number = number;
        }

        string getNumber() {
            return this->number;
        }

        void setEmail(string email) {
            this->email = email;
        }

        string getEmail() {
            return this->email;
        }

        void setBlood(string blood) {
            this->blood = blood;
        }

        string getBlood() {
            return this->blood;
        }

        void setRelationShip(string relationShip) {
            this->relationship = relationShip;
        }

        string getRelationShip() {
            return this->relationship;
        }

        void setAddress(string address) {
            this->address = address;
        }

        string getAddress() {
            return address;
        }


    


        void displayList() {

            cout << "\n\t Name : " << viewName << endl;
            cout << "\t Number : " << number << endl;
        }

        void contactInfo() {

            cout << "\n\t First Name : " << FirstName << endl;
            cout << "\t Last Name : " << LastName << endl;
            cout << "\t Number : " << number << endl;
            cout << "\t Email : " << email << endl;
            cout << "\t Blood : " << blood << endl;
            cout << "\t Relationship : " << relationship << endl;
            cout << "\t Address : " << address << endl;

        }


        



};