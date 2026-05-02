// Function : FUN_4010c910
// Address  : 0x4010c910
// Size     : 89 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short FUN_4010c910(void)

{
  short sVar1;
  char *pcVar2;
  int iVar3;
  
  sVar1 = 0x4000;
LAB_4010c922:
  _DAT_3ffbe0cc = _DAT_3ffbe0cc + 1;
  if (_DAT_3ffbe0cc == -1) {
    _DAT_3ffbe0cc = -0x4000;
  }
  pcVar2 = "_free";
  do {
    for (iVar3 = **(int **)pcVar2; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x34)) {
      if (*(short *)(iVar3 + 0x42) == _DAT_3ffbe0cc) {
        sVar1 = sVar1 + -1;
        if (sVar1 != 0) goto LAB_4010c922;
        memw();
        sVar1 = 0;
        goto LAB_4010c960;
      }
    }
    pcVar2 = pcVar2 + 4;
  } while (pcVar2 != &DAT_3f41099c);
  memw();
  memw();
  sVar1 = _DAT_3ffbe0cc;
LAB_4010c960:
  memw();
  return sVar1;
}

