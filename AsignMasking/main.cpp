#include <iostream>

void printUBinary(unsigned int n)
{
	if (n > 1) // we only recurse if n > 1, so this is our termination case for n == 0
		printUBinary(n / 2);

	std::cout << n % 2;
}

int main()
{
    constexpr unsigned char option_viewed{ 0x01 };
    constexpr unsigned char option_edited{ 0x02 };
    constexpr unsigned char option_favorited{ 0x04 };
    constexpr unsigned char option_shared{ 0x08 };
    constexpr unsigned char option_deleted{ 0x80 };

    unsigned char myArticleFlags{};

    //Write a line of code to set the article as viewed.
    myArticleFlags |= option_viewed;
{
	if (n > 1) // we only recurse if n > 1, so this is our termination case for n == 0
		printUBinary(n / 2);

	std::cout << n % 2;
};
    //Write a line of code to check if the article was deleted.
    if (myArticleFlags & option_deleted)


   //  Write a line of code to clear the article as a favorite.
     myArticleFlags &= ~option_favorited;




    return 0;
}
