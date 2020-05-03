#include "L_Relasi.h"
#include "L_Parent.h"
#include "L_Child.h"
#include <iostream>

using namespace std;

int main()
{
    list_parent LP;
    list_child LC;
    list_relasi LR;
    adr_parent p;
    adr_child c;
    adr_relasi r;
    int pilih, pilih2;
    string namaartis, namafilm;

    createList_artis(LP);
    createList_film(LC);
    createList_relasi(LR);

    cout << "================================================================" << endl;
    cout << "                         Data Perfilman                         " << endl;
    cout << "================================================================" << endl << endl;
    cout << "1. Penambahan Data Aktor / Aktris" << endl;
    cout << "2. Penambahan Data Film" << endl;
    cout << "3. Penambahan Data Relasi Aktor dan Film" << endl;
    cout << "4. Hapus Data Aktor / Aktris" << endl;
    cout << "5. Hapus Data Film" << endl;
    cout << "6. Tampil Data Aktor / Aktris" << endl;
    cout << "7. Tampil Data Film" << endl;
    cout << "8. Tampil Relasi Data Aktor/ Aktris beserta Film" << endl;
    cout << "9. Tampil Data Film yang Dibintangi Oleh Aktor/Aktris tertentu" << endl;
    cout << "10. Tampil Data Aktor/Aktris yang Membintangi Film Tertentu" << endl;
    cout << "11. Tampil Data 1 Orang Aktor dan 1 Orang Aktris yang Paing Top" << endl;
    cout << "12. Exit Program" << endl << endl;
    cout << "Pilihan : ";
    cin >> pilih;
    cout << endl;
    if(pilih == 12){
        cout << "--------------- Program Berakhir ---------------" << endl;
    }
    while(pilih != 12){
        if(pilih == 1){
            system("CLS");
            createdataartis(LP);
            system("PAUSE");
            system("CLS");
            cout << "Data Aktor/Aktris : " << endl;
            printInfo_parent(LP);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 2){
            system("CLS");
            createdatafilm(LC);
            system("PAUSE");
            system("CLS");
            cout << "Data Film : " << endl;
            printInfo_child(LC);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 3){
            system("CLS");
            createdatarelasi(LP, LC, LR);
            system("PAUSE");
            system("CLS");
            cout << "Data Relasi : " << endl;
            printInfo_relasi(LR);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 4){
            system("CLS");
            deletedataartis(LP, LR);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 5){
            system("CLS");
            deletedatafilm(LC, LR);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 6){
            system("CLS");
            cout << "Data Aktor/Aktris : " << endl;
            printInfo_parent(LP);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 7){
            system("CLS");
            cout << "Data Film : " << endl;
            printInfo_child(LC);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 8){
            system("CLS");
            cout << "Data Relasi : " << endl;
            printInfo_relasiAll(LR, LP, LC);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 9){
            system("CLS");
            cout << "====================================================================" << endl;
            cout << "               Film Yang Dibintangi Oleh Aktor/Aktris               " << endl;
            cout << "====================================================================" << endl;
            cout << "Masukkan Nama Aktor/Aktris : "; cin.ignore();
            getline(cin, namaartis);
            printInfoFilmByActor(LR, LP, LC, namaartis);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 10){
            system("CLS");
            cout << "================================================================" << endl;
            cout << "               Aktor/Aktris Yang Membintangi Film               " << endl;
            cout << "================================================================" << endl;
            cout << "Masukkan Nama Film : "; cin.ignore();
            getline(cin, namafilm);
            printInfoActorByFilm(LR, LP, LC, namafilm);
            system("PAUSE");
            system("CLS");
        } else if(pilih == 11){
            system("CLS");
            cout << "==============================================" << endl;
            cout << "               Top Aktor/Aktris               " << endl;
            cout << "==============================================" << endl;
            cout << "1. Top Aktor " << endl << "2. Top Aktris" << endl << endl << "Pilihan : ";
            cin >> pilih2;
            if(pilih2 == 1){
                system("CLS");
                printInfoMostMaleActor(LP);
                system("PAUSE");
                system("CLS");
            } else if(pilih2 == 2){
                system("CLS");
                printInfoMostFemaleActor(LP);
                system("PAUSE");
                system("CLS");
            } else if(pilih2 != 1 && pilih2 != 2){
                cout << "Pilihan Tidak Ada" << endl;
                system("PAUSE");
                system("CLS");
            }
        }
        cout << "================================================================" << endl;
        cout << "                         Data Perfilman                         " << endl;
        cout << "================================================================" << endl << endl;
        cout << "1. Penambahan Data Aktor / Aktris" << endl;
        cout << "2. Penambahan Data Film" << endl;
        cout << "3. Penambahan Data Relasi Aktor dan Film" << endl;
        cout << "4. Hapus Data Aktor / Aktris" << endl;
        cout << "5. Hapus Data Film" << endl;
        cout << "6. Tampil Data Aktor / Aktris" << endl;
        cout << "7. Tampil Data Film" << endl;
        cout << "8. Tampil Relasi Data Aktor/ Aktris beserta Film" << endl;
        cout << "9. Tampil Data Film yang Dibintangi Oleh Aktor/Aktris tertentu" << endl;
        cout << "10. Tampil Data Aktor/Aktris yang Membintangi Film Tertentu" << endl;
        cout << "11. Tampil Data 1 Orang Aktor dan 1 Orang Aktris yang Paing Top" << endl;
        cout << "12. Exit Program" << endl << endl;
        cout << "Pilihan : ";
        cin >> pilih;
        cout << endl;
    }

    return 0;
}
