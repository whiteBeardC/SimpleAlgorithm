/*
* Author: Yang Le
* Date: 2020/07/05
* Description: High-precision addition.
*/

string Addition(const string &lhs, const string &rhs)
{
    string str1 = lhs;
    string str2 = rhs;

    // make sure the size of str1 is larger than that of str2.
    if (str1.size() > str2.size())
    {
        swap(str1, str2);
    }

    int n = str1.size();
    int m = str2.size();

    int t = 0;  // the flag of carry
    string res = "";
    for (int i = 0; i < m; ++i)
    {
        int currentValue = 0;  // sum of current digit
        if (i < n)
            currentValue = (str1[i] - '0') + (str2[i] - '0') + t;
        else
            currentValue = str2[i] - '0' + t;
        res += to_string( currentValue % 10 );
        t = currentValue / 10;
    }

    if (t > 0)
    {
        res += "1";
    }

    return res;
}