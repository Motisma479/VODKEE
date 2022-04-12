#include "ui.hpp"

void printText(Font font, const char *rawText, Vector2 position, float fontSize, float spacing, Color tint, Game &game){
    std::string modifiedText = rawText;
    // copy;
    int positionII= position.y;
    
    
    for (int i = 0; modifiedText[i] != '\0'; i++)
        {//text parameter
            if(modifiedText[i]=='<' && modifiedText[i+1]=='l' && modifiedText[i+2]=='n' && modifiedText[i+3]=='>'){
                std::string copy = modifiedText.c_str() + i+4;
                modifiedText.replace(i,modifiedText.length()-i," ");
                

                positionII+=35;
                printText(font, (const char *)copy.c_str(), (Vector2){position.x, (float)positionII}, fontSize, spacing, tint, game);
                
                
            }

            if ((modifiedText[i]=='<'))
            {
                modifiedText.replace(i,4,"\0");
            }
            if ((modifiedText[i]=='#'))
            {
                modifiedText.replace(i,modifiedText.length()-i," ");
            }
            if ((modifiedText[i]=='\n'))
            {
                modifiedText.replace(i,1," ");
            }
    }
    DrawTextEx(font, (const char *)modifiedText.c_str(), position, fontSize, spacing, tint);
    game.textFrame++;
}

Button::Button()
    : mTextureId(0),
      mRec({0, 0, 0, 0}),
      mColor(WHITE),
      mFontSize(0),
      mText(""),
      mTextColor(BLACK),
      mFontId(2147483647),

      mButtonState(0)
{
}
Button::Button(int textureID, Rectangle rec, Color buttonColor, std::string text, int fontSize, Color textColor, int font)
    : mTextureId(textureID),
      mRec(rec),
      mColor(buttonColor),

      mFontSize(fontSize),
      mText(text),
      mTextColor(textColor),
      mFontId(font),

      mButtonState(0)
{
}
Button::~Button() {}

void Button::draw(Game game)
{
    DrawTexturePro(game.getTextureById(mTextureId), {(float)(game.getTextureById(mTextureId).width / 3) * mButtonState, 0, (float)(game.getTextureById(mTextureId).width / 3), (float)game.getTextureById(mTextureId).height}, mRec, {0, 0}, 0, mColor);
    Vector2 textMeasure;
    Font font;
    if (mFontId == 2147483647)
    {
        textMeasure = MeasureTextEx(GetFontDefault(), mText.c_str(), mFontSize, 1);
        font = GetFontDefault();
    }
    else
    {
        textMeasure = MeasureTextEx(game.getFontById(mFontId), mText.c_str(), mFontSize, 1);
        font = game.getFontById(mFontId);
    }

    DrawTextPro(font, mText.c_str(), {mRec.x + mRec.width / 2 - textMeasure.x / 2, mRec.y + mRec.height / 2 - textMeasure.y / 2}, {0, 0}, 0, mFontSize, 1, mTextColor);
}
void Button::update()
{
    if (CheckCollisionPointRec(GetMousePosition(), mRec))
    {
        isHovered = true;
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            mButtonState = 2;
        }
        else
        {
            mButtonState = 1;
        }

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            isPressed = true;
        }
        else
        {
            isPressed = false;
        }
    }
    else
    {
        mButtonState = 0;
        isPressed = false;
        isHovered = false;
    }
}
void Button::changePos(int x, int y)
{
    mRec.x = x;
    mRec.y = y;
}
Vector2 Button::getPos()
{
    return {mRec.x, mRec.y};
}
Vector2 Button::getRightCorner()
{
    return {mRec.width, mRec.y};
}


Dialogue::Dialogue()
    : mTextureId(0),
      mRec({0, 0, 0, 0}),
      mColor(WHITE),
      mFontSize(0),
      mTextColor(BLACK),
      mFontId(2147483647)

{
}
Dialogue::Dialogue(int textureID, Rectangle rec, Color buttonColor, int fontSize, Color textColor, int font)
    : mTextureId(textureID),
      mRec(rec),
      mColor(buttonColor),

      mFontSize(fontSize),
      mTextColor(textColor),
      mFontId(font)
{
}
Dialogue::~Dialogue() {}

void Dialogue::draw(Game &game)
{
    DrawTexturePro(game.getTextureById(mTextureId), {(float)(game.getTextureById(mTextureId).width), 0, (float)(game.getTextureById(mTextureId).width), (float)game.getTextureById(mTextureId).height}, mRec, {0, 0}, 0, mColor);
    //DrawTextureEx(game.getTextureById(4),,0,0.35,WHITE);
    Vector2 textMeasure;
    Font font;
    if (mFontId == 2147483647)
    {
        textMeasure = MeasureTextEx(GetFontDefault(), mStoredDialogue[0].text.c_str(), mFontSize, 1);
        font = GetFontDefault();
    }
    else
    {
        textMeasure = MeasureTextEx(game.getFontById(mFontId), mStoredDialogue[0].text.c_str(), mFontSize, 1);
        font = game.getFontById(mFontId);
    }

    //DrawTextPro(font, mStoredDialogue[0].text.c_str(), {mRec.x + mRec.width / 2 - textMeasure.x / 2, mRec.y + mRec.height / 2 - textMeasure.y / 2}, {0, 0}, 0, mFontSize, 1, mTextColor);
    printText(font,TextSubtext(TextFormat("%s", game.storedDialogue[0].text.c_str()), 0, game.textFrame/5),{mRec.x +20, mRec.y + textMeasure.y / 2},mFontSize,1,mTextColor,game);
}
void Dialogue::update()
{
    if (CheckCollisionPointRec(GetMousePosition(), mRec))
    {
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            isPressed = true;
        }
        else
        {
            isPressed = false;
        }
    }
    else
    {
        isPressed = false;
    }
}
void Dialogue::initText(dialogue* storedDialogue){
    mStoredDialogue = storedDialogue;
}
void Dialogue::changePos(int x, int y)
{
    mRec.x = x;
    mRec.y = y;
}
Vector2 Dialogue::getPos()
{
    return {mRec.x, mRec.y};
}
Vector2 Dialogue::getRightCorner()
{
    return {mRec.width, mRec.y};
}
