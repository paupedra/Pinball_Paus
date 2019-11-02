#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

enum GameState {
	GAME_TOSTART,
	GAME_RUNNING,
	GAME_WAITINGBALL,
	GAME_END
};


class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> Clear_Boards;


	PhysBody* left_flipper;
	PhysBody* right_flipper;
	PhysBody* left_flipper_joint;
	PhysBody* right_flipper_joint;
	PhysBody* left_L;
	PhysBody* right_L;
	PhysBody* cooler;
	PhysBody* cooler_bump;
	p2List<PhysBody*> triangles;
	
	

	PhysBody* sensor;
	bool sensed;

	SDL_Texture* ball_tex;
	SDL_Texture* board_tex;
	SDL_Texture* cover_board_tex;
	SDL_Texture* Left_Flipper_tex;
	SDL_Texture* Right_Flipper_tex;

	uint bonus_fx;

	p2Point<int> ray;
	bool ray_on;

	SDL_Rect board_rect = { 0,0,700,650 };
	
	uint score;
	uint prev_score;
	uint best_score;

	GameState current_state;

private:

	int Clear_Board[76] = {
	630, 650,
	526, 246,
	483, 333,
	513, 350,
	548, 350,
	597, 543,
	408, 648,
	406, 710,
	234, 708,
	230, 648,
	50, 542,
	106, 352,
	146, 348,
	173, 333,
	146, 244,
	136, 240,
	158, 164,
	184, 236,
	160, 153,
	193, 47,
	198, 36,
	205, 29,
	213, 25,
	221, 20,
	230, 15,
	243, 11,
	263, 8,
	422, 8,
	436, 8,
	449, 9,
	461, 13,
	475, 20,
	491, 30,
	506, 45,
	680, 650,
	682, 669,
	639, 673,
	630, 650
	};

	int cooler_point[30] = {
	289, 173,
	334, 168,
	383, 174,
	385, 244,
	381, 241,
	372, 187,
	360, 177,
	345, 175,
	334, 174,
	319, 175,
	307, 178,
	296, 187,
	287, 239,
	283, 243,
	289, 173
	};

	int left_L_point[12] = {
	142, 388,
	116, 510,
	208, 561,
	205, 566,
	113, 511,
	142, 388
	};

	int right_L_point[12] = {
	440, 562,
	442, 564,
	542, 510,
	517, 387,
	536, 507,
	440, 562
	};

	int left_triangles_points[12] = {
	432, 498,
	470, 390,
	481, 394,
	493, 477,
	443, 503,
	432, 498
	};

	int right_triangles_points[12] = {
	188, 390,
	175, 397,
	165, 482,
	211, 504,
	220, 495,
	188, 390
	};
	
	int Left_Flipper[20] = {
		7, 0,
		89, 0,
		94, 3,
		94, 10,
		91, 15,
		10, 25,
		1, 20,
		0, 12,
		2, 4,
		7, 0
	};
	int Right_Flipper[20] = {
		-7, 0,
		-89, 0,
		-94, 3,
		-94, 10,
		-91, 15,
		-10, 25,
		-1, 20,
		0, 12,
		-2, 4,
		-7, 0
	};

};
