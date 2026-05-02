// Function : FUN_40162300
// Address  : 0x40162300
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162300(void)

{
  int iVar1;
  
  _DAT_3ffca2f8 = 0;
  memw();
  FUN_40162224();
  iVar1 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
  if (iVar1 != 0) {
    FUN_40161bf8();
  }
  _DAT_3ffca2f8 = _DAT_3ffca2f8 + 1;
  if (DAT_3ffca2f5 != '\0') {
    memw();
    FUN_40161328();
    DAT_3ffca1e7 = 0;
    DAT_3ffca1e6 = 1;
    DAT_3ffca33c = 0;
    DAT_3ffca2f5 = '\x02';
    memw();
    memw();
    FUN_401615fc();
  }
  return;
}

