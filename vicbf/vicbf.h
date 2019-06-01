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
	u_int8 *table;
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
	this->table = new u_int8[m];
	Hashfamiy = hash(k);
	memset(table, 0, sizeof(table));
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
        if (table[index] + increase >= pow(2, 8) - 1)
        {
        	table[index] = pow(2, 8) - 1;
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
		int decrvalue = table[index] - decrement;
		if (decrvalue < 0)
		{
			return false;
		}
		else if (decrvalue > 0 && decrvalue < l)
		{
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