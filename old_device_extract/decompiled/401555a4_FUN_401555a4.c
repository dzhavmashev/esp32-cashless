// Function : FUN_401555a4
// Address  : 0x401555a4
// Size     : 102 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401555a4(uint param_1,int param_2,uint param_3,char param_4)

{
  int iVar1;
  int iVar2;
  
  param_1 = param_1 & 0xff;
  param_3 = param_3 & 0xff;
  if (param_1 < 3) {
    if (param_4 == '\x01') {
      if ((param_2 == 0) || (0x20 < param_3)) goto LAB_40155605;
      iVar1 = param_1 * 0x24 + 0x50;
      iVar2 = _DAT_3ffbfd50 + iVar1;
      *(uint *)(_DAT_3ffbfd50 + param_1 * 0x24 + 0x50) = param_3;
      memw();
      (*(code *)&SUB_4008b530)(iVar2 + 4);
      (*(code *)&SUB_4008b3d0)(_DAT_3ffbfd50 + iVar1 + 4,param_2,param_3);
    }
    *(char *)(_DAT_3ffbfd50 + param_1 + 0x98) = param_4;
    memw();
  }
LAB_40155605:
  memw();
  return;
}

