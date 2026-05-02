// Function : FUN_401336b8
// Address  : 0x401336b8
// Size     : 130 bytes


int FUN_401336b8(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  
  param_3 = param_3 & 0xff;
  if (param_1 != param_2) {
    iVar1 = FUN_40131574(param_1,param_2[1]);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_40131574(param_2,param_1[1]);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar4 = *param_1;
    uVar3 = (int)(-param_3 | param_3) >> 0x1f;
    uVar2 = FUN_40186390(param_3,*param_2,uVar4);
    *param_1 = uVar2;
    memw();
    uVar2 = FUN_40186390(param_3,uVar4,*param_2);
    *param_2 = uVar2;
    uVar5 = 0;
    while (uVar5 < (uint)param_1[1]) {
      iVar1 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      puVar8 = (uint *)(param_1[2] + iVar1);
      puVar7 = (uint *)(param_2[2] + iVar1);
      uVar6 = *puVar8;
      *puVar8 = (uVar6 ^ *puVar7) & uVar3 ^ uVar6;
      *puVar7 = (*puVar7 ^ uVar6) & uVar3 ^ *puVar7;
      memw();
    }
  }
  return 0;
}

