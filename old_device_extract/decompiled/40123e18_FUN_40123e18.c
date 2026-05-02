// Function : FUN_40123e18
// Address  : 0x40123e18
// Size     : 368 bytes


int FUN_40123e18(void)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined1 auStack_26 [38];
  
  puVar2 = (undefined4 *)FUN_40159f9c();
  iVar3 = (*(code *)&SUB_40094dd8)(1,0x1c);
  if (iVar3 == 0) {
    return 0;
  }
  iVar4 = (*(code *)&SUB_40094dd8)(1,0xd4);
  *(int *)(iVar3 + 4) = iVar4;
  if (iVar4 == 0) goto LAB_40123e42;
  piVar5 = (int *)(*(code *)&SUB_40094dd8)(1,0x50);
  if (piVar5 == (int *)0x0) {
    (*(code *)&SUB_40094d80)(iVar4);
    (*(code *)&SUB_40094d80)(iVar3);
    return 0;
  }
  iVar4 = FUN_40159fb8();
  if (iVar4 == 2) {
    *piVar5 = 1;
  }
  memw();
  iVar4 = FUN_40159fb8();
  if (iVar4 == 3) {
    *piVar5 = 2;
  }
  memw();
  iVar4 = FUN_40159fb8();
  if (iVar4 == 4) {
    *piVar5 = 3;
  }
  memw();
  iVar4 = FUN_40159fc8();
  if ((*piVar5 == 1) && (iVar4 == 4)) {
LAB_40123f24:
    piVar5[3] = 2;
    iVar8 = 10;
    memw();
  }
  else {
    iVar8 = 2;
    if (iVar4 != 3) {
      if (iVar4 != 4) goto LAB_40123f24;
      iVar8 = 8;
    }
    piVar5[3] = iVar8;
  }
  piVar5[2] = iVar8;
  piVar5[8] = iVar8;
  piVar5[1] = 2;
  piVar5[10] = 2;
  memw();
  uVar6 = FUN_4015a404(1);
  *(byte *)((int)piVar5 + 0x4d) = (byte)(uVar6 >> 0xb) & 1;
  memw();
  iVar4 = *(int *)(iVar3 + 4);
  uVar9 = *puVar2;
  *(byte *)(piVar5 + 0x13) = (byte)(uVar6 >> 10) & 1;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(iVar4 + 0x10,puVar2 + 1,uVar9);
  iVar8 = *(int *)(iVar3 + 4);
  *(undefined4 *)(iVar8 + 0x30) = *puVar2;
  memw();
  iVar4 = (*(code *)&SUB_40094dd8)(1,0x40);
  *(int *)(iVar8 + 0x3c) = iVar4;
  if (iVar4 != 0) {
    uVar9 = FUN_4015a06c();
    FUN_4015a06c();
    uVar7 = (*(code *)&SUB_4008c01c)();
    (*(code *)&SUB_4008b3d0)(iVar4,uVar9,uVar7);
    *(undefined4 *)(*(int *)(iVar3 + 4) + 0xbc) = 300;
    memw();
    FUN_40123fe8();
    FUN_4015a5a0(1,auStack_26);
    iVar4 = FUN_401246d4(auStack_26,piVar5,0);
    uVar1 = *(undefined2 *)(iVar4 + 0x58);
    uVar9 = *(undefined4 *)(iVar4 + 0x54);
    *(int *)(iVar3 + 0x18) = iVar4;
    memw();
    FUN_4015a8f8(3,uVar9,uVar1,0);
    (*(code *)&SUB_40094d80)(piVar5);
    return iVar3;
  }
  memw();
  (*(code *)&SUB_40094d80)(piVar5);
  (*(code *)&SUB_40094d80)(iVar8);
LAB_40123e42:
  memw();
  (*(code *)&SUB_40094d80)(iVar3);
  return 0;
}

