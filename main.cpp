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

class Jucator {
private:
    std::string nume;
    int zi_nastere, luna_nastere, an_nastere;
    float OVR;
    Atribute_Mentale mentale;
    Atribute_Fizice fizice;
    Atribute_Tehnice tehnice;
    Alte_Atribute altele;
public:
     explicit Jucator(std::string nume_ = "nume neintrodus", int zi_ = 1, int luna_ = 1, int an_ = 1970, float OVR_val = 0, Atribute_Mentale mentale_v = Atribute_Mentale(), Atribute_Tehnice tehnice_v = Atribute_Tehnice(), Atribute_Fizice fizice_v = Atribute_Fizice(), Alte_Atribute altele_v = Alte_Atribute())
        : nume(std::move(nume_)), zi_nastere(zi_), luna_nastere(luna_), an_nastere(an_), OVR(OVR_val), mentale(mentale_v), fizice(fizice_v), tehnice(tehnice_v), altele(std::move(altele_v)) {
        calculareOVR();
    }

    Jucator(const Jucator &alt_jucator) : nume(alt_jucator.nume), zi_nastere(alt_jucator.zi_nastere), luna_nastere(alt_jucator.luna_nastere), an_nastere(alt_jucator.an_nastere), OVR(alt_jucator.OVR), mentale(alt_jucator.mentale), fizice(alt_jucator.fizice), tehnice(alt_jucator.tehnice), altele(alt_jucator.altele) {
        calculareOVR();
    }
    Jucator& operator=(Jucator&& alt_jucator) noexcept {
        if (this != &alt_jucator) {
            nume = std::move(alt_jucator.nume);
            zi_nastere = alt_jucator.zi_nastere;
            luna_nastere = alt_jucator.luna_nastere;
            an_nastere = alt_jucator.an_nastere;
            OVR = alt_jucator.OVR;
            mentale = alt_jucator.mentale;
            fizice = alt_jucator.fizice;
            tehnice = alt_jucator.tehnice;
            altele = std::move(alt_jucator.altele);
        }
        std::cout << "operator=" << std::endl;
        return *this;
    }

    ~Jucator() {
        std::cout << "" << std::endl;
    }
    void aplicaAntrenament(int intensitate) {
        tehnice.finishing += intensitate;
        fizice.stamina += intensitate;
        calculareOVR();
        std::cout << "Jucatorul " << nume << " s-a antrenat. Noul OVR: " << OVR << std::endl;
    }

    void calculareOVR() {
        if (altele.pozitie == "DF")
            OVR = (static_cast<float>(tehnice.tackling) + static_cast<float>(mentale.marking_and_positioning)) / 2.0f + 0.2f * ((fizice.inaltime + static_cast<float>(fizice.acceleration) + fizice.greutate) / 3.0f);
        else if (altele.pozitie == "MF")
            OVR = (0.3f * static_cast<float>(tehnice.dribbling) + 0.1f * static_cast<float>(tehnice.finishing) + 0.1f * static_cast<float>(tehnice.faze_fixe) + 0.05f * static_cast<float>(tehnice.tackling) + 0.3f * static_cast<float>(mentale.concentrare) + 0.3f * static_cast<float>(mentale.flair) + 0.4f * static_cast<float>(mentale.vission) + 0.2f * static_cast<float>(mentale.work_rate) + 0.1f * static_cast<float>(mentale.marking_and_positioning)) / 1.85f;
        else if (altele.pozitie == "AF")
            OVR = (0.3f * static_cast<float>(tehnice.finishing) + 0.3f * static_cast<float>(tehnice.dribbling) + 0.2f * static_cast<float>(tehnice.faze_fixe) + 0.3f * static_cast<float>(mentale.concentrare) + 0.3f * static_cast<float>(mentale.flair) + 0.2f * static_cast<float>(mentale.vission) + 0.2f * static_cast<float>(fizice.acceleration) + (0.2f * static_cast<float>(fizice.pace) / 2.0f));
    }

    friend std::ostream& operator<<(std::ostream &os, const Jucator &jucator) {
        os << "nume: " << jucator.nume << std::endl;
        os << "data_nasterii: " << jucator.zi_nastere << "/" << jucator.luna_nastere << "/" << jucator.an_nastere << std::endl;
        os << "OVR: " << jucator.OVR << std::endl;
        os <<"atribute fizice: " <<endl;
        os << jucator.fizice << std::endl;
        os << "atribute tehnice: " <<std::endl;
        os << jucator.tehnice << std::endl;
        os << "atribute mentale: " <<std::endl;
        os << jucator.mentale << std::endl;
        os << "alte atribute: " <<std::endl;
        os << jucator.altele << std::endl;
        return os;
    }
};

