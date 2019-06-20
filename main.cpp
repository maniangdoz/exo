#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;

void saisie(string &mot){
    cout<<"\t\t\t\t\t\tEntrer votre mot:";
    cin>>mot;
    for(int i=1;i<=50;i++){
        cout<<"\n";
    }
}

string melange(string mot){
    int number(0);
    string melange;

    while(mot.size()!=0){
        number=rand() % mot.size();
        melange+=mot[number];
        mot.erase(number,1);
    }
    return melange;
}

int main()
{
    string mot_mystere,mot_melange,mot_utilisateur;
    int choix,point(5),malus(0),cmpt(5);
    int moyenne;

    cout<<"\t\t\t\t\t\t[Mot Mystere]"<<endl;

    do{
        srand(time(0));
        saisie(mot_mystere);
        mot_melange=melange(mot_mystere);

        do{
            for(int i=5;i>0;i--){

                cout<<"\t\t\t\t\t\tce mot te dit un truc ?"<<mot_melange<<"?"<<endl;
                cout<<"\t\t\t\t\t\tEntrer le mot correct:";
                cin>>mot_utilisateur;
                cout<<"\n";

                if(mot_utilisateur!=mot_mystere){
                    cout<<"\t\t\t\t\t\til te reste "<<i-1<<" essaies"<<endl;
                    cerr<<"\t\t\t\t\t\tErreur essaie encore !"<<endl;
                    malus++;
                    cmpt--;
                    cout<<"\n";
                }
                else{
                    cout<<"\t\t\t\t\t\tFelicitation ! Tu as trouve !."<<endl;
                    break;
                    cout<<"\n";
                }
            }
            if(cmpt==0){
                cout<<"\t\t\t\t\t\ttu t'es bien battu. la reponse est "<<mot_mystere<<endl;
                cout<<"\n";
            }

            mot_utilisateur=mot_mystere;
        }while(mot_utilisateur!=mot_mystere);

        cout<<"\t\t\t\t\t\t-->Continuer ?"<<endl;
        cout<<"\t\t\t\t\t\t1-continuer\n"<<"\t\t\t\t\t\t0-sortir\n";
        cout<<"\t\t\t\t\t\tton choix:";
        cin>>choix;

    }while(choix==1);

            moyenne=point-malus;
            cout<<"\t\t\t\t\t\tTa moyenne est de:"<<moyenne<<endl;
            cout<<"Merci pour votre participation"<<endl;

return 0;
}
