#include <iostream>
#include <set>
using namespace std;
class Book{

    public:
    //constructor, initializes title and rating, immediately adds book to set when object is created
    Book(string t, int r){
        title = t;
        rating = r;
        add();
    }
    //prints set in descending order
    void print(){
        for(multiset<Book>::reverse_iterator i = allBooks.rbegin(); i != allBooks.rend(); ++i){
            cout << i->title << ": " << i->rating << endl;
        }
    }
    //adds book to set
    void add(){
        allBooks.insert(*this);
    }
    //comparison operator for object
    bool operator<(const Book &otherBook) const{
        return rating < otherBook.rating;
    }
    private:
    string title;
    int rating;
    static multiset<Book> allBooks;
};
multiset<Book> Book::allBooks;

int main(){
    //creating books
    Book HG("Hunger Games", 10);
    Book BR("Beach Read", 7);
    Book HP("Harry Potter", 8);
    Book FS("The Fault in our Stars", 9);
    Book T("twilight", 10);
    Book MB("To Kill a Mocking Bird", 5);
    Book KR("The Kite Runner", 7);
    //calls print function
    HG.print();
}
