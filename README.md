# SuMoS - Sudden Motion Sensor

MacOs 64-bit Library Written in C for access to Sudden Motion Sensor including Java Native Interface (JNI).

This library is a transcription of the original Christian Klein. It was create and compiled in 2006 for PowerPC and 32-bit intel, doing impossible to use with modern MacOS Versions. I recompiled for 64-bit and port to actual framework doing compatible with MacOs 10.5+


# HowTo Use

I create a ``main.c`` file with a basic use of the library. You will find the way to detect SMS depending of you computer model (PowerPC, Macbook...) and read the coordenates of Motion Sensor.

# HowTo Use with Java

The ``library`` folder contain JNILib compiled in 64-bit ready to use from Java. It's named ``libUnimotionLib.jnilib``
 
To use in a Java Class you have to load the JNI interface
 
 ````
 static 
 {    	
    System.loadLibrary("UnimotionLib");
 }
````

And define a Native Function ``readSMS()``

````
    private static native int[] readSMS();
````

After that you can use the library calling ``readSMS()`` native function whenever you need.

You can find a sample of that in Unimotion.java Class in ``java`` project root folder

# HowTo Generate JNIlib

If you have to generate a new version of JNIlib I create a bash file script to do that, in ``script`` project root folder you can find ``build_JNI_Lib.sh``. Here is the command:

````
gcc -dynamiclib -o libUnimotionLib.jnilib -I/System/Library/Frameworks/JavaVM.framework/Headers  -I /System/Library/Frameworks/IOKit.framework/IOKit -framework IOKit -I /System/Library/Frameworks/CoreFoundation.framework/CoreFoundation  -framework CoreFoundation unimotion.c
````

# HowTo Compile

If you have to compile or debug the library, may be this help you. The project is Compiled using CLion JetBrain IDE for C and C++. Library have reference to external frameworks/libraries.

* CoreFoundation
* IOKit
* JavaVM (JNI)

I will explain how to compile in Command Line, CLion and Eclipse to solve the libraries dependencies.

####Command Line

I create a bash file in ``script`` project folder, it is ``build.sh`` named or you can use directly:

````gcc -I/System/Library/Frameworks/JavaVM.framework/Headers  -I /System/Library/Frameworks/IOKit.framework/IOKit -framework IOKit -I /System/Library/Frameworks/CoreFoundation.framework/CoreFoundation  -framework CoreFoundation unimotion.c````

####For CLion

You can compile like normal execute project but have to modify CMakeList.txt to add the dependencies. 

Before you have to create ``dyLib`` from existing MacOS Frameworks. 


* Creating CoreFoundation dyLib 
````
sudo mkdir /opt/local/lib/CoreFoundation
sudo cp /System/Library/Frameworks/CoreFoundation.framework/CoreFoudnation /opt/local/lib/JavaVM/libCoreFoundation.dylib
````

* Creating IOKit dyLib
````
sudo mkdir /opt/local/lib/IOKit
sudo cp /System/Library/Frameworks/IOKit.framework/IOKit /opt/local/lib/JavaVM/IOKit.dylib
````

* Creating JavaVM dyLib
````
sudo mkdir /opt/local/lib/JavaVM
sudo cp /System/Library/Frameworks/JavaVM.framework/JavaVM /opt/local/lib/JavaVM/libJavaVM.dylib
````

After that you can add to CMakeList.txt

````
  include_directories(/opt/local/lib/CoreFoundation/)
  target_link_libraries(SuMoS /opt/local/lib/CoreFoundation/libCoreFoundation.dylib)
  
  include_directories(/opt/local/lib/IOKit)
  target_link_libraries(SuMoS /opt/local/lib/IOKit/libIOKit.dylib)
  
  include_directories(/opt/local/lib/JavaVM/)
  target_link_libraries(SuMoS /opt/local/lib/JavaVM/libJavaVM.dylib)
  
````

Via Source Link [StackOverflow](http://stackoverflow.com/a/9974616/3883898)

####For Eclipse c/c++

1. Go to project proprieties
2. Go to C/C++ build --> settings
3. Choose Mac OS X C++ Linker --> Libraries Here is where the tricky part is... I found out by "try-error" method, how this works:

Lets say you have a dylib file you want to add called "libMyLib.dylib" located in /opt/local/lib/MyLibrary

To part of the window where it says libraries add line "MyLib" To part of the window where it says Library search path add line "/opt/local/lib/MyLibrary/"

=> eclipse will automatically do this: 1. add "lib" in front of the string 2. add ".dylib" after your string

There comes another problem with Mac... Lets say you use symbols from CoreFoundation framework. Mac OS frameworks are essentialy dylibs with header files ... If you are not sure you can always check by "file myFile"

The problem is that eclipse will never correctly pick up on those dylibs from MAC OS SDK and /System/Library/Frameworks/ cause they dont have the .dylib added to them. The trick is to simply go to where the dylib is located (eventhough it doesnt have a .dylib in its name) e.g. cd /System/Library/Frameworks/CoreFoundation.framework

and then copy the file and add dylib (do NOT RENAME IT!!!)

````
  file CoreFoundation
  CoreFoundation (for architecture x86_64): Mach-O 64-bit dynamically linked shared library x86_64 
  CoreFoundation (for architecture i386):   Mach-O dynamically linked shared library i386
  #copy the lib and name it to "eclipse friendly format"
  cp CoreFoundation libCoreFoundation.dylib
````
Via Source Link [StackOverflow](http://stackoverflow.com/a/9974616/3883898)


# Note

Modern apple Computers with Solid State Drives (SSD) or Flash Storage do not use SMS as the drives have no moving parts. So you can't use it with them.

# Credits

* Written by Christian Klein
* Modified for iBook compatibility by Pall Thayer
* Modified for Hi Res Powerbook compatibility by Pall Thayer
* Modified for MacBook Pro compatibility by Randy Green
* Disparate forks unified into UniMotion by Lincoln Ramsay
* Made into a Java Native Interface by Daniel Shiffman (@shiffman)
* Build in 64-bit for MacOs 10.5+ by Eduardo Estrella 

# Links

* [Daniel Shiffman GitHub] (https://github.com/shiffman/Sudden-Motion-Sensor-Processing)