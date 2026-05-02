// Function : FUN_4013365c
// Address  : 0x4013365c
// Size     : 90 bytes


int FUN_4013365c(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  
  iVar1 = FUN_40131574(param_1,param_2[1]);
  param_3 = param_3 & 0xff;
  if (iVar1 == 0) {
    uVar2 = FUN_40186390(param_3,*param_2,*param_1);
    *param_1 = uVar2;
    memw();
    FUN_401863a8(param_2[1],param_1[2],param_2[2],param_3);
    uVar3 = param_2[1];
    while (uVar3 < (uint)param_1[1]) {
      puVar4 = (uint *)(param_1[2] + uVar3 * 4);
      uVar3 = uVar3 + 1;
      *puVar4 = *puVar4 & ((int)(-param_3 | param_3) >> 0x1f ^ 0xffffffffU);
      memw();
    }
  }
  return iVar1;
}

