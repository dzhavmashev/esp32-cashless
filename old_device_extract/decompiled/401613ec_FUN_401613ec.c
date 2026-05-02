// Function : FUN_401613ec
// Address  : 0x401613ec
// Size     : 76 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401613ec(char param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  
  uVar2 = DAT_3ffca1ec;
  uVar1 = DAT_3ffca1eb;
  DAT_3ffca1eb = param_1 == '\0';
  if ((bool)DAT_3ffca1eb) {
    memw();
  }
  else {
    memw();
    memw();
  }
  DAT_3ffca1ec = !(bool)DAT_3ffca1eb;
  memw();
  iVar3 = (*_DAT_3ffc7bd0)(param_1,0);
  if (iVar3 == 0) {
    memw();
    DAT_3ffca1eb = uVar1;
    DAT_3ffca1ec = uVar2;
  }
  memw();
  return;
}

