#include "Pembelian.cpp"

int main(){
    vector<Pembelian> daftar; // menyimpan banyak objek Pembelian

    //membuat objek p1 dari kelas Pembelian
    Pembelian p1;
    p1.setPembelian("budi", "budi@gmail.com");  //mengisi nama dan email pembeli
    p1.setBarang("Laptop");                     //mengisi daftar barang yang dibeli
    p1.setBarang("Mouse");                      
    p1.setBarang("Flashdisk");                  //mengisi daftar barang yang dibeli
    p1.setMetode("Cash");                       //mengisi metode pembayaran
    daftar.push_back(p1);                       //menyimpan objek p1 ke dalam vector daftar

    //menampilkan data
    cout << "Nama Pembeli p1 : " << p1.getNama() << endl;               //menampilkan nama pembeli
    cout << "Nama Email p1 : " << p1.getEmail() << endl;                //menampilkan email pembeli
    cout << "List barang yang dibeli :" << endl;                        //menampilkan list barang yang dibeli
    cout << p1.getBarang();
    cout << "Metode Pembayaran : " << p1.getMetode() << endl << endl;   //menampilkan metode pembayaran yang digunakan

    //mengedit data pembeli
    p1.setPembelian("budiGanti", "budiGanti@gmail.com");    //mengganti nama pembeli
    p1.resetBarang();                                       //mengosongkan list barang
    p1.setBarang("TV");                                     //mengisi daftar barang yang dibeli
    p1.setMetode("transfer");                               //mengganti metode pembayaran
    daftar.push_back(p1);                                   //menyimpan objek p1 ke dalam vector daftar

    //menampilkan setelah mengubah data
    cout << "Nama Pembeli p1 : " << p1.getNama() << endl;               //menampilkan nama pembeli
    cout << "Nama Email p1 : " << p1.getEmail() << endl;                //menampilkan email pembeli
    cout << "List barang yang dibeli :" << endl;                        //menampilkan list barang yang dibeli
    cout << p1.getBarang();
    cout << "Metode Pembayaran : " << p1.getMetode() << endl << endl;   //menampilkan metode pembayaran yang digunakan

    p1.setPembelian("", "");//mengosongkan nama dan email pembeli
    p1.resetBarang();       //mengosongkan list barang
    p1.setMetode("");       //mengosongkan metode pembayaran

    //menampilkan setelah mengosongkan data
    cout << "Nama Pembeli p1 : " << p1.getNama() << endl;   //menampilkan nama pembeli
    cout << "Nama Email p1 : " << p1.getEmail() << endl;    //menampilkan email pembeli
    cout << "List barang yang dibeli :" << endl;            //menampilkan list barang yang dibeli
    cout << p1.getBarang();
    cout << "Metode Pembayaran : " << p1.getMetode() << endl;//menampilkan metode pembayaran yang digunakan

    Pembelian::cariPembelian(daftar, "budi");   //mencari data pembeli dengan nama "budi"

    return 0;
}