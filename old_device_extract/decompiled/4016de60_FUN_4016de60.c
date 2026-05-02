// Function : FUN_4016de60
// Address  : 0x4016de60
// Size     : 132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016de60(void)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((_DAT_3ffca4c8 & 0x400000) == 0) {
    uVar3 = (**(code **)(_DAT_3ffc7e64 + 0x198))();
    uVar4 = 0;
    if (uVar3 < 0xd33) {
      cVar1 = (**(code **)(_DAT_3ffc7e64 + 0x174))(uVar3,3);
      cVar2 = (**(code **)(_DAT_3ffc7e64 + 0x174))(0xd33,3);
      uVar4 = ((int)(char)((cVar1 - cVar2) * '\x02') + 2U >> 2 & 0xff) << 8;
    }
    uVar5 = (*(code *)&SUB_400953e4)();
    DAT_3ffca522 = DAT_3ffca5c6;
    memw();
    _DAT_3ffca588 = uVar3 << 0x10 | uVar5 | uVar4;
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x400000;
  }
  return;
}

