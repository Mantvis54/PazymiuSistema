#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int MAX_STUDENTS = 100;
    const int MAX_GRADES = 10;

    string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS][MAX_GRADES];
    int gradeCounts[MAX_STUDENTS] = {0};
    int studentCount = 0;

    int choice;

    while (true)
    {
        cout << "\n====================================\n";
        cout << "      MOKINIU PAZYMIU SISTEMA       \n";
        cout << "====================================\n";
        cout << "1. Ivesti mokinio varda ir pazymius\n";
        cout << "2. Perziureti pazymius\n";
        cout << "3. Atnaujinti konkretu pazymi\n";
        cout << "4. Pasalinti mokini is saraso\n";
        cout << "5. Iseiti\n";
        cout << "====================================\n";
        cout << "Pasirinkite veiksma: ";
        cin >> choice;

        if (choice == 1)
        {
            if (studentCount >= MAX_STUDENTS)
            {
                cout << "Klaida: Pasiektas maksimalus mokiniu skaicius (100).\n";
                continue;
            }

            cout << "Iveskite mokinio varda: ";
            cin >> ws;
            getline(cin, names[studentCount]);

            int count;
            cout << "Kiek pazymiu norite ivesti? (maksimaliai 10): ";
            cin >> count;

            if (count < 0)
                count = 0;
            if (count > MAX_GRADES)
            {
                cout << "Galima ivesti tik iki 10 pazymiu. Bus ivesta 10.\n";
                count = MAX_GRADES;
            }

            gradeCounts[studentCount] = count;
            for (int i = 0; i < count; i++)
            {
                cout << "Iveskite " << i + 1 << "-aji pazymi: ";
                cin >> grades[studentCount][i];
            }

            studentCount++;
            cout << "Mokinys ir pazymiai sekmingai prideti!\n";
        }
        else if (choice == 2)
        {
            if (studentCount == 0)
            {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            int viewChoice;
            cout << "1. Rodyti visu mokiniu pazymius\n";
            cout << "2. Rodyti konkretaus mokinio pazymius\n";
            cout << "Pasirinkite: ";
            cin >> viewChoice;

            if (viewChoice == 1)
            {
                for (int i = 0; i < studentCount; i++)
                {
                    cout << i + 1 << ". " << names[i] << " - Pazymiai: ";
                    if (gradeCounts[i] == 0)
                        cout << "Nera";
                    for (int j = 0; j < gradeCounts[i]; j++)
                    {
                        cout << grades[i][j] << " ";
                    }
                    cout << "\n";
                }
            }
            else if (viewChoice == 2)
            {
                for (int i = 0; i < studentCount; i++)
                    cout << i + 1 << ". " << names[i] << "\n";
                int studentIndex;
                cout << "Iveskite mokinio numeri (1 - " << studentCount << "): ";
                cin >> studentIndex;
                studentIndex--;

                if (studentIndex >= 0 && studentIndex < studentCount)
                {
                    cout << names[studentIndex] << " pazymiai: ";
                    if (gradeCounts[studentIndex] == 0)
                        cout << "Nera";
                    for (int j = 0; j < gradeCounts[studentIndex]; j++)
                    {
                        cout << grades[studentIndex][j] << " ";
                    }
                    cout << "\n";
                }
                else
                {
                    cout << "Klaida: Tokio mokinio nera.\n";
                }
            }
        }
        else if (choice == 3)
        {
            if (studentCount == 0)
            {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            for (int i = 0; i < studentCount; i++)
                cout << i + 1 << ". " << names[i] << "\n";
            int studentIndex;
            cout << "Kuriam mokiniui norite atnaujinti pazymi? (Iveskite numeri): ";
            cin >> studentIndex;
            studentIndex--;

            if (studentIndex >= 0 && studentIndex < studentCount)
            {
                if (gradeCounts[studentIndex] == 0)
                {
                    cout << "Sis mokinys dar neturi pazymiu.\n";
                    continue;
                }

                cout << names[studentIndex] << " dabartiniai pazymiai: \n";
                for (int j = 0; j < gradeCounts[studentIndex]; j++)
                {
                    cout << j + 1 << "-as pazymis: " << grades[studentIndex][j] << "\n";
                }

                int gradeIndex;
                cout << "Kuri pazymi norite pakeisti? (Iveskite eiles numeri): ";
                cin >> gradeIndex;
                gradeIndex--;

                if (gradeIndex >= 0 && gradeIndex < gradeCounts[studentIndex])
                {
                    cout << "Iveskite nauja pazymi: ";
                    cin >> grades[studentIndex][gradeIndex];
                    cout << "Pazymis sekmingai atnaujintas!\n";
                }
                else
                {
                    cout << "Klaida: Neteisingas pazymio numeris.\n";
                }
            }
            else
            {
                cout << "Klaida: Tokio mokinio nera.\n";
            }
        }
        else if (choice == 4)
        {
            if (studentCount == 0)
            {
                cout << "Mokiniu sarasas tuscias.\n";
                continue;
            }

            for (int i = 0; i < studentCount; i++)
                cout << i + 1 << ". " << names[i] << "\n";
            int deleteIndex;
            cout << "Kuri mokini norite pasalinti? (Iveskite numeri): ";
            cin >> deleteIndex;
            deleteIndex--;

            if (deleteIndex >= 0 && deleteIndex < studentCount)
            {
                for (int i = deleteIndex; i < studentCount - 1; i++)
                {
                    names[i] = names[i + 1];
                    gradeCounts[i] = gradeCounts[i + 1];
                    for (int j = 0; j < MAX_GRADES; j++)
                    {
                        grades[i][j] = grades[i + 1][j];
                    }
                }
                studentCount--;
                cout << "Mokinys sekmingai pasalintas!\n";
            }
            else
            {
                cout << "Klaida: Tokio mokinio nera.\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Programa baigia darba.\n";
            break;
        }
        else
        {
            cout << "Neteisingas pasirinkimas. Bandykite dar karta.\n";
        }
    }

    return 0;
}