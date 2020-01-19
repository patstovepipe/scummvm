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

#ifndef ULTIMA_ULTIMA1_ACTIONS_ENTER_H
#define ULTIMA_ULTIMA1_ACTIONS_ENTER_H

#include "ultima/ultima1/actions/action.h"
#include "ultima/shared/engine/messages.h"

namespace Ultima {
namespace Ultima1 {
namespace Actions {

using Shared::CEnterMsg;

class Enter : public Action {
	DECLARE_MESSAGE_MAP;
	bool EnterMsg(CEnterMsg &msg);
public:
	CLASSDEF;

	/**
	* Constructor
	*/
	Enter(TreeItem *parent) : Action(parent) {}

	/**
	 * Destructor
	 */
	virtual ~Enter() {}
};

} // End of namespace Actions
} // End of namespace Ultima1
} // End of namespace Ultima

#endif