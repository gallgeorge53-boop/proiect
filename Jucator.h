#ifndef JUCATOR_H
#define JUCATOR_H

#include "Atribute.h"

class Jucator {
private:
    std::string nume;
    int zi_nastere, luna_nastere, an_nastere;
    float OVR;
    Atribute_Mentale mentale;
    Atribute_Fizice fizice;
    Atribute_Tehnice tehnice;
    Alte_Atribute altele;

    void calculareOVR() {
        if (altele.pozitie == "DF")
            OVR = (static_cast<float>(tehnice.tackling) + static_cast<float>(mentale.marking_and_positioning)) / 2.0f + 0.2f * ((fizice.inaltime + static_cast<float>(fizice.acceleration) + fizice.greutate) / 3.0f);
        else if (altele.pozitie == "MF")
            OVR = (0.3f * static_cast<float>(tehnice.dribbling) + 0.1f * static_cast<float>(tehnice.finishing) + 0.1f * static_cast<float>(tehnice.faze_fixe) + 0.05f * static_cast<float>(tehnice.tackling) + 0.3f * static_cast<float>(mentale.concentrare) + 0.3f * static_cast<float>(mentale.flair) + 0.4f * static_cast<float>(mentale.vission) + 0.2f * static_cast<float>(mentale.work_rate) + 0.1f * static_cast<float>(mentale.marking_and_positioning)) / 1.85f;
        else if (altele.pozitie == "AF")
            OVR = (0.3f * static_cast<float>(tehnice.finishing) + 0.3f * static_cast<float>(tehnice.dribbling) + 0.2f * static_cast<float>(tehnice.faze_fixe) + 0.3f * static_cast<float>(mentale.concentrare) + 0.3f * static_cast<float>(mentale.flair) + 0.2f * static_cast<float>(mentale.vission) + 0.2f * static_cast<float>(fizice.acceleration) + (0.2f * static_cast<float>(fizice.pace) / 2.0f));
    }
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
    friend class Echipa;
    [[nodiscard]] float getOVR() const { return OVR;}
};

#endif