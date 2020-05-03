#ifndef L_PARENT_H_INCLUDED
#define L_PARENT_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string>

#define first(LP) LP.first
#define infoArtis(P) P->infoArtis
#define next(P) P->next

using namespace std;

struct artis{
    string nama;
    char jeniskelamin;
    int umur;
    string tanggallahir;
    int data;
};

typedef struct parent *adr_parent;

struct parent{
    artis infoArtis;
    adr_parent next;
};

struct list_parent{
    adr_parent first;
};

void createList_artis(list_parent &LP);
adr_parent create_artis(string nama, string jeniskelamin, int umur, string tanggallahir);
void insertfirst_parent(list_parent &LP, adr_parent p);
void createdataartis(list_parent &LP);
void delete_artis(list_parent &LP, adr_parent &p);
adr_parent find_artis(list_parent LP, string nama);
void printInfo_parent(list_parent LP);
void printInfoMostMaleActor(list_parent LP);
void printInfoMostFemaleActor(list_parent LP);

#endif // L_PARENT_H_INCLUDED
