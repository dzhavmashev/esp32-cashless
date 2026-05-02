// Function : FUN_400ed04c
// Address  : 0x400ed04c
// Size     : 40 bytes


undefined4 FUN_400ed04c(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 auStack_24 [9];
  
  if ((*(char *)(param_1 + 1) == '\x01') && (param_2 != 0)) {
    auStack_24[0] = param_3;
    FUN_400f994c(*param_1,param_2,auStack_24);
    param_3 = auStack_24[0];
  }
  return param_3;
}

