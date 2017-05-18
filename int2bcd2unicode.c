/*  this function only can convert 8 digit number
    use a 32bit variable to store the BCD code, because every BCD code need 4-bit space,
    so a 32bit var can store 8 BCD code.
*/
void mInt32ToBCD(int32_t iValue,uint8_t *pChar)
{
    uint32_t dTp=0;
    dTp      = iValue % 100;
    pChar[0] = (dTp/10)*16 + dTp%10;

    iValue   = iValue/100;
    dTp      = iValue % 100;
    pChar[1] = (dTp/10)*16 + dTp%10;

    iValue   = iValue/100;
    dTp      = iValue % 100;
    pChar[2] = (dTp/10)*16 + dTp%10;

    iValue   = iValue/100;
    dTp      = iValue % 100;
    pChar[3] = (dTp/10)*16 + dTp%10;
}

void BCDToUnicode (uint32_t value , uint8_t *pbuf , uint8_t len)
{
    uint8_t idx = 0;

    for( idx = 0 ; idx < len ; idx ++)
    {
        if( ((value >> 28)) < 0xA )
        {
            pbuf[ 2* idx] = (value >> 28) + '0';
        }
        else
        {
            pbuf[2* idx] = (value >> 28) + 'A' - 10;
        }
        value = value << 4;
        pbuf[ 2* idx + 1] = 0;
    }
}
