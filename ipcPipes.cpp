/*

* By: Aniket Kudale
* Email: aniket.kudale@hotmail.com
* http://www.github.com/aniketkudale
* IPC using Pipes simple
* Dated: 24-06-2014
* Share! Improve! Ask! But dont copy!
This program takes a string from user passes in child process(A), child process reverses the string and passes the results to parent process (B) which
prints it.



*/


#include<iostream> // required
#include<cstring>  // required for string manipulation
#include<algorithm> // reverse algorithm used for reversing string
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h> // req for pid_t datatype
using namespace std;
int main()
{
               int pid[2];   // pipe initialization
               ssize_t fbytes; //ssize_t is used for functions whose return value could either be a valid size, or a negative value to indicate an error
               pid_t childpid; // pid_t as a 'signed integer type"'
               char  buf[20]={0}; // initilize buffer to null values..
               string input;




               pipe(pid); // Only one pipe used // we can use two pipes also.

// fork() - return -1: error
// return 0:  its child process
// return value >0: its parent process

               if((childpid=fork())==-1) // fork the process, and assign returned value to childpid
               {
                          perror("Fork Error");
                          _exit(1);
               }

               if(childpid==0) // if childpid=0 its child process
               {
                               cout<<"Enter a String: "; //accepting string
                               getline(cin, input);

                              // child process close the input side of the pipe
                              close(pid[0]);  //pid[0] closing input side of pipe

                              reverse(input.begin(), input.end());  // reversing the string - builtin function used..
                              fbytes = input.length(); // getting the length of the string

                              char *cstr = &input[0];   // converting string to char

                              // Send reversed string through the output side of pipe
                              write(pid[1], cstr, fbytes);
                              close(pid[1]);
                              _exit(0);

               }
               else
               {


                              // Parent process closing the output side of pipe.
                              close(pid[1]);

                              // reading the string from the pipe
                              //reversed string will be retrived in buf
                             read(pid[0], buf, sizeof(buf));

                             cout<<"Reversed string: "<<buf;
                             close(pid[0]);



               }
               return 0;


}
