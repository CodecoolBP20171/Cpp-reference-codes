//
// Created by László Molnár on 2017-11-15.
//

#ifndef CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
#define CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
class LightningWordFinder
{
public:
    // compilation was made with MINGW on Windows
    // 1.880.460 ns
    std::string getLongestWord(const std::string& text)
    {
        unsigned currentWordStart = 0;
        unsigned currentWordLength = 0;
        unsigned biggestWordStart = 0;
        unsigned biggestWordLength = 0;
        unsigned textLength = text.size();

        for (unsigned i = 0; i < textLength; ++i) {
            if( text[i] > 64 && text[i] < 91 ||
                text[i] > 96 && text[i] < 123 )
            {
                ++currentWordLength;
            }else {
                if (currentWordLength > biggestWordLength) {
                    biggestWordLength = currentWordLength;
                    biggestWordStart = currentWordStart;
                }
                currentWordLength = 0;
                currentWordStart = i + 1;
            }
        }
        return text.substr(biggestWordStart, biggestWordLength);
    }

    // 1.973.496 ns
    std::string getLongestWord_1(const std::string& text)
    {
        // 1973496.000000ns
        unsigned currentWordStart = 0;
        unsigned currentWordLength = 0;
        unsigned biggestWordStart = 0;
        unsigned biggestWordLength = 0;
        unsigned textLength = text.size();

        for (unsigned i = 0; i < textLength; ++i) {
            if( text[i] < 'A' ||
                text[i] > 'Z' ||
                (text[i] > 'a' && text[i] < 'z') )
            {
                if (currentWordLength > biggestWordLength) {
                    biggestWordLength = currentWordLength;
                    biggestWordStart = currentWordStart;
                }
                currentWordLength = 0;
                currentWordStart = i + 1;
                continue;
            }
            ++currentWordLength;
        }
        return text.substr(biggestWordStart, biggestWordLength);
    }

    // 3.453.019 ns
    std::string getLongestWord_2(const std::string& text)
    {
        unsigned currentWordStart = 0;
        unsigned currentWordLength = 0;
        unsigned biggestWordStart = 0;
        unsigned biggestWordLength = 0;
        unsigned textLength = text.size();

        const char* strPtr = text.data();
        char chr;
        for (unsigned i = 0; i < textLength; ++i, ++strPtr) {
            chr = *strPtr;
            if( chr > 96 && chr < 123 ||
                chr > 64 && chr < 91 )
            {
                ++currentWordLength;
            }else{
                if (currentWordLength > biggestWordLength) {
                    biggestWordLength = currentWordLength;
                    biggestWordStart = currentWordStart;
                }
                currentWordLength = 0;
                currentWordStart = i + 1;
            }
        }
        return text.substr(biggestWordStart, biggestWordLength);
    }
};
#endif //CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
