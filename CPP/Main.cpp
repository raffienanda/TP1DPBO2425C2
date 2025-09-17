#include "Pembelian.cpp"

int main(){
    //membuat vector untuk menyimpan daftar pembelian
    vector<Pembelian> daftarPembelian; 

    //variabel untuk menyimpan pilihan menu
    int pilihan; 

    do{
        cout << "\n=== MENU UTAMA ===\n";       //menampilkan judul menu utama
        cout << "1. Tambah Pembelian\n";        //opsi tambah pembelian
        cout << "2. Lihat Semua Pembelian\n";   //opsi lihat semua pembelian
        cout << "3. Edit Pembelian\n";          //opsi edit pembelian
        cout << "4. Hapus Pembelian\n";         //opsi hapus pembelian
        cout << "5. Cari Pembelian\n";          //opsi cari pembelian
        cout << "6. Keluar\n";                  //opsi keluar dari program
        cout << "Pilih: ";                      //meminta input pilihan menu
        cin >> pilihan;                         //membaca input pilihan menu

        if(pilihan == 1){               //jika memilih tambah pembelian
            Pembelian p;                //membuat objek pembelian baru
            string nama, email, metode; //variabel untuk input data pembeli
            int jumlahBarang;           //variabel untuk jumlah barang

            cin.ignore();                           //mengabaikan karakter newline dari input sebelumnya
            cout << "Masukkan Nama Pembeli   : ";   //input nama pembeli
            getline(cin, nama);                     //membaca nama pembeli
            cout << "Masukkan Email Pembeli  : ";   //input email pembeli
            getline(cin, email);                    //membaca email pembeli
            p.setPembelian(nama, email);            //set nama dan email ke objek pembelian

            cout << "Masukkan Metode Bayar   : ";   //input metode pembayaran
            getline(cin, metode);                   //membaca metode pembayaran
            p.setMetode(metode);                    //set metode pembayaran ke objek pembelian

            cout << "Jumlah Barang Dibeli    : ";   //input jumlah barang
            cin >> jumlahBarang;                    //membaca jumlah barang
            cin.ignore();                           //mengabaikan karakter newline

            for(int i = 0; i < jumlahBarang; i++){      //loop untuk input nama barang
                string item;                            //variabel untuk nama barang
                cout << "  Barang ke-" << i+1 << " : "; //input nama barang ke-i
                getline(cin, item);                     //membaca nama barang
                p.setBarang(item);                      //menambahkan barang ke objek pembelian
            }

            daftarPembelian.push_back(p);                       //menambahkan objek pembelian ke vector daftarPembelian
            cout << "\nData pembelian berhasil ditambahkan!\n"; //konfirmasi data berhasil ditambah

        }else if(pilihan == 2){                         //jika memilih lihat semua pembelian
            if(daftarPembelian.empty()){                //cek jika daftar kosong
                cout << "Belum ada data pembelian.\n";  //tampilkan pesan jika kosong
            }else{
                cout << "\n=== DAFTAR PEMBELIAN ===\n";             //judul daftar pembelian
                for(int i = 0; i < daftarPembelian.size(); i++){    //loop semua data pembelian
                    cout << "Pembelian #" << i+1 << endl;           //tampilkan nomor pembelian
                    cout << "Nama Pembeli   : " << daftarPembelian[i].getNama() << endl;    //tampilkan nama pembeli
                    cout << "Email Pembeli  : " << daftarPembelian[i].getEmail() << endl;   //tampilkan email pembeli
                    cout << "Metode Bayar   : " << daftarPembelian[i].getMetode() << endl;  //tampilkan metode pembayaran
                    cout << "Daftar Barang  :\n" << daftarPembelian[i].getBarang();         //tampilkan daftar barang
                    cout << "-----------------------------\n";                              //pemisah antar data
                }
            }

        }else if(pilihan == 3){ //jika memilih edit pembelian
            int id;                                                 //variabel untuk nomor pembelian yang akan diedit
            cout << "Masukkan nomor pembelian yang ingin diedit: "; //input nomor pembelian
            cin >> id;                                              //membaca nomor pembelian
            cin.ignore();                                           //mengabaikan karakter newline

            if(id < 1 || id > daftarPembelian.size()){  //cek validitas id
                cout << "ID tidak valid.\n";            //tampilkan pesan jika id tidak valid
            }else{
                string nama, email, metode; //variabel untuk data baru
                int jumlahBarang;           //variabel untuk jumlah barang baru

                cout << "Edit Nama Pembeli   : ";               //input nama baru
                getline(cin, nama);                             //membaca nama baru
                cout << "Edit Email Pembeli  : ";               //input email baru
                getline(cin, email);                            //membaca email baru
                daftarPembelian[id-1].setPembelian(nama, email);//set nama dan email baru

                cout << "Edit Metode Bayar   : ";       //input metode pembayaran baru
                getline(cin, metode);                   //membaca metode pembayaran baru
                daftarPembelian[id-1].setMetode(metode);//set metode pembayaran baru

                daftarPembelian[id-1].resetBarang();//hapus semua barang lama
                cout << "Jumlah Barang Baru  : ";   //input jumlah barang baru
                cin >> jumlahBarang;                //membaca jumlah barang baru
                cin.ignore();                       //mengabaikan karakter newline

                for(int i = 0; i < jumlahBarang; i++){      //loop input barang baru
                    string item;                            //variabel nama barang
                    cout << "  Barang ke-" << i+1 << " : "; //input nama barang ke-i
                    getline(cin, item);                     //membaca nama barang
                    daftarPembelian[id-1].setBarang(item);  //tambah barang ke daftar
                }
                //konfirmasi data berhasil diedit
                cout << "Data pembelian berhasil diedit!\n"; 
            }

        }else if(pilihan == 4){ //jika memilih hapus pembelian
            int id;                                                 //variabel untuk nomor pembelian yang akan dihapus
            cout << "Masukkan nomor pembelian yang ingin dihapus: ";//input nomor pembelian
            cin >> id;                                              //membaca nomor pembelian

            if(id < 1 || id > daftarPembelian.size()){  //cek validitas id
                cout << "ID tidak valid.\n";            //tampilkan pesan jika id tidak valid
            }else{
                daftarPembelian.erase(daftarPembelian.begin() + (id-1));    //hapus data pembelian dari vector
                cout << "Data pembelian berhasil dihapus!\n";               //konfirmasi data berhasil dihapus
            }

        }else if(pilihan == 5){ //jika memilih cari pembelian
            cin.ignore();                                           //mengabaikan karakter newline
            string keyword;                                         //variabel untuk keyword pencarian
            cout << "Masukkan nama pembeli atau ID untuk dicari: "; //input keyword
            getline(cin, keyword);                                  //membaca keyword

            bool ketemu = false;                                //penanda apakah data ditemukan
            for(int i = 0; i < daftarPembelian.size(); i++){    //loop semua data pembelian
                //cek apakah input berupa angka (id) atau nama pembeli
                if(to_string(i+1) == keyword || daftarPembelian[i].getNama() == keyword){
                    cout << "\nPembelian ditemukan!\n";                                     //tampilkan pesan ditemukan
                    cout << "Pembelian #" << i+1 << endl;                                   //tampilkan nomor pembelian
                    cout << "Nama Pembeli   : " << daftarPembelian[i].getNama() << endl;    //tampilkan nama pembeli
                    cout << "Email Pembeli  : " << daftarPembelian[i].getEmail() << endl;   //tampilkan email pembeli
                    cout << "Metode Bayar   : " << daftarPembelian[i].getMetode() << endl;  //tampilkan metode pembayaran
                    cout << "Daftar Barang  :\n" << daftarPembelian[i].getBarang();         //tampilkan daftar barang
                    cout << "-----------------------------\n";                              //pemisah antar data
                    ketemu = true;                                                          //set ketemu menjadi true
                }
            }
            if(!ketemu){                                    //jika tidak ditemukan
                cout << "Data pembelian tidak ditemukan.\n";//tampilkan pesan tidak ditemukan
            }

        }else if(pilihan == 6){                 //jika memilih keluar
            cout << "Program selesai. Bye!\n";  //tampilkan pesan keluar
        }else{
            cout << "Pilihan tidak valid!\n";   //tampilkan pesan jika input menu tidak valid
        }

    }while(pilihan != 6); //loop selama pilihan bukan 6

    return 0;
}
