# SBUnix

SBUnix is a co-operative operatibg system. To run the file just load with following quemu command:



==SYSTEM CALLS==   

    READ()
    Syntax       :  read(file *file, uint64_t addr, char *buf )
    Description  :  Whenever called  this function reads the file in to the buffer 'buf'.
    return       :  This call returns the length of bytes read into the buffer or -1 if there is an error
    
    WRITE() 
    Syntax       :  int write(file *fd, char * buf, int size)
    Description  :  Whenever called it writes up to 'size' number of bytes into the file descriptor 'fd' from the buffer starting at 'addr'.
    Dependencies :  To open a file always use OPEN system call before reading and after the read is completed, close the file.
                    This call returns -1 for the files opened with O_RDONLY flag set. It cannot do any write operations on tarfs.
    return       :  This function retruns length of bytes written into the buffer
    
    FORK()
    Syntax       :  int fork (void); 
    Description  :  Whenever called a child process is created. It returns pid = 0 for child process and non zero for parent process.
    return       :  This call returns the pid for parent process or 0 for the child  process.
    
    EXECVE()
    Syntax       :  execvpe(char *file, char *argv[], char *envp[])
    Description  :  Whenever called a file along with any necessary arguments argv[] in the environment envp[] is executed.
    
    EXIT()
    Syntax       :  exit(int status)
    Description  :  Whenever called the calling process is terminated immediately.

    GETPID()
    Syntax       :  getpid()
    Description  :  Whenever called the process id of currently running process is returned.
    
    GETPPID()
    Syntax       :  getppid()
    Description  :  Whenever called the parent's process id of currently running process is returned.
    
    PS()
    Syntax       :  ps()
    Description  :  Whenever called the list of all currently running processes is returned.  
    
    SLEEP()
    Syntax       :  sleep(int msec)
    Description  :  The state of the current task is changed to 'sleep' for 'msec' milliseconds.
