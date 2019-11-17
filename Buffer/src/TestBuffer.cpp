#ifndef O_DIRECT
#define O_DIRECT 0
#endif
#include "../includes/Buffer.h"
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>

int main(int argc, char **argv) {

cout<<"hi"<<endl;
//Buffer*  buffer;
//Buffer buffer("../temper2.txt");
	char  *testFile ="testo10.txt";
	Buffer* buffer = new Buffer(testFile);

	cout<<"1:   "<<buffer->getChar()<<endl;
	cout<<"2:   "<<buffer->getChar()<<endl;
	cout<<"3:   "<<buffer->getChar()<<endl;
	cout<<"4:   "<<buffer->getChar()<<endl;
	cout<<"5:   "<<buffer->getChar()<<endl;
	cout<<"6:   "<<buffer->getChar()<<endl;
	cout<<"7:   "<<buffer->getChar()<<endl;
	cout<<"8:   "<<buffer->getChar()<<endl;
	cout<<"9:   "<<buffer->getChar()<<endl;
	cout<<"10:   "<<buffer->getChar()<<endl;

//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;
//	buffer->ungetChar();
//	cout<<buffer->getChar()<<endl;
//	cout<<buffer->getChar()<<endl;

//	for(int i=0; i<505 && !buffer->fileEnded();i++){ //
//		buffer->getChar();
//	}
//	cout<<"for schleife ending"<<endl;
	//cout<<buffer->getChar()<<endl;

	cout<<buffer->getChar()<<endl;
	cout<<buffer->getLine()<<endl;
	cout<<buffer->getColumn()<<endl;
	cout<<buffer->getChar()<<endl;
	cout<<buffer->getLine()<<endl;
	cout<<buffer->getColumn()<<endl;
	cout<<buffer->getChar()<<endl;
		cout<<buffer->getLine()<<endl;
		cout<<buffer->getColumn()<<endl;
		cout<<buffer->getChar()<<endl;
			cout<<buffer->getLine()<<endl;
			cout<<buffer->getColumn()<<endl;
			cout<<buffer->getChar()<<endl;
				cout<<buffer->getLine()<<endl;
				cout<<buffer->getColumn()<<endl;
				cout<<buffer->getChar()<<endl;
					cout<<buffer->getLine()<<endl;
					cout<<buffer->getColumn()<<endl;

						buffer->ungetChar();
						cout<<buffer->getChar()<<endl;
							cout<<buffer->getLine()<<endl;
							cout<<buffer->getColumn()<<endl;
							cout<<buffer->getChar()<<endl;
								cout<<buffer->getLine()<<endl;
								cout<<buffer->getColumn()<<endl;

//			cout<<buffer->getChar()<<endl;
//			cout<<buffer->getChar()<<endl;
//		cout<<buffer->getChar()<<endl;
//		cout<<buffer->getChar()<<endl;
//		cout<<"boolean '\n"<<endl;
//		cout<<(buffer->getChar()=='n')<<endl;
//		cout<<"end"<<endl;
//		cout<<buffer->getChar()<<endl;
//		cout<<buffer->getChar()<<endl;
//
//		cout<<buffer->getChar()<<endl;
//		cout<<buffer->getChar()<<endl;
//		cout<<buffer->getChar()<<endl;
//				cout<<buffer->getChar()<<endl;

















//	int fd;
//	char buf[50];
//	fd = open(testFile,O_DIRECT);
//	if(fd == -1){
//		printf("openinghla failed");
//		exit(1);
//	}
//	cout<<"fd ist: "<<fd<<endl;
//	read(fd,buf,48);
//	buf[49]='\0';
//
//	close(fd);
//	cout<<"buf 1 ist: "<<buf[0]<<endl;
//	cout<<"buf 2 ist: "<<buf[1]<<endl;
//	cout<<"buf 3 ist: "<<buf[2]<<endl;
	//printf("bus: %s\n", buf);



//	int fd;
//			char buf[1024];
//			char* leftBuffer;
//			char* rightBuffer;
//			unsigned int buffsize=1024;
//			leftBuffer= new char [buffsize];
//			rightBuffer= new char[buffsize];
//			posix_memalign((void**) &leftBuffer,1024,buffsize);
//			posix_memalign((void**) &rightBuffer,1024,buffsize);
//
////			fd = open("testo.txt",O_CREAT| O_WRONLY, 0600);
////			if(fd == -1){
////				printf("opening failed");
////				exit(1);
////			}
////			write(fd, "Hello World!\n take me \n",13);
////			close(fd);
//			char* current=&leftBuffer[0];
//			fd=open("testo.txt", O_DIRECT);
//			if(fd == -1){
//				printf("fail to read open file\n");
//			}else{
//					printf("open sucess\n");}
//
//
//			int byteReaded= read(fd,&leftBuffer[0],1024);
//			off_t fileEnd = lseek(fd,0,SEEK_END);//off_t represent file size , signed integer
//			int fileStart= lseek(fd,0,SEEK_SET);
//			buf[29]='\0';
////			printf("buf: %s\n", buf);
//			cout<<"fd : "<<fd<<endl;
//			cout<<"lseek : "<<fileEnd<<endl;
//			cout<<"lseek filestart : "<<fileStart<<endl;
//			cout<<"byteReaded number : "<<byteReaded<<endl;
//			cout<<"leftbuff 1 ist: "<<*current<<endl;
//
//			printf("Print leftBuff 1 : %c\n", *current);
//			current++;
//			printf("Print leftBuff 2 : %c\n", *current);
//			cout<<"bool \0: "<<(*current=='\0')<<endl;
//			current++;
//			printf("Print leftBuff 3 : %c\n", *current);
//			current++;
//			printf("Print leftBuff 4 : %c\n", *current);
//			current++;
//			printf("Print leftBuff 5 : %c\n", *current);
//			current++;
//			printf("Print leftBuff 6 : %c\n", *current);
//			cout<<"bool \0: "<<(*current=='\0')<<endl;
//			current++;
//			printf("Print leftBuff 7 : %c\n", *current);
//			cout<<"bool \0: "<<(*current=='\0')<<endl;
//			current++;
//			printf("Print leftBuff 8 : %c\n", *current);
//			cout<<"bool \0: "<<(*current=='\0')<<endl;
//			current++;
//			printf("Print leftBuff 9 : %c\n", *current);
//			cout<<"bool \0: "<<(*current=='\0')<<endl;
//			current++;
//			printf("Print leftBuff 10 : %c\n", *current);
//			cout<<"boo \0: "<<(*current=='\0')<<endl;
//			current++;
//			printf("Print leftBuff 11 : %c\n", *current);
//			cout<<"boo \0: "<<(*current=='\0')<<endl;
//			cout<<"bool \0: "<<(*current=='eof')<<endl;
//			cout<<"bool \0: "<<(*current==EOF)<<endl;
//			cout<<"bool \0: "<<(*current=='EOF')<<endl;
//			current++;
//			printf("Print leftBuff 12 : %c\n", *current);
//			cout<<"boo \0: "<<(*current=='\0')<<endl;
//			cout<<"bool \0: "<<(*current=='eof')<<endl;
//			cout<<"bool \0: "<<(*current==EOF)<<endl;
//			cout<<"bool \0: "<<(*current=='EOF')<<endl;
//			current++;
//			printf("Print leftBuff 13 : %c\n", *current);
//			cout<<"boo \0: "<<(*current=='\0')<<endl;
//			cout<<"bool \0: "<<(*current=='eof')<<endl;
//			cout<<"bool \0: "<<(*current==EOF)<<endl;
//			cout<<"bool \0: "<<(*current=='EOF')<<endl;
//			current++;
//			printf("Print leftBuff 14 : %c\n", *current);
//			cout<<"boo \0: "<<(*current=='\0')<<endl;
//			cout<<"bool \0: "<<(*current=='eof')<<endl;
//			cout<<"bool \0: "<<(*current==EOF)<<endl;
//			cout<<"bool \0: "<<(*current=='EOF')<<endl;
//			printf("Print leftBuff 15 : %c\n", *current);
//			cout<<"boo \0: "<<(*current=='\0')<<endl;
//			cout<<"bool \0: "<<(*current=='eof')<<endl;
//			cout<<"bool \0: "<<(*current==EOF)<<endl;
//			cout<<"bool \0: "<<(*current=='EOF')<<endl;
//			cout<<"buf 1 ist: "<<current<<endl;
//			printf("Print leftBuff: %c\n", *current);
//			current++;
//			cout<<"buf 2 ist: "<<current<<endl;




	return 0;

}

