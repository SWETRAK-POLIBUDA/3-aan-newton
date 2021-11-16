#include <iostream>
using namespace std;

double newton(double p, const double* x, const double* y, int wezly);

int main() {

    double p;
    int wezly;

    cout<<"Podaj ilość węzłów: ";
    cin>>wezly;
    double x[wezly];
    double y[wezly];
    cout<<"Podaj x:"<<endl;
    for(int i = 0; i< wezly; i++){
        cout<<"Podaj wartość x"<<i+1<<": ";
        cin>>x[i];
    }

    cout<<"Podaj y:"<<endl;
    for(int i = 0; i< wezly; i++){
        cout<<"Podaj wartość y"<<i+1<<": ";
        cin>>y[i];
    }
    cout<<"Podaj punkt: ";
    cin>>p;


    cout<<"Wynik to: "<<newton(p, x, y, wezly)<<endl;
    return 0;
}

/*
 * Format tablicy jest następujący tablica[wersy][kolumny]
 */

double newton(double p, const double* x, const double* y, int wezly){
    double tab[wezly][wezly];
    double wynik = 0;
    for(int i = 0; i < wezly; i++){
        tab[i][0] = y[i];
    }

    for(int k = 1; k< wezly; k++){
        for(int w = k; w< wezly; w++){
            tab[w][k] = (tab[w][k-1] - tab[w-1][k-1])/(x[w] - x[w-k]);
        }
    }

    /*
     *  Pętla drukująca tablice dwuwymiarowa

    for(int i = 0; i < wezly; i++){
        for(int j = 0; j < wezly; j++){
            cout<<tab[j][i]<<" ";
        }
        cout<<endl;
    }

    */

    for(int g = 0; g< wezly; g++){
        double subwynik = tab[g][g];
        for(int k = 0; k <= g-1; k++ ){
            subwynik *= (p - x[k]);
        }
        wynik += subwynik;
    }



    return wynik;
}
