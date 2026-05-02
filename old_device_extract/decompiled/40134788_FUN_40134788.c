// Function : FUN_40134788
// Address  : 0x40134788
// Size     : 80 bytes


int FUN_40134788(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(int *)(param_1 + 0x5c) + 7U >> 3;
  iVar3 = (uVar4 < param_4) * uVar4 + (uVar4 >= param_4) * param_4;
  iVar1 = FUN_4013183c(param_2,param_3,iVar3);
  iVar2 = iVar1;
  if (iVar1 == 0) {
    uVar4 = iVar3 * 8;
    if ((uVar4 <= *(uint *)(param_1 + 0x5c)) ||
       (iVar2 = FUN_40131a34(param_2,uVar4 - *(uint *)(param_1 + 0x5c)), iVar2 == 0)) {
      iVar3 = FUN_401860ec(param_2,param_1 + 0x4c);
      iVar2 = iVar1;
      if (-1 < iVar3) {
        iVar2 = FUN_40131d30(param_2,param_2,param_1 + 0x4c);
      }
    }
  }
  return iVar2;
}

