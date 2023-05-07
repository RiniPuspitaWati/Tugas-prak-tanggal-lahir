#include <iostream>
#include <ctime>

template<typename T>
class KalkulatorUmur {
private:
    T tanggal_lahir;
    T bulan_lahir;
    T tahun_lahir;
public:
    KalkulatorUmur(T tanggal, T bulan, T tahun) {
        tanggal_lahir = tanggal;
        bulan_lahir = bulan;
        tahun_lahir = tahun;
    }

    T getTanggalLahir() {
        return tanggal_lahir;
    }

    void setTanggalLahir(T tanggal) {
        tanggal_lahir = tanggal;
    }

    T getBulanLahir() {
        return bulan_lahir;
    }

    void setBulanLahir(T bulan) {
        bulan_lahir = bulan;
    }

    T getTahunLahir() {
        return tahun_lahir;
    }

    void setTahunLahir(T tahun) {
        tahun_lahir = tahun;
    }

    bool isTahunKabisat(T tahun) {
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

    T jumlahHariDalamBulan(T bulan, T tahun) {
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

        T tanggal_sekarang = waktu_lokal->tm_mday;
        T bulan_sekarang = waktu_lokal->tm_mon + 1;
        T tahun_sekarang = waktu_lokal->tm_year + 1900;

        T umur_tahun, umur_bulan, umur_hari;

        if (bulan_lahir > bulan_sekarang) {
            umur_tahun = tahun_sekarang - tahun_lahir - 1;
            umur_bulan = 12 - (bulan_lahir - bulan_sekarang);
        }
        else {
            umur_tahun = tahun_sekarang - tahun_lahir;
            umur_bulan = bulan_sekarang - bulan_lahir;
        }

        if (tanggal_lahir > tanggal_sekarang) {
            if (bulan_sekarang == 1) {
                bulan_sekarang = 13;
                tahun_sekarang--;
            }
            umur_hari = jumlahHariDalamBulan(bulan_sekarang - 1, tahun_sekarang) - (tanggal_lahir - tanggal_sekarang);
        }
        else {
            umur_hari = tanggal_sekarang - tanggal_lahir;
        }

        std::cout << "Umur Anda adalah " << umur_tahun << " tahun " << umur_bulan << " bulan " << umur_hari << " hari" << std::endl;
    }
};

int main() {
    int tanggal_lahir, bulan_lahir, tahun_lahir;
    std::cout << "Masukkan tanggal, bulan, dan tahun lahir anda: ";
    std::cin >> tanggal_lahir >> bulan_lahir >> tahun_lahir;

    KalkulatorUmur<int>kalkulator_umur(tanggal_lahir, bulan_lahir, tahun_lahir);
    kalkulator_umur.hitungUmur();
    
    return 0;
}
