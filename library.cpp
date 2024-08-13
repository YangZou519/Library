#include "library.h" //include the head file

Book::Book() : code(0), title(" "), available(0), rented(0){}
Book::Book(int c, string t, int a, int r) : code(c), title(t), available(a), rented(r){}
void Book::setCode(int code){this->code = code;}
void Book::setTitle(string title){this->title = title;}
void Book::setAvailable(int available){this->available = available;}
void Book::setRented(int rented){this->rented = rented;}
int Book::getCode(){return code;}
string Book::getTitle(){return title;}
int Book::getAvailable(){return available;}
int Book::getRented(){return rented;}

ChildrenBook::ChildrenBook():Book(), age(0){}
ChildrenBook::ChildrenBook(int a):age(a){}
void ChildrenBook::setAge(int age){this->age = age;}
int ChildrenBook::getAge(){return age;}

ComputerBook::ComputerBook():publisher(" "){}
ComputerBook::ComputerBook(string p):publisher(p){}
void ComputerBook::setPublisher(string publisher){this->publisher = publisher;}
string ComputerBook::getPublisher(){return publisher;}

Novel::Novel():publish_date(0){}
Novel::Novel(int p_d):publish_date(p_d){}
void Novel::setPublish_date(int publish_date){this->publish_date = publish_date;}
int Novel::getPublish_date(){return publish_date;}

Node::Node():link(NULL){}//set link with null
Node::Node(Book* l, Node* li):library(l), link(li){}
void Node::setBook(Book* library){this->library = library;}
void Node::setLink(Node* link){this->link = link;}
Book* Node::getBook(){return library;}
Node* Node::getLink(){return link;}

Person::Person():id(0), name(" "), count(0){}
Person::Person(int ID, string NAME, int COUNT):id(ID), name(NAME), count(COUNT){}
void Person::setId(int id){this->id = id;}
void Person::setName(string name){this->name = name;}
void Person::setCount(int count){this->count = count;}
int Person::getId(){return id;}
string Person::getName(){return name;}
int Person::getCount(){return count;}

Student::Student(){
    for(int i = 0; i < 2; i++)
        code[i] = 0;
}
Student::Student(int code[]){
    for(int i = 0; i < 2; i++)
        this->code[i] = code[i];
}
void Student::setStudent(int code[]){
    for(int i = 0; i < 2; i++)
        this->code[i] = code[i];
}
int* Student::getStudent(){return code;}

Teacher::Teacher(){
    for(int i = 0; i < 2; i++)
        code[i] = 0;
}
Teacher::Teacher(int code[]){
    for(int i = 0; i < 3; i++)
        this->code[i] = code[i];
}
void Teacher::setTeacher(int code[]){
    for(int i = 0; i < 3; i++)
        this->code[i] = code[i];
}
int* Teacher::getTeacher(){return code;}

Occupation::Occupation():link(NULL){}//set the link null
Occupation::Occupation(Person* d, Occupation* l):data(d), link(l){}
void Occupation::setData(Person* data){this->data = data;}
void Occupation::setLink(Occupation* link){this->link = link;}
Person* Occupation::getData(){return data;}
Occupation* Occupation::getLink(){return link;}

