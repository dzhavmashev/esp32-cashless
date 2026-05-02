// Function : FUN_400d4330
// Address  : 0x400d4330
// Size     : 22 bytes


undefined4 FUN_400d4330(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(byte *)(param_1 + 8) & 0x20) != 0) {
    uVar1 = FUN_400d431c(param_1,param_2);
  }
  return uVar1;
}

