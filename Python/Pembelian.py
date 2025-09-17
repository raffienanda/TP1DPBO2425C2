class Pembelian:
    def __init__(self):
        self.nama_pembeli = ""            #menyimpan nama pembeli
        self.email_pembeli = ""           #menyimpan email pembeli
        self.metode_pembayaran = ""       #menyimpan metode pembayaran
        self.nama_barang = []             #menyimpan daftar nama barang yang dibeli

    def set_pembelian(self, nama, email):
        self.nama_pembeli = nama          #set nama pembeli
        self.email_pembeli = email        #set email pembeli

    def get_nama(self):
        return self.nama_pembeli          #mengembalikan nama pembeli

    def get_email(self):
        return self.email_pembeli         #mengembalikan email pembeli

    def set_barang(self, barang):
        self.nama_barang.append(barang)   #tambah barang ke daftar nama_barang

    def get_barang(self):
        #mengembalikan daftar barang yang sudah diformat nomor urut
        return "\n".join([f"{i+1}. {barang}" for i, barang in enumerate(self.nama_barang)])

    def reset_barang(self):
        self.nama_barang.clear()          #hapus semua isi daftar nama_barang

    def set_metode(self, metode):
        self.metode_pembayaran = metode   #set metode pembayaran

    def get_metode(self):
        return self.metode_pembayaran     #mengembalikan metode pembayaran
