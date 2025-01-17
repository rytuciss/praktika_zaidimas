#ifndef ZAIDEJODUOMENYS_H
#define ZAIDEJODUOMENYS_H

using namespace std;

bool zaidejasSukurtas = false;

//saugo zaideju duomenis, yra 5 saugojimo vietos tam jeigu to pacio proceso metu bandys zaisti su visais uzsaugotais veikejais
struct zaidDuom {
    string vardas = "-";
    int sunkumas = 0; //1, 2, 3
    int hp = 100;
    int def = 0;
    int atk = 0;
    int shield = 0;
    int xp = 0; 
    int lvl = 0; 
    int gold = 500;
    int maistas = 19;
} zaidDuom[5];
//esant tam tikram lygiui sie bonusai prisides prie pagrindiniu zaidejo duomenu
struct lygis {
    int pliusPuolimas = 0;
    int pliusGyvybe = 0;
} lygis;
//efektai duomenims judant zemelapiu, krenta maistas, dideja patirtis
void zaidejoDuomenys(int nr, bool naujinti) {
    if (naujinti == true) {
        zaidDuom[nr].xp += 5;
        if (zaidDuom[nr].maistas > 0) zaidDuom[nr].maistas -= 2;
        if (zaidDuom[nr].maistas <= 0) {
            cout << "JUMS BAIGESI MAISTAS, PO MAZU PRARANDATE GYVYBES!\n\n";
            zaidDuom[nr].maistas = 0;
            zaidDuom[nr].hp -= 2;
        }
        else if (zaidDuom[nr].hp < (100 + lygis.pliusGyvybe)) {
            zaidDuom[nr].maistas -= 1;
            zaidDuom[nr].hp += 2;
            if (zaidDuom[nr].hp > (100 + lygis.pliusGyvybe)) zaidDuom[nr].hp = 100 + lygis.pliusGyvybe;
        }
    }
}
//judant zemelapiu spausdina reguliariai duomenis, kad matytu patirties ar maisto pokyti
void zaidejoDuomenuSpausdinimas(int nr) {
    cout << "GYVYBE: " << zaidDuom[nr].hp + lygis.pliusGyvybe <<
            "\nSARVAI: " << zaidDuom[nr].def <<
            "\nPUOLIMAS: " << zaidDuom[nr].atk + lygis.pliusPuolimas <<
            "\nGYNYBA: " << zaidDuom[nr].shield <<
            "\nLYGIS: " << zaidDuom[nr].lvl <<
            "\nXP: " << zaidDuom[nr].xp <<
            "\nAUKSAS: " << zaidDuom[nr].gold <<
            "\nMAISTAS: " << zaidDuom[nr].maistas;
}
//pasikelus lygi pasirenkame bonusus duomenims
void pasirinktiSavybe(int nr) {
    int pasirinkti;
    cout << "\n\nPASIKELETE " << zaidDuom[nr].lvl << "-AJI LYGI!"
            "\n1. PUOLIMAS +10."
            "\n2. GYVYBE +10."
            "\n\nPASIRINKITE NAUJA ZAIDEJO SAVYBE: ";
    cin >> pasirinkti;
    switch (pasirinkti) {
        case 1: {
            lygis.pliusPuolimas = lygis.pliusPuolimas + 10;
            break;
        }
        case 2: {
            lygis.pliusGyvybe = lygis.pliusGyvybe + 10;
            break;
        }
        default: {
            cout << "\nSIS MENU PUNKTAS NEEGZISTUOJA, PASIRINKITE IS NAUJO!\n";
            break;
        }
    }
}
//tikrina pagal patirties kieki ar pasieke nauja lygi
void pasikeleLygi(int nr) {
    if (zaidDuom[nr].xp >= 1000 && zaidDuom[nr].lvl < 1) {
        zaidDuom[nr].lvl = 1;
        pasirinktiSavybe(nr);
    }
    else if (zaidDuom[nr].xp >= 2500 && zaidDuom[nr].lvl < 2) {
        zaidDuom[nr].lvl = 2;   
        pasirinktiSavybe(nr);
    }
    else if (zaidDuom[nr].xp >= 5000 && zaidDuom[nr].lvl < 3) {
        zaidDuom[nr].lvl = 3;
        pasirinktiSavybe(nr);
    }
}

#endif