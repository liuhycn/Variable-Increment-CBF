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
	a.extract(filename, pktbuf, 4000);

	for (int k = 2; k <= 20; k++)
	{
		printf("k = %u\n", k);
		vicbf vic = vicbf(11250, k, 4, "s");

		//vic.Info();
		//printf("init \n");

		for (int i = 1; i <= 2000; i++)
		{
			vic.Insert(pktbuf[i]);
			//vic.Info();
			//printf("\n");
		}


		//printf("after Insert\n");

		int errcnt = 0;

		
		for (int i = 2001; i <= 4000; i++)
		{
			if (vic.Query(pktbuf[i]))
			{
				errcnt++;
			}
			//vic.Info();
			//printf("\n");
		}
		

		cout << errcnt << endl;
		cout<<endl;
	}
	

	return 0;
}