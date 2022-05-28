// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

extern "C" int __declspec(dllexport) __cdecl sum(int a, int b) {
    return a + b;
}