class Antrenor {
    std::string nume;
    int zi_nastere, luna_nastere, an_nastere;
    std::string rol;
    int OVR;
public:
    explicit Antrenor(std::string nume = "Nume neintrodus", int zi = 1, int luna = 1, int an = 1970, std::string rol = "Rol neintrodus", int OVR = 0)
        : nume(std::move(nume)), zi_nastere(zi), luna_nastere(luna), an_nastere(an), rol(std::move(rol)), OVR(OVR) {
    }
    friend std::ostream& operator<<(std::ostream &os, const Antrenor &antenor) {
        os << "nume: " << antenor.nume << std::endl;
        os << "data nasterii : " << antenor.zi_nastere << "/" << antenor.luna_nastere << "/" << antenor.an_nastere << std::endl;
        os << "rol: " << antenor.rol << std::endl;
        os << "OVR: " << antenor.OVR << std::endl;
        return os;
    }
    [[nodiscard]] int getOVR() const { return OVR; }
    friend class Echipa;
};

class Echipa {
private:
    std::string nume;
    std::vector<Jucator> jucatori;
    std::vector<Antrenor> antrenori;
public:
    explicit Echipa(std::string numele = "nume neintrodus", std::vector<Jucator> jucatori = {}, std::vector<Antrenor> antrenori = {}): nume(std::move(numele)), jucatori(std::move(jucatori)), antrenori(std::move(antrenori)) {
    }
    void calculeazaEficientaStaff() const {
        int suma = 0;
        for (const auto& antrenor : antrenori) {
            suma += antrenor.getOVR();
        }
        if (antrenori.empty()) cout << "Eficienta staff: 0" << endl;
        else cout<<"Eficienta staff: "<<static_cast<float>(suma)/static_cast<float>(antrenori.size())<<std::endl;
    }

    void adaugareJucatori(const Jucator &jucator) {
        jucatori.push_back(jucator);
    }
    void adaugareAntenori(const Antrenor &antenor) {
        antrenori.push_back(antenor);
    }
    friend std::ostream& operator<<(std::ostream &os, const Echipa &echipa) {
        os << "nume: " << echipa.nume << std::endl;
        os << "Lot Jucatori (" << echipa.jucatori.size() << "):\n";
        for (const auto& j : echipa.jucatori) {
            os << "  " << j << "\n";
        }
        os << "Staff Tehnic (" << echipa.antrenori.size() << "):\n";
        for (const auto& a : echipa.antrenori) {
            os << "  " << a << "\n";
        }
        return os;
    }
};

int main() {
    Atribute_Tehnice Palmer2{ 80, 85, 90, 50 };
    Atribute_Mentale Palmer1{ 60, 90, 95, 95, 60 };
    Atribute_Fizice Palmer3{ 80, 85, 70, 50, 1.80f, 65.2f };
    Alte_Atribute Palmer4{ "MF", "Advanced_Playmaker", 96, 70, 27 };
    Jucator Cole_Palmer{ "Cole Palmer", 6, 5, 2002, 0.0f, Palmer1, Palmer2, Palmer3, Palmer4 };

    Atribute_Tehnice James2 { 70, 70, 74, 90 };
    Atribute_Mentale James1{ 80, 65, 88, 80, 85 };
    Atribute_Fizice James3{ 85, 85, 83, 90, 1.80f, 91.0f };
    Alte_Atribute   James4{ "DF", "Wingback", 99, 70, 26 };
    Jucator Reece_James {"Reece James", 8, 12, 1999, 0.0f, James1,James2,James3,James4 };

    Antrenor Liam_Rosenior{ "Liam Rosenior", 9, 7, 1984, "Head Coach", 73 };
    Antrenor Callum_Macfarlane {"Callum Macfarlane", 13, 11, 1985, "Assistant Manager", 65};

    Echipa Chelsea("Chelsea FC");
    Chelsea.adaugareJucatori(Cole_Palmer);
    Chelsea.adaugareJucatori(Reece_James);
    Chelsea.adaugareAntenori(Liam_Rosenior);
    Chelsea.adaugareAntenori(Callum_Macfarlane);

    std::cout << Chelsea << std::endl;
    Cole_Palmer.aplicaAntrenament(80);
    Chelsea.calculeazaEficientaStaff();

    return 0;
}