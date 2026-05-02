// Function : FUN_40101550
// Address  : 0x40101550
// Size     : 29 bytes


undefined4 FUN_40101550(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x5002;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x10) != 0)) {
    uVar1 = FUN_40100abc(0x40100788,param_1,param_2);
  }
  return uVar1;
}

