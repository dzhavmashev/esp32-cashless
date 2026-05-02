// Function : FUN_401882e4
// Address  : 0x401882e4
// Size     : 140 bytes


void FUN_401882e4(int param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *(int *)(param_1 + 4);
  uVar6 = **(uint **)(param_1 + 0x2c);
  pbVar3 = *(byte **)(iVar5 + 4);
  if ((uVar6 & 0x40000) != 0) {
    pbVar3 = pbVar3 + 4;
  }
  if ((pbVar3[4] & 1) != 0) {
    **(uint **)(param_1 + 0x2c) = uVar6 | 2;
  }
  bVar1 = *pbVar3;
  puVar4 = *(uint **)(param_1 + 0x2c);
  if ((bVar1 & 0xc) == 8) {
    *puVar4 = *puVar4 | 8;
    if ((bVar1 & 0x70) != 0x40) goto LAB_40188355;
    puVar4 = *(uint **)(param_1 + 0x2c);
    uVar6 = *puVar4 & 0xfffffff7;
    memw();
  }
  else {
    if ((bVar1 & 0xc) != 0) goto LAB_40188355;
    if ((bVar1 & 0xf0) == 0x50) {
      uVar6 = *puVar4;
      uVar2 = 0x8000000;
      if ((uVar6 & 2) != 0) goto LAB_40188355;
    }
    else {
      if (((bVar1 & 0xf0) != 0x40) || (uVar6 = *puVar4, (uVar6 & 2) != 0)) goto LAB_40188355;
      uVar2 = 0x800;
    }
    uVar6 = uVar6 | uVar2;
  }
  *puVar4 = uVar6;
LAB_40188355:
  if ((**(uint **)(param_1 + 0x2c) & 0x40000) != 0) {
    *(char *)(*(int *)(iVar5 + 4) + 3) = (char)(*(ushort *)(pbVar3 + 0x16) >> 4);
    memw();
  }
  memw();
  return;
}

