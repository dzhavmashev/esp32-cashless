// Function : FUN_400d73b8
// Address  : 0x400d73b8
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400d73b8(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = _DAT_3ffc5708;
  memw();
  uVar4 = param_2[1];
  uVar3 = *param_1;
  memw();
  *param_1 = *param_2;
  uVar2 = param_1[1];
  param_1[1] = uVar4;
  *param_2 = uVar3;
  param_2[1] = uVar2;
  memw();
  memw();
  if (iVar1 != _DAT_3ffc5708) {
    func_0x40082ecc();
  }
  return;
}

