#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class vicbf
{
private:
	u_int64 m;
	u_int64 k;
	u_int64 l;
	u_int64 count = 0;
	vector<u_int64> dl;
	u_int16 *table;
	hash Hashfamiy;
public:
	vicbf(){}
	vicbf(u_int64 m, u_int64 k, u_int64 l, string type);
	~vicbf(){}
	bool Insert(fiveTuple_t pkt);
	bool Query(fiveTuple_t pkt);
	bool Delete(fiveTuple_t pkt);
	void Info()
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d ", table[i]);
		}
		printf("\n");
	}
};

vicbf::vicbf(u_int64 m, u_int64 k, u_int64 l, string type)
{
	this->m = m;
	this->k = k;
	this->table = new u_int16[m];
	Hashfamiy = hash(k);
	//memset(table, 0, sizeof(table));
	for (int i = 0; i < m; i++)
	{
		table[i] = 0;
	}
	int temp = 0;
	if (type[0] == 's')
	{
		for (int i = l; temp < l; temp++, i++)
		{
			dl.push_back(i);
		}
	}
	else if (type[0] == 'g')
	{
		dl.push_back(8);
		dl.push_back(12);
		dl.push_back(14);
		dl.push_back(15);
	}
	else
	{
		printf("init err\n");
	}
}

bool vicbf::Insert(fiveTuple_t pkt)
{
	for (int i = 0; i < k; i++)
	{
		u_int64 increase = dl[Hashfamiy.getkindex(pkt, k + i, dl.size())];
		u_int64 index = Hashfamiy.getkindex(pkt, i, m);
		//printf("increase = %u, index = %u.\n", increase, index);
		//printf("\n");

		/*
		if self.BF[slot_index] + increment >= 2 ** self.bpc - 1:
             self.BF[slot_index] = 2 ** self.bpc - 1
                else:
                    self.BF[slot_index] += increment
        */
       	//printf("index %u increase  %u\n",index, increase);
        if (table[index] + increase >= pow(2, 9) - 1)
        {
        	printf("maxxxxxx %u \n", index);
        	table[index] = pow(2, 9) - 1;
        	printf("1111\n");
        }
        else
        {
        	table[index] = table[index] + increase;
        }
		
		count++;
	}
}

bool vicbf::Query(fiveTuple_t pkt)
{
	for (int i = 0; i < k; i++)
	{
		u_int64 decrement = dl[Hashfamiy.getkindex(pkt, k + i, dl.size())];
		u_int64 index = Hashfamiy.getkindex(pkt, i, m);
		int decrvalue = (int)(table[index] - decrement);
		//printf("%d\n", decrvalue);
		//printf("index %u decrement  %u\n",index, decrement);
		//printf("cha zhi %d\n", decrvalue);
		if (decrvalue == 0 || decrvalue >= (int)dl[0])
		{
			//printf("pass this k\n");
			continue;
		}
		else
		{
			//printf("false11\n");
			return false;
		}
	}
	return true;
}

bool vicbf::Delete(fiveTuple_t pkt)
{
	for (int i = 0; i < k; i++)
	{
		u_int64 increase = dl[Hashfamiy.getkindex(pkt, k + i, dl.size())];
		u_int64 index = Hashfamiy.getkindex(pkt, i, m);
		
	}
}