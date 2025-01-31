/* permisi pak, di sini kami yang beranggotakan 3 orang (dimas, wahyu, fawaz) akan membuat suatu program di mana program tersebut menampilkan menu login dan menu utama
	apabila login berhasil (username dan nik benar/sesuai),maka dia akan menampilkan menu utama.
	di dalam menu utama, terdapat :
	- tambah barang (inputan berupa nama, berat barang, dan harga barang)
	- list barang (output berupa nama, berat barang, harga barang, total berat barang, dan total harga barang)
	- jumlah barang (berisi jumlah dari segala barang yang di masukan)
	dimana masing masing username memiliki list barang tersendiri berdasarkan username yang di input 
*/

#include <iostream>			//dimas andreansyah_2400018122
#include <fstream>
using namespace std;
struct registers
{
   string nama;
   long long nik;
};
static int j = 0; // untuk menandakan indeks pada saat pemanggilan array

void daftar(registers *reg)
{

   cin.ignore();
   cout << "Masukan Nama : ";
   getline(cin, reg[j].nama);
   cout << "Masukan NIM : ";
   cin >> reg[j].nik;

   ofstream akun;
   akun.open("akun.txt", ios::app); // setiap user atau username memiliki file txt masing masing
   akun << reg[j].nama << endl;
   akun << reg[j].nik << endl;
   akun.close();
   j++; // agar array tidak ditumpuk dan selalu bertambah
}

struct Nbarang
{ // informasi barang yang dijual
   string nama;
   double berat;
   long long harga;
};
static int indek = 0; // untuk menandakan indeks pada saat pemanggilan array

void Tmulai(Nbarang *barang, string a)			// Moh Wahyudin Huda_2400018136
{
   cin.ignore();
   cout << "Masukan Nama Barang : ";
   getline(cin, barang[indek].nama);
   cout << "Masukan Berat Barang : ";
   cin >> barang[indek].berat;
   cin.ignore();
   cout << "Masukan Harga barang : ";
   cin >> barang[indek].harga;

   ofstream dataBrg;
   dataBrg.open("barang.txt", ios::app); // tiap username memiliki informasi jual beli pada file txt masing masing
   dataBrg << barang[indek].nama << endl;
   dataBrg << barang[indek].berat << endl;
   dataBrg << barang[indek].harga;
   dataBrg.close();
   indek++;
}

void Tlist(string a)
{
   int l = 0, k = 0;
   int o = 0;
   ifstream dataBrg("barang.txt"); // membaca setiap barang yang akan di muncul di list dengan membaca masing masing file txt dari username
   string nbarang;
   double nberat;
   long long nharga;
   while (!dataBrg.eof())
   { // apabila variable dataBrg atau file txt dibuka, maka akan mengeksekusi perintah tertentu
      getline(dataBrg, nbarang);
      dataBrg >> nberat;
      dataBrg >> nharga;
      cout << o + 1 << ". " << nbarang << endl;
      cout << "berat : " << nberat << " kg" << endl;
      l = l + nberat;
      cout << "Rp." << nharga << endl;
      k = k + nharga;
      cout << endl
           << endl;
      o++;
   }
   cout << "Total Berat : " << l << endl;
   cout << "Total Harga : Rp." << k << endl;

   dataBrg.close();
}

void mulai(string a)
{
   Nbarang barang[1000];
   while (true)
   {
      cout << "1. Tambah Barang" << endl;
      cout << "2. List dan Total Barang" << endl;
      cout << "3. Keluar" << endl;
      int pil;
      cout << "Masukan Pilihan : ";
      cin >> pil;
      switch (pil)
      {
      case 1:
         Tmulai(barang, a);
         break;
      case 2:
         Tlist(a);
         break;
      case 3:
      	cout << "Keluar...\n";
                return;
      default:
                cout << "Pilihan tidak ada.\n";
      }
   }
}

void login(registers *reg)
{

   string a;
   long long b;
   cin.ignore();
   cout << "Masukan Username : ";
   getline(cin, a); // username login akan dimasukan sementara kedalam variable a
   cout << "Masukan NIM : ";
   cin >> b; // password atau nik user akan dimasukan sementara kedalam variable b

   ifstream akun("akun.txt");

   string p;
   long long q;
   bool loginBerhasil = false;

    while (getline(akun, p) && akun >> q)
    {
        akun.ignore(); // Mengabaikan newline setelah membaca NIM

        if (p == a && q == b)
        {
            loginBerhasil = true;
            break;
        }
    }

    akun.close();

    if (loginBerhasil)
    {
        cout << "Login berhasil!\n";
        mulai(a); // Panggil fungsi mulai dengan username yang valid
    }
    else
    {
        cout << "Login gagal! Username atau NIM salah.\n";
    }
}

void lihat(registers *reg) 
{
   ifstream Data("akun.txt"); // file yang berisi username username yang telah di daftarkan pada menu register
   string temp;
   int t = 1;
   while (getline(Data, temp))
   {
      cout << t << ". " << temp << endl;
      t++;
   }
}
int main()		//Fawwaz Syahmil Aufa Purba_2400018108 	
{
   registers reg[1000];
   while (true)
   {
      cout << "1. Register" << endl;
      cout << "2. Login" << endl;
      cout << "3. Lihat Username" << endl;
      int pil;
      cout << "Masukan Pilihan : ";
      cin >> pil;
      system("cls");
      switch (pil)
      {
      case 1:
         daftar(reg);
         system("pause");
         system("cls");
         break;
      case 2:
         login(reg);
         system("pause");
         system("cls");
         break;
      case 3:
         lihat(reg);
         system("pause");
         system("cls");
      }
   }
   return 0;
}
