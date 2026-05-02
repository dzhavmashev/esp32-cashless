// Function : FUN_4014ff48
// Address  : 0x4014ff48
// Size     : 179 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_4014ff48(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint local_30;
  char acStack_2c [44];
  
  bVar1 = *(byte *)(param_1 + 8);
  if (bVar1 == 0) {
    uVar6 = 1;
  }
  else {
    if (1 < bVar1) {
      return 0x102;
    }
    uVar6 = 2;
  }
  uVar5 = (uint)*(byte *)(param_1 + 9);
  if (3 < uVar5 - 1) {
    return 0x102;
  }
  if (bVar1 == 1) {
    if (*_DAT_3ffbfc54 == '\x01') {
      return 0x102;
    }
  }
  else if (*_DAT_3ffbfc54 == '\x02') {
    return 0x102;
  }
  cVar3 = *(char *)(param_1 + 10);
  memw();
  local_30 = uVar5;
  acStack_2c[0] = cVar3;
  if (bVar1 == 1) {
    memw();
    bVar2 = _DAT_3ffbfc54[0x3fa];
LAB_4014ff9b:
    if (uVar5 != bVar2) goto LAB_4014ffde;
  }
  else if (bVar1 == 0) {
    bVar2 = _DAT_3ffbfc54[0x9c];
    goto LAB_4014ff9b;
  }
  if (_DAT_3ffbfc54[1] != cVar3) goto LAB_4014ffde;
  if (bVar1 == 0) {
    uVar7 = 10;
LAB_4014ffac:
    iVar4 = FUN_40151060(uVar7,&local_30);
    if (iVar4 != 0) goto LAB_4014ffde;
  }
  else {
    uVar7 = 0x1f;
    if (bVar1 == 1) goto LAB_4014ffac;
  }
  iVar4 = FUN_40151060(0x25,acStack_2c);
  if (iVar4 == 0) {
    return 0;
  }
LAB_4014ffde:
  FUN_4014dd68(uVar6);
  iVar4 = FUN_4014dfdc(bVar1,uVar5,cVar3);
  FUN_4014dda8(uVar6);
  return (uint)(iVar4 != 0);
}

