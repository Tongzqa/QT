#ifndef QJSONOPER_H
#define QJSONOPER_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class QJsonOper; }
QT_END_NAMESPACE

class QJsonOper : public QDialog
{
    Q_OBJECT

public:
    QJsonOper(QWidget *parent = nullptr);
    ~QJsonOper();

private slots:
    void on_pushButtonWriteJson_clicked();

    void on_pushButtonReadJson_clicked();

private:
    Ui::QJsonOper *ui;
};
#endif // QJSONOPER_H
