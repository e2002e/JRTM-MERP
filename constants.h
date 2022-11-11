#ifndef CONSTANTS_H
#define CONSTANTS_H

class Constants {
public:
    Constants();
private:
    const char *tranchantes[5][23];
    const char *contendantes[5][25];
    const char *deuxmain[5][21];
    const char *projectiles[5][18];
    const char *dynamiques[9][23];
    const char *deplacement[6][6];
    const char *rencontres[5][13];
    const char *morsures[5][23];
    const char *saisies[5][21];
    const char *sorts[3][27];
    int JR[15][16];
    const char *boules[5][26];
    const char *eclairs[5][27];
};

#endif // CONSTANTS_H
