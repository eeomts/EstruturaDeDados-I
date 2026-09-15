typedef struct coord *Coord;

Coord generatePoint(int valueX, int valueY);
int getCoordX(Coord point);
int getCoordY(Coord point);
double distacePoints(Coord a, Coord b);

void freePoint(Coord **point);
