#include "L_Relasi.h"

void createList_relasi(list_relasi &LR)
{
    first(LR) = NULL;
    last(LR) = NULL;
}

adr_relasi create_relasi(list_parent LP, list_child LC, adr_parent P, adr_child C){
    adr_relasi R;

    R = new relasi;
    artis(R) = P;
    film(R) = C;
    next(R) = NULL;
    prev(R) = NULL;

    return R;
}

void insertfirst_relasi(list_relasi &LR, adr_relasi &R)
{
    if(first(LR) == NULL && last(LR) == NULL)
    {
        first(LR) = R;
        last(LR) = R;
    } else
    {
        next(R) = first(LR);
        prev(first(LR)) = R;
        first(LR) = R;
    }
}

void createdatarelasi(list_parent LP, list_child LC, list_relasi &LR)
{
    adr_relasi r, fr;
    adr_child c;
    adr_parent p;

    string namaartis, namafilm;

    cout << "============================================" << endl;
    cout << "============ Tambah Data Relasi ============" << endl;
    cout << "============================================" << endl;
    cout << "Nama Artis : "; cin.ignore();
    getline(cin, namaartis);
    cout << "Nama Film  : ";
    getline(cin, namafilm);
    cout << namaartis << " " << namafilm;
    cout << endl;

    p = find_artis(LP, namaartis);
    c = find_film(LC, namafilm);
    if(p == NULL || c == NULL){
        if(p == NULL){
            cout << "Maaf Data Artis Tidak Ditemukan" << endl;
        } else if(c == NULL){
            cout << "Maaf Data Film Tidak Ditemukan" << endl;
        }
    } else {
        fr = find_relasi(LR, LP, LC, namaartis, namafilm);
        if(fr == NULL){
            r = create_relasi(LP, LC, p, c);
            infoArtis(p).data++;
            insertfirst_relasi(LR, r);
            cout << "Data Berhasil Ditambahkan" << endl;
        } else {
            cout << "Data Sudah Terdaftar" << endl;
        }
    }
}

void deleterelasi(list_relasi &LR, adr_relasi &P)
{
    adr_relasi q = first(LR);

    if(first(LR) == P && last(LR) == P){
        first(LR) = NULL;
        last(LR) = NULL;
    } else if(P == first(LR)){
        first(LR) = next(first(LR));
        prev(first(LR)) = NULL;
        next(P) = NULL;
    } else if(P == last(LR)){
        last(LR) = prev(last(LR));
        next(last(LR)) = NULL;
        prev(P) = NULL;
    } else{
        while(next(q) != P){
            q = next(q);
        }
        next(q) = next(P);
        prev(next(P)) = q;
        next(P) = NULL;
        prev(P) = NULL;
    }
}               //delete berdasarkan data yang di cari

adr_relasi find_relasi(list_relasi LR, list_parent LP, list_child LC, string nama_artis, string nama_film)
{
    adr_relasi p = first(LR);
    adr_relasi found = NULL;

    if(p == NULL){
        return found;
    } else {
        while((infoArtis(artis(p)).nama != nama_artis && infoFilm(film(p)).nama != nama_film) && next(p) != NULL)
        {
            if(infoArtis(artis(p)).nama == nama_artis && infoFilm(film(p)).nama == nama_film){
                found = p;
            }
            p = next(p);
        }
        return found;
    }
}

//void deletedatarelasi(list_relasi &LR, list_child LC, list_parent LP)
//{
//    adr_relasi r;
//    string namaartis, namafilm;
//
//    cout << "===========================================" << endl;
//    cout << "============ Hapus Data Relasi ============" << endl;
//    cout << "===========================================" << endl;
//    cout << "Nama Artis : ";
//    getline(cin, namaartis);
//    cout << endl;
//    cout << "Nama Film  : ";
//    getline(cin, namafilm);
//    cout << endl;
//
//    r = find_relasi(LR, LP, LC, namaartis, namafilm);
//    if(r == NULL)
//    {
//        cout << "Data Relasi Tidak Ada" << endl;
//    } else
//    {
//        deleterelasi(LR, r);
//        cout << "Data Relasi Berhasil di Hapus" << endl;
//    }
//}

