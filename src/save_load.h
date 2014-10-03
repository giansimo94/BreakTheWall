#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <src/brick.h>
#include <fstream>

using namespace std;

/**
 * @brief
 * Struttura dati per salvataggio dei dati: Punteggio e Nome
 */

struct Score
{
    int POINTS;
    char Nome[20];
};

/**
 * @brief
 * Struttura dati per salvataggio/caricamento dei dati
 */

struct Save_Load
{
    void save(Score TopScores[]);
    void load(Score TopScores[]);
};

#endif // SAVE_LOAD_H
