#include "L_Parent.h"

void createList_artis(list_parent &LP){
    first(LP) = NULL;
}

adr_parent create_artis(string nama, char jeniskelamin, int umur, string tanggallahir){

    adr_parent P;
    P = new parent;
    infoArtis(P).nama = nama;
    infoArtis(P).jeniskelamin = jeniskelamin;
    infoArtis(P).umur = umur;
    infoArtis(P).tanggallahir = tanggallahir;
    infoArtis(P).data = 0;
    next(P) = NULL;

    return P;
}

void insertfirst_parent(list_parent &LP, adr_parent p){
    if(first(LP) == NULL){
        first(LP) = p;
    } else {
        next(p) = first(LP);
        first(LP) = p;
    }
}

void createdataartis(list_parent &LP){
    adr_parent p, q;
    string nama, tanggallahir;
    char jeniskelamin;
    int umur;

    cout << "=============================================================" << endl;
    cout << "==================== Masukkan Data Artis ====================" << endl;
    cout << "Nama                 : "; cin.ignore();
    getline(cin, nama);
    cout << "Jenis Kelamin        : ";
    cin >> jeniskelamin;
    cout << "Umur                 : ";
    cin >> umur;
    cout << "Tempat Tanggal Lahir : "; cin.ignore();
    getline(cin, tanggallahir);
    cout << endl;
    q = find_artis(LP, nama);
    if(q != NULL){
        cout << "Nama Sudah Terdaftar" << endl;
    } else {
        p = create_artis(nama, jeniskelamin, umur, tanggallahir);
        insertfirst_parent(LP, p);
        cout << "Data Berhasil Di Tambahkan" << endl;
    }
}

void delete_artis(list_parent &LP, adr_parent &p){
    adr_parent q = first(LP);

    if(first(LP) == p){
        first(LP) = next(first(LP));
        next(p) = NULL;
    } else if(next(p) == NULL){
        while(next(q) != p){
            q = next(q);
        }
        next(q) = NULL;
    } else {
        while(next(q) != p){
            q = next(q);
        }
        next(q) = next(p);
        next(p) = NULL;
    }
}

adr_parent find_artis(list_parent LP, string nama){
    adr_parent p = first(LP);
    if(p == NULL){
        return NULL;
    } else {
        while(infoArtis(p).nama != nama && next(p) != NULL){
            if(infoArtis(p).nama == nama){
                return p;
            } else {
                p = next(p);
            }
        }
        if(infoArtis(p).nama == nama){
            return p;
        } else {
            return NULL;
        }
    }
}

void printInfo_parent(list_parent LP){
    adr_parent p = first(LP);
    if(first(LP) == NULL){
        cout << "Data Kosong" << endl;
    } else {
        cout << "============ Data Artis ============" << endl << endl;
        while(p != NULL){
            cout << "Nama          : " << infoArtis(p).nama << endl;
            cout << "Jenis Kelamin : " << infoArtis(p).jeniskelamin << endl;
            cout << "Umur          : " << infoArtis(p).umur << " tahun" << endl;
            cout << "Tanggal Lahir : " << infoArtis(p).tanggallahir << endl;
            cout << endl;
            p = next(p);
        }
    }
}

void printInfoMostMaleActor(list_parent LP){
    if(first(LP) == NULL){
        cout << "Data Tidak Ada" << endl;
    } else {
        adr_parent p = next(first(LP));
        adr_parent maxdata = first(LP);

        while(p != NULL){
            if((infoArtis(maxdata).data < infoArtis(p).data) && infoArtis(p).jeniskelamin == 'L'){
                while(maxdata != p){
                    maxdata = next(maxdata);
                }
            }
            p = next(p);
        }

        if(infoArtis(maxdata).data == 0){
            cout << "Data Tidak Ada" << endl;
        }else if(infoArtis(maxdata).jeniskelamin == 'L'){
            cout << "============ Top Male Actor ============" << endl << endl;
            cout << "Nama                       : " << infoArtis(maxdata).nama << endl;
            cout << "Jenis Kelamin              : " << infoArtis(maxdata).jeniskelamin << endl;
            cout << "Umur                       : " << infoArtis(maxdata).umur << " tahun" << endl;
            cout << "Tanggal Lahir              : " << infoArtis(maxdata).tanggallahir << endl;
            cout << "Jumlah Film yang Dimainkan : " << infoArtis(maxdata).data << " Film" << endl;
            cout << endl;
        }
    }
}

void printInfoMostFemaleActor(list_parent LP){
    if(first(LP) == NULL){
        cout << "Data Tidak Ada" << endl;
    } else {
        adr_parent p = first(LP);
        adr_parent maxdata = first(LP);

        while(p != NULL){
            if((infoArtis(maxdata).data < infoArtis(p).data) && infoArtis(p).jeniskelamin == 'P'){
                while(maxdata != p){
                    maxdata = next(maxdata);
                }
            }
            p = next(p);
        }

        if(infoArtis(maxdata).data == 0){
            cout << "Data Tidak Ada" << endl;
        }else if(infoArtis(maxdata).jeniskelamin == 'P'){
            cout << "============ Top Female Actor ============" << endl << endl;
            cout << "Nama                       : " << infoArtis(maxdata).nama << endl;
            cout << "Jenis Kelamin              : " << infoArtis(maxdata).jeniskelamin << endl;
            cout << "Umur                       : " << infoArtis(maxdata).umur << " tahun" << endl;
            cout << "Tanggal Lahir              : " << infoArtis(maxdata).tanggallahir << endl;
            cout << "Jumlah Film yang Dimainkan : " << infoArtis(maxdata).data << " Film" << endl;
            cout << endl;
        }
    }
}
