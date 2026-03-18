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
    void genereazaRaportPerformanta() const {
        if (jucatori.empty()) {
            std::cout << "Nu exista date pentru raport.\n";
            return;
        }
        float sumaFizic = 0, sumaTehnic = 0, sumaMental = 0;
        int nrAF = 0, nrDF = 0;
        for (const auto& j : jucatori) {
            sumaFizic += (static_cast<float>(j.fizice.acceleration) + static_cast<float>(j.fizice.pace) + static_cast<float>(j.fizice.stamina)) / 3.0f;
            sumaTehnic += (static_cast<float>(j.tehnice.finishing) + static_cast<float>(j.tehnice.dribbling) + static_cast<float>(j.tehnice.tackling)) / 3.0f;
            sumaMental += (static_cast<float>(j.mentale.concentrare) + static_cast<float>(j.mentale.passing) + static_cast<float>(j.mentale.vission)) / 3.0f;
            if (j.altele.pozitie == "AF") nrAF++;
            if (j.altele.pozitie == "DF") nrDF++;
        }
        float medieF = sumaFizic / static_cast<float>(jucatori.size());
        float medieT = sumaTehnic / static_cast<float>(jucatori.size());
        float medieM = sumaMental / static_cast<float>(jucatori.size());
        std::cout << "--- RAPORT TACTIC: " << nume << " ---\n";
        std::cout << "Echilibru Linii: " << (nrAF > nrDF ? "Ofensiv" : (nrDF > nrAF ? "Defensiv" : "Echilibrat")) << "\n";
        if (medieF > 80 && medieT < 60) std::cout << "Sugestie: Echipa bazata pe contraatac (Viteza > Tehnica).\n";
        else if (medieT > 80 && medieM > 75) std::cout << "Sugestie: Stil Tiki-Taka (Tehnica si Viziune ridicata).\n";
        else std::cout << "Sugestie: Stil de joc Standard.\n";
        if (medieM < 50) std::cout << "ATENTIE: Nivel scazut de concentrare! Risc de goluri in ultimele minute.\n";
    }

    friend class Campionat;
    friend class Meci;
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
    void genereazaCronicaDetaliata() {
        simuleazaMeci();
        std::cout << "=== CRONICA MECIULUI: " << echipa1.getNume() << " vs " << echipa2.getNume() << " ===\n";
        float diff = echipa1.getMedieOVR() - echipa2.getMedieOVR();
        if (goluri_echipa1 > goluri_echipa2) {
            std::cout << "Dominare totala de la " << echipa1.getNume() << ". ";
            if (diff > 10) std::cout << "Diferenta de valoare a fost colosala pe teren.\n";
            else std::cout << "Victorie muncita, decisa la detalii tactice.\n";
        } else if (goluri_echipa1 < goluri_echipa2) {
            std::cout << "Surpriza pe tabela! " << echipa2.getNume() << " a controlat ritmul.\n";
        } else {
            std::cout << "Meci de sah! Ambele echipe s-au anulat reciproc la mijlocul terenului.\n";
        }
        if (diff < 2 && diff > -2) {
            std::cout << "Moment cheie: Bara in minutul 85 a impiedicat victoria uneia dintre echipe.\n";
        }
    }
    friend class Etapa;
    friend class Campionat;
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
    void analizeazaCompetitivitatea(float pragOVR) const {
        std::cout << "Analiza echipelor cu OVR peste " << pragOVR << ":\n";
        bool gasit = false;
        int contor = 0;
        float sumaOvrTotal = 0;
        for (const auto& echipa : echipe) {
            float ovrCurent = echipa.getMedieOVR();
            sumaOvrTotal += ovrCurent;
            if (ovrCurent >= pragOVR) {
                std::cout << " - " << echipa.getNume() << " (OVR Mediu: " << ovrCurent << ")\n";
                gasit = true;
                contor++;
            }
        }
        if (!gasit) std::cout << "Nicio echipa nu atinge acest prag de profesionalism.\n";
        else {
            float mediaLigii = sumaOvrTotal / static_cast<float>(echipe.size());
            std::cout << "In total " << contor << " echipe de elita dintr-un total de " << echipe.size() << ".\n";
            std::cout << "Media generala a competitiei: " << mediaLigii << "\n";
        }
    }
};

#endif