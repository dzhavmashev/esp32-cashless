// Function : FUN_40161504
// Address  : 0x40161504
// Size     : 168 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161504(void)

{
  char cVar1;
  int iVar2;
  
  if ((DAT_3ffca2f5 < 2) && (DAT_3ffca1e5 == '\0')) {
    return;
  }
  if (DAT_3ffca1e6 == '\0') {
    return;
  }
  FUN_40161174();
  if (DAT_3ffca1e5 == '\0') goto LAB_40161529;
  cVar1 = DAT_3ffca1d9;
  if (DAT_3ffca1d9 == '\0') {
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
    if (iVar2 == 0) {
      DAT_3ffca2f4 = '\x01';
      memw();
    }
    else {
      DAT_3ffca1f1 = '\x01';
      memw();
      memw();
    }
    memw();
    FUN_4018bdc0();
  }
  else {
    if (DAT_3ffca1d9 != '\x01') {
      FUN_4018bdc0();
      goto LAB_40161529;
    }
    if (DAT_3ffca1eb == '\0') goto LAB_40161529;
    iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
    if (iVar2 == 0) {
      memw();
      memw();
      DAT_3ffca2f4 = cVar1;
    }
    else {
      memw();
      memw();
      DAT_3ffca1f1 = cVar1;
    }
  }
  if (DAT_3ffca1ec == '\0') {
    FUN_401613ec(1);
  }
LAB_40161529:
  FUN_40161498();
  DAT_3ffca1e6 = 0;
  memw();
  memw();
  return;
}

