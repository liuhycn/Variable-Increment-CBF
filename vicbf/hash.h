#include "getpkt.h"


class hash
{
private:
	u_int64 seed = 0;
	u_int64 *hasher;
	u_int64 *scale;
	u_int64 *hardener;
public:
	hash(){}
	hash(u_int64 k)
	{
		hasher = new u_int64[k+k];
		scale = new u_int64[k+k];
		hardener = new u_int64[k+k];
		for (int i=0; i<2*k; i++)
		{
    	    hasher[i] = GenHashSeed(seed);
    	    //printf("%u ", hasher[i]);
  	 	}
  	 	//printf("\n");
   		 for (int i=0; i<2*k; i++) 
   	 	{
        	scale[i] = GenHashSeed(seed);
        	//printf("%u ", scale[i]);
    	}
    	//printf("\n");
    	for (int i=0; i<2*k; i++) 
    	{
       	 	hardener[i] = GenHashSeed(seed);
       	 	//printf("%u ", hardener[i]);
    	}
    	//printf("\n");
	}
	~hash(){}
	u_int64 AwareHash(u_char* data, u_int64 n, u_int64 hasher, u_int64 scale, u_int64 hardener);
	void mangle(const u_char* key, u_char* ret_key, int nbytes);
	u_int64 GenHashSeed(int index);
	int is_prime(int num);
	int calc_next_prime(int num);
	u_int64 getkindex(fiveTuple_t pkt, u_int64 i, u_int64 len);
};


u_int64 hash::AwareHash(u_char* data, u_int64 n, u_int64 hasher, u_int64 scale, u_int64 hardener) 
{

	while (n) 
	{
		hasher *= scale;
		hasher += *data++;
		n--;
	}
	return (hasher ^ hardener);
}


void hash::mangle(const u_char* key, u_char* ret_key, int nbytes) 
{
	for (int i=0; i<nbytes; ++i) 
	{
		ret_key[i] = key[nbytes-i-1];
	}

    if (nbytes == 13) 
    {
		ret_key[0] = key[5];
		ret_key[1] = key[11];
		ret_key[2] = key[7];
		ret_key[3] = key[6];
		ret_key[4] = key[1];
		ret_key[5] = key[9];
		ret_key[6] = key[10];
		ret_key[7] = key[4];
		ret_key[8] = key[2];
		ret_key[9] = key[8];
		ret_key[10] = key[12];
		ret_key[11] = key[0];
		ret_key[12] = key[3];
    }
}

u_int64 hash::GenHashSeed(int index) 
{
   
    u_int64 x, y = rand() + index;
    mangle((const u_char*)&y, (u_char*)&x, 8);
    return AwareHash((u_int8*)&y, 8, 388650253, 388650319, 1176845762);
}

int hash::is_prime(int num) 
{
    int i;
    for (i=2; i<num; i++)
    {
        if ((num % i) == 0)
        {
            break;
        }
    }
    if (i == num) 
    {
        return 1;
    }
    return 0;
}

int hash::calc_next_prime(int num) 
{
    while (!is_prime(num)) 
    {
        num++;
    }
    return num;
}

u_int64 hash::getkindex(fiveTuple_t pkt, u_int64 i, u_int64 len)
{
	return AwareHash(pkt.str, 13, hasher[i], scale[i], hardener[i]) % len;
}