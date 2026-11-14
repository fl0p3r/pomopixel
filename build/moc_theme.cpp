/****************************************************************************
** Meta object code from reading C++ file 'theme.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/theme.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'theme.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.12.0. It"
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
struct qt_meta_tag_ZN5ThemeE_t {};
} // unnamed namespace

template <> constexpr inline auto Theme::qt_create_metaobjectdata<qt_meta_tag_ZN5ThemeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Theme",
        "changed",
        "",
        "reload",
        "refreshRounding",
        "color",
        "key",
        "fallback",
        "accent",
        "background",
        "darkBackground",
        "darkerBackground",
        "lighterBackground",
        "foreground",
        "brightForeground",
        "muted",
        "red",
        "green",
        "yellow",
        "blue",
        "magenta",
        "orange",
        "cyan",
        "radius"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'changed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'reload'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'refreshRounding'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'color'
        QtMocHelpers::MethodData<QString(const QString &, const QString &) const>(5, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 6 }, { QMetaType::QString, 7 },
        }}),
        // Method 'color'
        QtMocHelpers::MethodData<QString(const QString &) const>(5, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::QString, {{
            { QMetaType::QString, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'accent'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'background'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'darkBackground'
        QtMocHelpers::PropertyData<QString>(10, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'darkerBackground'
        QtMocHelpers::PropertyData<QString>(11, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'lighterBackground'
        QtMocHelpers::PropertyData<QString>(12, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'foreground'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'brightForeground'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'muted'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'red'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'green'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'yellow'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'blue'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'magenta'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'orange'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'cyan'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'radius'
        QtMocHelpers::PropertyData<int>(23, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Theme, qt_meta_tag_ZN5ThemeE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Theme::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5ThemeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5ThemeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5ThemeE_t>.metaTypes,
    nullptr
} };

void Theme::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Theme *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->changed(); break;
        case 1: _t->reload(); break;
        case 2: _t->refreshRounding(); break;
        case 3: { QString _r = _t->color((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->color((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Theme::*)()>(_a, &Theme::changed, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->accent(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->background(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->darkBackground(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->darkerBackground(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->lighterBackground(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->foreground(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->brightForeground(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->muted(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->red(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->green(); break;
        case 10: *reinterpret_cast<QString*>(_v) = _t->yellow(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->blue(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->magenta(); break;
        case 13: *reinterpret_cast<QString*>(_v) = _t->orange(); break;
        case 14: *reinterpret_cast<QString*>(_v) = _t->cyan(); break;
        case 15: *reinterpret_cast<int*>(_v) = _t->radius(); break;
        default: break;
        }
    }
}

const QMetaObject *Theme::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Theme::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5ThemeE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Theme::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Theme::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
