// Function : FUN_4015c604
// Address  : 0x4015c604
// Size     : 93 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015c604(void)

{
  int iVar1;
  
  FUN_40147fe4(1,4,4,0x3f434573);
  while (iVar1 = _DAT_3ffca0b0, _DAT_3ffca0b0 != 0) {
    _DAT_3ffca0b0 = *(int *)(_DAT_3ffca0b0 + 8);
    memw();
    (*(code *)&SUB_4008b530)(iVar1,0,0xc);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar1);
    if (DAT_3ffca0b4 != '\0') {
      DAT_3ffca0b4 = DAT_3ffca0b4 + -1;
      memw();
    }
  }
  memw();
  return;
}

