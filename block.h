#include <QMainWindow>
#include <QString>
#include <QTime>

class Block
{
public:
    Block(const QString &data);
    Block(const Block &block)
        : index(block.index), data(block.data),
          hash(block.hash), previousHash(block.previousHash),
          time(block.time) {};
    Block& operator=(const Block &block)
    {
        index = block.index;
        data = block.data;
        return *this;
    }

    QString hash;
    QString previousHash;

    QString getData();
    QString getTime();
    int getIndex();

private:
    static int indexGenerator;
    int index;
    QTime time;
    QString data;

    QString calculateHash() const;
};
