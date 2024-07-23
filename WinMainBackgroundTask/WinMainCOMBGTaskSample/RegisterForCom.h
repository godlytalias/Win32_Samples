#pragma once
#include "pch.h"

namespace winrt::WinMainCOMBGTaskSample
{
	class RegisterForCom
	{
		~RegisterForCom();
		DWORD ComRegistrationToken = 0;
		static constexpr char* RegisterForComToken = "-RegisterForBGTaskServer";
		winrt::hresult RegisterAndWaitSingle(winrt::guid classId);
	};
}