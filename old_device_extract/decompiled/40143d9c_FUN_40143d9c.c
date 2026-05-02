// Function : FUN_40143d9c
// Address  : 0x40143d9c
// Size     : 79 bytes


int FUN_40143d9c(uint *param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int aiStack_24 [9];
  
  iVar1 = FUN_40141738(param_1,param_2,param_3 + 1,param_4 | 0xa0);
  if (iVar1 == 0) {
    param_3[2] = *param_1;
    *param_3 = param_4 | 0xa0;
    uVar2 = *param_1;
    uVar3 = param_3[1];
    memw();
    iVar1 = FUN_40141738(param_1,uVar2 + uVar3,aiStack_24,0x30);
    if (iVar1 == 0) {
      if (uVar2 + uVar3 == *param_1 + aiStack_24[0]) {
        return 0;
      }
      return -0x2566;
    }
  }
  return iVar1 + -0x2500;
}

