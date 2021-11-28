# Tugas Besar Alstrukdat - Kelompok 09

## Deskripsi 

Seorang mahasiswa Sistem dan Teknologi Informasi bernama Mobitang dan biasa dipanggil Mobi sedang kebingungan dalam menyelesaikan tugas programnya. 
Tugas program ini merupakan tugas akhir dari masa perkuliahannya di semester 3. Mobi mendapatkan bantuan dari 5 orang temannya yang ada di Jurusan Informatika. 
Kebetulan tugas Mobi adalah membuat game dengan spesifikasi yang mirip dengan permainan ular tangga. Karena mereka kebingungan dalam menamai game ini, 
akhirnya tercetus nama Mobitangga sebagai nama game tersebut. Mobi dengan 5 orang temannya ini kemudian memulai pekerjaannya agar tidak dekat dengan deadline.
Mobitangga merupakan game simulasi yang mirip dengan permainan ular tangga. Mobitangga diprogram menggunakan Bahasa C, dan merupakan permainan yang berbasis CLI 
(Command Line Interface). Program permainan Mobitangga ini memanfaatkan berbagai struktur data terkait list, array, mesin kata, dan stack serta struktur data baru 
yang dibuat demi memenuhi kebutuhan program dalam permainan.

## Anggota Kelompok 09

> Riandy Hasan 	              18220058 

> Calvin 				              18220062 

> Christian Michael Mozart S 	18220068 

> Alifiya Brizita Shary 		  18220069 

> Yosafat Raditya 			      18220078 

## Alur Program 

Alur permainan Mobitangga dimulai dari penentuan jumlah pemain yang akan bermain, dilanjutkan dengan pemutaran dadu dan pemerolehan skill dari hasil pengacakan, 
tergantung pada command yang dimasukkan pemain. Permainan dijalankan dengan batasan ronde. Dalam sebuah ronde, seorang pemain dapat memilih untuk menggunakan skill 
dan melakukan pemutaran dadu. Setiap ronde yang sudah dijalankan (sudah berlalu) akan disimpan datanya dan seorang pemain dapat melakukan undo untuk mengembalikan 
keadaan permainan menjadi keadaan seperti ronde sebelumnya. Permainan akan berakhir ketika terdapat seorang pemain yang sudah mencapai petak akhir dari map permainan.
Apabila permainan tidak ingin dilanjutkan, dapat dilakukan save yaitu untuk menyimpan state permainan saat itu. 

## Directory 

|   README.MD
|   
+---bin
|       Mobitangga.bat
|       Mobitangga.exe
|       sample_save.txt
|       test.txt
|       testlagi.txt
|       
+---data
|       100.txt
|       30.txt
|       40.txt
|       50.txt
|       70.txt
|       test.txt
|       
+---docs
|       Form Asistensi Tugas Besar.docx.pdf
|       Spesifikasi Tugas Besar IF2111 2021_2022.pdf
|       
\---src
    |   adt.h
    |   boolean.h
    |   console.c
    |   console.h
    |   main.c
    |   
    \---ADT
            array.c
            array.h
            driverarray.c
            driverlistlinier.c
            drivermap.c
            drivermesinkarkata.c
            driverplayer.c
            driverstate.c
            driverteleporter.c
            listlinier.c
            listlinier.h
            map.c
            map.h
            mesin_kar.c
            mesin_kar.h
            mesin_kata.c
            mesin_kata.h
            player.c
            player.h
            stack.c
            stack.h
            state.c
            state.h
            teleporter.c
            teleporter.h

## How to start play
1. Pergi ke folder bin lalu buka Mobitangga.bat
2. Pilih new gama atau load game
3. Pilih konfigurasi map
4. Selamat bermain :D 

