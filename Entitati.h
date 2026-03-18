#ifndef ENTITATI_H
#define ENTITATI_H

#include "Jucator.h"

class Antrenor {
    std::string nume;
    int zi_nastere, luna_nastere, an_nastere;
    std::string rol;
    float OVR;
public:
    explicit Antrenor(std::string nume = "Nume neintrodus", int zi = 1, int luna = 1, int an = 1970, std::string rol = "Rol neintrodus", float OVR = 0.0f)
        : nume(std::move(nume)), zi_nastere(zi), luna_nastere(luna), an_nastere(an), rol(std::move(rol)), OVR(OVR) {
    }
    friend std::ostream& operator<<(std::ostream &os, const Antrenor &antenor) {
        os << "nume: " << antenor.nume << std::endl;
        os << "data nasterii : " << antenor.zi_nastere << "/" << antenor.luna_nastere << "/" << antenor.an_nastere << std::endl;
        os << "rol: " << antenor.rol << std::endl;
        os << "OVR: " << antenor.OVR << std::endl;
        return os;
    }
    [[nodiscard]] float getOVR() const { return OVR; }
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
        float suma = 0;
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
        os <<  echipa.nume << std::endl;
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
    [[nodiscard]] float getMedieOVR() const {
        float sumaAntrenori = 0;
        float sumaJucatori = 0;
        for (const auto& antenor : antrenori) {
            sumaAntrenori += antenor.getOVR();
        }
        for (const auto& j : jucatori) {
            sumaJucatori += j.getOVR();
        }
        return (sumaAntrenori * 1.0f + sumaJucatori * 2.0f) / 3.0f;
    }
    [[nodiscard]] std::string getNume () const{ return nume; }
    friend class Campionat;
};

class Meci {
    Echipa echipa1;
    Echipa echipa2;
    int goluri_echipa1, goluri_echipa2;
    public:
    explicit Meci(Echipa echipa1_ = Echipa(),  Echipa echipa2_ = Echipa(), int goluri_echipa1_ = 0, int goluri_echipa2_ = 0): echipa1(std::move (echipa1_)), echipa2(std::move(echipa2_)), goluri_echipa1(goluri_echipa1_), goluri_echipa2(goluri_echipa2_) {
    }

    void simuleazaMeci() {
        float rating1 = echipa1.getMedieOVR();
        float rating2 = echipa2.getMedieOVR();

        if (rating1 > rating2 + 5.0f) {
            goluri_echipa1 = 2; goluri_echipa2 = 0;
        } else if (rating2 > rating1 + 5.0f) {
            goluri_echipa1 = 0; goluri_echipa2 = 2;
        } else {
            goluri_echipa1 = 1; goluri_echipa2 = 1;
        }
    }

    friend std::ostream& operator<<(std::ostream &os, const Meci &meci) {
        os << meci.echipa1.getNume() << meci.goluri_echipa1 << " - " << meci.goluri_echipa2<< meci.echipa2.getNume()<<::endl;
        return os;
    }
};

class Etapa {
    std::vector<Meci> meciuri;
    public:
    explicit Etapa(std::vector <Meci> meciuri_ = {}) :meciuri(std::move(meciuri_)) {
    }
    void adaugaMeci(const Meci &m) {
        meciuri.push_back(m);
    }
    friend std::ostream& operator<<(std::ostream &os, const Etapa &etapa) {
        for (unsigned long long i=0; i<etapa.meciuri.size(); i++) {
            os << "Etapa "<<i+1<<endl;
            os<<  etapa.meciuri[i] << endl;
        }
        return os;
    }
};

class Campionat {
    std::string nume;
    std::vector<Echipa> echipe;
    std::vector<Etapa> etape;

public:
    explicit Campionat(std::string numele = "nume", std::vector<Echipa> echipele = {}, std::vector<Etapa> etape = {}) : nume(std::move(numele)), echipe(std::move(echipele)), etape(std::move(etape)) {
    }
    friend std::ostream& operator<<(std::ostream &os, const Campionat &campionat) {
        os << "nume: " << campionat.nume << std::endl;
        os << "clasare: "<<endl;
        for (unsigned long long i = 0; i < campionat.echipe.size(); i++) {
            os<< i + 1 <<"."<<campionat.echipe[i] << " ";
        }
        for (const auto& etapa_ : campionat.etape) {
            os<< etapa_ << " ";
        }
        return os;
    }
    void adaugaEchipe(const Echipa &echipa) {
        echipe.push_back(echipa);
    }
    void adaugaEtapa(const Etapa &etapa) {
        etape.push_back(etapa);
    }
};

#endif