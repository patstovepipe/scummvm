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

#include "ultima/shared/std/string.h"
#include "common/algorithm.h"

namespace Ultima {
namespace std {

const char *const endl = "\n";

string::string(size_t n, char c) : Common::String() {
	ensureCapacity(n, false);
	for (size_t idx = 0; idx < n; ++idx)
		(*this) += c;
}

size_t string::find(char c, size_t pos) const {
	const char *p = strchr(_str + pos, c);
	return p ? p - _str : npos;
}

size_t string::find(const char *s) const {
	const char *str = strstr(_str, s);
	return str ? str - _str : npos;
}

size_t string::rfind(const char *s) const {
	int sLen = strlen(s);

	for (int idx = (int)_size - sLen; idx >= 0; --idx) {
		if (!strncmp(_str + idx, s, sLen))
			return idx;
	}

	return npos;
}

size_t string::rfind(char c, size_t pos) const {
	for (int idx = MIN((int)_size - 1, (int)pos); idx >= 0; --idx) {
		if ((*this)[idx] == c)
			return idx;
	}

	return npos;
}

size_t string::find_first_of(char c, size_t pos) const {
	const char *strP = (pos >= _size) ? 0 : strchr(_str + pos, c);
	return strP ? strP - _str : npos;
}

size_t string::find_first_of(const char *chars, size_t pos) const {
	for (uint idx = pos; idx < _size; ++idx) {
		if (strchr(chars, (*this)[idx]))
			return idx;
	}

	return npos;
}

size_t string::find_first_not_of(char c, size_t pos) const {
	for (uint idx = pos; idx < _size; ++idx) {
		if ((*this)[idx] != c)
			return idx;
	}

	return npos;
}

size_t string::find_first_not_of(const char *chars, size_t pos) const {
	for (uint idx = pos; idx < _size; ++idx) {
		if (!strchr(chars, (*this)[idx]))
			return idx;
	}

	return npos;
}

size_t string::find_last_not_of(char c) const {
	for (int idx = (int)_size - 1; idx >= 0; --idx) {
		if ((*this)[idx] != c)
			return c;
	}

	return npos;
}

size_t string::find_last_not_of(const char *chars) const {
	for (int idx = (int)_size - 1; idx >= 0; --idx) {
		if (!strchr(chars, (*this)[idx]))
			return idx;
	}

	return npos;
}

string string::substr(size_t pos, size_t len) const {
	if (pos >= _size)
		return string();
	else if (len == npos)
		return string(_str + pos);
	else
		return string(_str + pos, MIN(_size - pos, len));
}

string &string::erase(size_t pos, size_t len) {
	if (pos < _size) {
		if (len == npos || (pos + len) >= _size)
			*this = string(_str, _str + pos);
		else
			*this = string(_str, _str + pos) + string(_str + pos + len);
	}

	return *this;
}

string::iterator string::erase(iterator it) {
	this->deleteChar(it - _str);
	return it;
}

void string::resize(size_t count) {
	if (count == 0)
		clear();
	else if (count < size())
		*this = string(_str, _str + count);
	else {
		while (size() < count)
			*this += ' ';
	}
}

} // End of namespace std
} // End of namespace Ultima