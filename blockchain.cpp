#include "blockchain.h"

#define CURRENT_INDEX chain.count() - 1

Blockchain::Blockchain()
{
    interface = new QTableWidget(5, 5, this);
    hBox = new QHBoxLayout(this);
    hBox->addWidget(interface);

    chain.emplaceBack(Block("Genesis Block"));
    setBlockItem();
}

void Blockchain::addBlock(Block newBlock)
{
    newBlock.previousHash = getLastBlock().hash;
    chain.push_back(newBlock);

    setBlockItem();
}

Block Blockchain::getLastBlock() const
{
    return chain.back();
}

void Blockchain::setBlockItem()
{
    interface->setItem(0, CURRENT_INDEX, new QTableWidgetItem(QString::number(getLastBlock().getIndex())));
    interface->setItem(1, CURRENT_INDEX, new QTableWidgetItem(getLastBlock().getData()));
    interface->setItem(2, CURRENT_INDEX, new QTableWidgetItem(getLastBlock().getTime()));
    interface->setItem(3, CURRENT_INDEX, new QTableWidgetItem(getLastBlock().hash));
    interface->setItem(4, CURRENT_INDEX, new QTableWidgetItem(getLastBlock().previousHash));
}


