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


#include "widgetKeyBoard.h"
#include <QGuiApplication>
#include <QLayout>
#include <QScreen>
#include <QKeyEvent>
#include <QDir>
#include <QWidget>




bool widgetKeyBoard::m_created = false;



widgetKeyBoard::widgetKeyBoard(bool embeddedKeyboard, QWidget *activeForm, QWidget *parent) : QWidget(parent), m_nextInput(NULL), m_activeWindow(activeForm),
        m_currentTextBox(NULL), m_embeddedKeyboard(embeddedKeyboard), m_echoMode(false), m_zoomFacilityEmbedded(false), m_enablePasswordEcho(false),
        m_clipboard(QGuiApplication::clipboard())
{        
    this->m_zoomedKey = NULL;
    this->m_clipboard->clear();
   // this->setWindowIcon(QPixmap(":/TastieraVirtuale/logo"));
    resultTextBox=new QLineEdit();
    resultTextBox->setEchoMode(QLineEdit::Normal);
    focused=0;
    keysList=new QStringList();
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

widgetKeyBoard::~widgetKeyBoard()
{
}

void widgetKeyBoard::enableSwitchingEcho(bool status)
{
    this->m_enablePasswordEcho = status;
}

bool widgetKeyBoard::isEnabledSwitchingEcho(void)
{
    return (this->m_enablePasswordEcho);
}

bool widgetKeyBoard::isEmbeddedKeyboard(void)
{
    return (this->m_embeddedKeyboard);
}

void widgetKeyBoard::setZoomFacility(bool active)
{
    if (active == true) {
        if (this->m_zoomedKey == NULL)
            this->m_zoomedKey = new QLabel();
    }
    else {
        delete (this->m_zoomedKey);
        this->m_zoomedKey = NULL;
    }
    this->m_zoomFacilityEmbedded = active;
}

bool widgetKeyBoard::isZoomFacilityEnable(void)
{
    return (this->m_zoomFacilityEmbedded);
}



QPushButton * widgetKeyBoard::createNewKey(QString keyValue)
{
    QPushButton *tmp = new QPushButton();
    QString        style = QString(DEFAULT_STYLE_BUTTON) + QString(DEFAULT_BACKGROUND_BUTTON);
    QSize          imageDim;
    int            width = 0, height = 0;

    if (this->isEmbeddedKeyboard() == true) {
        imageDim.setWidth(64);
        imageDim.setHeight(64);
    }
    else {
        imageDim.setWidth(128);
        imageDim.setHeight(128);
    }    
    tmp->setText(keyValue);
    if (this->isEmbeddedKeyboard() == true) {
        width = KEY_WIDTH_EMBEDDED;
        height = KEY_HEIGHT_EMBEDDED;
        style += QString(EMBEDDED_KEYBOARD);
    }
    else {
        width = 54;
        height = 40;
    }
    tmp->setObjectName(keyValue);
    tmp->setMinimumSize(width, height);
    tmp->setMaximumSize(width, height);
    tmp->setStyleSheet(style);
    tmp->setVisible(true);


    if(!keyValue.compare("")){
        tmp->setEnabled(false);
    }
    else{
        tmp->setEnabled(true);
        keysList->append(tmp->text());
    }

    return (tmp);
}

void widgetKeyBoard::controlKeyEcho(QLineEdit *control)
{
    QString         textToSearch;
    QPushButton  *echoControlKey;
    QString         tmpStyle;
    QPushButton     *pasteButton = this->findChild<QPushButton *>(KEY_PASTE);
    QPushButton     *cutButton = this->findChild<QPushButton *>(KEY_CUT_LEFT);
    QPushButton     *copyButton = this->findChild<QPushButton *>(KEY_COPY);

    if (this->isEmbeddedKeyboard()) {
        textToSearch = KEY_HIDECHAR_EMBEDDED;
        tmpStyle = QString(EMBEDDED_KEYBOARD);
    }
    else
        textToSearch = KEY_HIDECHAR;
    if (pasteButton != NULL && copyButton != NULL) { // support for copy/paste functionality
        if (control->echoMode() == QLineEdit::Normal) {
            cutButton->setEnabled(true);
            copyButton->setEnabled(true);
            if (this->m_clipboard->text().length() > 0)
                pasteButton->setEnabled(true);
            else
                pasteButton->setEnabled(false);
        }
        else if (control->echoMode() == QLineEdit::Password) {
            copyButton->setEnabled(false);
            cutButton->setEnabled(false);
            pasteButton->setEnabled(false);
        }
    }
    echoControlKey = this->findChild<QPushButton *>(textToSearch);
    if (echoControlKey != NULL) { // support for password echo functionality            
        if (control->echoMode() == QLineEdit::Normal) {            
            echoControlKey->setStyleSheet(QString(DEFAULT_STYLE_BUTTON) + QString(DEFAULT_BACKGROUND_BUTTON) +  tmpStyle); // segnalato come attivo
            echoControlKey->setIcon(QPixmap(":/TastieraVirtuale/normalEcho"));
        }
        else if (control->echoMode() == QLineEdit::Password) {            
            echoControlKey->setStyleSheet(QString(DEFAULT_STYLE_BUTTON) + QString(CHANGED_BACKGROUND_BUTTON) + tmpStyle); // segnalato come attivo
            echoControlKey->setIcon(QPixmap(":/TastieraVirtuale/passwdEcho"));
        }
        echoControlKey->repaint();
        QGuiApplication::processEvents();
    }
}

// riceve i caratteri che sono stati digitati:
void widgetKeyBoard::receiptChildKey(QString key, QLineEdit *focusThisControl, bool reset)
{
    static QLineEdit *nextInput = resultTextBox;

    if (reset == true) { // reinizializza il controllo
        nextInput = this->getNextTextbox(focusThisControl, true);
        return;
     }
    if (nextInput == NULL)
        return;
//
    // inizia l'analisi del carattere ricevuto:
    QString newKey = key;
    QString tmpReceiptString = nextInput->text();
    int     tmpPos = nextInput->cursorPosition();

    if (IS_RETURN(newKey) == true) { // trattasi di TAB, si sposta alla text successiva        
        setVisible(false);        
        emit closeKeyboardEvent(false,resultTextBox->text());
    }
    else if (IS_BACK(newKey) == true || IS_BACK_EMB(newKey) == true) { // trattasi di CANCELLARE carattere, elimina il carattere a sinistra
        if (tmpPos-1 >= 0) {
            tmpReceiptString = tmpReceiptString.remove(tmpPos-1, 1);
            nextInput->setText(tmpReceiptString);
            nextInput->setCursorPosition(tmpPos-1);
            nextInput->setSelection(tmpPos-2, 1);
        }
    }
    else if (IS_CANC(newKey) == true) { // trattasi di CANC carattere, elimina il carattere a destra
       setVisible(false);     
       emit closeKeyboardEvent(true,"");
    }
    else if (IS_CLEAR_ALL(newKey) == true) { // trattasi di CANC carattere, elimina il carattere a destra
       nextInput->setText("");
    }
    else{
        tmpReceiptString = tmpReceiptString.insert(tmpPos, newKey);
        nextInput->setText(tmpReceiptString);
        nextInput->setCursorPosition(tmpPos+1);
        nextInput->setSelection(tmpPos, 1);
    }



}

void widgetKeyBoard::switchKeyEchoMode(QLineEdit *control)
{
    this->setStatusEchoMode(!this->statusEchoMode());
    if (this->statusEchoMode() == true)
        control->setEchoMode(QLineEdit::Password);
    else
        control->setEchoMode(QLineEdit::Normal);
    this->controlKeyEcho(control);
}

QLineEdit * widgetKeyBoard::getNextTextbox(QLineEdit *thisControl, bool reset)
{
    QLineEdit	*tmpInputFound = NULL;

    this->m_currentTextBox = NULL;
    if (this->m_activeWindow == NULL) { // nessuna finestra principale su cui operare
        m_nextInput = NULL;
        return (NULL);
    }
    if (thisControl != NULL) {
        if (this->m_activeWindow->findChild<QLineEdit *>(thisControl->objectName()) == 0) // verifies that thisControl is a child of m_activeWindow
            return (NULL);
        else // it's true!
            return (this->setCurrentTextStyle(thisControl));
    }
    //
    // cicla nella catena dei controlli in ordine di focus per ottenere la QEditLine
    if (m_nextInput == NULL || reset == true)
        m_nextInput = this->m_activeWindow->nextInFocusChain();
    else
        m_nextInput = m_nextInput->nextInFocusChain();
    do {
        if (m_nextInput->inherits("QLineEdit") == true) { // trovata una casella di testo da utilizzare
            tmpInputFound = dynamic_cast<QLineEdit *>(m_nextInput);
            return (this->setCurrentTextStyle(tmpInputFound));
        }
        m_nextInput = m_nextInput->nextInFocusChain();
    } while (m_nextInput != NULL);
    return (NULL);
}

QLineEdit * widgetKeyBoard::setCurrentTextStyle(QLineEdit *control)
{
    this->m_currentTextBox = control;
    control->setStyleSheet(STYLE_FOCUS_TEXT);
    return (control);
}

QLineEdit * widgetKeyBoard::setDefaultTextStyle(QLineEdit *control)
{
    control->setStyleSheet(this->m_noFocusPalette.styleSheet());
    return (control);
}

void widgetKeyBoard::init_keyboard(QLineEdit *focusThisControl)
{
    this->m_currentTextBox = NULL;
    this->m_nextInput = focusThisControl;   
    this->receiptChildKey(NULL, focusThisControl, true);
}

void widgetKeyBoard::soundClick(void)
{
    //this->m_player.play();
}

void widgetKeyBoard::show(QWidget *activeForm)
{
    this->m_activeWindow = activeForm;
    //this->init_keyboard(resultTextBox);
    this->focusThis(resultTextBox);

    if (this->windowState() == Qt::WindowMinimized)
        this->setWindowState(Qt::WindowNoState);

    this->setStatusEchoMode(false);
    this->m_clipboard->clear();
    this->move(20, QGuiApplication::screens()[0]->availableGeometry().height() - this->height() - 200);
    this->borderFrame(false);
    this->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    QWidget::showFullScreen();

    this->focusNextChild();
    this->focusNextChild();

}

void widgetKeyBoard::borderFrame(bool visible)
{
    if (visible == true)
        this->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::MSWindowsFixedSizeDialogHint);
    else
        this->setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint);
}

