#include "ChristmasTree.h"
#include <cassert>

AsciiChristmasTree::AsciiChristmasTree(
    int InSectionNum) :
    mSectionsNum{ InSectionNum }
{
    assert(InSectionNum >= 1);
    mHeight = InSectionNum * 3;
    mWidth = FIRST_SECTION_MAX_WIDTH + (InSectionNum - 1) * STEP_TO_SECTION;
    mTreeTable = std::make_shared<std::vector<char>>(mHeight * mWidth);
    mMiddleX = mWidth / 2;
    ConstructTree();
}

void AsciiChristmasTree::ConstructTree()
{
    mCurentHeight = 0;
    mCurrentWidth = 0;
    for (int i = 1; i <= mSectionsNum; ++i)
    {
        CreateSection(i);
    }
}

void AsciiChristmasTree::CreateSection(const int InNumberOfSection)
{
    int pointToDraw = mMiddleX;
    int pointToCancelDraw = 0;
    char charToDraw = ' ';
    int countToDraw = (InNumberOfSection - 1) * STEP_TO_SECTION;
    int triangleHeight = DEFAULT_SECTION_HEIGHT;
    for (int i = 0; i <= triangleHeight; ++i)
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
            mTreeTable->push_back(charToDraw);
        }
        --pointToDraw;
        countToDraw += 2;
        mTreeTable->push_back('\n');
    }
    mMiddleX -= 1;
}

std::ostream& operator<<(std::ostream& os, const AsciiChristmasTree& ChristmasTree)
{
    return ChristmasTree.Print(os);
}
