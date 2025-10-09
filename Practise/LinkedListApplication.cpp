#include<iostream>

using namespace std;

class Course{
    public:
    int code;
    string name;
    Course *prereq;
    Course *nextC;
    Course(){
        code = -1;
        name = " ";
        prereq = NULL;
        nextC = NULL;
    }
    Course(string n, int c){
        code = c;
        name = n;
        prereq = NULL;
        nextC = NULL;
    }
};

class CourseLL{
    public:
    Course *head = NULL;
    Course *tail = NULL;
    void addcourse(){
        Course *temp;
        temp = new Course;
        cin>>temp->code;
        cin>>temp->name;
        if(head == NULL){
            head = temp;
            tail = temp;
        }
        else if(head->code == tail->code){
            head->nextC = temp;
            tail = temp;
        }
        else{
            tail->nextC = temp;
            tail = temp;
        }       
    }
    void addprereq(int coursecode, Course *pre){
        Course *course;
        course = head;
        while(course->nextC != NULL){
            if(course->code == coursecode){
                course->prereq = pre;
            }
            course = course->nextC;
        }
        if(course->code == coursecode){
            course->prereq = pre;
        }
    }
    void CalculateNopre(){
        Course *temp;
        temp = head;
        cout<<"Courses with no Pre-requisites: "<<endl;
        while (temp != NULL){
            if(temp->prereq == NULL){
                cout<<"Name: "<<temp->name<<endl;
                cout<<"Code: "<<temp->code<<endl;
            }
            temp = temp->nextC;
        }
    }
    void CalculateLongestPre(){
        Course *Max = head;
        Course *pre;
        Course *temp;
        temp = head;
        int count =0;
        int max = -1;
        while(temp != NULL){
            count = 0;
            pre = temp;
            while(pre->prereq != NULL){
                count++;
                pre = pre->prereq;
            }
            if(count > max){
                max = count;
                Max = temp;
            }
            temp = temp->nextC;
        }
        cout<<"The longest Pre-requisite course is: "<<endl;
        cout<<"Course code: "<<Max->code<<endl;
        cout<<"Course name: "<<Max->name<<endl;
    }
    void display(){
        Course *temp;
        temp = head;
        while(temp != NULL){
            cout<<"Course code: "<<temp->code<<endl;
            cout<<"Course name: "<<temp->name<<endl;
            temp = temp->nextC;
        }
    }
};

int main(){
    CourseLL List;
    List.addcourse();
    List.addcourse();
    List.addcourse();
    List.addcourse();
    Course C1("OOP", 1002);
    Course C2("PF",1001);
    Course C3("AP",1003);
    List.addprereq(1000, &C1);
    List.addprereq(1002, &C2);
    List.addprereq(1004,&C3);
    List.display();
    List.CalculateNopre();
    List.CalculateLongestPre();
}