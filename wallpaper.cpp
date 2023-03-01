#include <iostream>
#include <windows.h>

int main()
{
	HKEY * key;
	LPCTSTR ruta = TEXT("Control Panel\\Desktop\\");
	long status = RegOpenKey(HKEY_CURRENT_USER, ruta, key);
	if (status != 0)
	{
		std::cout << "No se puede abrir la clave 2" << std::endl;
	}
	else
	{
		LPCTSTR _valor = "C:\\Wallpaper Virus\\Estoy en tu Disco Duro.png";
		long crear = RegSetValueEx(*key, "StartAtWindows", 0, REG_SZ, (LPBYTE)_valor, strlen(_valor)*sizeof(char));
		if (crear != 0)
		{
			std::cout << "No se pudo crear el registro 2." << std::endl;
		}
	}
	RegCloseKey(*key);
	
	system("pause");
	return 0;
}
