// Function : FUN_4017133c
// Address  : 0x4017133c
// Size     : 78 bytes


void FUN_4017133c(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar1 = *(uint *)(param_3 + 4);
  uVar3 = uVar1 >> 1;
  while (uVar3 = uVar3 - 1, uVar3 != 0xffffffff) {
    FUN_401712e0(param_1,param_2,param_3 + 8,uVar3,uVar1);
  }
  iVar2 = param_3 + uVar1 * 4;
  while( true ) {
    uVar1 = uVar1 - 1;
    if ((int)uVar1 < 1) break;
    uVar4 = *(undefined4 *)(param_3 + 8);
    *(undefined4 *)(param_3 + 8) = *(undefined4 *)(iVar2 + 4);
    *(undefined4 *)(iVar2 + 4) = uVar4;
    FUN_401712e0(param_1,param_2,param_3 + 8,0,uVar1);
    iVar2 = iVar2 + -4;
  }
  return;
}

