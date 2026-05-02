// Function : FUN_400ed920
// Address  : 0x400ed920
// Size     : 136 bytes


uint FUN_400ed920(char *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 0;
  if (*param_1 == '\0') {
    uVar1 = 0;
    if (*(int *)(param_1 + 0x10) != 0) {
      uVar3 = param_3;
      if ((uint)(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x24)) < param_3) {
        FUN_400ed41c(param_1);
        *param_1 = '\x04';
        uVar1 = 0;
      }
      else {
        while( true ) {
          iVar4 = *(int *)(param_1 + 0xc);
          uVar1 = param_3 - uVar3;
          if (iVar4 + uVar3 < 0x1001) break;
          func_0x4008b3d8(*(int *)(param_1 + 4) + iVar4,param_2 + uVar1,0x1000 - iVar4);
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + (0x1000 - iVar4);
          iVar2 = FUN_400ed674(param_1);
          if (iVar2 == 0) {
            return uVar1;
          }
          uVar3 = uVar3 + iVar4 + -0x1000;
        }
        func_0x4008b3d8(*(int *)(param_1 + 4) + iVar4,param_2 + uVar1,uVar3);
        iVar4 = *(int *)(param_1 + 0xc);
        *(uint *)(param_1 + 0xc) = uVar3 + iVar4;
        if ((uVar3 + iVar4 != *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x24)) ||
           (iVar4 = FUN_400ed674(param_1), iVar4 != 0)) {
          uVar1 = param_3;
        }
      }
    }
  }
  return uVar1;
}

