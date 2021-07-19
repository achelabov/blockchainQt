#include "block.h"
#include <QCryptographicHash>

int Block::indexGenerator = 0;

Block::Block(const QString &data)
    : data(data)
{
    index = indexGenerator++;
    time = QTime::currentTime();
    hash = calculateHash();
}

QString Block::getData()
{
    return data;
}

QString Block::getTime()
{
    return time.toString();
}

int Block::getIndex()
{
    return index;
}

QString Block::calculateHash() const
{
    QByteArray hashUtf8 = (data + time.toString() + previousHash + QString::number(index)).toUtf8();
    return QCryptographicHash::hash(hashUtf8, QCryptographicHash::Sha256).toHex();
}


