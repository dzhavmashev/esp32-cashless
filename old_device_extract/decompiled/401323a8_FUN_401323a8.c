// Function : FUN_401323a8
// Address  : 0x401323a8
// Size     : 46 bytes


int FUN_401323a8(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_401315c4(param_1,(uint)((param_2 & 3) != 0) + (param_2 >> 2));
  if ((iVar1 == 0) && (param_2 != 0)) {
    iVar1 = FUN_401314d4(param_1,param_2,param_3,param_4);
  }
  return iVar1;
}

