#include <iostream>

using namespace std;

int main()
{
    //setup jumlah hari dalam tiap bulan dan tahun
    int months[12], year=365;
    for(int i=0; i<12; ++i){
        if(i%2==0)months[i]=31;
        else months[i]=30;
    }
    months[1]=28;
    string month_name[12] = {"Januari","Februari","Maret","April","Mei","Juni","Juli","Agustus","September","Oktober","November","Desember"};

    int tahun, bulan, tanggal, hari, harix;
    //input tanggal sekarang
    cout << "Kalkulator Kalender\n\n"<< "masukkan tanggal hari ini\n";
    cout << "Tahun: ";
    cin >> tahun;
    cout << "Bulan(1-12): ";
    cin >> bulan;
    cout << "tanggal: ";
    cin >> tanggal;
    //input hari yang dihitung
    cout<< "jumlah hari yang akan dihitung:";
    cin >> hari;
    harix = hari;

    //sekarang = hari ke berapa dalam setahun
    int sekarang = tanggal;
    for(int i; i < bulan-1; ++i){
        sekarang += months[i];
    }

    //valid = hari setelah perhitungan
    int valid, skip_tahun=0;
    if(hari <= year-sekarang)//bila masih di tahun yang sama
        valid = sekarang+hari;
    else{//bila sudah beda tahun
        skip_tahun = 1;
        skip_tahun += (hari-(year-sekarang))/year;//pembagian integer
        valid = (hari-(year-sekarang))%year;
    }

    //hitung tanggal dari variabel valid
    bulan = 0;
    for(int i; valid > months[i]; ++i){
        valid -= months[i];
        bulan += 1;
    }

    tahun += skip_tahun;

    //output final
    cout<< "\n\nSetelah "<< harix<< " hari:"<< endl;
    cout<< valid<< " "<< month_name[bulan]<< " "<< tahun;

    return 0;
}
//program ini memiliki kekurangan belum bisa mengatasi tahun kabisat karena udh mepet deadline hehe
