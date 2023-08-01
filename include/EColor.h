#ifndef EColor_
#define EColor_

namespace Engine {
    /*
     * @class EColor
     * @brief Color Class
     */
    class EColor {
    public:
        EColor() noexcept;
        EColor(int red, int green, int blue, int alpha = 255) noexcept;

        int alpha() const;
        int red() const;
        int green() const;
        int blue() const;

        void setAlpha(int alpha);
        void setRed(int red);
        void setGreen(int green);
        void setBlue(int blue);
    protected:
        int r, g, b, a;
    };
}
#endif