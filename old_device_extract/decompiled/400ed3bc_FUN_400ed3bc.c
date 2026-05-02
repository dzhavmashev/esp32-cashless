// Function : FUN_400ed3bc
// Address  : 0x400ed3bc
// Size     : 29 bytes


undefined4 FUN_400ed3bc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = FUN_400efebc(0x3ffc53f4,param_2,0,*(undefined4 *)(param_1 + 8),0x10);
  }
  return uVar1;
}

