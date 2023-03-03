#pragma once

#include <cstdint>
#include <type_traits>

#define SCANCODE_TO_KEYCODE(x) (x | (1 << 30))

namespace poseidon
{
    enum class ScanCode : int32_t
    {
        Unknown = 0,

        A = 4,
        B = 5,
        C = 6,
        D = 7,
        E = 8,
        F = 9,
        G = 10,
        H = 11,
        I = 12,
        J = 13,
        K = 14,
        L = 15,
        M = 16,
        N = 17,
        O = 18,
        P = 19,
        Q = 20,
        R = 21,
        S = 22,
        T = 23,
        U = 24,
        V = 25,
        W = 26,
        X = 27,
        Y = 28,
        Z = 29,

        Alpha1 = 30,
        Alpha2 = 31,
        Alpha3 = 32,
        Alpha4 = 33,
        Alpha5 = 34,
        Alpha6 = 35,
        Alpha7 = 36,
        Alpha8 = 37,
        Alpha9 = 38,
        Alpha0 = 39,

        Return = 40,
        Escape = 41,
        Backspace = 42,
        Tab = 43,
        Space = 44,

        Minus = 45,
        Equals = 46,
        LeftBracket = 47,
        RightBracket = 48,
        Backslash = 49, 
                                           
        NonUSHash = 50,

        SemiColon = 51,
        Apostrophe = 52,
        Grave = 53, 

        Comma = 54,
        Period = 55,
        Slash = 56,

        CapsLock = 57,

        F1 = 58,
        F2 = 59,
        F3 = 60,
        F4 = 61,
        F5 = 62,
        F6 = 63,
        F7 = 64,
        F8 = 65,
        F9 = 66,
        F10 = 67,
        F11 = 68,
        F12 = 69,

        PrintScreen = 70,
        ScrollLock = 71,
        Pause = 72,
        Insert = 73, 

        Home = 74,
        PageUp = 75,
        Delete = 76,
        End = 77,
        PageDown = 78,
        Right = 79,
        Left = 80,
        Down = 81,
        Up = 82,

        NumLockClear = 83,

        KeypadDivide = 84,
        KeypadMultiply = 85,
        KeypadMinus = 86,
        KeypadPlus = 87,
        KeypadEnter = 88,
        Keypad1 = 89,
        Keypad2 = 90,
        Keypad3 = 91,
        Keypad4 = 92,
        Keypad5 = 93,
        Keypad6 = 94,
        Keypad7 = 95,
        Keypad8 = 96,
        Keypad9 = 97,
        Keypad0 = 98,
        KeypadPeriod = 99,

        NonUSBackslash = 100,

        Application = 101,
        Power = 102,

        KeypadEquals = 103,
        F13 = 104,
        F14 = 105,
        F15 = 106,
        F16 = 107,
        F17 = 108,
        F18 = 109,
        F19 = 110,
        F20 = 111,
        F21 = 112,
        F22 = 113,
        F23 = 114,
        F24 = 115,
        Execute = 116,
        Help = 117,
        Menu = 118,
        Select = 119,
        Stop = 120,
        Again = 121,
        Undo = 122,
        Cut = 123,
        Copy = 124,
        Paste = 125,
        Find = 126,
        Mute = 127,
        VolumeUp = 128,
        VolumeDown = 129,
        KeypadComma = 133,
        KeypadEqualsAs400 = 134,

        International1 = 135,
        International2 = 136,
        International3 = 137,
        International4 = 138,
        International5 = 139,
        International6 = 140,
        International7 = 141,
        International8 = 142,
        International9 = 143,
        Language1 = 144,
        Language2 = 145,
        Language3 = 146,
        Language4 = 147,
        Language5 = 148,
        Language6 = 149,
        Language7 = 150,
        Language8 = 151,
        Language9 = 152,

        AltErase = 153,
        SysReq = 154,
        Cancel = 155,
        Clear = 156,
        Prior = 157,
        Return2 = 158,
        Separator = 159,
        Out = 160,
        Oper = 161,
        ClearAgain = 162,
        CRSel = 163,
        EXSel = 164,

