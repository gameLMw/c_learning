bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    if (x == 0)
    {
        return true;
    }
    long long i = 0;
    int j = x;
    while (x > 0)
    {
        i = i * 10 + x % 10;
        x = x / 10;
    }
    return i == j;
}
