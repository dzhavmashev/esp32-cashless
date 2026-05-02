// Function : FUN_400f08c0
// Address  : 0x400f08c0
// Size     : 52 bytes


undefined4 FUN_400f08c0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  FUN_400f0be8(param_1,&DAT_3f42161d);
  while ((uVar1 = FUN_400f0834(param_2), -1 < (int)uVar1 && ((param_3 & 0xff) != uVar1))) {
    FUN_400f106c(param_1,uVar1 & 0xff);
  }
  return param_1;
}

