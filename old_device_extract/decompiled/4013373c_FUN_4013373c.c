// Function : FUN_4013373c
// Address  : 0x4013373c
// Size     : 156 bytes


undefined4 FUN_4013373c(uint *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar3 = 0xfffffffc;
  if (param_1[1] == param_2[1]) {
    uVar4 = (int)*param_1 >> 1 & 1;
    uVar5 = (int)(*param_2 ^ *param_1) >> 1 & 1;
    *param_3 = uVar4 & uVar5;
    uVar7 = param_1[1];
    while (uVar7 = uVar7 - 1, uVar7 != 0xffffffff) {
      puVar9 = (undefined4 *)(param_2[2] + uVar7 * 4);
      puVar8 = (undefined4 *)(param_1[2] + uVar7 * 4);
      memw();
      uVar1 = FUN_40186370(*puVar9,*puVar8);
      uVar6 = 1 - uVar5 & uVar4 & uVar1 | *param_3;
      *param_3 = uVar6;
      memw();
      uVar2 = FUN_40186370(*puVar8,*puVar9);
      *param_3 = 1 - uVar4 & uVar2 & 1 - (uVar5 | uVar1) | uVar6;
      uVar5 = uVar5 | uVar1 | uVar2;
      memw();
    }
    uVar3 = 0;
  }
  memw();
  return uVar3;
}

