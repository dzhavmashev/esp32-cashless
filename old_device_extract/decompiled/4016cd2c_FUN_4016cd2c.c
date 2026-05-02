// Function : FUN_4016cd2c
// Address  : 0x4016cd2c
// Size     : 665 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016cd2c(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  uint uVar6;
  short sVar7;
  uint uVar8;
  short sVar9;
  uint uVar10;
  short sVar11;
  undefined4 uVar12;
  
  if ((_DAT_3ffca4c8 & 0x800000) == 0) {
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6a,2,6,4,0);
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6a,2,0,5,4);
    uVar12 = 7;
    if ((DAT_3ffca5b9 != '\x01') && (uVar12 = 0xb, DAT_3ffca5b9 == '\x02')) {
      uVar12 = 6;
    }
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6a,2,4,7,4,uVar12);
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x68,3,1,5);
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6a,2,4,0,0,1);
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6a,2,4,3,3,0);
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6a,2,4,3,3,1);
    (*(code *)&SUB_40008534)(100);
    cVar1 = (**(code **)(_DAT_3ffc7e64 + 0xa4))(0x6a,2,5,5,0);
    memw();
    DAT_3ffca518 = cVar1;
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x68,3,1,5,5,0);
    uVar3 = (uint)(byte)(cVar1 + 0x38);
    (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x6a,2,4,0,0);
    DAT_3ffca51c = 0x7f;
    uVar8 = ((uVar3 * 0x2ee) / (uint)DAT_3ffc075d - 0x39) / 10;
    uVar10 = ((uVar3 * 0x2ee) / 0x5f - 0x39) / 10;
    uVar6 = ((uVar3 * 0x26c) / (uint)DAT_3ffc075c - 0x39) / 10;
    uVar4 = ((uVar3 * 0x26c) / 0xc3 - 0x39) / 10;
    uVar3 = ((uVar3 * 400) / 0x1e - 0x39) / 10;
    sVar7 = (short)uVar8;
    sVar9 = (short)uVar10;
    sVar5 = (short)uVar6;
    sVar2 = (short)uVar4;
    sVar11 = (short)uVar3;
    if ((sVar7 < 0x80) && (DAT_3ffca51c = 2, 1 < sVar7)) {
      DAT_3ffca51c = (undefined1)uVar8;
    }
    memw();
    DAT_3ffca51e = 0x7f;
    if ((sVar5 < 0x80) && (DAT_3ffca51e = 2, 1 < sVar5)) {
      DAT_3ffca51e = (undefined1)uVar6;
    }
    memw();
    DAT_3ffca51d = 0x7f;
    if ((sVar9 < 0x80) && (DAT_3ffca51d = 0xe, 0xd < sVar9)) {
      DAT_3ffca51d = (undefined1)uVar10;
    }
    memw();
    DAT_3ffca51f = 0x7f;
    if ((sVar2 < 0x80) && (DAT_3ffca51f = 0xe, 0xd < sVar2)) {
      DAT_3ffca51f = (undefined1)uVar4;
    }
    memw();
    DAT_3ffca521 = '\x7f';
    if (sVar11 < 0x80) {
      cVar1 = (char)uVar3;
      DAT_3ffca520 = '\x02';
      if (1 < sVar11) {
        DAT_3ffca520 = cVar1;
      }
      memw();
      DAT_3ffca521 = '\x02';
      if (1 < sVar11) {
        DAT_3ffca521 = cVar1;
      }
    }
    else {
      DAT_3ffca520 = '\x7f';
      memw();
    }
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x800000;
  }
  (*(code *)&SUB_4018fa64)(0);
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,7,DAT_3ffca520 + -2);
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,8,DAT_3ffca520);
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,5,DAT_3ffca521 + -2);
  (**(code **)(_DAT_3ffc7e64 + 0xa0))(0x67,1,6,DAT_3ffca521);
  return;
}

