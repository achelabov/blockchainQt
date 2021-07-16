#include <QVector>
#include "block.h"
#include <QHBoxLayout>
#include <QWidget>
#include <QTableWidget>

class Blockchain : public QWidget
{
public:
    Blockchain();

    void addBlock(Block newBlock);

    void setBlockItem();

private:
    QTableWidget *interface;
    QHBoxLayout *hBox;

    QVector<Block> chain;
    Block getLastBlock() const;
};

