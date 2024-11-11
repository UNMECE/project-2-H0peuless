#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <set>

using namespace std;

class Student {
protected:
    string firstname;
    string lastname;
    double gpa;
    int graduation_year;
    string graduation_semester;
    int enrolled_year;
    string enrolled_semester;
    string grad_undergrad;

public:
    Student() {
        firstname = "undefined";
        lastname = "undefined";
        gpa = 0;
        graduation_year = 2024;
        graduation_semester = "undefined";
        enrolled_year = 2024;
        enrolled_semester = "undefined";
        grad_undergrad = "undefined";
    }

    string get_firstname() {
        return firstname;
    }

    string get_lastname() {
        return lastname;
    }

    string get_name() {
        return firstname + " " + lastname;
    }

    double get_gpa() {
        return gpa;
    }

    int get_graduation_year() const {
        return graduation_year;
    }

    string get_graduation_semester() const {
        return graduation_semester;
    }

    int get_enrolled_year() const {
        return enrolled_year;
    }

    string get_enrolled_semester() const {
        return enrolled_semester;
    }

    string get_grad_undergrad() const {
        return grad_undergrad;
    }

    ~Student()=default;

    void set_firstname(string first_name) {
        this->firstname = first_name;
    }
    void set_lastname(string last_name) {
        this->lastname = last_name;
    }
    void set_name(string first_name, string last_name){
        this ->firstname = first_name;
        this ->lastname = last_name;
    };

    void set_gpa(double gpa) {
        this->gpa = gpa;
    }

    void set_graduation_year(int graduation_year) {
        this->graduation_year = graduation_year;
    }

    void set_graduation_semester(string graduation_semester) {
        if (graduation_semester == "Fall" || graduation_semester == "Spring") {
            this->graduation_semester = graduation_semester;
        }
        else{ cerr<< "Not a valid semester" << endl; }
    }
    void set_enrolled_year(int enrolled_year) {
        this->enrolled_year = enrolled_year;
    }
    void set_enrolled_semester(string enrolled_semester) {
        if (enrolled_semester == "Fall" || enrolled_semester == "Spring") {
            this->enrolled_semester = enrolled_semester;
        }
        else{ cerr<< "Not a valid semester" << endl; }
    }

    void set_grad_undergrad(string grad_undergrad) {
        if (grad_undergrad == "Grad" || grad_undergrad == "Undergrad") {
            this->grad_undergrad =grad_undergrad ;
        }
        else{ cerr<< "Please choose Grad or Undergrad" << endl; }
    }


};

class Art_Student:public Student {
    string art_emphasis;
public:
    Art_Student() {
        firstname = "undefined";
        lastname = "undefined";
        gpa = 0;
        graduation_year = 2024;
        graduation_semester = "undefined";
        enrolled_year = 2024;
        enrolled_semester = "undefined";
        grad_undergrad = "undefined";
        art_emphasis = "undefined";
    }
    ~Art_Student()=default;

    string get_art_emphasis() {
        return art_emphasis;
    }
    void set_art_emphasis(string art_emphasis) {
        if(art_emphasis == "Art Studio" || art_emphasis == "Art History" || art_emphasis == "Art Education"){
            this->art_emphasis = art_emphasis;
        }
        else {
            cerr<< "Please choose Art Studio; Art History or Art Education" << endl;
        }
    }


};

class Physic_Student:public Student {
  string concentration;
public:
    Physic_Student() {
        firstname = "undefined";
        lastname = "undefined";
        gpa = 0;
        graduation_year = 2024;
        graduation_semester = "undefined";
        enrolled_year = 2024;
        enrolled_semester = "undefined";
        grad_undergrad = "undefined";
        concentration = "undefined";
    }
    ~Physic_Student()=default;

    string get_concentration() {
        return concentration;
    }
    void set_concentration(string concentration) {
        if(concentration == "Biophysics" || concentration == "Earth and Planetary Science"){
            this->concentration = concentration;
        }
        else {
            cerr<< "Please choose Art Studio; Art History or Art Education" << endl;
        }
    }
};

std::ostream& operator << (std::ostream& outs, Physic_Student& student){
    return outs << student.get_name()
    <<" "
    << student.get_gpa()
    <<" "
    << student.get_graduation_year()
    <<" "
    << student.get_graduation_semester()
    <<" "
    << student.get_enrolled_year()
    <<" "
    << student.get_enrolled_semester()
    <<" "
    << student.get_grad_undergrad()
    <<" "
    <<student.get_concentration();
}
std::ostream& operator << (std::ostream& outs, Art_Student& student){
    return outs << student.get_name()
    <<" "
    << student.get_gpa()
    <<" "
    << student.get_graduation_year()
    <<" "
    << student.get_graduation_semester()
    <<" "
    << student.get_enrolled_year()
    <<" "
    << student.get_enrolled_semester()
    <<" "
    << student.get_grad_undergrad()
    <<" "
    <<student.get_art_emphasis();
}

int main() {
    Art_Student student;
    student.set_art_emphasis("Biophysics");
    student.set_gpa(100);
    student.set_name("Maxime","Prevost");
    student.set_graduation_year(2025);
    student.set_graduation_semester("Spring");
    student.set_enrolled_year(2022);
    student.set_enrolled_semester("Fall");
    student.set_grad_undergrad("Undergrad");
    cout << student << endl;
    return 0;
}
