#include "library.cpp"
void sort(Node* &, Node* );//after this call the static array will sort in ascending order by the code of the book
void sortPerson(Occupation* &, Occupation* );

int main(){
    ifstream inStream;
    inStream.open("book.txt");//open file 
    if(inStream.fail()){//if the instream fail
        cout << "Input file opening failed.\n";
        exit(1);
    }
    Node** library = new Node*[3];//creat a dynamic array use for store the information of the three type of book
    int code, available, rented, age, date;//use for pass the value from the file
    string title, publisher;//use for pass the value from the file
    while(!inStream.eof()){
        inStream >> code >> title;//pass the code and title first
        if(code >= 1001 && code <= 2000){//if the code is greater than 1000 and less than 2001 then it is children book
            inStream >> age >> available >> rented;//pass the value from the file
            Book* child = new ChildrenBook;//create for store the children book information, and 'setBook()' function
            child->setCode(code);//set code of the book
            child->setTitle(title);//set title of the book
            child->setAge(age);//set the age are sutitable for children
            child->setAvailable(available);//set amount of the book are available
            child->setRented(rented);//set amount of the book are rented
            Node* child_ptr = new Node;//create a static array to store the information of children book
            child_ptr->setBook(child);//set the book inforation
            child_ptr->setLink(NULL);//set link with null
            sort(library[0], child_ptr);//after this call the array will sort to ascending order of code of the book
        }
        if(code >= 2001 && code <= 3000){//if the code is greater than 2000 and less than 3001 then it is children book
            inStream >> publisher >> available >> rented;//pass the value from the file
            Book* computer = new ComputerBook;//create for store the computer book information, and 'setBook()' function
            computer->setCode(code);//set code of the book
            computer->setTitle(title);//set title of the book
            computer->setPublisher(publisher);//set publisher of the book
            computer->setAvailable(available);//set amount of the book are available
            computer->setRented(rented);//set amount of the book are rented
            Node* computer_ptr = new Node;//create a static array to store the information of computer book
            computer_ptr->setBook(computer);//set the book information
            computer_ptr->setLink(NULL);//set link with null
            sort(library[1], computer_ptr);//after this call the array will sort to ascending order of code of the book
        }
        if(code >= 3001 && code <= 4000){//if the code is greater than 3000 and less than 4001 then it is children book
            inStream >> date >> available >> rented;//pass the value from the file
            Book* novel = new Novel;//create for store the novel information, and 'setBook()' function
            novel->setCode(code);//set code of the book
            novel->setTitle(title);//set title of the book
            novel->setPublish_date(date);//set date of the book
            novel->setAvailable(available);//set amount of the book are available
            novel->setRented(rented);//set amount of the book are rented
            Node* novel_ptr = new Node;//create a static array to store the information of Novel
            novel_ptr->setBook(novel);//set the book information
            novel_ptr->setLink(NULL);//set link with null
            sort(library[2], novel_ptr);//after this call the array will sort to ascending order of code of the book
        }
    }
    inStream.close();//close the file

    inStream.open("person.txt");//open the person file
    if(inStream.fail()){//if the instream fail
        cout << "Input file opening failed.\n";
        exit(1);
    }
    Occupation** data = new Occupation*[2];//creat a dynamic array use for store the information of student and teacher
    int id, i = 0;//id is use for pass the value from the  file, i is the variable use for array
    int* teacher_code = new int[3];//create for store the book code are rented by the teacher
    int* student_code = new int[2];//store the book code are retned by the student
    string name;//use for pass the value from the file
    while(!inStream.eof()){
        for(i = 0; i < 3; i++)//store teacher_code with all zeros;
            teacher_code[i] = 0;
        inStream >> id >> name >> rented;//pass the value from the file
        if(id >= 1 && id <= 100){//if id between 0 and 101 then he is teacher
            Person* list = new Teacher;//use for store the teacher's information
            if(rented == 1)//if the amount of the teacher's rented is 1
                inStream >> teacher_code[0];//pass the value from file
            if(rented == 2)//if the amount of the teacher's rented is 2
                inStream >> teacher_code[0] >> teacher_code[1];//pass the value from file
            if(rented == 3)//if the amount of the teacher's rented is 3
                inStream >> teacher_code[0] >> teacher_code[1] >> teacher_code[2];//pass the value from file
            list->setId(id);//set id of the person
            list->setName(name);// set the name of the person
            list->setCount(rented);//set the amount of the person rented
            list->setTeacher(teacher_code);//set the teacher's information
            Occupation* ptr = new Occupation;//use for store teacher's information in a static array
            ptr->setData(list);//set teacher's information
            ptr->setLink(NULL);//set link with null
            sortPerson(data[0], ptr);//after this call the array will sort in ascending order of the id of the people
        }
        for(i = 0; i < 2; i++)//set student code wih all zeros
            student_code[i] = 0;
        if(id >= 101 && id <= 300){//if id is between 100 and 301 he is a student
            Person* list = new Student;//use for store the infomation of the student
            if(rented == 1)//if the amount of the student rented is 1
                inStream >> student_code[0];//pass the value from the file
            if(rented == 2)//if the amount of the student rented is 2
                inStream >> student_code[0] >> student_code[1];//pass the value from the file
            list->setId(id);//set the student's id
            list->setName(name);//set the student's name
            list->setCount(rented);//set the amount of the student rendted
            list->setStudent(student_code);//set the studen inforamtion
            Occupation* ptr = new Occupation;//use for store student's information in a static array
            ptr->setData(list);//set student's information
            ptr->setLink(NULL);//set link with null
            sortPerson(data[1], ptr);//after this call the array will sort in ascending order of the id of the people
        }
    }
    inStream.close();//close the file
    int answer, ID;//answer is the user input for select the option he wants to use
    char choice;//choice is the user input answer (y/n)
    do{
        cout << "\n\n---------------------------\n         Menu         \n---------------------------\n1. Search a book\n2. Rent a book\n3. Return a book\n4. Show my information\n5. Show all books\n6. Exit\n\nSelect (1~6) : ";
        cin >> answer;//user input his choice of the options
        if(answer == 1){//if the user's answer is 1
            cout << "\nEnter code  : ";
            cin >> code;//user input the code of the book want to search
            cout << "Enter title : ";
            cin >> title;//user input the title of the book want to search
            Node* ptr = new Node;//will use for the temp of the book 
            try{
                for(i = 0; i < 3; i++)//i is the type of the book, 0 is children book, 1 is computer book, 2 is novel
                    for (ptr = library[i]; ptr; ptr = ptr->getLink()){//let ptr equal book, while ptr is not null ptr will go to next link
                        if(code == (ptr->getBook())->getCode() && title == (ptr->getBook())->getTitle()) throw i;//if code and title are find then throw i
                        if(i == 2 && !(ptr->getLink()))//if the loop end means that the user input is not find
                            cout << endl << title << "(" << code << ") is not found!"; 
                    }
            }
            catch (int x){
                cout << endl << title << "(" << code << ") exists.\ncategory : ";
                if(x == 0)//0 means children book
                    cout << "children\nage : " << (ptr->getBook())->getAge() << endl << (ptr->getBook())->getAvailable() << " available, " << (ptr->getBook())->getRented() << " rented" << endl;
                if(x == 1)//1 means computer book
                    cout << "computer\npublisher : " << (ptr->getBook())->getPublisher() << endl << (ptr->getBook())->getAvailable() << " available, " << (ptr->getBook())->getRented() << " rented" << endl;
                if(x == 2)//2 means novel
                    cout << "novel\npublash date : " << (ptr->getBook())->getPublish_date() << endl << (ptr->getBook())->getAvailable() << " available, " << (ptr->getBook())->getRented() << " rented" << endl;   
            }
        }
        if(answer == 2){
            Occupation* ptr = new Occupation;//temp for the person 
            Node* book = new Node;// temp for the book 
            cout << "Enter your id     : ";
            cin >> ID;//user input id want return
            cout << "Enter book title  : ";
            cin >> title;//user input title want return
            try{
                for(i = 0; i < 2; i++){// 0 is teacher, 1 is student
                    for (ptr = data[i]; ptr; ptr = ptr->getLink()){//let ptr equal to person, while ptr is not null ptr will go to next link
                        if(ID== (ptr->getData())->getId())throw i;//if id is find then throw i
                        if(i == 1 && !(ptr->getLink()))//if the loop end means that the user input is not find
                            cout << "\nID not found!";
                    }
                }
            }
            catch(int x){
                cout << "\nYour are " << (ptr->getData())->getName() << ". You rented " << (ptr->getData())->getCount() << " book.\nDo you want to rent '" << title << "' (y/n)? ";
                cin >> choice;//user input (y/n);
                if(choice == 'y'){//if choice is y
                    if(ID >= 1 && ID <= 100){//if id is between 0 and 101 means he is a teacher
                        try{
                            for(i = 0; i < 3; i++){//i is three types of book
                                for (book = library[i]; book; book = book->getLink()){
                                    if(title == (book->getBook())->getTitle()) throw book->getBook();//if title found throw book->getBook()
                                    if(i == 2 && !(book->getLink()))//if loop end then the title is not found
                                        cout << endl << title << " is not found!"; 
                                }  
                            }  
                        }
                        catch(Book* temp){
                            if((ptr->getData())->getCount() >= 3 && temp->getAvailable() > 0)//if the book he rented is greater than 2 and library have available book
                                cout << "\nSorry, your permission is limited to renting three books.";
                            if((ptr->getData())->getCount() <= 3 && temp->getAvailable() < 1)//if the book he rented is less than 3 and library doesn't have available book
                                cout << "\nAll '" << title << "' has been rented out.";
                            if((ptr->getData())->getCount() < 3 && (book->getBook())->getAvailable() > 0)//if the book he rented is less than 3 and library have abailable book
                            {
                                cout << "\n***** Rent succeed. Check your info!";
                                temp->setAvailable((book->getBook())->getAvailable() - 1);//update available book -1
                                temp->setRented((book->getBook())->getRented() + 1);//update rented book +1
                                (ptr->getData())->setCount((ptr->getData())->getCount() +1);//update person rented book +1
                                for(int k = 0; k < 3; k++)
                                    teacher_code[k] = (ptr->getData())->getTeacher()[k];//copy the book code the person rented
                                teacher_code[((ptr->getData())->getCount())-1] = temp->getCode();//set the new book the person just rent
                                (ptr->getData())->setTeacher(teacher_code);//update the book code the person rented
                            }
                        }
                    }
                    if(ID >= 101 && ID <=300){
                        try{
                            for(i = 0; i < 3; i++){//i is three types of book
                                for (book = library[i]; book; book = book->getLink()){
                                    if(title == (book->getBook())->getTitle()) throw book->getBook();//if the title find then throw book->getBook()
                                    if(i == 2 && !(book->getLink()))//if loop end then the title is not found
                                        cout << endl << title << " is not found."; 
                                }  
                            }  
                        }
                        catch(Book* x){
                            if((ptr->getData())->getCount() <= 2 && x->getAvailable() < 1)//if the book he rented is less than 2 and library have no available book
                                cout << "\nAll '" << title << "' has been rented out.";
                            if((ptr->getData())->getCount() >= 2 && x->getAvailable() > 0)////if the book he rented is greater than 2 and library have available book
                                cout << "\nSorry, your permission is limited to renting two books.";
                            if((ptr->getData())->getCount() < 2 && (book->getBook())->getAvailable() > 0)//if the book he rented is less than 2 and library have abailable book
                            {
                                cout << "\n***** Rent succeed. Check your info!";
                                x->setAvailable((book->getBook())->getAvailable() - 1);//update available book -1
                                x->setRented((book->getBook())->getRented() + 1);//update rented book +1
                                (ptr->getData())->setCount((ptr->getData())->getCount() +1);//update person rented book +1
                                for(int k = 0; k < 2; k++)
                                    student_code[k] = (ptr->getData())->getStudent()[k];//copy the book code the person rented
                                student_code[((ptr->getData())->getCount())-1] = x->getCode();//set the new book the person just rent
                                (ptr->getData())->setStudent(student_code);//update the book code the person rented
                            }
                        }
                    }
                }
                else//if choice is not y
                    cout << "\nOk, have a good one!";
            }
        }
        if(answer == 3){
            cout << "\nEnter your id     : ";
            cin >> ID;//user input person's id
            cout << "Enter the book code to return : ";
            cin >> code;//user input the book code wants to return
            Node* book = new Node;//temp for store the book information
            Occupation* ptr = new Occupation;//temp for store the person information
            try{
                for(i = 0; i < 2; i++)//0 is teacher, 1 is student
                    for (ptr = data[i]; ptr; ptr = ptr->getLink()){
                        if(ID== (ptr->getData())->getId())throw i;//if the id find then throw i
                        if(i == 1 && !(ptr->getLink()))//if the loop end means that id is not found
                            cout << "\nID not found!";
                    }
            }
            catch(int x){//catch i
                try{
                    for(i = 0; i < 3; i++){//i is the three types of book
                        for (book = library[i]; book; book = book->getLink()){//book = library[i], while book is not null, book will go to next link
                            if(code == (book->getBook())->getCode()) throw book->getBook();//if code find then throw book->getBook()
                            if(i == 2 && !(book->getLink()))//if the loop end means that the code is not find
                                cout << endl << "Book code (" << code << ") is not exists."; 
                        }
                    }
                }
                catch(Book* temp){//catch book->getBook()
                    cout << "\nDo you want to return '" << temp->getTitle() << "' (y/n)?";
                    cin >> choice;//user type (y/n)
                    if(choice == 'y'){//if user type y
                        if(ID <= 100){//if id is less than 101 then he is a teacher
                            for(i = 0; i < 3; i++){//i is the teacher's rented book's code
                                if(code == ((ptr->getData())->getTeacher())[i]){//if the code is find in the teacher's rented book list
                                    for(int l = 0; l < 3; l++)
                                        teacher_code[l] = ((ptr->getData())->getTeacher())[l];//copy the teacher's rented book's code list
                                    teacher_code[i] = 0;//the book is return then update with 0
                                    (ptr->getData())->setTeacher(teacher_code);//set the new updatedlist
                                    (ptr->getData())->setCount((ptr->getData())->getCount() - 1);//update the total rented book amount
                                    temp->setAvailable(temp->getAvailable() + 1);//update the book available info in library
                                    temp->setRented(temp->getRented() - 1);//update the book rented info in linbrary
                                    cout << "\n***** Return succeed. Check your info!";
                                    break;//stop the loop
                                }
                                if(i == 2 && code != ((ptr->getData())->getTeacher())[i])//if i == 2 and code is not find means, you didn't rent this book
                                    cout << "\nYou didn't rent this book.";
                            }
                        }
                        else{        
                            for(i = 0; i < 2; i++){//i is the studet rented book's code
                                if(temp->getCode() == ((ptr->getData())->getStudent())[i]){//if the code find in the list
                                    for(int l = 0; l < 2; l++)
                                        student_code[l] = ((ptr->getData())->getStudent())[l];//copy all code of all the student rented
                                    student_code[i] = 0;//the book return, then update with 0
                                    (ptr->getData())->setStudent(student_code);//update the student rented book
                                    (ptr->getData())->setCount((ptr->getData())->getCount() - 1);//update the student rented book amount
                                    temp->setAvailable(temp->getAvailable() + 1);//update the book available amount in the library
                                    temp->setRented(temp->getRented() - 1);//update the book rented amount in the library
                                    cout << "***** Return succeed. Check your info!";
                                    break;//stop the loop
                                }
                                if(i == 1 && code != ((ptr->getData())->getStudent())[i])//if i == 1 and the code is not find means that you didn't rent this book
                                    cout << "You didn't rent this book.";
                            }
                        }
                    }
                    else  //if user input other than 'y'  
                        cout << "\nOk, have a good one!";
                }
            }
        }
        if(answer == 4){
            cout << "Enter your id   : ";
            cin >> ID;//user input his id
            cout << "Enter your name : ";
            string name; 
            cin >> name;//user input his name
            Occupation* ptr = new Occupation;//temp for copy the person information
            Node* book = new Node;//temp for copy the book information
            try{
                for(i = 0; i < 2; i++){//0 is teacher's list, 1 is student's list
                    for (ptr = data[i]; ptr; ptr = ptr->getLink()){
                        if(ID == (ptr->getData())->getId() && name == (ptr->getData())->getName())throw i;//if the id and the name find throw i
                        if(i == 1 && !(ptr->getLink()))//if i == 1 and ptr == null means the id and name not find 
                            cout << "\nI can't find you! Please check your input.";
                    }
                }
            }
            catch(int x){
                cout << "\nYou rented " << (ptr->getData())->getCount();
                if ((ptr->getData())->getCount() > 1)//if the amount of the person rented is greater than 1 then use books
                    cout << " books.";
                else
                    cout << " book.";
                if(ID >= 1 && ID <= 100 && (ptr->getData())->getCount() > 0)//id between 0 to 101 is teacher, 
                    for(i = 0; i < 3; i++)//teacher can rent 3 books so the array size is 3
                        for(int j = 0; j < 3; j++)//j is the three types of book
                            for (book = library[j]; book; book = book->getLink())
                                if((ptr->getData())->getTeacher()[i] == (book->getBook())->getCode())//find the rented book information in the library
                                {
                                    if((book->getBook())->getCode() >= 1001 && (book->getBook())->getCode() <= 2000)//code between 1000 to 2001 is childrenbook
                                        cout << "\n* " << (book->getBook())->getTitle() << "(" << (book->getBook())->getCode() << ") - age : " << (book->getBook())->getAge();
                                    if((book->getBook())->getCode() >= 2001 && (book->getBook())->getCode() <= 3000)//code between 2000 to 3001 is computer book
                                        cout << "\n* " << (book->getBook())->getTitle() << "(" << (book->getBook())->getCode() << ") - publisher : " << (book->getBook())->getPublisher();
                                    if((book->getBook())->getCode() >= 3001 && (book->getBook())->getCode() <= 4000)//code between 3000 to 4001 is novel
                                        cout << "\n* " << (book->getBook())->getTitle() << "(" << (book->getBook())->getCode() << ") - publisher date : " << (book->getBook())->getPublish_date();
                                }
                if(ID >= 101 && ID <= 300 && (ptr->getData())->getCount() > 0)//id between 100 to 301 is student
                    for(i = 0; i < 2; i++)//student can rent 2 books so the array size is 2
                        for(int j = 0; j < 3; j++)//j is the three types of the book
                            for (book = library[j]; book; book = book->getLink())
                                if((ptr->getData())->getStudent()[i] == (book->getBook())->getCode())//find the book information in the library
                                {
                                    if((book->getBook())->getCode() >= 1001 && (book->getBook())->getCode() <= 2000)//code between 1000 to 2001 is childrenbook
                                        cout << "\n* " << (book->getBook())->getTitle() << "(" << (book->getBook())->getCode() << ") - age : " << (book->getBook())->getAge();
                                    if((book->getBook())->getCode() >= 2001 && (book->getBook())->getCode() <= 3000)//code between 2000 to 3001 is computer book
                                        cout << "\n* " << (book->getBook())->getTitle() << "(" << (book->getBook())->getCode() << ") - publisher : " << (book->getBook())->getPublisher();
                                    if((book->getBook())->getCode() >= 3001 && (book->getBook())->getCode() <= 4000)//code between 3000 to 4001 is novel
                                        cout << "\n* " << (book->getBook())->getTitle() << "(" << (book->getBook())->getCode() << ") - publisher date : " << (book->getBook())->getPublish_date();
                                }
            }
        }
        if(answer == 5){
            cout.setf(ios::fixed);
            cout.setf(ios::showpoint);
            cout.setf(ios::right);//leave spaces to the right
            cout << "\n==============================================================\n                     Children Books\n==============================================================\ncode               title             age   available  rented\n--------------------------------------------------------------\n";
            Node* ptr = new Node;//temp for the library 
            for (ptr = library[0]; ptr; ptr = ptr->getLink()){//[0] is children book
                char* temp = new char[((ptr->getBook())->getTitle()).length()];//creat temp of the book title
                cout << (ptr->getBook())->getCode();
                for(i = 0; i < ((ptr->getBook())->getTitle()).length(); i++){//copy the book title to char data type
                    if(((ptr->getBook())->getTitle())[i] == '_')//if is '_' then save ' '
                        temp[i] = ' ';
                    else
                        temp[i] = ((ptr->getBook())->getTitle())[i];//copy the characters 
                }
                title = temp;//cstring to string
                cout.width(30);//30 spaces to the right
                cout << title;
                cout << setw(5) << (ptr->getBook())->getAge() << setw(10) << (ptr->getBook())->getAvailable() << setw(8) << (ptr->getBook())->getRented() << endl;
                delete[] temp;//delete the spaces in the heap
            }
            cout << "\n============================================================================\n                           Computer Books\n============================================================================\ncode                  title               publisher      available  rented\n----------------------------------------------------------------------------\n";
            for (ptr = library[1]; ptr; ptr = ptr->getLink()){//library[1] is computer book
                char* temp = new char[((ptr->getBook())->getTitle()).length()];//temp for the title
                char* pub_temp = new char[((ptr->getBook())->getPublisher()).length()];//temp for copy the publisher
                cout << (ptr->getBook())->getCode();
                for(i = 0; i < ((ptr->getBook())->getTitle()).length(); i++){
                    if(((ptr->getBook())->getTitle())[i] == '_')//if the charater is '_' then store space' '
                        temp[i] = ' ';
                    else
                        temp[i] = ((ptr->getBook())->getTitle())[i];//copy the charaters
                }
                title = temp;//cstring to string
                cout.width(30);//30 spaces to the right
                cout << title;
                for(i = 0; i < ((ptr->getBook())->getPublisher()).length(); i++){
                    if(((ptr->getBook())->getPublisher())[i] == '-')//if charater is '-' then store ' '
                        pub_temp[i] = ' ';
                    else
                        pub_temp[i] = ((ptr->getBook())->getPublisher())[i];//copy the letters
                }
                publisher = pub_temp;//cstring to string
                cout.width(20);//20 spaces to the right
                cout << publisher;
                cout << setw(9) << (ptr->getBook())->getAvailable() << setw(8) << (ptr->getBook())->getRented() << endl;
                delete[] temp;//delete the spaces created in the heap
                delete[] pub_temp;//delete the spaces created in the heap
            }
            cout << "\n======================================================================\n                                 Novel\n======================================================================\ncode               title         publish date     available  rented\n----------------------------------------------------------------------\n";
            for (ptr = library[2]; ptr; ptr = ptr->getLink()){//library[2] is novel
                char* temp = new char[((ptr->getBook())->getTitle()).length()];//temp for the title
                cout << (ptr->getBook())->getCode();
                for(i = 0; i < ((ptr->getBook())->getTitle()).length(); i++){
                    if(((ptr->getBook())->getTitle())[i] == '_')//if the charater is '_' then store ' '
                        temp[i] = ' ';
                    else
                        temp[i] = ((ptr->getBook())->getTitle())[i];//copy the letters
                }
                title = temp;//cstring to string
                cout.width(25);//25 spaces to the right
                cout << temp;
                cout << setw(12) << (ptr->getBook())->getPublish_date() << setw(15) << (ptr->getBook())->getAvailable() << setw(8) << (ptr->getBook())->getRented() << endl;
                delete[] temp;//delete the spaces created in heap
            }
            
        }
    }while (answer != 6);//while answer is not 6 this loop will run forever

    for(i = 0; i < 3; i++){
        delete library[i];//delete all books information in heap
        if(i < 2)
            delete data[i]; //delete all people information in heap
    }
    delete[] library;//delete library's space in heap
    delete[] data;//delete person's space in heap
    delete[] teacher_code;//delete teacher's rented books' code
    delete[] student_code;//delete student's rented books' code
    return 0;
}
void sort(Node* &data, Node* ptr){//after this call the library's static array will pass, and will sort in ascending order
    if (!data)//if data is null
        data = ptr;//data will have ptr 
    else{
        if((ptr->getBook())->getCode() < (data->getBook())->getCode()){//if the code is less than data's book code
                    ptr->setLink(data);//this ptr will insert behind the head
                    data = ptr;
                }
                else{
                    Node* temp = data;
                    Node* prev = data;//the previous ptr
                    for(temp = data; temp; temp = temp->getLink()){
                        if((ptr->getBook())->getCode() < (temp->getBook())->getCode()){//if the ptr book code is less than the library book code
                            ptr->setLink(temp);
                            prev->setLink(ptr);//insert ptr between prev and temp
                            break;//stop the loop
                        }
                        if(!temp->getLink()){//if the temp is null meas that all book code are less than the ptr book
                            temp->setLink(ptr);//insert ptr at the end of the array
                            break;//stop the loop
                        }
                        prev = temp;//update previous
                    }
                }
    }
}
void sortPerson(Occupation* &data, Occupation* ptr){//after this call the person's static array will pass, and will sort in ascending order
    if (!data)//if data is null
        data = ptr;//data will have ptr 
    else{
        if((ptr->getData())->getId() < (data->getData())->getId()){//if the code is less than data's id
                    ptr->setLink(data);//this ptr will insert behind the head
                    data = ptr;
                }
                else{
                    Occupation* temp = data;
                    Occupation* prev = data;//the previous ptr
                    for(temp = data; temp; temp = temp->getLink()){
                        if((ptr->getData())->getId() < (temp->getData())->getId()){//if the ptr's id is less than the person's id
                            ptr->setLink(temp);
                            prev->setLink(ptr);//insert ptr between prev and temp
                            break;//stop the loop
                        }
                        if(!temp->getLink()){//if the temp is null meas that all ID are less than the ptr's ID
                            temp->setLink(ptr);//insert ptr at the end of the array
                            break;//stop the loop
                        }
                        prev = temp;//update previous
                    }
                }
    }
}
