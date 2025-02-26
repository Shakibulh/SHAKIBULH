#include <bits/stdc++.h>
#include "List.h"


using namespace std;


List l;


void printMenu() {

    cout << "\n\t\t -------------MENU-------------- \n\t\t|\t\t\t\t|" << endl;
    cout << "\t\t|\t1. New Contact      \t|" << endl;
    cout << "\t\t|\t2. Edit Contact     \t|" << endl;
    cout << "\t\t|\t3. Search Contact\t|" << endl;
    cout << "\t\t|\t4. Delete Contact\t|" << endl;
    cout << "\t\t|\t5. View List        \t|" << endl;
    cout << "\t\t|\t6. EXIT             \t|" << endl;
    cout << "\t\t|\t\t\t\t|\n\t\t ------------------------------- \n" << endl;

}

void printNewContactMenu(string FirstName, string LastName, string number, string email, string blood, string relationship,string address) {

    cout << "\n ----------------New Contact----------- \n" << endl;
    cout << "\t1. First Name : " << FirstName <<  endl;
    cout << "\t2. Last Name : " << LastName << endl;
    cout << "\t3. Number : " << number << endl;
    cout << "\t4. Email : " << email << endl;
    cout << "\t5. Blood : " << blood << endl;
    cout << "\t6. Relationship : " << relationship << endl;
    cout << "\t7. Address : " << address << endl;
    cout << "\n\tSAVE   -> (Press 0)" << endl;
    cout << "\tCANCEL -> (Press 9)" << endl;
    cout << "\n -------------------------------------- \n" << endl;

}


void printEditContactMenu(string FirstName, string LastName, string number, string email, string blood, string relationship,string address) {

    cout << "\n ----------------Edit Contact----------- \n" << endl;
    cout << "\t1. First Name : " << FirstName <<  endl;
    cout << "\t2. Last Name : " << LastName << endl;
    cout << "\t3. Number : " << number << endl;
    cout << "\t4. Email : " << email << endl;
    cout << "\t5. Blood : " << blood << endl;
    cout << "\t6. Relationship : " << relationship << endl;
    cout << "\t7. Address : " << address << endl;
    cout << "\n\tSAVE   -> (Press 0)" << endl;
    cout << "\tCANCEL -> (Press 9)" << endl;
    cout << "\n -------------------------------------- \n" << endl;

}


void printDeleteMenu() {

    cout << "\n ----------------Delete Contact----------- \n" << endl;
    cout << "\t1. Delete A contact " <<  endl;
    cout << "\t2. Delete multiple contact " << endl;
    cout << "\t3. Merge Duplicate contact " << endl;
    cout << "\n ----------------------------------------- \n" << endl;
}








bool isNumber(string s) {

    for(int i=0; i<s.size(); i++) {
        if(!isdigit(s.at(i)))
            return false;
    }
    return true;
}

int inputValidity(string s) {

    if(!isNumber(s))
        return -1;
    else 
        return stoi(s);
}








void newContact() {

    bool run = true;

    string FirstName;
    string LastName;
    string number;
    string email;
    string blood;
    string relationship;
    string address;

    while(run) {

        system("cls");

        printNewContactMenu(FirstName,LastName,number,email,blood,relationship,address);

        string c;
        cout << " Enter choice : ";
        cin >> c;

        int ch = inputValidity(c);

        switch(ch) {

            case 1 :
                cout << "\n Enter First Name : ";
                cin >> FirstName;
                break;

            case 2 :
                cout << "\n Enter Last Name : ";
                cin >> LastName;
                break;

            case 3 :
                cout << "\n Enter Number : ";
                cin >> number;
                break;

            case 4 :
                cout << "\n Enter email : ";
                cin >> email;
                break;

            case 5 :
                cout << "\n Enter blood : ";
                cin >> blood;
                break;

            case 6 :
                cout << "\n Enter relationship : ";
                cin >> relationship;
                break;


            case 7 :
                cout << "\n Enter address : ";
                cin >> address;
                break;

            case 0 :

                if((!FirstName.empty() || !LastName.empty()) && !number.empty()) {
                    Contact conatact(FirstName,LastName,number,email,blood,relationship,address);
                    l.insertAtFirst(conatact);
                    l.sort();
                    run = false;

                }

                else {
                    cout << "\n\t [Please Input Name and Number]\n\n" << endl;
                    system("pause");
                }

                break;

            case 9 :
                run = false;
                break;
                
            default:
                cout << "\n\t Invalid Option\n\n" << endl;
                system("pause");
                break;
        }

    }


}



