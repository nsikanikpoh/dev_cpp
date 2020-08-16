#include <iostream>

using namespace std;

int palindromeIndex(string s)
{
    int j = s.length()-1;
    for(int i = 0 ; i<s.length()/2; i++,j--)
    {
        if(s[i]!=s[j])
        {
            if(s[i+1]==s[j])
                if(s[i]==s[j-1] && s[i+1]==s[j-2])
                    return j;
                else
                    return i;

            else if(s[j-1]==s[i])
                return j;
        }
    }
    return -1;
}

int main()
{
    cout << palindromeIndex("aaab")<< endl;
    cout << palindromeIndex("quyjjdcgsvvsgcdjjyq")<< endl;
    cout << palindromeIndex("hgygsvlfwcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcflvsgygh")<< endl;
    cout << palindromeIndex("fgnfnidynhxebxxxfmxixhsruldhsaobhlcggchboashdlurshxixmfxxxbexhnydinfngf")<< endl;
    cout << palindromeIndex("bsyhvwfuesumsehmytqioswvpcbxyolapfywdxeacyuruybhbwxjmrrmjxwbhbyuruycaexdwyfpaloyxbcpwsoiqtymhesmuseufwvhysb")<< endl;
    cout << palindromeIndex("fvyqxqxynewuebtcuqdwyetyqqisappmunmnldmkttkmdlnmnumppasiqyteywdquctbeuwenyxqxqyvf")<< endl;
    cout << palindromeIndex("mmbiefhflbeckaecprwfgmqlydfroxrblulpasumubqhhbvlqpixvvxipqlvbhqbumusaplulbrxorfdylqmgfwrpceakceblfhfeibmm")<< endl;
    cout << palindromeIndex("tpqknkmbgasitnwqrqasvolmevkasccsakvemlosaqrqwntisagbmknkqptlhrxvssvxrhl")<< endl;
    cout << palindromeIndex("prcoitfiptvcxrvoalqmfpnqyhrubxspplrftomfehbbhefmotfrlppsxburhyqnpfmqlaorxcvtpiftiocrp")<< endl;
    return 0;
}
