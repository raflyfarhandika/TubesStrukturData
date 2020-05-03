#ifndef L_CHILD_H_INCLUDED
#define L_CHILD_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string>

#define first(LC) LC.first
#define infoFilm(P) P->infoFilm
#define next(P) P->next

using namespace std;

struct film{
    string nama;
    string tanggalterbit;
    string durasi;
    float rating;
};

typedef struct child *adr_child;

struct child{
    film infoFilm;
    adr_child next;
};

struct list_child{
    adr_child first;
};

void createList_film(list_child &LC);
adr_child create_film(string nama, string tanggalterbit, string durasi, float rating);
void insertlast_child(list_child &LC, adr_child p);
void createdatafilm(list_child &LC);
void delete_film(list_child &LC, adr_child &P);
adr_child find_film(list_child LC, string nama);
void printInfo_child(list_child LC);


#endif // L_CHILD_H_INCLUDED
