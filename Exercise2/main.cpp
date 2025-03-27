#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

std::vector<double> Mappa(std::vector<double> vettore_valori_iniziali) {
	std::vector<double> nuovi_valori;
    int dimensione = vettore_valori_iniziali.size();                      // Funzione (Mappa) che prende un vettore di partenza di N componenti double in [1,5] e restituisce 
    for (int i = 0; i < dimensione; i++) {                                // un vettore le cui componenti (double) sono quelle di partenza mappate in [-1,2](rispettando le      
	  nuovi_valori.push_back(0.75 * vettore_valori_iniziali[i] - 1.75);   // posizioni iniziali).
	    }
    return nuovi_valori;
}

int main() {   
    std::ifstream inputFile("data.txt");
	std::vector<std::string> righe;
	std::string riga;
    while (getline(inputFile, riga)) {
        righe.push_back(riga);                           // Prendo le righe del file in lettura (che sono stringhe), le metto dentro al vettore di stringhe
    }                                                    // 'righe' e poi le converto in double inserendo i valori ordinati nel vettore 'valori_iniziali'.                    
    std::vector<double> valori_iniziali;
	int N = righe.size();
	for (int i = 0; i < N; i++) {
		valori_iniziali.push_back(std::stod(righe[i]));
	}
	std::vector<double> mean_vector;
	std::vector<double> new_values = Mappa(valori_iniziali);
	for (int i = 0; i < N; i++) {
		double sum = 0.0;                                 // Una volta aver applicato 'Mappa' al vettore 'valori_iniziali' creo il vettore contenente 
	    for (int j = 0; j <= i; j++) {		              // le medie e poi con le componenti di quel vettore scrivo le righe del file "result.txt".
			    sum += new_values[j];
		    }
	        mean_vector.push_back(sum/(i + 1));
	} 
    std::ofstream outputFile("result.txt");
	outputFile << "#" << " " << "N" << " " << "Mean" << "\n";
	for (int z = 0; z < N; z++) {
		outputFile << z + 1 << " " << std::scientific << std::setprecision(16) << mean_vector[z] << "\n";
    }
}

