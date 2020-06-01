#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {

    protected:
        string name;
        int age;
        int cur_id;

    public:
        virtual void putdata() = 0;
        virtual void getdata() = 0;
};

class Professor : public Person {

    private:
        static int id_pool;
        int publications;

    public:
    
        Professor() {
            this->cur_id = this->id_pool;
            this->id_pool++;
        }

        virtual void getdata() override {
            cin >> this->name >> this->age >> this->publications;
        }

        virtual void putdata() override {
        cout << this->name << " " << this->age << " " << this->publications << " " << this->cur_id << endl;
    }

};

class Student : public Person {

    private:
        static const int number_of_marks = 6;
        static int id_pool;
        int marks[number_of_marks];

        int sum_of_marks() {
            int sum = 0;
            for (int i=0; i<this->number_of_marks; i++) {
                sum += marks[i];
            }
            return sum;
        }

    public: 

        Student() {
            this->cur_id = this->id_pool;
            this->id_pool++;
        }

        virtual void getdata() override {
            cin >> this->name >> this->age;
            for (int i=0; i<this->number_of_marks; i++) {
                cin >> this->marks[i];
            }
        }

        virtual void putdata() override {
            cout << this->name << " " << this->age << " " << sum_of_marks() << " " << this->cur_id << endl;
        }
};

int Professor::id_pool = 1;
int Student::id_pool = 1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