void editContact() {

    


    if(!l.isEmpty()) {
        
        system("cls");
        cout << "\n ----------------Edit Contact----------- \n\n" << endl;

        l.printList();
        
        cout << "\n\n\n Enter Serial No : ";
        string ch;
        cin >> ch;

        int sr = inputValidity(ch);
        if(sr==-1) {
            cout << "\n\t Invalid Option\n" << endl;
            system("pause");
            return;
        }

        Contact contact = l.findNodeContact_Index(sr); 

        if(contact.getViewName().empty()) {
            cout << "\n\t Contact Not Found\n\n" << endl;
            system("pause");
            return;
        }

        bool run = true;

        string FirstName = contact.getFirstName();
        string LastName = contact.getLastName();
        string number = contact.getNumber();
        string email = contact.getEmail();
        string blood = contact.getBlood();
        string relationship = contact.getRelationShip();
        string address = contact.getAddress();

        while(run) {

            system("cls");

            printEditContactMenu(FirstName,LastName,number,email,blood,relationship,address);

            string c;
            cout << " Enter choice : ";
            cin >> c;

            int cc = inputValidity(c);


            switch(cc) {

                case 1 :
                    cout << "\n Enter First Name : ";
                    cin >> FirstName;
                    contact.setFirstName(FirstName);
                    break;

                case 2 :
                    cout << "\n Enter Last Name : ";
                    cin >> LastName;
                    contact.setLastName(LastName);
                    break;

                case 3 :
                    cout << "\n Enter Number : ";
                    cin >> number;
                    contact.setNumber(number);
                    break;

                case 4 :
                    cout << "\n Enter email : ";
                    cin >> email;
                    contact.setEmail(email);
                    break;


                case 5 :
                    cout << "\n Enter blood : ";
                    cin >> blood;
                    contact.setBlood(blood);
                    break;

                case 6 :
                    cout << "\n Enter relationship : ";
                    cin >> relationship;
                    contact.setRelationShip(relationship);
                    break;


                case 7 :
                    cout << "\n Enter address : ";
                    cin >> address;
                    contact.setAddress(address);
                    break;

                case 0 :

                        l.insertAt(contact,sr);
                        l.sort();
                        run = false;
                        cout << "\n\t Contact Updated" << endl;

                    // if((!FirstName.empty() || !LastName.empty()) && !number.empty()) {
                    //     l.insertAt(contact,ch);
                    //     l.sort();
                    //     run = false;
                    // }

                    // else {
                    //     cout << "\n\t [Please Input Name and Number]\n\n" << endl;
                    //     system("pause");
                    // }

                    break;
                
                case 9 :
                    run = false;
                    break;

                default:
                    cout << "\n\t Invalid Option\n\n" << endl;
                    system("pause");
                    break;                    
            }

        }

    }

    else
        cout << "\n\t List is EMPTY" << endl;

    cout << endl;
    system("pause");

}




void editDelSearch(Contact contact, int ch) {


    if(ch==1) {

        system("cls");
        cout << "\n ----------------Edit Contact----------- \n\n" << endl;
         
        if(contact.getViewName().empty()) {
            cout << "\n\t Contact Not Found\n\n" << endl;
            system("pause");
            return;
        }

        bool run = true;

        string FirstName = contact.getFirstName();
        string LastName = contact.getLastName();
        string number = contact.getNumber();
        string email = contact.getEmail();
        string blood = contact.getBlood();
        string relationship = contact.getRelationShip();
        string address = contact.getAddress();

        while(run) {

            system("cls");

            printEditContactMenu(FirstName,LastName,number,email,blood,relationship,address);

            int c;
            cout << " Enter choice : ";
            cin >> c;


            switch(c) {

                case 1 :
                    cout << "\n Enter First Name : ";
                    cin >> FirstName;
                    contact.setFirstName(FirstName);
                    break;

                case 2 :
                    cout << "\n Enter Last Name : ";
                    cin >> LastName;
                    contact.setLastName(LastName);
                    break;

                case 3 :
                    cout << "\n Enter Number : ";
                    cin >> number;
                    contact.setNumber(number);
                    break;

                case 4 :
                    cout << "\n Enter email : ";
                    cin >> email;
                    contact.setEmail(email);
                    break;


                case 5 :
                    cout << "\n Enter blood : ";
                    cin >> blood;
                    contact.setBlood(blood);
                    break;

                case 6 :
                    cout << "\n Enter relationship : ";
                    cin >> relationship;
                    contact.setRelationShip(relationship);
                    break;


                case 7 :
                    cout << "\n Enter address : ";
                    cin >> address;
                    contact.setAddress(address);
                    break;

                case 0 :

                    if((FirstName.empty() || LastName.empty()) && number.empty()) {
                        cout << "\n\t [Please Input Name and Number]\n\n" << endl;
                        system("pause");
                    }

                    else {
                        l.insertAt(contact,ch);
                        l.sort();
                        run = false;
                        cout << "\n\t Contact Updated" << endl;
                    }

                    break;
                
                case 9 :
                    run = false;
                    break;

                default:
                    cout << "\n\t Invalid Option\n\n" << endl;
                    system("pause");
                    break;                    
            }

        }


    }



    else {
        l.deleteNode_Contact(contact);
    }




}




