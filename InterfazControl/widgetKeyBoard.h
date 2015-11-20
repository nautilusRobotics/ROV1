/***************************************************************************
 *   Copyright (C) 2008 by Giovanni Romano                                 *
 *   Giovanni.Romano.76@gmail.com                                          *
 *                                                                         *
 *   This program may be distributed under the terms of the Q Public       *
 *   License as defined by Trolltech AS of Norway and appearing in the     *
 *   file LICENSE.QPL included in the packaging of this file.              *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                  *
 ***************************************************************************/


#ifndef _WIDGETKEYBOARD_H

//#define DEFAULT_BACKGROUND_BUTTON	"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #8C8F8C, stop: 1 #000000);"
//#define CHANGED_BACKGROUND_BUTTON	"background:lightgray;color:darkred;"
//#define DEFAULT_BACKGROUND_BUTTON	"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);"
//#define CHANGED_BACKGROUND_BUTTON	"background:lightblue;"

#define DEFAULT_STYLE_BUTTON            "color:black;border: 2px solid #8C8F8C;border-radius:6px;"
//#define DEFAULT_STYLE_BUTTON          "border: 1px solid #8f8f91;border-radius:5px;"
#define STYLE_FOCUS_TEXT                "border: 1px solid black"

//#define DEFAULT_STYLE_BUTTON		"color:white;border: 2px solid black;border-radius:5px;font-weight: bold;font-size:17px;"
#define DEFAULT_BACKGROUND_BUTTON	"background:lightgray;"
#define CHANGED_BACKGROUND_BUTTON	"background:lightgray;"

#define EMBEDDED_KEYBOARD               "font-size:20px"
#define WIDTH_ZOOM_KEY                  20
#define HEIGHT_ZOOM_KEY                 WIDTH_ZOOM_KEY
#define ZOOMED_WIDGET_STYLESHEET    "border-radius:8px;font:bold 16px;color:black;"
//
// tasti speciali utilizzati all'interno delle classi:
#define KEY_TAB                         tr("")
#define KEY_ALT                         tr("")
#define KEY_CAPS                        tr("MAYUS")
#define KEY_CLEAR_ALL                   tr("Clear All")
#define KEY_CUT_LEFT                    tr("")
#define KEY_COPY                        tr("")
#define KEY_PASTE                       tr("")
#define KEY_BACKSPACE                   tr("Backspace")
#define KEY_BACKSPACE_EMBEDDED          tr("Backspace")
#define KEY_HIDECHAR                    tr("")
#define KEY_HIDECHAR_EMBEDDED           tr("")
#define KEY_CANC                        tr("Cancel")
#define KEY_RETURN                      tr("Enter")
#define KEY_SPACE                       " "
#define KEY_WIDTH_EMBEDDED              78
#define KEY_HEIGHT_EMBEDDED             66
//
// macro parametrizzate per la riduzione del codice:
#define IS_KEY(keyTextPressed, keyValCompare)   (keyTextPressed).contains((keyValCompare), Qt::CaseInsensitive)


#define IS_CAPS(text)                   IS_KEY(text, KEY_CAPS)
#define IS_CLEAR_ALL(text)              IS_KEY(text, KEY_CLEAR_ALL)
#define IS_BACK(text)                   IS_KEY(text, KEY_BACKSPACE)
#define IS_BACK_EMB(text)               IS_KEY(text, KEY_BACKSPACE_EMBEDDED)
#define IS_CANC(text)                   IS_KEY(text, KEY_CANC)
#define IS_RETURN(text)                 IS_KEY(text, KEY_RETURN)
#define IS_SPACE(text)                  IS_KEY(text, KEY_SPACE)

	
    #define _WIDGETKEYBOARD_H

    #include "joystickwidget.h"
    #include <QSound>
    #include <QLineEdit>
    #include <QClipboard>
    #include <QLabel>
    #include <QDebug>

    //
    //
    // classe che crea e controlla la tastiera:
    class widgetKeyBoard : public QWidget {
        Q_OBJECT

        public:
            widgetKeyBoard(bool embeddedKeyboard = false, QWidget *activeForm = NULL, QWidget *parent = NULL);
            ~widgetKeyBoard();

            void            createKeyboard(void);
            bool            isEmbeddedKeyboard(void);
            void            soundClick(void);
            void            setZoomFacility(bool active); // only valid for embedded keyboard
            bool            isZoomFacilityEnable(void);
            bool            statusEchoMode(void){return (this->m_echoMode);}
            void            setStatusEchoMode(bool echo) {this->m_echoMode = echo; }
            void            receiptChildKey(QString key, QLineEdit *focusThisControl, bool reset = false); // accoglie i tasti premuti
            QLineEdit *     currentTextBox(void) { return (this->m_currentTextBox);}
            void            switchKeyEchoMode(QLineEdit *control);
            void            enableSwitchingEcho(bool status); // if you don't want control echo from keyboard
            bool            isEnabledSwitchingEcho(void); // current status
            void            borderFrame(bool visible = true);
            QLabel *        zoomedWidget();
            void            setJoystick(JoystickWidget *j);
            void            initLayout(QStringList *kl, QVBoxLayout *klayout, QLineEdit *resultTxt);

        signals:
            void closeKeyboardEvent(bool cancelled, QString result);

        public slots:
            void            show(QWidget *activeForm);
            void            hide(bool noChangeColor);
            void            focusThis(QLineEdit *control);
            void            handleJoystickAxisEvent(QString axis, int value);
            void            handleJoystickButtonEvent(QString button,QGameControllerButtonEvent* event);

        protected:
            virtual void    closeEvent(QCloseEvent * event);

        private:
            widgetKeyBoard(const widgetKeyBoard&);
            widgetKeyBoard& operator=(const widgetKeyBoard&);

            void            init_keyboard(QLineEdit *focusThisControl); // reinizializza le funzioni base della tastiera

            QLineEdit *     setCurrentTextStyle(QLineEdit *control);
            QLineEdit *     setDefaultTextStyle(QLineEdit *control);
            QPushButton *createNewKey(QString keyValue);
            QLineEdit *		getNextTextbox(QLineEdit *thisControl = NULL, bool reset = false);
            void            controlKeyEcho(QLineEdit *control);

        private:
            QLineEdit		m_noFocusPalette; // usata per ripristinare la linetext senza focus
            QWidget         *m_nextInput; // punta alla textbox attualmente in focus
            QWidget         *m_activeWindow;
            QLineEdit		*m_currentTextBox; // mantiene il riferimento alla casella correntemente in uso
            QLineEdit		*resultTextBox; // mantiene il riferimento alla casella correntemente in uso
            QLabel          *m_zoomedKey; // used for zoomed pressed key
            int             focused;
            QStringList     *keysList;
            JoystickWidget  *joystick;
            static bool     m_created;
            bool            m_embeddedKeyboard;
            bool            m_echoMode; // status of current text object for echo
            bool            m_zoomFacilityEmbedded;
            bool            m_enablePasswordEcho; // controls the possibility to change among normal/password echo
          //  QSound          m_player;
            QClipboard      *m_clipboard;
    };

#endif // _WIDGETKEYBOARD_H
