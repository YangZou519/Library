#ifndef Zou_project2
#define Zou_project2

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class Book //class for store the basic information(code, title, available, rented) for the books.  
{
public:
    Book();//default constructor
    Book(int, string, int, int);

    void setCode(int);//after this function call, the code of the book will set.
    void setTitle(string);//after this function call the title of the book will set
    void setAvailable(int);//after this function call the amount of available of the book will set
    void setRented(int);////after this function call the amount of rented book will set
    int getCode();//after this call this code will return
    string getTitle();//after this call this title will return
    int getAvailable();//after this call this available will return
    int getRented();//after this call this rented will return
    virtual void setAge(int) = 0;//pure vitrual function, refer to ChildrenBook class;
    virtual int getAge() = 0; //pure vitrual function, refer to ChildrenBook class;
    virtual void setPublisher(string) = 0;////pure vitrual function, refer to ComputerBook class;
    virtual string getPublisher() = 0;////pure vitrual function, refer to ComputerBook class;
    virtual void setPublish_date(int) = 0;////pure vitrual function, refer to Novel class;
    virtual int getPublish_date() = 0;////pure vitrual function, refer to Novel class;

private:
    int code;//the code of the book
    string title;//the title of the book
    int available;//amount of the book are available now
    int rented;//amount of the book alreadey rented
};
class ChildrenBook : public Book //child class of Book, use for store the age that stuibale for children of the children book 
{
public:
    ChildrenBook();//default constructor
    ChildrenBook(int);
    void setAge(int);//after this call the age of the book will set
    int getAge();//after this call this age will return
    void setPublisher(string){}//pure vitural function 
    string getPublisher(){return "";}//pure vitural function 
    void setPublish_date(int){}//pure vitural function 
    int getPublish_date(){return 0;}//pure vitural function 
private:
    int age;//age of the children suitable
};
class ComputerBook : public Book //child class of book, use for store the publisher of the computer book
{
public:
    ComputerBook();//default constructor
    ComputerBook(string);

    void setPublisher(string);//after this call the publisher will set
    string getPublisher();//after this call this publisher will return
    void setAge(int){}//pure vitural function 
    int getAge(){return 0;}//pure vitural function 
    void setPublish_date(int){}//pure vitural function 
    int getPublish_date(){return 0;}//pure vitural function 
private:
    string publisher;//publisher of the book
};
class Novel : public Book //child class of Book, use for store the publish date of Novel
{
public:
    Novel();//default constructor
    Novel(int);

    void setPublish_date(int);//after this call the publish date of the book will set
    int getPublish_date();//after this call this publish date will return
    void setPublisher(string){}//pure vitural function 
    string getPublisher(){return "";}//pure vitural function 
    void setAge(int){}//pure vitural function 
    int getAge(){return 0;}//pure vitural function 
private:
    int publish_date;//publish date of the book
};

class Node //this is use for create the static array for the books
{
public:
    Node();//default constructor
    Node(Book*, Node*);
    void setBook(Book*);//after this call the book information will set
    void setLink(Node*);//after this call the link will set
    Book* getBook();//after this call will return this library
    Node* getLink();//after thtis call will return this link
private:
    Book* library;//book infomation
    Node* link;//link of next node
};

class Person
{
public:
    Person();//default constructor
    Person(int, string, int);

    void setId(int);//after this call id will set
    void setName(string);//after this call name will set
    void setCount(int);//after this call count of the person rented the book will set
    int getId();//after this call will return this id
    string getName();//after this call will return this name
    int getCount();//after this call will return this count
    virtual void setStudent(int []){}//pure vitural function refer to Student
    virtual int* getStudent(){return 0;}//pure vitural function refer to Student
    virtual void setTeacher(int []){}//pure vitural function refer to Teacher class
    virtual int* getTeacher(){return 0;}//pure vitural function refer to Teacher class
private:
    int id;//ID of the person
    string name;//name of the person
    int count;//amount of the book this person rented
};
class Student : public Person //child class of Person, use for store the student infomation
{
public:
    Student();//default constructor
    Student(int []);

    void setStudent(int []);//after this call the code of the student rented will return
    int* getStudent();//after this call will return this code
    void setTeacher(int []){}//pure vitural function
    int* getTeacher(){return 0;}//pure vitural function
private:
    int code[2];//array store the code of the student rented
};
class Teacher : public Person //child class of Person, use for store the information of teachers
{
public:
    Teacher();//default constructor
    Teacher(int []);

    void setTeacher(int []);//after this call the code of teacher rented book will set
    int* getTeacher();//after this call the code of teacher rented book will return
    void setStudent(int []){}//pure vitural function
    int* getStudent(){return 0;}//pure vitural function
private:
    int code[3];//array store the code of the teacher rented
};

class Occupation //class use for create the static array of person
{
public:
    Occupation();//default constructor
    Occupation(Person*, Occupation*);
    void setData(Person*); // after this call the data of person will store
    void setLink(Occupation*);//after this call link will store
    Person* getData();//after this call this data will return
    Occupation* getLink();//after this call this link will return
private:
    Person* data;//data have the information of the person
    Occupation* link;//use for creat the static array
};
#endif
