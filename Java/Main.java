import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);                         //scanner untuk input user
        List<Pembelian> daftarPembelian = new ArrayList<>();              //list untuk simpan data pembelian
        int pilihan;                                                      //variabel untuk simpan pilihan menu

        do{
            System.out.println("\n=== Menu ===");                         //tampil judul menu utama
            System.out.println("1. Tambah Pembelian");                    //opsi tambah pembelian
            System.out.println("2. Lihat Semua Pembelian");               //opsi lihat semua pembelian
            System.out.println("3. Edit Pembelian");                      //opsi edit pembelian
            System.out.println("4. Hapus Pembelian");                     //opsi hapus pembelian
            System.out.println("5. Cari Pembelian");                      //opsi cari pembelian
            System.out.println("6. Keluar");                              //opsi keluar program
            System.out.print("Pilih menu: ");                             //input pilihan menu
            pilihan = scanner.nextInt();                                  //baca input pilihan menu
            scanner.nextLine();                                           //konsumsi newline

            switch (pilihan){
                case 1:
                    System.out.print("Masukkan Nama: ");                  //input nama pembeli
                    String nama = scanner.nextLine();                     //baca nama pembeli
                    System.out.print("Masukkan Email: ");                 //input email pembeli
                    String email = scanner.nextLine();                    //baca email pembeli
                    System.out.print("Masukkan Metode Pembayaran: ");     //input metode pembayaran
                    String metode = scanner.nextLine();                   //baca metode pembayaran
                    Pembelian pembelian = new Pembelian(nama, email, metode); //buat objek pembelian baru

                    System.out.print("Masukkan jumlah barang: ");         //input jumlah barang
                    int jumlahBarang = scanner.nextInt();                 //baca jumlah barang
                    scanner.nextLine();                                   //konsumsi newline
                    for (int i = 0; i < jumlahBarang; i++) {              //loop input nama barang
                        System.out.print("Barang ke-" + (i+1) + ": ");   //input nama barang ke-i
                        String barang = scanner.nextLine();               //baca nama barang
                        pembelian.tambahBarang(barang);                   //tambah barang ke objek
                    }
                    daftarPembelian.add(pembelian);                       //tambah objek ke list daftar
                    break;

                case 2:
                    if (daftarPembelian.isEmpty()) {                      //cek jika daftar kosong
                        System.out.println("Belum ada data pembelian.");  //pesan jika kosong
                    } else {
                        for (int i = 0; i < daftarPembelian.size(); i++) {//loop semua data
                            System.out.println("ID: " + (i+1));           //menampilkan id pembelian
                            System.out.println(daftarPembelian.get(i));   //menampilkan detail pembelian (nama, email, metode, barang)
                            System.out.println("--------------------");    //pemisah data
                        }
                    }
                    break;

                case 3:
                    System.out.print("Masukkan ID pembelian yang ingin diedit: "); //input id pembelian
                    int editId = scanner.nextInt();                       //baca id pembelian
                    scanner.nextLine();                                   //konsumsi newline
                    if (editId >= 1 && editId <= daftarPembelian.size()) {//cek id valid
                        Pembelian p = daftarPembelian.get(editId - 1);    //ambil objek yang mau diedit

                        System.out.print("Nama baru: ");                  //input nama baru
                        p.setNama(scanner.nextLine());                    //set nama baru

                        System.out.print("Email baru: ");                 //input email baru
                        p.setEmail(scanner.nextLine());                   //set email baru

                        System.out.print("Metode pembayaran baru: ");     //input metode baru
                        p.setMetodePembayaran(scanner.nextLine());        //set metode baru

                        System.out.print("Apakah ingin mengganti daftar barang? (y/n): "); //tanya ganti barang
                        String ubahBarang = scanner.nextLine();           //baca jawaban
                        if(ubahBarang.equalsIgnoreCase("y")){
                            p.clearBarang();                                    //hapus semua barang lama
                            System.out.print("Masukkan jumlah barang baru: ");  //input jumlah barang baru
                            int jumlahBaru = scanner.nextInt();                 //baca jumlah barang baru
                            scanner.nextLine();                                 //konsumsi newline
                            for(int i = 0; i < jumlahBaru; i++){                //loop input barang baru
                                System.out.print("Barang ke-" + (i+1) + ": ");  //input nama barang ke-i
                                String barang = scanner.nextLine();             //baca nama barang
                                p.tambahBarang(barang);                         //tambah barang ke daftar
                            }
                        }

                        System.out.println("Data berhasil diupdate.");    //konfirmasi edit data
                    }else{
                        System.out.println("ID tidak valid.");            //pesan jika id tidak valid
                    }
                    break;

                case 4:
                    System.out.print("Masukkan ID pembelian yang ingin dihapus: "); //input id pembelian
                    int hapusId = scanner.nextInt();                      //baca id pembelian
                    scanner.nextLine();                                   //konsumsi newline
                    if(hapusId >= 1 && hapusId <= daftarPembelian.size()){//cek id valid
                        daftarPembelian.remove(hapusId - 1);              //hapus data dari list
                        System.out.println("Data berhasil dihapus.");     //konfirmasi hapus data
                    }else{
                        System.out.println("ID tidak valid.");            //pesan jika id tidak valid
                    }
                    break;

                case 5:
                    System.out.print("Masukkan Nama atau ID pembelian: "); //input keyword pencarian
                    String keyword = scanner.nextLine();                   //baca keyword
                    boolean ditemukan = false;                             //penanda data ditemukan

                    for(int i = 0; i < daftarPembelian.size(); i++){       //loop semua data
                        if(String.valueOf(i+1).equals(keyword) || daftarPembelian.get(i).getNama().equalsIgnoreCase(keyword)){
                            System.out.println("Data ditemukan:");         //menampilkan pesan ditemukan
                            System.out.println("ID: " + (i+1));           //menampilkan id pembelian
                            System.out.println(daftarPembelian.get(i));   //menampilkan detail pembelian (nama, email, metode, barang)
                            ditemukan = true;                             //set ditemukan true
                            break;
                        }
                    }

                    if(!ditemukan){
                        System.out.println("Data tidak ditemukan.");       //pesan jika tidak ditemukan
                    }
                    break;

                case 6:
                    System.out.println("Keluar program...");               //pesan keluar program
                    break;

                default:
                    System.out.println("Pilihan tidak valid.");            //pesan jika input tidak valid
            }
        }while(pilihan != 6);                                              //loop selama belum pilih keluar

        scanner.close();                                                   //tutup scanner
    }
}
