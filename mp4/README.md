Write a program to do the following:
loads username/password sets from the file password.txt and insert them into the hash table until the end of file is reached on password.txt. The password.txt file will look something like this with one username/password set per line.
mary     changeMe!

The program will then present a login prompt, read one username, present a password prompt, and after looking up the username's password in the hash table, will print either "Authentication successful" or "Authentication failure".

The above step will be repeated until the end of the input data (EOF) is reached on the console input stream (cin). The EOF character on the PC's is the CTRL Z character.

To convert from a string to an integer, we can add the ascii value of each character together. For instance, Mary's conversion from string to integer might look something like this:

109('m') + 97('a') + 114('r') + 121('y')=441

We've converted the string to an integer, but we still need to convert the integer to an index. For an array of 10 elements we can divide by 10 and use the remainder as an index. Combining these two hash functions, we will get Mary's index to be: 441 % 10 = 1

Your primary tasks for this homework are to edit the login.cpp to replace the comments with lines so that it does the following:
Insert passwords into the Hash Table.
Retrieve one user's Password structure from the Hash Table.
Compare retrieved user password to input password and print "Authentication failure" or "Authentication successful."