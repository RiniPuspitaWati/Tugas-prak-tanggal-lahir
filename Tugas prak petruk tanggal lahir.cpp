#include <iostream>
#include <ctime>
using namespace std;

class KalkulatorUmur {
private:
    int tanggal_lahir;
    int bulan_lahir;
    int tahun_lahir;
public:
    KalkulatorUmur(int tanggal, int bulan, int tahun) {
        tanggal_lahir = tanggal;
        bulan_lahir = bulan;
        tahun_lahir = tahun;
    }

    int getTanggalLahir() {
        return tanggal_lahir;
    }

    void setTanggalLahir(int tanggal) {
        tanggal_lahir = tanggal;
    }

    int getBulanLahir() {
        return bulan_lahir;
    }

    void setBulanLahir(int bulan) {
        bulan_lahir = bulan;
    }

    int getTahunLahir() {
        return tahun_lahir;
    }

    void setTahunLahir(int tahun) {
        tahun_lahir = tahun;
    }

    bool isTahunKabisat(int tahun) {
        if (tahun % 4 == 0) {
            if (tahun % 100 == 0) {
                if (tahun % 400 == 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }

    int jumlahHariDalamBulan(int bulan, int tahun) {
        if (bulan == 2) {
            if (isTahunKabisat(tahun)) {
                return 29;
            }
            else {
                return 28;
            }
        }
        else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }

    void hitungUmur() {
        time_t sekarang = time(0);
        tm* waktu_lokal = localtime(&sekarang);

        int hari_ini = waktu_lokal->tm_mday;
        int bulan_ini = waktu_lokal->tm_mon + 1;
        int tahun_ini = waktu_lokal->tm_year + 1900;

        int umur_tahun, umur_bulan, umur_hari;

        if (bulan_lahir > bulan_ini) {
            umur_tahun = tahun_ini - tahun_lahir - 1;
            umur_bulan = 12 - (bulan_lahir - bulan_ini);
        }
        else {
            umur_tahun = tahun_ini - tahun_lahir;
            umur_bulan = bulan_ini - bulan_lahir;
        }

        if (tanggal_lahir > hari_ini) {
            if (bulan_ini == 1) {
                bulan_ini = 13;
                tahun_ini--;
            }
            umur_hari = jumlahHariDalamBulan(bulan_ini - 1, tahun_ini) - (tanggal_lahir - hari_ini);
        }
        else {
            umur_hari = hari_ini - tanggal_lahir;
        }

        cout << "Umur Anda adalah " << umur_tahun << " tahun " << umur_bulan << " bulan " << umur_hari << " hari" << endl;
    }
};

int main() {
    int tanggal_lahir, bulan_lahir, tahun_lahir;
    cout << "Masukkan tanggal, bulan, dan tahun lahir Anda: ";
    cin >> tanggal_lahir >> bulan_lahir >> tahun_lahir;

    KalkulatorUmur kalkulator_umur(tanggal_lahir, bulan_lahir, tahun_lahir);
    kalkulator_umur.hitungUmur();
  
    return 0;
}






