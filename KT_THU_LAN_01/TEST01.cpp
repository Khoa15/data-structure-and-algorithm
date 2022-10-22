#include "TEST01_LIB.h"
#include <fstream>
void Book::showData(){
    cout    << Id           << "\t"
            << name         << "\t"
            << totalPages   << "\t"
            << year         << "\t"
            << price        << endl
            << "==========" << endl;
}
void Book::getData(){
    cout << "Ma sach: ";
    cin >> Id;
    cout << "Ten sach: ";
    cin.getline(name, 31);
    cout << "So trang: ";
    cin >> totalPages;
    cout << "Nam xuat ban: ";
    cin >> year;
    cout << "Gia ban: ";
    cin >> price;
}
NBook* ListBook::createNode(Data Info){
    NBook* p = new NBook();
    if(p == NULL){
        cout << "Memory is not enought";
        return NULL;
    }
    p->setInfo(Info);
    p->setNext(NULL);
    return p;
}

void ListBook::getFile(string file){
    fstream F("Books.txt");
    int n;
    F >> n;
    for(;n>0;n--){
        Data book;
        F >> book.Id >> book.name >> book.price >> book.totalPages >> book.year;
        NBook* p = createNode(book);
        addHead(p);
    }
}
NBook* ListBook::getHead(){
    return pHead;
}
void ListBook::addHead(NBook* book){
    book->setNext(getHead());
    setHead(book);
}
int ListBook::countBookPagesLargerXyearIsY(int x, int y){
    int result = 0;
    for(NBook* tmp = getHead(); tmp != NULL; tmp = tmp->getNext()){
        if(tmp->getInfo().totalPages > x && tmp->getInfo().year == y){
            result += tmp->getInfo().totalPages;
        }
    }
    return result;
}
void ListBook::addBookBeforeBookHavePriceSmallerX(NBook* book, int x){
    if(getHead()->getInfo().price < x){
        book->setNext(getHead());
        setHead(book);
        return;
    }
    for(NBook* tmp = getHead(); tmp->getNext() != NULL; tmp = tmp->getNext()){
        if(tmp->getNext()->getInfo().price < x){
            book->setNext(tmp->getNext());
            tmp->setNext(book);
            return;
        }
    }
}
void ListBook::deleteAllBooksPriceLargeX(int x){
    for(NBook* tmp = getHead(); tmp != NULL; tmp = tmp->getNext()){
        if(tmp->getInfo().price > x){
            deleteBook(tmp);
        }
    }
}
void ListBook::deleteBook(NBook* book){
    if(book == getHead()){
        setHead(book->getNext());
        delete book;
        return;
    }
    for(NBook* tmp = getHead(); tmp->getNext() != NULL; tmp = tmp->getNext()){
        if(tmp->getNext() == book){
            tmp->setNext(book->getNext());
            delete book;
            return;
        }
    }
}
void ListBook::findBookPriceLargerX(int x){
    for(NBook* tmp = getHead(); tmp != NULL; tmp = tmp->getNext()){
        if(tmp->getInfo().price > x){
            deleteBook(tmp);
            return;
        }
    }
}
void ListBook::showList(){
    cout    << "Ma sach"        << "\t"
            << "Ten Sach"       << "\t"
            << "So Trang"       << "\t"
            << "Nam xuat ban"   << "\t"
            << "Gia ban"        << endl
            << "========="      << endl;
    for(NBook* tmp = getHead(); tmp != NULL; tmp = tmp->getNext()){
        tmp->getInfo().showData();
    }
}
//=============================
Node Stack::pop(){
    Node rs;
    rs.val[0] = pHead->val[0];
    return rs;
}
Node* Stack::top(){
    return pHead;
}
void Stack::push(Node* p){
    p->pNext = pHead;
    pHead = p;
}
