// Function : FUN_4018b19c
// Address  : 0x4018b19c
// Size     : 425 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4018b19c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  bVar1 = *(byte *)(param_1 + 8);
  uVar5 = (uint)bVar1;
  uVar6 = (uint)*(byte *)(param_1 + 0xc);
  if (*(short *)(param_1 + 0x10) != 0) {
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
    if (*(ushort *)(param_1 + 0x10) <= *(ushort *)(param_1 + 0xe)) {
      *(short *)(uVar5 * 0xc + 0x3ffc7c62) = *(short *)(uVar5 * 0xc + 0x3ffc7c62) + 1;
      memw();
      pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x58);
      memw();
      goto LAB_4018b33e;
    }
    piVar4 = (int *)(uVar5 * 0xc + 0x3ffc7c58);
    iVar7 = *piVar4;
    *(ushort *)(param_1 + 0xe) = *(ushort *)(param_1 + 0xe) + 1;
    memw();
    *piVar4 = iVar7 + 1;
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  }
  if (uVar5 == 0) {
LAB_4018b249:
    iVar7 = FUN_4015f674(uVar5);
  }
  else {
    if (uVar5 < 5) {
      pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x15c);
    }
    else {
      if (2 < uVar5 - 7) goto LAB_4018b249;
      pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x16c);
    }
    iVar7 = (*pcVar2)(uVar6 + 0x60 + param_2);
  }
  if (iVar7 != 0) {
    (*(code *)&SUB_4008b530)(iVar7,0,0x5c);
    *(int *)(iVar7 + 0x2c) = iVar7 + 0x3c;
    iVar8 = iVar7 + 0x5c;
    uVar3 = *(undefined4 *)(param_1 + 4);
    *(int *)(iVar7 + 4) = iVar7 + 0x30;
    *(int *)(iVar7 + 8) = iVar7 + 0x30;
    *(undefined2 *)(iVar7 + 0xc) = 1;
    memw();
    *(undefined4 *)(iVar7 + 0x3c) = uVar3;
    *(uint *)(iVar7 + 0x40) = *(uint *)(iVar7 + 0x40) | 0xf;
    uVar5 = uVar6 + param_2;
    *(uint *)(iVar7 + 0x34) = iVar8 + uVar6;
    *(int *)(iVar7 + 0x10) = iVar8;
    if (uVar5 < 0xffc) {
      *(undefined4 *)(iVar8 + uVar5) = 0xdeadbeef;
      memw();
      memw();
      *(uint *)(iVar7 + 0x30) = *(uint *)(iVar7 + 0x30) & 0xfffff000 | uVar5 & 0xfff;
    }
    else {
      memw();
      memw();
      *(uint *)(iVar7 + 0x30) = *(uint *)(iVar7 + 0x30) & 0xfffff000 | 0xffc;
      memw();
    }
    *(short *)(iVar7 + 0x16) = (short)param_2;
    *(byte *)(iVar7 + 0x1a) = bVar1;
    memw();
    if (param_3 == 0) {
      return iVar7;
    }
    memw();
    (*(code *)&SUB_4008b3d0)(*(undefined4 *)(*(int *)(iVar7 + 4) + 4),param_3,param_2);
    return iVar7;
  }
  if (*(short *)(param_1 + 0x10) == 0) {
    return 0;
  }
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  if (*(short *)(param_1 + 0xe) != 0) {
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -1;
    memw();
    piVar4 = (int *)(uVar5 * 0xc + 0x3ffc7c58);
    *piVar4 = *piVar4 + 1;
  }
  *(short *)(uVar5 * 0xc + 0x3ffc7c60) = *(short *)(uVar5 * 0xc + 0x3ffc7c60) + 1;
  memw();
  pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x58);
LAB_4018b33e:
  memw();
  (*pcVar2)(_DAT_3ffc799c);
  return 0;
}

