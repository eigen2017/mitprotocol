//
// Created by root on 9/25/17.
//

#ifndef MITPROTOCOL_MYCROSS_H
#define MITPROTOCOL_MYCROSS_H

#ifdef ANDROID
#include <android/log.h>
	#define MyPrint(...)  __android_log_print(ANDROID_LOG_INFO, "myprint:", __VA_ARGS__)
#else
#include <stdio.h>
#define MyPrint(...) printf("myprint:" __VA_ARGS__)
#endif

#endif //MITPROTOCOL_MYCROSS_H
