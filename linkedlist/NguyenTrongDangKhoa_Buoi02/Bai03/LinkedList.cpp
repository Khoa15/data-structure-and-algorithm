#include "LinkedList.h"
#include <cmath>
#include <string.h>
#include <algorithm>
using namespace std;
void Node::showNode(){
    printf(
        "%-5s %-5s %-5s %-5d %f\n",
        info.maSV,
        info.hoDem,
        info.tenSV,
        info.namSinh,
        info.diemKQ
        );
    cout << "Ma SV: " << info.maSV << endl
        << "Ho dem: " << info.hoDem << endl
        << "Ten SV: " << info.tenSV << endl
        << "Nam sinh: " << info.namSinh << endl
        << "Diem KQ: " << info.diemKQ << endl
        << "==============\n"
        ;
}
void Node::getInput(){
    
}
void SList::addTail(Node* p) {
    // Node* p = new Node(x);
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
    FILE *f = fopen(_filename, "r");
    if( f == NULL){
        printf("File not found\n");
        return;
    }
    Data song;
    int n = 0;
    fscanf(f, "%d\n", &n);
    for(;n>0; n--){
        fscanf(f, "%[^#] %*c %[^#] %*c %[^#] %*c %d\n", song.name, song.author, song.singer, &song.time);
        addNode(song);
    }
}

unsigned int SList::sumTimeList(){
    unsigned int result = 0;
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        result += tmp->info.time;
    }

    return result;
}
void SList::addNode(Data Info){
    if(round(rand())){
        addTail(Info);
    }else{
        Node* p = new Node(Info);
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
bool SList::isExists(char* name){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(strcmp(tmp->info.name, name) == 0){
            return true;
        }
    }
    return false;
}
Node* SList::findNode(char* name){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(strcmp(tmp->info.name, name) == 0){
            return tmp;
        }
    }
}
void SList::deleteSong(char* name){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(strcmp(tmp->info.name, name) == 0){
            deleteNode(tmp);
            break;
        }
    }
}
void SList::sortByName(){
    for(Node* x = pHead; x->pNext != NULL; x = x->pNext){
        for(Node* y = pHead; y != NULL; y = y->pNext){
            if(x->info.name[0] > y->info.name[0]){
                std::swap(x->info, y->info);
            }
        }
    }
}
void SList::sortBySinger(){
    for(Node* x = pHead; x->pNext != NULL; x = x->pNext){
        for(Node* y = pHead; y != NULL; y = y->pNext){
            if(x->info.singer[0] > y->info.singer[0]){
                std::swap(x->info, y->info);
            }
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

Data getInputSong(){
    
}
//=================================================
Node* SList::findStudent(char *Id){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(strcmp(tmp->info.maSV, Id) == 0){
            return tmp;
        }
    }
    printf("Student not found\n");
    return NULL;
}
void SList::sortBy(char *type){
    short int b_type = strcmp(type, "id") == 0 ? 1 : strcmp(type, "name") ? 2 : 0;
    if(b_type == 0) return;
    for(Node* x = pHead; x->pNext != NULL; x = x->pNext){
        for(Node* y = pHead->pNext; y != NULL; y = y->pNext){
            switch (b_type)
            {
            case 1:
                if(y->info < x->info){
                    swap(y->info, x->info);
                }
                break;
            case 2:
                if(y->info < x->info){
                    swap(y->info, x->info);
                }
                break;
            }
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
    for(Node* tmp = pHead; tmp->pNext != NULL; tmp = tmp->pNext()){
        if(p->info.maSV < tmp->pNext->info.maSV){
            addNodeXAfterNodeY(p, tmp);
        }
    }
}
void SList::deleteStudent(Node* p){
    //
}
SList* SList::createNewListDESCByScore(){
    SList *sl = new SList;
    sortBy("score");
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        sl->addTail(tmp);
    }
}
void SList::printStudents(){

}
void SList::maxScore(){

}
void SList::minScore(){

}

void Menu();

int main(){
    SList *sl = new SList();
    int option = 0, x = 0;
    bool flag = false;
    char filename[] = "songs.txt", song_name[100];
    while(1){
        Menu();
        printf("Choose option: ");
        scanf("%d", &option);
        switch(option){
        case 1:
            sl->printList();
            break;
        case 2:
            if(flag == false){
                // scanf("%s", filename);
                sl->getFile(filename);
                flag = true;
            }
            break;
        case 3:
            printf("Total time: %d\n", sl->sumTimeList());
            break;
        case 4:
            sl->addNode(getInputSong());
            break;
        case 5:
            printf("Enter a song's name: ");
            scanf("%s", filename);
            sl->deleteSong(filename);
            break;
        case 6:
            printf("Enter a song's name: ");
            scanf("%s", song_name);
            printf("%d\n", sl->isExists(song_name));
            break;
        case 7:
            sl->sortByName();
            break;
        case 8:
            sl->sortBySinger();
            break;
        case 9:
            printf("Enter a song's name: ");
            scanf("%s", song_name);
            sl->setNodeToHead(sl->findNode(song_name));
        case 0:
            return 0;
        }
    }

    return 0;
}

void Menu(){
    printf(
        "=============XOM BAI HAT=============\n"
        "1. In danh sach\n"
        "2. Doc danh sach nhac tu file\n"
        "3. Thoi gian can de nghe het bai hat trong danh sach\n"
        "4. Them mot bai hat vao dau/cuoi playlist\n"
        "5. Xoa mot bai nhac\n"
        "6. Tim bai nhac\n"
        "7. Sap xep theo ten bai nhac\n"
        "8. Sap xep theo ten ca si\n"
        "9. Dua mot bai hat len dau\n"
        );
}