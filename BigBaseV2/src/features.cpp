#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "PlayerInfo.h"

namespace big
{
	void features::run_tick()
	{
		if (g_local_player.player != PLAYER::PLAYER_ID() || g_local_player.player_ped != PLAYER::PLAYER_PED_ID())
		{
			g_local_player.player = PLAYER::PLAYER_ID();
			g_local_player.player_ped = PLAYER::PLAYER_PED_ID();
		}
	}

	void features::script_func()
	{
		while (true)
		{
			TRY_CLAUSE
			{
				run_tick();
			}
			EXCEPT_CLAUSE
			script::get_current()->yield();
		}
	}
}
