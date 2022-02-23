#pragma once

#include <vector>
#include <string>

namespace metrum {
    enum TokenType {
        WHITESPACE,
        PLOSIV,
        FRIKATIV,
        NASAL,
        LIQUID,
        HALBVOKAL,
        VOKAL_G,
        VOKAL_O,
        POT_SCHWA
    };

    static const char *sTokenTypeStr[] = {
        "[Whitespace]",
        "[Plosiv]",
        "[Frikativ]",
        "[Nasal]",
        "[Liquid]",
        "[Halb Vokal]",
        "[geschlosser Vokal]",
        "[offener Vokal]",
        "[vllt Schwa-a]"
    };

    class Token {
    public:
        enum TokenType mType{WHITESPACE};
        std::string mText;
    };

    class Word {
    public:
        std::vector<Token> mTokens;
        void debugPrint();
    };

    class Tokenizer {
    public:
        static Word parse(const std::string &inProgram);

    private:
        static void endToken(Token &token, Word &currWord);
    };
}