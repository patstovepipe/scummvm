/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef KINGDOM_KINGDOM_H
#define KINGDOM_KINGDOM_H

#include "common/scummsys.h"
#include "common/config-manager.h"
#include "common/random.h"
#include "engines/advancedDetector.h"
#include "common/error.h"
#include "engines/engine.h"

#include "audio/audiostream.h"
#include "audio/decoders/wave.h"
#include "audio/mixer.h"
#include "common/events.h"
#include "common/file.h"
#include "common/queue.h"
#include "common/system.h"
#include "common/timer.h"
#include "graphics/palette.h"
#include "graphics/screen.h"
#include "graphics/surface.h"
#include "image/bmp.h"

#include "kingdom/console.h"

namespace Kingdom {
	enum KingdomDebugChannels {
		kDebugGeneral = 1 << 0
	};

	class KingdomGame : public Engine {
	public:
		KingdomGame(OSystem *syst, const ADGameDescription *gameDesc);
		~KingdomGame();

		virtual Common::Error run();

		// Detection related functions
		const ADGameDescription *_gameDescription;
		const char *getGameId() const;
		Common::Platform getPlatform() const;

	private:
		Console *_console;
		Common::RandomSource *_rnd;

		bool _LoopFlag;
		int _GameMode;
		int _StatPlay;
		bool _FstFwd;
		bool _NoIFScreen;
		bool _Sound;
		int _FrameStop;
		int _DaelonCntr;
		bool _Spell1;
		bool _Spell2;
		bool _Spell3;
		bool _ItemInhibit;
		bool _ASMode;
		bool _ATimerFlag;
		bool _BTimerFlag;
		bool _CTimerFlag;
		bool _SkylarTimerFlag;
		int _ATimer;
		int _BTimer;
		int _CTimer;
		int _SkylarTimer;
		bool _TideCntl;
		bool _MapEx;
		int _Health;
		int _HealthOld;
		int _HealthTmr;
		int _TreeEyeTimer;
		int _TreeHGTimer;
		int _TreeHGUPic;
		int _TreeLeftPic;
		int _TreeRightPic;
		int _TreeRightSta;
		bool _TSIconOnly;
		bool _LastObs;
		bool _Pouch;
		bool _NoMusic;
		byte *_ASPtr;
		int _ASMap;
		int _CurrMap;
		int _OldTLS;
		int _TreeLeftSta;
		bool _IconsClosed;
		bool _OldEye;
		bool _Eye;
		bool _OldHelp;
		bool _Help;
		bool _OldPouch;
		int _PMovie;
		bool _KeyActive;
		bool _IconRedraw;
		bool _Replay;

		// Game Flags - Will be renames later into _Nodes[]
		int16 word_2D77E;
		int16 word_2D7CC;

		Common::SeekableReadStream *_ArtPtr;
		Common::SeekableReadStream *_RezPointers[510];
		int _RezSize[510];
		int8 _Inventory[19];
		int _IconPic[7];
		uint16 _UserInput;

		void drawScreen();
		void SetupPics();
		void InitTools();
		void TitlePage();
		void InitPlay();
		void InitHelp();
		void FadeToBlack1();
		void FadeToBlack2();
		void GameHelp();
		void GPLogic1();
		void GPLogic2();
		void GPLogic3();
		void GPLogic4();
		void LoadAResource(int reznum);
		void ReleaseAResource(int reznum);
		void ShowPic(int reznum);
		void FShowPic(int reznum);
		void InitCursor();
		void SetMouse();
		void InitMPlayer();
		void PlayMovie(int movieNum);
		void EnAll();
		void DsAll();
		void SaveAS();
		void RestoreAS();
		void DrawHelpScreen();
		void DrawRect(int v1, int v2, int v3, int v4, int v5);
		void DrawInventory();
		void GameHelp_Sub43C();
		void SaveGame();
		void PlaySound(int v1);
		void EraseCursor();
	};
} // End of namespace Kingdom

#endif