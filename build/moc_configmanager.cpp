/****************************************************************************
** Meta object code from reading C++ file 'configmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/configmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configmanager.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13ConfigManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto ConfigManager::qt_create_metaobjectdata<qt_meta_tag_ZN13ConfigManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ConfigManager",
        "changed",
        "",
        "loadConfig",
        "setMascot",
        "mascot",
        "nextMascot",
        "saveConfig",
        "configFilePath",
        "focusDuration",
        "shortBreakDuration",
        "longBreakDuration",
        "longBreakInterval",
        "soundEnabled",
        "volume",
        "finishSound",
        "startSound",
        "clickSound",
        "notificationsEnabled",
        "autoStartBreaks",
        "autoStartFocus",
        "windowWidth",
        "windowHeight",
        "alwaysOnTop",
        "useOmarchyTheme",
        "customAccent"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'changed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'loadConfig'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'setMascot'
        QtMocHelpers::MethodData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Method 'nextMascot'
        QtMocHelpers::MethodData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'saveConfig'
        QtMocHelpers::MethodData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'configFilePath'
        QtMocHelpers::MethodData<QString() const>(8, 2, QMC::AccessPublic, QMetaType::QString),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'focusDuration'
        QtMocHelpers::PropertyData<int>(9, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'shortBreakDuration'
        QtMocHelpers::PropertyData<int>(10, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'longBreakDuration'
        QtMocHelpers::PropertyData<int>(11, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'longBreakInterval'
        QtMocHelpers::PropertyData<int>(12, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'mascot'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'soundEnabled'
        QtMocHelpers::PropertyData<bool>(13, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'volume'
        QtMocHelpers::PropertyData<qreal>(14, QMetaType::QReal, QMC::DefaultPropertyFlags, 0),
        // property 'finishSound'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'startSound'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'clickSound'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'notificationsEnabled'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'autoStartBreaks'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'autoStartFocus'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'windowWidth'
        QtMocHelpers::PropertyData<int>(21, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'windowHeight'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'alwaysOnTop'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'useOmarchyTheme'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'customAccent'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ConfigManager, qt_meta_tag_ZN13ConfigManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ConfigManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13ConfigManagerE_t>.metaTypes,
    nullptr
} };

void ConfigManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ConfigManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->changed(); break;
        case 1: _t->loadConfig(); break;
        case 2: _t->setMascot((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->nextMascot(); break;
        case 4: _t->saveConfig(); break;
        case 5: { QString _r = _t->configFilePath();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ConfigManager::*)()>(_a, &ConfigManager::changed, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->focusDuration(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->shortBreakDuration(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->longBreakDuration(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->longBreakInterval(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->mascot(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->soundEnabled(); break;
        case 6: *reinterpret_cast<qreal*>(_v) = _t->volume(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->finishSound(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->startSound(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->clickSound(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->notificationsEnabled(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->autoStartBreaks(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->autoStartFocus(); break;
        case 13: *reinterpret_cast<int*>(_v) = _t->windowWidth(); break;
        case 14: *reinterpret_cast<int*>(_v) = _t->windowHeight(); break;
        case 15: *reinterpret_cast<bool*>(_v) = _t->alwaysOnTop(); break;
        case 16: *reinterpret_cast<bool*>(_v) = _t->useOmarchyTheme(); break;
        case 17: *reinterpret_cast<QString*>(_v) = _t->customAccent(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 4: _t->setMascot(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *ConfigManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13ConfigManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ConfigManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void ConfigManager::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
