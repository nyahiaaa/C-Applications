/*
Nazlee Yahia
p1200800



*/
#include <fstream>
#include <iostream>
#include <vector> 
#include <algorithm> 
#include <sstream>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std; 

bool sortcol( const vector<double>& v1, const vector<double>& v2 ) { 
 return v1[0] < v2[0];     //pour assurer que le sort par rangee est bien fait
} 

int main(int argc, char** argv) 
{ 
	string input;	//pour les commandes
	string ofile;   //pour nom du fichier out
	string ifile;   //pour nom du fichier in
	char spc = ' '; //char espace
    ofstream outfile; 
	vector< vector<double> > vect;	 //la matrice 2d
	int i;	       //compteur
	bool out = false; //sign du -o out
	bool in = false;  //sign du -i in
	bool a = false;   //sign du -a alleatoire
	bool r = false;   //sign du -r random
	bool c = false;   //sign du -c colonne
	bool h = false;

	
	for (i = 0; i < argc; ++i){
		input = argv[i];  //sauvegarde la commande
		
		if(input == "-h"){ //commande -h
			cout<<"\t\tLa Matrice"<<endl;
			cout<<"Le but de ce programme est de trier une matrice sur les rangee ou les colonnes\navec des donnee aleatoire ou du user"<<endl;
			cout<<"-o output: le fichier qui suit la commande va contenir les resultat"<<endl;
			cout<<"-i input: le fichier qui suit la commande va contneir les valeurs a utiliser"<<endl;
			cout<<"-a aleatoire: va generer des tailles et valeur aleatoires"<<endl;
			cout<<"-r random: va peremettre a la commande -a de generer de nouvelles valeur et non le meme"<<endl;
			cout<<"-c colonne: triage faite en colonnes"<<endl;
			cout<<"-h help: pour savoires les different commandes"<<endl;
			
		}
		
		else if(input == "-o"){ //commande -o
			cout<<"-o output. le fichier est "<<argv[i+1]<<endl;
			ofile = argv[i+1]; //sauvegarde le fichier dans le quel output
			i++;
            outfile.open(ofile);//ouvrire le fichier avec le nom 
            out = true;//vrai que l'ont output dans un fichier
            
		}
		
		else if(input == "-i"){//commande -i
			cout<<"-i input. le fichier est "<<argv[i+1]<<endl;
			ifile = argv[i+1];//sauvegarde le fichier du quel on lit
			i++;
			if(a == true){
				cout<<"erreur -a est initialiser"<<endl;
				break;
			}
			in = true;//vrai que l'ont input du fichier
   			ifstream ifs(ifile);//ouvrir le fichier
    		string tempstr;
    		double tempint;

    		while (getline(ifs, tempstr)) { //lire la ligne et mettre les valeur dans un vecteur
        	istringstream iss(tempstr);
        	vector<double> tempv;
        	while (iss >> tempint) {
            tempv.push_back(tempint);
        	}
        	vect.push_back(tempv);//mettre le vecteur dans un vecteur pour un vecteur 2d
    		}
			
			
				
		}
		
		else if(input == "-a"){//commande -a
			cout<<"-a alleatoire. "<<endl;
			if(in == true){
				cout<<"erreur -i est initialiser"<<endl;
				break;
			}
			a = true;//vrai on veux des valeurs alleatoire
			
		}
		
		else if(input == "-r"){//commande -r
			cout<<"-r randomize"<<endl;
			if(in == true){
				cout<<"-i was initialized first"<<endl;
				break;
			}
			r = true; //vrai on veux la valeur de Time dans srand()
		}
		
		else if(input == "-c"){//commande -c
			cout<<"-c tirage faite en colonne"<<endl;
			c = true; //vrai on veux triage en colonne
		}
		
	}
	
	
	if(a == true){//remplir le vecteur 2d avec des valeur alleatoire
		if(r == true){//si -r est vrai mettre Time dans srand()
			srand((unsigned)time(NULL));
		}
		int row, col;
		double rando;
		row = rand() % 10 + 1;
		col = rand() % 10 + 1;
		rando = rand() % 10;
		for(int q = 0; q < row; q++){
			vector<double> temp;
			for(int w = 0; w < col; w++){
				temp.push_back(rando);
				rando = rand() % 10;
			}
			vect.push_back(temp);
		}
		
	}
	
	if(a == false && in == false && h == false){//si -a et -i ne sont pas initialiser
		cout<<"no input. end."<<endl;
		return 0;
	}

    int m = vect.size(); //nombre de range
  
    int n = vect[0].size(); //nombre de colonne


	//imprimer la matrice avant le triage
	if(out == true)
		outfile << "The Matrix before sorting is:\n"; //si -o output dans le fichier
	else
    	cout << "The Matrix before sorting is:\n";
	 
    for (int i=0; i<m; i++) 
    { 
    	if(out == true){

    	for (int j=0; j<n ;j++){
            outfile << vect[i][j] << spc;
        }
            outfile << endl;
		}
		
		else{
		
        for (int j=0; j<n ;j++) 
            cout << vect[i][j] << " "; 
        cout << endl;
	}
    }                                
  
	if(c == true){//si -c tirage de colonne
			for(int i = 0; i <= n; i++){
			for(int j = 1; j < n; j++){
				double v1 = vect[0][j-1];
				double v2 = vect[0][j];
				
				if(v2 < v1){
				for(int k = 0; k < m; k++){
					double t1 = vect[k][j-1];
					double t2 = vect[k][j];
					double t3;
					t3 = t1;
					vect[k][j-1] = t2;
					vect[k][j] = t3;		
				}
				}
				
			}
		}
	

	}
	
	else{ //sinon triage par range
    sort(vect.begin(), vect.end(), sortcol);


	}
	  
	  
    //imprimer la matrice apres le tirage 
	if(out == true)
		outfile << "The Matrix after sorting is:\n"; //si -o
	else
    	cout << "The Matrix after sorting is:\n";
    for (int i=0; i<m; i++) 
    { 
    	if(out == true){
    
    	for (int j=0; j<n ;j++){
            outfile << vect[i][j] << spc;
        }
            outfile << endl;
		}
		
		else{
        for (int j=0; j<n ;j++) 
            cout << vect[i][j] << " "; 
        cout << endl;
	}
    }     	
	

	return 0; 
} 
