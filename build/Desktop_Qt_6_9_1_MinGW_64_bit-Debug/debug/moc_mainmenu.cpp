/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainmenu.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN8MainMenuE_t {};
} // unnamed namespace

template <> constexpr inline auto MainMenu::qt_create_metaobjectdata<qt_meta_tag_ZN8MainMenuE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "MainMenu",
        "on_btnAdicionarTexto_clicked",
        "",
        "on_btnAdicionarLista_clicked",
        "on_btnAdicionarVideo_clicked",
        "on_btnAdicionarImagem_clicked",
        "on_btnAdicionarLink_clicked",
        "on_btnAdicionarFormulario_clicked",
        "on_btnLayoutFlexbox_clicked",
        "on_btnLayoutGrid_clicked",
        "on_btnPersonalizarEstilo_clicked",
        "on_btnTemplatePortfolio_clicked",
        "on_btnTemplateBlog_clicked",
        "on_btnSalvar_clicked",
        "on_btnSair_clicked",
        "on_btnNovoProjeto_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_btnAdicionarTexto_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarLista_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarVideo_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarImagem_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarLink_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnAdicionarFormulario_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnLayoutFlexbox_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnLayoutGrid_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnPersonalizarEstilo_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnTemplatePortfolio_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnTemplateBlog_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSalvar_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnSair_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnNovoProjeto_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainMenu, qt_meta_tag_ZN8MainMenuE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject MainMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8MainMenuE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8MainMenuE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8MainMenuE_t>.metaTypes,
    nullptr
} };

void MainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainMenu *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_btnAdicionarTexto_clicked(); break;
        case 1: _t->on_btnAdicionarLista_clicked(); break;
        case 2: _t->on_btnAdicionarVideo_clicked(); break;
        case 3: _t->on_btnAdicionarImagem_clicked(); break;
        case 4: _t->on_btnAdicionarLink_clicked(); break;
        case 5: _t->on_btnAdicionarFormulario_clicked(); break;
        case 6: _t->on_btnLayoutFlexbox_clicked(); break;
        case 7: _t->on_btnLayoutGrid_clicked(); break;
        case 8: _t->on_btnPersonalizarEstilo_clicked(); break;
        case 9: _t->on_btnTemplatePortfolio_clicked(); break;
        case 10: _t->on_btnTemplateBlog_clicked(); break;
        case 11: _t->on_btnSalvar_clicked(); break;
        case 12: _t->on_btnSair_clicked(); break;
        case 13: _t->on_btnNovoProjeto_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8MainMenuE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