        Keypad00 = 176,
        Keypad000 = 177,
        ThousandsSeparator = 178,
        DecimalSeparator = 179,
        CurrencyUnit = 180,
        CurrencySubUnit = 181,
        KeypadLeftParen = 182,
        KeypadRightParen = 183,
        KeypadLeftBrace = 184,
        KeypadRightBrace = 185,
        KeypadTab = 186,
        KeypadBackspace = 187,
        KeypadA = 188,
        KeypadB = 189,
        KeypadC = 190,
        KeypadD = 191,
        KeypadE = 192,
        KeypadF = 193,
        KeypadXOR = 194,
        KeypadPower = 195,
        KeypadPercent = 196,
        KeypadLess = 197,
        KeypadGreater = 198,
        KeypadAmpersand = 199,
        KeypadDoubleAmpersand = 200,
        KeypadVerticalBar = 201,
        KeypadDoubleVerticalBar = 202,
        KeypadColon = 203,
        KeypadHash = 204,
        KeypadSpace = 205,
        KeypadAt = 206,
        KeypadExclaim = 207,
        KeypadMemStore = 208,
        KeypadMemRecall = 209,
        KeypadMemClear = 210,
        KeypadMemAdd = 211,
        KeypadMemSubtract = 212,
        KeypadMemMultiply = 213,
        KeypadMemDivide= 214,
        KeypadPlusMinus = 215,
        KeypadClear = 216,
        KeypadClearEntry = 217,
        KeypadBinary = 218,
        KeypadOctal = 219,
        KeypadDecimal = 220,
        KeypadHexadecimal = 221,

        LeftCtrl = 224,
        LeftShift = 225,
        LeftAlt = 226,
        LeftGUI = 227,
        RightCtrl = 228,
        RightShift = 229,
        RightAlt = 230,
        RightGUI = 231,

        Mode = 257,    

        AudioNext = 258,
        AudioPrev = 259,
        AudioStop = 260,
        AudioPlay = 261,
        AudioMute = 262,
        MediaSelect = 263,
        WWW = 264,
        Mail = 265,
        Calculator = 266,
        Computer = 267,
        ApplicationControlSearch = 268,
        ApplicationControlHome = 269,
        ApplicationControlBack= 270,
        ApplicationControlForward = 271,
        ApplicationControlStop = 272,
        ApplicationControlRefresh= 273,
        ApplicationControlBookmarks = 274,

        BrightnessDown = 275,
        BrightnessUp = 276,
        DisplaySwitch= 277,

        KeyboardIlluminationToggle = 278,
        KeyboardIlluminationDown = 279,
        KeyboardIlluminationUp = 280,
        Eject = 281,
        Sleep = 282,

        App1 = 283,
        App2 = 284,

        AudioRewind = 285,
        AudioFastForward = 286,

        SoftLeft = 287,
        SoftRight = 288,
        Call = 289,
        EndCall = 290
    };

    enum class KeyCode : uint32_t
    {
        Unknown = 0,

        Return = '\r',
        Escape = '\x1B',
        Backspace = '\b',
        Tab = '\t',
        Space = ' ',
        Exclaim = '!',
        DoubleQuote = '"',
        Hash = '#',
        Percent = '%',
        Dollar = '$',
        Ampersand = '&',
        Quote = '\'',
        LeftParen = '(',
        RightParen = ')',
        Asterisk = '*',
        Plus = '+',
        Comma = ',',
        Minus = '-',
        Period = '.',
        Slash = '/',
        Alpha0 = '0',
        Alpha1 = '1',
        Alpha2 = '2',
        Alpha3 = '3',
        Alpha4 = '4',
        Alpha5 = '5',
        Alpha6 = '6',
        Alpha7 = '7',
        Alpha8 = '8',
        Alpha9 = '9',
        Colon = ':',
        SemiColon = ';',
        Less = '<',
        Equals = '=',
        Greater = '>',
        Question = '?',
        At = '@',

