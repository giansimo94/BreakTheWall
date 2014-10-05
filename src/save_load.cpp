#include "src/save_load.h"

#define filename "BestScores.o"

/**
 * @brief
 * Salvataggio della struttura in un file binario
 * @param TopScores
 */

void Save_Load::save(Score TopScores[])
{
    ofstream salvataggio(filename);
    for (int i=0; i<10; i++)
    {
        salvataggio << TopScores[i].Nome << "     ";
        salvataggio << TopScores[i].POINTS;
        salvataggio << endl;
    }
    salvataggio.close();
}

/**
 * @brief
 * Caricamento dei dati da file binario nella struttura di riferimento
 * @param TopScores
 */

void Save_Load::load(Score TopScores[])
{
    ifstream caricamento(filename);

    for (int i=0; i<10; i++)
    {
        caricamento >> TopScores[i].Nome;
        caricamento >> TopScores[i].POINTS;

    }
    caricamento.close();
}

