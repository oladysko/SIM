/*

Imebra 2011 build 2013-09-04_11-02-26

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013 by Paolo Brandoli/Binarno s.p.
All rights reserved.

This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as published by
 the Free Software Foundation.

This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

-------------------

If you want to use Imebra commercially then you have to buy the commercial
 support available at http://imebra.com

After you buy the commercial support then you can use Imebra according
 to the terms described in the Imebra Commercial License Version 1.
A copy of the Imebra Commercial License Version 1 is available in the
 documentation pages.

Imebra is available at http://imebra.com

The author can be contacted by email at info@binarno.com or by mail at
 the following address:
 Paolo Brandoli
 Rakuseva 14
 1000 Ljubljana
 Slovenia



*/

/*! \file dataHandlerTime.h
    \brief Declaration of the class dataHandlerTime.

*/

#if !defined(imebraDataHandlerTime_22271468_E9BC_4c3e_B733_6EA5C9DC858E__INCLUDED_)
#define imebraDataHandlerTime_22271468_E9BC_4c3e_B733_6EA5C9DC858E__INCLUDED_

#include "dataHandlerDateTimeBase.h"


///////////////////////////////////////////////////////////
//
// Everything is in the namespace puntoexe::imebra
//
///////////////////////////////////////////////////////////
namespace puntoexe
{

namespace imebra
{

namespace handlers
{

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
/// \brief This %data handler is returned by the class
///         buffer when the application wants to deal
///         with a dicom tag of type "TM" (time)
///
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
class dataHandlerTime : public dataHandlerDateTimeBase
{

public:
	virtual imbxUint32 getUnitSize() const;

	virtual void getDate(
                const imbxUint32 index,
		imbxInt32* pYear, 
		imbxInt32* pMonth, 
		imbxInt32* pDay, 
		imbxInt32* pHour, 
		imbxInt32* pMinutes,
		imbxInt32* pSeconds,
		imbxInt32* pNanoseconds,
		imbxInt32* pOffsetHours,
		imbxInt32* pOffsetMinutes) const;

	virtual void setDate(
                const imbxUint32 index,
		imbxInt32 year, 
		imbxInt32 month, 
		imbxInt32 day, 
		imbxInt32 hour, 
		imbxInt32 minutes,
		imbxInt32 seconds,
		imbxInt32 nanoseconds,
		imbxInt32 offsetHours,
		imbxInt32 offsetMinutes);

	/// \brief Return a string representing the time stored in 
	///         the buffer.
	///
	/// The returned string has the format: "HH:MM:SS.FFFFFF"
	///  where:
	///  - HH is the hour
	///  - MM is the minute
	///  - SS is the second
	///  - FFFFFF is the fraction of seconds in nanoseconds
	///
	/// @param index the zero based index of the time value to
	///               read
	/// @return a string representing the time stored in the
	///          buffer
	///
	///////////////////////////////////////////////////////////
	virtual std::wstring getUnicodeString(const imbxUint32 index) const;

	/// \brief Set the date from a string.
	///
	/// The string must have the format: "HH:MM:SS.FFFFFF"
	///  where:
	///  - HH is the hour
	///  - MM is the minute
	///  - SS is the second
	///  - FFFFFF is the fraction of seconds in nanoseconds
	///
	/// @param index the zero based index of the time value to
	///               modify
	/// @param value the string representing the time to be set
	///
	///////////////////////////////////////////////////////////
	virtual void setUnicodeString(const imbxUint32 index, const std::wstring& value);

	void parseBuffer(const ptr<memory>& memoryBuffer);

protected:
	virtual imbxUint32 maxSize() const;
};

} // namespace handlers

} // namespace imebra

} // namespace puntoexe

#endif // !defined(imebraDataHandlerTime_22271468_E9BC_4c3e_B733_6EA5C9DC858E__INCLUDED_)
