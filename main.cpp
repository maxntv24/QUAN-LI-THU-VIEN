#include <iostream>
#include <string>
#include "menu.h"
#include "my_lib.h"
#include "HamHoTro.h"
int main() {
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	remove_scrollbar();
	//taoMaDocGia();
	//testgithub
	//intro();
	menuChinh();
	
	return 0;
}