        LeftBracket = '[',
        Backslash = '\\',
        RightBracket = ']',
        Caret = '^',
        Underscore = '_',
        BackQuote = '`',
        a = 'a',
        b = 'b',
        c = 'c',
        d = 'd',
        e = 'e',
        f = 'f',
        g = 'g',
        h = 'h',
        i = 'i',
        j = 'j',
        k = 'k',
        l = 'l',
        m = 'm',
        n = 'n',
        o = 'o',
        p = 'p',
        q = 'q',
        r = 'r',
        s = 's',
        t = 't',
        u = 'u',
        v = 'v',
        w = 'w',
        x = 'x',
        y = 'y',
        z = 'z',

        CapsLock = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::CapsLock)),

        F1 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F1)),
        F2 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F2)),
        F3 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F3)),
        F4 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F4)),
        F5 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F5)),
        F6 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F6)),
        F7 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F7)),
        F8 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F8)),
        F9 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F9)),
        F10 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F10)),
        F11 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F11)),
        F12 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F12)),

        PrintScreen = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::PrintScreen)),
        ScrollLock = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ScrollLock)),
        Pause = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Pause)),
        Insert = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Insert)),
        Home = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Home)),
        PageUp = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::PageUp)),
        Delete = '\x7F',
        End = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::End)),
        PageDown = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::PageDown)),
        Right = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Right)),
        Left = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Left)),
        Down = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Down)),
        Up = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Up)),

        NumLockClear = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::NumLockClear)),
        KeypadDivide = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadDivide)),
        KeypadMultiply = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMultiply)),
        KeypadMinus = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMinus)),
        KeypadPlus = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadPlus)),
        KeypadEnter = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadEnter)),
        Keypad1 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad1)),
        Keypad2 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad2)),
        Keypad3 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad3)),
        Keypad4 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad4)),
        Keypad5 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad5)),
        Keypad6 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad6)),
        Keypad7 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad7)),
        Keypad8 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad8)),
        Keypad9 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad9)),
        Keypad0 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad0)),
        KeypadPeriod = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadPeriod)),

        Application = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Application)),
        Power = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Power)),
        KeypadEquals = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadEquals)),
        F13 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F13)),
        F14 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F14)),
        F15 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F15)),
        F16 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F16)),
        F17 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F17)),
        F18 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F18)),
        F19 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F19)),
        F20 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F20)),
        F21 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F21)),
        F22 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F22)),
        F23 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F23)),
        F24 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::F24)),
        Execute = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Execute)),
        Help = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Help)),
        Menu = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Menu)),
        Select = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Select)),
        Stop = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Stop)),
        Again = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Again)),
        Undo = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Undo)),
        Cut = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Cut)),
        Copy = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Copy)),
        Paste = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Paste)),
        Find = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Find)),
        Mute = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Mute)),
        VolumeUp = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::VolumeUp)),
        VolumeDown = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::VolumeDown)),
        KeypadComma = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadComma)),
        KeypadEqualsAs400 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadEqualsAs400)),

        AltErase = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AltErase)),
        SysReq = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::SysReq)),
        Cancel = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Cancel)),
        Clear = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Clear)),
        Prior = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Prior)),
        Return2 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Return2)),
        Separator = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Separator)),
        Out = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Out)),
        Oper = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Oper)),
        ClearAgain = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ClearAgain)),
        CRSel = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::CRSel)),
        EXSel = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::EXSel)),

        Keypad00 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad00)),
        Keypad000 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Keypad000)),
        ThousandsSeparator = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ThousandsSeparator)),
        DecimalSeparator = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::DecimalSeparator)),
        CurrencyUnit = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::CurrencyUnit)),
        CurrencySubUnit = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::CurrencySubUnit)),
        KeypadLeftParen = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadLeftParen)),
        KeypadRightParen = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadRightParen)),
        KeypadLeftBrace = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadLeftBrace)),
        KeypadRightBrace = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadRightBrace)),
        KeypadTab = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadTab)),
        KeypadBackspace = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadBackspace)),
        KeypadA = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadA)),
        KeypadB = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadB)),
        KeypadC = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadC)),
        KeypadD = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadD)),
        KeypadE = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadE)),
        KeypadF = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadF)),
        KeypadXOR = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadXOR)),
        KeypadPower = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadPower)),
        KeypadPercent = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadPercent)),
        KeypadLess = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadLess)),
        KeypadGreater = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadGreater)),
        KeypadAmpersand = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadAmpersand)),
        KeypadDoubleAmpersand = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadDoubleAmpersand)),
        KeypadVerticalBar = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadVerticalBar)),
        KeypadDoubleVerticalBar = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadDoubleVerticalBar)),
        KeypadColon = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadColon)),
        KeypadHash = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadHash)),
        KeypadSpace = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadSpace)),
        KeypadAt = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadAt)),
        KeypadExclaim = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadExclaim)),
        KeypadMemStore = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMemStore)),
        KeypadMemRecall = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMemRecall)),
        KeypadMemClear = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMemClear)),
        KeypadMemAdd = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMemAdd)),
        KeypadMemSubtract = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMemSubtract)),
        KeypadMemMultiply = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMemMultiply)),
        KeypadMemDivide = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadMemDivide)),
        KeypadPlusMinus = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadPlusMinus)),
        KeypadClear = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadClear)),
        KeypadClearEntry = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadClearEntry)),
        KeypadBinary = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadBinary)),
        KeypadOctal = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadOctal)),
        KeypadDecimal = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadDecimal)),
        KeypadHexadecimal = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeypadHexadecimal)),

        LeftCtrl = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::LeftCtrl)),
        LeftShift = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::LeftShift)),
        LeftAlt = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::LeftAlt)),
        LeftGUI = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::LeftGUI)),
        RightCtrl = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::RightCtrl)),
        RightShift = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::RightShift)),
        RightAlt = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::RightAlt)),
        RightGUI = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::RightGUI)),

        Mode = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Mode)),

        AudioNext = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AudioNext)),
        AudioPrev = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AudioPrev)),
        AudioStop = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AudioStop)),
        AudioPlay = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AudioPlay)),
        AudioMute = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AudioMute)),
        MediaSelect = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::MediaSelect)),
        WWW = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::WWW)),
        Mail = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Mail)),
        Calculator = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Calculator)),
        Computer = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Computer)),
        ApplicationControlSearch = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ApplicationControlSearch)),
        ApplicationControlHome = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ApplicationControlHome)),
        ApplicationControlBack = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ApplicationControlBack)),
        ApplicationControlForward = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ApplicationControlForward)),
        ApplicationControlStop = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ApplicationControlStop)),
        ApplicationControlRefresh = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ApplicationControlRefresh)),
        ApplicationControlBookmarks = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::ApplicationControlBookmarks)),

        BrightnessDown = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::BrightnessDown)),
        BrightnessUp = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::BrightnessUp)),
        DisplaySwitch = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::DisplaySwitch)),
        KeyboardIlluminationToggle = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeyboardIlluminationToggle)),
        KeyboardIlluminationDown = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeyboardIlluminationDown)),
        KeyboardIlluminationUp = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::KeyboardIlluminationUp)),
        Eject = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Eject)),
        Sleep = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Sleep)),
        App1 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::App1)),
        App2 = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::App2)),

        AudioRewind = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AudioRewind)),
        AudioFastForward = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::AudioFastForward)),

        SoftLeft = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::SoftLeft)),
        SoftRight = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::SoftRight)),
        Call = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::Call)),
        EndCall = SCANCODE_TO_KEYCODE(static_cast<std::underlying_type<ScanCode>::type>(ScanCode::EndCall))
    };

    enum class KeyModifiers : uint16_t
    {
        None        = 0x0000,
        LeftShift   = 0x0001,
        RightShift  = 0x0002,
        LeftCtrl    = 0x0040,
        RightCtrl   = 0x0080,
        LeftAlt     = 0x0100,
        RightAlt    = 0x0200,
        LeftGUI     = 0x0400,
        RightGUI    = 0x0800,
        Num         = 0x1000,
        Caps        = 0x2000,
        Mode        = 0x4000,
        Scroll      = 0x8000,

        Ctrl = LeftCtrl | RightCtrl,
        Shift = LeftShift | RightShift,
        Alt = LeftAlt | RightAlt,
        GUI = LeftGUI | RightGUI,

        Reserved = Scroll
    };

    KeyModifiers operator|(KeyModifiers lhs, KeyModifiers rhs);
    KeyModifiers operator&(KeyModifiers lhs, KeyModifiers rhs);
}