void deletedataartis(list_parent &LP, list_relasi &LR, list_child LC)
{
    adr_parent p;
    string nama;

    cout << "========== Delete Data Artis ==========" << endl;
    cout << "Masukkan Nama Artis : "; cin.ignore();
    getline(cin, nama);
    cout << endl;

    p = find_artis(LP, nama);
    if(p == NULL){
        cout << "Data tidak ditemukan" << endl;
    }else if(p != NULL){
        adr_relasi r = first(LR);
        if(r == NULL){
            delete_artis(LP, p);
            cout << "Data Berhasil di Hapus" << endl;
        } else {
            while(next(r) != NULL){
                if(infoArtis(artis(r)).nama == infoArtis(p).nama){
                    r = next(r);
                    adr_relasi found = prev(r);
                    deleterelasi(LR, found);
                    infoArtis(p).data--;
                } else {
                    r = next(r);
                }
            }

            if(infoArtis(artis(r)).nama == nama){
                deleterelasi(LR, r);
            }
            delete_artis(LP, p);
            cout << "Data Berhasil di Hapus" << endl;
        }
    }
}

void deletedatafilm(list_child &LC, list_relasi &LR, list_parent LP){
    adr_child p;
    string namafilm;

    cout << "========== Delete Data Film ==========" << endl;
    cout << "Masukkan Nama Film : "; cin.ignore();
    getline(cin, namafilm);
    cout << endl;

    p = find_film(LC, namafilm);
    if(p == NULL) {
        cout << "Data tidak ditemukan" << endl;
    }else if(p != NULL) {
        adr_relasi r = first(LR);
        if(r == NULL) {
            delete_film(LC, p);
            cout << "Data Berhasil di Hapus" << endl;
        } else {
            while(next(r) != NULL){
                if(infoFilm(film(r)).nama == infoFilm(p).nama){
                    r = next(r);
                    adr_relasi found = prev(r);
                    infoArtis(artis(found)).data--;
                    deleterelasi(LR, found);

                } else {
                    r = next(r);
                }
            }

            if(infoFilm(film(r)).nama == namafilm){
                deleterelasi(LR, r);
            }

            delete_film(LC, p);
            cout << "Data Berhasil di Hapus" << endl;
        }
    }
}

void printInfo_relasi(list_relasi LR)
{
    adr_relasi p = first(LR);
    int angka = 1;
    if(first(LR) == NULL){
        cout << "Data Relasi Kosong" << endl;
    } else {
        cout << "============ Data Relasi ============" << endl << endl;
        while(p != NULL){
            cout << "Data ke- " << angka << " || Nama Artis : " << infoArtis(artis(p)).nama << " || Nama Film : " << infoFilm(film(p)).nama << endl;
            p = next(p);
            angka++;
        }
        cout << "=====================================" << endl;
    }
}

void printInfo_relasiAll(list_relasi LR, list_parent LP, list_child LC)
{
    adr_parent p = first(LP);

    if(first(LR) == NULL)
    {
        cout << "Data tidak ada" << endl;
    }else
    {

        while(p != NULL){
            cout << infoArtis(p).nama << " :" << endl;
            adr_relasi r = first(LR);
            while(r != NULL){
                if(infoArtis(artis(r)).nama == infoArtis(p).nama){
                    cout << infoFilm(film(r)).nama << " (" << infoFilm(film(r)).durasi << ")" << endl;
                }
                r = next(r);
            }
            p = next(p);
        }
    }
}

void printInfoFilmByActor(list_relasi LR, list_parent LP, list_child LC, string namaartis)
{
    adr_relasi p = first(LR);
//    printInfo_parent(LP);
//    cout << endl << endl;
//    cout << namaartis << " :" << endl;
    while(p != NULL)
    {
        if(infoArtis(artis(p)).nama == namaartis){
            cout << "- " << infoFilm(film(p)).nama << endl;
        }
        p = next(p);
    }
}

void printInfoActorByFilm(list_relasi LR, list_parent LP, list_child LC, string namafilm)
{
    adr_relasi p = first(LR);
//    printInfo_child(LC);
//    cout << endl << endl;
//    cout << namafilm << " :" << endl;
    while(p != NULL)
    {
        if(infoFilm(film(p)).nama == namafilm){
            cout << "- " << infoArtis(artis(p)).nama << endl;
        }
        p = next(p);
    }
}
