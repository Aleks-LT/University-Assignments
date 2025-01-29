#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

// Programa paruose Aleks Komarov JNII23

using namespace std;

template<typename Type>
 class Stack{
    private:
int size;
int top = -1;
Type * my_array;


    public:
Stack(int size_){
    size = size_;
my_array = new Type [size];}


void push(Type x){
my_array[++top] = x;
cout<< "    Pushed {"<<x<<"}. ";
cout<< "    Top = "<<top<<endl;
}


Type pop(){
    if(top<=-1)
        cout<< "    Stack is empty\n";
    else{
        return my_array[top--];
        cout<<"     Popped {"<<my_array[top]<<"}.\n"; return my_array[top--];}
}

int isntEmpty(){
if(top>=0) return 1;
else       return 0;
}

};


void application_1(){
Stack<int>  *myStack = new Stack<int>(10);
int number;
bool is_negative=0;
unsigned long long int result=0;

cout<< "Decimal to Binary Convertion\n";
cout<< "============================\n";
cout<< "Write a digit: "; cin>>number;

if (number!=abs(number)){
    number=abs(number);
    is_negative = 1;}

while(number>0){
    myStack->push(number%2);
    number=number/2;
}

int n= 0;
while(myStack->isntEmpty()){
    n++;
    result = result*10 + myStack->pop();
    cout<<n<< ") Intervening result is "<< result<<endl;
}

cout<<endl<<"Final Result = ";
if(is_negative)   cout<< "-";
cout<< result <<endl;}

void application_2(){
string text;
cout<< "Text processing\n";
cout<< "===================\n";
cout<< "Write a word or a sentence: "; cin>>text;
cout<< "This text consists of "<<text.size()<<" symbols."<<endl;
Stack<char>  *myStack = new Stack<char>(text.size());
for (int i = 0; i< text.size(); i++)
    {myStack->push(text[i]);}
cout<< "Reversed text: ";
while(myStack->isntEmpty()){
    cout<<myStack->pop();
}
}

void application_3(){
string  word="", word_without_spaces="", second_word= "", second_word_without_spaces= "";
cout<< "Palindrome finding\n";
cout<< "==================\n";
cout<< "Write a word or a sentence: ";
getline(cin>>ws, word);

Stack<char>  *myStack = new Stack<char>(word.size());
cout<< "This text consists of "<<word.size()<<" symbols."<<endl;
for (int i = 0; i< word.size(); i++)
    {myStack->push(word[i]);}

while(myStack->isntEmpty()){
    second_word= second_word + myStack->pop();
}

word_without_spaces = word;
word_without_spaces.erase(remove_if(word_without_spaces.begin(), word_without_spaces.end(), ::isspace), word_without_spaces.end());
second_word_without_spaces = second_word;
second_word_without_spaces.erase(remove_if(second_word_without_spaces.begin(), second_word_without_spaces.end(), ::isspace), second_word_without_spaces.end());


cout<<setw(100)<<setfill('=')<<'+'<<setfill(' ');
cout<<setw(50)<<endl<< "You wrote: "<<fixed<<word<<endl;
cout<<setw(50)<< "Your text written backwards: "<<fixed<<second_word<<endl<<endl;
cout<<setw(50)<< "Your text without spaces: "<<word_without_spaces<<endl;
cout<<setw(50)<< "Your text without spaces written backwards: "<<second_word_without_spaces<<endl;
cout<<setw(100)<<setfill('=')<<'+';
cout<<endl<<"Answer: ";
if(word_without_spaces == second_word_without_spaces)
    cout<< "This text is a palindrome.\n";
else
    cout<< "This text is not a palindrome.\n";


}

int main(){

int num;
string answer="y";
while(answer == "y" || answer== "Y"){
cout<<endl<< "__________________________________\n";
cout<<"Choose application:"<<endl;
cout<< "1) Decimal to Binary Convertion"<<endl;
cout<< "2) Text processing"<<endl;
cout<< "3) Palindrome finding"<<endl;

getline(cin>>ws, answer); cout<<endl;
//if user input isn't an integer, the program still continues
try {num = stoi(answer);    throw 504;}  catch(...) {/*cout<< "error\n";*/}
switch (num){
case 1:
    application_1();
    break;
case 2:
    application_2();
    break;
case 3:
    application_3();
    break;

default:
    cout<< "That choice is not available."<<endl<<endl;
    break;
}

cout<< "\nDo you want to repeat the task again (Y/N): ";
cin>>answer;
system("cls");
}

return 0;
};



