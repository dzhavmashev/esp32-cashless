// Function : FUN_4014d708
// Address  : 0x4014d708
// Size     : 203 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4014d708(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  
  iVar7 = *(int *)(*(int *)(param_2 + 4) + 4);
  pcVar4 = (char *)(iVar7 + 0x18);
  pcVar6 = pcVar4 + *(ushort *)(param_2 + 0x16);
  if ((*(byte *)(iVar7 + 1) & 0x40) != 0) {
    pcVar4 = pcVar4 + _DAT_3ffbfebc;
    pcVar6 = pcVar6 + -_DAT_3ffbfec0;
  }
  uVar3 = (int)pcVar6 - (int)pcVar4;
  if (uVar3 < 2) {
    return 0xffffffff;
  }
  cVar1 = *pcVar4;
  if ((cVar1 == '\x7f') || (cVar1 == '\x04')) {
    return 0;
  }
  if ((param_1 != 0) && (iVar7 = (*(code *)&SUB_4008b33c)(iVar7 + 10,param_1 + 4,6), iVar7 != 0)) {
    return 0xffffffff;
  }
  if (cVar1 == '\a') {
    uVar5 = (uint)(byte)pcVar4[1];
    if (uVar5 == 0) {
      uVar2 = 1;
      if (uVar3 != 2) {
        uVar2 = uVar5;
      }
    }
    else {
      if (uVar5 != 1) {
        return 0;
      }
      uVar2 = 0;
      if (uVar3 == 2) {
        uVar2 = uVar5;
      }
    }
    goto LAB_4014d7ba;
  }
  if (cVar1 == '\b') {
    if (1 < (byte)pcVar4[1]) {
      return 0;
    }
    iVar7 = 1;
    if (uVar3 < 4) goto LAB_4014d7d0;
LAB_4014d7ce:
    iVar7 = 0;
LAB_4014d7d0:
    return -iVar7;
  }
  if (cVar1 != '\x03') {
    return 0;
  }
  cVar1 = pcVar4[1];
  if (cVar1 == '\x01') {
    uVar2 = 1;
    if (uVar3 < 9) goto LAB_4014d7ba;
  }
  else {
    if (cVar1 == '\0') {
      iVar7 = 1;
      if (uVar3 < 9) goto LAB_4014d7d0;
      goto LAB_4014d7ce;
    }
    if (cVar1 != '\x02') {
      return 0;
    }
    uVar2 = 1;
    if (uVar3 < 6) goto LAB_4014d7ba;
  }
  uVar2 = 0;
LAB_4014d7ba:
  return -uVar2;
}

