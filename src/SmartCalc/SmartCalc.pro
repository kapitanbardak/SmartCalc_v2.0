QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Lexemes/bracket_lexeme.cc \
    ../Lexemes/close_bracket_lexeme.cc \
    ../Lexemes/dual_purpose_operand_lexeme.cc \
    ../Lexemes/function_lexeme.cc \
    ../Lexemes/lexeme.cc \
    ../Lexemes/numeric_lexeme.cc \
    ../Lexemes/numeric_const_lexeme.cc \
    ../Lexemes/numeric_usual_lexeme.cc \
    ../Lexemes/open_bracket_lexeme.cc \
    ../Lexemes/operand_lexeme.cc \
    ../Lexemes/operator_lexeme.cc \
    ../Lexemes/unary_operand_lexeme.cc \
    ../Lexemes/usual_operand_lexeme.cc \
    ../controller.cc \
    ../model.cc \
    ../operations.cc \
    ../operator.cc \
    ../operator_map.cc \
    ../string_reader.cc \
    ../two_stack_calculator.cc \
    main.cpp \
    mainwindow.cpp \
    plot_widget.cpp \
    qcustomplot.cpp \
    x_input_widget.cpp

HEADERS += \
    ../Lexemes/bracket_lexeme.h \
    ../Lexemes/close_bracket_lexeme.h \
    ../Lexemes/dual_purpose_operand_lexeme.h \
    ../Lexemes/function_lexeme.h \
    ../Lexemes/lexeme.h \
    ../Lexemes/numeric_lexeme.h \
    ../Lexemes/numeric_const_lexeme.h \
    ../Lexemes/numeric_usual_lexeme.h \
    ../Lexemes/open_bracket_lexeme.h \
    ../Lexemes/operand_lexeme.h \
    ../Lexemes/operator_lexeme.h \
    ../Lexemes/unary_operand_lexeme.h \
    ../Lexemes/usual_operand_lexeme.h \
    ../controller.h \
    ../decorators.h \
    ../model.h \
    ../operations.h \
    ../operator.h \
    ../operator_map.h \
    ../string_reader.h \
    ../two_stack_calculator.h \
    mainwindow.h \
    plot_widget.h \
    qcustomplot.h \
    x_input_widget.h

FORMS += \
    mainwindow.ui \
    plot_widget.ui \
    x_input_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
