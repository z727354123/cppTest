
#include <iostream>
#include <Windows.h>
using namespace std;
 
int main()
{
    
    // 注册两个热键 Ctrl+F1 , Ctrl+F2
    if (0 == RegisterHotKey(NULL, 1, MOD_CONTROL, VK_F1)) {
        cout << "RegisterHotKey error : " << GetLastError() << endl;
    }
    if (0 == RegisterHotKey(NULL, 2, MOD_CONTROL, VK_F2)) {
        cout << "RegisterHotKey error : " << GetLastError() << endl;
    }
 
    // 消息循环
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)){
 
        switch (msg.message) {
        case WM_HOTKEY:
        {
            if (1 == msg.wParam) {
                cout << "1" << endl;
            }
                
            else if (2 == msg.wParam) {
                cout << "2" << endl;
            }
 
            break;
        }
            
        default:
            break;
        }
 
    }
 
    cout << "finished." << endl;
    return 0;
}