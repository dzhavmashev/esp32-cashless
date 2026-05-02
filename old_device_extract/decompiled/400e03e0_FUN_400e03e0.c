// Function : FUN_400e03e0
// Address  : 0x400e03e0
// Size     : 34 bytes


int FUN_400e03e0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  while (iVar1 = param_1, iVar1 != 0) {
    iVar2 = FUN_400f1218(iVar1 + 0x10,param_3);
    if (iVar2 == 0) {
      param_1 = *(int *)(iVar1 + 8);
      param_2 = iVar1;
    }
    else {
      param_1 = *(int *)(iVar1 + 0xc);
    }
  }
  return param_2;
}

