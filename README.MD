# NotSoSpammy
An Email Advertizing service where you have to spam/send the email shown on the screen to the
people/Mails you know to earn tokens and you can use these tokens to change the mail that will
be shown on yours and others screen. Which is a great way to achieve free of cost email advertizing

This Project was fully built on C, it uses the GTK4 library for the construction of the GUI and
CURL 8 for the API calls and requests while using google sheet to store the global mail and it's subject
which is visible and locked and same for all the users and you can override it after you earn enough tokens

# How to use?
- Login using your gmail and the app password<br>
      (You can obtain your app password by going into manage your google account and searching it there and create a new one for this usage"<br>
- Enter the email you know into the recipient mail<br>
- Click the send mail button send the mail that is shown on your screen<br>
- After clicking the edit button you can see a token counter <br>
      (You get +10 tokens for each successful mail you send)<br>
- After Spa-/Sending your mails you amass 100 tokens than you can go into the edit mail and create a new mail with a new message which is global.<br>
- After you submit it 100 tokens are deducted and the global mail that is displayed on everyone's screen will be changed to your current submitted one.<br>

## HAPPY SPAMMING!!

# LIUNX BUILD INSTRUCTIONS

| FOR DEBIAN/UBUNTU                | For ARCH                    |      
|----------------------------------|-----------------------------|      
| Install Dependencies             | Install Dependencies        |      
| sudo apt install gtk             | sudo pacman -S gtk          |
| sudo apt install curl            | sudo pacman -S curl         |
| sudo apt install build-essential | sudo pacman -S base-devel   |
| sudo apt install cmake           | sudo pacman -S cmake        |
 
### Clone into the Github repo

| Command                             |
|---------------------------------------------------------|
| git clone https://github.com/acharya-dilip/NotSoSpammy.git |
### Navigate to project directory
| Command   |
|------------------------------|
| cd NotSoSpammy               |
### Create the build directory
| Command  |
|--------------------------|
| mkdir build              |
### Navigate into the build directory
| Command   |
|----------------------------------|
| cd build                         |
###  Execute the Build Commands
| Commands   |
|----------------------------|
| cmake ..                   |
| cmake --build .            |

### Run the Program

| Command         |
|-----------------|
| ./justasimpleccal |

# Windows Build Instructions
      
 ### Install Required Porgrams
#### Download <a href=https://www.mingw-w64.org/>MinGW</a>
#### Download <a href=https://www.msys2.org/>MSYS2</a> 

### Install Dependencies
- After Installing MSYS2 open the MSYS MinGW64 terminal
- Paste the following commands

 |Commands                               |What it Does             |
 |---------------------------------------|-------------------------|
 | pacman -Syu                           | Updates your packages   |
 | pacman -S mingw-w64-x86_64-toolchain  | Installs Toolchain      |
 | pacman -S mingw-w64-x86_64-cmake      | Installs Cmake          | 
 | pacman -S mingw-w64-x86_64-gtk4       | Installs GTK4 Library   |
 | pacman -S mingw-w64-x86_64-curl       | Installs CURL Library   | 
 | pacman -S pkgconf                     | Installs PackageConfig  | 

### Clone into the Github repo
| Command                                |
|-----------------------------------------------------------|
| git clone https://github.com/acharya-dilip/NotSoSpammy.git |
### Navigate to project dir from MSYS MinGW terminal                                   
| Command                                                                           |
|-----------------------------------------------------------------------------------|
| cd /NotSoSpammy (Be sure to use forward / while navigating in MSYS MinGW terminal) |
### Create the build directory
| Command |
|---------------------------|
| mkdir build               |
### Navigate into the build directory
| Command |
|----------------------------------|
| cd build                         |
### Execute the Build Commands
| Commands |
|----------------------------|
| cmake -G "MinGW Makefiles" .. |
| mingw32-make |

### Extract the dll.zip file
Before running the program you just compiled be sure to extract the dll.zip file from the repo
 in the same directory as your .exe file that you just made or the program wont run.


| Run the Program       |
|-----------------------|
| ./justasimpleccal.exe |
      
