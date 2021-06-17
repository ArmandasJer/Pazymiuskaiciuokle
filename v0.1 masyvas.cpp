#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
struct pazymiai
{
    string vardas, pavarde;
    double pazymys;
    char MV;
    double galutinis;
    pazymiai()
    {
        galutinis = 0;
    }
};
void Rykiuoti(pazymiai M[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (M[i].pazymys > M[j].pazymys)
                swap(M[i], M[j]);
}
int main()
{
    pazymiai A[100];
    int stud = 1;
    srand(time(NULL));
    for (int i = 0; i < stud; i++)
    {
        cout << "Iveskite studento varda:" << endl;
        cin >> A[i].vardas;
        for (int j = 0; j < A[i].vardas.size(); j++)
        {
            if (!(isalpha(A[i].vardas[j])))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "KLAIDA. Irasykite 'taip' arba 'ne'" << endl;
            }
        }
        int ndk = 0;
        double suma = 0;
        double ndr;
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
                        A[ndk].pazymys = ndr;
                        ndk++;
                        suma += ndr;
                    }
                    else if (ndr != (int)ndr)
                        cout << "KLAIDA. Skaicius turi buti sveikasis. Iveskite studento namu darbu rezultata:" << endl;
                }
                if (cin.fail() || ndr == 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "KLAIDA. Iveskite studento pazymiu kieki:" << endl;
                }
            }
            cout << "Sugeneruoti pazymiai:";
            for (int j = 0; j < n; j++)
            {
                ndk++;
                A[j].pazymys = rand() % 10 + 1;
                cout << A[j].pazymys << " ";
                suma += A[j].pazymys;
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "KLAIDA. Irasykite 'taip' arba 'ne': " << endl;
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
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "KLAIDA. Iveskite studento egzamino rezultata:" << endl;
                }
            }
        }
        else if (klausimas2 == "taip")
        {
            egzaminas = rand() % 10 + 1;
            cout << "Sugeneruotas egzamino rezultatas:" << egzaminas << endl;
        }
            
        double mediana = 0;
        cout << "Jei galutini bala norite skaiciuoti su mediana spauskite 'M', jei vidurkiu 'V'" << endl;
        while (1)
        {
            cin >> A[i].MV;
            if (A[i].MV == 'M' || A[i].MV == 'V')
                break;
            else 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "KLAIDA. Irasykite 'M' arba 'V':";
            }
        }
        if (A[i].MV == 'V')
            A[i].galutinis = 0.4 * (suma / ndk) + (0.6 * egzaminas);
        else if (A[i].MV == 'M')
        {
            Rykiuoti(A, ndk);
            if (ndk % 2 != 0)
            {
                int k = 0;
                k = ndk / 2;
                ndk -= k;
                mediana = A[ndk - 1].pazymys;
            }
            else
            {
                int k = 0;
                k = ndk / 2;
                mediana = (A[k - 1].pazymys + A[k].pazymys) / 2;
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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "KLAIDA. Irasykite 'taip' arba 'ne': " << endl;
            }
        }
        if (klausimas3 == "taip")
        {
            stud++;
            ndk = 0;
            suma = 0;
        }
    }
    cout.width(15);
    cout << left << "Pavarde";
    cout.width(15);
    cout << left << "Vardas";
    cout.width(34);
    cout << left << "Galutinis(Vid.) / Galutinis (Med.)" << endl;
    for (int i = 0; i < 64; i++)
        cout << "-";
    cout << endl;
    for (int i = 0; i < stud; i++)
    {
        if (A[i].MV == 'V') 
        {
            cout.width(15);
            cout << left << A[i].pavarde;
            cout.width(15);
            cout << left << A[i].vardas;
            cout << fixed << setprecision(2) << A[i].galutinis << endl;
        }
        else if (A[i].MV == 'M')
        {
            cout.width(15);
            cout << left << A[i].pavarde;
            cout.width(15);
            cout << left << A[i].vardas;
            cout << setw(22);
            cout << right << fixed << setprecision(2) << A[i].galutinis << endl;
        }
    }
}