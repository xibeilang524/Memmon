#ifndef XPROCESSTABLEHEADER_H
#define XPROCESSTABLEHEADER_H

#include <QWidget>
#include <QObject>
#include <QRectF>
#include <QColor>

class QPainter;
class QPaintEvent;
class QMouseEvent;


#if 0
class XProcessTableHeader : public QWidget
{
    struct HeaderItem
    {
        explicit HeaderItem(const QString& text,qreal width,bool pressed):_text(text),_width(width),_pressed(pressed),_hover(false){}
        explicit HeaderItem(const QString& text):_text(text),_width(0),_pressed(false),_hover(false){}
        QString _text;
        int _index;
        qreal _width;
        qreal _startXPos;
        qreal _separatorXPos;
        bool _pressed;
        bool _hover;
        QRectF _dragRect;
        QRectF _thisRect;
    };

Q_OBJECT
public:
    explicit XProcessTableHeader(QWidget* parent = 0);
    virtual ~XProcessTableHeader(){ clear(); }

public:
    void setLabels(const QStringList& labels);
    QStringList labels() const;

    void clear();
    void sortByThis(const QStringList& labels);
    void setAutoAdjust(bool adjust);
    bool isAutoAdjust() const;

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void leaveEvent(QEvent *);
    void resizeEvent(QResizeEvent *);

    QSize sizeHint() const
    {
        return QSize(400,XPT::Constant::Header_Height);
    }


private:
    void drawBackground(QPainter* painter);
    void drawItems(QPainter* painter);
    void drawSeparators(QPainter* painter);
    void drawHoverItem(QPainter* painter,HeaderItem* item,qreal& initX);
    void drawPressedItem(QPainter* painter,HeaderItem* item,qreal& initX);
    void drawNormalItem(QPainter* painter,HeaderItem* item,qreal& initX);

private:
    void initVars();
    void initSettings();
    void createItems();
    void clearHover();
    void mouseMoveEventHandler(QMouseEvent*);
    void mousePressEventHandler(QMouseEvent*);
    void mouseReleaseEventHandler(QMouseEvent *);
    qreal resetLatterItems(int startIndex); // returns the total width
    void updateColumnWidth();
    bool isDraggingItem(QMouseEvent* e);

    void setItemCount(int count);
    int itemCount() const;
    int getTotalWidth();



private:
    QStringList _labels;
    QVector<HeaderItem*> _headerItems;
    int _width;
    int _itemCount;
    bool _mousePressed;
    bool _startDragging;
    bool _isAutoAdjust;
    qreal _selectedXPos;
    qreal _maxWidth;
    HeaderItem* _selectedItem;
    QPointF _pressedPoint;

Q_SIGNALS:
    void columnWidthChanged(QVector<qreal> allColumnWidth);
    void columnsChanged(const QStringList& columns);


};
#endif

#endif // XPROCESSTABLEHEADER_H