QLabel *widgetKeyBoard::zoomedWidget()
{
    return (this->m_zoomedKey);
}

void widgetKeyBoard::focusThis(QLineEdit *control)
{
    if (this->m_activeWindow != NULL) {
        if (this->m_currentTextBox != NULL)
            this->m_currentTextBox = this->setDefaultTextStyle(this->m_currentTextBox);
        this->init_keyboard(control);
        this->controlKeyEcho(control);
    }
    else {
        ;// Non è attiva nessuna finestra su cui operare
    }
}

void widgetKeyBoard::closeEvent(QCloseEvent * event)
{
    event->ignore();
}

void widgetKeyBoard::hide(bool changeColor)
{
    try {
        if (changeColor == true)
            if (this->m_activeWindow != NULL && this->m_currentTextBox != NULL)
                this->m_currentTextBox = this->setDefaultTextStyle(this->m_currentTextBox);
        this->m_currentTextBox = NULL;
        this->m_activeWindow = NULL;
        setVisible(false);
    }
    catch (...) {
    }
}

void widgetKeyBoard::createKeyboard(void)
{
    QPushButton 	*tmp = NULL;
    QVBoxLayout     *tmpVLayout = new QVBoxLayout;
    QHBoxLayout     *tmpLayout = new QHBoxLayout;
    QString         tmpStyle = QString::null;




   if (widgetKeyBoard::m_created == true) // tastiera già  creata: esce
		return;
    widgetKeyBoard::m_created = true; // segnala che è stata creata la tastiera
	//
    // stampa tasti numerici:



    tmpLayout->addWidget(createNewKey(""));
	for (short i = 49; i <= 57; i++) {
		tmpLayout->addWidget(createNewKey(QChar(i)));
	}
    tmpLayout->addWidget(createNewKey(tr("0")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = QString(KEY_BACKSPACE_EMBEDDED);
    else
        tmpStyle = QString(KEY_BACKSPACE);
    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
	tmpLayout->addWidget(tmp);
    tmpStyle = QString(KEY_CANC);
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = tmpStyle.toLower();
    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth());
    tmp->setMinimumWidth(tmp->minimumWidth());
    tmpLayout->addWidget(tmp);

    tmpVLayout->insertLayout(0, tmpLayout);
	//
	// Stampa linea della "Q":
	tmpLayout = new QHBoxLayout;	
    QVBoxLayout *layoutReturn = new QVBoxLayout;
    tmp = createNewKey(KEY_TAB);
    tmp->setMaximumWidth(tmp->maximumWidth() *1.5);
    tmp->setMinimumWidth(tmp->minimumWidth() *1.5);
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("Q")));
    tmpLayout->addWidget(createNewKey(tr("W")));
    tmpLayout->addWidget(createNewKey(tr("E")));
    tmpLayout->addWidget(createNewKey(tr("R")));
    tmpLayout->addWidget(createNewKey(tr("T")));
    tmpLayout->addWidget(createNewKey(tr("Y")));
    tmpLayout->addWidget(createNewKey(tr("U")));
    tmpLayout->addWidget(createNewKey(tr("I")));
    tmpLayout->addWidget(createNewKey(tr("O")));
    tmpLayout->addWidget(createNewKey(tr("P")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));

    layoutReturn->insertLayout(0, tmpLayout, 1); // inserisce la riga della "Q"
	//
	// Stampa linea della "A":
    tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_CAPS);
	tmp->setMaximumWidth(tmp->maximumWidth() * 2 + 5);
	tmp->setMinimumWidth(tmp->minimumWidth() * 2 + 5);                
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = QString(EMBEDDED_KEYBOARD);
    tmp->setStyleSheet(QString(DEFAULT_STYLE_BUTTON) + QString(CHANGED_BACKGROUND_BUTTON) + tmpStyle); // segnalato come attivo
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("A")));
    tmpLayout->addWidget(createNewKey(tr("S")));
    tmpLayout->addWidget(createNewKey(tr("D")));
    tmpLayout->addWidget(createNewKey(tr("F")));
    tmpLayout->addWidget(createNewKey(tr("G")));
    tmpLayout->addWidget(createNewKey(tr("H")));
    tmpLayout->addWidget(createNewKey(tr("J")));
    tmpLayout->addWidget(createNewKey(tr("K")));
    tmpLayout->addWidget(createNewKey(tr("L")));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr("")));
	tmpLayout->insertStretch(-1, 1);

    layoutReturn->insertLayout(1, tmpLayout, 1); // inserisce la riga della "A"
	//
	// inserisce il vertical layout all'interno di un horizontal:	
	tmpLayout = new QHBoxLayout;
	tmpLayout->insertLayout(0, layoutReturn, 1);
	//
	// inserisce anche il tasto invio:
    tmp = createNewKey(KEY_RETURN);
	tmp->setMaximumWidth(tmp->maximumWidth() * 2);
	tmp->setMinimumWidth(tmp->minimumWidth() * 2);
	tmp->setMinimumHeight(tmp->minimumHeight() * 2);
	tmp->setMaximumHeight(tmp->maximumHeight() * 2);
    tmpLayout->addWidget(tmp);
	//
    // inserisce l'horizontal all'interno del layout verticale principale:
    tmpVLayout->insertLayout(1, tmpLayout);
	//	
	// Stampa linea della "Z":
	tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_CUT_LEFT);
	tmp->setMaximumWidth(tmp->maximumWidth() * 2);
	tmp->setMinimumWidth(tmp->minimumWidth() * 2);
	tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("_")));
    tmpLayout->addWidget(createNewKey(tr("Z")));
    tmpLayout->addWidget(createNewKey(tr("X")));
    tmpLayout->addWidget(createNewKey(tr("C")));
    tmpLayout->addWidget(createNewKey(tr("V")));
    tmpLayout->addWidget(createNewKey(tr("B")));
    tmpLayout->addWidget(createNewKey(tr("N")));
    tmpLayout->addWidget(createNewKey(tr("M")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmp = createNewKey(KEY_CLEAR_ALL);
	tmp->setMaximumWidth(tmp->maximumWidth() * 3 + 5);
	tmp->setMinimumWidth(tmp->minimumWidth() * 3 + 5);
    tmpLayout->addWidget(tmp);
    tmpVLayout->insertLayout(2, tmpLayout);
	//	
	// Stampa linea dello SPACE:
	tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_COPY);
	tmp->setMaximumWidth(tmp->maximumWidth() * 2);
	tmp->setMinimumWidth(tmp->minimumWidth() * 2);
	tmpLayout->addWidget(tmp);
	tmp = createNewKey(KEY_ALT);
	tmp->setMaximumWidth(tmp->maximumWidth() * 2);
	tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmp = createNewKey(KEY_SPACE);
	tmp->setMaximumWidth(tmp->maximumWidth() * 10);
	tmp->setMinimumWidth(tmp->minimumWidth() * 10);
	tmpLayout->addWidget(tmp);
    // password echo button:
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = QString(KEY_HIDECHAR_EMBEDDED);
    else
        tmpStyle = QString(KEY_HIDECHAR);
    tmp = createNewKey(tmpStyle);
	tmp->setMaximumWidth(tmp->maximumWidth() * 2);
	tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    //
    tmp = createNewKey(KEY_PASTE);
	tmp->setMaximumWidth(tmp->maximumWidth() * 2);
	tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmpVLayout->insertLayout(3, tmpLayout);

    tmpLayout = new QHBoxLayout;
    tmpLayout->addWidget(resultTextBox);
    tmpVLayout->insertLayout(0, tmpLayout);

    tmpLayout = new QHBoxLayout;
    tmpLayout->addWidget(new QLabel("Enter the name of the new mission:"));
    tmpVLayout->insertLayout(0, tmpLayout);
	//
    this->setLayout(tmpVLayout);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    if (this->isZoomFacilityEnable()) {
        this->m_zoomedKey->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        this->m_zoomedKey->setStyleSheet(DEFAULT_BACKGROUND_BUTTON ZOOMED_WIDGET_STYLESHEET);
        this->m_zoomedKey->setGeometry(10, 10, 35, 35);
        this->m_zoomedKey->setParent(this);
        this->m_zoomedKey->hide();
    }
}
/*
QVBoxLayout *widgetKeyBoard::generateKeyboard(void)
{
    QPushButton 	*tmp = NULL;
    QVBoxLayout     *tmpVLayout = new QVBoxLayout;
    QHBoxLayout     *tmpLayout = new QHBoxLayout;
    QString         tmpStyle = QString::null;



    tmpLayout->addWidget(createNewKey(""));
    for (short i = 49; i <= 57; i++) {
        tmpLayout->addWidget(createNewKey(QChar(i)));
    }
    tmpLayout->addWidget(createNewKey(tr("0")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = QString(KEY_BACKSPACE_EMBEDDED);
    else
        tmpStyle = QString(KEY_BACKSPACE);
    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmpStyle = QString(KEY_CANC);
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = tmpStyle.toLower();
    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth());
    tmp->setMinimumWidth(tmp->minimumWidth());
    tmpLayout->addWidget(tmp);

    tmpVLayout->insertLayout(0, tmpLayout);
    //
    // Stampa linea della "Q":
    tmpLayout = new QHBoxLayout;
    QVBoxLayout *layoutReturn = new QVBoxLayout;
    tmp = createNewKey(KEY_TAB);
    tmp->setMaximumWidth(tmp->maximumWidth() *1.5);
    tmp->setMinimumWidth(tmp->minimumWidth() *1.5);
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("Q")));
    tmpLayout->addWidget(createNewKey(tr("W")));
    tmpLayout->addWidget(createNewKey(tr("E")));
    tmpLayout->addWidget(createNewKey(tr("R")));
    tmpLayout->addWidget(createNewKey(tr("T")));
    tmpLayout->addWidget(createNewKey(tr("Y")));
    tmpLayout->addWidget(createNewKey(tr("U")));
    tmpLayout->addWidget(createNewKey(tr("I")));
    tmpLayout->addWidget(createNewKey(tr("O")));
    tmpLayout->addWidget(createNewKey(tr("P")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));

    layoutReturn->insertLayout(0, tmpLayout, 1); // inserisce la riga della "Q"
    //
    // Stampa linea della "A":
    tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_CAPS);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2 + 5);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2 + 5);
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = QString(EMBEDDED_KEYBOARD);
    tmp->setStyleSheet(QString(DEFAULT_STYLE_BUTTON) + QString(CHANGED_BACKGROUND_BUTTON) + tmpStyle); // segnalato come attivo
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("A")));
    tmpLayout->addWidget(createNewKey(tr("S")));
    tmpLayout->addWidget(createNewKey(tr("D")));
    tmpLayout->addWidget(createNewKey(tr("F")));
    tmpLayout->addWidget(createNewKey(tr("G")));
    tmpLayout->addWidget(createNewKey(tr("H")));
    tmpLayout->addWidget(createNewKey(tr("J")));
    tmpLayout->addWidget(createNewKey(tr("K")));
    tmpLayout->addWidget(createNewKey(tr("L")));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->insertStretch(-1, 1);

    layoutReturn->insertLayout(1, tmpLayout, 1); // inserisce la riga della "A"
    //
    // inserisce il vertical layout all'interno di un horizontal:
    tmpLayout = new QHBoxLayout;
    tmpLayout->insertLayout(0, layoutReturn, 1);
    //
    // inserisce anche il tasto invio:
    tmp = createNewKey(KEY_RETURN);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmp->setMinimumHeight(tmp->minimumHeight() * 2);
    tmp->setMaximumHeight(tmp->maximumHeight() * 2);
    tmpLayout->addWidget(tmp);
    //
    // inserisce l'horizontal all'interno del layout verticale principale:
    tmpVLayout->insertLayout(1, tmpLayout);
    //
    // Stampa linea della "Z":
    tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_CUT_LEFT);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("_")));
    tmpLayout->addWidget(createNewKey(tr("Z")));
    tmpLayout->addWidget(createNewKey(tr("X")));
    tmpLayout->addWidget(createNewKey(tr("C")));
    tmpLayout->addWidget(createNewKey(tr("V")));
    tmpLayout->addWidget(createNewKey(tr("B")));
    tmpLayout->addWidget(createNewKey(tr("N")));
    tmpLayout->addWidget(createNewKey(tr("M")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmp = createNewKey(KEY_CLEAR_ALL);
    tmp->setMaximumWidth(tmp->maximumWidth() * 3 + 5);
    tmp->setMinimumWidth(tmp->minimumWidth() * 3 + 5);
    tmpLayout->addWidget(tmp);
    tmpVLayout->insertLayout(2, tmpLayout);
    //
    // Stampa linea dello SPACE:
    tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_COPY);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmp = createNewKey(KEY_ALT);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmp = createNewKey(KEY_SPACE);
    tmp->setMaximumWidth(tmp->maximumWidth() * 10);
    tmp->setMinimumWidth(tmp->minimumWidth() * 10);
    tmpLayout->addWidget(tmp);
    // password echo button:
    if (this->isEmbeddedKeyboard() == true)
        tmpStyle = QString(KEY_HIDECHAR_EMBEDDED);
    else
        tmpStyle = QString(KEY_HIDECHAR);
    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    //
    tmp = createNewKey(KEY_PASTE);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmpVLayout->insertLayout(3, tmpLayout);

    tmpLayout = new QHBoxLayout;
    tmpLayout->addWidget(resultTextBox);
    tmpVLayout->insertLayout(0, tmpLayout);

    tmpLayout = new QHBoxLayout;
    tmpLayout->addWidget(new QLabel("Enter the name of the new mission:"));
    tmpVLayout->insertLayout(0, tmpLayout);
    //
    return tmpVLayout;

}
*/
void widgetKeyBoard::handleJoystickAxisEvent(QString axis, int value){

    if(this->isVisible()){
        int lastKey=keysList->length()-1;

        if((!axis.compare(axis_cross_horizontal) || !axis.compare(axis_left_horizontal) || !axis.compare(axis_right_horizontal))  && value==1000){
            if(focused==21){
               for(int i=0;i<10;i++){
                   this->focusNextChild();
                   focused++;
               }
            }
            else if(focused==lastKey){
                    this->focusNextChild();
                    focused++;
            }

            this->focusNextChild();
            focused++;
            focused=(focused>lastKey)?0:focused;
        }
        else if((!axis.compare(axis_cross_horizontal) || !axis.compare(axis_left_horizontal) || !axis.compare(axis_right_horizontal)) && value==-1000){
            if(focused==0){
                this->focusPreviousChild();
                focused--;
           }
           this->focusPreviousChild();
           focused--;
           focused=(focused<0)?lastKey:focused;
        }
        else if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==-1000){
          int limit=(focused==32)?21:11;
          limit=(focused>=0 && focused<=11)?(focused+1):limit;
          limit=(focused>=33 && focused<=40)?10:limit;
          limit=(focused==lastKey)?3:limit;
          limit=(focused==41)?9:limit;
          limit=(focused==22)?10:limit;

          for (int i=0;i<limit;i++){
           this->focusPreviousChild();
           focused--;
           if(focused<0){
               focused=lastKey;
               this->focusPreviousChild();
           }

          }

        }
        else if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical))&& value==1000){

            int limit=(focused==0 || focused==1)?12:11;
            limit=(focused>=33 && focused<=lastKey)?(lastKey-focused):limit;
            limit=(focused==lastKey)?2:limit;
            limit=(focused==11)?21:limit;
            limit=(focused==30 || focused==31 || focused==32)?9:limit;


              for (int i=0;i<limit;i++){
               this->focusNextChild();
               focused++;
               focused=(focused>lastKey+1)?0:focused;
              }
            }
    }


}

void widgetKeyBoard::handleJoystickButtonEvent(QString button,QGameControllerButtonEvent* event){   

    if(this->isVisible()){
        if(button==button_A && !event->pressed()){
         receiptChildKey(keysList->at(focused),NULL,false);
        }        
    }
}

void widgetKeyBoard::initLayout( QStringList *kl, QVBoxLayout *klayout, QLineEdit *resultTxt){
    keysList=kl;
    resultTextBox=resultTxt;
    resultTextBox->setText("");
    this->setLayout(klayout);
}
