#include "../include/ogl3d/window/OWindow.h"
#include <Windows.h>
#include <assert.h>

OWindow::OWindow() {
    WNDCLASSEXW wc = {};  // Use WNDCLASSEXW for wide-character
    wc.cbSize = sizeof(WNDCLASSEXW);
    wc.lpszClassName = L"OGL3dWindow";  // Wide-character string
    wc.lpfnWndProc = DefWindowProc;

    assert(RegisterClassExW(&wc));  // Use RegisterClassExW for wide-character

    RECT rc = {0, 0, 1024, 768};
    AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE);

    m_handle = CreateWindowExW(
        0, L"OGL3dWindow", L"Alyssa's Really Cool Window", 
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, 
        CW_USEDEFAULT, CW_USEDEFAULT, 
        rc.right - rc.left, rc.bottom - rc.top, 
        NULL, NULL, NULL, NULL
    );

    assert(m_handle);

    ShowWindow((HWND)m_handle, SW_SHOW);
    UpdateWindow((HWND)m_handle);
}

OWindow::~OWindow() {
    DestroyWindow((HWND)m_handle);
}
