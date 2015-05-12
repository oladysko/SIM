#include "Parser.h"
#include "DicomDataAdapter.h"

namespace  ParserH
{
	void MarshalString(String ^ s, std::string& os)
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	void fileNametoPath(std::string% os)
	{
		std::string tmp;
		std::size_t found = 0;
		while ((found = os.find("\\", found + 2)) != std::string::npos){
			os.insert(found, "\\");
			if (found + 2 > os.size())
				return;
		}
	}
}