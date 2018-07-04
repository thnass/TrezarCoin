#ifndef OVERVIEWPAGE_H
#define OVERVIEWPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

namespace Ui {
    class OverviewPage;
}
class WalletModel;
class ClientModel;
class TxViewDelegate;
class TransactionFilterProxy;


/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget *parent = 0);
    ~OverviewPage();

    void setModel(WalletModel *model);
    void showOutOfSyncWarning(bool fShow);

public slots:
    void setBalance(qint64 balance, qint64 stake, qint64 unconfirmed, qint64 immature);
    void setNetwork();
    void setNumTransactions(int count);

signals:
    void transactionClicked(const QModelIndex &index);

private:
    Ui::OverviewPage *ui;
    ClientModel *clientModel;
    WalletModel *model;

    qint64 currentBalance;
    qint64 currentStake;
    qint64 currentUnconfirmed;
    qint64 currentImmature;
    

    TxViewDelegate *txdelegate;
    TransactionFilterProxy *filter;

private slots:
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex &index);
};

#endif // OVERVIEWPAGE_H
