#include <iostream>
using namespace std;

bool est_entier(string valeur){
	bool verif(false);
	int compteur(0);
	for(int i=0;i<valeur.size();i++){
		if(valeur[i]>47 && valeur[i]<58){
			compteur++;
		}
	}
	if(compteur==valeur.size()){
		verif=true;
	}

	return verif;
}

bool est_caractere(string valeur){
	bool verif;
	if(valeur.size()==1){
		verif=est_entier(valeur);
		if(verif){
			verif=false;
		}else{
			verif=true;
		}
	}
	return verif;
}

bool est_chaine(string valeur){
	bool verif(false);
	string val;
	int compteur(0);
	if(valeur.size()>1){
		for(int i=0;i<valeur.size();i++){
			val=valeur[i];
			verif=est_caractere(val);
			if(verif){
				compteur++;
			}
		}
		if(compteur>0){
			return verif=true;
		}
	}
	return verif;
}

bool est_reel(string valeur){
	bool verif,verif2,verif3(false);
	string val,val2,val3;
	int comp_int(0),comp_moins(0),comp_point(0),comp_char(0),taille;
	for(int i=0;i<valeur.size();i++){
		val=valeur[i];
		verif=est_caractere(val);
		if(verif){
			if(val=="."){
				comp_point++;
			}else{
				comp_char++;
			}
		}else{
			verif2=est_entier(val);
			if(verif2){
				comp_int++;
			}
		}
	}
	if(valeur[0]=='-'){
		comp_moins++;
	}
	taille=valeur.size()-(comp_point+comp_moins);
	val3=valeur[0];
	val2=valeur[valeur.size()-1];
	verif2=est_entier(val2);
	verif3=est_entier(val3);
	if(verif3){
		verif3=true;
	}
	if(verif2){
		if(comp_point==1){
			if(comp_int==taille){
				if(verif3){
					return verif2;
				}else{
					if(valeur[0]=='-'){
						return verif2;
					}else{
						return false;
					}
				}
			}else{
				return false;
			}
		}else{
			if(valeur[0]=='-' && comp_char==1){
				return verif2;
			}else{
				return false;
			}
		}
	}else{
		return false;
	}
}

void est_de_type(string valeur){
	bool v1;
	v1=est_entier(valeur);
	if(v1){
		cout<<"Entier"<<endl;
	}else{
		v1=est_caractere(valeur);
		if(v1){
			cout<<"Caractere"<<endl;
		}else{
			v1=est_reel(valeur);
			if(v1){
				cout<<"Reel"<<endl;
			}else{
				v1=est_chaine(valeur);
				if(v1){
					cout<<"Chaine de caractere"<<endl;
				}else{
					cout<<"Votre valeur n'a pas de type repertorie."<<endl;
				}
			}
		}
	}
}

/*int main()
{
	string valeur;
	bool verif;
	cout<<"Entre une valeur et je te dirai son type"<<endl;
	getline(cin,valeur);
	est_de_type(valeur);
	return 0;
}
*/
