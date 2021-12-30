#pragma once
#include <vector>
#include <iostream>

#define FIRST_SECTION_MAX_WIDTH 5
#define STEP_TO_SECTION 2
#define DEFAULT_SECTION_HEIGHT 3

class AsciiChristmasTree
{
public:
    explicit AsciiChristmasTree(
        int InSectionNum
    );

    ~AsciiChristmasTree()
    {
        if (mTreeTable != nullptr)
        {
            delete[] mTreeTable;
        }
    }

    std::ostream& Print(std::ostream& os) const
    {
        if (mTreeTable != nullptr)
        {
            int IndexLastChar = mHeight * mWidth;
            for (int i = 0; i < IndexLastChar; ++i)
            {
                os << mTreeTable[i];
            }
        }
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const AsciiChristmasTree& ChristmasTree);

private:
    AsciiChristmasTree(const AsciiChristmasTree& other) = delete;
    AsciiChristmasTree& operator=(const AsciiChristmasTree& other) = delete;

    void ConstructTree();
    void CreateSection(const int InNumberOfSection);

    char* mTreeTable{nullptr};

    int mHeight{ 0 };
    int mWidth{ 0 };
    int mSectionsNum{ 0 };

    int mCurentHeight{ 0 };
    int mCurrentWidth{ 0 };

    int mMiddleX{ 0 };
};

