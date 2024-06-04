/*
  ==============================================================================

	Styles.h
	Created: 28 Feb 2024 1:05:17pm
	Author:  Personal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

// These are all of our style constants. This includes colours, measurements, corner radius' and so on.
// It also includes all of the custom LookAndFeels used in the project.

// Reference available in the report. [3]
// https://stackoverflow.com/a/12043198/13142325

// MARK: Style Constants
// Main styles.
const int STYLE_SIZE_BAR_HEIGHT = 28;
const float STYLE_SIZE_TEXT_PRIMARY = 12.0f;
const float STYLE_RADIUS_PRIMARY = 6.0f;
const float STYLE_RADIUS_SECONDARY = 8.0f;
const juce::Colour STYLE_COLOR_BACKING_PRIMARY = juce::Colour(2, 2, 2);
const juce::Colour STYLE_COLOR_BACKING_SECONDARY = juce::Colour(99, 73, 61);
const juce::Colour STYLE_COLOR_BACKING_TERTIARY = juce::Colour(16, 16, 16);
const juce::Colour STYLE_COLOR_DIVIDER_PRIMARY = juce::Colour(34, 34, 34);

// Raised styles.
const juce::Colour STYLE_COLOR_RAISED_FACE = juce::Colour(118, 93, 85);
const juce::Colour STYLE_COLOR_RAISED_CLICK = juce::Colour(102, 77, 69);
const juce::Colour STYLE_COLOR_RAISED_TEXT = juce::Colour(232, 232, 232);
const juce::Colour STYLE_COLOR_RAISED_PLACEHOLDER = juce::Colour(175, 162, 158);
const juce::Colour STYLE_COLOR_RAISED_BORDER = juce::Colour(69, 62, 55);

// Flat styles.
const float STYLE_SIZE_FLAT_BUTTON = 32.0f;
const juce::Colour STYLE_COLOR_FLAT_TEXT = juce::Colour(69, 69, 69);

// Slider styles.
const juce::Colour STYLE_COLOR_SLIDER_BORDER = juce::Colour(78, 78, 78);
const juce::Colour STYLE_COLOR_SLIDER_BACKING = juce::Colour(29, 29, 29);
const juce::Colour STYLE_COLOR_SLIDER_UNI_PRIMARY = juce::Colour(166, 188, 233);
const juce::Colour STYLE_COLOR_SLIDER_UNI_SECONDARY = juce::Colour(107, 125, 161);
const juce::Colour STYLE_COLOR_SLIDER_BI_PRIMARY = juce::Colour(213, 58, 62);
const juce::Colour STYLE_COLOR_SLIDER_BI_SECONDARY = juce::Colour(70, 70, 70);
const juce::Colour STYLE_COLOR_SLIDER_BI_TERTIARY = juce::Colour(36, 36, 36);

// Tables styles.
const juce::Colour STYLE_COLOR_TABLES_DIVIDER = juce::Colour(60, 60, 60);
const juce::Colour STYLE_COLOR_DECK_FACE_PRIMARY = juce::Colour(juce::uint8(255), juce::uint8(255), juce::uint8(255), 0.75f);
const int STYLE_DECK_PADDING_PRIMARY = 18;

// Song library styles.
const int STYLE_SIZE_LIBRARY_MARGIN = 18;
const int STYLE_SIZE_LIBRARY_ITEM_HEIGHT = 36;
const juce::Colour STYLE_COLOR_LIBRARY_BACKING_BAR = juce::Colour(90, 67, 56);
const juce::Colour STYLE_COLOR_LIBRARY_DIVIDER_BAR = juce::Colour(78, 60, 52);
const juce::Colour STYLE_COLOR_LIBRARY_TEXT_BAR = juce::Colour(214, 208, 205);
const juce::Colour STYLE_COLOR_LIBRARY_TEXT_ITEM = juce::Colour(255, 255, 255);
const juce::Colour STYLE_COLOR_LIBRARY_BACKING_ITEM_PRIMARY = juce::Colour(99, 74, 62);
const juce::Colour STYLE_COLOR_LIBRARY_BACKING_ITEM_SECONDARY = juce::Colour(111, 83, 70);

// MARK: Fonts
// Font styles.
struct CustomFonts {
public:
    static juce::Font fontLabel(std::string family, std::string style, float labelSize)
    {
        juce::Font font { family, labelSize, juce::Font::plain };
        font.setTypefaceStyle(style);
        font.setExtraKerningFactor(0.04f);
        return font;
    };

    static juce::Font fontSFProRegular(float labelSize)
    {
        juce::Font font { "SF Pro", labelSize, juce::Font::plain };
        font.setTypefaceStyle("Light");
        font.setExtraKerningFactor(0.04f);
        return font;
    };

    static juce::Font fontSFProMedium(float labelSize)
    {
        juce::Font font { "SF Pro", labelSize, juce::Font::plain };
        font.setTypefaceStyle("Regular");
        font.setExtraKerningFactor(0.04f);
        return font;
    };

    static juce::Font fontSFProBold(float labelSize)
    {
        juce::Font font { "SF Pro", labelSize, juce::Font::plain };
        font.setTypefaceStyle("Medium");
        font.setExtraKerningFactor(0.04f);
        return font;
    };
};

// MARK: Custom LookAndFeels
// Table styles.
struct LibraryTableLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawTableHeaderColumn(juce::Graphics& g, juce::TableHeaderComponent& table, const juce::String& columnName, int columnId, int width, int height, bool isMouseOver, bool isMouseDown, int columnFlags) override
    {
        // Draw the text for a column.
        g.setColour(STYLE_COLOR_LIBRARY_TEXT_BAR);
        g.setFont(CustomFonts::fontSFProRegular(15));
        g.drawText(columnName, STYLE_SIZE_LIBRARY_MARGIN, 0, width, height, juce::Justification::left);
    }

    void drawTableHeaderBackground(juce::Graphics& g, juce::TableHeaderComponent& table) override
    {
        // Draw the backing.
        g.fillAll(STYLE_COLOR_LIBRARY_BACKING_BAR);

        // Get the measurements of the table.
        int x = table.getX();
        int y = table.getY();
        int width = table.getWidth();
        int height = table.getHeight();

        // Draw the outline.
        g.setColour(STYLE_COLOR_LIBRARY_DIVIDER_BAR);
        g.drawLine(x, y, width, y, 2.0f);
        g.drawLine(x, y + height, width, y + height, 2.0f);
    }
};

struct DecksTableLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawTableHeaderColumn(juce::Graphics& g, juce::TableHeaderComponent& table, const juce::String& columnName, int columnId, int width, int height, bool isMouseOver, bool isMouseDown, int columnFlags) override
    {
        // Draw the text for a column.
        g.setColour(juce::Colour(juce::uint8(255), juce::uint8(255), juce::uint8(255), 0.6f));
        g.setFont(CustomFonts::fontSFProRegular(15));
        g.drawText(columnName, STYLE_SIZE_LIBRARY_MARGIN, 0, width, height, juce::Justification::left);
    }

    void drawTableHeaderBackground(juce::Graphics& g, juce::TableHeaderComponent& table) override
    {
        // Draw the backing.
        g.fillAll(STYLE_COLOR_BACKING_TERTIARY);

        // Get the measurements of the table.
        int x = table.getX();
        int y = table.getY();
        int width = table.getWidth();
        int height = table.getHeight();

        // Draw the outline.
        g.setColour(STYLE_COLOR_DIVIDER_PRIMARY);
        g.drawLine(x, y, width, y, 2.0f);
        g.drawLine(x, y + height, width, y + height, 2.0f);
    }
};

// Slider styles.
struct SliderUniLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawLinearSlider(juce::Graphics& g, int xRaw, int yRaw, int widthRaw, int heightRaw, float sliderPos, float minSliderPos, float maxSliderPos, juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override
    {
        int x = xRaw + 1;
        int y = yRaw + 1;
        int width = widthRaw - 2;
        int height = heightRaw - 2;

        // Draw slider backing.
        g.setColour(STYLE_COLOR_SLIDER_BACKING);
        g.fillRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY);

        // Draw slider fill.
        int fillBorder = 2;
        float fillWidth = (float(slider.getValue()) / 10.0f) * float(width);
        // We need to save the state of the graphics object because we're
        // applying a clip.
        g.saveState();
        g.setColour(STYLE_COLOR_SLIDER_UNI_PRIMARY);
        g.reduceClipRegion(x + fillBorder, y + fillBorder, width - (fillBorder * 2), height - (fillBorder * 2));
        g.fillRect(float(x), float(y), fillWidth, float(height));
        g.restoreState();

        // Draw slider fill border.
        g.setColour(STYLE_COLOR_SLIDER_BACKING);
        g.drawRoundedRectangle(float(x) + 1, float(y) + 1, float(width) - 2, float(height) - 2, STYLE_RADIUS_SECONDARY, 3.0f);

        // Draw slider border.
        g.setColour(STYLE_COLOR_SLIDER_BORDER);
        g.drawRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY, 1.0f);
    }
};

struct SliderUniProgressLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawLinearSlider(juce::Graphics& g, int xRaw, int yRaw, int widthRaw, int heightRaw, float sliderPos, float minSliderPos, float maxSliderPos, juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override
    {
        int x = xRaw + 1;
        int y = yRaw + 1;
        int width = widthRaw - 2;
        int height = heightRaw - 2;

        // Draw slider backing.
        g.setColour(STYLE_COLOR_SLIDER_BACKING);
        g.fillRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY);

        // Draw slider fill.
        int sliderPosition = x + ((slider.getValue() / 10.0f) * (width - 3)) + 1;
        // We need to save the state of the graphics object because we're
        // applying a clip.
        g.saveState();
        // This allows us to clip the vertical line to a rounded rectangle path.
        juce::Path path;
        path.addRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY);
        g.reduceClipRegion(path);

        // Draw value chaser.
        g.setColour(STYLE_COLOR_SLIDER_BI_TERTIARY);
        g.drawLine(x, height / 2, sliderPosition, height / 2, height);

        // Draw value marker.
        if (slider.getValue() != 0.0f) {
            g.setColour(STYLE_COLOR_SLIDER_BI_PRIMARY);
            g.fillRect(sliderPosition, y, 1, height);
        }

        // Restores the pre-clipped state so we can draw the border.
        g.restoreState();

        // Draw slider border.
        g.setColour(STYLE_COLOR_SLIDER_BORDER);
        g.drawRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY, 1.0f);
    }
};

struct SliderBiLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawLinearSlider(juce::Graphics& g, int xRaw, int yRaw, int widthRaw, int heightRaw, float sliderPos, float minSliderPos, float maxSliderPos, juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override
    {
        int x = xRaw + 1;
        int y = yRaw + 1;
        int width = widthRaw - 2;
        int height = heightRaw - 2;

        // Draw slider backing.
        g.setColour(STYLE_COLOR_SLIDER_BACKING);
        g.fillRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY);

        // Draw slider fill.
        int sliderPosition = x + ((slider.getValue() / 10.0f) * (width - 3)) + 1;
        int sliderMiddle = x + (width / 2);
        // We need to save the state of the graphics object because we're
        // applying a clip.
        g.saveState();
        // This allows us to clip the vertical line to a rounded rectangle path.
        juce::Path path;
        path.addRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY);
        g.reduceClipRegion(path);

        // Draw value chaser.
        g.setColour(STYLE_COLOR_SLIDER_BI_TERTIARY);
        g.drawLine(sliderMiddle, height / 2, sliderPosition, height / 2, height);

        // Draw slider middle marker.
        g.setColour(STYLE_COLOR_SLIDER_BI_SECONDARY);
        g.fillRect(sliderMiddle, y, 1, height);

        // Draw value marker.
        g.setColour(STYLE_COLOR_SLIDER_BI_PRIMARY);
        g.fillRect(sliderPosition, y, 1, height);

        // Restores the pre-clipped state so we can draw the border.
        g.restoreState();

        // Draw slider border.
        g.setColour(STYLE_COLOR_SLIDER_BORDER);
        g.drawRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY, 1.0f);
    }
};

struct SliderBiVerticalLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawLinearSlider(juce::Graphics& g, int xRaw, int yRaw, int widthRaw, int heightRaw, float sliderPos, float minSliderPos, float maxSliderPos, juce::Slider::SliderStyle sliderStyle, juce::Slider& slider) override
    {
        int x = xRaw + 1;
        int y = yRaw + 1;
        int width = widthRaw - 2;
        int height = heightRaw - 2;

        // Draw slider backing.
        g.setColour(STYLE_COLOR_SLIDER_BACKING);
        g.fillRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY);

        // Draw slider fill.
        int sliderPosition = (y + height) - ((slider.getValue() / 10.0f) * (height - 3)) - 2;
        int sliderMiddle = y + (height / 2);
        // We need to save the state of the graphics object because we're
        // applying a clip.
        g.saveState();
        // This allows us to clip the vertical line to a rounded rectangle path.
        juce::Path path;
        path.addRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY);
        g.reduceClipRegion(path);

        // Draw value chaser.
        g.setColour(STYLE_COLOR_SLIDER_BI_TERTIARY);
        g.drawLine(width / 2, sliderMiddle, width / 2, sliderPosition, width);

        // Draw slider middle marker.
        g.setColour(STYLE_COLOR_SLIDER_BI_SECONDARY);
        g.fillRect(x, sliderMiddle, width, 1);

        // Draw value marker.
        g.setColour(STYLE_COLOR_SLIDER_BI_PRIMARY);
        g.fillRect(x, sliderPosition, width, 1);

        // Restores the pre-clipped state so we can draw the border.
        g.restoreState();

        // Draw slider border.
        g.setColour(STYLE_COLOR_SLIDER_BORDER);
        g.drawRoundedRectangle(x, y, width, height, STYLE_RADIUS_SECONDARY, 1.0f);
    }
};

// Text editor styles.
struct SearchLookAndFeel : public juce::LookAndFeel_V4 {
public:
    void drawTextEditorOutline(juce::Graphics& g, int width, int height, juce::TextEditor& textEditor) override
    {
    }

    void fillTextEditorBackground(juce::Graphics& g, int width, int height, juce::TextEditor& textEditor) override
    {
        // Draw the text editor's background.
        g.fillAll(STYLE_COLOR_RAISED_FACE);

        // Draw the text editor's placeholder.
        if (textEditor.hasKeyboardFocus(true) == false && textEditor.isEmpty()) {
            g.setColour(STYLE_COLOR_RAISED_PLACEHOLDER);
            g.setFont(CustomFonts::fontSFProMedium(15));
            g.drawText("Search", 3, textEditor.getY() - 1, width, height, juce::Justification::left);
        }
    }
};

// Button styles.
struct RaisedLookAndFeel : public juce::LookAndFeel_V4 {
public:
    juce::Font getTextButtonFont(juce::TextButton&, int buttonHeight) override
    {
        juce::Font font = CustomFonts::fontLabel("SF Pro", "Regular", 15);
        return font;
    }

    void drawButtonBackground(juce::Graphics& g, juce::Button& button, const juce::Colour& backgroundColour, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        int width = button.getWidth();
        int height = button.getHeight();

        // Draw the text editor's outline.
        g.setColour(STYLE_COLOR_RAISED_BORDER);
        g.fillRoundedRectangle(button.getX(), button.getY(), width, height, STYLE_RADIUS_PRIMARY);

        // Set the draw color based on the click state.
        if (shouldDrawButtonAsDown) {
            g.setColour(STYLE_COLOR_RAISED_CLICK);
        } else {
            g.setColour(STYLE_COLOR_RAISED_FACE);
        }

        // Draw the text editor's background.
        g.fillRoundedRectangle(button.getX() + 1, button.getY() + 1, width - 2, height - 2, STYLE_RADIUS_PRIMARY - 0.5f);

        // Draw the button hover state.
        if (shouldDrawButtonAsHighlighted) {
            // Reference available in the report. [6]
            // https://forum.juce.com/t/changing-the-mouse-cursor-on-os-x/6981
            button.setMouseCursor(juce::MouseCursor::PointingHandCursor);
        }
    }
};

// MARK: Button Font Styles
// Reference available in the report. [5]
// https://forum.juce.com/t/changing-font-and-font-sizes-of-buttons-and-texteditors/20761/4
struct SFProRegularLookAndFeel : public juce::LookAndFeel_V4 {
public:
    juce::Font getTextButtonFont(juce::TextButton& button, int buttonHeight) override
    {
        // It states Light here but this is just to compensate for JUCE's fuzz around font renders.
        juce::Font font = CustomFonts::fontLabel("SF Pro", "Light", 15);
        return font;
    };
};

struct SFProMediumLookAndFeel : public juce::LookAndFeel_V4 {
public:
    juce::Font getTextButtonFont(juce::TextButton& button, int buttonHeight) override
    {
        // It states Regular here but this is just to compensate for JUCE's fuzz around font renders.
        juce::Font font = CustomFonts::fontLabel("SF Pro", "Regular", 15);
        return font;
    };
};

struct SFProBoldLookAndFeel : public juce::LookAndFeel_V4 {
public:
    juce::Font getTextButtonFont(juce::TextButton& button, int buttonHeight) override
    {
        // It states Medium here but this is just to compensate for JUCE's fuzz around font renders.
        juce::Font font = CustomFonts::fontLabel("SF Pro", "Medium", 15);
        return font;
    };
};
