#include "L_Child.h"

void createList_film(list_child &LC)
{
    first(LC) = NULL;
}

adr_child create_film(string nama, string tanggalterbit, string durasi, float rating)
{
    adr_child P;

    P = new child;
    infoFilm(P).nama = nama;
    infoFilm(P).tanggalterbit = tanggalterbit;
    infoFilm(P).durasi = durasi;
    infoFilm(P).rating = rating;
    next(P) = NULL;

    return P;
}

void insertlast_child(list_child &LC, adr_child p)
{
    adr_child q = first(LC);

    if(first(LC) == NULL)
    {
        first(LC) = p;
        next(p) = p;
    } else
    {
        while(next(q) != first(LC))
        {
            q = next(q);
        }
        next(p) = q;
        next(q) = p;
        next(p) = first(LC);
    }
}

void createdatafilm(list_child &LC)
{
    adr_child p, q;
    string namafilm, tanggalterbit, durasi;
    float rating;

    cout << "============================================================" << endl;
    cout << "==================== Masukkan Data Film ====================" << endl;
    cout << "Nama Film            : "; cin.ignore();
    getline(cin, namafilm);
    cout << "Tanggal Terbit       : ";
    getline(cin, tanggalterbit);
    cout << "Durasi Film          : ";
    getline(cin, durasi);
    cout << "Rating Film          : ";
    cin >> rating;
    cout << endl;

    q = find_film(LC, namafilm);
    if(q == NULL){
        p = create_film(namafilm, tanggalterbit, durasi, rating);
        insertlast_child(LC, p);
        cout << "Data Berhasil Didaftarkan" << endl;
    } else {
        cout << "Data Sudah Terdaftar" << endl;
    }
}

void delete_film(list_child &LC, adr_child &P)
{
    adr_child q = first(LC);

    if(next(P) == P){
        first(LC) = NULL;
    } else if(next(P) == first(LC)){
        while(next(q) != P){
            q = next(q);
        }
        next(q) = first(LC);
        next(P) = NULL;
    } else if(P == first(LC)){
        while(next(q) != first(LC)){
            q = next(q);
        }
        first(LC) = next(first(LC));
        next(q) = first(LC);
        next(P) = NULL;
    } else {
        while(next(q) != P){
            q = next(q);
        }
        next(q) = next(P);
        next(P) = NULL;
    }
}

adr_child find_film(list_child LC, string nama)
{
    adr_child p = first(LC);
    if(p == NULL){
        return NULL;
    } else {
        while(infoFilm(p).nama != nama && next(p) != first(LC)){
            if(infoFilm(p).nama == nama){
                return p;
            } else {
                p = next(p);
            }
        }
        if(infoFilm(p).nama == nama){
            return p;
        } else {
            return NULL;
        }
    }
}

void printInfo_child(list_child LC)
{
    adr_child p = first(LC);
    if(first(LC) == NULL){
        cout << "Data Kosong" << endl;
    } else {
        cout << "============ Data Film ============" << endl << endl;
        while(next(p) != first(LC)){
            cout << "Nama Film      : " << infoFilm(p).nama << endl;
            cout << "Tanggal Terbit : " << infoFilm(p).tanggalterbit << endl;
            cout << "Durasi Film    : " << infoFilm(p).durasi << endl;
            cout << "Rating Film    : " << infoFilm(p).rating << endl;
            cout << endl;
            p = next(p);
        }
        cout << "Nama Film      : " << infoFilm(p).nama << endl;
        cout << "Tanggal Terbit : " << infoFilm(p).tanggalterbit << endl;
        cout << "Durasi Film    : " << infoFilm(p).durasi << endl;
        cout << "Rating Film    : " << infoFilm(p).rating << endl;
        cout << endl;
    }
}
