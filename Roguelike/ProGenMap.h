/** \file ProGenMap.h
* Contains the Definitions of the ProceduralMap class
*/

#include "Structs.h"

/**
* \class ProceduralMap ProGenMap.h "ProGenMap.H"
* \brief This class represents the engine to Procedurally Generate Maps
*/

class ProceduralMap{

	public:

		ProceduralMap(char **Map, int x, int y);
		void GenerateRoom(char **Map, int x, int y, int size);
		void GeneratePaths(char **Map, Coord Rooms[]);
		~ProceduralMap();
		bool IsWall(char **Map, int x, int y);
		bool IsDoor(char **Map,int x, int y);
		bool IsTile(char **Map,int x, int y);

	private:



};