// Function : FUN_40131b00
// Address  : 0x40131b00
// Size     : 196 bytes


int FUN_40131b00(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  puVar3 = param_2;
  if (((param_1 != param_3) && (puVar3 = param_3, param_1 != param_2)) &&
     (iVar2 = FUN_4013167c(param_1,param_2), iVar2 != 0)) {
    return iVar2;
  }
  *param_1 = 1;
  uVar4 = puVar3[1];
  while( true ) {
    if (uVar4 == 0) goto LAB_40131b14;
    if (*(int *)(puVar3[2] + uVar4 * 4 + -4) != 0) break;
    uVar4 = uVar4 - 1;
  }
  iVar2 = FUN_40131574(param_1,uVar4);
  if (iVar2 != 0) {
    return iVar2;
  }
  puVar5 = (uint *)param_1[2];
  uVar7 = *(uint *)puVar3[2];
  uVar6 = *puVar5 + uVar7;
  *puVar5 = uVar6;
  bVar1 = uVar6 < uVar7;
  puVar5 = puVar5 + uVar4;
  while (uVar6 = (uint)bVar1, uVar6 != 0) {
    if ((uint)param_1[1] <= uVar4) {
      memw();
      iVar2 = FUN_40131574(param_1,uVar4 + 1);
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar5 = (uint *)(param_1[2] + uVar4 * 4);
    }
    uVar7 = *puVar5;
    *puVar5 = uVar6 + uVar7;
    bVar1 = uVar6 + uVar7 < uVar6;
    puVar5 = puVar5 + 1;
    memw();
    uVar4 = uVar4 + 1;
  }
LAB_40131b14:
  memw();
  return 0;
}

