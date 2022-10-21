#include "LinkedList.h"
#include <cmath>
#include <string.h>
#include <algorithm>
#include <fstream>
using namespace std;
Node* createNode(Data Info){
    Node *p = new Node(Info);
    if(p == NULL){
        printf("Memory is not enough");
        return NULL;
    }
    return p;
}
void SList::getInputNode(Data* info){
    do{
        cout << "Nhap MSSV: ";
        cin >> info->maSV;
    }while(this->findStudentById(info));
    cout << "Nhap Ho Dem: ";
    cin >> info->hoDem;
    cout << "Nhap Ten: ";
    cin >> info->tenSV;
    cout << "Nhap nam sinh: ";
    cin >> info->namSinh;
    cout << "Nhap diem KQ: ";
    cin >> info->diemKQ;
}
void Node::showNode(){
    // printf(
    //     "%-5s %-5s %-5s %-5d %f\n",
    //     info.maSV,
    //     info.hoDem,
    //     info.tenSV,
    //     info.namSinh,
    //     info.diemKQ
    //     );
    if( this == NULL){
        return;
    }
    cout << "Ma SV: " << info.maSV << endl
        << "Ho dem: " << info.hoDem << endl
        << "Ten SV: " << info.tenSV << endl
        << "Nam sinh: " << info.namSinh << endl
        << "Diem KQ: " << info.diemKQ << endl
        << "==============\n"
        ;
}
void SList::addTail(Node* p) {
	if (pHead == NULL) {
		pHead = p;
		pTail = p;
		return;
	}
	Node* tmp = pHead;
	while (tmp->pNext != NULL) {
		tmp = tmp->pNext;
	}
	tmp->pNext = p;
	pTail = p;
}
void SList::printList(){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        tmp->showNode();
    }
}
void SList::getFile(char* _filename){
    ifstream F("students.txt");
    // FILE *f = fopen(_filename, "r");
    // if( f == NULL){
    //     printf("File not found\n");
    //     return;
    // }
    int n = 0;
    F >> n;
    for(;n>0; n--){
        Data student;
        F   >> student.maSV
            >> student.hoDem
            >> student.tenSV
            >> student.diemKQ
            >> student.namSinh
            ;
        addNode(createNode(student));
    }
    F.close();
}

void SList::addNode(Node* p){
    if(round(rand())){
        addTail(p);
    }else{
        p->pNext = pHead;
        pHead->pNext = p;
    }
}
void SList::deleteNode(Node* p){
    if(pHead == p){
        Node* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
        return;
    }
    Node* tmp = pHead;
    while(tmp->pNext != NULL){
        if(tmp->pNext == p){
            tmp->pNext = p->pNext;
            delete p;
            return;
        }
    }
}

void SList::setNodeToHead(Node* p){
    for(Node* x = pHead; x->pNext != NULL; x = x->pNext){
        if(x->pNext == p){
            x->pNext = p->pNext;
            p->pNext = pHead;
            pHead = p;
        }
    }
}
//=================================================
Node* SList::findStudentById(Data* info){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(strcmp(tmp->info.maSV, info->maSV) == 0){
            return tmp;
        }
    }
    printf("Student not found\n");
    return NULL;
}
Node* SList::findStudentByName(Data* info){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(strcmp(tmp->info.tenSV, info->tenSV) == 0){
            return tmp;
        }
    }
    printf("Student not found\n");
    return NULL;
}
void SList::sortBy(char *type){
    short int b_type = strcmp(type, "id") == 0 
                        ? 1 : 
                        strcmp(type, "name") == 0
                        ? 2 : 0;
    if(b_type == 0) return;
    for(Node* x = pHead; x->pNext != NULL; x = x->pNext){
        for(Node* y = pHead->pNext; y != NULL; y = y->pNext){
            switch (b_type)
            {
            case 1://Id
                if(atoi(y->info.maSV) < atoi(x->info.maSV)){
                    swap(y->info, x->info);
                }
                break;
            case 2://Name
                if(y->info.tenSV[0] > x->info.tenSV[0]){
                    swap(y->info, x->info);
                }
                break;
            }
        }
    }
}
void SList::addNodeXAfterNodeY(Node* x, Node* y){
	if (pHead == y) {
		addNode(x);
		return;
	}
	for (Node* tmp = pHead; tmp->pNext != NULL; tmp = tmp->pNext) {
		if (tmp->pNext == y) {
			x->pNext = tmp->pNext;
			tmp->pNext = x;
			return;
		}
	}
}
void SList::addStudent(Node* p){
    if(pHead == NULL){
        pHead = p;
        pTail = p;
        return;
    }
    if(pHead->info.maSV > p->info.maSV){
        p->pNext = pHead;
        pHead = p;
        return;
    }
    if(pTail->info.maSV < p->info.maSV){
        pTail->pNext = p;
        pTail = p;
        return;
    }
    for(Node* tmp = pHead; tmp->pNext != NULL; tmp = tmp->pNext){
        if(p->info.maSV < tmp->pNext->info.maSV){
            addNodeXAfterNodeY(p, tmp);
        }
    }
}
void SList::deleteStudent(Node* p){
    for(Node* tmp = pHead; tmp->pNext != NULL; tmp = tmp->pNext){
        if(tmp->pNext == p){
            tmp->pNext = p->pNext;
            delete tmp->pNext;
        }
    }
}
SList* SList::createNewListDESCByScore(){
    SList *sl = new SList;
    sortBy((char*)"score");
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        sl->addTail(createNode(tmp->info));
    }
}
void SList::printStudents(){
    for(Node*  tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        tmp->showNode();
    }
}
Node* SList::maxScoreStudent(){
    Node* maxScore = pHead;
    for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
        if(maxScore->info.diemKQ > tmp->info.diemKQ){
            maxScore = tmp;
        }
    }
    return maxScore;
}
Node* SList::minScoreStudent(){
    Node* minScore = pHead;
    for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
        if(minScore->info.diemKQ > tmp->info.diemKQ){
            minScore = tmp;
        }
    }
    return minScore;
}
Node* SList::minScoreGoodStudent(){
    Node* minScore = pHead;
    for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
        if(minScore->info.diemKQ > tmp->info.diemKQ &&
            minScore->info.type() == 3
        ){
            minScore = tmp;
        }
    }
    return minScore;
}
Node* SList::findStudentAroundScore(float x){
    float minCarry = abs(x - pHead->info.diemKQ);
    Node* carry = pHead;
    for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
        if(abs(x - carry->info.diemKQ) < abs(x - tmp->info.diemKQ)){
            carry = tmp;
        }
    }
    return carry;
}

