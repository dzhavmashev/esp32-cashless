// Function : FUN_40148118
// Address  : 0x40148118
// Size     : 179 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40148118(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = _DAT_3ffc8804;
  bVar2 = DAT_3ffc7979 & 0xfe;
  memw();
  if (DAT_3ffbfc34 == '\0') {
    DAT_3ffc7979 = bVar2;
    if ((((_DAT_3ffc8864 == 0) || (_DAT_3ffc1a40 == 0)) || (iVar1 = FUN_4015a384(), iVar1 == 0)) ||
       ((memw(), DAT_3ffc1a3c != '\0' || (iVar1 = FUN_40161264(), bVar2 = DAT_3ffc7979, iVar1 == 0))
       )) {
      memw();
      _DAT_3ffc7968 = FUN_4015fd98();
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffc797c);
      (**(code **)(_DAT_3ffc1a34 + 0xe8))(0x3ffc797c,_DAT_3ffc7968,0);
      bVar2 = DAT_3ffc7979;
    }
  }
  else if ((DAT_3ffc7979 & 2) != 0) {
    DAT_3ffc7979 = DAT_3ffc7979 & 0xfc;
    memw();
    bVar2 = DAT_3ffc7979;
    if (*(code **)(_DAT_3ffc87ec + 0xc) != (code *)0x0) {
      memw();
      (**(code **)(_DAT_3ffc87ec + 0xc))();
      bVar2 = DAT_3ffc7979;
    }
  }
  DAT_3ffc7979 = bVar2;
  if (((iVar3 != 0) && (iVar3 = *(int *)(iVar3 + 0xec), iVar3 != 0)) && (DAT_3ffc7978 != '\0')) {
    FUN_401549d8(iVar3,0);
  }
  return;
}

