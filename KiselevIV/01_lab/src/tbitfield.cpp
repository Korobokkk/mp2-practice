// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"


TBitField::TBitField(int len)
{
    if (len <= 0) {
        throw "Error";
    }
    BitLen = len;
    MemLen = (len - 1) / (sizeof(TELEM) * 8) + 1;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = 0;
    }
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    MemLen = bf.MemLen;
    BitLen = bf.BitLen;
    pMem = new TELEM[MemLen];
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
}

TBitField::~TBitField()
{
    delete[] this->pMem;
    
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    if ((n < 0) || (n >= BitLen)) {
        throw "ERROR";
    }
    return n / (sizeof(TELEM) * 8);
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    if ((n < 0) || (n > BitLen)) {
        throw "ERROR";
    }
    return 1 << (n % (sizeof(TELEM) * 8));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    if (n >= BitLen || n<0)
        throw "invalid index";
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    if (n >= BitLen || n < 0)
        throw "invalid index";
    pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & (~GetMemMask(n));
}

int TBitField::GetBit(const int n) const // получить значение бита
{
    if (n < 0  || n>BitLen) {
        throw "Unvalid n";
    }
    if ((pMem[n / (sizeof(TELEM) * 8)] & GetMemMask(n)) == 0) return 0;
}

// битовые операции

const TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (pMem == bf.pMem) {
        return *this;
    }
    if (MemLen != bf.MemLen) {
        delete[] this->pMem;
        MemLen = bf.MemLen;
        pMem = new TELEM[MemLen];

    }
    BitLen = bf.BitLen;
    for (int i = 0; i < MemLen; i++) {
        pMem[i] = bf.pMem[i];
    }
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    // 0-есть различие 1- нет
    if (BitLen != bf.BitLen) {
        return 0;
    }
    for (int i = 0; i < MemLen; i++)
        if (pMem[i] != bf.pMem[i])
            return 0;
    return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение // TODO !!! ==
{
    return  !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    TBitField tmp(max(BitLen, bf.BitLen));

    for (int i = 0; i < this->MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < tmp.MemLen; i++)
        tmp.pMem[i] |= bf.pMem[i];
    return tmp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    TBitField tmp(max(BitLen, bf.BitLen));
    for (int i = 0; i < MemLen; i++)
        tmp.pMem[i] = pMem[i];
    for (int i = 0; i < tmp.MemLen; i++)
        tmp.pMem[i] &= bf.pMem[i];
    return tmp;
}

TBitField TBitField::operator~(void) // отрицание
{
    TBitField tmp(*this);
    for (int i = 0; i < this->BitLen; i++)
    {
        if (GetBit(i) == 0)
            tmp.SetBit(i);
        else
            tmp.ClrBit(i);
    }
    return tmp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    string  bitstring;
    istr >> bitstring;
    for (int i = 0; i < bf.BitLen; i++) {
        if (bitstring[i] == 1) {
            bf.SetBit(i);
        }
    }
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    for (int i = 0; i < bf.BitLen; i++) {
        ostr << bf.GetBit(i);
    }
    return ostr;;
}
