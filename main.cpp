#include <iostream>
#include <string>

class VietnameseLetterCounter {
private:
    static bool isVietnameseLetter(char firstChar, char secondChar) 
     {
        std::string twoChars = {firstChar, secondChar};
        switch (twoChars[0]) 
        {
            case 'a':
                return twoChars == "aw" || twoChars == "aa";
            case 'd':
                return twoChars == "dd";
            case 'e':
                return twoChars == "ee";
            case 'o':
                return twoChars == "oo" || twoChars == "ow";
            default:
                return false;
        }
     }
public:
    static int countVietnameseLetters(const std::string& input) {
        int count = 0;
        int i = 0;
        int len = input.length();
        while (i < len) {
            if (i + 1 < len) 
            {
                char firstChar = input[i];
                char secondChar = input[i + 1];
                if (isVietnameseLetter(firstChar, secondChar))
                {
                    count++; 
                    i += 2; 
                } 
                else 
                {
                    if (input[i] == 'w')
                    {
                      count++;
                    }
                    i++; 
                }
            } 
            else 
            {
                if (input[i] == 'w')
                    {
                      count++;
                    }
                i++; 
            }
        }
        return count;
    }
};

int main()
{
    std::string input = "hfdawhwhcoomddw";
    int vietnameseLetterCount = VietnameseLetterCounter::countVietnameseLetters(input);
    std::cout << "Số lượng chữ cái Tiếng Việt có thể được tạo thành: " << vietnameseLetterCount << std::endl;
    return 0;
}
