//
// Created by bence on 9/26/17.
//

#include "decipher.h"

namespace {
    class Key {
    public:
        Key(const std::string &key)
                : _idx(0), _size(key.size()), _key(key) {}

        char nextKey() {
            char newKey = static_cast<char>(toupper(_key[_idx]));
            _idx += 1;
            if(_idx >= _size)
                _idx = 0;
            return newKey;
        }

    private:
        size_t _idx;
        const size_t _size;
        const std::string _key;
    };

    char translate(char base, char c) {
        char shiftWith = base - 'A';
        bool convertToLower = false;
        if (islower(c)) {
            convertToLower = true;
            c = toupper(c);
        }
        c = c + shiftWith;
        if (c > 'Z')
            c -= 'Z' - 'A' + 1;
        if (convertToLower)
            c = tolower(c);
        return c;
    }
}

std::string decipher(const std::string &key, const std::string &codedMessage) {
    std::string message(codedMessage);
    if (key.empty())
        return message;
    Key k(key);
    for (size_t idx = 0; idx < message.size(); ++idx) {
        if (!isalpha(message[idx]))
            continue;
        char base = k.nextKey();
        message[idx] = translate(base, message[idx]);
    }
    return message;
}
