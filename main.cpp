#include "Entitati.h"
#include "include/Example.h"

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
    Jucator Reece_James {"Reece James", 8, 12, 1999, 0.0f, James1, James2, James3, James4 };

    Echipa Chelsea("Chelsea FC");
    Chelsea.adaugareJucatori(Cole_Palmer);
    Chelsea.adaugareJucatori(Reece_James);

    Atribute_Tehnice SakaT{ 85, 88, 80, 45 };
    Atribute_Mentale SakaM{ 82, 85, 80, 84, 80 };
    Atribute_Fizice SakaF{ 92, 90, 85, 85, 1.78f, 72.0f };
    Alte_Atribute SakaA{ "AF", "Inverted Winger", 95, 80, 26 };
    Jucator Bukayo_Saka{ "Bukayo Saka", 5, 9, 2001, 0.0f, SakaM, SakaT, SakaF, SakaA };

    Atribute_Tehnice OdeT{ 75, 85, 95, 55 };
    Atribute_Mentale OdeM{ 92, 85, 96, 98, 88 };
    Atribute_Fizice OdeF{ 78, 76, 88, 92, 1.78f, 68.0f };
    Alte_Atribute OdeA{ "MF", "Playmaker", 94, 85, 28 };
    Jucator Martin_Odegaard{ "Martin Odegaard", 17, 12, 1998, 0.0f, OdeM, OdeT, OdeF, OdeA };

    Antrenor Mikel_Arteta{ "Mikel Arteta", 26, 3, 1982, "Head Coach", 86 };

    Echipa Arsenal("Arsenal FC");
    Arsenal.adaugareJucatori(Bukayo_Saka);
    Arsenal.adaugareJucatori(Martin_Odegaard);
    Arsenal.adaugareAntenori(Mikel_Arteta);

    Meci derby(Chelsea, Arsenal);
    derby.simuleazaMeci();

    Etapa etapa1;
    etapa1.adaugaMeci(derby);

    Campionat PremierLeague("Premier League");
    PremierLeague.adaugaEchipe(Chelsea);
    PremierLeague.adaugaEchipe(Arsenal);
    PremierLeague.adaugaEtapa(etapa1);

    operator<<(operator<<(std::cout, PremierLeague), etapa1);


    Chelsea.calculeazaEficientaStaff();
    Arsenal.calculeazaEficientaStaff();
    Cole_Palmer.aplicaAntrenament(80);
    Chelsea.genereazaRaportPerformanta();
    derby.genereazaCronicaDetaliata();
    PremierLeague.analizeazaCompetitivitatea(70.0f);
    Example obiect;
    obiect.g();
    return 0;
}