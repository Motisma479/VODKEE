#include "common.hpp"
class Button{
    public:
        Button();
        Button(int textureID, Rectangle rec, Color buttonColor, std::string text, int fontSize, Color textColor, int font = 2147483647);
        ~Button();

        void draw(Game game);
        void update();

        void changePos(int x, int y);
        Vector2 getPos();
        Vector2 getRightCorner();

        bool isPressed = false;
        bool isHovered = false;

    private:
        int mTextureId;
        Rectangle mRec;
        Color mColor;

        int             mFontSize;
        std::string     mText;
        Color           mTextColor;
        int      mFontId;

        int mButtonState;
};
class Dialogue{
    public:
        Dialogue();
        Dialogue(int textureID, Rectangle rec, Color buttonColor, int fontSize, Color textColor, int font = 2147483647);
        ~Dialogue();

        void draw(Game &game);
        void update();

        void initText(dialogue* storedDialogue);

        void changePos(int x, int y);
        Vector2 getPos();
        Vector2 getRightCorner();

        bool isPressed = false;

    private:
        int mTextureId;
        Rectangle mRec;
        Color mColor;

        int             mFontSize;
        dialogue*       mStoredDialogue;
        Color           mTextColor;
        int      mFontId;

};