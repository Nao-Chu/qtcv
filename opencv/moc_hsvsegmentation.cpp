/****************************************************************************
** Meta object code from reading C++ file 'hsvsegmentation.h'
**
** Created: Sat Mar 28 18:01:20 2020
**      by: The Qt Meta Object Compiler version 67 (Qt 5.0.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hsvsegmentation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hsvsegmentation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HsvSegmentation_t {
    QByteArrayData data[30];
    char stringdata[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_HsvSegmentation_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_HsvSegmentation_t qt_meta_stringdata_HsvSegmentation = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 12),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 5),
QT_MOC_LITERAL(4, 36, 12),
QT_MOC_LITERAL(5, 49, 12),
QT_MOC_LITERAL(6, 62, 12),
QT_MOC_LITERAL(7, 75, 12),
QT_MOC_LITERAL(8, 88, 12),
QT_MOC_LITERAL(9, 101, 12),
QT_MOC_LITERAL(10, 114, 12),
QT_MOC_LITERAL(11, 127, 12),
QT_MOC_LITERAL(12, 140, 12),
QT_MOC_LITERAL(13, 153, 12),
QT_MOC_LITERAL(14, 166, 12),
QT_MOC_LITERAL(15, 179, 17),
QT_MOC_LITERAL(16, 197, 7),
QT_MOC_LITERAL(17, 205, 5),
QT_MOC_LITERAL(18, 211, 3),
QT_MOC_LITERAL(19, 215, 3),
QT_MOC_LITERAL(20, 219, 11),
QT_MOC_LITERAL(21, 231, 1),
QT_MOC_LITERAL(22, 233, 13),
QT_MOC_LITERAL(23, 247, 9),
QT_MOC_LITERAL(24, 257, 5),
QT_MOC_LITERAL(25, 263, 11),
QT_MOC_LITERAL(26, 275, 11),
QT_MOC_LITERAL(27, 287, 3),
QT_MOC_LITERAL(28, 291, 11),
QT_MOC_LITERAL(29, 303, 3)
    },
    "HsvSegmentation\0acquire_hmin\0\0value\0"
    "acquire_hmax\0acquire_smin\0acquire_smax\0"
    "acquire_vmin\0acquire_vmax\0spinbox_hmin\0"
    "spinbox_hmax\0spinbox_smin\0spinbox_smax\0"
    "spinbox_vmin\0spinbox_vmax\0acquire_threshlod\0"
    "cv::Mat\0frame\0col\0row\0judge_color\0h\0"
    "inrange_class\0frame_hsv\0model\0min_average\0"
    "vector<int>\0min\0max_average\0max\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HsvSegmentation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08,
       4,    1,  102,    2, 0x08,
       5,    1,  105,    2, 0x08,
       6,    1,  108,    2, 0x08,
       7,    1,  111,    2, 0x08,
       8,    1,  114,    2, 0x08,
       9,    1,  117,    2, 0x08,
      10,    1,  120,    2, 0x08,
      11,    1,  123,    2, 0x08,
      12,    1,  126,    2, 0x08,
      13,    1,  129,    2, 0x08,
      14,    1,  132,    2, 0x08,
      15,    3,  135,    2, 0x08,
      20,    1,  142,    2, 0x08,
      22,    2,  145,    2, 0x08,
      25,    1,  150,    2, 0x08,
      28,    1,  153,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int, QMetaType::Int,   17,   18,   19,
    QMetaType::Int, QMetaType::Int,   21,
    0x80000000 | 16, 0x80000000 | 16, QMetaType::Int,   23,   24,
    QMetaType::Int, 0x80000000 | 26,   27,
    QMetaType::Int, 0x80000000 | 26,   29,

       0        // eod
};

void HsvSegmentation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HsvSegmentation *_t = static_cast<HsvSegmentation *>(_o);
        switch (_id) {
        case 0: _t->acquire_hmin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->acquire_hmax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->acquire_smin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->acquire_smax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->acquire_vmin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->acquire_vmax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->spinbox_hmin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->spinbox_hmax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->spinbox_smin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->spinbox_smax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->spinbox_vmin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->spinbox_vmax((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->acquire_threshlod((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: { int _r = _t->judge_color((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 14: { cv::Mat _r = _t->inrange_class((*reinterpret_cast< cv::Mat(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< cv::Mat*>(_a[0]) = _r; }  break;
        case 15: { int _r = _t->min_average((*reinterpret_cast< vector<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->max_average((*reinterpret_cast< vector<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject HsvSegmentation::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_HsvSegmentation.data,
      qt_meta_data_HsvSegmentation,  qt_static_metacall, 0, 0}
};


const QMetaObject *HsvSegmentation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HsvSegmentation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HsvSegmentation.stringdata))
        return static_cast<void*>(const_cast< HsvSegmentation*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int HsvSegmentation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
