



int digit_sum(int num)
{
    int s = 0;

    if (num < 0)
        num = -num;

    while (num > 0)
    {
        s += num % 10;
        num /= 10;
    }
    return s;
}
