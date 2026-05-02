// Function : FUN_400f0880
// Address  : 0x400f0880
// Size     : 45 bytes


undefined4 FUN_400f0880(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_400f0be8(param_1,&DAT_3f42161d);
  while (uVar1 = FUN_400f0834(param_2), -1 < (int)uVar1) {
    FUN_400f106c(param_1,uVar1 & 0xff);
  }
  return param_1;
}

