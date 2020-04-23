// collisions.h
void check_gates()
{
	if(map_Y == 1 && (map_X == 4 || map_X == 5 || map_X == 6))
	{
		map[1][5] = 0;
		//gate1_status++;
		//if (gate1_status > 4) gate1_status = 1;
	}
	else if((map_Y == 4 || map_Y == 5 || map_Y == 6) && map_X == 1) {map[5][1] = 0;}
	else if((map_Y == 4 || map_Y == 5 || map_Y == 6) && map_X == 4) {map[5][4] = 0;}
	else {map[1][5] = 120; map[5][1] = 110; map[5][4] = 110;}
}

void check_stuff()
{
	if(map_Y == 2 && map_X == 3) {map[2][3] = 0; ammo_2x3 = true;} else if(map_Y1 == 2 && map_X1 == 3) {map[2][3] = 0; ammo_2x3 = true;}
	if(map_Y == 2 && map_X == 4) {map[2][4] = 0; grenade_2x4 = true;} else if(map_Y1 == 2 && map_X1 == 4) {map[2][4] = 0; grenade_2x4 = true;}
	if(map_Y == 3 && map_X == 3) {map[3][3] = 0; grenade_3x3 = true;} else if(map_Y1 == 3 && map_X1 == 3) {map[3][3] = 0; grenade_3x3 = true;}
	if(map_Y == 3 && map_X == 4) {map[3][4] = 0; grenade_3x4 = true;} else if(map_Y1 == 3 && map_X1 == 4) {map[3][4] = 0; grenade_3x4 = true;}
	if(map_Y == 3 && map_X == 1) {map[3][1] = 0; first_aid_3x1 = true;} else if(map_Y1 == 3 && map_X1 == 1) {map[3][1] = 0; first_aid_3x1 = true;}
}

////////////////////////////////////////////////////////////////////////////////
// checking collision //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void check_collision()
{
	if (map[map_Y][map_X] == 100 || map[map_Y1][map_X1] == 100) collision = true;
	else if (map[map_Y][map_X] == 110 || map[map_Y1][map_X1] == 110) collision = true;
	else if (map[map_Y][map_X] == 200 || map[map_Y1][map_X1] == 200) collision = true;
	else collision = false;
}
