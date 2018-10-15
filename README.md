# checkout-system
Checkout Order Kata

Blah Blah Blah

Developed in C++(11) on a PC running Windows 10 using Visual Studio Code as editor
Built and tested on Ubuntu Linux running in a VirtualBox VM
Test-Driven Development using Google Test

Dependencies:
-------------
Google Test (https://github.com/google/googletest)

Tool chain:
-----------
Gradle 4.10.2 (requires Java JDK or JRE version 7 or higher to be installed)
make (to build googletest)

To build and run Checkout System tests on Linux:
------------------------------------------------
cd checkout-system
gradle installGoogleTest  # downloads and installs googletest package (only need to run once, though will redo if done repeatedly)
gradle build              # builds and runs unit tests




Design Notes:
-------------

Assumptions for Checkout Order Kata:
- Scans and limit adjustments on specials are frequent; markdowns, specials, and removals are infrequent.
- Specials only apply to same items, though BnGmOfELVforXoff applies to same items different weights.

