#include "afficheur.h"

using std::cin;
using std::cout;
using std::endl;

afficheur::afficheur() : _pbm{1}, _setup{}, _algo{_pbm, _setup}
{
    srand(time(NULL));
}

afficheur::~afficheur()
{}

void afficheur::init()
{
    int choix = 0;
    while(choix != 3)
    {
        system("cls");

        afficher_pbm();
        afficher_menu_principal();

        cin >> choix;

        switch (choix)
        {
            case 1:
                start_resolution();
                break;
            case 2:
                afficher_menu_eddit();
                break;
            default:
                break;
        }
    }
}

void afficheur::afficher_pbm()
{
    cout << "Probleme courant :" << endl << endl;
    cout << _pbm << endl;
    cout << _setup << endl;
}

void afficheur::afficher_menu_principal()
{
    cout << "(1) Lancer la resolution" << endl;
    cout << "(2) Modifier les parametres" << endl;
    cout << "(3) Quitter" << endl;
}

void afficheur::start_resolution()
{
    system("cls");

    _algo.initialize();
    cout << _pbm.get_nom_pbm() << ", premiere solution : " << endl;
    _algo.afficher_best();

    cout << "0                                                                                               100%" << endl;
    _algo.evolution();

    cout << endl << endl << "meilleure solution : " << endl;
    _algo.afficher_best();

    cout << "(1) Quitter" << endl;
    int choix = 0;
    while(choix != 1)
    {
        cin >> choix;
        switch (choix)
        {
            case 1:
                break;
            default:
                break;
        }
    }
}

void afficheur::afficher_menu_eddit()
{
    int choix = 0;
    while(choix != 5)
    {
        system("cls");

        cout << "(1) Nombre d'evolutions " << endl; // evolution
        cout << "(2) Nombre de planetes" << endl; // population
        cout << "(3) Nombre de dimensions" << endl; // independant run
        cout << "(4) Choix du benchmark" << endl;
        cout << "(5) Quitter" << endl;

        cin >>choix ;
        switch ( choix )
        {
            case 1:
                cout << "Saisir le nombre d'�volutions : " ;
                cin >> choix ;
                _setup.set_nb_evolution_steps(choix);
                break;
            case 2:
                cout << "Saisir le nombre de plan�tes : " ;
                cin >> choix ;
                _setup.set_population_size(choix);
                break;
            case 3:
                cout << "Saisir le nombre de dimensions : " ;
                cin >> choix ;
                _pbm.set_dimension(choix);
                break;
            case 4:
                cout << " --> Rosenbrock (1) "<<endl;
                cout << " --> Rastrigin (2) "<<endl;
                cout << " --> Ackley (3) "<<endl;
                cout << " --> Schwefel (4) "<<endl;
                cout << " --> Schaffer (5) "<<endl;
                cout << " --> Weierstrass (6) "<<endl;

                cin >> choix;
                _pbm = Problem{choix};
                break;
            case 5:
                _algo.change_parameters(_setup, _pbm);
                break;
            default:
                break;
        }
    }
}
