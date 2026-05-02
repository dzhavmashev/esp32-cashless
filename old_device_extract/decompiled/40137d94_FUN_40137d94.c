// Function : FUN_40137d94
// Address  : 0x40137d94
// Size     : 165 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40137d94(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int local_a8;
  undefined1 auStack_a4 [128];
  undefined4 *puStack_24;
  
  puVar4 = (undefined1 *)0x0;
  uVar5 = 0;
  memw();
  iVar3 = -0x3c;
  memw();
  puStack_24 = _DAT_3ffc5708;
  puVar2 = (undefined4 *)(param_1 + 0xe4);
LAB_40137db4:
  if ((int)uVar5 < *(int *)(param_1 + 0xe0)) goto LAB_40137df0;
  if (puVar4 == (undefined1 *)0x0) {
    iVar3 = -0x3d;
  }
LAB_40137dc0:
  memw();
  FUN_4013ae54(auStack_a4,0x80);
  iVar1 = iVar3;
LAB_40137dd6:
  param_1 = iVar1;
  puVar2 = _DAT_3ffc5708;
  memw();
  memw();
  if (puStack_24 == _DAT_3ffc5708) {
    return;
  }
  (*(code *)&SUB_40082ec4)();
  puVar4 = &DAT_3ffc5708;
LAB_40137df0:
  if (puVar2[4] == 1) {
    puVar4 = (undefined1 *)0x1;
  }
  local_a8 = 0;
  memw();
  iVar3 = (*(code *)*puVar2)(puVar2[1],auStack_a4,0x80,&local_a8);
  if (iVar3 == 0) {
    if (local_a8 != 0) goto code_r0x40137e16;
    goto LAB_40137e2c;
  }
  goto LAB_40137dc0;
code_r0x40137e16:
  iVar1 = FUN_40137d00(param_1,uVar5 & 0xff,auStack_a4);
  if (iVar1 == 0) {
    puVar2[2] = puVar2[2] + local_a8;
LAB_40137e2c:
    uVar5 = uVar5 + 1;
    puVar2 = puVar2 + 5;
    memw();
    goto LAB_40137db4;
  }
  goto LAB_40137dd6;
}

