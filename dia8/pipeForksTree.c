#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	//R
	if (fork()==0){//M 
		if (fork()==0)//Q
		{
			/* code */sleep(20);

		}
		else{
			if (fork()==0)//z
			{
				if (fork()==0)//s
				{
					if (fork()==0)//t
					{
						/* code */sleep(20);
					}
					else{
							sleep(20);
					}
				}
				else{
						sleep(20);
				}
			}
			else{
				sleep(20);
			}
		}
	}
	else{
		if (fork()==0)//L
		{
			if (fork()==0)//a
			{
				/* code */sleep(20);
			}
			else{
				if (fork()==0)//w
				{
					if (fork()==0)//b
					{
						/* code */sleep(20);
					}
					else{
						if (fork()==0)//D
						{
							if (fork()==0)//F
							{
								/* code */ sleep(20);
							}
							else{
								if (fork()==0)//E
								{
									/* code */ sleep(20);
								}
								else{
									sleep(20);
								}
							}
						}
						else{
							sleep(20);
						}
					}
				}
				else{
					if (fork()==0)//k
					{
						/* code */sleep(20);
					}
					else{
						sleep(20);
						//lo que hace L 
					}
				}
			}
		}
		else{
			sleep(20);
		//lo que hace R
		}
	}
	return 0;
}