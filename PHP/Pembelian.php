<?php
session_start(); //mulai session untuk menyimpan data pembelian

// Inisialisasi array pembelian jika belum ada di session
if (!isset($_SESSION['pembelian'])) {
    $_SESSION['pembelian'] = []; //buat array kosong untuk data pembelian
}

// === Tambah data pembelian ===
if (isset($_POST['tambah'])) {
    $nama   = $_POST['nama']; //ambil nama dari form
    $email  = $_POST['email']; //ambil email dari form
    $metode = $_POST['metode']; //ambil metode pembayaran dari form
    $barang = explode(",", $_POST['barang']); //ubah input barang jadi array

    // Upload foto
    $fotoPath = ""; //inisialisasi path foto
    $targetDir = "uploads/"; //folder upload
    if (!is_dir($targetDir)) {
        mkdir($targetDir, 0777, true); //buat folder upload jika belum ada
    }

    if (isset($_FILES['foto']) && $_FILES['foto']['error'] === 0) { //cek jika ada file foto diupload
        $fileName = time() . "_" . basename($_FILES['foto']['name']); //buat nama file unik
        $fotoPath = $targetDir . $fileName; //gabungkan folder dan nama file

        if (!move_uploaded_file($_FILES['foto']['tmp_name'], $fotoPath)) { //upload file ke server
            $fotoPath = ""; //jika gagal upload, kosongkan path
        }
    }

    //simpan data pembelian ke session
    $_SESSION['pembelian'][] = [
        "nama"   => $nama,
        "email"  => $email,
        "metode" => $metode,
        "barang" => $barang,
        "foto"   => $fotoPath
    ];
}

// === Hapus data pembelian ===
if (isset($_GET['hapus'])) {
    $id = $_GET['hapus']; //ambil id yang mau dihapus
    unset($_SESSION['pembelian'][$id]); //hapus data dari array
    $_SESSION['pembelian'] = array_values($_SESSION['pembelian']); //reset index array
    header("Location: Pembelian.php"); //redirect ke halaman utama
    exit;
}

// === Edit data pembelian ===
if (isset($_POST['edit'])) {
    $id     = $_POST['id']; //ambil id data yang diedit
    $nama   = $_POST['nama']; //ambil nama baru
    $email  = $_POST['email']; //ambil email baru
    $metode = $_POST['metode']; //ambil metode baru
    $barang = explode(",", $_POST['barang']); //ubah input barang jadi array

    $fotoPath = $_SESSION['pembelian'][$id]['foto']; //default pakai foto lama
    if (isset($_FILES['foto']) && $_FILES['foto']['error'] === 0) { //jika upload foto baru
        $targetDir = "uploads/";
        $fileName = time() . "_" . basename($_FILES['foto']['name']);
        $newPath = $targetDir . $fileName;
        if (move_uploaded_file($_FILES['foto']['tmp_name'], $newPath)) {
            $fotoPath = $newPath; //pakai foto baru jika berhasil upload
        }
    }

    //update data di session
    $_SESSION['pembelian'][$id] = [
        "nama"   => $nama,
        "email"  => $email,
        "metode" => $metode,
        "barang" => $barang,
        "foto"   => $fotoPath
    ];
    header("Location: Pembelian.php"); //redirect ke halaman utama
    exit;
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Data Pembelian</title>
</head>
<body>
    <h2>Form Tambah Pembelian</h2>
    <form method="post" enctype="multipart/form-data">
        Nama: <input type="text" name="nama" required><br>
        Email: <input type="email" name="email" required><br>
        Metode Bayar: <input type="text" name="metode" required><br>
        Barang (pisahkan dengan koma): <input type="text" name="barang" required><br>
        Foto: <input type="file" name="foto"><br>
        <button type="submit" name="tambah">Tambah</button>
    </form>

    <h2>Cari Pembelian</h2>
    <form method="get">
        <input type="text" name="cari" placeholder="Masukkan ID atau Nama">
        <button type="submit">Cari</button>
    </form>

    <h2>Daftar Pembelian</h2>
    <?php
    $data = $_SESSION['pembelian']; //ambil semua data pembelian dari session

    // Jika ada pencarian
    if (isset($_GET['cari']) && $_GET['cari'] !== "") {
        $keyword = $_GET['cari']; //ambil keyword pencarian
        $hasil = [];
        foreach ($data as $i => $p) {
            //cari berdasarkan id atau nama (mengandung keyword)
            if ($keyword == $i+1 || stripos($p['nama'], $keyword) !== false) {
                $hasil[$i] = $p;
            }
        }
        $data = $hasil; //tampilkan hasil pencarian saja
    }

    if (empty($data)) {
        echo "<p>Belum ada data.</p>"; //tampilkan pesan jika data kosong
    } else {
        //tampilkan tabel data pembelian
        echo "<table border='1' cellpadding='5'>
                <tr>
                    <th>ID</th>
                    <th>Nama</th>
                    <th>Email</th>
                    <th>Metode</th>
                    <th>Barang</th>
                    <th>Foto</th>
                    <th>Aksi</th>
                </tr>";
        foreach ($data as $i => $p) {
            echo "<tr>
                    <td>".($i+1)."</td>                                        
                    <td>".htmlspecialchars($p['nama'])."</td>                   
                    <td>".htmlspecialchars($p['email'])."</td>                  
                    <td>".htmlspecialchars($p['metode'])."</td>                 
                    <td>".implode(', ', $p['barang'])."</td>                    
                    <td>";
            if ($p['foto']) {
                echo "<img src='".$p['foto']."' width='80'>";                   //tampilkan foto jika ada
            } else {
                echo "(Tidak ada foto)";                                        //tampilkan jika tidak ada foto
            }
            echo "</td>
                  <td>
                    <a href='?hapus=$i'>Hapus</a> |                             
                    <a href='?edit=$i'>Edit</a>                                
                  </td>
                </tr>";
        }
        echo "</table>";
    }

    // Form edit
    if (isset($_GET['edit'])) {
        $id = $_GET['edit']; //ambil id yang mau diedit
        $p = $_SESSION['pembelian'][$id]; //ambil data pembelian sesuai id
        ?>
        <h2>Edit Pembelian</h2>
        <form method="post" enctype="multipart/form-data">
            <input type="hidden" name="id" value="<?= $id ?>">
            Nama: <input type="text" name="nama" value="<?= htmlspecialchars($p['nama']) ?>"><br>
            Email: <input type="email" name="email" value="<?= htmlspecialchars($p['email']) ?>"><br>
            Metode Bayar: <input type="text" name="metode" value="<?= htmlspecialchars($p['metode']) ?>"><br>
            Barang (pisahkan dengan koma): <input type="text" name="barang" value="<?= implode(", ", $p['barang']) ?>"><br>
            Foto: <input type="file" name="foto"><br>
            <?php if ($p['foto']): ?>
                <img src="<?= $p['foto'] ?>" width="80"><br>                   <!-- tampilkan foto lama jika ada -->
            <?php endif; ?>
            <button type="submit" name="edit">Simpan</button>
        </form>
        <?php
    }
    ?>
</body>
</html>
