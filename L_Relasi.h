#ifndef L_RELASI_H_INCLUDED
#define L_RELASI_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string>

#include "L_Parent.h"
#include "L_Child.h"

#define next(R) R->next
#define prev(R) R->prev
#define artis(R) R->artis
#define film(R) R->film
#define first(LR) LR.first
#define last(LR) LR.last

using namespace std;

typedef struct relasi *adr_relasi;

struct relasi{
    adr_parent artis;
    adr_child film;
    adr_relasi next;
    adr_relasi prev;
};

struct list_relasi{
    adr_relasi first;
    adr_relasi last;
};

void createList_relasi(list_relasi &LR);
adr_relasi create_relasi(list_parent LP, list_child LC, adr_parent P, adr_child C);
void insertfirst_relasi(list_relasi &LR, adr_relasi &R);
void createdatarelasi(list_parent LP, list_child LC, list_relasi &LR);
void deleterelasi(list_relasi &LR, adr_relasi &P);               //delete berdasarkan data yang di cari
adr_relasi find_relasi(list_relasi LR, list_parent LP, list_child LC, string nama_artis, string nama_film);
//void deletedatarelasi(list_relasi &LR, list_child LC, list_parent LP);
void deletedataartis(list_parent &LP, list_relasi &LR, list_child LC);
void deletedatafilm(list_child &LC, list_relasi &LR, list_parent LP);
void printInfo_relasi(list_relasi LR);
void printInfo_relasiAll(list_relasi LR, list_parent LP, list_child LC);
void printInfoFilmByActor(list_relasi LR, list_parent LP, list_child LC, string namaartis);
void printInfoActorByFilm(list_relasi LR, list_parent LP, list_child LC, string namafilm);


#endif // L_RELASI_H_INCLUDED
