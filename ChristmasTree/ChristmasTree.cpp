#include "ChristmasTree.h"
#include <cassert>

AsciiChristmasTree::AsciiChristmasTree(
    int InSectionNum) :
    mSectionsNum{ InSectionNum }
{
    assert(InSectionNum >= 1);
    mHeight = InSectionNum * 3;
    mWidth = FIRST_SECTION_MAX_WIDTH + (InSectionNum - 1) * STEP_TO_SECTION + 1;
    int tableSize = (mHeight * mWidth);
    mTreeTable = new char[tableSize];
    mMiddleX = mWidth / 2;
    ConstructTree();
}

void AsciiChristmasTree::ConstructTree()
{
    mCurentHeight = 0;
    mCurrentWidth = 0;
    for (int i = 0; i < mSectionsNum; ++i)
    {
        CreateSection(i);
    }
}

void AsciiChristmasTree::CreateSection(const int InNumberOfSection)
{
    int pointToDraw = mMiddleX - 1;
    int pointToCancelDraw = 0;
    char charToDraw = ' ';
    int countToDraw = (InNumberOfSection) * STEP_TO_SECTION;
    char* ptrTable = mTreeTable + (InNumberOfSection * (mWidth * DEFAULT_SECTION_HEIGHT));
    for (int i = 0; i < DEFAULT_SECTION_HEIGHT; ++i)
    {
        pointToCancelDraw = pointToDraw + countToDraw + 1;
        for (int j = 0; j < mWidth; ++j)
        {
            if (j == pointToDraw)
            {
                charToDraw = '*';
            }
            if (j == pointToCancelDraw)
            {
                charToDraw = ' ';
            }
            *ptrTable = charToDraw;
            ++ptrTable;
        }
        --pointToDraw;
        countToDraw += 2;
        --ptrTable;
        *ptrTable = '\n';
        ++ptrTable;
    }
    --mMiddleX;
}

std::ostream& operator<<(std::ostream& os, const AsciiChristmasTree& ChristmasTree)
{
    return ChristmasTree.Print(os);
}
