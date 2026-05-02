// Function : FUN_401345cc
// Address  : 0x401345cc
// Size     : 85 bytes


int FUN_401345cc(int param_1,int *param_2,int param_3,int param_4,undefined4 param_5,
                undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_28;
  int aiStack_24 [9];
  
  uVar1 = *(undefined4 *)(param_1 + 0xdc);
  iVar2 = -0x4f80;
  if (*(int *)(param_1 + 0x58) != 0) {
    iVar2 = FUN_401344b0(param_1,param_1 + 0x7c,param_1 + 0x88,param_5,param_6);
    if (((iVar2 == 0) && (iVar2 = FUN_401360d8(param_1,&iStack_28,param_3,param_4), iVar2 == 0)) &&
       (iVar2 = FUN_4013605c(param_1,param_1 + 0x88,uVar1,aiStack_24,param_3 + iStack_28,
                             param_4 - iStack_28), iVar2 == 0)) {
      *param_2 = iStack_28 + aiStack_24[0];
    }
  }
  memw();
  return iVar2;
}

