#ifndef IntCell_H
#define IntCell_H

/**
 * A class for simjulating an integer memory cell.
 */
class IntCell
{
public:
    // We declare here the functions that exist
    explicit IntCell(int initialValue = 0);
    int read() const;
    void write(int x);

private:
    int storedValue;
};

#endif