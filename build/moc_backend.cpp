/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/backend.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7BackendE_t {};
} // unnamed namespace

template <> constexpr inline auto Backend::qt_create_metaobjectdata<qt_meta_tag_ZN7BackendE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Backend",
        "modeChanged",
        "",
        "timerTicked",
        "runningChanged",
        "statsChanged",
        "onTick",
        "onConfigChanged",
        "toggle",
        "start",
        "pause",
        "reset",
        "skip",
        "setMode",
        "mode",
        "playClick",
        "modeName",
        "secondsRemaining",
        "totalSeconds",
        "formattedTime",
        "progress",
        "isRunning",
        "completedCycles",
        "isMascotResting",
        "Mode",
        "ModeFocus",
        "ModeShortBreak",
        "ModeLongBreak"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'modeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'timerTicked'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'runningChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'statsChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onTick'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onConfigChanged'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'toggle'
        QtMocHelpers::MethodData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'start'
        QtMocHelpers::MethodData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'pause'
        QtMocHelpers::MethodData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'reset'
        QtMocHelpers::MethodData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'skip'
        QtMocHelpers::MethodData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'setMode'
        QtMocHelpers::MethodData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Method 'playClick'
        QtMocHelpers::MethodData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'mode'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'modeName'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'secondsRemaining'
        QtMocHelpers::PropertyData<int>(17, QMetaType::Int, QMC::DefaultPropertyFlags, 1),
        // property 'totalSeconds'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags, 0),
        // property 'formattedTime'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'progress'
        QtMocHelpers::PropertyData<qreal>(20, QMetaType::QReal, QMC::DefaultPropertyFlags, 1),
        // property 'isRunning'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags, 2),
        // property 'completedCycles'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags, 3),
        // property 'isMascotResting'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Mode'
        QtMocHelpers::EnumData<enum Mode>(24, 24, QMC::EnumFlags{}).add({
            {   25, Mode::ModeFocus },
            {   26, Mode::ModeShortBreak },
            {   27, Mode::ModeLongBreak },
        }),
    };
    return QtMocHelpers::metaObjectData<Backend, qt_meta_tag_ZN7BackendE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Backend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7BackendE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7BackendE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7BackendE_t>.metaTypes,
    nullptr
} };

void Backend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Backend *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->modeChanged(); break;
        case 1: _t->timerTicked(); break;
        case 2: _t->runningChanged(); break;
        case 3: _t->statsChanged(); break;
        case 4: _t->onTick(); break;
        case 5: _t->onConfigChanged(); break;
        case 6: _t->toggle(); break;
        case 7: _t->start(); break;
        case 8: _t->pause(); break;
        case 9: _t->reset(); break;
        case 10: _t->skip(); break;
        case 11: _t->setMode((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->playClick(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::modeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::timerTicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::runningChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Backend::*)()>(_a, &Backend::statsChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->mode(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->modeName(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->secondsRemaining(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->totalSeconds(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->formattedTime(); break;
        case 5: *reinterpret_cast<qreal*>(_v) = _t->progress(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isRunning(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->completedCycles(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->isMascotResting(); break;
        default: break;
        }
    }
}

const QMetaObject *Backend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7BackendE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Backend::modeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Backend::timerTicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Backend::runningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Backend::statsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
