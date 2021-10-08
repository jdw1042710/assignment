#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>
#include <iomanip>

using namespace std;


class Student{
    private:
        string name;
        string studentID;
        string birthYear;
        string department;
        string telephone;

    public:
        Student(){}
        void setName(string name){
            this->name = name;
        }
        void setStudentID(string studentID){
            this->studentID = studentID;
        }
        void setBirthYear(string birthYear){
            this->birthYear = birthYear;
        }
        void setDepartment(string department){
            this->department = department;
        }
        void setTelephone(string telephone){
            this->telephone = telephone;
        }
        
        string getName() {
            return this->name;
        }
        string getStudentID() {
            return this->studentID;
        }
        string getBirthYear() {
            return this->birthYear;
        }
        string getDepartment() {
            return this->department;
        }
        string getTelephone() {
            return this->telephone;
        }
};

class StudentDB{
    private:
        vector<Student> studentList;
        string fileDirectory = "file1.txt";
        int option = 1;

        void loadFile(){

        }

        void saveFile(){

        }

        bool checkName(string name){
            if (0 == name.length() || 15 < name.length()){
                return false;
            }
            return true;
        }
        bool checkStudentID(string studentID){
            regex standard("\\d{10}");
            if (!regex_match(studentID, standard)){
                return false;
            }
            if (1000 > stoi(studentID.substr(0, 4)) || 2022 < stoi(studentID.substr(0, 4))){
                return false;
            }
            for (int i = 0; i < studentList.size(); i++){
                if(studentList.at(i).getStudentID() == studentID){
                    return false;
                }
            }
            return true;
        }
        bool checkBirthYear(string birthYear){
            regex standard("\\d{4}");
            if (!regex_match(birthYear, standard)){
                return false;
            }
            return true;
        }
        bool checkTelephone(string telephone){
            regex standard("\\d{0, 12}");
            if (!regex_match(telephone, standard)){
                return false;
            }
            return true;
        }
        void sorting(){
            switch(option){
                case 1:
                    sort(studentList.begin(), studentList.end(), compareName);
                    break;
                case 2:
                    sort(studentList.begin(), studentList.end(), compareStudentID);
                    break;
                case 3:
                    sort(studentList.begin(), studentList.end(), compareAdmissionYear);
                    break;
                case 4:
                    sort(studentList.begin(), studentList.end(), compareDepartment);
                    break;
            }

        }
        static bool compareName(Student a, Student b) {
            string n1 = a.getName();
            string n2 = b.getName();
		    return n1 > n2;
        }
        static bool compareStudentID(Student a, Student b) {
            string n1 = a.getStudentID();
            string n2 = b.getStudentID();
		    return n1 > n2;
        }
        static bool compareAdmissionYear(Student a, Student b) {
            string n1 = a.getStudentID().substr(0,4);
            string n2 = b.getStudentID().substr(0,4);
		    return n1 > n2;
        }
        static bool compareDepartment(Student a, Student b) {
            string n1 = a.getDepartment();
            string n2 = b.getDepartment();
		    return n1 > n2;
            }
        void searchByName(){
            string keyword;
            cout << "Name keyword? ";
            cin >> keyword;
            cout.setf(ios::left);
            cout << setw(16) << "Name" << setw(11) << "StudentID" << setw(25) << "Dept" << setw(11) << "BirthYear" << setw(12) << "Tel" << endl;
            cout.setf(ios::right);
            for (int i = 0; i < studentList.size(); i++){
                Student temp = studentList[i];
                if(keyword == temp.getName()){
                    cout << setw(16) << temp.getName() << setw(11) << temp.getStudentID() << setw(25) << temp.getDepartment() << setw(11) << temp.getBirthYear() << setw(12) << temp.getTelephone() << endl;
                }
            }
        }
        void searchByStudentID(){
            string keyword;
            cout << "Student ID keyword? ";
            cin >> keyword;
            cout.setf(ios::left);
            cout << setw(16) << "Name" << setw(11) << "StudentID" << setw(25) << "Dept" << setw(11) << "BirthYear" << setw(12) << "Tel" << endl;
            cout.setf(ios::right);
            for (int i = 0; i < studentList.size(); i++){
                Student temp = studentList[i];
                if(keyword == temp.getStudentID()){
                    cout << setw(16) << temp.getName() << setw(11) << temp.getStudentID() << setw(25) << temp.getDepartment() << setw(11) << temp.getBirthYear() << setw(12) << temp.getTelephone() << endl;
                }
            }
        }
        void searchByAdmissionYear(){
            string keyword;
            cout << "Admission Year keyword? ";
            cin >> keyword;
            cout.setf(ios::left);
            cout << setw(16) << "Name" << setw(11) << "StudentID" << setw(25) << "Dept" << setw(11) << "BirthYear" << setw(12) << "Tel" << endl;
            cout.setf(ios::right);
            for (int i = 0; i < studentList.size(); i++){
                Student temp = studentList[i];
                if(keyword == temp.getStudentID().substr(0, 4)){
                    cout << setw(16) << temp.getName() << setw(11) << temp.getStudentID() << setw(25) << temp.getDepartment() << setw(11) << temp.getBirthYear() << setw(12) << temp.getTelephone() << endl;
                }
            }
        }
        void searchByDepartmentName(){
            string keyword;
            cout << "Department Name keyword? ";
            cin >> keyword;
            cout.setf(ios::left);
            cout << setw(16) << "Name" << setw(11) << "StudentID" << setw(25) << "Dept" << setw(11) << "BirthYear" << setw(12) << "Tel" << endl;
            cout.setf(ios::right);
            for (int i = 0; i < studentList.size(); i++){
                Student temp = studentList[i];
                if(keyword == temp.getDepartment()){
                    cout << setw(16) << temp.getName() << setw(11) << temp.getStudentID() << setw(25) << temp.getDepartment() << setw(11) << temp.getBirthYear() << setw(12) << temp.getTelephone() << endl;
                }
            }
        }
        void listAll(){
            cout.setf(ios::left);
            cout << setw(16) << "Name" << setw(11) << "StudentID" << setw(25) << "Dept" << setw(11) << "BirthYear" << setw(12) << "Tel" << endl;
            cout.setf(ios::right);
            for (int i = 0; i < studentList.size(); i++){
                Student temp = studentList[i];
                cout << setw(16) << temp.getName() << setw(11) << temp.getStudentID() << setw(25) << temp.getDepartment() << setw(11) << temp.getBirthYear() << setw(12) << temp.getTelephone() << endl;
            }
        }
    public:
        StudentDB(){}
        void insertion(){
            Student temp;
            string answer;

            cout << "Name? ";
            cin >> answer;
            if(!checkName(answer)){
                cout << "'Name' has up to 15 (English) characters" << endl;
                cout << "Return to menu (Press Enter..)";
                cin >> answer;
                return;
            }
            temp.setName(answer);

            cout << "Student ID (10 digits)? ";
            cin >> answer;
            if(!checkStudentID(answer)){
                cout << "'Student ID' should be exactly 10 digits where first 4 digits represent admission year" << endl;
                cout << "Return to menu (Press Enter..)";
                cin >> answer;
                return;
            }
            temp.setStudentID(answer);

            cout << "Birth Year (4 digits)? ";
            cin >> answer;
            if(!checkBirthYear(answer)){
                cout << "'Birth Year' should be exactly 4 digits." << endl;
                cout << "Return to menu (Press Enter..)";
                cin >> answer;
                return;
            }
            temp.setBirthYear(answer);

            cout << "Department? ";
            cin >> answer;
            temp.setDepartment(answer);

            cout << "Tel? ";
            cin >> answer;
            if(!checkTelephone(answer)){
                cout << "'Tel' has up to 12 digits." << endl;
                cout << "Return to menu (Press Enter..)";
                cin >> answer;
                return;
            }     
            temp.setTelephone(answer);
            studentList.push_back(temp);
            cout << "Successfully inserted! (Press Enter..)";
            cin >> answer; 
        }
        void search(){           
            sorting();
            while(true){
                int answer;

                cout << "- Search -" << endl;
                cout << "1. Search by name" << endl;
                cout << "2. Search by student ID (10 numbers)" << endl;
                cout << "3. Search by admission year (4 numbers)" << endl;
                cout << "4. Search by department name" << endl;
                cout << "5. List All" << endl;
                cout << ">";
                cin >> answer;
                switch(answer){
                    case 1:
                        searchByName();
                        return;
                    case 2:
                        searchByStudentID();
                        return;
                    case 3:
                        searchByAdmissionYear();
                        return;
                    case 4:
                        searchByDepartmentName();
                        return;
                    case 5:
                        listAll();
                        return;
                    default:
                        cout << "Please input only number in [1-5]" << endl;
                }
            }
        }
        void sortingOption () {
            while(true){
                int answer;

                cout << "1. Sort by Name" << endl;
                cout << "2. Sort by Student ID" << endl;
                cout << "3. Sort by AdmissionYear" << endl;
                cout << "4. Sort by Department" << endl;
                cout << ">";
                cin >> answer;
                if (0 < answer && answer <= 4){
                    this->option = answer;
                    break;
                }
                cout << "Please input only number in [1-4]" << endl;
            }
            
        }
        ~StudentDB(){
            saveFile();
        }
};

class Menu{
    private:
        StudentDB studentDB;

        void printMenu(){
            cout << "1. Insertion" << endl;
            cout << "2. Search" << endl;
            cout << "3. Sorting Option" << endl;
            cout << "4. Exit" << endl;
            cout << ">";
        }

    public:
        Menu(){
            while(true){
                int answer;
                printMenu();
                cin >> answer;
                switch(answer){
                    case 1:
                        studentDB.insertion();
                        break;
                    case 2:
                        studentDB.search();
                        break;
                    case 3:
                        studentDB.sortingOption();
                        break;
                    case 4:
                        return;
                        break;
                    default:
                        cout << "Please input only number in [1-4]" << endl;
                        break;
                }
            }
        }
};


int main(void){
    Student p1;
    string str = "9999999999";
    Menu menu;
}