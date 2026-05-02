// Function : FUN_4013c404
// Address  : 0x4013c404
// Size     : 48 bytes


undefined4
FUN_4013c404(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xa8);
  if (*(int *)(param_1 + 0xa8) == 0) {
    iVar2 = param_5;
  }
  memw();
  uVar1 = FUN_4013c204(param_1,param_2,param_3,param_4,param_5,param_6,param_7,iVar2,0xffffffff,
                       param_8);
  return uVar1;
}

