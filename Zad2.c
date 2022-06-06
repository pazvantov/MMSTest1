#include<stdio.h>
#include<stdint.h>

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4);
void flipOddBits(uint64_t* mask);
void mirrorBits(uint16_t* mask);

int main()
{
    unsigned int a;
    a = bitsNCount(127ll,63,31,15);
    printf("Bit count is:%u\n",a);

    uint64_t flip = 0ul;
    flipOddBits(&flip);
    printf("\nThe flipped num is : %lu\n",flip);
    
    uint16_t b = 64512;
    printf("\nNumber: %u\n",b);
    mirrorBits(&b);
    printf("Mirrored number: %u\n",b);

    return 0;
}

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4)
{
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    for(int i = 0;i<64;i++)
    {
        if(!!(mask1 & (1ul<<i)))
            count1++;
    }
    for(int i = 0;i<32;i++)
    {
        if(!!(mask2 & (1u<<i)))
            count2++;
    }
    for(int i = 0;i<16;i++)
    {
        if(!!(mask3 & (1u<<i)))
            count3++;
    }
    for(int i = 0;i<8;i++)
    {
        if(!!(mask4 & (1u<<i)))
            count4++;
    }
    return count1+count2+count3+count4;
}

void flipOddBits(uint64_t* mask)
{
    for(int i=1;i<64;i+=2)
    {
        *mask ^= (1lu<<i);
    }
}

void mirrorBits(uint16_t* mask)
{
    int flip1,flip2;
    for(int i=0;i<8;i++)
    {
        flip1 = !!(*mask & (1<<i));
        flip2 = !!(*mask & (1<<15-i));

        if(flip1)
            *mask |= (1<<15-i);
        else
            *mask &= ~(1<<15-i);

        if(flip2)
            *mask |= (1<<i);
        else
            *mask &= ~(1<<i);

    }
}