# CS210-CPP
## Collab krichbourg1-snhu

## Summarize the project and what problem it was solving.
The Corner Grocer Item Frequency Analyzer is a C++ program that was developed to help a grocery store analyze purchasing trends. The program reads a text file containing grocery items and calculates the frequency of each item.  The program uses object-oriented principles, including two classes and a vector, to store items and analyze their frequency of purchase.  There is an interactive menu for users to search for specific items, display frequencies numerically, or view a histogram representation of purchases.

## What did you do particularly well?
Using principles of object-oriented programming, I separated data storage from data processing.  This allows for a well organized, easy to read, and scalable product.  I also implemented input validation to create a seamless execution. 

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
The program could be enhanced by editing the item searches to not be case-sensitive.  Further, organizing output alphabetically or numerically would allow for easier data review by the end user.  Lastly, a GUI and a database integration would streamline data managemnt. 

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most challenging aspect was fully understanding data encapsulation.  I struggled to figure out how to group each item's name and frequency count together while still keeping data accessible and modifiable. I decided to design a vector of ItemRecord objects.  This allowed me to dynamically store the many items and their count.  This way I can manage the dataset as a whole while also allowing the ability to manage individual data separately.  

I used ZyBooks as a resource as well as the following websites:
https://stackify.com/oop-concept-for-beginners-what-is-encapsulation/
https://www.geeksforgeeks.org/cpp/encapsulation-in-cpp/
https://www.geeksforgeeks.org/cpp/creating-a-vector-of-class-objects-in-cpp/
https://hatchjs.com/c-vector-of-objects/

## What skills from this project will be particularly transferable to other projects or course work?
This project strenghthened my file I/O handling, vector manipulation, class logic, and data encapsulation.  These are basic skills that I will utilizie in almost every future project.

## How did you make this program maintainable, readable, and adaptable?
I made the program maintainable by organizing code into separate class files (.h and .cpp) with meaningful function names and thorough inline documentation explaining the why behind each operation.
