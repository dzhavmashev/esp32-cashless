// Function : FUN_400e5988
// Address  : 0x400e5988
// Size     : 52 bytes


undefined4 FUN_400e5988(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    param_2 = (int *)*param_2;
  }
  FUN_400f06a4(0x3ffc5490,"ze: %u\n",param_2);
  FUN_400e4c2c(param_1);
  iVar1 = FUN_400dc9cc(*param_3," an SSL message",param_3[1]);
  if (iVar1 != 0) {
    FUN_400e472c("nd: %s\n",iVar1);
  }
  return 1;
}

