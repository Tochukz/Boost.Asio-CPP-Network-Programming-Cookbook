# Boost.Asio C++ Network Programming Cookbook  (2016)  
__By Dmytro Radchuk__  

### Development Environment
[Install MinGW and VSCode Ext. for C++](https://code.visualstudio.com/docs/languages/cpp)    
[Setup VSCode for GCC with MinGW](https://code.visualstudio.com/docs/cpp/config-mingw)

__task.json__  
The `.vscode/tasks.json` file tells VS Code how to build (compile) the program.  
```
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "shell",
      "label": "C/C++: g++.exe build active file",
      "command": "C:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\g++.exe",
      "args": ["-g", "${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}.exe"],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "problemMatcher": ["$gcc"],
      "group": {
        "kind": "build",
        "isDefault": true
      }
    }
  ]
}
```  
To run the build go to `Terminal > Run Build Task` or `Ctrl+Shift+b`

### Boost C++ Library
[Boost Getting Started](https://www.boost.org/doc/libs/1_76_0/more/getting_started/index.html)  
[Boost Libraries A-Z](https://www.boost.org/doc/libs/1_76_0/libs/libraries.htm#Alphabetically)
__Installation__  
* Download and unpack the from boost_1_76_0.zip from [boost.org/users/history/version_1_76_0.html](https://www.boost.org/users/history/version_1_76_0.html)
* Move the unpacked file to `C:\Program Files\boost\boost_1_76_0`  
* Most Boost libraries are _header-only_ and therefore require no separately-compiled library binaries or special treatment when linking.
* Some Boost libraries like _Boost.Filesystem_, _Boost.IOStream_ etc, must be build separately and others like _Boost.Graph_, _Boost.Math_ etc, have optional separately-compiled binaries. See [boost.org/doc/libs/1_76_0/more/getting_started/windows.html](https://www.boost.org/doc/libs/1_76_0/more/getting_started/windows.html) for details.

#### Building Simple Program Using Boost
__Build From Visual Studio IDE__  
Add the Path to boost (`C:\Program Files\boost\boost_1_76_0`) to your project's VC++ Directories.  
* Right click on your project and click _Properties_
* Click on _Configuration Properties_ > _V++ Directories_
* Go to _General_ > _Include Directories_
* Append the path  `C:\Program Files\boost\boost_1_76_0` to the Include Directories
```
[EXITING_PATH];C:\Program Files\boost\boost_1_76_0
```
* You can now `#include` boost in your source code

#### Preparing Boost Library Binary
To use any of the separately-compiled Boost libraries, you'll need to acquire library binaries.
__Simple use of Boost Library Binary__  
To build from source using Visual C++
* Open and command prompt and navigate to the root directory of boost
* Prepare the _Boost.Build_ system  
```
> bootstrap
```  
* Invoke the _Boost.Build_ separately-compiled Boost libraries
```
> b2
```
This command will take a while to complete. At the end you should see a final output that looks like this   
  ```
  The Boost C++ Libraries were successfully built!

  The following directory should be added to compiler include paths:

      C:\Program Files\boost\boost_1_76_0

  The following directory should be added to linker library paths:

      C:\Program Files\boost\boost_1_76_0\stage\lib
  ```

__Build Binaries from Source__  
For earlier version of Visual C++ or a compiler from another vendor you'll need to build and install _Boost.Build_.   
To install _Boost.Build_
* Go to `tools/build` from your boost root directory
* Run the bootstrap.bat script
```
> bootstrap.bat
```
* Run the install
```
> b2 install --prefix=YOUR-CHOOSEN-INSTALLATION-PATH
```
* Add `YOUR-CHOOSEN-INSTALLATION-PATH/bin` to your PATH environment variable  

## Chapter 1: The Basics
__Introduction__  
The application that consists of two or more parts, each of which runs on a separate computing device, and communicates with other parts over a computer network is called a __distributed application__.  

Network programming is inherently complex and doing it with a low-level C-style socket API makes it even more complex and error prone. _Boost.Asio_ is an object-oriented C++ library that is, just like raw Socket API, built around the concept of a _socket_. Roughly speaking, _Boost.Asio_ wraps raw Socket API and provides the developer with object-oriented interface to it.  

__Active socket vs Passive socket__   
A socket intended to be used to send and receive data to and from a remote application or to initiate a connection establishment process with it is called an _active socket_, whereas a _passive socket_ is the one used to passively wait for incoming connection requests from remote applications. Passive sockets don't take part in user data transmission.  
