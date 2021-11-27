// header buat console

#include "adt.h"


void printBanner();
/* I.S. Sembarang  */
/* F.S. Tampilan awal pada main menu saat permainan baru dibuka */

void printLoading();
/* I.S. Sembarang  */
/* F.S. Waktu bagi pemain untuk menunggu pengaturan saat awal bermain */

void printRoll();
/* I.S. Sembarang  */
/* F.S. Waktu menunggu bagi pemain untuk meng-generate roll dadu */

void newGame();
/* I.S. Sembarang  */
/* F.S. Permainan baru telah dimulai, mengisi data terkait permainan (player & map) */

void mainMenu();
/* I.S. Sembarang  */
/* F.S. Mengeluarkan tampilan awal berupa pilihan untuk memulai permainan baru atau memainkan permainan yang sudah ada sebelumnya */

int roll(Player p);
/* Menghasilkan sebuah angka hasil rolling dadu sesuai kondisi */

void endturn(State turn);
/* I.S. Ronde telah selesai dilaksanakan */
/* F.S. Melanjutkan ke ronde berikutnya dari permainan */

void undo();
/* I.S. Ronde sekarang (yang sedang berlangsung) */
/* F.S. Kembali ke ronde sebelumnya */

void save();


void CommandSkill (Player *P);
/* I.S. Sembarang  */
/* F.S. mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */


void playerRoll(Player P);
/* I.S. Sembarang  */
/* F.S. Pemain melakukan roll dadu dan melakukan langkahnya pada map menyesuaikan pada kondisi player (buff) */

void cmdPlayer();
/* I.S. Sembarang  */
/* F.S. Membaca setiap inputan yang diterima dari user terkait command yang ingin dilakukan user */

void playerTurn(State *St);
/* I.S. Sembarang  */
/* F.S. informasi terkait posisi dan keadaan player ketika berada di sebuah ronde */

void startGame();
/* I.S. Sembarang  */
/* F.S. Permainan dimulai */


void UseMesinWaktu (Player *T);
/* I.S. Sembarang  */
/* F.S. Pemain yang dipilih dimundurkan posisinya dari posisi sebelumnya */

void UseBalingBalingJambu (Player *T);
/* I.S. Sembarang  */
/* F.S. Pemain yang dipilih dimajukan posisinya dari posisi sebelumnya */
