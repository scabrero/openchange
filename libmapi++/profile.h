/*
   libmapi C++ Wrapper
   Profile Class

   Copyright (C) Alan Alvarez 2008.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef LIBMAPIPP__PROFILE_H__
#define LIBMAPIPP__PROFILE_H__

#include <libmapi++/clibmapi.h>

namespace libmapipp {

class profile 
{
	public:

		bool static set_default(const char* profname)
		{
			return (SetDefaultProfile(profname) == MAPI_E_SUCCESS);
		}

		bool static set_default(const std::string& profname)
		{
			return set_default(profname.c_str());
		}

		std::string static get_default_profile() throw (mapi_exception)
		{
			const char* profname = NULL;
			if (GetDefaultProfile(&profname) != MAPI_E_SUCCESS)
				throw mapi_exception(GetLastError(), "profile::get_default_profile : GetDefaultProfile()");

			return std::string(profname);
		}

		~profile()
		{
			if (m_profile)
				::ShutDown(m_profile);
		}


	private:
		mapi_profile	*m_profile;
};

} // namespace libmapipp

#endif //!LIBMAPIPP__PROFILE_H__