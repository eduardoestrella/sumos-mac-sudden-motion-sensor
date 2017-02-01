#!/bin/bash

gcc -I/System/Library/Frameworks/JavaVM.framework/Headers  -I /System/Library/Frameworks/IOKit.framework/IOKit -framework IOKit -I /System/Library/Frameworks/CoreFoundation.framework/CoreFoundation  -framework CoreFoundation unimotion.c
