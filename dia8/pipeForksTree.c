#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char const *argv[])
{
	//R
	if (fork()==0){//M 
		if (fork()==0)//Q
		{
			/* code */
		}
		else{
			if (fork()==0)//z
			{
				if (fork()==0)//s
				{
					if (fork()==0)//t
					{
						/* code */
					}
					else{

					}
				}
				else{

				}
			}
			else{

			}
			//aqui va lo que hace m
		}
	}
	else{
		if (fork()==0)//L
		{
			if (fork()==0)//a
			{
				/* code */
			}
			else{
				if (fork()==0)//w
				{
					if (fork()==0)//b
					{
						/* code */
					}
					else{
						if (fork()==0)//D
						{
							if (fork()==0)//F
							{
								/* code */
							}
							else{
								if (fork()==0)//E
								{
									/* code */
								}
							}
						}
					}
				}
				else{
					if (fork()==0)//k
					{
						/* code */
					}
					else{
						//lo que hace L
					}
				}
			}
		}
		//lo que hace R
	}
	return 0;
}
