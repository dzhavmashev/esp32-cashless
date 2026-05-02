// Function : FUN_40113d60
// Address  : 0x40113d60
// Size     : 257 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_40113d60(int param_1,uint *param_2,undefined2 param_3)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    return -0x10;
  }
  if ((*(short *)(param_1 + 0x3a) == 0) && (cVar2 = FUN_40113770(param_1,param_1), cVar2 != '\0')) {
    return cVar2;
  }
  uVar1 = param_2[5];
  *(char *)(param_1 + 0x2c) = (char)uVar1;
  memw();
  if ((char)uVar1 == '\x06') {
    uVar5 = *param_2;
    *(uint *)(param_1 + 0x18) = uVar5;
    *(uint *)(param_1 + 0x1c) = param_2[1];
    *(uint *)(param_1 + 0x20) = param_2[2];
    *(uint *)(param_1 + 0x24) = param_2[3];
    uVar1 = param_2[4];
    *(char *)(param_1 + 0x28) = (char)uVar1;
    memw();
    if (((char)uVar1 != '\0') ||
       ((((uVar5 & 0xc0ff) != 0x80fe && (((uVar5 & 0x8fff) - 0x1ff & 0xfffffeff) != 0)) ||
        (iVar3 = FUN_401172d4(param_1,param_1 + 0x18), iVar3 == 0)))) goto LAB_40113da9;
    if (((*(uint *)(param_1 + 0x18) & 0xc0ff) == 0x80fe) ||
       (cVar2 = '\0', ((*(uint *)(param_1 + 0x18) & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
      cVar2 = *(char *)(iVar3 + 0xee) + '\x01';
    }
  }
  else {
    *(uint *)(param_1 + 0x18) = *param_2;
    cVar2 = '\0';
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(char *)(param_1 + 0x28) = cVar2;
  memw();
  memw();
LAB_40113da9:
  *(undefined2 *)(param_1 + 0x3c) = param_3;
  iVar3 = _DAT_3ffc8424;
  memw();
  *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 4;
  memw();
  iVar4 = iVar3;
  while( true ) {
    if (iVar4 == 0) {
      *(int *)(param_1 + 0x34) = iVar3;
      memw();
      _DAT_3ffc8424 = param_1;
      return '\0';
    }
    if (iVar4 == param_1) break;
    iVar4 = *(int *)(iVar4 + 0x34);
  }
  return '\0';
}

