#pragma once
#include "pch.h"

namespace winrt::BGTaskTest
{
	class RegisterForCom
	{
		DWORD ComRegistrationToken = 0;
	public:
		~RegisterForCom();
		winrt::hresult RegisterAndWait(winrt::guid classId);
		static constexpr wchar_t* RegisterForComToken = L"-RegisterForBGTaskServer";
	};
}