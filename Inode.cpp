/*
* By: Aniket Kudale
* Email: aniket.kudale@hotmail.com
* http://www.github.com/aniketkudale
* Simulate stat() command using c++
* Dated: 23-06-2014
* Share! Improve! Ask! But dont copy!
*/


#include<iostream>
#include<fstream>
#include<string>
#include<sys/types.h>// required
#include<sys/stat.h>// required
#include<fcntl.h>
#include<time.h>
#include<cstring>
using namespace std;
int main()
{

              struct stat buf; // stat structure object creation

              //Getting file name from user
              char filename[90];
              cout<<"Enter filename: ";
              cin>> filename;

              char* ext =strrchr(filename,'.'); // getting the file extension



              //Pre-file initialization
             //ifstream inFile;
            // inFile.open(filename); // to scan and open filename

              stat(filename,&buf); // stat function which stores all req info in buffer;

              // Printing Inode info
              cout<<filename<<endl;
              cout<<"File type: ";
              switch(buf.st_mode & S_IFMT)   // checking file type // Bit Mask for file type bit fields
              {
                             case S_IFBLK: cout<<"Its a Block device"<<endl;
                             break;

                             case S_IFREG: cout<<"Its a  Regular "<<ext<<" File"<<endl;
                             break;

                             case S_IFCHR: cout<<"Its a Character device"<<endl;
                             break;

                             case S_IFDIR: cout<<"Its a Directory"<<endl;
                             break;

                             case S_IFIFO: cout<<"Its a Pipe/FIFO"<<endl;
                             break;

                             case S_IFLNK: cout<<"Its a Symlink"<<endl;
                             break;

                             case S_IFSOCK: cout<<"Its a Socket file"<<endl;
                             break;

                             default: cout<<"File type unknown"<<endl;
                             break;



              }
              cout<<"Device no: "<<buf.st_dev<<endl;
              cout<<"File Permission: ";

               if(S_ISDIR(buf.st_mode))
               {
                              cout<<"d";

               }
               else
               {
                               cout<<"-";
               }

               if(buf.st_mode & S_IRUSR)
               {
                              cout<<"r";

               }
               else
               {
                               cout<<"-";
               }

               if(buf.st_mode & S_IWUSR)
               {
                              cout<<"w";

               }
               else
               {
                               cout<<"-";
               }

               if(buf.st_mode & S_IXUSR)
               {
                              cout<<"x";

               }
               else
               {
                               cout<<"-";
               }
               if(buf.st_mode & S_IRGRP)
               {
                              cout<<"r";

               }
               else
               {
                               cout<<"-";
               }
               if(buf.st_mode & S_IWGRP)
               {
                              cout<<"w";

               }
               else
               {
                               cout<<"-";
               }
               if(buf.st_mode & S_IXGRP)
               {
                              cout<<"x";

               }
               else
               {
                               cout<<"-";
               }
               if(buf.st_mode & S_IROTH)
               {
                              cout<<"r";

               }
               else
               {
                               cout<<"-";
               }
               if(buf.st_mode & S_IWOTH)
               {
                              cout<<"w";

               }
               else
               {
                               cout<<"-";
               }
               if(buf.st_mode & S_IXOTH)
               {
                              cout<<"x";

               }
               else
               {
                               cout<<"-";
               }

              cout<<endl;
              cout<<"Inode no: "<<buf.st_ino<<endl;
              cout<<"No. of Hard Links: "<<buf.st_nlink<<endl;
              cout<<"User ID of owner: "<<buf.st_uid<<endl;
              cout<<"Group ID of owner: "<<static_cast<unsigned long>(buf.st_gid)<<endl;
              cout<<"Total Size (in bytes): "<<static_cast<double>(buf.st_size/1024)<<" KB"<<endl;
              cout<<"Blocksize for filesystem I/O: "<<static_cast<unsigned long>(buf.st_blksize)<<endl;
              cout<<"Number of blocks allocated: "<<static_cast<unsigned long>(buf.st_blocks)<<endl;

              cout<<"Time (Last Access): "<<ctime(&buf.st_atime)<<endl;
              cout<<"Time (Last Modification): "<< ctime(&buf.st_mtime)<<endl;
              cout<<"Time (Last Changed): "<<ctime(&buf.st_ctime)<<endl;


return 0;
}
