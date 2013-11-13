#include <random>
#include "ProGenMap.h"

using namespace std;


void ProceduralMap::GenerateRoom(char **map, int x, int y, int size){
	
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<> dis(1, 5);

	//what's the biggest size room we can put on this map
	int max_room_size = 0;

	for (int i(1); i < 6; i++){

		int length = i + i + 3; //1 wall + i blocks + 1 anchor + i blocks + 1 wall



	}

	//if max room size is 0 then map is too small to make any real rooms in

	int quota = 0;
	size < 3 ? quota = 3 : quota = size;

	for (int i(0); i < size;i++)


}

bool ProceduralMap::IsDoor(char **map,int x, int y){

	return map[x][y] = '#' ? true : false;

}

bool ProceduralMap::IsTile(char **map, int x, int y){

	return map[x][y] = '.' ? true : false;

}

bool ProceduralMap::IsWall(char **map, int x, int y){

	return map[x][y] = '=' ? true : false;

}