#include <bits/stdc++.h>
#include<limits>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::swap;
using std::numeric_limits;
using std::fixed;
using std::setprecision;
using std::setw;
using std::ifstream;
using std::stringstream;
using std::ofstream;
struct pazymiai
{
    string vardas, pavarde;
    vector <int> pazymys = {};
    double galutinis;
    pazymiai()
    {
        galutinis = 0;
    }
};
int ZodziuKiekis(string str)
{
    stringstream s(str);
    string zodis;
    int wc = 0;
    while (s >> zodis)
        wc++;
    return wc;
}
int main()
{
    ifstream in("kursiokai.txt");
    vector <pazymiai> A;
    int stud = 1, a = 0;
    char MV;
    string eilute, siuksle, nuskaitymas;
    srand(time(NULL));
    cout << "Ar studentus surasysite rankiniu budu? ('taip'/'ne')" << endl;
    bool nuskaitymas2 = false;
    while(1)
    {
        cin >> nuskaitymas;
        if (nuskaitymas == "taip")
        {
            nuskaitymas2 = false;
            break;
        }
        else if(nuskaitymas == "ne")
        {
            nuskaitymas2 = true;
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(500,'\n');
            cout << "KLAIDA. Irasykite 'taip' arba 'ne'" << endl;
        }
    }
    cout << "Jei galutini bala norite skaiciuoti su mediana spauskite 'M', jei vidurkiu 'V'" << endl;
    while (1)
    {
        cin >> MV;
        if (MV == 'M' || MV == 'V')
            break;
        else
        {
            cin.clear();
            cin.ignore(500, '\n');
            cout << "KLAIDA. Irasykite 'M' arba 'V':";
        }
    }
    if (nuskaitymas2 == true)
    {
        getline(in, siuksle);
        while(getline(in, eilute))
        {
            stringstream ss (eilute);
            int zodziai = ZodziuKiekis(eilute) - 3;
            int egzaminas, suma = 0;
            double mediana;
            A.push_back(pazymiai());
            ss >> A[a].vardas >> A[a].pavarde;
            int temp;
            for(int i = 0; i < zodziai; i++)
            {
                ss >> temp;
                suma += temp;
                A[a].pazymys.push_back(temp);
            }
            ss >> egzaminas;
            if(MV == 'V')
                A[a].galutinis = 0.4 * (suma/zodziai) + (0.6 * egzaminas);
            else if(MV == 'M')
            {
                sort(A[a].pazymys.begin(), A[a].pazymys.end());
                if(zodziai % 2 != 0)
                {
                    int k = 0, centras;
                    k = zodziai / 2;
                    centras = zodziai;
                    centras -= k;
                    mediana = A[a].pazymys[centras-1];
                }
                else
                {
                    int k = 0;
                    k = zodziai / 2;
                    mediana = (A[a].pazymys[k-1] + A[a].pazymys[k])/2;
                }
                A[a].galutinis = mediana;
            }
            a++;
            stud = a;
        }
    }
    else
    {
        for (int i = 0; i < stud; i++)
        {
            A.push_back(pazymiai());
            cout << "Iveskite studento varda:" << endl;
            cin >> A[i].vardas;
            for (int j = 0; j < A[i].vardas.size(); j++)
            {
                if (!(isalpha(A[i].vardas[j])))
                {
                    cin.clear();
                    cin.ignore(500, '\n');
                    cout << "KLAIDA. Studento varda privalo sudaryti tik raides. Iveskite studento varda:" << endl;
                    cin >> A[i].vardas;
                    j = 0;
                }
            }
            cout << "Iveskite studento pavarde:" << endl;
            cin >> A[i].pavarde;
            for (int t = 0; t < A[i].pavarde.size(); t++)
            {
                if (!(isalpha(A[i].pavarde[t])))
                {
                    cin.clear();
                    cin.ignore(500, '\n');
                    cout << "KLAIDA. Studento pavarde privalo sudaryti tik raides. Iveskite studento pavarde:" << endl;;
                    cin >> A[i].pavarde;
                    t = 0;
                }
            }
            cout << "Ar norite namu darbu rezultatus sugeneruoti atsitiktinai? ('taip'/'ne')" << endl;
            string klausimas1;
            while (1)
            {
                cin >> klausimas1;
                if (klausimas1 == "taip" || klausimas1 == "ne")
                    break;
                else
                {
                    cin.clear();
                    cin.ignore(500, '\n');
                    cout << "KLAIDA. Irasykite 'taip' arba 'ne'" << endl;
                }
            }
            int ndk = 0;
            double ndr, mediana = 0, suma = 0;
            if (klausimas1 == "ne")
            {
                cout << "Iveskite studento namu darbu rezultatus, po kiekvieno ivesto spauskite 'ENTER', suvede visus pazymius iveskite -1" << endl;
                while (1)
                {
                    cin >> ndr;
                    if (ndr > 10 || ndr < -1)
                    {
                        cout << "KLAIDA. Pazymiai galimi tik desimtbaleje sistemoje. Iveskite studento namu darbu rezultata:" << endl;
                    }
                    else
                    {
                        if (!cin.fail() && ndr <= 10 && ndr >= 1 && ndr == (int)ndr)
                        {
                            A[i].pazymys.push_back(ndr);
                            ndk++;
                            suma += ndr;
                        }
                        else if (ndr != (int)ndr)
                            cout << "KLAIDA. Skaicius turi buti sveikasis. Iveskite studento namu darbu rezultata:" << endl;
                    }
                    if (cin.fail() || ndr == 0)
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "KLAIDA. Rezultatas turi buti skaicius, didenis uz 0. Iveskite studento namu darbu rezultata:" << endl;
                    }
                    if (ndk != 0 && ndr == -1)
                        break;
                }
            }
            else
            {
                cout << "Kiek norite kad studentas turetu pazymiu?" << endl;
                double n;
                while (1)
                {
                    cin >> n;
                    if (!cin.fail() && n > 0 && n == (int)n)
                        break;
                    else
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "KLAIDA. Iveskite studento pazymiu kieki:" << endl;
                    }
                }
                cout << "Sugeneruoti pazymiai:";
                for (int j = 0; j < n; j++)
                {
                    ndk++;
                    A[i].pazymys.push_back(rand()%10+1);
                    cout << A[i].pazymys[j] << " ";
                    suma += A[i].pazymys[j];
                }
                cout << endl;
            }
            cout << "Ar norite sugeneruoti atsitiktini egzamino rezultata? ('taip'/'ne')" << endl;
            string klausimas2;
            while (1)
            {
                cin >> klausimas2;
                if (klausimas2 == "taip" || klausimas2 == "ne")
                    break;
                else
                {
                    cin.clear();
                    cin.ignore(500, '\n');
                    cout << "KLAIDA. Irasykite 'taip' arba 'ne'" << endl;
                }
            }
            double egzaminas;
            if (klausimas2 == "ne")
            {
                cout << "Iveskite studento egzamino rezultata:" << endl;
                while (1)
                {
                    cin >> egzaminas;
                    if (!cin.fail() && egzaminas <= 10 && egzaminas == (int)egzaminas && egzaminas > 0 && egzaminas == (int)egzaminas)
                        break;
                    else
                    {
                        cin.clear();
                        cin.ignore(500, '\n');
                        cout << "KLAIDA. Iveskite studento egzamino rezultata:" << endl;
                    }
                }
            }
            else if (klausimas2 == "taip")
            {
                egzaminas = rand()%10+1;
                cout << "Sugeneruotas egzamino rezultatas:" << egzaminas << endl;
            }
            if(MV == 'V')
                A[i].galutinis = 0.4 * (suma/ndk) + (0.6 * egzaminas);
            else if (MV == 'M')
            {
                sort(A[i].pazymys.begin(), A[i].pazymys.end());
                if (ndk % 2 != 0)
                {
                    int k = 0;
                    k = ndk / 2;
                    ndk -= k;
                    mediana = A[i].pazymys[ndk-1];
                }
                else
                {
                    int k = 0;
                    k = ndk / 2;
                    mediana = (A[i].pazymys[k-1] + A[i].pazymys[k]) / 2;
                }
                A[i].galutinis = mediana;
            }
        cout << "Ar yra daugiau studentu? ('taip'/'ne')" << endl;
        string klausimas3;
        while (1)
        {
            cin >> klausimas3;
            if (klausimas3 == "taip" || klausimas3 == "ne")
                break;
            else
            {
                cin.clear();
                cin.ignore(500, '\n');
                cout << "KLAIDA. Irasykite 'taip' arba 'ne':" << endl;
            }
        }
        if (klausimas3 == "taip")
        {
            stud++;
            ndk = 0;
            suma = 0;
        }
    }
    }
    string rikiavimas;
    cout << "Pagal kokia skilti norite rusiuoti sarasa?('vardus'/'pavardes')" << endl;
    while(1)
    {
        cin >> rikiavimas;
        if (rikiavimas == "vardus" || rikiavimas == "pavardes")
            break;
        else
        {
            cin.clear();
            cin.ignore(500, '\n');
            cout << "KLAIDA. Irasykite pagal ka rikiuosite('vardus' ar 'pavardes')" << endl;
        }
    }
    if (rikiavimas == "vardus")
        sort(A.begin(), A.end(), [](pazymiai a, pazymiai b)
             {
                 return a.vardas < b.vardas;
             });
    else
        sort(A.begin(), A.end(), [](pazymiai a, pazymiai b)
             {
                 return a.pavarde < b.pavarde;
             });
    cout.width(15);
    cout << std::left << "Pavarde";
    cout.width(15);
    cout << std::left << "Vardas";
    cout.width(34);
    cout << std::left << "Galutinis(Vid.) / Galutinis (Med.)" << endl;
    for (int i = 0; i < 64; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < stud; i++)
    {
        if (MV == 'V')
        {
            cout.width(15);
            cout << std::left << A[i].pavarde;
            cout.width(15);
            cout << std::left << A[i].vardas;
            cout << fixed << setprecision(2) << A[i].galutinis << endl;
        }
        else if (MV == 'M')
        {
            cout.width(15);
            cout << std::left << A[i].pavarde;
            cout.width(15);
            cout << std::left << A[i].vardas;
            cout << setw(22);
            cout << std::right << fixed << setprecision(2) << A[i].galutinis << endl;
        }
    }
}