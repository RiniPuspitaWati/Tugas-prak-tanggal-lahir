#include <iostream>
#include <ctime>
using namespace std;

class AgeCalculator {
private:
    int birth_day;
    int birth_month;
    int birth_year;
public:
    AgeCalculator(int day, int month, int year) {
        birth_day = day;
        birth_month = month;
        birth_year = year;
    }

    int getBirthDay() {
        return birth_day;
    }

    void setBirthDay(int day) {
        birth_day = day;
    }

    int getBirthMonth() {
        return birth_month;
    }

    void setBirthMonth(int month) {
        birth_month = month;
    }

    int getBirthYear() {
        return birth_year;
    }

    void setBirthYear(int year) {
        birth_year = year;
    }

    bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
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

    int daysInMonth(int month, int year) {
        if (month == 2) {
            if (isLeapYear(year)) {
                return 29;
            }
            else {
                return 28;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        else {
            return 31;
        }
    }

    void calculateAge() {
        time_t now = time(0);
        tm* local_time = localtime(&now);

        int current_day = local_time->tm_mday;
        int current_month = local_time->tm_mon + 1;
        int current_year = local_time->tm_year + 1900;

        int age_year, age_month, age_day;

        if (birth_month > current_month) {
            age_year = current_year - birth_year - 1;
            age_month = 12 - (birth_month - current_month);
        }
        else {
            age_year = current_year - birth_year;
            age_month = current_month - birth_month;
        }

        if (birth_day > current_day) {
            if (current_month == 1) {
                current_month = 13;
                current_year--;
            }
            age_day = daysInMonth(current_month - 1, current_year) - (birth_day - current_day);
        }
        else {
            age_day = current_day - birth_day;
        }

        cout << "Umur Anda adalah " << age_year << " tahun " << age_month << " bulan " << age_day << " hari" << endl;
    }
};

int main() {
    int birth_day, birth_month, birth_year;
    cout << "Masukkan tanggal, bulan, dan tahun lahir anda: ";
    cin >> birth_day >> birth_month >> birth_year;

    AgeCalculator age(birth_day, birth_month, birth_year);
    age.calculateAge();

    return 0;
}

