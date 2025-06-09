#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string baris;
    string namefile;

    cout << "Masukkan name file : ";
    cin >> namefile;
    cin.ignore();

    //membuat objek output file stream
    ofstream outfile;
    // membuka file untuk ditulisi
    outfile.open(namefile + ".csvcontoh");

    cout << ">= Menulis file, \'q\' untuk keluar" << endl;

    //unlimited loop untuk menulis
    while(true) {
        cout << "- ";
        //mendapatkan setiap karakter dalam satu baris
        getline(cin, baris);
        // loop akan berhenti jika anda memasukkan karakter q
        if (baris == "q") break;
        //menulis dan memasukkan nilai dari 'baris' ke dalam file 
        outfile << baris << endl;
    }
    //selesai dalam menulis sekarang tutup filenya
    outfile.close();

    //membuat objek input file stream
    ifstream infile;
    // membuka file yang dituliskan
    infile.open(namefile + ".csv");

    cout << endl << ">= Membuka dan membaca file " << endl;
    //jika file ada maka 
    if (infile.is_open())
    {
        while (getline(infile, baris))
        {
            //dan tampilkan di sini
            cout << baris << '\n';
        }
        // tutup file tersebut setelah selesai
        infile.close();
    }
    //jika tidak ditemukan file maka akan menampilkan ini
    else cout << "Unable to open file";
    return 0;
}