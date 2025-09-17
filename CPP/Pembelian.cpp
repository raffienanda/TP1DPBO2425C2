#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Pembelian{
    private:
        string nama_pembeli;        //menyimpan nama pembeli
        string email_pembeli;       //menyimpan email pembeli
        string metode_pembayaran;   //menyimpan metode pembayaran
        vector<string> nama_barang; //menyimpan daftar nama barang yang dibeli

    public:
        //konstruktor
        Pembelian(){} 

        void setPembelian(string nama, string email){
            this->nama_pembeli = nama;      //set nama pembeli
            this->email_pembeli = email;    //set email pembeli
        }

        string getNama(){
            return this->nama_pembeli; //mengembalikan nama pembeli
        }

        string getEmail(){
            return this->email_pembeli; //mengembalikan email pembeli
        }

        void setBarang(string barang){
            nama_barang.push_back(barang); //tambah barang ke vector nama_barang
        }

        string getBarang(){
            string list;                                                //menampung daftar barang
            for(int i = 0; i < nama_barang.size(); i++){
                list += to_string(i + 1) + ". " + nama_barang[i] + "\n";//format nomor dan nama barang
            }
            return list;                                                //mengembalikan daftar barang terformat
        }

        void resetBarang(){
            nama_barang.clear(); //hapus semua isi vector nama_barang
        }

        void setMetode(string metode){
            this->metode_pembayaran = metode; //set metode pembayaran
        }

        string getMetode(){
            return this->metode_pembayaran; //mengembalikan metode pembayaran
        }

        ~Pembelian(){} //destruktor
};
