// https://github.com/MrFranQx/winblitz
//
// This module includes conversions from UTF-16 to UTF-8 and vice versa.

module;

#include <string>
#include <string_view>
#include <Windows.h>

export module mrfranqx.winblitz.utf8;

namespace Winblitz {
	export std::wstring utf8_to_utf16(std::string_view s)
	{
		std::wstring ws;
		if (s.empty())
			return ws;
		int sz = MultiByteToWideChar(
			CP_UTF8,
			MB_ERR_INVALID_CHARS,
			s.data(),
			static_cast<int>(s.size()),
			nullptr,
			0
		);
		
		ws.resize(sz);
		int chk = MultiByteToWideChar(
			CP_UTF8,
			MB_ERR_INVALID_CHARS,
			s.data(),
			static_cast<int>(s.size()),
			ws.data(),
			sz
		);

		if (chk == 0) {
			// TODO: add error handling
		}

		return ws;
	}

	export std::string utf16_to_utf8(std::wstring_view ws)
	{
		std::string s;
		if (ws.empty())
			return s;

		int sz = WideCharToMultiByte(
			CP_UTF8,
			WC_ERR_INVALID_CHARS,
			ws.data(),
			static_cast<int>(ws.size()),
			nullptr,
			0,
			nullptr,
			nullptr
		);

		s.resize(sz);
		int chk = WideCharToMultiByte(
			CP_UTF8,
			WC_ERR_INVALID_CHARS,
			ws.data(),
			static_cast<int>(ws.size()),
			s.data(),
			sz,
			nullptr,
			nullptr
		);

		if (chk == 0) {
			// TODO: add error handling
		}

		return s;
	}
}