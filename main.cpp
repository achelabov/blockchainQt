#include "blockchain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Blockchain blc = Blockchain();

    blc.addBlock(Block("first"));
    blc.addBlock(Block("second"));
    blc.addBlock(Block("third"));
    blc.addBlock(Block("fourth"));

    blc.show();
    return a.exec();
}
