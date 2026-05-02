// Function : FUN_4012c1f8
// Address  : 0x4012c1f8
// Size     : 313 bytes


int FUN_4012c1f8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int aiStack_24 [9];
  
  iVar2 = param_1[0x11];
  puVar3 = (undefined1 *)(iVar2 + 0x8d4);
  iVar4 = *(int *)(iVar2 + 0x1dc);
  if ((iVar4 == 0) || (uVar5 = *(uint *)(iVar2 + 0x1e0), uVar5 == 0)) {
    iVar4 = *(int *)(*param_1 + 0xcc);
    if (iVar4 == 0) {
      return -0x6c00;
    }
    uVar5 = *(uint *)(*param_1 + 0xd0);
    if (uVar5 == 0) {
      return -0x6c00;
    }
  }
  uVar6 = (undefined1)(uVar5 >> 8);
  if (param_2 == 5) {
    *(undefined1 *)(iVar2 + 0x4b0) = uVar6;
    *(char *)(iVar2 + 0x4b1) = (char)uVar5;
    memw();
    if (0x422 < uVar5) goto LAB_4012c330;
    (*(code *)&SUB_4008b530)(iVar2 + 0x4b2,0,uVar5);
    puVar8 = (undefined1 *)(iVar2 + 0x4b2 + uVar5);
  }
  else if (param_2 == 7) {
    *(undefined1 *)(iVar2 + 0x4b0) = 0;
    puVar8 = (undefined1 *)(iVar2 + 0x4e2);
    *(undefined1 *)(iVar2 + 0x4b1) = 0x30;
    memw();
    memw();
  }
  else {
    if (param_2 == 6) {
      iVar1 = FUN_401342c4(iVar2 + 0x28,iVar2 + 0x4b2,0x422,aiStack_24,
                           *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50));
    }
    else {
      if (param_2 != 8) {
        return -0x6c00;
      }
      iVar1 = FUN_40134718(iVar2 + 0xa4,aiStack_24,iVar2 + 0x4b2,0x422,
                           *(undefined4 *)(*param_1 + 0x4c),*(undefined4 *)(*param_1 + 0x50));
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    *(char *)(iVar2 + 0x4b0) = (char)((uint)aiStack_24[0] >> 8);
    *(char *)(iVar2 + 0x4b1) = (char)aiStack_24[0];
    memw();
    puVar8 = (undefined1 *)(iVar2 + aiStack_24[0] + 0x4b2);
    memw();
  }
  if (1 < (int)puVar3 - (int)puVar8) {
    *puVar8 = uVar6;
    puVar7 = puVar8 + 2;
    puVar8[1] = (char)uVar5;
    memw();
    if ((puVar7 <= puVar3) && (uVar5 <= (uint)((int)puVar3 - (int)puVar7))) {
      memw();
      iVar2 = (*(code *)&SUB_4008b3d0)(puVar7,iVar4,uVar5);
      *(uint *)(param_1[0x11] + 0x10) = (iVar2 + uVar5) - (param_1[0x11] + 0x4b0);
      memw();
      return 0;
    }
  }
LAB_4012c330:
  memw();
  return -0x7100;
}