void SList::deleteAllStudentsByName(Data* Info){
    Node* tmp = this->findStudentByName(Info);
    while(tmp != NULL){
        this->deleteStudent(tmp);
        tmp = this->findStudentByName(Info);
    }
}
void Menu();
void Control(int option, SList *sl, SList *sl1){
    Data x;
    switch (option)
    {
    case 1:
        sl->printList();
        break;
    case 2:
        cout << "Nhap x:";
        cin >> x.maSV;
        sl->findStudentById(&x)->showNode();
        break;
    case 3:
        cout << "Nhap x:";
        cin >> x.tenSV;
        sl->findStudentByName(&x)->showNode();
        break;
    case 4:
        sl->sortBy((char*)"id");
        break;
    case 5:
        sl->sortBy((char*)"name");
        break;
    case 6:
        // sl->getInputNode(&x);
        // Node* p = createNode(x);
        // sl->addNode(p);
        break;
    case 7:
        cout << "Nhap maSV: ";
        cin >> x.maSV;
        sl->deleteStudent(sl->findStudentById(&x));
        break;
    case 8:
        cout << "Nhap tenSV: ";
        cin >> x.tenSV;
        sl->deleteAllStudentsByName(&x);
        break;
    case 9:
        sl1 = sl->createNewListDESCByScore();
        sl1->printList();
        break;
    case 10:
        //Nope
        break;
    case 11:
        sl->maxScoreStudent()->showNode();
        break;
    case 12:
        sl->minScoreStudent()->showNode();
        break;
    case 13:
        sl->minScoreGoodStudent()->showNode();
        break;
    case 14:
        cout << "Nhap x: ";
        cin >> x.diemKQ;
        sl->findStudentAroundScore(x.diemKQ)->showNode();
        break;    
    default:
        cout << "Error code";
        break;
    }
}
int main(){
    SList *sl = new SList(), *sl1 = new SList();
    int option = -1, x = 0;
    bool flag = false;
    char filename[] = "students.txt", song_name[100];
    sl->getFile(filename);
    while(option != 0){
        Menu();
        cin >> option;
        Control(option, sl, sl1);
    }

    return 0;
}

void Menu(){
    printf(
        "=============LOP TUY Y=============\n"
        "1. In danh sach\n"
        "2. Cho biet ho ten va diem ket qua hoc tap cua sinh vien co ma so la x\n"
        "3. Cho biet cac thong tin ve sinh vien co ten la x\n"
        "4. Sap xep DSSV theo chieu tang dan theo MaSV\n"
        "5. Sap xep DSSV theo chieu tang dan cua ten sinh vien\n"
        "6. Them mot sinh vien sao cho van ggiu nguyen thu tu tang dan cua ma so sinh vien\n"
        "7. Xoa sinh vien co MaSV=x\n"
        "8. xoa tat ca cac sinh vien co ten la x\n"
        "9. Tao danh sach moi tu danh sach da cho sao cho danh sach moi giam dan theo diem ket qua hoc tap\n"
        "10. In danh sach cac sinh vien duoc xep loai kha\n"
        "11. Cho biet sinh vien co diem ket qua hoc tap cao nhat\n"
        "12. Cho biet sinh vien co diem ket qua hoc tap thap nhat\n"
        "13. Cho biet sinh vien co diem ket qua hoc tap thap nhat trong so cac sinh vien xep loai gioi\n"
        "14. Cho biet sinh vien co diem ket qua hoc tap gan x nhat\n"
        "=======\n"
        );
}