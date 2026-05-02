// Function : FUN_401346b4
// Address  : 0x401346b4
// Size     : 56 bytes


int FUN_401346b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0xdc);
  iVar2 = -0x4f80;
  if (*(int *)(param_1 + 0x58) != 0) {
    iVar2 = FUN_401344b0(param_1,param_1 + 0x7c,param_1 + 0x88,param_5,param_6);
    if (iVar2 == 0) {
      iVar2 = FUN_4013605c(param_1,param_1 + 0x88,uVar1,param_2,param_3,param_4);
    }
  }
  return iVar2;
}

