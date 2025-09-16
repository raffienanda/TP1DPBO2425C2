#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Pembelian{
    private:
        // Menyimpan nama pembeli
        string nama_pembeli;
        // Menyimpan email pembeli
        string email_pembeli;
        // Menyimpan metode pembayaran yang dipilih pembeli
        string metode_pembayaran;
        // Menyimpan daftar nama barang yang dipesan secara dinamis
        vector<string> nama_barang;

    public:
        //constructor
        Pembelian(){}

        //mengisi dan mengubah data nama dan email
        void setPembelian(string nama_pembeli, string email_pembeli){
            this->nama_pembeli = nama_pembeli;  
            this->email_pembeli = email_pembeli;
        }

        //mengembalikan nama pembeli
        string getNama(){
            return this->nama_pembeli;
        }

        //mengembalikan email pembeli
        string getEmail(){
            return this->email_pembeli;
        }

        //mengisi daftar barang yang dibeli
        void setBarang(string barang){
            //menambahkan nama barang ke dalam vector nama_barang
            nama_barang.push_back(barang);
        }

        //mengembalikan daftar barang yang dibeli
        string getBarang(){
            string list;                                                //membuat string untuk menampung list barang
            for(int i = 0; i < nama_barang.size(); i++){                //melakukan perulangan sebanyak jumlah barang yang ada
                list += to_string(i + 1) + ". " + nama_barang[i] + "\n";//menambahkan nomor urut, nama barang, dan enter ke dalam string list
            }
            return list;                                                //mengembalikan string list yang berisi daftar barang yang dibeli
        }

        //menghapus seluruh daftar barang
        void resetBarang(){
            //menghapus seluruh isi vector nama_barang
            nama_barang.clear();
        }

        //mengisi dan mengubah metode pembayaran
        void setMetode(string metode){
            this->metode_pembayaran = metode;
        }

        //mengembalikan metode pembayaran
        string getMetode(){
            return this->metode_pembayaran;
        }

        static void cariPembelian(vector<Pembelian> &daftar, string keyword){
            bool ketemu = false;
            for(int i = 0; i < daftar.size(); i++){
                if (daftar[i].getNama() == keyword || daftar[i].getEmail() == keyword) {
                    cout << "\n=== Data Ditemukan ===\n";
                    cout << "Nama Pembeli : " << daftar[i].getNama() << endl;
                    cout << "Email Pembeli : " << daftar[i].getEmail() << endl;
                    cout << "List Barang :" << endl;
                    cout << daftar[i].getBarang();
                    cout << "Metode Pembayaran : " << daftar[i].getMetode() << endl;
                    ketemu = true;
                }
            }
            if(!ketemu){
                cout << "\nData dengan keyword \"" << keyword << "\" tidak ditemukan.\n";
            }
        }

        //destructor
        ~Pembelian(){}
};
