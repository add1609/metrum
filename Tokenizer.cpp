#include "Tokenizer.hpp"
#include <iostream>
#include <iomanip>


namespace metrum {

    Word Tokenizer::parse(const std::string &inProgram) {
        Word currWord;
        Token currToken;

        for (char currCh : inProgram) {
            if(currToken.mType == POT_SCHWA && currCh != ' ') {
                currToken.mType = VOKAL_O;
                currToken.mText = currToken.mText.front();
                endToken(currToken,currWord);

                currToken.mType = FRIKATIV;
                currToken.mText.append(1, 'r');
                endToken(currToken,currWord);
            }
            switch (currCh) {
                case 'A':
                case 'a':
                    endToken(currToken,currWord);
                    currToken.mType = VOKAL_O;
                    currToken.mText.append(1, currCh);
                    break;

                case 'B':
                case 'b':
                    endToken(currToken,currWord);
                    currToken.mType = PLOSIV;
                    currToken.mText.append(1, currCh);
                    break;

                case 'C':
                case 'c':
                    if(currToken.mText.back() == 'S' || currToken.mText.back() == 's') {
                        currToken.mType = PLOSIV; // bsp. scannen
                    } else {
                        endToken(currToken,currWord);
                    }
                    currToken.mText.append(1, currCh);
                    break;

                case 'D':
                case 'd':
                    endToken(currToken,currWord);
                    currToken.mType = PLOSIV;
                    currToken.mText.append(1, currCh);
                    break;

                case 'E':
                case 'e':
                    if(currToken.mText.back() == 'I' || currToken.mText.back() == 'i') {
                        currToken.mText.append(1, currCh);
                        endToken(currToken,currWord);
                    } else {
                        endToken(currToken,currWord);
                        currToken.mType = VOKAL_O;
                        currToken.mText.append(1, currCh);
                    }
                    break;

                case 'F':
                case 'f':
                    if(currToken.mText.back() != 'P' && currToken.mText.back() != 'p') {
                        endToken(currToken,currWord);
                    }
                    currToken.mType = FRIKATIV;
                    currToken.mText.append(1, currCh);
                    endToken(currToken,currWord);
                    break;

                case 'G':
                case 'g':
                    endToken(currToken,currWord);
                    currToken.mType = PLOSIV;
                    currToken.mText.append(1, currCh);
                    break;

                case 'H':
                case 'h':
                    if(currToken.mText.back() != 'C' && currToken.mText.back() != 'c') {
                        endToken(currToken,currWord);
                        currToken.mType = NASAL;
                    } else {
                        currToken.mType = FRIKATIV;
                    }
                    currToken.mText.append(1, currCh);
                    break;

                case 'I':
                case 'i':
                    if(currToken.mText.back() == 'Q' || currToken.mText.back() == 'q'
                    || currToken.mText.back() == 'A' || currToken.mText.back() == 'a'
                    || currToken.mText.back() == 'E' || currToken.mText.back() == 'e'
                    || currToken.mText.back() == 'O' || currToken.mText.back() == 'o') {
                        currToken.mText.append(1, currCh);
                        endToken(currToken,currWord);
                    } else {
                        endToken(currToken,currWord);
                        currToken.mType = VOKAL_G;
                        currToken.mText.append(1, currCh);
                    }
                    break;

                case 'J':
                case 'j':
                    endToken(currToken,currWord);
                    currToken.mType = HALBVOKAL;
                    currToken.mText.append(1, currCh);
                    endToken(currToken,currWord);
                    break;

                case 'K':
                case 'k':
                    currToken.mType = PLOSIV;
                    currToken.mText.append(1, currCh);
                    endToken(currToken,currWord);
                    break;

                case 'L':
                case 'l':
                    endToken(currToken,currWord);
                    currToken.mType = LIQUID;
                    currToken.mText.append(1, currCh);
                    endToken(currToken,currWord);
                    break;

                case 'M':
                case 'm':
                case 'N':
                case 'n':
                    if(currToken.mText.back() != 'E' && currToken.mText.back() != 'e'
                    && currToken.mText.back() != 'H' && currToken.mText.back() != 'h') {
                        endToken(currToken,currWord);
                    }
                    currToken.mType = NASAL;
                    currToken.mText.append(1, currCh);
                    break;

                case 'O':
                case 'o':
                    endToken(currToken,currWord);
                    currToken.mType = VOKAL_O;
                    currToken.mText.append(1, currCh);
                    break;

                case 'P':
                case 'p':
                    endToken(currToken,currWord);
                    currToken.mType = PLOSIV;
                    currToken.mText.append(1, currCh);
                    break;

                case 'Q':
                case 'q':
                    endToken(currToken,currWord);
                    currToken.mType = PLOSIV;
                    currToken.mText.append(1, currCh);
                    break;

                case 'R':
                case 'r':
                    if(currToken.mText.back() == 'e') {
                        // Schwa-a
                        currToken.mType = POT_SCHWA;
                        currToken.mText.append(1, currCh);
                    } else {
                        endToken(currToken,currWord);
                        currToken.mType = FRIKATIV;
                        currToken.mText.append(1, currCh);
                    }
                    break;

                case 'S':
                case 's':
                    if(currToken.mText.back() != 'T' && currToken.mText.back() != 't') {
                        endToken(currToken,currWord);
                    }
                    currToken.mType = FRIKATIV;
                    currToken.mText.append(1, currCh);
                    break;

                case 'T':
                case 't':
                    if(currToken.mText.back() == 'S' || currToken.mText.back() == 's') {
                        currToken.mType = FRIKATIV;
                    } else {
                        endToken(currToken,currWord);
                        currToken.mType = PLOSIV;
                    }
                    currToken.mText.append(1, currCh);
                    break;

                case 'U':
                case 'u':
                    if(currToken.mText.back() == 'Q' || currToken.mText.back() == 'q'
                    || currToken.mText.back() == 'A' || currToken.mText.back() == 'a'
                    || currToken.mText.back() == 'E' || currToken.mText.back() == 'e') {
                        currToken.mText.append(1, currCh);
                        endToken(currToken,currWord);
                    } else {
                        endToken(currToken,currWord);
                        currToken.mType = VOKAL_G;
                        currToken.mText.append(1, currCh);
                    }
                    break;

                case 'V':
                case 'v':
                case 'W':
                case 'w':
                case 'X':
                case 'x':
                    endToken(currToken,currWord);
                    currToken.mText.append(1, currCh);
                    currToken.mType = FRIKATIV;
                    break;

                case 'Y':
                case 'y':
                    currToken.mText.append(1, currCh);
                    break;

                case 'Z':
                case 'z':
                    if(currToken.mText.back() == 'T' || currToken.mText.back() == 't') {
                        currToken.mType = FRIKATIV;
                    }
                    endToken(currToken,currWord);
                    currToken.mText.append(1, currCh);
                    currToken.mType = FRIKATIV;
                    endToken(currToken,currWord);
                    break;

                case ' ':
                    if(currToken.mType == POT_SCHWA) {
                        currToken.mType = VOKAL_O;
                    }
                    endToken(currToken,currWord);
                    currToken.mType = WHITESPACE;
                    currWord.mTokens.push_back(currToken);
                    currToken.mText.erase();
                    break;

                default:
                    break;
            }
        }
        if(currToken.mType == POT_SCHWA) {
            currToken.mType = VOKAL_O;
        }
        endToken(currToken,currWord);

        return currWord;
    }

    void Tokenizer::endToken(Token &token, Word &currWord) {
        if(token.mType != WHITESPACE) {
            currWord.mTokens.push_back(token);
        }
        token.mType = WHITESPACE;
        token.mText.erase();
    }

    void Word::debugPrint() {
        for(const auto &token : this->mTokens) {
            std::cout << std::setfill('-') << std::right << std::setw(token.mType - 1) << "" << token.mText;
            if(token.mType != WHITESPACE) {
                uint8_t l = 12 - token.mText.size() - token.mType;
                std::cout << std::setw(l) << "" << sTokenTypeStr[token.mType] << "\n";
            } else {
                std::cout << "\n";
            }
            //std::cout << "[" << token.mType << "] " << token.mText << "\n";
            //std::cout << token.mText << " " << sTokenTypeStr[token.mType] << "\n";
        }
    }
}

