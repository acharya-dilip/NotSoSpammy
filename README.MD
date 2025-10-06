# NotSoSpammy
An Email Advertizing service where you have to spam/send the email shown on the screen to the
people/Mails you know to earn tokens and you can use these tokens to change the mail that will
be shown on yours and others screen. Which is a great way to achieve free of cost email advertizing

This Project was fully built on C, it uses the GTK4 library for the construction of the GUI and
CURL 8 for the API calls and requests while using google sheet to store the global mail and it's subject
which is visible and locked and same for all the users and you can override it after you earn enough tokens

# How to use?
-->Login using your gmail and the app password
      (You can obtain your app password by going into manage your google account and searching it there and create a new one for this usage"
-->Enter the email you know into the recipient mail
-->Click the send mail button send the mail that is shown on your screen
-->After clicking the edit button you can see a token counter 
      (You get +10 tokens for each successful mail you send)
-->After Spa-/Sending your mails you amass 100 tokens than you can go into the edit mail and create a new mail with a new message which is global.
-->After you submit it 100 tokens are deducted and the global mail that is displayed on everyone's screen will be changed to your current submitted one.

## HAPPY SPAMMING!!

# LINUX BUILD INSTRUCTIONS

| FOR DEBIAN/UBUNTU                | For ARCH                    |
|----------------------------------|-----------------------------|
| Install Dependencies             | Install Dependencies        |
|  sudo apt install gtk            | sudo pacman -S gtk          |
|  sudo apt install curl           | sudo pacman -S curl         |
| sudo apt install build-essential | sudo pacman -S base-devel   |
|  sudo apt install cmake          | sudo pacman -S cmake        |

### Clone into the Github repo
#### git clone https://github.com/acharya-dilip/NotSoSpammy.git

### Navigate to project directory
#### cd NotSoSpammy

### Create the build directory
#### mkdir build

### Navigate into the build directory
#### cd build

### Execute the Build Commands

#### cmake ..
#### cmake --build .

### Run the Program
#### ./justasimpleccal



