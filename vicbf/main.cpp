#include "hash.h"
#include "vicbf.h"

#include <iostream>
#include <math.h>

using namespace std;

fiveTuple_t pktbuf[38000001];

int main()
{
	srand(time(NULL));

	extracter a;
	char filename[] = "test2.pcap";
	a.extract(filename, pktbuf, 40000);

	for (int ii = 0; ii < 20; ii++)
	{

	
		//printf("%d\n\n\n", ii);
		for (int k = 10; k <= 10; k++)
		{
			//printf("k = %u\n", k);
			vicbf vic = vicbf(122222, k, 16, "s");

			//vic.Info();
			//printf("init \n");

			for (int i = 1; i <= 20000; i++)
			{
				vic.Insert(pktbuf[i]);
				//vic.Info();
				//printf("\n");
			}


			//printf("after Insert\n");

			int errcnt = 0;

			
			for (int i = 20001; i <= 40000; i++)
			{
				if (vic.Query(pktbuf[i]))
				{
					errcnt++;
				}
				//vic.Info();
				//printf("\n");
			}
			

			cout << errcnt * 1.0 / 20000 << endl;
			//cout<<endl;
		}
		//printf("\n");

	}
	return 0;
}