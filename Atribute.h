#ifndef ATRIBUTE_H
#define ATRIBUTE_H

#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class Atribute_Tehnice {
private:
    int finishing;
    int dribbling;
    int faze_fixe;
    int tackling;
public:
    explicit Atribute_Tehnice(int finishing = 50, int dribbling = 50, int faze_fixe = 50, int tackling = 50)
        : finishing(finishing), dribbling(dribbling), faze_fixe(faze_fixe), tackling(tackling) {
    }
    friend std::ostream& operator<<(std::ostream& os, const Atribute_Tehnice &t) {
        os << "finishing: " << t.finishing << "\n";
        os << "dribbling: " << t.dribbling << "\n";
        os << "faze_fixe: " << t.faze_fixe << "\n";
        os << "tackling: " << t.tackling << "\n";
        return os;
    }
    friend class Jucator;
};

class Atribute_Mentale {
private:
    int concentrare;
    int flair;
    int passing;
    int vission;
    int work_rate;
    int marking_and_positioning;
public:
    explicit Atribute_Mentale(int concentrare = 50, int flair = 50, int passing = 50, int vission = 50, int work_rate = 50, int marking_and_positioning = 50)
        : concentrare(concentrare), flair(flair), passing(passing), vission(vission), work_rate(work_rate), marking_and_positioning(marking_and_positioning) {
    }
    friend std::ostream& operator<<(std::ostream &os, const Atribute_Mentale &t) {
        os << "concentrare:" << t.concentrare << "\n";
        os << "flair:" << t.flair << "\n";
        os << "passing:" << t.passing << "\n";
        os << "vission:" << t.vission << "\n";
        os << "work_rate:" << t.work_rate << "\n";
        os << "marking_and_positioning:" << t.marking_and_positioning << "\n";
        return os;
    }
    friend class Jucator;
};

class Atribute_Fizice {
    int acceleration;
    int pace;
    int natural_fitness;
    int stamina;
    float inaltime;
    float greutate;
public:
    explicit Atribute_Fizice(int acceleration = 50, int pace = 50, int natural_fitness = 50, int stamina = 50, float inaltime = 50, float greutate = 50)
        : acceleration(acceleration), pace(pace), natural_fitness(natural_fitness), stamina(stamina), inaltime(inaltime), greutate(greutate) {
    }
    friend std::ostream& operator<<(std::ostream &os, const Atribute_Fizice &t) {
        os << "acceleration:" << t.acceleration << "\n";
        os << "pace:" << t.pace << "\n";
        os << "natural_fitness:" << t.natural_fitness << "\n";
        os << "stamina:" << t.stamina << "\n";
        os << "inaltime:" << t.inaltime << "\n";
        os << "greutate:" << t.greutate << "\n";
        return os;
    }
    friend class Jucator;
};

class Alte_Atribute {
    std::string pozitie;
    std::string rol;
    int Max_Potential;
    int Min_Potential;
    int peak_age;
public:
    explicit Alte_Atribute(std::string pozitie = "nedeterminat", std::string rol = "nedeterminat", int Max_Potential = 99, int Min_Potential = 60, int peak_age = 28)
        : pozitie(std::move(pozitie)), rol(std::move(rol)), Max_Potential(Max_Potential), Min_Potential(Min_Potential), peak_age(peak_age) {
    }
    friend std::ostream& operator<<(std::ostream &os, const Alte_Atribute &t) {
        os << "Max_Potential:" << t.Max_Potential << "\n";
        os << "Min_Potential:" << t.Min_Potential << "\n";
        os << "peak_age:" << t.peak_age << "\n";
        return os;
    }
    friend class Jucator;
};

#endif