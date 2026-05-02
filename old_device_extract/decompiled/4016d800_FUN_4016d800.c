// Function : FUN_4016d800
// Address  : 0x4016d800
// Size     : 211 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016d800(void)

{
  uint uVar1;
  short sStack_30;
  char acStack_2e [46];
  
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(5,1,_DAT_3ffc073c);
  (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,_DAT_3ffc073e);
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0x10c))(_DAT_3ffc073e);
  (**(code **)(_DAT_3ffc7e64 + 0xdc))((uVar1 & 0xffff) * 8 + 0x3ffca4d4);
  FUN_4016d398(0x80,0x3ffca527,1,0x2b,acStack_2e,_DAT_3ffca42c,(int)DAT_3ffc075e,0);
  if (0x10 < (byte)(acStack_2e[0] - 0xcU)) {
    sStack_30 = 0x14 - acStack_2e[0];
    memw();
    (*(code *)&SUB_40088f98)(&sStack_30,&DAT_3ffc073c,&DAT_3ffc073e,0);
    (**(code **)(_DAT_3ffc7e64 + 0xb8))(5,1,_DAT_3ffc073c);
    (**(code **)(_DAT_3ffc7e64 + 0xb8))(1,2,_DAT_3ffc073e);
    DAT_3ffc075e = 'E' - (char)sStack_30;
    memw();
    return;
  }
  DAT_3ffc075e = acStack_2e[0] + '1';
  memw();
  return;
}

