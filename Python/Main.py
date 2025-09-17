from Pembelian import Pembelian

def main():
    #list untuk menyimpan objek pembelian
    daftar_pembelian = [] 

    while True:
        print("\n=== MENU UTAMA ===")       #tampil judul menu utama
        print("1. Tambah Pembelian")        #opsi tambah pembelian
        print("2. Lihat Semua Pembelian")   #opsi lihat semua pembelian
        print("3. Edit Pembelian")          #opsi edit pembelian
        print("4. Hapus Pembelian")         #opsi hapus pembelian
        print("5. Cari Pembelian")          #opsi cari pembelian
        print("6. Keluar")                  #opsi keluar program
        pilihan = input("Pilih: ")          #input pilihan menu

        #jika tambah pembelian
        if pilihan == "1": 
            p = Pembelian()                             #buat objek pembelian baru
            nama = input("Masukkan Nama Pembeli   : ")  #input nama pembeli
            email = input("Masukkan Email Pembeli  : ") #input email pembeli
            p.set_pembelian(nama, email)                #set nama & email ke objek

            metode = input("Masukkan Metode Bayar   : ")#input metode pembayaran
            p.set_metode(metode)                        #set metode pembayaran ke objek

            try:
                jumlah_barang = int(input("Jumlah Barang Dibeli    : "))#input jumlah barang
            except ValueError:
                jumlah_barang = 0                                       #jika input tidak valid, set 0

            for i in range(jumlah_barang):              #loop input nama barang
                item = input(f"  Barang ke-{i+1} : ")   #input nama barang ke-i
                p.set_barang(item)                      #tambah barang ke objek

            daftar_pembelian.append(p)                      #tambah objek ke list daftar
            print("\nData pembelian berhasil ditambahkan!") 

        #jika lihat semua pembelian
        elif pilihan == "2": 
            if not daftar_pembelian:               #cek jika daftar kosong
                print("Belum ada data pembelian.") #pesan jika kosong
            else: #jika ada data
                print("\n=== DAFTAR PEMBELIAN ===") 
                for i, pembelian in enumerate(daftar_pembelian, start=1):   #loop semua data
                    print(f"Pembelian #{i}")                                #menampilkan nomor pembelian
                    print("Nama Pembeli   :", pembelian.get_nama())         #menampilkan nama pembeli
                    print("Email Pembeli  :", pembelian.get_email())        #menampilkan email pembeli
                    print("Metode Bayar   :", pembelian.get_metode())       #menampilkan metode pembayaran
                    print("Daftar Barang  :\n" + pembelian.get_barang())    #menampilkan daftar barang
                    print("-----------------------------")                  

        #jika edit pembelian
        elif pilihan == "3": 
            try:
                #input nomor pembelian
                id_edit = int(input("Masukkan nomor pembelian yang ingin diedit: ")) 
            except ValueError:
                #jika input tidak valid
                print("ID tidak valid.") 
                continue

            if id_edit < 1 or id_edit > len(daftar_pembelian):  #cek id valid
                print("ID tidak valid.")                        #pesan jika id tidak valid
            else:
                p = daftar_pembelian[id_edit-1]         #ambil objek yang mau diedit
                nama = input("Edit Nama Pembeli   : ")  #input nama baru
                email = input("Edit Email Pembeli  : ") #input email baru
                p.set_pembelian(nama, email)            #set nama & email baru

                metode = input("Edit Metode Bayar   : ")#input metode baru
                p.set_metode(metode)                    #set metode baru

                #hapus semua barang lama
                p.reset_barang() 
                try:
                    #jika input valid, input jumlah barang baru
                    jumlah_barang = int(input("Jumlah Barang Baru  : ")) 
                except ValueError:
                    #jika input tidak valid
                    jumlah_barang = 0 

                for i in range(jumlah_barang):              #loop input barang baru
                    item = input(f"  Barang ke-{i+1} : ")   #input nama barang ke-i
                    p.set_barang(item)                      #tambah barang ke daftar

                print("Data pembelian berhasil diedit!")

        #jika hapus pembelian
        elif pilihan == "4": 
            try:
                #jika input valid, input nomor pembelian
                id_hapus = int(input("Masukkan nomor pembelian yang ingin dihapus: ")) 
            except ValueError:
                #jika pesan jika input tidak valid
                print("ID tidak valid.") 
                continue

            if id_hapus < 1 or id_hapus > len(daftar_pembelian):#cek id valid
                print("ID tidak valid.")                        #pesan jika id tidak valid
            else:
                daftar_pembelian.pop(id_hapus-1)            #hapus data dari list
                print("Data pembelian berhasil dihapus!")   #konfirmasi hapus data

        #jika cari pembelian
        elif pilihan == "5": 
            keyword = input("Masukkan nama pembeli atau ID untuk dicari: ") #input keyword
            ketemu = False                                                  #penanda data ditemukan

            for i, pembelian in enumerate(daftar_pembelian, start=1):   #loop semua data
                if str(i) == keyword or pembelian.get_nama() == keyword:#cek id/nama
                    print("\nPembelian ditemukan!")                     #menampilkan pesan ditemukan
                    print(f"Pembelian #{i}")                            #menampilkan nomor pembelian
                    print("Nama Pembeli   :", pembelian.get_nama())     #menampilkan nama pembeli
                    print("Email Pembeli  :", pembelian.get_email())    #menampilkan email pembeli
                    print("Metode Bayar   :", pembelian.get_metode())   #menampilkan metode pembayaran
                    print("Daftar Barang  :\n" + pembelian.get_barang())#menampilkan daftar barang
                    print("-----------------------------")              
                    ketemu = True                                       #set ketemu dengan true
            
            #jika tidak ditemukan
            if not ketemu: 
                print("Data pembelian tidak ditemukan.") 
        
        #jika keluar
        elif pilihan == "6": 
            print("Program selesai. Bye!")
            break
        else:
            #pesan jika input tidak valid
            print("Pilihan tidak valid!") 

if __name__ == "__main__":
    main()