void searchContact() {

    if(!l.isEmpty()) {

        system("cls");
        cout << "\n ----------------Search Contact----------- \n\n" << endl;

        cout << " Enter search info : ";
        string src;
        cin >> src;

        if(!l.findNodeContact(src).getViewName().empty()) {
            
            l.findNodeContact(src).contactInfo();
            
            cout << "\n ----------------------------------------- \n\n" << endl;
            cout << "\t> Press 1 to EDIT the contact" << endl;
            cout << "\t> Press 2 to Delete the Contact" << endl;
            cout << "\t> Press 0 to BACK to the MENU" << endl;    

            cout << "\n\t  Enter choice : ";
            string ps;
            cin >> ps;

            int pr = inputValidity(ps);

            if(pr==1 || pr==2) {
                editDelSearch(l.findNodeContact(src), pr);
            }

            else if(pr==-1)
                cout << "\n\t Invalid option\n" << endl;
        
        }           

        else
            cout << "\n\t Contact Not found" << endl;

    }

    else
        cout << "\n\t List is EMPTY" << endl;


    cout << endl;
    system("pause");

}



void deleteContact() {


    if(!l.isEmpty()) {

        system("cls");
        printDeleteMenu();

        cout << "Enter choice : ";
        string str;
        cin >> str;

        int ch = inputValidity(str);
        if(ch==-1) {
            cout << "\n\t Invalid Option\n" << endl;
            system("pause");
            return;
        }

        switch(ch) {

            case 1: {

                l.printList();

                cout << "\n\n\n Enter Serial No : ";
                string str;
                cin >> str;

                int sr = inputValidity(str);
                if(sr==-1) {
                    cout << "\n\t Invalid Option\n" << endl;
                    system("pause");
                    return;
                }

                l.deleteNode(sr);
            }
                break;

            case 2: {

                l.printList();


                vector<int> v;

                cout << "\n\n\n Enter Serial No (Press -1 to stop) : ";


                while(true) {
                    int a;
                    cin >> a;

                    if(a==-1)
                        break;

                    v.push_back(a);
                }

                queue<Node*> qNode;

                for(int i=0; i<v.size(); i++) {
                    qNode.push(l.findNode(v.at(i)));
                }


                int i = 0;
                while(!qNode.empty()) {
                    l.deleteNode_Node(qNode.front(),v.at(i++));
                    qNode.pop();
                }
            

            }
                break;

            case 3: {

                cout << "\n\t Are you sure? (This will delete duplicate contacts)" << endl;
                cout << "\n\t Press ~ Y or N : ";
                string yn;
                cin >> yn;

                if(yn=="Y" || yn=="y") {
                    l.deleteDuplicate();
                }

            }
                break;
            
            default:
                cout << "\n\t Invalid Option\n\n" << endl;
                //system("pause");
                break;

        }


    }

    else
        cout << "\n\t List is EMPTY" << endl;
    
    cout << endl;
    system("pause");


}










int main() {


    while(true) {

        printMenu();

        string choice;
        cout << " Enter choice : ";
        cin >> choice;
        int ch = inputValidity(choice);

        cout << endl;

        switch(ch) {

            case 1: 
                newContact();
                break;


            case 2:
                editContact();
                break;


            case 3: 
                searchContact();
                break;


            case 4: 
                deleteContact();
                break;


            case 5:
                l.printList();
                system("pause");
                break;


            case 6:
                exit(0);
                break;


            default:
                cout << "\n\t Invalid Option\n\n" << endl;
                system("pause");
                break;

        }


        system("cls");

    }





    system("pause");

    return 0;
    
}