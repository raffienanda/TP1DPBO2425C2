import java.util.ArrayList;
import java.util.List;

public class Pembelian {
    private String namaPembeli;                          //menyimpan nama pembeli
    private String emailPembeli;                         //menyimpan email pembeli
    private String metodePembayaran;                     //menyimpan metode pembayaran
    private List<String> namaBarang;                     //menyimpan daftar nama barang yang dibeli

    // Constructor
    public Pembelian(String namaPembeli, String emailPembeli, String metodePembayaran) {
        this.namaPembeli = namaPembeli;                  //set nama pembeli
        this.emailPembeli = emailPembeli;                //set email pembeli
        this.metodePembayaran = metodePembayaran;        //set metode pembayaran
        this.namaBarang = new ArrayList<>();             //inisialisasi list barang
    }

    // Getter dan Setter
    public String getNama() {
        return namaPembeli;                              //mengembalikan nama pembeli
    }

    public void setNama(String namaPembeli) {
        this.namaPembeli = namaPembeli;                  //set nama pembeli
    }

    public String getEmail() {
        return emailPembeli;                             //mengembalikan email pembeli
    }

    public void setEmail(String emailPembeli) {
        this.emailPembeli = emailPembeli;                //set email pembeli
    }

    public String getMetodePembayaran() {
        return metodePembayaran;                         //mengembalikan metode pembayaran
    }

    public void setMetodePembayaran(String metodePembayaran) {
        this.metodePembayaran = metodePembayaran;        //set metode pembayaran
    }

    public List<String> getNamaBarang() {
        return namaBarang;                               //mengembalikan list nama barang
    }

    public void tambahBarang(String barang) {
        this.namaBarang.add(barang);                     //tambah barang ke list namaBarang
    }

    public void clearBarang() {
        this.namaBarang.clear();                         //hapus semua barang dari list
    }

    @Override
    public String toString() {
        return "Nama Pembeli: " + namaPembeli +          //menampilkan nama pembeli
               "\nEmail: " + emailPembeli +              //menampilkan email pembeli
               "\nMetode Pembayaran: " + metodePembayaran + //menampilkan metode pembayaran
               "\nBarang: " + (namaBarang.isEmpty() ? "-" : String.join(", ", namaBarang)); //menampilkan daftar barang
    }
}
